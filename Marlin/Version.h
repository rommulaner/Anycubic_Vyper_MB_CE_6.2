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

#include "Configuration.h"

/**
 * Marlin release version identifier
 */

#ifdef VYPER_NOZZLE_HOMING
    #ifdef VYPER_BUILD_CJ
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(CJ+N)"
    #elif defined VYPER_BUILD_CJ_IS
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(CJ+IS+N)"
    #elif defined VYPER_BUILD_LA_JD
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+N)"
    #elif defined VYPER_BUILD_LA_CJ
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+N)"
    #elif defined VYPER_BUILD_LA_JD_IS
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+IS+N)"
    #elif defined VYPER_BUILD_LA_CJ_IS
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+IS+N)"
    #elif defined VYPER_BUILD_LA_JD_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+T+N)"
    #elif defined VYPER_BUILD_LA_CJ_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+T+N)"
    #elif defined VYPER_BUILD_LA_JD_IS_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+IS+T+N)"
    #elif defined VYPER_BUILD_LA_CJ_IS_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+IS+T+N)"
    #elif defined VYPER_BUILD_LA_JD_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+TE+N)"
    #elif defined VYPER_BUILD_LA_CJ_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+TE+N)"
    #elif defined VYPER_BUILD_LA_JD_IS_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+IS+TE+N)"
    #elif defined VYPER_BUILD_LA_CJ_IS_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+IS+TE+N)"
    #else
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2"
    #endif
#else
    #ifdef VYPER_BUILD_CJ
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(CJ)"
    #elif defined VYPER_BUILD_CJ_IS
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(CJ+IS)"
    #elif defined VYPER_BUILD_LA_JD
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD)"
    #elif defined VYPER_BUILD_LA_CJ
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ)"
    #elif defined VYPER_BUILD_LA_JD_IS
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+IS)"
    #elif defined VYPER_BUILD_LA_CJ_IS
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+IS)"
    #elif defined VYPER_BUILD_LA_JD_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+T)"
    #elif defined VYPER_BUILD_LA_CJ_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+T)"
    #elif defined VYPER_BUILD_LA_JD_IS_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+IS+T)"
    #elif defined VYPER_BUILD_LA_CJ_IS_T
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+IS+T)"
    #elif defined VYPER_BUILD_LA_JD_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+TE)"
    #elif defined VYPER_BUILD_LA_CJ_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+TE)"
    #elif defined VYPER_BUILD_LA_JD_IS_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+JD+IS+TE)"
    #elif defined VYPER_BUILD_LA_CJ_IS_TE
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2(LA+CJ+IS+TE)"
    #else
        #define SHORT_BUILD_VERSION "Vyper-CE-6.2.2"
    #endif
#endif

/**
 * Verbose version identifier which should contain a reference to the location
 * from where the binary was downloaded or the source code was compiled.
 */
#define DETAILED_BUILD_VERSION "Vyper Community Firmware - Release 6.2.2 (Marlin 2.1.2.1)"

/**
 * The STRING_DISTRIBUTION_DATE represents when the binary file was built,
 * here we define this default string as the date where the latest release
 * version was tagged.
 */
#define STRING_DISTRIBUTION_DATE "2024-12-25"

/**
 * Defines a generic printer name to be output to the LCD after booting Marlin.
 */
//#define MACHINE_NAME "3D Printer"

/**
 * The SOURCE_CODE_URL is the location where users will find the Marlin Source
 * Code which is installed on the device. In most cases —unless the manufacturer
 * has a distinct Github fork— the Source Code URL should just be the main
 * Marlin repository.
 */
#define SOURCE_CODE_URL "github.com/rommulaner"

/**
 * Default generic printer UUID.
 */
//#define DEFAULT_MACHINE_UUID "cede2a2f-41a2-4748-9b12-c55c62f367ff"

/**
 * The WEBSITE_URL is the location where users can get more information such as
 * documentation about a specific Marlin release.
 */
#define WEBSITE_URL "github.com/rommulaner"

/**
 * Set the vendor info the serial USB interface, if changable
 * Currently only supported by DUE platform
 */
//#define USB_DEVICE_VENDOR_ID           0x0000
//#define USB_DEVICE_PRODUCT_ID          0x0000
//#define USB_DEVICE_MANUFACTURE_NAME    WEBSITE_URL
