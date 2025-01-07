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
#define typeof __typeof__

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

#define $reduce(f, i, j, ...)                                                 \
  __VA_OPT__ (__C1_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C1_(f, i, j, ...)                                                   \
  __VA_OPT__ (__C2_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C2_(f, i, j, ...)                                                   \
  __VA_OPT__ (__C3_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C3_(f, i, j, ...)                                                   \
  __VA_OPT__ (__C4_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C4_(f, i, j, ...)                                                   \
  __VA_OPT__ (__C5_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C5_(f, i, j, ...)                                                   \
  __VA_OPT__ (__C6_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C6_(f, i, j, ...)                                                   \
  __VA_OPT__ (__C7_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C7_(f, i, j, ...)                                                   \
  __VA_OPT__ (__C8_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C8_(f, i, j, ...)                                                   \
  __VA_OPT__ (__C9_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C9_(f, i, j, ...)                                                   \
  __VA_OPT__ (__C10_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C10_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C11_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C11_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C12_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C12_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C13_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C13_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C14_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C14_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C15_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C15_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C16_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C16_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C17_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C17_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C18_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C18_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C19_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C19_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C20_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C20_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C21_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C21_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C22_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C22_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C23_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C23_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C24_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C24_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C25_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C25_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C26_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C26_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C27_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C27_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C28_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C28_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C29_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C29_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C30_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C30_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C31_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C31_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C32_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C32_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C33_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C33_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C34_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C34_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C35_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C35_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C36_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C36_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C37_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C37_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C38_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C38_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C39_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C39_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C40_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C40_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C41_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C41_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C42_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C42_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C43_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C43_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C44_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C44_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C45_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C45_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C46_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C46_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C47_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C47_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C48_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C48_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C49_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C49_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C50_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C50_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C51_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C51_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C52_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C52_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C53_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C53_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C54_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C54_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C55_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C55_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C56_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C56_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C57_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C57_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C58_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C58_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C59_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C59_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C60_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C60_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C61_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C61_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C62_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C62_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C63_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C63_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C64_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C64_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C65_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C65_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C66_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C66_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C67_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C67_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C68_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C68_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C69_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C69_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C70_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C70_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C71_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C71_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C72_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C72_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C73_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C73_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C74_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C74_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C75_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C75_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C76_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C76_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C77_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C77_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C78_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C78_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C79_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C79_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C80_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C80_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C81_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C81_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C82_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C82_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C83_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C83_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C84_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C84_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C85_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C85_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C86_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C86_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C87_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C87_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C88_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C88_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C89_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C89_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C90_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C90_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C91_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C91_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C92_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C92_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C93_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C93_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C94_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C94_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C95_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C95_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C96_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C96_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C97_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C97_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C98_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C98_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C99_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C99_(f, i, j, ...)                                                  \
  __VA_OPT__ (__C100_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C100_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C101_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C101_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C102_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C102_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C103_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C103_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C104_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C104_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C105_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C105_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C106_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C106_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C107_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C107_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C108_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C108_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C109_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C109_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C110_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C110_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C111_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C111_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C112_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C112_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C113_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C113_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C114_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C114_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C115_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C115_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C116_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C116_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C117_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C117_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C118_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C118_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C119_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C119_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C120_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C120_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C121_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C121_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C122_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C122_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C123_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C123_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C124_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C124_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C125_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C125_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C126_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C126_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C127_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C127_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C128_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C128_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C129_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C129_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C130_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C130_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C131_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C131_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C132_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C132_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C133_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C133_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C134_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C134_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C135_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C135_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C136_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C136_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C137_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C137_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C138_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C138_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C139_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C139_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C140_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C140_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C141_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C141_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C142_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C142_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C143_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C143_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C144_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C144_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C145_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C145_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C146_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C146_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C147_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C147_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C148_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C148_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C149_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C149_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C150_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C150_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C151_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C151_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C152_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C152_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C153_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C153_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C154_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C154_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C155_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C155_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C156_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C156_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C157_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C157_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C158_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C158_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C159_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C159_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C160_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C160_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C161_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C161_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C162_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C162_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C163_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C163_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C164_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C164_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C165_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C165_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C166_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C166_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C167_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C167_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C168_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C168_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C169_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C169_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C170_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C170_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C171_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C171_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C172_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C172_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C173_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C173_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C174_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C174_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C175_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C175_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C176_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C176_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C177_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C177_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C178_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C178_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C179_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C179_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C180_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C180_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C181_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C181_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C182_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C182_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C183_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C183_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C184_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C184_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C185_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C185_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C186_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C186_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C187_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C187_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C188_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C188_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C189_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C189_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C190_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C190_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C191_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C191_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C192_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C192_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C193_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C193_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C194_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C194_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C195_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C195_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C196_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C196_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C197_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C197_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C198_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C198_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C199_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C199_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C200_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C200_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C201_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C201_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C202_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C202_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C203_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C203_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C204_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C204_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C205_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C205_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C206_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C206_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C207_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C207_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C208_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C208_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C209_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C209_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C210_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C210_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C211_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C211_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C212_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C212_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C213_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C213_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C214_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C214_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C215_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C215_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C216_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C216_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C217_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C217_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C218_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C218_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C219_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C219_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C220_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C220_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C221_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C221_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C222_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C222_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C223_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C223_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C224_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C224_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C225_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C225_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C226_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C226_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C227_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C227_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C228_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C228_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C229_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C229_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C230_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C230_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C231_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C231_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C232_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C232_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C233_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C233_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C234_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C234_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C235_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C235_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C236_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C236_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C237_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C237_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C238_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C238_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C239_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C239_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C240_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C240_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C241_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C241_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C242_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C242_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C243_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C243_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C244_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C244_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C245_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C245_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C246_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C246_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C247_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C247_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C248_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C248_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C249_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C249_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C250_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C250_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C251_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C251_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C252_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C252_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C253_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C253_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C254_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C254_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C255_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C255_(f, i, j, ...)                                                 \
  __VA_OPT__ (__C256_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define __C256_(f, i, j, ...)                                                 \
  __VA_OPT__ (f) (f (i, j) __VA_OPT__ (, ) __VA_ARGS__)

#define __P_quote_helper_(content) #content
#define quote$(content) __P_quote_helper_ (content)

#define __P_cat_helper_(c, d) c##d
#define cat$(c, d) __P_cat_helper_ (c, d)

#define uniq$(content) cat$ (cat$ (__U_, __COUNTER__), _##content##_)

#define empty$(...) (sizeof (quote$ (__VA_ARGS__)) == sizeof (""))

#ifndef offsetof
#define offsetof(type, mbr) ((uptr)(&(((type *)0)->mbr)))
#endif
#define container_of(ptr, type, mbr)                                          \
  ((type *)(((byte *)(ptr)) - offsetof (type, mbr)))

#define packetof(data, container)                                             \
  ((container *)((byte *)(data) - sizeof (container)))
#define dataof(packet) ((void *)((byte *)(packet) + sizeof (*(packet))))

#define typewarn$(x, y) (!!(sizeof ((typeof (x) *)1 == (typeof (y) *)1)))

#define umax$(i, j)                                                           \
  ({                                                                          \
    (void)typewarn$ (i, j);                                                   \
    sizeof (union {                                                           \
      byte uniq$ (u)[i];                                                      \
      byte uniq$ (v)[j];                                                      \
    });                                                                       \
  })
#define umin$(i, j) (umax$ (i, j) ^ (i) ^ (j))

#define ice$(expr)                                                            \
  (sizeof (uptr) == sizeof (*(1 ? (void *)(((uptr)(expr)) * 0) : (uptr *)1)))

#ifdef __GNUC__
#define choose$(cond, expr_1, expr_2)                                         \
  __builtin_choose_expr (cond, expr_1, expr_2)
#else
#define choose$(cond, expr_1, expr_2)                                         \
  _Generic (1 ? (void *)((uptr)(!(uptr)(cond))) : (uptr *)1,                  \
      uptr *: (expr_1),                                                       \
      default: (expr_2))
#endif

/* override expression */
#define ovre$(default, ...)                                                   \
  choose$ (0 __VA_OPT__ (|| 1), ((void)0 __VA_OPT__ (, ) __VA_ARGS__), default)
/* override type */
#define ovrt$(default, ...)                                                   \
  typeof (choose$ (0 __VA_OPT__ (|| 1),                                       \
                   __VA_OPT__ ((typeof (__VA_ARGS__)){) 0 __VA_OPT__ (}),     \
                   (typeof (default)){ 0 }))

#define likely(cond) __builtin_expect (!!(cond), 1)
#define unlikely(cond) __builtin_expect (!!(cond), 0)

#ifdef __GNUC__
#define typematch$(type_1, type_2, expr_1, expr_2)                            \
  choose$ (__builtin_types_compatible_p (typeof (type_1), typeof (type_2)),   \
           expr_1, expr_2)
#define lengthof(array)                                                       \
  typematch$ (array, &(array)[0], ((void)0),                                  \
              (sizeof (array) / sizeof ((array)[0])))
#else
#define typematch$(type_1, type_2, expr_1, expr_2)                            \
  _Generic ((typeof (type_1)){ 0 },                                           \
      typeof (type_2): (expr_1),                                              \
      default: (expr_2))
#define lengthof(array) (sizeof (array) / sizeof ((array)[0]))
#endif

#define dense$ __attribute__ ((__packed__))
#define inline$ inline __attribute__ ((__always_inline__))
#define pure$ __attribute__ ((__const__))
#define defer$(fn) __attribute__ ((__cleanup__ (fn)))

#define __P_add_(i, j) ((i) + (j))
#define __P_mul_(i, j) ((i) * (j))
#define __P_xor_(i, j) ((i) ^ (j))
#define __P_or_(i, j) ((i) | (j))
#define __P_and_(i, j) ((i) & (j))

#define sum$(x, ...)                                                          \
  ovre$ (x __VA_OPT__ (, $reduce (__P_add_, x, __VA_ARGS__)))
#define prod$(x, ...)                                                         \
  ovre$ (x __VA_OPT__ (, $reduce (__P_mul_, x, __VA_ARGS__)))

#define __P_reduce_helper_(r, a, i, reducer, first, ...)                      \
  ({                                                                          \
    auto r = first;                                                           \
    typeof (r) a[] = { __VA_ARGS__ };                                         \
    for (usz i = 0; i < lengthof (a); ++i)                                    \
      {                                                                       \
        reducer (r, a[i]);                                                    \
      }                                                                       \
    r;                                                                        \
  })
#define reduce$(reducer, first, ...)                                          \
  __P_reduce_helper_ (uniq$ (r), uniq$ (a), uniq$ (i), reducer,               \
                      first __VA_OPT__ (, ) __VA_ARGS__)

#define __P_reducer_add_(i, j) ((i) += (j))
#define __P_reducer_mul_(i, j) ((i) *= (j))
#define __P_reducer_xor_(i, j) ((i) ^= (j))
#define __P_reducer_or_(i, j) ((i) |= (j))
#define __P_reducer_and_(i, j) ((i) &= (j))

#define __P_reducer_max_(i, j)                                                \
  do                                                                          \
    {                                                                         \
      if ((i) < (j))                                                          \
        (i) = (j);                                                            \
    }                                                                         \
  while (0)
#define max(x_1, x_2, ...)                                                    \
  choose$ (__VA_OPT__ (1 ||) !ice$ (x_1) || !ice$ (x_2),                      \
           reduce$ (__P_reducer_max_, x_1, x_2 __VA_OPT__ (, ) __VA_ARGS__),  \
           ((x_1) > (x_2) ? (x_1) : (x_2)))

#define __P_reducer_min_(i, j)                                                \
  do                                                                          \
    {                                                                         \
      if ((i) > (j))                                                          \
        (i) = (j);                                                            \
    }                                                                         \
  while (0)
#define min(x_1, x_2, ...)                                                    \
  choose$ (__VA_OPT__ (1 ||) !ice$ (x_1) || !ice$ (x_2),                      \
           reduce$ (__P_reducer_min_, x_1, x_2 __VA_OPT__ (, ) __VA_ARGS__),  \
           ((x_1) < (x_2) ? (x_1) : (x_2)))

#define __P_swap_helper_(t, i, j)                                             \
  ({                                                                          \
    (void)typewarn$ (i, j);                                                   \
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

#ifndef smartimpl$
#define smartimpl$(...)                                                       \
  __VA_ARGS__ void static$ (free) (void *pinstance)                           \
  {                                                                           \
    __P_smart_delete_ (*(void **)pinstance);                                  \
  }                                                                           \
  __VA_ARGS__ void *static$ (uninit) (void *instance)                         \
  {                                                                           \
    return __P_smart_uninit_ (instance, __P_get_callback_);                   \
  }                                                                           \
  __VA_ARGS__ void static$ (delete) (void *pinstance)                         \
  {                                                                           \
    __P_smart_delete_ (*(void **)pinstance, static$ (uninit));                \
  }                                                                           \
  __VA_ARGS__ void static$ (fclose) (void *pstream)                           \
  {                                                                           \
    if (*(void **)pstream == null)                                            \
      return;                                                                 \
    fclose (*(void **)pstream);                                               \
  }
smartimpl$ (static inline);
#endif
#define smartptr defer$ (static$ (free))
#define auto$ defer$ (static$ (uninit))
#define smart$ defer$ (static$ (delete))
#define smartfile defer$ (static$ (fclose))

#define uninit$(instance) static$ (uninit) (instance)
#define delete$(instance) __P_smart_delete_ (instance, static$ (uninit))

/******************************* smart pointer *******************************/

#define malloc$(...) malloc (sum$ (__VA_ARGS__))
#define calloc$(...) calloc (1, sum$ (__VA_ARGS__))
#define realloc$(ptr, ...) realloc (ptr, sum$ (__VA_ARGS__))
#define alloca$(...) alloca (sum$ (__VA_ARGS__))

/******************************* pseudo class ********************************/

#define fn$(fn) __D_##fn##_
#define $fn(class, fn) static$ (class##_##fn)
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

#define bind$(class, fn, ptr) ((ptr)->fn$ (fn) = (void *)$fn (class, fn))

#define __P_call_helper_(p, ptr, fn, ...)                                     \
  ({                                                                          \
    auto p = ptr;                                                             \
    p->fn$ (fn) (p __VA_OPT__ (, ) __VA_ARGS__);                              \
  })
#define call$(ptr, fn, ...)                                                   \
  __P_call_helper_ (uniq$ (p), ptr, fn __VA_OPT__ (, ) __VA_ARGS__)
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

#define let$(var, class, ...)                                                 \
  smart$ struct class *var = (void *)new$ (class __VA_OPT__ (, ) __VA_ARGS__)

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

#define __P_async_helper_(ctx, structure, ...)                                \
  async$ (({                                                                  \
    static __VA_ARGS__ co$ (, structure) ctx;                                 \
    &ctx;                                                                     \
  }))
/* type fn (...) $async ({...}[, keyword]) { ...; exit$ (ret); } */
#define $async(structure, ...)                                                \
  __P_async_helper_ (uniq$ (ctx), structure __VA_OPT__ (, ) __VA_ARGS__)

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

#define __P_lcm_helper_(i, j, r, x, y)                                        \
  ({                                                                          \
    auto i = x;                                                               \
    auto j = y;                                                               \
    auto r = __P_gcd_ (i, j);                                                 \
    r ? (i / r) * j : 0;                                                      \
  })
#define __P_lcm_(x, y) __P_lcm_helper_ (uniq$ (i), uniq$ (j), uniq$ (r), x, y)

#define __P_reducer_gcd_(x, y) ((x) = __P_gcd_ (x, y))
/* single line trick: while ((x) && (x %= y ^= x ^= y ^= x)); */
#define gcd(x_1, x_2, ...)                                                    \
  reduce$ (__P_reducer_gcd_, x_1, x_2 __VA_OPT__ (, ) __VA_ARGS__)

#define __P_reducer_lcm_(x, y) ((x) = __P_lcm_ (x, y))
#define lcm(x_1, x_2, ...)                                                    \
  reduce$ (__P_reducer_lcm_, x_1, x_2 __VA_OPT__ (, ) __VA_ARGS__)

#define __P_lowbit_helper_(t, x)                                              \
  ({                                                                          \
    auto t = x;                                                               \
    t & -t;                                                                   \
  })
#define __P_lowbit_(x) __P_lowbit_helper_ (uniq$ (t), x)
#define lowbit(x) choose$ (ice$ (x), ((x) & -(x)), __P_lowbit_ (x))

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
  __P_dynarr_helper_ (                                                        \
      uniq$ (uc), uniq$ (us), uniq$ (r), capacity, size,                      \
      umax$ (sizeof (int), (usz)0 __VA_OPT__ (| (__VA_ARGS__))))

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

#if (__P_UNLOCKED_STDIO_ + 0) > 0 || !defined getchar && !defined getc
#define __P_getchar_1_(stream) __P_getc_worker_ (stream)
#define __P_getchar_0_(...) __P_getchar_worker_ ()
#define __P_getchar_va_(a_1, argc, ...) cat$ (__P_getchar_, argc##_) (a_1)
#undef getchar
#define getchar(...) __P_getchar_va_ (__VA_ARGS__ __VA_OPT__ (, ) 1, 0)
#undef getc
#define getc(...) getchar (__VA_ARGS__)
#endif

#if (__P_UNLOCKED_STDIO_ + 0) > 0 || !defined putchar && !defined putc
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
#define gets(...)                                                             \
  choose$ (0 __VA_OPT__ (|| 1),                                               \
           ((void)0 __VA_OPT__ (, __P_gets_g_ (__VA_ARGS__))), getvs ())
#else
#define gets(...)                                                             \
  choose$ (0 __VA_OPT__ (|| 1),                                               \
           ((void)0 __VA_OPT__ (, __P_gets_va_ (__VA_ARGS__, 3, 2, 1))),      \
           getvs ())
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

#define epoll(...) epoll_create1 (0 __VA_OPT__ (| (__VA_ARGS__)))

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

/***************************** Mersenne Twister ******************************/

#define __P_MT_NN_ 312
#define __P_MT_MM_ 156
#define __P_MT_MATRIX_A_ UINT64_C (0xb5026f5aa96619e9)
#define __P_MT_UM_ UINT64_C (0xffffffff80000000)
#define __P_MT_LM_ UINT64_C (0x7fffffff)
#define mt$(name) __MT_##name##_

#define __MT_impl_(...)                                                       \
  __VA_ARGS__ u64 static$ (mt)[__P_MT_NN_];                                   \
  __VA_ARGS__ int static$ (mti) = __P_MT_NN_ + 1;                             \
  __VA_ARGS__ void mt$ (seed) (u64 seed)                                      \
  {                                                                           \
    static$ (mt)[0] = seed;                                                   \
    for (static$ (mti) = 1; static$ (mti) < __P_MT_NN_; ++static$ (mti))      \
      static$ (mt)[static$ (mti)]                                             \
          = (UINT64_C (6364136223846793005)                                   \
                 * (static$ (mt)[static$ (mti) - 1]                           \
                    ^ (static$ (mt)[static$ (mti) - 1] >> 62))                \
             + static$ (mti));                                                \
  }                                                                           \
  __VA_ARGS__ u64 static$ (mt64) (void)                                       \
  {                                                                           \
    u64 x;                                                                    \
    if (static$ (mti) >= __P_MT_NN_)                                          \
      {                                                                       \
        if (static$ (mti) == __P_MT_NN_ + 1)                                  \
          {                                                                   \
            struct timespec tp;                                               \
            if (clock_gettime (CLOCK_MONOTONIC, &tp) == 0)                    \
              mt$ (seed) (~(u64)tp.tv_sec ^ ~(u64)tp.tv_nsec                  \
                          ^ (u64)tp.tv_nsec << 32);                           \
            else                                                              \
              mt$ (seed) (UINT64_C (5489));                                   \
          }                                                                   \
        int i;                                                                \
        static u64 mag01[2] = { UINT64_C (0), __P_MT_MATRIX_A_ };             \
        for (i = 0; i < __P_MT_NN_ - __P_MT_MM_; ++i)                         \
          {                                                                   \
            x = (static$ (mt)[i] & __P_MT_UM_)                                \
                | (static$ (mt)[i + 1] & __P_MT_LM_);                         \
            static$ (mt)[i] = static$ (mt)[i + __P_MT_MM_] ^ (x >> 1)         \
                              ^ mag01[(int)(x & UINT64_C (1))];               \
          }                                                                   \
        for (; i < __P_MT_NN_ - 1; ++i)                                       \
          {                                                                   \
            x = (static$ (mt)[i] & __P_MT_UM_)                                \
                | (static$ (mt)[i + 1] & __P_MT_LM_);                         \
            static$ (mt)[i] = static$ (mt)[i + (__P_MT_MM_ - __P_MT_NN_)]     \
                              ^ (x >> 1) ^ mag01[(int)(x & UINT64_C (1))];    \
          }                                                                   \
        x = (static$ (mt)[__P_MT_NN_ - 1] & __P_MT_UM_)                       \
            | (static$ (mt)[0] & __P_MT_LM_);                                 \
        static$ (mt)[__P_MT_NN_ - 1] = static$ (mt)[__P_MT_MM_ - 1]           \
                                       ^ (x >> 1)                             \
                                       ^ mag01[(int)(x & UINT64_C (1))];      \
        static$ (mti) = 0;                                                    \
      }                                                                       \
    x = static$ (mt)[static$ (mti)++];                                        \
    x ^= (x >> 29) & UINT64_C (0x5555555555555555);                           \
    x ^= (x << 17) & UINT64_C (0x71d67fffeda60000);                           \
    x ^= (x << 37) & UINT64_C (0xfff7eee000000000);                           \
    x ^= (x >> 43);                                                           \
    return x;                                                                 \
  }
#define mtimpl$(...) mt$ (impl) (__VA_ARGS__)
/* mt$ (u64) generates a random number on [0, 2 ** 64)-interval */
#define __MT_u64_ (static$ (mt64) ())
/* mt$ (i64) generates a random number on [0, 2 ** 63)-interval */
#define __MT_i64_ ((i64)(static$ (mt64) () >> 1))
/* mt$ (real) generates a random number on [0, 1]-real-interval */
#define __MT_real_ ((static$ (mt64) () >> 11) * (1.0 / 9007199254740991.0))
/* mt$ (rea) generates a random number on [0, 1)-real-interval */
#define __MT_rea_ ((static$ (mt64) () >> 11) * (1.0 / 9007199254740992.0))
/* mt$ (eal) generates a random number on (0, 1]-real-interval */
#define __MT_eal_ (1.0 - mt$ (rea) ())
/* mt$ (ea) generates a random number on (0, 1)-real-interval */
#define __MT_ea_                                                              \
  (((static$ (mt64) () >> 12) + 0.5) * (1.0 / 4503599627370496.0))

#define __P_mt19937_1_(type)                                                  \
  _Generic ((typeof (type)){ 0 },                                             \
      u64: mt$ (u64),                                                         \
      i64: mt$ (i64),                                                         \
      real: mt$ (rea),                                                        \
      default: ((void)0))
#define __P_mt19937_0_(...) __P_mt19937_1_ (u64)
#define __P_mt19937_va_(a_1, argc, ...) cat$ (__P_mt19937_, argc##_) (a_1)
/* C++ style of mt19937 */
#define mt19937(...) __P_mt19937_va_ (__VA_ARGS__ __VA_OPT__ (, ) 1, 0)

/***************************** Mersenne Twister ******************************/
