/*
 * Sun RPC is a product of Sun Microsystems, Inc. and is provided for
 * unrestricted use provided that this legend is included on all tape
 * media and as a part of the software program in whole or part.  Users
 * may copy or modify Sun RPC without charge, but are not authorized
 * to license or distribute it to anyone else except as part of a product or
 * program developed by the user.
 *
 * SUN RPC IS PROVIDED AS IS WITH NO WARRANTIES OF ANY KIND INCLUDING THE
 * WARRANTIES OF DESIGN, MERCHANTIBILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE OR TRADE PRACTICE.
 *
 * Sun RPC is provided with no support and without any obligation on the
 * part of Sun Microsystems, Inc. to assist in its use, correction,
 * modification or enhancement.
 *
 * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE
 * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY SUN RPC
 * OR ANY PART THEREOF.
 *
 * In no event will Sun Microsystems, Inc. be liable for any lost revenue
 * or profits or other special, indirect and consequential damages, even if
 * Sun has been advised of the possibility of such damages.
 *
 * Sun Microsystems, Inc.
 * 2550 Garcia Avenue
 * Mountain View, California  94043
 *
 * @(#)auth_none.c	1.19 87/08/11 Copyr 1984 Sun Micro
 * @(#)auth_none.c	2.1 88/07/29 4.0 RPCSRC
 * $NetBSD: auth_none.c,v 1.13 2000/01/22 22:19:17 mycroft Exp $
 * $FreeBSD: src/lib/libc/rpc/auth_none.c,v 1.14 2006/02/27 22:10:58 deischen Exp $
 */

/*
 * auth_none.c
 * Creates a client authentication handle for passing "null"
 * credentials and verifiers to remote systems.
 *
 * Copyright (C) 1984, Sun Microsystems, Inc.
 */

#include "namespace.h"
#include "reentrant.h"
#include <assert.h>
#include <stdlib.h>
#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/auth.h>
#include "un-namespace.h"
#include "mt_misc.h"

#define MAX_MARSHAL_SIZE 20

/*
 * Authenticator operations routines
 */

static bool_t	authnone_marshal(AUTH *, XDR *);
static void	authnone_verf(AUTH *);
static bool_t	authnone_validate(AUTH *, struct opaque_auth *);
static bool_t	authnone_refresh(AUTH *, void *);
static void	authnone_destroy(AUTH *);

static struct auth_ops	*authnone_ops(void);

static struct authnone_private {
	AUTH	no_client;
	char	marshalled_client[MAX_MARSHAL_SIZE];
	u_int	mcnt;
} *authnone_private;

AUTH *
authnone_create(void)
{
	struct authnone_private *ap = authnone_private;
	XDR xdr_stream;
	XDR *xdrs;

	mutex_lock(&authnone_lock);
	if (ap == NULL) {
		ap = (struct authnone_private *)calloc(1, sizeof (*ap));
		if (ap == NULL) {
			mutex_unlock(&authnone_lock);
			return (0);
		}
		authnone_private = ap;
	}
	if (!ap->mcnt) {
		ap->no_client.ah_cred = ap->no_client.ah_verf = _null_auth;
		ap->no_client.ah_ops = authnone_ops();
		xdrs = &xdr_stream;
		xdrmem_create(xdrs, ap->marshalled_client,
		    (u_int)MAX_MARSHAL_SIZE, XDR_ENCODE);
		xdr_opaque_auth(xdrs, &ap->no_client.ah_cred);
		xdr_opaque_auth(xdrs, &ap->no_client.ah_verf);
		ap->mcnt = XDR_GETPOS(xdrs);
		XDR_DESTROY(xdrs);
	}
	mutex_unlock(&authnone_lock);
	return (&ap->no_client);
}

/*ARGSUSED*/
static bool_t
authnone_marshal(AUTH *client __unused, XDR *xdrs)
{
	struct authnone_private *ap;
	bool_t dummy;

	assert(xdrs != NULL);

	ap = authnone_private;
	if (ap == NULL) {
		mutex_unlock(&authnone_lock);
		return (FALSE);
	}
	dummy = (*xdrs->x_ops->x_putbytes)(xdrs,
	    ap->marshalled_client, ap->mcnt);
	mutex_unlock(&authnone_lock);
	return (dummy);
}

/* All these unused parameters are required to keep ANSI-C from grumbling */
/*ARGSUSED*/
static void
authnone_verf(AUTH *client __unused)
{
}

/*ARGSUSED*/
static bool_t
authnone_validate(AUTH *client __unused, struct opaque_auth *opaque __unused)
{

	return (TRUE);
}

/*ARGSUSED*/
static bool_t
authnone_refresh(AUTH *client __unused, void *dummy __unused)
{

	return (FALSE);
}

/*ARGSUSED*/
static void
authnone_destroy(AUTH *client __unused)
{
}

static struct auth_ops *
authnone_ops(void)
{
	static struct auth_ops ops;

/* VARIABLES PROTECTED BY ops_lock: ops */

	mutex_lock(&ops_lock);
	if (ops.ah_nextverf == NULL) {
		ops.ah_nextverf = authnone_verf;
		ops.ah_marshal = authnone_marshal;
		ops.ah_validate = authnone_validate;
		ops.ah_refresh = authnone_refresh;
		ops.ah_destroy = authnone_destroy;
	}
	mutex_unlock(&ops_lock);
	return (&ops);
}
