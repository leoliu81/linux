#ifndef _MWGENERIC_H_
#define _MWGENERIC_H_

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/io.h>
#include <linux/wait.h>
#include <linux/dma-mapping.h>
#include <linux/delay.h>
#include <linux/debugfs.h>
#include <linux/uaccess.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/clk.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/mm.h>

struct mw_dma_info {
	void				*virt;
	dma_addr_t			phys;
	size_t				size;
};

/* Struct types */
struct ipcore_info {
    const char 			        *name;
    struct resource 		    *mem;
    void __iomem 		        *regs;
    struct device               *dev;
    struct device				*char_device;
	struct cdev 		        cdev;
    dev_t 			            dev_id;
    int 			            irq;
    struct fasync_struct 	    *asyncq;
	char						memtype;
/*
 * DMA Virtual and physical address
 */
    struct mw_dma_info	        dma_info;

/*
 * I2C Controller and EEPROM
 */
    struct i2c_client           *i2c;
};


#define MWGENERIC_MEMTYPE_NORMAL		0
#define MWGENERIC_MEMTYPE_NOMEM			1
#define MWGENERIC_MEMTYPE_NOMEM_STR		"nomem"

#define MWGENERIC_MAX_DEVTYPE 32
#define	MWGENERIC_DEVNAME_LEN 32

struct mwgeneric_info {
	char			devname[MWGENERIC_DEVNAME_LEN];
	u16				ss_vid;
	u16				ss_did;
	dev_t			devid;
	int				devcnt;
};

#endif
