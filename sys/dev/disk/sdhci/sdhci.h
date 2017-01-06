/*-
 * Copyright (c) 2008 Alexander Motin <mav@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD: src/sys/dev/sdhci/sdhci.h,v 1.1 2008/10/21 20:33:40 mav Exp $
 */

#ifndef	__SDHCI_H__
#define	__SDHCI_H__

#define DMA_BLOCK_SIZE	4096
#define DMA_BOUNDARY	0	/* DMA reload every 4K */

/* Controller doesn't honor resets unless we touch the clock register */
#define SDHCI_QUIRK_CLOCK_BEFORE_RESET			(1<<0)
/* Controller really supports SDMA */
#define SDHCI_QUIRK_FORCE_SDMA				(1<<1)
/* Controller has unusable DMA engine */
#define SDHCI_QUIRK_BROKEN_DMA				(1<<2)
/* Controller doesn't like to be reset when there is no card inserted. */
#define SDHCI_QUIRK_NO_CARD_NO_RESET			(1<<3)
/* Controller has flaky internal state so reset it on each ios change */
#define SDHCI_QUIRK_RESET_ON_IOS			(1<<4)
/* Controller can only DMA chunk sizes that are a multiple of 32 bits */
#define SDHCI_QUIRK_32BIT_DMA_SIZE			(1<<5)
/* Controller needs to be reset after each request to stay stable */
#define SDHCI_QUIRK_RESET_AFTER_REQUEST			(1<<6)
/* Controller has an off-by-one issue with timeout value */
#define SDHCI_QUIRK_INCR_TIMEOUT_CONTROL		(1<<7)
/* Controller has broken read timings */
#define SDHCI_QUIRK_BROKEN_TIMINGS			(1<<8)
/* Controller needs lowered frequency */
#define	SDHCI_QUIRK_LOWER_FREQUENCY			(1<<9)
/* Data timeout is invalid, should use SD clock */
#define	SDHCI_QUIRK_DATA_TIMEOUT_USES_SDCLK		(1<<10)
/* Timeout value is invalid, should be overriden */
#define	SDHCI_QUIRK_BROKEN_TIMEOUT_VAL			(1<<11)
/* SDHCI_CAPABILITIES is invalid */
#define	SDHCI_QUIRK_MISSING_CAPS			(1<<12)
/* Hardware shifts the 136-bit response, don't do it in software. */
#define	SDHCI_QUIRK_DONT_SHIFT_RESPONSE			(1<<13)
/* Wait to see reset bit asserted before waiting for de-asserted  */
#define	SDHCI_QUIRK_WAITFOR_RESET_ASSERTED		(1<<14)
/* Leave controller in standard mode when putting card in HS mode. */
#define	SDHCI_QUIRK_DONT_SET_HISPD_BIT			(1<<15)
/* Alternate clock source is required when supplying a 400 KHz clock. */
#define	SDHCI_QUIRK_BCM577XX_400KHZ_CLKSRC		(1<<16)
/* Allow ADMA2 to be used. */
#define	SDHCI_QUIRK_WHITELIST_ADMA2			(1<<17)

/*
 * Controller registers
 */
#define SDHCI_SDMA_ADDRESS	0x00

#define SDHCI_BLOCK_SIZE	0x04
#define  SDHCI_MAKE_BLKSZ(dma, blksz) (((dma & 0x7) << 12) | (blksz & 0xFFF))

#define SDHCI_BLOCK_COUNT	0x06

#define SDHCI_ARGUMENT		0x08

#define SDHCI_TRANSFER_MODE	0x0C
#define  SDHCI_TRNS_DMA		0x01
#define  SDHCI_TRNS_BLK_CNT_EN	0x02
#define  SDHCI_TRNS_ACMD12	0x04
#define  SDHCI_TRNS_READ	0x10
#define  SDHCI_TRNS_MULTI	0x20

