/*
 * System call names.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * $DragonFly: src/sys/kern/syscalls.c,v 1.57 2007/06/16 20:00:37 dillon Exp $
 * created from DragonFly: src/sys/kern/syscalls.master,v 1.55 2007/05/03 23:04:31 dillon Exp 
 */

char *syscallnames[] = {
#ifdef COMPAT_43
#endif
	"syscall",			/* 0 = syscall */
	"exit",			/* 1 = exit */
	"fork",			/* 2 = fork */
	"read",			/* 3 = read */
	"write",			/* 4 = write */
	"open",			/* 5 = open */
	"close",			/* 6 = close */
	"wait4",			/* 7 = wait4 */
	"old.creat",		/* 8 = old creat */
	"link",			/* 9 = link */
	"unlink",			/* 10 = unlink */
	"obs_execv",			/* 11 = obsolete execv */
	"chdir",			/* 12 = chdir */
	"fchdir",			/* 13 = fchdir */
	"mknod",			/* 14 = mknod */
	"chmod",			/* 15 = chmod */
	"chown",			/* 16 = chown */
	"break",			/* 17 = break */
	"getfsstat",			/* 18 = getfsstat */
	"old.lseek",		/* 19 = old lseek */
	"getpid",			/* 20 = getpid */
	"mount",			/* 21 = mount */
	"unmount",			/* 22 = unmount */
	"setuid",			/* 23 = setuid */
	"getuid",			/* 24 = getuid */
	"geteuid",			/* 25 = geteuid */
	"ptrace",			/* 26 = ptrace */
	"recvmsg",			/* 27 = recvmsg */
	"sendmsg",			/* 28 = sendmsg */
	"recvfrom",			/* 29 = recvfrom */
	"accept",			/* 30 = accept */
	"getpeername",			/* 31 = getpeername */
	"getsockname",			/* 32 = getsockname */
	"access",			/* 33 = access */
	"chflags",			/* 34 = chflags */
	"fchflags",			/* 35 = fchflags */
	"sync",			/* 36 = sync */
	"kill",			/* 37 = kill */
	"old.stat",		/* 38 = old stat */
	"getppid",			/* 39 = getppid */
	"old.lstat",		/* 40 = old lstat */
	"dup",			/* 41 = dup */
	"pipe",			/* 42 = pipe */
	"getegid",			/* 43 = getegid */
	"profil",			/* 44 = profil */
	"ktrace",			/* 45 = ktrace */
	"obs_freebsd3_sigaction",			/* 46 = obsolete freebsd3_sigaction */
	"getgid",			/* 47 = getgid */
	"obs_freebsd3_sigprocmask",			/* 48 = obsolete freebsd3_sigprocmask */
	"getlogin",			/* 49 = getlogin */
	"setlogin",			/* 50 = setlogin */
	"acct",			/* 51 = acct */
	"obs_freebsd3_sigpending",			/* 52 = obsolete freebsd3_sigpending */
	"sigaltstack",			/* 53 = sigaltstack */
	"ioctl",			/* 54 = ioctl */
	"reboot",			/* 55 = reboot */
	"revoke",			/* 56 = revoke */
	"symlink",			/* 57 = symlink */
	"readlink",			/* 58 = readlink */
	"execve",			/* 59 = execve */
	"umask",			/* 60 = umask */
	"chroot",			/* 61 = chroot */
	"old.fstat",		/* 62 = old fstat */
	"old.getkerninfo",		/* 63 = old getkerninfo */
	"old.getpagesize",		/* 64 = old getpagesize */
	"msync",			/* 65 = msync */
	"vfork",			/* 66 = vfork */
	"obs_vread",			/* 67 = obsolete vread */
	"obs_vwrite",			/* 68 = obsolete vwrite */
	"sbrk",			/* 69 = sbrk */
	"sstk",			/* 70 = sstk */
	"old.mmap",		/* 71 = old mmap */
	"vadvise",			/* 72 = vadvise */
	"munmap",			/* 73 = munmap */
	"mprotect",			/* 74 = mprotect */
	"madvise",			/* 75 = madvise */
	"obs_vhangup",			/* 76 = obsolete vhangup */
	"obs_vlimit",			/* 77 = obsolete vlimit */
	"mincore",			/* 78 = mincore */
	"getgroups",			/* 79 = getgroups */
	"setgroups",			/* 80 = setgroups */
	"getpgrp",			/* 81 = getpgrp */
	"setpgid",			/* 82 = setpgid */
	"setitimer",			/* 83 = setitimer */
	"old.wait",		/* 84 = old wait */
	"swapon",			/* 85 = swapon */
	"getitimer",			/* 86 = getitimer */
	"old.gethostname",		/* 87 = old gethostname */
	"old.sethostname",		/* 88 = old sethostname */
	"getdtablesize",			/* 89 = getdtablesize */
	"dup2",			/* 90 = dup2 */
	"#91",			/* 91 = getdopt */
	"fcntl",			/* 92 = fcntl */
	"select",			/* 93 = select */
	"#94",			/* 94 = setdopt */
	"fsync",			/* 95 = fsync */
	"setpriority",			/* 96 = setpriority */
	"socket",			/* 97 = socket */
	"connect",			/* 98 = connect */
	"old.accept",		/* 99 = old accept */
	"getpriority",			/* 100 = getpriority */
	"old.send",		/* 101 = old send */
	"old.recv",		/* 102 = old recv */
	"obs_freebsd3_sigreturn",			/* 103 = obsolete freebsd3_sigreturn */
	"bind",			/* 104 = bind */
	"setsockopt",			/* 105 = setsockopt */
	"listen",			/* 106 = listen */
	"obs_vtimes",			/* 107 = obsolete vtimes */
	"old.sigvec",		/* 108 = old sigvec */
	"old.sigblock",		/* 109 = old sigblock */
	"old.sigsetmask",		/* 110 = old sigsetmask */
	"obs_freebsd3_sigsuspend",			/* 111 = obsolete freebsd3_sigsuspend */
	"old.sigstack",		/* 112 = old sigstack */
	"old.recvmsg",		/* 113 = old recvmsg */
	"old.sendmsg",		/* 114 = old sendmsg */
	"obs_vtrace",			/* 115 = obsolete vtrace */
	"gettimeofday",			/* 116 = gettimeofday */
	"getrusage",			/* 117 = getrusage */
	"getsockopt",			/* 118 = getsockopt */
	"#119",			/* 119 = resuba */
	"readv",			/* 120 = readv */
	"writev",			/* 121 = writev */
	"settimeofday",			/* 122 = settimeofday */
	"fchown",			/* 123 = fchown */
	"fchmod",			/* 124 = fchmod */
	"old.recvfrom",		/* 125 = old recvfrom */
	"setreuid",			/* 126 = setreuid */
	"setregid",			/* 127 = setregid */
	"rename",			/* 128 = rename */
	"old.truncate",		/* 129 = old truncate */
	"old.ftruncate",		/* 130 = old ftruncate */
	"flock",			/* 131 = flock */
	"mkfifo",			/* 132 = mkfifo */
	"sendto",			/* 133 = sendto */
	"shutdown",			/* 134 = shutdown */
	"socketpair",			/* 135 = socketpair */
	"mkdir",			/* 136 = mkdir */
	"rmdir",			/* 137 = rmdir */
	"utimes",			/* 138 = utimes */
	"obs_4.2",			/* 139 = obsolete 4.2 sigreturn */
	"adjtime",			/* 140 = adjtime */
	"old.getpeername",		/* 141 = old getpeername */
	"old.gethostid",		/* 142 = old gethostid */
	"old.sethostid",		/* 143 = old sethostid */
	"old.getrlimit",		/* 144 = old getrlimit */
	"old.setrlimit",		/* 145 = old setrlimit */
	"old.killpg",		/* 146 = old killpg */
	"setsid",			/* 147 = setsid */
	"quotactl",			/* 148 = quotactl */
	"old.quota",		/* 149 = old quota */
	"old.getsockname",		/* 150 = old getsockname */
	"#151",			/* 151 = sem_lock */
	"#152",			/* 152 = sem_wakeup */
	"#153",			/* 153 = asyncdaemon */
	"#154",			/* 154 = nosys */
	"nfssvc",			/* 155 = nfssvc */
	"old.getdirentries",		/* 156 = old getdirentries */
	"statfs",			/* 157 = statfs */
	"fstatfs",			/* 158 = fstatfs */
	"#159",			/* 159 = nosys */
	"#160",			/* 160 = nosys */
	"getfh",			/* 161 = getfh */
	"getdomainname",			/* 162 = getdomainname */
	"setdomainname",			/* 163 = setdomainname */
	"uname",			/* 164 = uname */
	"sysarch",			/* 165 = sysarch */
	"rtprio",			/* 166 = rtprio */
	"#167",			/* 167 = nosys */
	"#168",			/* 168 = nosys */
	"semsys",			/* 169 = semsys */
	"msgsys",			/* 170 = msgsys */
	"shmsys",			/* 171 = shmsys */
	"#172",			/* 172 = nosys */
	"extpread",			/* 173 = extpread */
	"extpwrite",			/* 174 = extpwrite */
	"#175",			/* 175 = nosys */
	"ntp_adjtime",			/* 176 = ntp_adjtime */
	"#177",			/* 177 = sfork */
	"#178",			/* 178 = getdescriptor */
	"#179",			/* 179 = setdescriptor */
	"#180",			/* 180 = nosys */
	"setgid",			/* 181 = setgid */
	"setegid",			/* 182 = setegid */
	"seteuid",			/* 183 = seteuid */
	"#184",			/* 184 = lfs_bmapv */
	"#185",			/* 185 = lfs_markv */
	"#186",			/* 186 = lfs_segclean */
	"#187",			/* 187 = lfs_segwait */
	"old.stat",		/* 188 = old stat */
	"old.fstat",		/* 189 = old fstat */
	"old.lstat",		/* 190 = old lstat */
	"pathconf",			/* 191 = pathconf */
	"fpathconf",			/* 192 = fpathconf */
	"#193",			/* 193 = nosys */
	"getrlimit",			/* 194 = getrlimit */
	"setrlimit",			/* 195 = setrlimit */
	"old.getdirentries",		/* 196 = old getdirentries */
	"mmap",			/* 197 = mmap */
	"__syscall",			/* 198 = __syscall */
	"lseek",			/* 199 = lseek */
	"truncate",			/* 200 = truncate */
	"ftruncate",			/* 201 = ftruncate */
	"__sysctl",			/* 202 = __sysctl */
	"mlock",			/* 203 = mlock */
	"munlock",			/* 204 = munlock */
	"undelete",			/* 205 = undelete */
	"futimes",			/* 206 = futimes */
	"getpgid",			/* 207 = getpgid */
	"#208",			/* 208 = newreboot */
	"poll",			/* 209 = poll */
	"lkmnosys",			/* 210 = lkmnosys */
	"lkmnosys",			/* 211 = lkmnosys */
	"lkmnosys",			/* 212 = lkmnosys */
	"lkmnosys",			/* 213 = lkmnosys */
	"lkmnosys",			/* 214 = lkmnosys */
	"lkmnosys",			/* 215 = lkmnosys */
	"lkmnosys",			/* 216 = lkmnosys */
	"lkmnosys",			/* 217 = lkmnosys */
	"lkmnosys",			/* 218 = lkmnosys */
	"lkmnosys",			/* 219 = lkmnosys */
	"__semctl",			/* 220 = __semctl */
	"semget",			/* 221 = semget */
	"semop",			/* 222 = semop */
	"#223",			/* 223 = semconfig */
	"msgctl",			/* 224 = msgctl */
	"msgget",			/* 225 = msgget */
	"msgsnd",			/* 226 = msgsnd */
	"msgrcv",			/* 227 = msgrcv */
	"shmat",			/* 228 = shmat */
	"shmctl",			/* 229 = shmctl */
	"shmdt",			/* 230 = shmdt */
	"shmget",			/* 231 = shmget */
	"clock_gettime",			/* 232 = clock_gettime */
	"clock_settime",			/* 233 = clock_settime */
	"clock_getres",			/* 234 = clock_getres */
	"#235",			/* 235 = timer_create */
	"#236",			/* 236 = timer_delete */
	"#237",			/* 237 = timer_settime */
	"#238",			/* 238 = timer_gettime */
	"#239",			/* 239 = timer_getoverrun */
	"nanosleep",			/* 240 = nanosleep */
	"#241",			/* 241 = nosys */
	"#242",			/* 242 = nosys */
	"#243",			/* 243 = nosys */
	"#244",			/* 244 = nosys */
	"#245",			/* 245 = nosys */
	"#246",			/* 246 = nosys */
	"#247",			/* 247 = nosys */
	"#248",			/* 248 = nosys */
	"#249",			/* 249 = nosys */
	"minherit",			/* 250 = minherit */
	"rfork",			/* 251 = rfork */
	"openbsd_poll",			/* 252 = openbsd_poll */
	"issetugid",			/* 253 = issetugid */
	"lchown",			/* 254 = lchown */
	"#255",			/* 255 = nosys */
	"#256",			/* 256 = nosys */
	"#257",			/* 257 = nosys */
	"#258",			/* 258 = nosys */
	"#259",			/* 259 = nosys */
	"#260",			/* 260 = nosys */
	"#261",			/* 261 = nosys */
	"#262",			/* 262 = nosys */
	"#263",			/* 263 = nosys */
	"#264",			/* 264 = nosys */
	"#265",			/* 265 = nosys */
	"#266",			/* 266 = nosys */
	"#267",			/* 267 = nosys */
	"#268",			/* 268 = nosys */
	"#269",			/* 269 = nosys */
	"#270",			/* 270 = nosys */
	"#271",			/* 271 = nosys */
	"old.getdents",		/* 272 = old getdents */
	"#273",			/* 273 = nosys */
	"lchmod",			/* 274 = lchmod */
	"netbsd_lchown",			/* 275 = netbsd_lchown */
	"lutimes",			/* 276 = lutimes */
	"netbsd_msync",			/* 277 = netbsd_msync */
	"obs_{",			/* 278 = obsolete { */
	"obs_{",			/* 279 = obsolete { */
	"obs_{",			/* 280 = obsolete { */
	"#281",			/* 281 = nosys */
	"#282",			/* 282 = nosys */
	"#283",			/* 283 = nosys */
	"#284",			/* 284 = nosys */
	"#285",			/* 285 = nosys */
	"#286",			/* 286 = nosys */
	"#287",			/* 287 = nosys */
	"#288",			/* 288 = nosys */
	"extpreadv",			/* 289 = extpreadv */
	"extpwritev",			/* 290 = extpwritev */
	"#291",			/* 291 = nosys */
	"#292",			/* 292 = nosys */
	"#293",			/* 293 = nosys */
	"#294",			/* 294 = nosys */
	"#295",			/* 295 = nosys */
	"#296",			/* 296 = nosys */
	"fhstatfs",			/* 297 = fhstatfs */
	"fhopen",			/* 298 = fhopen */
	"old.fhstat",		/* 299 = old fhstat */
	"modnext",			/* 300 = modnext */
	"modstat",			/* 301 = modstat */
	"modfnext",			/* 302 = modfnext */
	"modfind",			/* 303 = modfind */
	"kldload",			/* 304 = kldload */
	"kldunload",			/* 305 = kldunload */
	"kldfind",			/* 306 = kldfind */
	"kldnext",			/* 307 = kldnext */
	"kldstat",			/* 308 = kldstat */
	"kldfirstmod",			/* 309 = kldfirstmod */
	"getsid",			/* 310 = getsid */
	"setresuid",			/* 311 = setresuid */
	"setresgid",			/* 312 = setresgid */
	"obs_signanosleep",			/* 313 = obsolete signanosleep */
	"aio_return",			/* 314 = aio_return */
	"aio_suspend",			/* 315 = aio_suspend */
	"aio_cancel",			/* 316 = aio_cancel */
	"aio_error",			/* 317 = aio_error */
	"aio_read",			/* 318 = aio_read */
	"aio_write",			/* 319 = aio_write */
	"lio_listio",			/* 320 = lio_listio */
	"yield",			/* 321 = yield */
	"thr_sleep",			/* 322 = thr_sleep */
	"thr_wakeup",			/* 323 = thr_wakeup */
	"mlockall",			/* 324 = mlockall */
	"munlockall",			/* 325 = munlockall */
	"__getcwd",			/* 326 = __getcwd */
	"sched_setparam",			/* 327 = sched_setparam */
	"sched_getparam",			/* 328 = sched_getparam */
	"sched_setscheduler",			/* 329 = sched_setscheduler */
	"sched_getscheduler",			/* 330 = sched_getscheduler */
	"sched_yield",			/* 331 = sched_yield */
	"sched_get_priority_max",			/* 332 = sched_get_priority_max */
	"sched_get_priority_min",			/* 333 = sched_get_priority_min */
	"sched_rr_get_interval",			/* 334 = sched_rr_get_interval */
	"utrace",			/* 335 = utrace */
	"obs_freebsd4_sendfile",			/* 336 = obsolete freebsd4_sendfile */
	"kldsym",			/* 337 = kldsym */
	"jail",			/* 338 = jail */
	"#339",			/* 339 = pioctl */
	"sigprocmask",			/* 340 = sigprocmask */
	"sigsuspend",			/* 341 = sigsuspend */
	"sigaction",			/* 342 = sigaction */
	"sigpending",			/* 343 = sigpending */
	"sigreturn",			/* 344 = sigreturn */
	"sigtimedwait",			/* 345 = sigtimedwait */
	"sigwaitinfo",			/* 346 = sigwaitinfo */
	"__acl_get_file",			/* 347 = __acl_get_file */
	"__acl_set_file",			/* 348 = __acl_set_file */
	"__acl_get_fd",			/* 349 = __acl_get_fd */
	"__acl_set_fd",			/* 350 = __acl_set_fd */
	"__acl_delete_file",			/* 351 = __acl_delete_file */
	"__acl_delete_fd",			/* 352 = __acl_delete_fd */
	"__acl_aclcheck_file",			/* 353 = __acl_aclcheck_file */
	"__acl_aclcheck_fd",			/* 354 = __acl_aclcheck_fd */
	"extattrctl",			/* 355 = extattrctl */
	"extattr_set_file",			/* 356 = extattr_set_file */
	"extattr_get_file",			/* 357 = extattr_get_file */
	"extattr_delete_file",			/* 358 = extattr_delete_file */
	"aio_waitcomplete",			/* 359 = aio_waitcomplete */
	"getresuid",			/* 360 = getresuid */
	"getresgid",			/* 361 = getresgid */
	"kqueue",			/* 362 = kqueue */
	"kevent",			/* 363 = kevent */
	"sctp_peeloff",			/* 364 = sctp_peeloff */
	"#365",			/* 365 = nosys */
	"#366",			/* 366 = nosys */
	"#367",			/* 367 = nosys */
	"#368",			/* 368 = nosys */
	"#369",			/* 369 = nosys */
	"#370",			/* 370 = nosys */
	"#371",			/* 371 = nosys */
	"#372",			/* 372 = nosys */
	"#373",			/* 373 = nosys */
	"#374",			/* 374 = nosys */
	"#375",			/* 375 = nosys */
	"#376",			/* 376 = nosys */
	"#377",			/* 377 = nosys */
	"#378",			/* 378 = nosys */
	"#379",			/* 379 = nosys */
	"#380",			/* 380 = nosys */
	"#381",			/* 381 = nosys */
	"#382",			/* 382 = nosys */
	"#383",			/* 383 = nosys */
	"#384",			/* 384 = nosys */
	"#385",			/* 385 = nosys */
	"#386",			/* 386 = nosys */
	"#387",			/* 387 = nosys */
	"#388",			/* 388 = nosys */
	"#389",			/* 389 = nosys */
	"#390",			/* 390 = nosys */
	"#391",			/* 391 = nosys */
	"uuidgen",			/* 392 = uuidgen */
	"sendfile",			/* 393 = sendfile */
	"#394",			/* 394 = nosys */
	"#395",			/* 395 = nosys */
	"#396",			/* 396 = nosys */
	"#397",			/* 397 = nosys */
	"#398",			/* 398 = nosys */
	"#399",			/* 399 = nosys */
	"#400",			/* 400 = nosys */
	"#401",			/* 401 = nosys */
	"#402",			/* 402 = nosys */
	"#403",			/* 403 = nosys */
	"#404",			/* 404 = nosys */
	"#405",			/* 405 = nosys */
	"#406",			/* 406 = nosys */
	"#407",			/* 407 = nosys */
	"#408",			/* 408 = nosys */
	"#409",			/* 409 = nosys */
	"#410",			/* 410 = nosys */
	"#411",			/* 411 = nosys */
	"#412",			/* 412 = nosys */
	"#413",			/* 413 = nosys */
	"#414",			/* 414 = nosys */
	"#415",			/* 415 = nosys */
	"#416",			/* 416 = nosys */
	"#417",			/* 417 = nosys */
	"#418",			/* 418 = nosys */
	"#419",			/* 419 = nosys */
	"#420",			/* 420 = nosys */
	"#421",			/* 421 = nosys */
	"#422",			/* 422 = nosys */
	"#423",			/* 423 = nosys */
	"#424",			/* 424 = nosys */
	"#425",			/* 425 = nosys */
	"#426",			/* 426 = nosys */
	"#427",			/* 427 = nosys */
	"#428",			/* 428 = nosys */
	"#429",			/* 429 = nosys */
	"#430",			/* 430 = nosys */
	"#431",			/* 431 = nosys */
	"#432",			/* 432 = nosys */
	"#433",			/* 433 = nosys */
	"#434",			/* 434 = nosys */
	"#435",			/* 435 = nosys */
	"#436",			/* 436 = nosys */
	"#437",			/* 437 = nosys */
	"#438",			/* 438 = nosys */
	"#439",			/* 439 = nosys */
	"#440",			/* 440 = nosys */
	"#441",			/* 441 = nosys */
	"#442",			/* 442 = nosys */
	"#443",			/* 443 = nosys */
	"#444",			/* 444 = nosys */
	"#445",			/* 445 = nosys */
	"#446",			/* 446 = nosys */
	"#447",			/* 447 = nosys */
	"#448",			/* 448 = nosys */
	"#449",			/* 449 = nosys */
	"varsym_set",			/* 450 = varsym_set */
	"varsym_get",			/* 451 = varsym_get */
	"varsym_list",			/* 452 = varsym_list */
	"upc_register",			/* 453 = upc_register */
	"upc_control",			/* 454 = upc_control */
	"caps_sys_service",			/* 455 = caps_sys_service */
	"caps_sys_client",			/* 456 = caps_sys_client */
	"caps_sys_close",			/* 457 = caps_sys_close */
	"caps_sys_put",			/* 458 = caps_sys_put */
	"caps_sys_reply",			/* 459 = caps_sys_reply */
	"caps_sys_get",			/* 460 = caps_sys_get */
	"caps_sys_wait",			/* 461 = caps_sys_wait */
	"caps_sys_abort",			/* 462 = caps_sys_abort */
	"caps_sys_getgen",			/* 463 = caps_sys_getgen */
	"caps_sys_setgen",			/* 464 = caps_sys_setgen */
	"exec_sys_register",			/* 465 = exec_sys_register */
	"exec_sys_unregister",			/* 466 = exec_sys_unregister */
	"sys_checkpoint",			/* 467 = sys_checkpoint */
	"mountctl",			/* 468 = mountctl */
	"umtx_sleep",			/* 469 = umtx_sleep */
	"umtx_wakeup",			/* 470 = umtx_wakeup */
	"jail_attach",			/* 471 = jail_attach */
	"set_tls_area",			/* 472 = set_tls_area */
	"get_tls_area",			/* 473 = get_tls_area */
	"closefrom",			/* 474 = closefrom */
	"stat",			/* 475 = stat */
	"fstat",			/* 476 = fstat */
	"lstat",			/* 477 = lstat */
	"fhstat",			/* 478 = fhstat */
	"getdirentries",			/* 479 = getdirentries */
	"getdents",			/* 480 = getdents */
	"usched_set",			/* 481 = usched_set */
	"extaccept",			/* 482 = extaccept */
	"extconnect",			/* 483 = extconnect */
	"syslink",			/* 484 = syslink */
	"mcontrol",			/* 485 = mcontrol */
	"vmspace_create",			/* 486 = vmspace_create */
	"vmspace_destroy",			/* 487 = vmspace_destroy */
	"vmspace_ctl",			/* 488 = vmspace_ctl */
	"vmspace_mmap",			/* 489 = vmspace_mmap */
	"vmspace_munmap",			/* 490 = vmspace_munmap */
	"vmspace_mcontrol",			/* 491 = vmspace_mcontrol */
	"vmspace_pread",			/* 492 = vmspace_pread */
	"vmspace_pwrite",			/* 493 = vmspace_pwrite */
	"extexit",			/* 494 = extexit */
	"lwp_create",			/* 495 = lwp_create */
	"lwp_gettid",			/* 496 = lwp_gettid */
	"lwp_kill",			/* 497 = lwp_kill */
	"lwp_rtprio",			/* 498 = lwp_rtprio */
};
