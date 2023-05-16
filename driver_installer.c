#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>  

#include <conio.h>

#include "libwdi.h"

#define RECOVERY_VID 0x2CA3
#define RECOVERY_PID 0x40
#define RECOVERY_DESC "DJI Recovery"
#define RECOVERY_INF_NAME "dji_recovery.inf"

struct target
{
    unsigned short vid;
    unsigned short pid;
    bool is_composite;
    unsigned char iface;
    char* vendor_name;
    char* description; 
    char* inf_name;
    int driver_type;

};

int numtargets=3;
static struct target targets[2] = {
                    {0x2CA3, 0x40, false, 0, "DJI", "DJI Recovery", "dji_recovery.inf", WDI_LIBUSB0},
                    {0x18D1, 0xD00D, false, 0, "DJI", "Kedacom Fastboot/ADB", "android_winusb.inf", WDI_USER},
                    // {0x2CA3, 0x001F, true, 0x03, "DJI", "DJI RMVT Bulk", "dji_rmvt_bulk.inf", WDI_WINUSB} // not used
                };

void waitforexit(int r) {
    printf("Press any key to close the installer.\n");
    getch(); 
    exit(r);
}
int main(int argc, char **argv) {
    if(argc == 2 && strncmp(argv[1], "-v", 2) == 0) {
        wdi_set_log_level(WDI_LOG_LEVEL_DEBUG);
    }
    else {
        wdi_set_log_level(WDI_LOG_LEVEL_NONE);
    }
    struct target* ptr = targets;
    printf("Drone-Hacks.com driver installer v1.0, shout-out fpv-wtf! Thanks!\n", ptr->description); //Thanks to FPV.WTF for the permission to use this :)
    printf("Installing drivers, this may take a few minutes.\n", ptr->description);

    for (int i=0; i<numtargets; i++, ptr++ ) {
        struct wdi_device_info recovery_dev = {NULL, ptr->vid, ptr->pid, ptr->is_composite, ptr->iface,  ptr->description, NULL, NULL, NULL, NULL, NULL, 0};
        int r;
        static struct wdi_options_prepare_driver opd = { 0 };
        static struct wdi_options_install_driver oid = { 0 };
        opd.driver_type = ptr->driver_type;
        opd.vendor_name = ptr->vendor_name;

        r = wdi_prepare_driver(&recovery_dev, NULL, ptr->inf_name, &opd);
        if (r != WDI_SUCCESS) {
            printf("Error: Unable to prepare %s driver for installation: %s.\n", ptr->description, wdi_strerror(r));
            waitforexit(1);
        }
        r = wdi_install_driver(&recovery_dev, NULL, ptr->inf_name, &oid);
        if(r != WDI_SUCCESS) {
            printf("Error: Unable to install %s driver: %s.\n", ptr->description, wdi_strerror(r));
            waitforexit(1);
        }

    }
    printf("Drivers installed successfully.\n\n");
    waitforexit(0);
 
}
