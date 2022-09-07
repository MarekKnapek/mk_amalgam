#ifndef mk_include_guard_std_uintp
#define mk_include_guard_std_uintp


#include "mk_std_platform.h"


#if mk_std_platform_os == mk_std_platform_os_16 && (mk_std_platform_mm == mk_std_platform_mm_tiny || mk_std_platform_mm == mk_std_platform_mm_small || mk_std_platform_mm == mk_std_platform_mm_compact)
#include "../../mk_int/src/exact/mk_uint_16.h"
#define mk_uintp_bits 16
#define mk_uintp_t mk_uint16_t
#define mk_uintp_zero mk_uint16_zero
#define mk_uintp_one mk_uint16_one
#define mk_uintp_from_int mk_uint16_from_int
#define mk_uintp_to_int mk_uint16_to_int
#define mk_uintp_from_long mk_uint16_from_long
#define mk_uintp_to_long mk_uint16_to_long
#define mk_uintp_from_sizet mk_uint16_from_sizet
#define mk_uintp_to_sizet mk_uint16_to_sizet
#define mk_uintp_from_buff_le mk_uint16_from_buff_le
#define mk_uintp_to_buff_le mk_uint16_to_buff_le
#define mk_uintp_from_buff_be mk_uint16_from_buff_be
#define mk_uintp_to_buff_be mk_uint16_to_buff_be
#define mk_uintp_is_zero mk_uint16_is_zero
#define mk_uintp_is_max mk_uint16_is_max
#define mk_uintp_cmplmnt mk_uint16_cmplmnt
#define mk_uintp_or mk_uint16_or
#define mk_uintp_and mk_uint16_and
#define mk_uintp_xor mk_uint16_xor
#define mk_uintp_shl mk_uint16_shl
#define mk_uintp_shr mk_uint16_shr
#define mk_uintp_rotl mk_uint16_rotl
#define mk_uintp_rotr mk_uint16_rotr
#define mk_uintp_eq mk_uint16_eq
#define mk_uintp_neq mk_uint16_neq
#define mk_uintp_lt mk_uint16_lt
#define mk_uintp_le mk_uint16_le
#define mk_uintp_gt mk_uint16_gt
#define mk_uintp_ge mk_uint16_ge
#define mk_uintp_inc mk_uint16_inc
#define mk_uintp_dec mk_uint16_dec
#define mk_uintp_add mk_uint16_add
#define mk_uintp_sub mk_uint16_sub
#define mk_uintp_mul mk_uint16_mul
#define mk_uintp_divmod mk_uint16_divmod
#define mk_uintp_divmodsm mk_uint16_divmodsm
#define mk_uintp_div mk_uint16_div
#define mk_uintp_mod mk_uint16_mod
#define mk_uintp_log2 mk_uint16_log2
#define mk_uintp_to_string_dec_n mk_uint16_to_string_dec_n
#define mk_uintp_to_string_dec_w mk_uint16_to_string_dec_w
#define mk_uintp_to_string_hex_n mk_uint16_to_string_hex_n
#define mk_uintp_to_string_hex_w mk_uint16_to_string_hex_w
#define mk_uintp_to_string_hex_full_n mk_uint16_to_string_hex_full_n
#define mk_uintp_to_string_hex_full_w mk_uint16_to_string_hex_full_w
#elif mk_std_platform_os == mk_std_platform_os_32 || (mk_std_platform_os == mk_std_platform_os_16 && (mk_std_platform_mm == mk_std_platform_mm_medium || mk_std_platform_mm == mk_std_platform_mm_large || mk_std_platform_mm == mk_std_platform_mm_huge))
#include "../../mk_int/src/exact/mk_uint_32.h"
#define mk_uintp_bits 32
#define mk_uintp_t mk_uint32_t
#define mk_uintp_zero mk_uint32_zero
#define mk_uintp_one mk_uint32_one
#define mk_uintp_from_int mk_uint32_from_int
#define mk_uintp_to_int mk_uint32_to_int
#define mk_uintp_from_long mk_uint32_from_long
#define mk_uintp_to_long mk_uint32_to_long
#define mk_uintp_from_sizet mk_uint32_from_sizet
#define mk_uintp_to_sizet mk_uint32_to_sizet
#define mk_uintp_from_buff_le mk_uint32_from_buff_le
#define mk_uintp_to_buff_le mk_uint32_to_buff_le
#define mk_uintp_from_buff_be mk_uint32_from_buff_be
#define mk_uintp_to_buff_be mk_uint32_to_buff_be
#define mk_uintp_is_zero mk_uint32_is_zero
#define mk_uintp_is_max mk_uint32_is_max
#define mk_uintp_cmplmnt mk_uint32_cmplmnt
#define mk_uintp_or mk_uint32_or
#define mk_uintp_and mk_uint32_and
#define mk_uintp_xor mk_uint32_xor
#define mk_uintp_shl mk_uint32_shl
#define mk_uintp_shr mk_uint32_shr
#define mk_uintp_rotl mk_uint32_rotl
#define mk_uintp_rotr mk_uint32_rotr
#define mk_uintp_eq mk_uint32_eq
#define mk_uintp_neq mk_uint32_neq
#define mk_uintp_lt mk_uint32_lt
#define mk_uintp_le mk_uint32_le
#define mk_uintp_gt mk_uint32_gt
#define mk_uintp_ge mk_uint32_ge
#define mk_uintp_inc mk_uint32_inc
#define mk_uintp_dec mk_uint32_dec
#define mk_uintp_add mk_uint32_add
#define mk_uintp_sub mk_uint32_sub
#define mk_uintp_mul mk_uint32_mul
#define mk_uintp_divmod mk_uint32_divmod
#define mk_uintp_divmodsm mk_uint32_divmodsm
#define mk_uintp_div mk_uint32_div
#define mk_uintp_mod mk_uint32_mod
#define mk_uintp_log2 mk_uint32_log2
#define mk_uintp_to_string_dec_n mk_uint32_to_string_dec_n
#define mk_uintp_to_string_dec_w mk_uint32_to_string_dec_w
#define mk_uintp_to_string_hex_n mk_uint32_to_string_hex_n
#define mk_uintp_to_string_hex_w mk_uint32_to_string_hex_w
#define mk_uintp_to_string_hex_full_n mk_uint32_to_string_hex_full_n
#define mk_uintp_to_string_hex_full_w mk_uint32_to_string_hex_full_w
#elif mk_std_platform_os == mk_std_platform_os_64
#include "../../mk_int/src/exact/mk_uint_64.h"
#define mk_uintp_bits 64
#define mk_uintp_t mk_uint64_t
#define mk_uintp_zero mk_uint64_zero
#define mk_uintp_one mk_uint64_one
#define mk_uintp_from_int mk_uint64_from_int
#define mk_uintp_to_int mk_uint64_to_int
#define mk_uintp_from_long mk_uint64_from_long
#define mk_uintp_to_long mk_uint64_to_long
#define mk_uintp_from_sizet mk_uint64_from_sizet
#define mk_uintp_to_sizet mk_uint64_to_sizet
#define mk_uintp_from_buff_le mk_uint64_from_buff_le
#define mk_uintp_to_buff_le mk_uint64_to_buff_le
#define mk_uintp_from_buff_be mk_uint64_from_buff_be
#define mk_uintp_to_buff_be mk_uint64_to_buff_be
#define mk_uintp_is_zero mk_uint64_is_zero
#define mk_uintp_is_max mk_uint64_is_max
#define mk_uintp_cmplmnt mk_uint64_cmplmnt
#define mk_uintp_or mk_uint64_or
#define mk_uintp_and mk_uint64_and
#define mk_uintp_xor mk_uint64_xor
#define mk_uintp_shl mk_uint64_shl
#define mk_uintp_shr mk_uint64_shr
#define mk_uintp_rotl mk_uint64_rotl
#define mk_uintp_rotr mk_uint64_rotr
#define mk_uintp_eq mk_uint64_eq
#define mk_uintp_neq mk_uint64_neq
#define mk_uintp_lt mk_uint64_lt
#define mk_uintp_le mk_uint64_le
#define mk_uintp_gt mk_uint64_gt
#define mk_uintp_ge mk_uint64_ge
#define mk_uintp_inc mk_uint64_inc
#define mk_uintp_dec mk_uint64_dec
#define mk_uintp_add mk_uint64_add
#define mk_uintp_sub mk_uint64_sub
#define mk_uintp_mul mk_uint64_mul
#define mk_uintp_divmod mk_uint64_divmod
#define mk_uintp_divmodsm mk_uint64_divmodsm
#define mk_uintp_div mk_uint64_div
#define mk_uintp_mod mk_uint64_mod
#define mk_uintp_log2 mk_uint64_log2
#define mk_uintp_to_string_dec_n mk_uint64_to_string_dec_n
#define mk_uintp_to_string_dec_w mk_uint64_to_string_dec_w
#define mk_uintp_to_string_hex_n mk_uint64_to_string_hex_n
#define mk_uintp_to_string_hex_w mk_uint64_to_string_hex_w
#define mk_uintp_to_string_hex_full_n mk_uint64_to_string_hex_full_n
#define mk_uintp_to_string_hex_full_w mk_uint64_to_string_hex_full_w
#endif


#endif
