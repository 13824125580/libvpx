/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef VP9_COMMON_VP9_COMMON_H_
#define VP9_COMMON_VP9_COMMON_H_

/* Interface header for common constant data structures and lookup tables */

#include <assert.h>

#include "./vpx_config.h"
#include "vpx_mem/vpx_mem.h"
#include "vpx/vpx_integer.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#define ROUND_POWER_OF_TWO(value, n) (((value) + (1 << ((n) - 1))) >> (n))

/* If we don't want to use ROUND_POWER_OF_TWO macro
static INLINE int16_t round_power_of_two(int16_t value, int n) {
  return (value + (1 << (n - 1))) >> n;
}*/

// Only need this for fixed-size arrays, for structs just assign.
#define vp9_copy(dest, src) {            \
    assert(sizeof(dest) == sizeof(src)); \
    vpx_memcpy(dest, src, sizeof(src));  \
  }

// Use this for variably-sized arrays.
#define vp9_copy_array(dest, src, n) {       \
    assert(sizeof(*dest) == sizeof(*src));   \
    vpx_memcpy(dest, src, n * sizeof(*src)); \
  }

#define vp9_zero(dest) vpx_memset(&dest, 0, sizeof(dest));
#define vp9_zero_array(dest, n) vpx_memset(dest, 0, n * sizeof(*dest));

static INLINE uint8_t clip_pixel(int val) {
  return (val > 255) ? 255u : (val < 0) ? 0u : val;
}

static INLINE int clamp(int value, int low, int high) {
  return value < low ? low : (value > high ? high : value);
}

static INLINE double fclamp(double value, double low, double high) {
  return value < low ? low : (value > high ? high : value);
}

static INLINE int multiple8(int value) {
  return (value + 7) & ~7;
}

static int get_unsigned_bits(unsigned int num_values) {
  int cat = 0;
  if (num_values <= 1)
    return 0;
  num_values--;
  while (num_values > 0) {
    cat++;
    num_values >>= 1;
  }
  return cat;
}

#define SYNC_CODE_0 0x49
#define SYNC_CODE_1 0x83
#define SYNC_CODE_2 0x42


#endif  // VP9_COMMON_VP9_COMMON_H_
