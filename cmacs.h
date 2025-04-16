/*
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

  1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define _GNU_SOURCE

/* C89 */
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* C99 */
#include <complex.h>
#include <fenv.h>
#include <inttypes.h>
/* #include <iso646.h> */
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
#include <wchar.h>
#include <wctype.h>

/* C11 */
#include <stdalign.h>
/* #include <stdatomic.h> */
#include <stdnoreturn.h>
/* #include <threads.h> */
/* #include <uchar.h> */

/* POSIX */
/* #include <regex.h> */
/* #include <unistd.h> */

#ifdef __cplusplus
#define null nullptr
#else
#define null NULL
#endif
#define generic _Generic
#define bitint _BitInt
#ifndef __cplusplus
#define auto __auto_type
#endif
#define asm __asm__

typedef uint8_t byte;
typedef uintptr_t word;

typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
#if (__SIZEOF_INT128__ + 0) == 16
#define __P_INT128_ 16
typedef __int128_t i128;
typedef __uint128_t u128;
#else
typedef intmax_t i128;
typedef uintmax_t u128;
#endif
typedef intmax_t imx;
typedef uintmax_t umx;
typedef intptr_t iptr;
typedef uintptr_t uptr;
typedef ssize_t isz;
typedef size_t usz;

typedef uint_least8_t c8;
typedef uint_least16_t c16;
typedef uint_least32_t c32;

typedef double real;
#ifdef __FLT16_MAX__
#define __P_FLOAT16_ 2
typedef _Float16 f16;
#else
typedef float f16;
#endif
typedef float f32;
typedef double f64;
#if (__SIZEOF_FLOAT128__ + 0) == 16
#define __P_FLOAT128_ 16
typedef __float128 f128;
#else
typedef long double f128;
#endif

#define todo$(...) static_assert (0 __VA_OPT__ (, ) __VA_ARGS__)

#define macro$(name) __P_##name##_
#define static$(name) __S_##name##_
#define const$(name) __C_##name##_

#define __C_p2_ UINT64_C (3)
#define __C_p3_ UINT64_C (7)
#define __C_p4_ UINT64_C (13)
#define __C_p5_ UINT64_C (31)
#define __C_p6_ UINT64_C (61)
#define __C_p7_ UINT64_C (127)
#define __C_p8_ UINT64_C (251)
#define __C_p9_ UINT64_C (509)
#define __C_p10_ UINT64_C (1021)
#define __C_p11_ UINT64_C (2039)
#define __C_p12_ UINT64_C (4093)
#define __C_p13_ UINT64_C (8191)
#define __C_p14_ UINT64_C (16381)
#define __C_p15_ UINT64_C (32749)
#define __C_p16_ UINT64_C (65521)
#define __C_p17_ UINT64_C (131071)
#define __C_p18_ UINT64_C (262139)
#define __C_p19_ UINT64_C (524287)
#define __C_p20_ UINT64_C (1048573)
#define __C_p21_ UINT64_C (2097143)
#define __C_p22_ UINT64_C (4194301)
#define __C_p23_ UINT64_C (8388593)
#define __C_p24_ UINT64_C (16777213)
#define __C_p25_ UINT64_C (33554393)
#define __C_p26_ UINT64_C (67108859)
#define __C_p27_ UINT64_C (134217689)
#define __C_p28_ UINT64_C (268435399)
#define __C_p29_ UINT64_C (536870909)
#define __C_p30_ UINT64_C (1073741789)
#define __C_p31_ UINT64_C (2147483647)
#define __C_p32_ UINT64_C (4294967291)
#define __C_p33_ UINT64_C (8589934583)
#define __C_p34_ UINT64_C (17179869143)
#define __C_p35_ UINT64_C (34359738337)
#define __C_p36_ UINT64_C (68719476731)
#define __C_p37_ UINT64_C (137438953447)
#define __C_p38_ UINT64_C (274877906899)
#define __C_p39_ UINT64_C (549755813881)
#define __C_p40_ UINT64_C (1099511627689)
#define __C_p41_ UINT64_C (2199023255531)
#define __C_p42_ UINT64_C (4398046511093)
#define __C_p43_ UINT64_C (8796093022151)
#define __C_p44_ UINT64_C (17592186044399)
#define __C_p45_ UINT64_C (35184372088777)
#define __C_p46_ UINT64_C (70368744177643)
#define __C_p47_ UINT64_C (140737488355213)
#define __C_p48_ UINT64_C (281474976710597)
#define __C_p49_ UINT64_C (562949953421231)
#define __C_p50_ UINT64_C (1125899906842597)
#define __C_p51_ UINT64_C (2251799813685119)
#define __C_p52_ UINT64_C (4503599627370449)
#define __C_p53_ UINT64_C (9007199254740881)
#define __C_p54_ UINT64_C (18014398509481951)
#define __C_p55_ UINT64_C (36028797018963913)
#define __C_p56_ UINT64_C (72057594037927931)
#define __C_p57_ UINT64_C (144115188075855859)
#define __C_p58_ UINT64_C (288230376151711717)
#define __C_p59_ UINT64_C (576460752303423433)
#define __C_p60_ UINT64_C (1152921504606846883)
#define __C_p61_ UINT64_C (2305843009213693951)
#define __C_p62_ UINT64_C (4611686018427387847)
#define __C_p63_ UINT64_C (9223372036854775783)
#define __C_p64_ UINT64_C (18446744073709551557)

#define __C_tp3_ UINT64_C (5)
#define __C_tp4_ UINT64_C (11)
#define __C_tp5_ UINT64_C (29)
#define __C_tp6_ UINT64_C (59)
#define __C_tp7_ UINT64_C (107)
#define __C_tp8_ UINT64_C (239)
#define __C_tp9_ UINT64_C (461)
#define __C_tp10_ UINT64_C (1019)
#define __C_tp11_ UINT64_C (2027)
#define __C_tp12_ UINT64_C (4091)
#define __C_tp13_ UINT64_C (8087)
#define __C_tp14_ UINT64_C (16361)
#define __C_tp15_ UINT64_C (32717)
#define __C_tp16_ UINT64_C (65519)
#define __C_tp17_ UINT64_C (131009)
#define __C_tp18_ UINT64_C (262109)
#define __C_tp19_ UINT64_C (524219)
#define __C_tp20_ UINT64_C (1048571)
#define __C_tp21_ UINT64_C (2097131)
#define __C_tp22_ UINT64_C (4193801)
#define __C_tp23_ UINT64_C (8388449)
#define __C_tp24_ UINT64_C (16777139)
#define __C_tp25_ UINT64_C (33554009)
#define __C_tp26_ UINT64_C (67108667)
#define __C_tp27_ UINT64_C (134217437)
#define __C_tp28_ UINT64_C (268435007)
#define __C_tp29_ UINT64_C (536870837)
#define __C_tp30_ UINT64_C (1073741717)
#define __C_tp31_ UINT64_C (2147482949)
#define __C_tp32_ UINT64_C (4294965839)
#define __C_tp33_ UINT64_C (8589934289)
#define __C_tp34_ UINT64_C (17179868807)
#define __C_tp35_ UINT64_C (34359737297)
#define __C_tp36_ UINT64_C (68719476389)
#define __C_tp37_ UINT64_C (137438953271)
#define __C_tp38_ UINT64_C (274877906627)
#define __C_tp39_ UINT64_C (549755813357)
#define __C_tp40_ UINT64_C (1099511626397)
#define __C_tp41_ UINT64_C (2199023255477)
#define __C_tp42_ UINT64_C (4398046509737)
#define __C_tp43_ UINT64_C (8796093021407)
#define __C_tp44_ UINT64_C (17592186044297)
#define __C_tp45_ UINT64_C (35184372088319)
#define __C_tp46_ UINT64_C (70368744176777)
#define __C_tp47_ UINT64_C (140737488353699)
#define __C_tp48_ UINT64_C (281474976710129)
#define __C_tp49_ UINT64_C (562949953419317)
#define __C_tp50_ UINT64_C (1125899906841971)
#define __C_tp51_ UINT64_C (2251799813684459)
#define __C_tp52_ UINT64_C (4503599627369861)
#define __C_tp53_ UINT64_C (9007199254738541)
#define __C_tp54_ UINT64_C (18014398509481727)
#define __C_tp55_ UINT64_C (36028797018963797)
#define __C_tp56_ UINT64_C (72057594037925807)
#define __C_tp57_ UINT64_C (144115188075854267)
#define __C_tp58_ UINT64_C (288230376151709777)
#define __C_tp59_ UINT64_C (576460752303422429)
#define __C_tp60_ UINT64_C (1152921504606845471)
#define __C_tp61_ UINT64_C (2305843009213692029)
#define __C_tp62_ UINT64_C (4611686018427386201)
#define __C_tp63_ UINT64_C (9223372036854774509)
#define __C_tp64_ UINT64_C (18446744073709550771)

#define __P_quote_(...) #__VA_ARGS__
#define quote$(...) __P_quote_ (__VA_ARGS__)

#define __P_cat_(c, d) c##d
#define cat$(c, d) __P_cat_ (c, d)

#define uniq$(c) cat$ (cat$ (__U_, __COUNTER__), _##c##_)

#define lp$ (
#define rp$ )