#define SDHCI_COMMAND_FLAGS	0x0E
#define  SDHCI_CMD_RESP_NONE	0x00
#define  SDHCI_CMD_RESP_LONG	0x01
#define  SDHCI_CMD_RESP_SHORT	0x02
#define  SDHCI_CMD_RESP_SHORT_BUSY 0x03
#define  SDHCI_CMD_RESP_MASK	0x03
#define  SDHCI_CMD_CRC		0x08
#define  SDHCI_CMD_INDEX	0x10
#define  SDHCI_CMD_DATA		0x20
#define  SDHCI_CMD_TYPE_NORMAL	0x00
#define  SDHCI_CMD_TYPE_SUSPEND	0x40
#define  SDHCI_CMD_TYPE_RESUME	0x80
#define  SDHCI_CMD_TYPE_ABORT	0xc0
#define  SDHCI_CMD_TYPE_MASK	0xc0

#define SDHCI_COMMAND		0x0F

#define SDHCI_RESPONSE		0x10

#define SDHCI_BUFFER		0x20

#define SDHCI_PRESENT_STATE	0x24
#define  SDHCI_CMD_INHIBIT	0x00000001
#define  SDHCI_DAT_INHIBIT	0x00000002
#define  SDHCI_DAT_ACTIVE	0x00000004
#define  SDHCI_RETUNE_REQUEST	0x00000008
#define  SDHCI_DOING_WRITE	0x00000100
#define  SDHCI_DOING_READ	0x00000200
#define  SDHCI_SPACE_AVAILABLE	0x00000400
#define  SDHCI_DATA_AVAILABLE	0x00000800
#define  SDHCI_CARD_PRESENT	0x00010000
#define  SDHCI_CARD_STABLE	0x00020000
#define  SDHCI_CARD_PIN		0x00040000
#define  SDHCI_WRITE_PROTECT	0x00080000
#define  SDHCI_STATE_DAT_MASK	0x00f00000
#define  SDHCI_STATE_CMD	0x01000000

#define SDHCI_HOST_CONTROL 	0x28
#define  SDHCI_CTRL_LED		0x01
#define  SDHCI_CTRL_4BITBUS	0x02
#define  SDHCI_CTRL_HISPD	0x04
#define  SDHCI_CTRL_SDMA	0x00
#define  SDHCI_CTRL_ADMA2	0x10
#define  SDHCI_CTRL_ADMA264	0x18
#define  SDHCI_CTRL_DMA_MASK	0x18
#define  SDHCI_CTRL_8BITBUS	0x20
#define  SDHCI_CTRL_CARD_DET	0x40
#define  SDHCI_CTRL_FORCE_CARD	0x80

#define SDHCI_POWER_CONTROL	0x29
#define  SDHCI_POWER_ON		0x01
#define  SDHCI_POWER_180	0x0A
#define  SDHCI_POWER_300	0x0C
#define  SDHCI_POWER_330	0x0E

#define SDHCI_BLOCK_GAP_CONTROL	0x2A

#define SDHCI_WAKE_UP_CONTROL	0x2B

#define SDHCI_CLOCK_CONTROL	0x2C
#define  SDHCI_DIVIDER_MASK	0xff
#define  SDHCI_DIVIDER_MASK_LEN	8
#define  SDHCI_DIVIDER_SHIFT	8
#define  SDHCI_DIVIDER_HI_MASK	3
#define  SDHCI_DIVIDER_HI_SHIFT	6
#define  SDHCI_CLOCK_CARD_EN	0x0004
#define  SDHCI_CLOCK_INT_STABLE	0x0002
#define  SDHCI_CLOCK_INT_EN	0x0001

#define SDHCI_TIMEOUT_CONTROL	0x2E

#define SDHCI_SOFTWARE_RESET	0x2F
#define  SDHCI_RESET_ALL	0x01
#define  SDHCI_RESET_CMD	0x02
#define  SDHCI_RESET_DATA	0x04

