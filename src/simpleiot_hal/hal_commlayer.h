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

#if !defined __SA_COMMLAYER_H__
#define __SA_COMMLAYER_H__

#include <simpleiot/siot_common.h>
//#include "zepto_mem_mngmt_hal_spec.h"
#include "siot_mem_mngmt.h"

// RET codes
#define COMMLAYER_RET_FAILED 0
#define COMMLAYER_RET_OK 1
#define COMMLAYER_RET_PENDING 2

#define HAL_GET_PACKET_BYTES_FAILED 1
#define HAL_GET_PACKET_BYTES_DONE 2

#define COMMLAYER_RET_FROM_DEV 11
#define COMMLAYER_RET_TIMEOUT 12

#ifdef __cplusplus
extern "C" {
#endif

bool communication_initialize();
void communication_terminate();
#ifdef MESH_TEST
uint8_t hal_send_packet( MEMORY_HANDLE mem_h, uint8_t bus_id, uint8_t intrabus_id );
uint8_t hal_get_busid_of_last_packet(); // TODO: this approach seems not to be too good interface solution
#else
uint8_t send_message( MEMORY_HANDLE mem_h, uint16_t bus_id );
#endif
uint8_t hal_get_packet_bytes( MEMORY_HANDLE mem_h, uint16_t bus_id );
void keep_transmitter_on( bool keep_on );

#ifdef __cplusplus
}
#endif


#endif // __SA_COMMLAYER_H__