/*******************************************************************************
Copyright (C) 2015 OLogN Technologies AG

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*******************************************************************************/


#if !defined __SAOUDP_PROTOCOL_H__
#define __SAOUDP_PROTOCOL_H__

#include "sa_common.h"
#include "zepto_mem_mngmt.h"


// ret codes
#define SAOUDP_RET_FAILED 0
#define SAOUDP_RET_OK 1

uint8_t handler_saoudp_send( MEMORY_HANDLE mem_h, MEMORY_HANDLE mem_h_tag );
uint8_t handler_saoudp_receive( MEMORY_HANDLE mem_h, MEMORY_HANDLE mem_h_tag );


#endif // __SAOUDP_PROTOCOL_H__