#define SDHCI_INT_STATUS	0x30
#define SDHCI_INT_ENABLE	0x34
#define SDHCI_SIGNAL_ENABLE	0x38
#define  SDHCI_INT_RESPONSE	0x00000001
#define  SDHCI_INT_DATA_END	0x00000002
#define  SDHCI_INT_BLOCK_GAP	0x00000004
#define  SDHCI_INT_DMA_END	0x00000008
#define  SDHCI_INT_SPACE_AVAIL	0x00000010
#define  SDHCI_INT_DATA_AVAIL	0x00000020
#define  SDHCI_INT_CARD_INSERT	0x00000040
#define  SDHCI_INT_CARD_REMOVE	0x00000080
#define  SDHCI_INT_CARD_INT	0x00000100
#define  SDHCI_INT_INT_A	0x00000200
#define  SDHCI_INT_INT_B	0x00000400
#define  SDHCI_INT_INT_C	0x00000800
#define  SDHCI_INT_RETUNE	0x00001000
#define  SDHCI_INT_ERROR	0x00008000
#define  SDHCI_INT_TIMEOUT	0x00010000
#define  SDHCI_INT_CRC		0x00020000
#define  SDHCI_INT_END_BIT	0x00040000
#define  SDHCI_INT_INDEX	0x00080000
#define  SDHCI_INT_DATA_TIMEOUT	0x00100000
#define  SDHCI_INT_DATA_CRC	0x00200000
#define  SDHCI_INT_DATA_END_BIT	0x00400000
#define  SDHCI_INT_BUS_POWER	0x00800000
#define  SDHCI_INT_ACMD12ERR	0x01000000
#define  SDHCI_INT_ADMAERR	0x02000000
#define  SDHCI_INT_TUNEERR	0x04000000

#define  SDHCI_INT_NORMAL_MASK	0x00007FFF
#define  SDHCI_INT_ERROR_MASK	0xFFFF8000

#define  SDHCI_INT_CMD_ERROR_MASK 	(SDHCI_INT_TIMEOUT | \
		SDHCI_INT_CRC | SDHCI_INT_END_BIT | SDHCI_INT_INDEX)

#define  SDHCI_INT_CMD_MASK	(SDHCI_INT_RESPONSE | SDHCI_INT_CMD_ERROR_MASK)

#define  SDHCI_INT_DATA_MASK	(SDHCI_INT_DATA_END | SDHCI_INT_DMA_END | \
		SDHCI_INT_DATA_AVAIL | SDHCI_INT_SPACE_AVAIL | \
		SDHCI_INT_DATA_TIMEOUT | SDHCI_INT_DATA_CRC | \
		SDHCI_INT_DATA_END_BIT)

#define SDHCI_ACMD12_ERR	0x3C

#define SDHCI_HOST_CONTROL2	0x3E
#define  SDHCI_CTRL2_PRESET_VALUE	0x8000
#define  SDHCI_CTRL2_ASYNC_INTR	0x4000
#define  SDHCI_CTRL2_SAMPLING_CLOCK	0x0080
#define  SDHCI_CTRL2_EXEC_TUNING	0x0040
#define  SDHCI_CTRL2_DRIVER_TYPE_MASK	0x0030
#define  SDHCI_CTRL2_DRIVER_TYPE_B	0x0000
#define  SDHCI_CTRL2_DRIVER_TYPE_A	0x0010
#define  SDHCI_CTRL2_DRIVER_TYPE_C	0x0020
#define  SDHCI_CTRL2_DRIVER_TYPE_D	0x0030
#define  SDHCI_CTRL2_S18_ENABLE	0x0008
#define  SDHCI_CTRL2_UHS_MASK	0x0007
#define  SDHCI_CTRL2_UHS_SDR12	0x0000
#define  SDHCI_CTRL2_UHS_SDR25	0x0001
#define  SDHCI_CTRL2_UHS_SDR50	0x0002
#define  SDHCI_CTRL2_UHS_SDR104	0x0003
#define  SDHCI_CTRL2_UHS_DDR50	0x0004

