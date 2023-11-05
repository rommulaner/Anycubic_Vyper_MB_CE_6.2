/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */
#pragma once

////////////////////////////
// VENDOR VERSION EXAMPLE //
////////////////////////////

/**
 * Marlin release version identifier
 */
#ifdef VYPER_NOZZLE_HOMING
    #ifdef VYPER_BUILD
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d(CJ+N)"
    #elif defined VYPER_BUILD_LA
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d(LA+N)"
    #elif defined VYPER_BUILD_LA_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d(LA+T+N)"
    #elif defined VYPER_BUILD_LA_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d(LA+TE+N)"
    #else
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d"
    #endif
#else
    #ifdef VYPER_BUILD
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d(CJ)"
    #elif defined VYPER_BUILD_LA
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d(LA)"
    #elif defined VYPER_BUILD_LA_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d(LA+T)"
    #elif defined VYPER_BUILD_LA_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d(LA+TE)"
    #else
        #define SHORT_BUILD_VERSION "Vyper-CE-6.1d"
    #endif
#endif

/**
 * Verbose version identifier which should contain a reference to the location
 * from where the binary was downloaded or the source code was compiled.
 */
#define DETAILED_BUILD_VERSION "Vyper Community Firmware - Release 6.1d (based on Marlin 2.0.9.1)"

/**
 * The STRING_DISTRIBUTION_DATE represents when the binary file was built,
 * here we define this default string as the date where the latest release
 * version was tagged.
 */
#define STRING_DISTRIBUTION_DATE "2023-11-05"


/**
 * Defines a generic printer name to be output to the LCD after booting Marlin.
 */
#ifndef CUSTOM_MACHINE_NAME
    #define CUSTOM_MACHINE_NAME SHORT_BUILD_VERSION
#endif
#define MACHINE_NAME CUSTOM_MACHINE_NAME

/**
 * The SOURCE_CODE_URL is the location where users will find the Marlin Source
 * Code which is installed on the device. In most cases —unless the manufacturer
 * has a distinct Github fork— the Source Code URL should just be the main
 * Marlin repository.
 */
#define SOURCE_CODE_URL "https://github.com/rommulaner"

/**
 * Default generic printer UUID.
 */
//#define DEFAULT_MACHINE_UUID "cede2a2f-41a2-4748-9b12-c55c62f367ff"

/**
 * The WEBSITE_URL is the location where users can get more information such as
 * documentation about a specific Marlin release.
 */
#define WEBSITE_URL "https://github.com/rommulaner"

/**
 * Set the vendor info the serial USB interface, if changable
 * Currently only supported by DUE platform
 */
//#define USB_DEVICE_VENDOR_ID           0x0000
//#define USB_DEVICE_PRODUCT_ID          0x0000
//#define USB_DEVICE_MANUFACTURE_NAME    WEBSITE_URL