#define paren$(...) (__VA_ARGS__)

#define __NO___P_recur_
#define __P_recur_(...) __P_recur_ __VA_ARGS__
#define __P_unparen_helper_(...) __NO_##__VA_ARGS__
#define __P_unparen_(...) __P_unparen_helper_ (__VA_ARGS__)
#define unparen$(c) __P_unparen_ (__P_recur_ c)

/* scan 1024 times */
#define scan$(...)                                                            \
  __P_scan_r_1_ (__P_scan_r_1_ (__P_scan_r_1_ (__P_scan_r_1_ (__VA_ARGS__))))
#define __P_scan_r_1_(...)                                                    \
  __P_scan_r_2_ (__P_scan_r_2_ (__P_scan_r_2_ (__P_scan_r_2_ (__VA_ARGS__))))
#define __P_scan_r_2_(...)                                                    \
  __P_scan_r_3_ (__P_scan_r_3_ (__P_scan_r_3_ (__P_scan_r_3_ (__VA_ARGS__))))
#define __P_scan_r_3_(...)                                                    \
  __P_scan_r_4_ (__P_scan_r_4_ (__P_scan_r_4_ (__P_scan_r_4_ (__VA_ARGS__))))
#define __P_scan_r_4_(...)                                                    \
  __P_scan_r_5_ (__P_scan_r_5_ (__P_scan_r_5_ (__P_scan_r_5_ (__VA_ARGS__))))
#define __P_scan_r_5_(...) __VA_ARGS__