#define SDHCI_CAPABILITIES	0x40
#define  SDHCI_TIMEOUT_CLK_MASK	0x0000003F
#define  SDHCI_TIMEOUT_CLK_SHIFT 0
#define  SDHCI_TIMEOUT_CLK_UNIT	0x00000080
#define  SDHCI_CLOCK_BASE_MASK	0x00003F00
#define  SDHCI_CLOCK_V3_BASE_MASK	0x0000FF00
#define  SDHCI_CLOCK_BASE_SHIFT	8
#define  SDHCI_MAX_BLOCK_MASK	0x00030000
#define  SDHCI_MAX_BLOCK_SHIFT  16
#define  SDHCI_CAN_DO_8BITBUS	0x00040000
#define  SDHCI_CAN_DO_ADMA2	0x00080000
#define  SDHCI_CAN_DO_HISPD	0x00200000
#define  SDHCI_CAN_DO_DMA	0x00400000
#define  SDHCI_CAN_DO_SUSPEND	0x00800000
#define  SDHCI_CAN_VDD_330	0x01000000
#define  SDHCI_CAN_VDD_300	0x02000000
#define  SDHCI_CAN_VDD_180	0x04000000
#define  SDHCI_CAN_DO_64BIT	0x10000000
#define  SDHCI_CAN_ASYNC_INTR	0x20000000
#define  SDHCI_SLOTTYPE_MASK	0xC0000000
#define  SDHCI_SLOTTYPE_REMOVABLE	0x00000000
#define  SDHCI_SLOTTYPE_EMBEDDED	0x40000000
#define  SDHCI_SLOTTYPE_SHARED	0x80000000

#define SDHCI_CAPABILITIES2	0x44
#define  SDHCI_CAN_SDR50	0x00000001
#define  SDHCI_CAN_SDR104	0x00000002
#define  SDHCI_CAN_DDR50	0x00000004
#define  SDHCI_CAN_DRIVE_TYPE_A	0x00000010
#define  SDHCI_CAN_DRIVE_TYPE_C	0x00000020
#define  SDHCI_CAN_DRIVE_TYPE_D	0x00000040
#define  SDHCI_RETUNE_CNT_MASK	0x00000F00
#define  SDHCI_RETUNE_CNT_SHIFT	8
#define  SDHCI_TUNE_SDR50	0x00002000
#define  SDHCI_RETUNE_MODES_MASK  0x0000C000
#define  SDHCI_RETUNE_MODES_SHIFT 14
#define  SDHCI_CLOCK_MULT_MASK	0x00FF0000
#define  SDHCI_CLOCK_MULT_SHIFT	16

#define SDHCI_MAX_CURRENT	0x48
#define SDHCI_FORCE_AUTO_EVENT	0x50
#define SDHCI_FORCE_INTR_EVENT	0x52

#define SDHCI_ADMA_ERR		0x54
#define  SDHCI_ADMA_ERR_LENGTH	0x04
#define  SDHCI_ADMA_ERR_STATE_MASK	0x03
#define  SDHCI_ADMA_ERR_STATE_STOP	0x00
#define  SDHCI_ADMA_ERR_STATE_FDS	0x01
#define  SDHCI_ADMA_ERR_STATE_TFR	0x03

#define SDHCI_ADMA_ADDRESS_LOW	0x58
#define SDHCI_ADMA_ADDRESS_HI	0x5C

#define SDHCI_PRESET_VALUE	0x60
#define SDHCI_SHARED_BUS_CTRL	0xE0

#define SDHCI_SLOT_INT_STATUS	0xFC

#define SDHCI_HOST_VERSION	0xFE
#define  SDHCI_VENDOR_VER_MASK	0xFF00
#define  SDHCI_VENDOR_VER_SHIFT	8
#define  SDHCI_SPEC_VER_MASK	0x00FF
#define  SDHCI_SPEC_VER_SHIFT	0
#define	SDHCI_SPEC_100		0
#define	SDHCI_SPEC_200		1
#define	SDHCI_SPEC_300		2
#define	SDHCI_SPEC_400		3


/*
 * ADMA2 descriptors
 */
#define SDHCI_ADMA2_ATTR_VALID	0x0001
#define SDHCI_ADMA2_ATTR_END	0x0002
#define SDHCI_ADMA2_ATTR_INT	0x0004
#define SDHCI_ADMA2_ATTR_OP_MASK 0x0030
#define SDHCI_ADMA2_ATTR_OP_NOP	0x0000
#define SDHCI_ADMA2_ATTR_OP_TRAN 0x0020
#define SDHCI_ADMA2_ATTR_OP_LINK 0x0030

/* DMA buffer constants for our ADMA2 descriptor table */
#define SDHCI_ADMA2_DESCBUF_SIZE	PAGE_SIZE
#define SDHCI_ADMA2_DESC_COUNT	\
	(SDHCI_ADMA2_DESCBUF_SIZE / sizeof(struct sdhci_adma2_desc32))

