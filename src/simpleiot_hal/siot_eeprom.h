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

#if !defined __SA_EEPROM_H__
#define __SA_EEPROM_H__

#include <simpleiot/siot_common.h>

#define EEPROM_CHECKSUM_SIZE 4


// data IDs (for communication with eeprom
#define EEPROM_SLOT_DATA_SASP_NONCE_LW_ID 0 // Nonce Lower Watermark
#define EEPROM_SLOT_DATA_SASP_NONCE_LS_ID 1 // Nonce to use For Sending

// data sizes
#define DATA_REINCARNATION_ID_SIZE 16 // reincarnation id is treated as a not listed slot with special processing of DATA_REINCARNATION_ID_SIZE * 2 size
#define DATA_SASP_NONCE_LW_SIZE 6 // Nonce Lower Watermark
#define DATA_SASP_NONCE_LS_SIZE 6 // Nonce to use For Sending

#define EEPROM_SLOT_MAX 2
// ...to be continued

#ifdef USED_AS_MASTER

#define PERM_STORAGE_MIN_SIZE (DATA_SASP_NONCE_LW_SIZE + DATA_SASP_NONCE_LS_SIZE + 2 * EEPROM_CHECKSUM_SIZE)

// ret codes
#define PERM_STORAGE_RET_OK 0
#define PERM_STORAGE_RET_ALREADY_EXISTS 1
#define PERM_STORAGE_RET_DOES_NOT_EXIST 2
#define PERM_STORAGE_RET_OUT_OF_MEM 10

// calls
uint8_t perm_storage_add_device( uint16_t device_id );
uint8_t perm_storage_remove_device( uint16_t device_id );
void eeprom_write( uint16_t device_id, uint8_t item, uint16_t sz, uint8_t* data );
void eeprom_read( uint16_t device_id, uint8_t item, uint16_t sz, uint8_t* data );

#else // USED_AS_MASTER

#define EEPROM_SERIALIZED_SIZE ( 2 + DATA_REINCARNATION_ID_SIZE + 2 * EEPROM_SLOT_MAX + DATA_SASP_NONCE_LW_SIZE + DATA_SASP_NONCE_LS_SIZE )

// ret codes
#define EEPROM_RET_REINCARNATION_ID_OLD 0
#define EEPROM_RET_REINCARNATION_ID_OK_ONE_OK 1
#define EEPROM_RET_REINCARNATION_ID_OK_BOTH_OK 2

bool init_eeprom_access();
uint8_t eeprom_check_reincarnation( uint8_t* rid ); // returns one of EEPROM_RET_REINCARNATION_ID_XXX
bool eeprom_check_at_start(); // returns true, if all slots are OK; TODO: it should be upper level logic to determine what to do with each corrupted slot separately
void eeprom_update_reincarnation_if_necessary( uint8_t* rid );
void eeprom_write( uint8_t id, uint8_t* data);
void eeprom_read( uint8_t id, uint8_t* data);
uint16_t eeprom_serialize( uint8_t* buff );
void eeprom_deserialize( uint8_t* buff );

#endif // USED_AS_MASTER

#endif // __SA_EEPROM_H__