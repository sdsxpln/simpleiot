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

#if !defined __SA_DATA_TYPES_H__
#define __SA_DATA_TYPES_H__

#include "sa_uint48.h"
#include "../hal/hal_time_provider.h"


typedef sa_uint48_t sasp_nonce_type;
#define SASP_NONCE_TYPE_SIZE 6 // sizeof(sa_uint48_t)

typedef struct _timeout_action // NOTE: might be a temporary solution
{
	sa_time_val tv;
	uint8_t action;
} timeout_action;


#endif // __SA_DATA_TYPES_H__