/*****************************************************************************
*                                                                            *
*  OpenNI 2.x Alpha                                                          *
*  Copyright (C) 2012 PrimeSense Ltd.                                        *
*                                                                            *
*  This file is part of OpenNI.                                              *
*                                                                            *
*  Licensed under the Apache License, Version 2.0 (the "License");           *
*  you may not use this file except in compliance with the License.          *
*  You may obtain a copy of the License at                                   *
*                                                                            *
*      http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*****************************************************************************/
#ifndef _PRIME_SENSE_H_
#define _PRIME_SENSE_H_

#include <OniCTypes.h>

#define PS_USB_VENDOR_ID        0x1D27
#define PS_NAME					"PrimeSense"

/**
* Additional properties for PrimeSense devices
*
* @remarks 
* properties structure is 0x1D27XXYY where XX is range and YY is code.
* range values:
* 00 - common stream properties
* 10 - depth stream properties
* E0 - device commands
* F0 - device properties
*/
enum
{
	// Device Properties
	PS_PROPERTY_USB_INTERFACE = 0x1d27F001, // values from XnUsbInterfaceType
};

/**
* Additional commands for PrimeSense devices
*
* @remarks 
* Commands structure is 0x1D27XXYY where XX is range and YY is code.
* range values:
* E0 - device commands
*/
enum
{
	// Device Commands
	PS_COMMAND_AHB_READ = 0x1d27E001, // XnCommandAHB
	PS_COMMAND_AHB_WRITE = 0x1d27E002, // XnCommandAHB
	PS_COMMAND_I2C_READ = 0x1d27E003, // XnCommandI2C
	PS_COMMAND_I2C_WRITE = 0x1d27E004, // XnCommandI2C
	PS_COMMAND_SOFT_RESET = 0x1d27E005, // no arguments
	PS_COMMAND_POWER_RESET = 0x1d27E006, // no arguments
};

typedef enum XnUsbInterfaceType
{
	PS_USB_INTERFACE_DONT_CARE = 0,
	PS_USB_INTERFACE_ISO_ENDPOINTS = 1,
	PS_USB_INTERFACE_BULK_ENDPOINTS = 2,
} XnUsbInterfaceType;

#pragma pack (push, 1)

typedef struct XnCommandAHB
{
	uint32_t address;		// Address of this register
	uint32_t offsetInBits;	// Offset of the field in bits within address
	uint32_t widthInBits;	// Width of the field in bits
	uint32_t value;			// For read requests, this is where the actual value will be filled. For write requests, the value to write.
} XnCommandAHB;

typedef struct XnCommandI2C
{
	uint32_t deviceID;		// Device to communicate with
	uint32_t addressSize;	// Size of the address, in bytes (1-4)
	uint32_t address;		// Address
	uint32_t valueSize;		// Size of the value, in bytes (1-4)
	uint32_t mask;			// For write request - a mask to be applied to the value. For read requests - ignored.
	uint32_t value;			// For write request - the value to be written. For read requests - the place where the actual value is written to
} XnCommandI2C;

#pragma pack (pop)

#endif //_PRIME_SENSE_H_