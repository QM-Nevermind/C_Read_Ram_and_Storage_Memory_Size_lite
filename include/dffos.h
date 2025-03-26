/*
 * Copyright (C) 2024 QM-Nevermind
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (LGPL) Version 3
 * or later versions. See the LICENSE file distributed with this program, or
 * visit <https://www.gnu.org/licenses/> for more information.
 *
 * This program is provided "as is" without any warranty.
 */

#pragma once
#include <stdio.h>

 
typedef unsigned long size_tl;
typedef unsigned long long size_tll;

typedef enum{
    BYTE,
    KILOBYTE,
    MEGABYTE,
    GIGABYTE,
} RRS_UNIT;

size_tl get_total_ram(RRS_UNIT unit);
size_tl get_free_ram(RRS_UNIT unit);
size_tll get_total_storage_memory(RRS_UNIT unit);
size_tll get_free_storage_memory(RRS_UNIT unit);

//function to print the warnings.
void invalid_unit();
void ull_overflow_ul();





