// ahci.h
// Created by Fred Nora.

// See:
// https://en.wikipedia.org/wiki/Advanced_Host_Controller_Interface

#ifndef __DD_AHCI_H
#define __DD_AHCI_H    1

#define NR_PORTS  32  // maximum number of ports
//#define NR_CMDS   32  // maximum number of queued commands

int ahci_initialize(void);

#endif  

