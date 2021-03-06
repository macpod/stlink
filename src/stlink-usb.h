/* 
 * File:   stlink-usb.h
 * Author: karl
 *
 * Created on October 1, 2011, 11:29 PM
 */

#ifndef STLINK_USB_H
#define	STLINK_USB_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <libusb-1.0/libusb.h>
#include "stlink-common.h"
    
#define STLINK_CMD_SIZE 16

#if defined(CONFIG_USE_LIBUSB)
    struct stlink_libusb {
        libusb_context* libusb_ctx;
        libusb_device_handle* usb_handle;
        struct libusb_transfer* req_trans;
        struct libusb_transfer* rep_trans;
        unsigned int ep_req;
        unsigned int ep_rep;
    };
#else
#error "it's all bad!"
    struct stlink_libusb {};
#endif

    
    stlink_t* stlink_open_usb(const char *dev_name, const int verbose);


#ifdef	__cplusplus
}
#endif

#endif	/* STLINK_USB_H */