#if (RECURSIVE_REDUCE_MACRO + 0) == 0
#define __R1_(f, i, j, ...)                                                   \
  __VA_OPT__ (__R2_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R2_(f, i, j, ...)                                                   \
  __VA_OPT__ (__R3_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R3_(f, i, j, ...)                                                   \
  __VA_OPT__ (__R4_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R4_(f, i, j, ...)                                                   \
  __VA_OPT__ (__R5_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R5_(f, i, j, ...)                                                   \
  __VA_OPT__ (__R6_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R6_(f, i, j, ...)                                                   \
  __VA_OPT__ (__R7_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R7_(f, i, j, ...)                                                   \
  __VA_OPT__ (__R8_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R8_(f, i, j, ...)                                                   \
  __VA_OPT__ (__R9_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R9_(f, i, j, ...)                                                   \
  __VA_OPT__ (__R10_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R10_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R11_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R11_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R12_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R12_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R13_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R13_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R14_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R14_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R15_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R15_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R16_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R16_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R17_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R17_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R18_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R18_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R19_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R19_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R20_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R20_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R21_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R21_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R22_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R22_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R23_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R23_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R24_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R24_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R25_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R25_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R26_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R26_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R27_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R27_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R28_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R28_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R29_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R29_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R30_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R30_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R31_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R31_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R32_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R32_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R33_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R33_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R34_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R34_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R35_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R35_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R36_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R36_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R37_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R37_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R38_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R38_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R39_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R39_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R40_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R40_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R41_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R41_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R42_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R42_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R43_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R43_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R44_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R44_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R45_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R45_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R46_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R46_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R47_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R47_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R48_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R48_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R49_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R49_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R50_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R50_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R51_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R51_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R52_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R52_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R53_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R53_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R54_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R54_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R55_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R55_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R56_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R56_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R57_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R57_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R58_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R58_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R59_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R59_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R60_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R60_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R61_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R61_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R62_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R62_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R63_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R63_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R64_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R64_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R65_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R65_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R66_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R66_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R67_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R67_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R68_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R68_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R69_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R69_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R70_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R70_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R71_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R71_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R72_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R72_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R73_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R73_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R74_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R74_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R75_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R75_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R76_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R76_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R77_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R77_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R78_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R78_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R79_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R79_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R80_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R80_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R81_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R81_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R82_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R82_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R83_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R83_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R84_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R84_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R85_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R85_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R86_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R86_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R87_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R87_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R88_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R88_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R89_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R89_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R90_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R90_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R91_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R91_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R92_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R92_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R93_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R93_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R94_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R94_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R95_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R95_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R96_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R96_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R97_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R97_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R98_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R98_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R99_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R99_(f, i, j, ...)                                                  \
  __VA_OPT__ (__R100_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R100_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R101_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R101_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R102_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R102_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R103_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R103_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R104_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R104_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R105_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R105_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R106_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R106_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R107_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R107_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R108_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R108_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R109_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R109_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R110_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R110_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R111_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R111_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R112_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R112_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R113_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R113_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R114_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R114_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R115_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R115_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R116_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R116_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R117_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R117_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R118_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R118_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R119_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R119_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R120_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R120_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R121_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R121_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R122_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R122_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R123_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R123_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R124_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R124_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R125_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R125_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R126_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R126_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R127_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R127_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R128_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R128_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R129_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R129_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R130_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R130_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R131_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R131_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R132_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R132_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R133_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R133_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R134_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R134_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R135_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R135_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R136_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R136_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R137_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R137_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R138_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R138_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R139_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R139_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R140_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R140_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R141_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R141_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R142_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R142_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R143_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R143_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R144_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R144_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R145_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R145_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R146_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R146_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R147_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R147_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R148_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R148_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R149_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R149_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R150_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R150_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R151_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R151_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R152_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R152_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R153_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R153_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R154_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R154_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R155_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R155_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R156_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R156_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R157_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R157_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R158_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R158_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R159_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R159_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R160_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R160_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R161_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R161_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R162_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R162_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R163_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R163_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R164_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R164_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R165_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R165_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R166_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R166_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R167_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R167_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R168_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R168_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R169_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R169_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R170_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R170_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R171_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R171_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R172_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R172_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R173_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R173_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R174_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R174_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R175_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R175_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R176_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R176_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R177_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R177_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R178_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R178_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R179_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R179_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R180_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R180_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R181_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R181_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R182_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R182_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R183_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R183_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R184_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R184_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R185_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R185_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R186_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R186_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R187_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R187_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R188_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R188_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R189_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R189_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R190_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R190_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R191_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R191_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R192_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R192_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R193_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R193_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R194_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R194_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R195_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R195_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R196_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R196_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R197_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R197_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R198_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R198_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R199_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R199_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R200_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R200_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R201_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R201_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R202_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R202_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R203_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R203_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R204_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R204_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R205_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R205_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R206_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R206_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R207_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R207_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R208_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R208_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R209_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R209_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R210_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R210_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R211_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R211_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R212_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R212_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R213_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R213_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R214_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R214_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R215_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R215_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R216_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R216_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R217_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R217_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R218_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R218_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R219_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R219_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R220_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R220_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R221_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R221_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R222_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R222_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R223_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R223_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R224_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R224_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R225_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R225_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R226_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R226_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R227_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R227_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R228_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R228_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R229_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R229_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R230_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R230_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R231_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R231_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R232_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R232_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R233_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R233_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R234_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R234_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R235_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R235_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R236_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R236_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R237_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R237_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R238_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R238_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R239_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R239_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R240_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R240_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R241_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R241_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R242_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R242_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R243_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R243_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R244_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R244_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R245_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R245_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R246_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R246_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R247_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R247_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R248_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R248_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R249_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R249_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R250_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R250_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R251_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R251_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R252_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R252_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R253_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R253_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R254_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R254_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R255_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R255_(f, i, j, ...)                                                 \
  __VA_OPT__ (__R256_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __R256_(f, i, j, ...)                                                 \
  __VA_OPT__ (f) (f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#undef $reduce
#define $reduce(f, i, j, ...)                                                 \
  unparen$ (__VA_OPT__ (__R1_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, )     \
                                    __VA_ARGS__))
#else
#define __P_reduce_(f, i, j, ...)                                             \
  __VA_OPT__ (__Q_reduce_ lp$ f, ) f (i, j) __VA_OPT__ (, __VA_ARGS__ rp$)
#define __Q_reduce_(f, i, j, ...)                                             \
  __VA_OPT__ (__P_reduce_ lp$ f, ) f (i, j) __VA_OPT__ (, __VA_ARGS__ rp$)
#undef $reduce
#define $reduce(f, i, j, ...)                                                 \
  scan$ (__P_reduce_ (f, i, j __VA_OPT__ (, ) __VA_ARGS__))
#endif /* RECURSIVE_REDUCE_MACRO */

#define head$(c, ...) c

#define __P_tail_(c, d) d
#define tail$(c, ...) $reduce (__P_tail_, , c __VA_OPT__ (, ) __VA_ARGS__)

#define __P_typeof_helper_(i, j) 0 ? i : (__typeof__ (j)){ 0 }
#define typeof(a, ...)                                                        \
  __typeof__ (__VA_OPT__ ($reduce) (__VA_OPT__ (__P_typeof_helper_, ) (       \
      __typeof__ (a)){ 0 } __VA_OPT__ (, ) __VA_ARGS__))

#define empty$(...) head$ (__VA_OPT__ (0, ) 1)

#define __P_count_helper_(i, j) i + !empty$ (j)
#define count$(...) ($reduce (__P_count_helper_, 0, __VA_ARGS__))

#ifndef offsetof
#define offsetof(type, mbr) ((uptr)(&(((type *)0)->mbr)))
#endif
#define container_of(ptr, type, mbr)                                          \
  ((type *)(((byte *)(ptr)) - offsetof (type, mbr)))

#define packetof(data, container)                                             \
  ((container *)((byte *)(data) - sizeof (container)))
#define dataof(packet) ((void *)((byte *)(packet) + sizeof (*(packet))))

#define __P_typewarn_helper_(x, y)                                            \
  ((void)sizeof ((typeof (x) *)0 == (typeof (y) *)0), y)
#define typewarn$(a_1, a_2, ...)                                              \
  ((void)$reduce (__P_typewarn_helper_, a_1, a_2 __VA_OPT__ (, ) __VA_ARGS__))

#define ice$(expr)                                                            \
  (sizeof (int) == sizeof (*(0 ? (void *)(((long)(expr)) * 0l) : (int *)0)))

#define __P_ace_helper_(i, j) i &&ice$ (j)
#define ace$(expr, ...)                                                       \
  ($reduce (__P_ace_helper_, 1, expr __VA_OPT__ (, ) __VA_ARGS__))

#ifdef __GNUC__
#define choose$(cond, expr_1, expr_2)                                         \
  __builtin_choose_expr (cond, expr_1, expr_2)
#else
#define choose$(cond, expr_1, expr_2)                                         \
  _Generic (0 ? (void *)(sizeof (union { long uniq$ (a)[1 + !(cond)]; })      \
                         - sizeof (long))                                     \
              : (int *)0,                                                     \
      int *: (expr_1),                                                        \
      default: (expr_2))
#endif

/* override expression */
#define ovre$(e, ...)                                                         \
  choose$ (0 __VA_OPT__ (|| 1), tail$ (e __VA_OPT__ (, ) __VA_ARGS__), e)
/* override type */
#define ovrt$(t, ...) typeof (tail$ (t, __VA_OPT__ (, ) __VA_ARGS__))

#define __P_umax_(u, v)                                                       \
  sizeof (union {                                                             \
    byte uniq$ (a)[u];                                                        \
    byte uniq$ (a)[v];                                                        \
  })
#define __P_umin_(u, v) (__P_umax_ (u, v) ^ (u) ^ (v))

#define umax$(u, ...) $reduce (__P_umax_, u, u __VA_OPT__ (, ) __VA_ARGS__)
#define umin$(u, ...) $reduce (__P_umin_, u, u __VA_OPT__ (, ) __VA_ARGS__)

#define likely(cond) __builtin_expect (!!(cond), 1)
#define unlikely(cond) __builtin_expect (!!(cond), 0)

#ifdef __GNUC__
#define typematch$(type_1, type_2, expr_1, expr_2)                            \
  choose$ (__builtin_types_compatible_p (typeof (type_1), typeof (type_2)),   \
           expr_1, expr_2)
#else
#define typematch$(type_1, type_2, expr_1, expr_2)                            \
  _Generic ((void (*) (typeof (type_2) *))0,                                  \
      void (*) (typeof (type_1) *): (expr_1),                                 \
      default: (expr_2))
#endif

#define lengthof(array)                                                       \
  typematch$ (array, &(array)[0], (void)0,                                    \
              sizeof (array) / sizeof ((array)[0]))

#define dense$ __attribute__ ((__packed__))
#define inline$ inline __attribute__ ((__always_inline__))
#define pure$ __attribute__ ((__const__))
#define defer$(fn) __attribute__ ((__cleanup__ (fn)))
#define weak$ __attribute__ ((__weak__))

#define __P_add_(i, j) i + (j)
#define __P_mul_(i, j) i *(j)
#define __P_xor_(i, j) i ^ (j)
#define __P_or_(i, j) i | (j)
#define __P_and_(i, j) i &(j)

#define sum$(x, ...)                                                          \
  (tail$ (x __VA_OPT__ (, $reduce (__P_add_, (x), __VA_ARGS__))))
#define prod$(x, ...)                                                         \
  (tail$ (x __VA_OPT__ (, $reduce (__P_mul_, (x), __VA_ARGS__))))

#define __P_reduce_helper_(r, a, i, reducer, first, ...)                      \
  ({                                                                          \
    typeof (first __VA_OPT__ (, ) __VA_ARGS__) r = first;                     \
    typeof (r) a[] = { __VA_ARGS__ };                                         \
    for (usz i = 0; i < lengthof (a); ++i)                                    \
      {                                                                       \
        reducer (r, a[i]);                                                    \
      }                                                                       \
    r;                                                                        \
  })
#define reduce$(reducer, a_1, a_2, ...)                                       \
  __P_reduce_helper_ (uniq$ (r), uniq$ (a), uniq$ (i), reducer, a_1,          \
                      a_2 __VA_OPT__ (, ) __VA_ARGS__)

#define __P_add_reducer_(i, j) i += j
#define __P_mul_reducer_(i, j) i *= j
#define __P_xor_reducer_(i, j) i ^= j
#define __P_or_reducer_(i, j) i |= j
#define __P_and_reducer_(i, j) i &= j

#define __P_max_(i, j) (i) > (j) ? (i) : (j)
#define __P_max_reducer_(i, j)                                                \
  do                                                                          \
    {                                                                         \
      if (i < j)                                                              \
        i = j;                                                                \
    }                                                                         \
  while (0)
#define max(x, ...)                                                           \
  tail$ ((x)__VA_OPT__ (                                                      \
      , choose$ (ace$ (x, __VA_ARGS__), $reduce (__P_max_, x, __VA_ARGS__),   \
                 reduce$ (__P_max_reducer_, x, __VA_ARGS__))))

#define __P_min_(i, j) (i) < (j) ? (i) : (j)
#define __P_min_reducer_(i, j)                                                \
  do                                                                          \
    {                                                                         \
      if (i > j)                                                              \
        i = j;                                                                \
    }                                                                         \
  while (0)
#define min(x, ...)                                                           \
  tail$ ((x)__VA_OPT__ (                                                      \
      , choose$ (ace$ (x, __VA_ARGS__), $reduce (__P_min_, x, __VA_ARGS__),   \
                 reduce$ (__P_min_reducer_, x, __VA_ARGS__))))

#define __P_swap_helper_(t, i, j)                                             \
  ({                                                                          \
    auto t = i;                                                               \
    (i) = j;                                                                  \
    (j) = t;                                                                  \
    t;                                                                        \
  })
#define swap(i, j) __P_swap_helper_ (uniq$ (t), i, j)

#define __P_lambda_helper_(fn, type, function) ({ type fn function fn; })
#define lambda(type, function) __P_lambda_helper_ (uniq$ (fn), type, function)

/******************************* smart pointer *******************************/

#define __P_move_helper_(ret, ptr)                                            \
  ({                                                                          \
    auto ret = ptr;                                                           \
    (ptr) = null;                                                             \
    ret;                                                                      \
  })
#define move(ptr) __P_move_helper_ (uniq$ (ret), ptr)

#define __P_smart_delete_(instance, ...) free (__VA_ARGS__ (instance))

#define __P_smart_uninit_helper_(pp, instance, pp_finder)                     \
  ({                                                                          \
    auto pp = (void *(*)(void *))pp_finder (instance);                        \
    pp == null ? (instance) : pp (instance);                                  \
  })
#define __P_smart_uninit_(instance, pp_finder)                                \
  __P_smart_uninit_helper_ (uniq$ (pp), instance, pp_finder)

#define __P_get_callback_(instance)                                           \
  ((instance) == null ? null : *(void **)(instance))

#if (SMART_POINTER_IMPL + 0) == 0
#undef SMART_POINTER_IMPL
#define SMART_POINTER_IMPL 1

static inline void *
__S_free_ (void *pinstance)
{
  if (pinstance == null || *(void **)pinstance == null)
    return pinstance;
  __P_smart_delete_ (*(void **)pinstance);
  return pinstance;
}

static inline void *
__S_uninit_ (void *instance)
{
  if (instance == null)
    return null;
  return __P_smart_uninit_ (instance, __P_get_callback_);
}

static inline void *
__S_delete_ (void *pinstance)
{
  if (pinstance == null || *(void **)pinstance == null)
    return pinstance;
  __P_smart_delete_ (*(void **)pinstance, __S_uninit_);
  return pinstance;
}

static inline void *
__S_revoke_ (void *pproxy)
{
  if (pproxy == null || *(void **)pproxy == null)
    return pproxy;
  __P_smart_delete_ (*(void **)pproxy, __S_delete_);
  return pproxy;
}

static inline void *
__S_fclose_ (void *pstream)
{
  if (pstream == null || *(void **)pstream == null)
    return pstream;
  fclose (*(void **)pstream);
  return pstream;
}

#endif /* SMART_POINTER_IMPL */

#define smartptr defer$ (static$ (free))
#define autoinst defer$ (static$ (uninit))
#define smartinst defer$ (static$ (delete))
#define autoprx defer$ (static$ (delete))
#define smartprx defer$ (static$ (revoke))
#define smartfs defer$ (static$ (fclose))

#define uninit$(instance) static$ (uninit) (instance)
#define delete$(instance) macro$ (smart_delete) (instance, static$ (uninit))
#define $revoke(proxy) static$ (delete) (proxy)
#define revoke$(proxy) macro$ (smart_delete) (proxy, static$ (delete))

/******************************* smart pointer *******************************/

#define malloc$(...) malloc (sum$ (__VA_ARGS__))
#define calloc$(...) calloc (1, sum$ (__VA_ARGS__))
#define realloc$(ptr, ...) realloc (ptr, sum$ (__VA_ARGS__))
#define alloca$(...) alloca (sum$ (__VA_ARGS__))

/******************************* pseudo class ********************************/

#define fn$(fn) __D_##fn##_
#define $fn(class, fn) static$ (class##___##fn)
#define mbr$(mbr) __M_##mbr##_

/*
Be careful of default argument promotions on trailing arguments:
 - float arguments are converted to double as in floating-point promotion
 - bool, char, short, and unscoped enumerations are converted to int or wider
integer types as in integer promotion
*/

#define fx$(fn, ...) (*fn$ (fn)) (void *__VA_OPT__ (, ) __VA_ARGS__, ...)
#define $fx(class, fn, ...)                                                   \
  $fn (class, fn) (struct class * this __VA_OPT__ (, ) __VA_ARGS__)

#define bind$(class, fn, instance)                                            \
  ((instance)->fn$ (fn) = (void *)$fn (class, fn))

#define __P_call_helper_(p, instance, fn, ...)                                \
  ({                                                                          \
    auto p = instance;                                                        \
    p->fn$ (fn) (p __VA_OPT__ (, ) __VA_ARGS__);                              \
  })
#define call$(instance, fn, ...)                                              \
  __P_call_helper_ (uniq$ (p), instance, fn __VA_OPT__ (, ) __VA_ARGS__)
#define $call(class, fn, ...) $fn (class, fn) (__VA_ARGS__)

#define class$(name, structure)                                               \
  struct name                                                                 \
  {                                                                           \
    struct name *fx$ (uninit);                                                \
    struct structure;                                                         \
  }

#define new$(class, ...)                                                      \
  $call (class, init,                                                         \
         malloc$ (sizeof (struct class) __VA_OPT__ (, ) __VA_ARGS__))

#define def$(var, class, ...)                                                 \
  smartinst struct class *var = new$ (class __VA_OPT__ (, ) __VA_ARGS__)

#define trait$(name, structure)                                               \
  struct name                                                                 \
  {                                                                           \
    void *mbr$ (instance);                                                    \
    struct structure;                                                         \
  }

#define __P_invoke_helper_(p, proxy, fn, ...)                                 \
  ({                                                                          \
    auto p = proxy;                                                           \
    p->fn$ (fn) (*(void **)p __VA_OPT__ (, ) __VA_ARGS__);                    \
  })
#define invoke$(proxy, fn, ...)                                               \
  __P_invoke_helper_ (uniq$ (p), proxy, fn __VA_OPT__ (, ) __VA_ARGS__)

/******************************* pseudo class ********************************/

/***************************** pseudo coroutine ******************************/

typedef typeof (__LINE__) coroutine;

/* mbr$ (progcnt) should be zeroed */
#define co$(name, structure)                                                  \
  struct name                                                                 \
  {                                                                           \
    coroutine mbr$ (progcnt);                                                 \
    struct structure;                                                         \
  }

/* type fn ([coptr,] ...) async$ (coptr) { ...; exit$ (ret); } */
#define async$(coptr)                                                         \
  {                                                                           \
    auto this = coptr;                                                        \
    switch (*(coroutine *)this)                                               \
      {                                                                       \
      default:;

#ifdef _REENTRANT
#define __P_async_helper_(ctx, structure)                                     \
  async$ (({                                                                  \
    static __thread co$ (, structure) ctx;                                    \
    &ctx;                                                                     \
  }))
#else
#define __P_async_helper_(ctx, structure)                                     \
  async$ (({                                                                  \
    static co$ (, structure) ctx;                                             \
    &ctx;                                                                     \
  }))
#endif

/* type fn (...) $async ({...}) { ...; exit$ (ret); } */
#define $async(structure) __P_async_helper_ (uniq$ (ctx), structure)

#define yield$(...)                                                           \
  do                                                                          \
    {                                                                         \
      *(coroutine *)this = __LINE__;                                          \
      return __VA_ARGS__;                                                     \
    case __LINE__:;                                                           \
    }                                                                         \
  while (0)

#define loop$(...)                                                            \
  do                                                                          \
    {                                                                         \
      *(coroutine *)this = 0;                                                 \
      return __VA_ARGS__;                                                     \
    }                                                                         \
  while (0)

#define __P_await_helper_(r, call, target, ret)                               \
  ({                                                                          \
    typeof (call) r;                                                          \
    for (;;)                                                                  \
      {                                                                       \
        r = call;                                                             \
        if (target (r))                                                       \
          break;                                                              \
        yield$ (ret);                                                         \
      }                                                                       \
    r;                                                                        \
  })
#define __P_await_3_(call, target, ret)                                       \
  __P_await_helper_ (uniq$ (r), call, target, ret)
#define __P_await_2_(call, target, ...) __P_await_3_ (call, target, 0)
#define __P_await_1_(call, ...) __P_await_2_ (call, )
#define __P_await_va_(a_1, a_2, a_3, argc, ...)                               \
  cat$ (__P_await_, argc##_) (a_1, a_2, a_3)
#define await$(call, ...)                                                     \
  __P_await_va_ (call, __VA_ARGS__ __VA_OPT__ (, ) 3, 2, 1)

/* exit$ must be called directly at the end of each coroutine */
#define exit$(...)                                                            \
  }                                                                           \
  yield$ (__VA_ARGS__);                                                       \
  }                                                                           \
  return __VA_ARGS__

/***************************** pseudo coroutine ******************************/

#ifdef __clang__
#define print_struct(ptr) __builtin_dump_struct (ptr, printf)
#endif

/*********************************** math ************************************/

/* single line trick: while ((x) && (x %= y ^= x ^= y ^= x)); */
#define __P_gcd_helper_(i, j, r, x, y)                                        \
  ({                                                                          \
    auto i = x;                                                               \
    auto j = y;                                                               \
    while (j)                                                                 \
      {                                                                       \
        auto r = i % j;                                                       \
        i = j;                                                                \
        j = r;                                                                \
      }                                                                       \
    i;                                                                        \
  })
#define __P_gcd_(x, y) __P_gcd_helper_ (uniq$ (i), uniq$ (j), uniq$ (r), x, y)
#define __P_gcd_reducer_(x, y) x = __P_gcd_ (x, y)
#define gcd(i, ...)                                                           \
  tail$ ((i)__VA_OPT__ (, reduce$ (__P_gcd_reducer_, i, __VA_ARGS__)))

#define __P_lcm_helper_(i, j, r, x, y)                                        \
  ({                                                                          \
    auto i = x;                                                               \
    auto j = y;                                                               \
    auto r = __P_gcd_ (i, j);                                                 \
    r ? (i / r) * j : 0;                                                      \
  })
#define __P_lcm_(x, y) __P_lcm_helper_ (uniq$ (i), uniq$ (j), uniq$ (r), x, y)
#define __P_lcm_reducer_(x, y) x = __P_lcm_ (x, y)
#define lcm(i, ...)                                                           \
  tail$ ((i)__VA_OPT__ (, reduce$ (__P_lcm_reducer_, i, __VA_ARGS__)))

#define __P_lowbit_helper_(t, x)                                              \
  ({                                                                          \
    auto t = x;                                                               \
    t & -t;                                                                   \
  })
#define __P_lowbit_(x) __P_lowbit_helper_ (uniq$ (t), x)
#define lowbit(x) choose$ (ice$ (x), (x) & -(x), __P_lowbit_ (x))

#define __P_qpow_helper_(b, res, e, base, exp, ...)                           \
  ({                                                                          \
    auto b = (base)__VA_OPT__ (% (__VA_ARGS__));                              \
    auto res = (typeof (b)){ 1 };                                             \
    for (auto e = exp; e; e >>= 1)                                            \
      {                                                                       \
        res = (res * ((e & 1) * (b ^ 1) ^ 1)) __VA_OPT__ (% (__VA_ARGS__));   \
        b = (b * b) __VA_OPT__ (% (__VA_ARGS__));                             \
      }                                                                       \
    res;                                                                      \
  })
#define qpow(base, exp, ...)                                                  \
  __P_qpow_helper_ (uniq$ (b), uniq$ (res), uniq$ (e), base,                  \
                    exp __VA_OPT__ (, ) __VA_ARGS__)

/*********************************** math ************************************/

/********************************** bitset ***********************************/

#define bitbyte$(array, index) (((byte *)(array))[(usz)(index) >> 3])
#define bitbit$(index) (1u << ((index) & (7u)))
#define __P_bitdo_helper_(i, op, array, index)                                \
  ({                                                                          \
    auto i = (usz)(index);                                                    \
    bitbyte$ (array, i) op bitbit$ (i);                                       \
  })
#define bitdo$(op, array, index)                                              \
  __P_bitdo_helper_ (uniq$ (i), op, array, index)
#define bitget$(array, index) bitdo$ (&, array, index)
#define bitput$(array, index) bitdo$ (|=, array, index)
#define bitclear$(array, index) bitdo$ (&= ~, array, index)
#define bitflip$(array, index) bitdo$ (^=, array, index)

/********************************** bitset ***********************************/

/******************************* dynamic array *******************************/

#define daexp$ 2
#define dadyn$ 1
#define dalb$ (daexp$ - dadyn$)
#define daub$ (daexp$ + dadyn$)

#define __P_dynarr_helper_(uc, us, r, capacity, size, page)                   \
  ({                                                                          \
    auto uc = (usz)(capacity) / (page);                                       \
    auto us = (usz)(size) / (page);                                           \
    usz r = uc;                                                               \
    if (us <= daub$)                                                          \
      r = daub$ + dadyn$ + 1;                                                 \
    else if (us >= uc || us <= uc * dalb$ / daub$)                            \
      r = us * daub$ / daexp$;                                                \
    (page) * r;                                                               \
  })
#define dynarr$(capacity, size, ...)                                          \
  __P_dynarr_helper_ (uniq$ (uc), uniq$ (us), uniq$ (r), capacity, size,      \
                      umax$ (sizeof (int), __VA_ARGS__))

/******************************* dynamic array *******************************/

/***************************** Xor Address PaiR ******************************/

typedef uptr xapr;
#define xapr$(cmd) __XAPR_##cmd##_
#define __XAPR_otr_(pair, nbr)                                                \
  ((xapr *)((byte *)0 + (*(xapr *)(pair) ^ (xapr)(nbr))))
#define __P_XAPR_ins_helper_(upair, un_1, un_2, pair, n_1, n_2)               \
  ({                                                                          \
    auto upair = (xapr *)(pair);                                              \
    auto un_1 = (xapr *)(n_1);                                                \
    auto un_2 = (xapr *)(n_2);                                                \
    *upair = (xapr)un_1 ^ (xapr)un_2;                                         \
    *un_1 ^= (xapr)un_2 ^ (xapr)upair;                                        \
    *un_2 ^= (xapr)un_1 ^ (xapr)upair;                                        \
    upair;                                                                    \
  })
#define __XAPR_ins_(pair, n_1, n_2)                                           \
  __P_XAPR_ins_helper_ (uniq$ (upair), uniq$ (un_1), uniq$ (un_2), pair, n_1, \
                        n_2)
#define __P_XAPR_rem_helper_(upair, unbr, uotr, pair, nbr)                    \
  ({                                                                          \
    auto upair = (xapr *)(pair);                                              \
    auto unbr = (xapr *)(nbr);                                                \
    auto uotr = xapr$ (otr) (upair, unbr);                                    \
    *unbr ^= (xapr)uotr ^ (xapr)upair;                                        \
    *uotr ^= (xapr)unbr ^ (xapr)upair;                                        \
    uotr;                                                                     \
  })
#define __XAPR_rem_(pair, nbr)                                                \
  __P_XAPR_rem_helper_ (uniq$ (upair), uniq$ (unbr), uniq$ (uotr), pair, nbr)

/***************************** Xor Address PaiR ******************************/

/****************************** xor linked list ******************************/

#define list$(cmd) __LS_##cmd##_
#define __P_LS_ins_helper_(uxpr, uprev, unext, ufirst, ulast, xpr, prev,      \
                           next, first, last)                                 \
  ({                                                                          \
    auto uxpr = (xapr *)(xpr);                                                \
    auto uprev = (xapr *)(prev);                                              \
    auto unext = (xapr *)(next);                                              \
    auto ufirst = (xapr **)(first);                                           \
    auto ulast = (xapr **)(last);                                             \
    if (uprev == null && unext == null)                                       \
      {                                                                       \
        *uxpr = 0;                                                            \
        *ufirst = *ulast = uxpr;                                              \
      }                                                                       \
    else if (uprev == null)                                                   \
      *ufirst = xapr$ (ins) (uxpr, *ufirst, *ulast);                          \
    else if (unext == null)                                                   \
      *ulast = xapr$ (ins) (uxpr, *ufirst, *ulast);                           \
    else                                                                      \
      xapr$ (ins) (uxpr, uprev, unext);                                       \
    uxpr;                                                                     \
  })
#define __LS_ins_(xpr, prev, next, first, last)                               \
  __P_LS_ins_helper_ (uniq$ (uxpr), uniq$ (uprev), uniq$ (unext),             \
                      uniq$ (ufirst), uniq$ (ulast), xpr, prev, next, first,  \
                      last)
#define __P_LS_rem_helper_(uxpr, unbr, ufirst, ulast, xpr, nbr, first, last)  \
  ({                                                                          \
    auto uxpr = (xapr *)(xpr);                                                \
    auto unbr = (xapr *)(nbr);                                                \
    auto ufirst = (xapr **)(first);                                           \
    auto ulast = (xapr **)(last);                                             \
    if (uxpr == unbr)                                                         \
      *ufirst = *ulast = null;                                                \
    else if (uxpr == *ufirst)                                                 \
      *ufirst = xapr$ (rem) (uxpr, *ulast);                                   \
    else if (uxpr == *ulast)                                                  \
      *ulast = xapr$ (rem) (uxpr, *ufirst);                                   \
    else                                                                      \
      xapr$ (rem) (uxpr, unbr);                                               \
    uxpr;                                                                     \
  })
#define __LS_rem_(xpr, nbr, first, last)                                      \
  __P_LS_rem_helper_ (uniq$ (uxpr), uniq$ (unbr), uniq$ (ufirst),             \
                      uniq$ (ulast), xpr, nbr, first, last)
#define __P_LS_unshift_helper_(ufirst, xpr, first, last)                      \
  ({                                                                          \
    auto ufirst = (xapr **)(first);                                           \
    list$ (ins) (xpr, null, *ufirst, ufirst, last);                           \
  })
#define __LS_unshift_(xpr, first, last)                                       \
  __P_LS_unshift_helper_ (uniq$ (ufirst), xpr, first, last);
#define __P_LS_shift_helper_(ufirst, ulast, first, last)                      \
  ({                                                                          \
    auto ufirst = (xapr **)(first);                                           \
    auto ulast = (xapr **)(last);                                             \
    list$ (rem) (*ufirst, *ulast, ufirst, ulast);                             \
  })
#define __LS_shift_(first, last)                                              \
  __P_LS_shift_helper_ (uniq$ (ufirst), uniq$ (ulast), first, last)
#define __P_LS_push_helper_(ulast, xpr, first, last)                          \
  ({                                                                          \
    auto ulast = (xapr **)(last);                                             \
    list$ (ins) (xpr, *ulast, null, first, ulast);                            \
  })
#define __LS_push_(xpr, first, last)                                          \
  __P_LS_push_helper_ (uniq$ (ulast), xpr, first, last);
#define __P_LS_pop_helper_(ufirst, ulast, first, last)                        \
  ({                                                                          \
    auto ufirst = (xapr **)(first);                                           \
    auto ulast = (xapr **)(last);                                             \
    list$ (rem) (*ulast, *ufirst, ufirst, ulast);                             \
  })
#define __LS_pop_(first, last)                                                \
  __P_LS_pop_helper_ (uniq$ (ufirst), uniq$ (ulast), first, last)

#define __P_lsfor_helper_(f, i, var, zeroth, first, last)                     \
  for (xapr *f = (xapr *)&f, *i = (xapr *)(zeroth), *var = (xapr *)(first);   \
       f != (last); i = xapr$ (otr) (var, i), f = swap (var, i))
#define __P_lsfor_4_(var, zeroth, first, last)                                \
  __P_lsfor_helper_ (uniq$ (f), uniq$ (i), var, zeroth, first, last)
#define __P_lsfor_3_(var, first, last, ...)                                   \
  __P_lsfor_4_ (var, last, first, last)
#define __P_lsfor_va_(a_1, a_2, a_3, a_4, argc, ...)                          \
  cat$ (__P_lsfor_, argc##_) (a_1, a_2, a_3, a_4)
#define lsfor$(var, xpr_1, xpr_2, ...)                                        \
  __P_lsfor_va_ (var, xpr_1, xpr_2, __VA_ARGS__ __VA_OPT__ (, ) 4, 3)

#define __P_lsfree_worker_(ufirst, ulast, i, first, last, ...)                \
  do                                                                          \
    {                                                                         \
      auto ufirst = (xapr **)(first);                                         \
      auto ulast = (xapr **)(last);                                           \
      xapr *i;                                                                \
      do                                                                      \
        {                                                                     \
          i = list$ (shift) (ufirst, ulast);                                  \
          __VA_OPT__ (__VA_ARGS__;)                                           \
          free (i);                                                           \
        }                                                                     \
      while (i);                                                              \
    }                                                                         \
  while (0)
#define __P_lsfree_helper_(ufirst, ulast, i, first, last, ...)                \
  __P_lsfree_worker_ (ufirst, ulast, i, first,                                \
                      last __VA_OPT__ (, __VA_ARGS__ (i)))
#define lsfree$(first, last, ...)                                             \
  __P_lsfree_helper_ (uniq$ (ufirst), uniq$ (ulast), uniq$ (i), first,        \
                      last __VA_OPT__ (, ) __VA_ARGS__)

/****************************** xor linked list ******************************/

#define __P_memhash_helper_(umemb, usize, m, res, i, memb, size, mod)         \
  ({                                                                          \
    auto umemb = (byte *)(memb);                                              \
    auto usize = (usz)(size);                                                 \
    auto m = mod;                                                             \
    auto res = (typeof (m)){ 0 };                                             \
    for (usz i = 0; i < usize; ++i)                                           \
      res = (res << 8 ^ umemb[i]) % m;                                        \
    res;                                                                      \
  })
#define __P_memhash_3_(memb, size, mod)                                       \
  __P_memhash_helper_ (uniq$ (umemb), uniq$ (usize), uniq$ (m), uniq$ (res),  \
                       uniq$ (i), memb, size, mod)
#define __P_memhash_2_(memb, size, ...)                                       \
  __P_memhash_3_ (memb, size, const$ (tp56))
#define __P_memhash_1_(memb, ...) __P_memhash_2_ (memb, sizeof (memb))
#define __P_memhash_va_(a_1, a_2, a_3, argc, ...)                             \
  cat$ (__P_memhash_, argc##_) (a_1, a_2, a_3)
#define memhash(memb, ...)                                                    \
  __P_memhash_va_ (memb, __VA_ARGS__ __VA_OPT__ (, ) 3, 2, 1)

#define __P_strhash_helper_(ustr, m, res, i, str, mod)                        \
  ({                                                                          \
    auto ustr = (byte *)(str);                                                \
    auto m = mod;                                                             \
    auto res = (typeof (m)){ 0 };                                             \
    for (usz i = 0; ustr[i]; ++i)                                             \
      res = (res << 8 ^ ustr[i]) % m;                                         \
    res;                                                                      \
  })
#define __P_strhash_2_(str, mod)                                              \
  __P_strhash_helper_ (uniq$ (ustr), uniq$ (m), uniq$ (res), uniq$ (i), str,  \
                       mod)
#define __P_strhash_1_(str, ...) __P_strhash_2_ (str, const$ (tp56))
#define __P_strhash_va_(a_1, a_2, argc, ...)                                  \
  cat$ (__P_strhash_, argc##_) (a_1, a_2)
#define strhash(str, ...)                                                     \
  __P_strhash_va_ (str, __VA_ARGS__ __VA_OPT__ (, ) 2, 1)

/************************************ I/O ************************************/

#if !defined __P_UNLOCKED_STDIO_                                              \
    && (defined __USE_POSIX199506                                             \
        || (defined getchar_unlocked && defined getc_unlocked                 \
            && defined putchar_unlocked && defined putc_unlocked))
#define __P_UNLOCKED_STDIO_ 1
#define __P_getchar_worker_ getchar_unlocked
#define __P_getc_worker_ getc_unlocked
#define __P_putchar_worker_ putchar_unlocked
#define __P_putc_worker_ putc_unlocked
#elif defined _WIN32
#define __P_UNLOCKED_STDIO_ 32
#define __P_getchar_worker_ _getchar_nolock
#define __P_getc_worker_ _getc_nolock
#define __P_putchar_worker_ _putchar_nolock
#define __P_putc_worker_ _putc_nolock
#endif
#if (__P_UNLOCKED_STDIO_ + 0) == 1                                            \
    && (defined __USE_GNU                                                     \
        || (defined fgets_unlocked && defined fputs_unlocked))
#undef __P_UNLOCKED_STDIO_
#define __P_UNLOCKED_STDIO_ 3
#define __P_fgets_worker_ fgets_unlocked
#define __P_fputs_worker_ fputs_unlocked
#endif

/* fallback */

#ifndef __P_getchar_worker_
#define __P_getchar_worker_ getchar
#endif
#ifndef __P_getc_worker_
#define __P_getc_worker_ getc
#endif
#ifndef __P_putchar_worker_
#define __P_putchar_worker_ putchar
#endif
#ifndef __P_putc_worker_
#define __P_putc_worker_ putc
#endif
#ifndef __P_fgets_worker_
#define __P_fgets_worker_ fgets
#endif
#ifndef __P_fputs_worker_
#define __P_fputs_worker_ fputs
#endif

#ifndef EOL
#define EOL 10
#endif

#if (__P_UNLOCKED_STDIO_ + 0) != 0 || !defined getchar && !defined getc
#define __P_getchar_1_(stream) __P_getc_worker_ (stream)
#define __P_getchar_0_(...) __P_getchar_worker_ ()
#define __P_getchar_va_(a_1, argc, ...) cat$ (__P_getchar_, argc##_) (a_1)
#undef getchar
#define getchar(...) __P_getchar_va_ (__VA_ARGS__ __VA_OPT__ (, ) 1, 0)
#undef getc
#define getc(...) getchar (__VA_ARGS__)
#endif

#if (__P_UNLOCKED_STDIO_ + 0) != 0 || !defined putchar && !defined putc
#define __P_putchar_2_(c, stream) __P_putc_worker_ (c, stream)
#define __P_putchar_1_(c, ...) __P_putchar_worker_ (c)
#define __P_putchar_0_(...) __P_putchar_worker_ (EOL)
#define __P_putchar_va_(a_1, a_2, argc, ...)                                  \
  cat$ (__P_putchar_, argc##_) (a_1, a_2)
#undef putchar
#define putchar(...) __P_putchar_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#undef putc
#define putc(...) putchar (__VA_ARGS__)
#endif

#define __P_ungetc_2_(c, stream) ungetc (c, stream)
#define __P_ungetc_1_(c, ...) ungetc (c, stdin)
#define __P_ungetc_0_(...) ungetc (EOL, stdin)
#define __P_ungetc_va_(a_1, a_2, argc, ...)                                   \
  cat$ (__P_ungetc_, argc##_) (a_1, a_2)
#define ungetc(...) __P_ungetc_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#define ungetchar(...) ungetc (__VA_ARGS__)

#define __P_getc_delimited_helper_(c, r, i, delim, ...)                       \
  ({                                                                          \
    int c = getc (__VA_ARGS__);                                               \
    int r = c;                                                                \
    usz i = 0;                                                                \
    for (i = 0; (delim)[i]; ++i)                                              \
      if (c == (delim)[i])                                                    \
        {                                                                     \
          r = EOF;                                                            \
          break;                                                              \
        }                                                                     \
    for (i += !!(delim)[i]; (delim)[i]; ++i)                                  \
      {                                                                       \
        c = getc (__VA_ARGS__);                                               \
        if (c != (delim)[i])                                                  \
          {                                                                   \
            ungetc (c __VA_OPT__ (, ) __VA_ARGS__);                           \
            break;                                                            \
          }                                                                   \
      }                                                                       \
    r;                                                                        \
  })
#define __P_getc_delimited_(delim, ...)                                       \
  __P_getc_delimited_helper_ (uniq$ (c), uniq$ (r), uniq$ (i),                \
                              delim __VA_OPT__ (, ) __VA_ARGS__)

#define __P_gets_3_(str, length, stream)                                      \
  __P_fgets_worker_ (str, (iptr)(length), stream)
#define __P_gets_2_(str, length, ...) __P_gets_3_ (str, length, stdin)
#define __P_gets_1_(str, ...) __P_gets_2_ (str, lengthof (str))
#define __P_gets_va_(a_1, a_2, a_3, argc, ...)                                \
  cat$ (__P_gets_, argc##_) (a_1, a_2, a_3)
#define __P_getvs_helper_(ud, ups, sz, cap, str, ch, sp, i, s, delimiter,     \
                          psize, stream)                                      \
  ({                                                                          \
    auto ud = (const char *)(delimiter);                                      \
    auto ups = (usz *)((byte *)0 + (uptr)(psize));                            \
    usz sz = 0, cap = dynarr$ (0, 2);                                         \
    char *str = calloc (1, cap);                                              \
    while (str)                                                               \
      {                                                                       \
        int ch = __P_getc_delimited_ (ud, stream);                            \
        if (ch == EOF)                                                        \
          break;                                                              \
        char *s = realloc (str, cap = dynarr$ (cap, sz + 2));                 \
        if (s)                                                                \
          {                                                                   \
            s[sz++] = ch;                                                     \
            s[sz] = 0;                                                        \
          }                                                                   \
        str = s;                                                              \
      }                                                                       \
    if (str && ups)                                                           \
      *ups = sz;                                                              \
    str;                                                                      \
  })
#define __P_getvs_3_(delimiter, psize, stream)                                \
  __P_getvs_helper_ (uniq$ (ud), uniq$ (ups), uniq$ (sz), uniq$ (cap),        \
                     uniq$ (str), uniq$ (ch), uniq$ (sp), uniq$ (i),          \
                     uniq$ (s), delimiter, psize, stream)
#define __P_getvs_2_(delimiter, psize, ...)                                   \
  __P_getvs_3_ (delimiter, psize, stdin)
#define __P_getvs_1_(delimiter, ...) __P_getvs_2_ (delimiter, null)
#define __P_getvs_0_(...) __P_getvs_1_ ("\r\n")
#define __P_getvs_va_(a_1, a_2, a_3, argc, ...)                               \
  cat$ (__P_getvs_, argc##_) (a_1, a_2, a_3)
#define getvs(...) __P_getvs_va_ (__VA_ARGS__ __VA_OPT__ (, ) 3, 2, 1, 0)
#define getvstr(...) getvs (__VA_ARGS__)
#ifdef __GNUC__
#define __P_gets_g_(str, ...)                                                 \
  choose$ (__builtin_constant_p (str),                                        \
           getvs (str __VA_OPT__ (, ) __VA_ARGS__),                           \
           __P_gets_va_ (str, __VA_ARGS__ __VA_OPT__ (, ) 3, 2, 1))
#define gets(...) tail$ (getvs () __VA_OPT__ (, __P_gets_g_ (__VA_ARGS__)))
#else
#define gets(...)                                                             \
  tail$ (getvs () __VA_OPT__ (, __P_gets_va_ (__VA_ARGS__, 3, 2, 1)))
#endif
#define getstr(...) gets (__VA_ARGS__)

#define __P_puts_2_(str, stream) __P_fputs_worker_ (str, stream)
#define __P_puts_1_(str, ...) __P_fputs_worker_ (str, stdout)
#define __P_puts_0_(...) puts ("")
#define __P_puts_va_(a_1, a_2, argc, ...) cat$ (__P_puts_, argc##_) (a_1, a_2)
#define puts(...) __P_puts_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#define putstr(...) puts (__VA_ARGS__)

#define __P_peekchar_helper_(c, ...)                                          \
  ({                                                                          \
    int c = getc (__VA_ARGS__);                                               \
    ungetc (c __VA_OPT__ (, ) __VA_ARGS__);                                   \
    c;                                                                        \
  })
#define peekchar(...)                                                         \
  __P_peekchar_helper_ (uniq$ (c) __VA_OPT__ (, ) __VA_ARGS__)
#define peekc(...) peekchar (__VA_ARGS__)

/* quick decimal integer I/O */

#define __P_getdec_helper_(j, s, ch, type, ...)                               \
  ({                                                                          \
    auto j = (type){ 0 };                                                     \
    bool s = false;                                                           \
    int ch = '+';                                                             \
    while (ch != EOF && !isdigit (ch))                                        \
      {                                                                       \
        s = ch == '-';                                                        \
        ch = getc (__VA_ARGS__);                                              \
      }                                                                       \
    while (isdigit (ch))                                                      \
      {                                                                       \
        j = (j << 3) + (j << 1) + ('0' - ch);                                 \
        ch = getc (__VA_ARGS__);                                              \
      }                                                                       \
    ungetc (ch __VA_OPT__ (, ) __VA_ARGS__);                                  \
    !s ? -j : j;                                                              \
  })
#define __P_getdec_2_(type, stream)                                           \
  __P_getdec_helper_ (uniq$ (j), uniq$ (s), uniq$ (ch), type, stream)
#define __P_getdec_1_(type, ...) __P_getdec_2_ (type, )
#define __P_getdec_0_(...) __P_getdec_1_ (int)
#define __P_getdec_va_(a_1, a_2, argc, ...)                                   \
  cat$ (__P_getdec_, argc##_) (a_1, a_2)
#define getdec(...) __P_getdec_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#define getd(...) getdec (__VA_ARGS__)

#define __P_putdec_helper_(j, s, sta, ptr, i, ...)                            \
  do                                                                          \
    {                                                                         \
      auto j = i;                                                             \
      bool s = j < 0;                                                         \
      char sta[39];                                                           \
      char *ptr = sta;                                                        \
      do                                                                      \
        {                                                                     \
          *ptr++ = '0' + (j % 10) * (1 - ((!!s) << 1));                       \
          j /= 10;                                                            \
        }                                                                     \
      while (j);                                                              \
      if (s)                                                                  \
        putc ('-' __VA_OPT__ (, ) __VA_ARGS__);                               \
      while (ptr > sta)                                                       \
        putc (*--ptr __VA_OPT__ (, ) __VA_ARGS__);                            \
    }                                                                         \
  while (0)
#define putdec(i, ...)                                                        \
  __P_putdec_helper_ (uniq$ (j), uniq$ (s), uniq$ (sta), uniq$ (ptr),         \
                      i __VA_OPT__ (, ) __VA_ARGS__)
#define putd(i, ...) putdec (i __VA_OPT__ (, ) __VA_ARGS__)

#define getint(...) getdec (__VA_ARGS__)
#define geti(...) getd (__VA_ARGS__)
#define putint(i, ...) putdec (i __VA_OPT__ (, ) __VA_ARGS__)
#define puti(i, ...) putd (i __VA_OPT__ (, ) __VA_ARGS__)

#define __P_seekchar_helper_(uc, ch, c, stream)                               \
  ({                                                                          \
    auto uc = c;                                                              \
    int ch;                                                                   \
    do                                                                        \
      ch = getc (stream);                                                     \
    while (ch != uc && ch != EOF);                                            \
    ch;                                                                       \
  })
#define __P_seekchar_2_(c, stream)                                            \
  __P_seekchar_helper_ (uniq$ (uc), uniq$ (ch), c, stream)
#define __P_seekchar_1_(c, ...) __P_seekchar_2_ (c, )
#define __P_seekchar_0_(...) __P_seekchar_1_ (EOL)
#define __P_seekchar_va_(a_1, a_2, argc, ...)                                 \
  cat$ (__P_seekchar_, argc##_) (a_1, a_2)
#define seekchar(...) __P_seekchar_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#define seekc(...) seekchar (__VA_ARGS__)

#define __P_seekint_helper_(ui, j, i, ...)                                    \
  ({                                                                          \
    auto ui = i;                                                              \
    typeof (ui) j;                                                            \
    do                                                                        \
      j = geti (typeof (ui) __VA_OPT__ (, ) __VA_ARGS__);                     \
    while (j != ui && peekc (__VA_ARGS__) != EOF);                            \
    j;                                                                        \
  })
#define seekint(i, ...)                                                       \
  __P_seekint_helper_ (uniq$ (ui), uniq$ (j), i __VA_OPT__ (, ) __VA_ARGS__)
#define seeki(i, ...) seekint (i __VA_OPT__ (, ) __VA_ARGS__)

#define __P_echo_(a)                                                          \
  _Generic (a,                                                                \
      char *: ({                                                              \
              puts (_Generic (a, char *: a, default: ""));                    \
              (void)0;                                                        \
            }),                                                               \
      default: ({                                                             \
              puti (_Generic (a, char *: 0, default: a));                     \
              (void)0;                                                        \
            }))
#define __P_echo_helper_(a, b)                                                \
  a;                                                                          \
  putchar (' ');                                                              \
  __P_echo_ (b);
#define __P_echo_n_(a, ...)                                                   \
  do                                                                          \
    {                                                                         \
      __VA_OPT__ ($reduce)                                                    \
      (__VA_OPT__ (__P_echo_helper_, ) __P_echo_ (a) __VA_OPT__ (, )          \
           __VA_ARGS__);                                                      \
    }                                                                         \
  while (0)
#define echo(...)                                                             \
  ({                                                                          \
    __VA_OPT__ (__P_echo_n_ (__VA_ARGS__));                                   \
    putchar ();                                                               \
    (void)0;                                                                  \
  })

/************************************ I/O ************************************/

/************************ Miller-Rabin primality test ************************/

#define __P_isprime_helper_(ui, res, u, t, tn, j, stn, v, s, i)               \
  ({                                                                          \
    auto ui = i;                                                              \
    bool res = true;                                                          \
    if (ui < 3 || ui % 2 == 0)                                                \
      res = ui == 2;                                                          \
    else if (ui % 3 == 0)                                                     \
      res = ui == 3;                                                          \
    else                                                                      \
      {                                                                       \
        auto u = ui - 1;                                                      \
        int t = 0;                                                            \
        while ((u & 1) == 0)                                                  \
          {                                                                   \
            u >>= 1;                                                          \
            ++t;                                                              \
          }                                                                   \
        const u32 tn[]                                                        \
            = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };           \
        for (usz j = 0; j < lengthof (tn); ++j)                               \
          {                                                                   \
            auto stn = choose$ (sizeof (ui) < sizeof (u64), (u64)tn[j],       \
                                (u128)tn[j])                                  \
                       % ui;                                                  \
            if (stn == 0 || stn == 1 || stn == ui - 1)                        \
              continue;                                                       \
            auto v = qpow (stn, u, ui);                                       \
            if (v == 1)                                                       \
              continue;                                                       \
            int s;                                                            \
            for (s = 0; s < t; ++s)                                           \
              {                                                               \
                if (v == ui - 1)                                              \
                  break;                                                      \
                v = v * v % ui;                                               \
              }                                                               \
            if (s == t)                                                       \
              {                                                               \
                res = false;                                                  \
                break;                                                        \
              }                                                               \
          }                                                                   \
      }                                                                       \
    res;                                                                      \
  })

#define isprime(i)                                                            \
  __P_isprime_helper_ (uniq$ (ui), uniq$ (res), uniq$ (u), uniq$ (t),         \
                       uniq$ (tn), uniq$ (j), uniq$ (stn), uniq$ (v),         \
                       uniq$ (s), i)

/************************ Miller-Rabin primality test ************************/

#define __P_trng_helper_(utp, useed, uend, ubeg)                              \
  ({                                                                          \
    struct timespec utp;                                                      \
    u64 useed;                                                                \
    if (timespec_get (&utp, TIME_UTC) == 0)                                   \
      useed                                                                   \
          = (~(u64)utp.tv_sec ^ ~(u64)utp.tv_nsec ^ (u64)utp.tv_nsec << 32);  \
    else                                                                      \
      useed = time (null);                                                    \
    useed *= 1111111111111111111;                                             \
    useed ^= useed >> 33;                                                     \
    clock_t uend;                                                             \
    clock_t ubeg = clock ();                                                  \
    do                                                                        \
      {                                                                       \
        useed += ubeg;                                                        \
        useed *= 1111111111111111111;                                         \
      }                                                                       \
    while ((uend = clock ()) == ubeg);                                        \
    useed += uend;                                                            \
    useed *= 1111111111111111111;                                             \
    useed ^= useed >> 33;                                                     \
    useed;                                                                    \
  })
#define trng$()                                                               \
  __P_trng_helper_ (uniq$ (utp), uniq$ (useed), uniq$ (uend), uniq$ (ubeg))

/***************************** Mersenne Twister ******************************/

#define __P_mt_va_(name, ...) __MT_##name##_
#define mt$(...) __P_mt_va_ (__VA_ARGS__ __VA_OPT__ (, ) u64)

#define __MT_NN_ 312
#define __MT_MM_ 156
#define __MT_MATRIX_A_ UINT64_C (0xb5026f5aa96619e9)
#define __MT_UM_ UINT64_C (0xffffffff80000000)
#define __MT_LM_ UINT64_C (0x7fffffff)

#if (MERSENNE_TWISTER_64_IMPL + 0) == 0
#undef MERSENNE_TWISTER_64_IMPL
#define MERSENNE_TWISTER_64_IMPL 1

#ifdef _REENTRANT
static __thread u64 __MT_mt_[__MT_NN_];
static __thread int __MT_mti_ = __MT_NN_ + 1;
#else
static u64 __MT_mt_[__MT_NN_];
static int __MT_mti_ = __MT_NN_ + 1;
#endif

static inline void
__MT_init_genrand64_ (u64 __MT_seed_)
{
  __MT_mt_[0] = __MT_seed_;
  for (__MT_mti_ = 1; __MT_mti_ < __MT_NN_; ++__MT_mti_)
    __MT_mt_[__MT_mti_]
        = (UINT64_C (6364136223846793005)
               * (__MT_mt_[__MT_mti_ - 1] ^ (__MT_mt_[__MT_mti_ - 1] >> 62))
           + __MT_mti_);
}

static inline void
__MT_init_by_array64_ (u64 __MT_init_key_[], u64 __MT_key_length_)
{
  unsigned int __MT_i_, __MT_j_;
  u64 __MT_k_;
  __MT_init_genrand64_ (UINT64_C (19650218));
  __MT_i_ = 1;
  __MT_j_ = 0;
  __MT_k_ = (__MT_NN_ > __MT_key_length_ ? __MT_NN_ : __MT_key_length_);
  for (; __MT_k_; --__MT_k_)
    {
      __MT_mt_[__MT_i_]
          = (__MT_mt_[__MT_i_]
             ^ ((__MT_mt_[__MT_i_ - 1] ^ (__MT_mt_[__MT_i_ - 1] >> 62))
                * UINT64_C (3935559000370003845)))
            + __MT_init_key_[__MT_j_] + __MT_j_;
      ++__MT_i_;
      ++__MT_j_;
      if (__MT_i_ >= __MT_NN_)
        {
          __MT_mt_[0] = __MT_mt_[__MT_NN_ - 1];
          __MT_i_ = 1;
        }
      if (__MT_j_ >= __MT_key_length_)
        __MT_j_ = 0;
    }
  for (__MT_k_ = __MT_NN_ - 1; __MT_k_; --__MT_k_)
    {
      __MT_mt_[__MT_i_]
          = (__MT_mt_[__MT_i_]
             ^ ((__MT_mt_[__MT_i_ - 1] ^ (__MT_mt_[__MT_i_ - 1] >> 62))
                * UINT64_C (2862933555777941757)))
            - __MT_i_;
      ++__MT_i_;
      if (__MT_i_ >= __MT_NN_)
        {
          __MT_mt_[0] = __MT_mt_[__MT_NN_ - 1];
          __MT_i_ = 1;
        }
    }
  __MT_mt_[0] = UINT64_C (1) << 63;
}

static inline u64
__MT_genrand64_int64_ ()
{
  int __MT_i_;
  u64 __MT_x_;
#ifdef _REENTRANT
  static __thread u64 __MT_mag01_[2] = { UINT64_C (0), __MT_MATRIX_A_ };
#else
  static u64 __MT_mag01_[2] = { UINT64_C (0), __MT_MATRIX_A_ };
#endif
  if (__MT_mti_ >= __MT_NN_)
    {
      if (__MT_mti_ == __MT_NN_ + 1)
        __MT_init_genrand64_ (trng$ ());
      for (__MT_i_ = 0; __MT_i_ < __MT_NN_ - __MT_MM_; ++__MT_i_)
        {
          __MT_x_ = (__MT_mt_[__MT_i_] & __MT_UM_)
                    | (__MT_mt_[__MT_i_ + 1] & __MT_LM_);
          __MT_mt_[__MT_i_] = __MT_mt_[__MT_i_ + __MT_MM_] ^ (__MT_x_ >> 1)
                              ^ __MT_mag01_[(int)(__MT_x_ & UINT64_C (1))];
        }
      for (; __MT_i_ < __MT_NN_ - 1; ++__MT_i_)
        {
          __MT_x_ = (__MT_mt_[__MT_i_] & __MT_UM_)
                    | (__MT_mt_[__MT_i_ + 1] & __MT_LM_);
          __MT_mt_[__MT_i_] = __MT_mt_[__MT_i_ + (__MT_MM_ - __MT_NN_)]
                              ^ (__MT_x_ >> 1)
                              ^ __MT_mag01_[(int)(__MT_x_ & UINT64_C (1))];
        }
      __MT_x_ = (__MT_mt_[__MT_NN_ - 1] & __MT_UM_) | (__MT_mt_[0] & __MT_LM_);
      __MT_mt_[__MT_NN_ - 1] = __MT_mt_[__MT_MM_ - 1] ^ (__MT_x_ >> 1)
                               ^ __MT_mag01_[(int)(__MT_x_ & UINT64_C (1))];
      __MT_mti_ = 0;
    }
  __MT_x_ = __MT_mt_[__MT_mti_++];
  __MT_x_ ^= (__MT_x_ >> 29) & UINT64_C (0x5555555555555555);
  __MT_x_ ^= (__MT_x_ << 17) & UINT64_C (0x71d67fffeda60000);
  __MT_x_ ^= (__MT_x_ << 37) & UINT64_C (0xfff7eee000000000);
  __MT_x_ ^= (__MT_x_ >> 43);
  return __MT_x_;
}

#endif /* MERSENNE_TWISTER_64_IMPL */

#define __P_MT_seed_2_(a_1, a_2) __MT_init_by_array64_ (a_1, a_2)
#define __P_MT_seed_1_(a_1, ...) __MT_init_genrand64_ (a_1)
#define __P_MT_seed_0_(...) __MT_init_genrand64_ (macro$ (trng))
#define __P_MT_seed_va_(a_1, a_2, argc, ...)                                  \
  cat$ (__P_MT_seed_, argc##_) (a_1, a_2)
#define __MT_seed_(...) __P_MT_seed_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)

/* mt$ (u64) generates a random number on [0, 2 ** 64)-interval */
#define __MT_u64_ __MT_genrand64_int64_ ()
/* mt$ (i64) generates a random number on [0, 2 ** 63)-interval */
#define __MT_i64_ ((i64)(__MT_genrand64_int64_ () >> 1))
/* mt$ (real) generates a random number on [0, 1]-real-interval */
#define __MT_real_                                                            \
  ((__MT_genrand64_int64_ () >> 11) * (1.0 / 9007199254740991.0))
/* mt$ (rea) generates a random number on [0, 1)-real-interval */
#define __MT_rea_                                                             \
  ((__MT_genrand64_int64_ () >> 11) * (1.0 / 9007199254740992.0))
/* mt$ (eal) generates a random number on (0, 1]-real-interval */
#define __MT_eal_                                                             \
  (1.0 - (__MT_genrand64_int64_ () >> 11) * (1.0 / 9007199254740992.0))
/* mt$ (ea) generates a random number on (0, 1)-real-interval */
#define __MT_ea_                                                              \
  (((__MT_genrand64_int64_ () >> 12) + 0.5) * (1.0 / 4503599627370496.0))

#define __P_mt19937_1_(type)                                                  \
  _Generic ((typeof (type)){ 0 },                                             \
      u64: __MT_u64_,                                                         \
      i64: __MT_i64_,                                                         \
      real: __MT_rea_,                                                        \
      default: (void)0)
#define __P_mt19937_0_(...) __P_mt19937_1_ (u64)
#define __P_mt19937_va_(a_1, argc, ...) cat$ (__P_mt19937_, argc##_) (a_1)
/* C++ style of mt19937 */
#define mt19937(...) __P_mt19937_va_ (__VA_ARGS__ __VA_OPT__ (, ) 1, 0)

/***************************** Mersenne Twister ******************************/

#define prng$(...) mt$ (__VA_ARGS__)