/* The maximum data length for one descriptor entry */
#define SDHCI_ADMA2_MAX_SEGSIZE	32768	/* 65536 is broken on some chipsets */

struct sdhci_adma2_desc32 {
	uint16_t attribute;
	uint16_t length;
	uint32_t address;
} __packed;

struct sdhci_adma2_desc64 {
	uint16_t attribute;
	uint16_t length;
	uint64_t address;
} __packed;

_Static_assert(SDHCI_ADMA2_DESC_COUNT >= MAXPHYS / PAGE_SIZE + 1,
    "SDHCI_ADMA2_DESC_COUNT is not big enough");

struct sdhci_slot {
	u_int		quirks;		/* Chip specific quirks */
	u_int		caps;		/* Override SDHCI_CAPABILITIES */
	device_t	bus;		/* Bus device */
	device_t	dev;		/* Slot device */
	u_char		num;		/* Slot number */
	u_char		opt;		/* Slot options */
#define SDHCI_HAVE_SDMA			1
#define SDHCI_PLATFORM_TRANSFER		2
#define SDHCI_HAVE_ADMA2		4
	u_char		version;
	int		timeout;	/* Transfer timeout */
	int		failures;	/* N Failures in a row */
	uint32_t	max_clk;	/* Max possible freq */
	uint32_t	timeout_clk;	/* Timeout freq */
	bus_dmamem_t	sdma_mem;	/* DMA block for SDMA */
	bus_dmamem_t	adma2_descs;	/* DMA block for ADMA2 descriptors */
	bus_dma_tag_t	adma2_tag;	/* DMA tag for ADMA2 data buffer */
	bus_dmamap_t	adma2_map;	/* DMA map for ADMA2 data buffer */
	struct task	card_task;	/* Card presence check task */
	struct callout	card_callout;	/* Card insert delay callout */
	struct callout	timeout_callout;/* Card command/data response timeout */
	struct mmc_host host;		/* Host parameters */
	struct mmc_request *req;	/* Current request */
	struct mmc_command *curcmd;	/* Current command of current request */
	
	uint32_t	intmask;	/* Current interrupt mask */
	uint32_t	clock;		/* Current clock freq. */
	size_t		offset;		/* Data buffer offset */
	uint8_t		hostctrl;	/* Current host control register */
	u_char		power;		/* Current power */
	u_char		bus_busy;	/* Bus busy status */
	u_char		cmd_done;	/* CMD command part done flag */
	u_char		data_done;	/* DAT command part done flag */
	u_char		flags;		/* Request execution flags */
#define CMD_STARTED		1
#define STOP_STARTED		2
#define SDHCI_USE_SDMA		4	/* Use SDMA for this req. */
#define PLATFORM_DATA_STARTED	8	/* Data transfer is handled by platform */
#define SDHCI_USE_ADMA2		16	/* Use ADMA2 for this req. */
	struct lock	lock;		/* Slot mutex */
};

int sdhci_generic_read_ivar(device_t bus, device_t child, int which, uintptr_t *result);
int sdhci_generic_write_ivar(device_t bus, device_t child, int which, uintptr_t value);
int sdhci_init_slot(device_t dev, struct sdhci_slot *slot, int num);
void sdhci_start_slot(struct sdhci_slot *slot);
/* performs generic clean-up for platform transfers */
void sdhci_finish_data(struct sdhci_slot *slot);
int sdhci_cleanup_slot(struct sdhci_slot *slot);
int sdhci_generic_suspend(struct sdhci_slot *slot);
int sdhci_generic_resume(struct sdhci_slot *slot);
int sdhci_generic_update_ios(device_t brdev, device_t reqdev);
int sdhci_generic_request(device_t brdev, device_t reqdev, struct mmc_request *req);
int sdhci_generic_get_ro(device_t brdev, device_t reqdev);
int sdhci_generic_acquire_host(device_t brdev, device_t reqdev);
int sdhci_generic_release_host(device_t brdev, device_t reqdev);
void sdhci_generic_intr(struct sdhci_slot *slot);
uint32_t sdhci_generic_min_freq(device_t brdev, struct sdhci_slot *slot);
boolean_t sdhci_generic_get_card_present(device_t brdev, struct sdhci_slot *slot);

#endif	/* __SDHCI_H__ */
