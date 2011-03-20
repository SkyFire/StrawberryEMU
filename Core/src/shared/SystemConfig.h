/*
 * Copyright (C) 2010-2011 Strawberry-Pr0jcts <http://www.strawberry-pr0jcts.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STRAWBERRY_SYSTEMCONFIG_H
#define STRAWBERRY_SYSTEMCONFIG_H

#include "Define.h"
#include "revision_nr.h"

#if STRAWBERRY_ENDIAN == STRAWBERRY_BIGENDIAN
# define _ENDIAN_STRING "big-endian"
#else
# define _ENDIAN_STRING "little-endian"
#endif

// Name of the Core
#define _PACKAGENAME "StrawberryCore "

// For revision output in console
#define _FULLVERSION _PACKAGENAME "\n" "Revision: " REVISION_NR

/*-----------------------CONFIGS-----------------------*/

// Set Config directory
// Default: "Configs/" - Configs are in subfolder "Configs", based on World- and RealmServer directory
# define SYSCONFDIR "Configs/"

/* Set name of config files */
// Config for WorldServer
#define WORLD_CONFIG_FILE SYSCONFDIR "WorldServer.conf"

// Config for RealmServer
#define REALM_CONFIG_FILE SYSCONFDIR "RealmServer.conf"

#endif

