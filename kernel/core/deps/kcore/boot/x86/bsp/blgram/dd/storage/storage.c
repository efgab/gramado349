// storage.c
// Storage support.
// Created by Fred Nora.

#include "../../bl.h"


struct boot_disk_d  BootDisk;


// read_lba: 
// Read a LBA from the disk.
void read_lba( unsigned long address, unsigned long lba )
{
// Called by fsLoadFile in fs.c

    // if ( address == 0 ){}

    //printf("read_lba:\n");

    if (BootDisk.initialized != TRUE){
        printf("read_lba: BootDisk not initialized\n");
        goto fail;
    }

    int ControllerType = BootDisk.controller_type;
    switch (ControllerType)
    {
        case CONTROLLER_TYPE_AHCI:
            //ahci_read_sector(...)
            break;

        // see: libata.c
        case CONTROLLER_TYPE_ATA:
            //printf("CONTROLLER_TYPE_ATA\n");
            ata_read_sector ( address, lba, 0, 0 );
            break;
        
        default:
            printf("read_lba: Invalid controller type\n");
            goto fail;
            break;
    }

//OK:
    return;

fail:
    return;
}

// write_lba: 
// Write a LBA into the disk.
void write_lba ( unsigned long address, unsigned long lba )
{
// Called by fsLoadFile in fs.c

    // if ( address == 0 ){}

    if (BootDisk.initialized != TRUE)
    {
        printf("write_lba: BootDisk not initialized\n");
        goto fail;
    }

    int ControllerType = BootDisk.controller_type;
    switch (ControllerType)
    {
        case CONTROLLER_TYPE_AHCI:
            //ahci_write_sector(...)
            break;

        case CONTROLLER_TYPE_ATA:
            ata_write_sector ( address, lba, 0, 0 );
            break;
        
        default:
            printf("write_lba: Invalid controller type\n");
            goto fail;
            break;
    }

//OK:
    return;

fail:
    return;
}

// Called by main.c
int storage_initialize(void)
{
    int Status = FALSE;

// AHCI:
// Try initialization for the ahci mode.
// AHCI handles only SATA interface standard.
    Status = (int) ahci_initialize();
    if (Status != TRUE){
        // Nothing in case of failure.
    }

// ATA:
// Try initialization for the ata mode.
// ATA handles PATA and SATA intarface standards.
    Status = (int) ata_initialize();
    if (Status != TRUE){
        return FALSE;        
    }

// Done
    return TRUE;
}
