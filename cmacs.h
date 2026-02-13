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

#if (__STDC_HOSTED__ + 0) != 0
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
#endif /* __STDC_HOSTED__ */

#define asm __asm__
#ifdef __cplusplus
#define null nullptr
#define restrict __restrict__
#else
#define null NULL
#define auto __auto_type
#define generic _Generic
#define atomic _Atomic
#endif

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
#define _P_INT128_ 16
typedef __int128_t i128;
typedef __uint128_t u128;
#else
typedef intmax_t i128;
typedef uintmax_t u128;
#endif
typedef intptr_t iptr;
typedef uintptr_t uptr;
typedef ptrdiff_t isz;
typedef size_t usz;

typedef uint_least8_t c8;
typedef uint_least16_t c16;
typedef uint_least32_t c32;

typedef double real;
#ifdef __FLT16_MAX__
#define _P_FLOAT16_ 2
typedef _Float16 f16;
#else
typedef float f16;
#endif
typedef float f32;
typedef double f64;
#if (__SIZEOF_FLOAT128__ + 0) == 16
#define _P_FLOAT128_ 16
typedef __float128 f128;
#else
typedef long double f128;
#endif

typedef long long isto;
typedef unsigned long long usto;
typedef long double fsto;

#define todo$(...) static_assert (0 __VA_OPT__ (, ) __VA_ARGS__)

#define macro$(name) _P_##name##_
#define static$(name) _S_##name##_
#define const$(name) _C_##name##_

#define _C_p2_ UINT64_C (3)
#define _C_p3_ UINT64_C (7)
#define _C_p4_ UINT64_C (13)
#define _C_p5_ UINT64_C (31)
#define _C_p6_ UINT64_C (61)
#define _C_p7_ UINT64_C (127)
#define _C_p8_ UINT64_C (251)
#define _C_p9_ UINT64_C (509)
#define _C_p10_ UINT64_C (1021)
#define _C_p11_ UINT64_C (2039)
#define _C_p12_ UINT64_C (4093)
#define _C_p13_ UINT64_C (8191)
#define _C_p14_ UINT64_C (16381)
#define _C_p15_ UINT64_C (32749)
#define _C_p16_ UINT64_C (65521)
#define _C_p17_ UINT64_C (131071)
#define _C_p18_ UINT64_C (262139)
#define _C_p19_ UINT64_C (524287)
#define _C_p20_ UINT64_C (1048573)
#define _C_p21_ UINT64_C (2097143)
#define _C_p22_ UINT64_C (4194301)
#define _C_p23_ UINT64_C (8388593)
#define _C_p24_ UINT64_C (16777213)
#define _C_p25_ UINT64_C (33554393)
#define _C_p26_ UINT64_C (67108859)
#define _C_p27_ UINT64_C (134217689)
#define _C_p28_ UINT64_C (268435399)
#define _C_p29_ UINT64_C (536870909)
#define _C_p30_ UINT64_C (1073741789)
#define _C_p31_ UINT64_C (2147483647)
#define _C_p32_ UINT64_C (4294967291)
#define _C_p33_ UINT64_C (8589934583)
#define _C_p34_ UINT64_C (17179869143)
#define _C_p35_ UINT64_C (34359738337)
#define _C_p36_ UINT64_C (68719476731)
#define _C_p37_ UINT64_C (137438953447)
#define _C_p38_ UINT64_C (274877906899)
#define _C_p39_ UINT64_C (549755813881)
#define _C_p40_ UINT64_C (1099511627689)
#define _C_p41_ UINT64_C (2199023255531)
#define _C_p42_ UINT64_C (4398046511093)
#define _C_p43_ UINT64_C (8796093022151)
#define _C_p44_ UINT64_C (17592186044399)
#define _C_p45_ UINT64_C (35184372088777)
#define _C_p46_ UINT64_C (70368744177643)
#define _C_p47_ UINT64_C (140737488355213)
#define _C_p48_ UINT64_C (281474976710597)
#define _C_p49_ UINT64_C (562949953421231)
#define _C_p50_ UINT64_C (1125899906842597)
#define _C_p51_ UINT64_C (2251799813685119)
#define _C_p52_ UINT64_C (4503599627370449)
#define _C_p53_ UINT64_C (9007199254740881)
#define _C_p54_ UINT64_C (18014398509481951)
#define _C_p55_ UINT64_C (36028797018963913)
#define _C_p56_ UINT64_C (72057594037927931)
#define _C_p57_ UINT64_C (144115188075855859)
#define _C_p58_ UINT64_C (288230376151711717)
#define _C_p59_ UINT64_C (576460752303423433)
#define _C_p60_ UINT64_C (1152921504606846883)
#define _C_p61_ UINT64_C (2305843009213693951)
#define _C_p62_ UINT64_C (4611686018427387847)
#define _C_p63_ UINT64_C (9223372036854775783)
#define _C_p64_ UINT64_C (18446744073709551557)

#define _C_tp3_ UINT64_C (5)
#define _C_tp4_ UINT64_C (11)
#define _C_tp5_ UINT64_C (29)
#define _C_tp6_ UINT64_C (59)
#define _C_tp7_ UINT64_C (107)
#define _C_tp8_ UINT64_C (239)
#define _C_tp9_ UINT64_C (461)
#define _C_tp10_ UINT64_C (1019)
#define _C_tp11_ UINT64_C (2027)
#define _C_tp12_ UINT64_C (4091)
#define _C_tp13_ UINT64_C (8087)
#define _C_tp14_ UINT64_C (16361)
#define _C_tp15_ UINT64_C (32717)
#define _C_tp16_ UINT64_C (65519)
#define _C_tp17_ UINT64_C (131009)
#define _C_tp18_ UINT64_C (262109)
#define _C_tp19_ UINT64_C (524219)
#define _C_tp20_ UINT64_C (1048571)
#define _C_tp21_ UINT64_C (2097131)
#define _C_tp22_ UINT64_C (4193801)
#define _C_tp23_ UINT64_C (8388449)
#define _C_tp24_ UINT64_C (16777139)
#define _C_tp25_ UINT64_C (33554009)
#define _C_tp26_ UINT64_C (67108667)
#define _C_tp27_ UINT64_C (134217437)
#define _C_tp28_ UINT64_C (268435007)
#define _C_tp29_ UINT64_C (536870837)
#define _C_tp30_ UINT64_C (1073741717)
#define _C_tp31_ UINT64_C (2147482949)
#define _C_tp32_ UINT64_C (4294965839)
#define _C_tp33_ UINT64_C (8589934289)
#define _C_tp34_ UINT64_C (17179868807)
#define _C_tp35_ UINT64_C (34359737297)
#define _C_tp36_ UINT64_C (68719476389)
#define _C_tp37_ UINT64_C (137438953271)
#define _C_tp38_ UINT64_C (274877906627)
#define _C_tp39_ UINT64_C (549755813357)
#define _C_tp40_ UINT64_C (1099511626397)
#define _C_tp41_ UINT64_C (2199023255477)
#define _C_tp42_ UINT64_C (4398046509737)
#define _C_tp43_ UINT64_C (8796093021407)
#define _C_tp44_ UINT64_C (17592186044297)
#define _C_tp45_ UINT64_C (35184372088319)
#define _C_tp46_ UINT64_C (70368744176777)
#define _C_tp47_ UINT64_C (140737488353699)
#define _C_tp48_ UINT64_C (281474976710129)
#define _C_tp49_ UINT64_C (562949953419317)
#define _C_tp50_ UINT64_C (1125899906841971)
#define _C_tp51_ UINT64_C (2251799813684459)
#define _C_tp52_ UINT64_C (4503599627369861)
#define _C_tp53_ UINT64_C (9007199254738541)
#define _C_tp54_ UINT64_C (18014398509481727)
#define _C_tp55_ UINT64_C (36028797018963797)
#define _C_tp56_ UINT64_C (72057594037925807)
#define _C_tp57_ UINT64_C (144115188075854267)
#define _C_tp58_ UINT64_C (288230376151709777)
#define _C_tp59_ UINT64_C (576460752303422429)
#define _C_tp60_ UINT64_C (1152921504606845471)
#define _C_tp61_ UINT64_C (2305843009213692029)
#define _C_tp62_ UINT64_C (4611686018427386201)
#define _C_tp63_ UINT64_C (9223372036854774509)
#define _C_tp64_ UINT64_C (18446744073709550771)

#define _P_quote_(...) #__VA_ARGS__
#define quote$(...) _P_quote_ (__VA_ARGS__)

#define _P_cat_(c, d) c##d
#define cat$(c, d) _P_cat_ (c, d)

#define uniq$(c) cat$ (cat$ (_U_, __COUNTER__), _##c##_)

#define lp$ (
#define rp$ )

#define paren$(...) (__VA_ARGS__)

#define _NO__P_recur_
#define _P_recur_(...) _P_recur_ __VA_ARGS__
#define _P_unparen_helper_(...) _NO_##__VA_ARGS__
#define _P_unparen_(...) _P_unparen_helper_ (__VA_ARGS__)
#define unparen$(c) _P_unparen_ (_P_recur_ c)

/* scan 1024 times */
#define scan$(...)                                                            \
  _P_scan_r_1_ (_P_scan_r_1_ (_P_scan_r_1_ (_P_scan_r_1_ (__VA_ARGS__))))
#define _P_scan_r_1_(...)                                                     \
  _P_scan_r_2_ (_P_scan_r_2_ (_P_scan_r_2_ (_P_scan_r_2_ (__VA_ARGS__))))
#define _P_scan_r_2_(...)                                                     \
  _P_scan_r_3_ (_P_scan_r_3_ (_P_scan_r_3_ (_P_scan_r_3_ (__VA_ARGS__))))
#define _P_scan_r_3_(...)                                                     \
  _P_scan_r_4_ (_P_scan_r_4_ (_P_scan_r_4_ (_P_scan_r_4_ (__VA_ARGS__))))
#define _P_scan_r_4_(...)                                                     \
  _P_scan_r_5_ (_P_scan_r_5_ (_P_scan_r_5_ (_P_scan_r_5_ (__VA_ARGS__))))
#define _P_scan_r_5_(...) __VA_ARGS__

#if (RECURSIVE_REDUCE_MACRO + 0) == 0
#define _R1_(f, i, j, ...)                                                    \
  __VA_OPT__ (_R2_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R2_(f, i, j, ...)                                                    \
  __VA_OPT__ (_R3_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R3_(f, i, j, ...)                                                    \
  __VA_OPT__ (_R4_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R4_(f, i, j, ...)                                                    \
  __VA_OPT__ (_R5_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R5_(f, i, j, ...)                                                    \
  __VA_OPT__ (_R6_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R6_(f, i, j, ...)                                                    \
  __VA_OPT__ (_R7_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R7_(f, i, j, ...)                                                    \
  __VA_OPT__ (_R8_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R8_(f, i, j, ...)                                                    \
  __VA_OPT__ (_R9_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R9_(f, i, j, ...)                                                    \
  __VA_OPT__ (_R10_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R10_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R11_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R11_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R12_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R12_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R13_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R13_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R14_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R14_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R15_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R15_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R16_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R16_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R17_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R17_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R18_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R18_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R19_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R19_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R20_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R20_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R21_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R21_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R22_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R22_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R23_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R23_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R24_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R24_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R25_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R25_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R26_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R26_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R27_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R27_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R28_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R28_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R29_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R29_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R30_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R30_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R31_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R31_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R32_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R32_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R33_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R33_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R34_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R34_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R35_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R35_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R36_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R36_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R37_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R37_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R38_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R38_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R39_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R39_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R40_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R40_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R41_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R41_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R42_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R42_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R43_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R43_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R44_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R44_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R45_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R45_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R46_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R46_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R47_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R47_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R48_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R48_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R49_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R49_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R50_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R50_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R51_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R51_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R52_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R52_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R53_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R53_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R54_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R54_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R55_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R55_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R56_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R56_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R57_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R57_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R58_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R58_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R59_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R59_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R60_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R60_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R61_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R61_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R62_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R62_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R63_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R63_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R64_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R64_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R65_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R65_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R66_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R66_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R67_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R67_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R68_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R68_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R69_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R69_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R70_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R70_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R71_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R71_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R72_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R72_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R73_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R73_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R74_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R74_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R75_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R75_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R76_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R76_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R77_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R77_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R78_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R78_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R79_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R79_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R80_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R80_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R81_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R81_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R82_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R82_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R83_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R83_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R84_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R84_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R85_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R85_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R86_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R86_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R87_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R87_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R88_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R88_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R89_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R89_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R90_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R90_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R91_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R91_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R92_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R92_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R93_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R93_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R94_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R94_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R95_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R95_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R96_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R96_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R97_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R97_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R98_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R98_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R99_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R99_(f, i, j, ...)                                                   \
  __VA_OPT__ (_R100_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R100_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R101_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R101_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R102_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R102_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R103_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R103_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R104_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R104_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R105_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R105_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R106_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R106_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R107_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R107_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R108_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R108_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R109_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R109_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R110_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R110_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R111_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R111_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R112_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R112_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R113_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R113_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R114_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R114_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R115_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R115_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R116_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R116_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R117_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R117_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R118_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R118_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R119_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R119_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R120_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R120_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R121_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R121_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R122_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R122_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R123_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R123_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R124_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R124_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R125_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R125_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R126_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R126_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R127_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R127_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R128_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R128_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R129_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R129_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R130_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R130_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R131_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R131_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R132_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R132_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R133_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R133_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R134_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R134_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R135_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R135_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R136_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R136_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R137_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R137_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R138_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R138_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R139_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R139_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R140_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R140_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R141_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R141_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R142_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R142_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R143_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R143_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R144_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R144_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R145_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R145_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R146_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R146_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R147_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R147_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R148_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R148_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R149_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R149_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R150_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R150_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R151_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R151_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R152_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R152_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R153_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R153_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R154_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R154_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R155_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R155_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R156_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R156_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R157_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R157_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R158_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R158_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R159_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R159_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R160_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R160_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R161_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R161_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R162_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R162_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R163_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R163_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R164_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R164_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R165_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R165_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R166_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R166_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R167_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R167_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R168_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R168_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R169_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R169_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R170_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R170_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R171_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R171_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R172_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R172_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R173_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R173_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R174_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R174_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R175_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R175_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R176_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R176_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R177_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R177_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R178_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R178_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R179_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R179_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R180_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R180_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R181_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R181_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R182_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R182_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R183_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R183_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R184_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R184_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R185_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R185_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R186_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R186_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R187_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R187_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R188_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R188_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R189_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R189_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R190_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R190_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R191_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R191_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R192_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R192_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R193_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R193_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R194_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R194_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R195_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R195_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R196_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R196_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R197_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R197_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R198_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R198_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R199_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R199_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R200_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R200_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R201_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R201_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R202_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R202_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R203_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R203_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R204_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R204_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R205_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R205_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R206_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R206_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R207_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R207_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R208_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R208_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R209_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R209_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R210_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R210_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R211_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R211_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R212_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R212_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R213_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R213_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R214_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R214_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R215_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R215_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R216_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R216_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R217_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R217_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R218_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R218_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R219_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R219_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R220_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R220_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R221_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R221_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R222_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R222_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R223_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R223_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R224_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R224_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R225_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R225_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R226_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R226_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R227_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R227_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R228_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R228_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R229_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R229_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R230_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R230_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R231_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R231_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R232_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R232_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R233_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R233_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R234_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R234_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R235_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R235_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R236_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R236_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R237_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R237_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R238_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R238_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R239_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R239_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R240_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R240_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R241_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R241_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R242_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R242_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R243_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R243_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R244_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R244_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R245_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R245_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R246_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R246_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R247_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R247_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R248_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R248_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R249_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R249_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R250_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R250_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R251_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R251_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R252_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R252_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R253_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R253_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R254_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R254_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R255_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R255_(f, i, j, ...)                                                  \
  __VA_OPT__ (_R256_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#define _R256_(f, i, j, ...)                                                  \
  __VA_OPT__ (f) (f (i, j) __VA_OPT__ (, ) __VA_ARGS__)
#undef $reduce
#define $reduce(f, i, j, ...)                                                 \
  unparen$ (__VA_OPT__ (_R1_) (__VA_OPT__ (f, ) f (i, j) __VA_OPT__ (, )      \
                                   __VA_ARGS__))
#else
#define _P_reduce_(f, i, j, ...)                                              \
  __VA_OPT__ (_Q_reduce_ lp$ f, ) f (i, j) __VA_OPT__ (, __VA_ARGS__ rp$)
#define _Q_reduce_(f, i, j, ...)                                              \
  __VA_OPT__ (_P_reduce_ lp$ f, ) f (i, j) __VA_OPT__ (, __VA_ARGS__ rp$)
#undef $reduce
#define $reduce(f, i, j, ...)                                                 \
  scan$ (_P_reduce_ (f, i, j __VA_OPT__ (, ) __VA_ARGS__))
#endif /* RECURSIVE_REDUCE_MACRO */

#define head$(c, ...) c

#define _P_tail_(c, d) d
#define tail$(c, ...) $reduce (_P_tail_, , c __VA_OPT__ (, ) __VA_ARGS__)

#define _P_typeof_helper_(i, j) 0 ? i : (__typeof__ (j)){ 0 }
#define typeof(a, ...)                                                        \
  __typeof__ (__VA_OPT__ ($reduce) (__VA_OPT__ (_P_typeof_helper_, ) (        \
      __typeof__ (a)){ 0 } __VA_OPT__ (, ) __VA_ARGS__))

#define empty$(...) head$ (__VA_OPT__ (0, ) 1)

#define _P_count_helper_(i, j) i + !empty$ (j)
#define count$(...) ($reduce (_P_count_helper_, 0, __VA_ARGS__))

#ifndef offsetof
#define offsetof(type, mbr) ((uptr)(&(((type *)0)->mbr)))
#endif
#define container_of(ptr, type, mbr)                                          \
  ((type *)(((byte *)(ptr)) - offsetof (type, mbr)))

#define packetof(data, container)                                             \
  ((container *)((byte *)(data) - sizeof (container)))
#define dataof(packet) ((void *)((byte *)(packet) + sizeof (*(packet))))

#define _P_typewarn_helper_(x, y)                                             \
  ((void)sizeof ((typeof (x) *)0 == (typeof (y) *)0), y)
#define typewarn$(a_1, a_2, ...)                                              \
  ((void)$reduce (_P_typewarn_helper_, a_1, a_2 __VA_OPT__ (, ) __VA_ARGS__))

#define ice$(expr)                                                            \
  (sizeof (int) == sizeof (*(0 ? (void *)(((long)(expr)) * 0l) : (int *)0)))

#define _P_ace_helper_(i, j) i &&ice$ (j)
#define ace$(expr, ...)                                                       \
  ($reduce (_P_ace_helper_, 1, expr __VA_OPT__ (, ) __VA_ARGS__))

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

#define _P_umax_(u, v)                                                        \
  sizeof (union {                                                             \
    byte uniq$ (a)[u];                                                        \
    byte uniq$ (a)[v];                                                        \
  })
#define _P_umin_(u, v) (_P_umax_ (u, v) ^ (u) ^ (v))

#define umax$(u, ...) $reduce (_P_umax_, u, u __VA_OPT__ (, ) __VA_ARGS__)
#define umin$(u, ...) $reduce (_P_umin_, u, u __VA_OPT__ (, ) __VA_ARGS__)

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

#define countof(array)                                                        \
  typematch$ (array, &(array)[0], (void)0,                                    \
              sizeof (array) / sizeof ((array)[0]))

#define ipe$(expr) typematch$ (expr, (expr) - (expr), 0, 1)

#define _P_ape_helper_(i, j) i &&ipe$ (j)
#define ape$(expr, ...)                                                       \
  ($reduce (_P_ape_helper_, 1, expr __VA_OPT__ (, ) __VA_ARGS__))

#define dense$ __attribute__ ((__packed__))
#define inline$ inline __attribute__ ((__always_inline__))
#define pure$ __attribute__ ((__const__))
#define defer$(fn) __attribute__ ((__cleanup__ (fn)))
#define weak$ __attribute__ ((__weak__))

#define _P_add_(i, j) i + (j)
#define _P_mul_(i, j) i *(j)
#define _P_xor_(i, j) i ^ (j)
#define _P_or_(i, j) i | (j)
#define _P_and_(i, j) i &(j)

#define sum$(x, ...)                                                          \
  (tail$ (x __VA_OPT__ (, $reduce (_P_add_, (x), __VA_ARGS__))))
#define prod$(x, ...)                                                         \
  (tail$ (x __VA_OPT__ (, $reduce (_P_mul_, (x), __VA_ARGS__))))

#define _P_reduce_helper_(r, a, i, reducer, first, ...)                       \
  ({                                                                          \
    typeof (first __VA_OPT__ (, ) __VA_ARGS__) r = first;                     \
    typeof (r) a[] = { __VA_ARGS__ };                                         \
    for (usz i = 0; i < countof (a); ++i)                                     \
      {                                                                       \
        reducer (r, a[i]);                                                    \
      }                                                                       \
    r;                                                                        \
  })
#define reduce$(reducer, a_1, a_2, ...)                                       \
  _P_reduce_helper_ (uniq$ (r), uniq$ (a), uniq$ (i), reducer, a_1,           \
                     a_2 __VA_OPT__ (, ) __VA_ARGS__)

#define _P_add_reducer_(i, j) i += j
#define _P_mul_reducer_(i, j) i *= j
#define _P_xor_reducer_(i, j) i ^= j
#define _P_or_reducer_(i, j) i |= j
#define _P_and_reducer_(i, j) i &= j

#define _P_max_(i, j) (i) > (j) ? (i) : (j)
#define _P_max_reducer_(i, j)                                                 \
  do                                                                          \
    {                                                                         \
      if (i < j)                                                              \
        i = j;                                                                \
    }                                                                         \
  while (0)
#define max(x, ...)                                                           \
  tail$ ((x)__VA_OPT__ (                                                      \
      , choose$ (ace$ (x, __VA_ARGS__), $reduce (_P_max_, x, __VA_ARGS__),    \
                 reduce$ (_P_max_reducer_, x, __VA_ARGS__))))

#define _P_min_(i, j) (i) < (j) ? (i) : (j)
#define _P_min_reducer_(i, j)                                                 \
  do                                                                          \
    {                                                                         \
      if (i > j)                                                              \
        i = j;                                                                \
    }                                                                         \
  while (0)
#define min(x, ...)                                                           \
  tail$ ((x)__VA_OPT__ (                                                      \
      , choose$ (ace$ (x, __VA_ARGS__), $reduce (_P_min_, x, __VA_ARGS__),    \
                 reduce$ (_P_min_reducer_, x, __VA_ARGS__))))

#define _P_swap_helper_(t, i, j)                                              \
  ({                                                                          \
    auto t = i;                                                               \
    (i) = j;                                                                  \
    (j) = t;                                                                  \
    t;                                                                        \
  })
#define swap(i, j) _P_swap_helper_ (uniq$ (t), i, j)

#define _P_lambda_helper_(fn, type, function) ({ type fn function fn; })
#define lambda(type, function) _P_lambda_helper_ (uniq$ (fn), type, function)

#define _P_with_helper_(u, d, ...)                                            \
  for (d, *u = (void *)&u; u; ({                                              \
         __VA_OPT__ (__VA_ARGS__;)                                            \
         u = null;                                                            \
       }))
#define with$(decl, ...)                                                      \
  _P_with_helper_ (uniq$ (u), decl __VA_OPT__ (, ) __VA_ARGS__)

/******************************* smart pointer *******************************/

#define _P_move_helper_(ret, ptr)                                             \
  ({                                                                          \
    auto ret = ptr;                                                           \
    (ptr) = choose$ (ipe$ (ret), null, -1);                                   \
    ret;                                                                      \
  })
#define move(ptr) _P_move_helper_ (uniq$ (ret), ptr)

#define _P_smart_deinit_helper_(pp, instance, pp_finder)                      \
  ({                                                                          \
    auto pp = (void *(*)(void *))pp_finder (instance);                        \
    pp ? pp (instance) : (instance);                                          \
  })
#define _P_smart_deinit_(instance, pp_finder)                                 \
  _P_smart_deinit_helper_ (uniq$ (pp), instance, pp_finder)
#define _P_get_deinit_(instance) ((instance) ? *(void **)(instance) : null)

#if (SMART_POINTER_IMPL + 0) == 0
#undef SMART_POINTER_IMPL
#define SMART_POINTER_IMPL 1

static inline void *
_S_free_ (void *pinstance)
{
  if (!pinstance || !*(void **)pinstance)
    return pinstance;
  free (*(void **)pinstance);
  return pinstance;
}

static inline void *
_S_deinit_ (void *instance)
{
  if (!instance)
    return null;
  return _P_smart_deinit_ (instance, _P_get_deinit_);
}

static inline void *
_S_delete_ (void *pinstance)
{
  if (!pinstance || !*(void **)pinstance)
    return pinstance;
  free (_S_deinit_ (*(void **)pinstance));
  return pinstance;
}

static inline void *
_S_revoke_ (void *pinterface)
{
  if (!pinterface || !*(void **)pinterface)
    return pinterface;
  free (_S_delete_ (*(void **)pinterface));
  return pinterface;
}

static inline void *
_S_fclose_ (void *pstream)
{
  if (!pstream || !*(void **)pstream)
    return pstream;
  fclose (*(void **)pstream);
  return pstream;
}

#endif /* SMART_POINTER_IMPL */

#define smartptr defer$ (static$ (free))
#define autoinst defer$ (static$ (deinit))
#define smartinst defer$ (static$ (delete))
#define autointf defer$ (static$ (delete))
#define smartintf defer$ (static$ (revoke))
#define smartfs defer$ (static$ (fclose))

#define deinit$(instance) static$ (deinit) (instance)
#define delete$(instance) free (deinit$ (instance))
#define $revoke(interface) static$ (delete) (interface)
#define revoke$(interface) free ($revoke (interface))
#define $eject(vtab)                                                          \
  packetof (static$ (deinit) (dataof (vtab)), typeof (*(vtab)))
#define eject$(vtab) free ($eject (vtab))

/******************************* smart pointer *******************************/

#define _P_fail_abort_ptrcall_(uptr, call)                                    \
  ({                                                                          \
    auto uptr = call;                                                         \
    if (unlikely (!uptr))                                                     \
      abort ();                                                               \
    uptr;                                                                     \
  })
#define malloc$(...)                                                          \
  _P_fail_abort_ptrcall_ (uniq$ (uptr), malloc (sum$ (__VA_ARGS__)))
#define calloc$(...)                                                          \
  _P_fail_abort_ptrcall_ (uniq$ (uptr), calloc (1, sum$ (__VA_ARGS__)))
#define _P_realloc_helper_(ret, up, us, ptr, ...)                             \
  ({                                                                          \
    auto up = ptr;                                                            \
    typeof (up) ret;                                                          \
    usz us = sum$ (__VA_ARGS__);                                              \
    if (us)                                                                   \
      ret = _P_fail_abort_ptrcall_ (uniq$ (uptr), realloc (up, us));          \
    else                                                                      \
      {                                                                       \
        free (up);                                                            \
        ret = null;                                                           \
      }                                                                       \
    ret;                                                                      \
  })
#define realloc$(ptr, ...)                                                    \
  _P_realloc_helper_ (uniq$ (ret), uniq$ (up), uniq$ (us),                    \
                      ptr __VA_OPT__ (, ) __VA_ARGS__)
#define alloca$(...) alloca (sum$ (__VA_ARGS__))

/******************************* pseudo class ********************************/

#define fn$(fn) _D_##fn##_
#define $fn(class, fn) static$ (class##___##fn)
#define mbr$(mbr) _M_##mbr##_

#define fx$(fn, ...) (*fn$ (fn)) (void *__VA_OPT__ (, ) __VA_ARGS__)
#define $fx(class, fn, ...)                                                   \
  $fn (class, fn) (struct class * this __VA_OPT__ (, ) __VA_ARGS__)

#define _P_call_helper_(p, offset, ptr, fp, ...)                              \
  ({                                                                          \
    auto p = ptr;                                                             \
    p->fp (offset (p) __VA_OPT__ (, ) __VA_ARGS__);                           \
  })
#define call$(instance, fp, ...)                                              \
  _P_call_helper_ (uniq$ (p), , instance, fp __VA_OPT__ (, ) __VA_ARGS__)

#define class$(name, structure)                                               \
  struct name                                                                 \
  {                                                                           \
    struct name *fx$ (deinit);                                                \
    struct structure;                                                         \
  }

#define _P_new_helper_(ret, p, class, ...)                                    \
  ({                                                                          \
    struct class *ret = null;                                                 \
    void *p                                                                   \
        = malloc (sum$ (sizeof (struct class) __VA_OPT__ (, ) __VA_ARGS__));  \
    if (likely (p))                                                           \
      {                                                                       \
        ret = $fn (class, init) (p);                                          \
        if (!ret)                                                             \
          free (p);                                                           \
      }                                                                       \
    ret;                                                                      \
  })
#define new$(class, ...)                                                      \
  _P_new_helper_ (uniq$ (ret), uniq$ (p), class __VA_OPT__ (, ) __VA_ARGS__)

#define def$(var, class, ...)                                                 \
  smartinst struct class *var = new$ (class __VA_OPT__ (, ) __VA_ARGS__)

#define trait$(name, structure)                                               \
  struct name                                                                 \
  {                                                                           \
    void *mbr$ (instance);                                                    \
    struct structure;                                                         \
  }

#define invoke$(interface, fp, ...)                                           \
  _P_call_helper_ (uniq$ (p), *(void **), interface,                          \
                   fp __VA_OPT__ (, ) __VA_ARGS__)

#define inject$(vtab, fp, ...)                                                \
  _P_call_helper_ (uniq$ (p), dataof, vtab, fp __VA_OPT__ (, ) __VA_ARGS__)

/******************************* pseudo class ********************************/

/***************************** pseudo coroutine ******************************/

#define label$ cat$ (cat$ (_L, __LINE__), _)

typedef void *coroutine;

/* mbr$ (coroutine) should be zeroed */
#define co$(name, structure)                                                  \
  struct name                                                                 \
  {                                                                           \
    coroutine mbr$ (coroutine);                                               \
    struct structure;                                                         \
  }

/* type fn ([coptr,] ...) async$ (coptr) { ...; exit$ (ret); } */
#define async$(coptr)                                                         \
  {                                                                           \
    auto this = coptr;                                                        \
    if (*(void **)this)                                                       \
      goto **(void **)this;                                                   \
    else                                                                      \
      *(void **)this = &&_LBASE_;                                             \
  _LBASE_:;

#ifdef _REENTRANT
#define _P_async_helper_(ctx, structure)                                      \
  async$ (({                                                                  \
    static __thread co$ (, structure) ctx;                                    \
    &ctx;                                                                     \
  }))
#else
#define _P_async_helper_(ctx, structure)                                      \
  async$ (({                                                                  \
    static co$ (, structure) ctx;                                             \
    &ctx;                                                                     \
  }))
#endif

/* type fn (...) $async ({...}) { ...; exit$ (ret); } */
#define $async(structure) _P_async_helper_ (uniq$ (ctx), structure)

#define yield$(...)                                                           \
  do                                                                          \
    {                                                                         \
      *(void **)this = &&label$;                                              \
      return __VA_ARGS__;                                                     \
    label$:;                                                                  \
    }                                                                         \
  while (0)

#define loop$(...)                                                            \
  do                                                                          \
    {                                                                         \
      *(void **)this = null;                                                  \
      return __VA_ARGS__;                                                     \
    }                                                                         \
  while (0)

#define _P_await_3_(call, cond, ...)                                          \
  do                                                                          \
    {                                                                         \
      call;                                                                   \
      if (!(cond))                                                            \
        break;                                                                \
      yield$ (__VA_ARGS__);                                                   \
    }                                                                         \
  while (1)
#define _P_await_2_(call, cond, ...) _P_await_3_ (call, cond, 0)
#define _P_await_1_(call, ...) _P_await_2_ (, !(call))
#define _P_await_va_(a_1, a_2, a_3, argc, ...)                                \
  cat$ (_P_await_, argc##_) (a_1, a_2, a_3)
#define await$(call, ...)                                                     \
  _P_await_va_ (call, __VA_ARGS__ __VA_OPT__ (, ) 3, 2, 1)

/* exit$ must be called directly at the end of each coroutine */
#define exit$(...)                                                            \
  *(void **)this = null;                                                      \
  }                                                                           \
  return __VA_ARGS__

/***************************** pseudo coroutine ******************************/

#ifdef __clang__
#define print_struct(ptr) __builtin_dump_struct (ptr, printf)
#endif

/*********************************** math ************************************/

/* single line trick: while ((x) && (x %= y ^= x ^= y ^= x)); */
#define _P_gcd_helper_(i, j, r, x, y)                                         \
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
#define _P_gcd_(x, y) _P_gcd_helper_ (uniq$ (i), uniq$ (j), uniq$ (r), x, y)
#define _P_gcd_reducer_(x, y) x = _P_gcd_ (x, y)
#define gcd(i, ...)                                                           \
  tail$ ((i)__VA_OPT__ (, reduce$ (_P_gcd_reducer_, i, __VA_ARGS__)))

#define _P_lcm_helper_(i, j, r, x, y)                                         \
  ({                                                                          \
    auto i = x;                                                               \
    auto j = y;                                                               \
    auto r = _P_gcd_ (i, j);                                                  \
    r ? (i / r) * j : 0;                                                      \
  })
#define _P_lcm_(x, y) _P_lcm_helper_ (uniq$ (i), uniq$ (j), uniq$ (r), x, y)
#define _P_lcm_reducer_(x, y) x = _P_lcm_ (x, y)
#define lcm(i, ...)                                                           \
  tail$ ((i)__VA_OPT__ (, reduce$ (_P_lcm_reducer_, i, __VA_ARGS__)))

#define _P_abs_helper_(t, x)                                                  \
  ({                                                                          \
    auto t = x;                                                               \
    t < 0 ? -t : t;                                                           \
  })
#define _P_abs_(x) _P_abs_helper_ (uniq$ (t), x)
#define abs(x) choose$ (ice$ (x), (x) < 0 ? -(x) : (x), _P_abs_ (x))

#define _P_lowbit_helper_(t, x)                                               \
  ({                                                                          \
    auto t = x;                                                               \
    t & -t;                                                                   \
  })
#define _P_lowbit_(x) _P_lowbit_helper_ (uniq$ (t), x)
#define lowbit(x) choose$ (ice$ (x), (x) & -(x), _P_lowbit_ (x))

#define _P_qpow_helper_(b, res, e, base, exp, ...)                            \
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
  _P_qpow_helper_ (uniq$ (b), uniq$ (res), uniq$ (e), base,                   \
                   exp __VA_OPT__ (, ) __VA_ARGS__)

/*********************************** math ************************************/

/********************************** bitset ***********************************/

#define bitbyte$(array, index) (((byte *)(array))[(usz)(index) >> 3])
#define bitbit$(index) (1u << ((index) & (7u)))
#define _P_bitdo_helper_(i, op, array, index)                                 \
  ({                                                                          \
    auto i = (usz)(index);                                                    \
    bitbyte$ (array, i) op bitbit$ (i);                                       \
  })
#define bitdo$(op, array, index) _P_bitdo_helper_ (uniq$ (i), op, array, index)
#define bitget$(array, index) bitdo$ (&, array, index)
#define bitput$(array, index) bitdo$ (|=, array, index)
#define bitclear$(array, index) bitdo$ (&= ~, array, index)
#define bitflip$(array, index) bitdo$ (^=, array, index)

/********************************** bitset ***********************************/

/******************************* dynamic array *******************************/

#define _C_daexp_ 4
#define _C_dadyn_ 3
#define daexp$ _C_daexp_
#define dadyn$ _C_dadyn_

#define _C_dalb_ (daexp$ - dadyn$)
#define _C_daub_ (daexp$ + dadyn$)
#define dalb$ _C_dalb_
#define daub$ _C_daub_

#define _P_dynarr_helper_(uc, us, r, capacity, size, page)                    \
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
  _P_dynarr_helper_ (uniq$ (uc), uniq$ (us), uniq$ (r), capacity, size,       \
                     umax$ (2, __VA_ARGS__))

/******************************* dynamic array *******************************/

/******************************** linked list ********************************/

#ifndef _S_LSNOD_
#define _S_LSNOD_ 1
struct lsnod
{
  union
  {
    struct
    {
      struct lsnod *prev;
      struct lsnod *next;
    };
    struct lsnod *link[2];
  };
};
#endif /* _S_LSNOD_ */

#define list$(cmd) _LS_##cmd##_

#define _P_LS_ins_helper_(unod, upre, unxt, nod, pre, nxt)                    \
  ({                                                                          \
    auto unod = nod;                                                          \
    auto upre = pre;                                                          \
    auto unxt = nxt;                                                          \
    unod->next = unxt;                                                        \
    unod->prev = upre;                                                        \
    unxt->prev = unod;                                                        \
    upre->next = unod;                                                        \
  })
#define _LS_ins_(node, prev, next)                                            \
  _P_LS_ins_helper_ (uniq$ (unod), uniq$ (upre), uniq$ (unxt), node, prev,    \
                     next)

#define _P_LS_rem_worker_(p, n)                                               \
  ({                                                                          \
    n->prev = p;                                                              \
    p->next = n;                                                              \
  })
#define _P_LS_rem_helper_(up, un, nd, node)                                   \
  ({                                                                          \
    auto nd = node;                                                           \
    auto up = nd->prev;                                                       \
    auto un = nd->next;                                                       \
    _P_LS_rem_worker_ (up, un);                                               \
  })
#define _LS_rem_(node)                                                        \
  _P_LS_rem_helper_ (uniq$ (up), uniq$ (un), uniq$ (nd), node)

/******************************** linked list ********************************/

/***************************** Xor Address PaiR ******************************/

typedef uptr xapr;
#define xapr$(cmd) _XAPR_##cmd##_
#define _XAPR_otr_(pair, nbr)                                                 \
  ((xapr *)((byte *)0 + (*(xapr *)(pair) ^ (xapr)(nbr))))
#define _P_XAPR_ins_helper_(upair, un_1, un_2, pair, n_1, n_2)                \
  ({                                                                          \
    auto upair = (xapr *)(pair);                                              \
    auto un_1 = (xapr *)(n_1);                                                \
    auto un_2 = (xapr *)(n_2);                                                \
    *upair = (xapr)un_1 ^ (xapr)un_2;                                         \
    *un_1 ^= (xapr)un_2 ^ (xapr)upair;                                        \
    *un_2 ^= (xapr)un_1 ^ (xapr)upair;                                        \
    upair;                                                                    \
  })
#define _XAPR_ins_(pair, n_1, n_2)                                            \
  _P_XAPR_ins_helper_ (uniq$ (upair), uniq$ (un_1), uniq$ (un_2), pair, n_1,  \
                       n_2)
#define _P_XAPR_rem_helper_(upair, unbr, uotr, pair, nbr)                     \
  ({                                                                          \
    auto upair = (xapr *)(pair);                                              \
    auto unbr = (xapr *)(nbr);                                                \
    auto uotr = xapr$ (otr) (upair, unbr);                                    \
    *unbr ^= (xapr)uotr ^ (xapr)upair;                                        \
    *uotr ^= (xapr)unbr ^ (xapr)upair;                                        \
    uotr;                                                                     \
  })
#define _XAPR_rem_(pair, nbr)                                                 \
  _P_XAPR_rem_helper_ (uniq$ (upair), uniq$ (unbr), uniq$ (uotr), pair, nbr)

/***************************** Xor Address PaiR ******************************/

/****************************** Xor linked LIST ******************************/

#define xlist$(cmd) _XLS_##cmd##_
#define _P_XLS_ins_helper_(uxpr, uprev, unext, ufirst, ulast, xpr, prev,      \
                           next, first, last)                                 \
  ({                                                                          \
    auto uxpr = (xapr *)(xpr);                                                \
    auto uprev = (xapr *)(prev);                                              \
    auto unext = (xapr *)(next);                                              \
    auto ufirst = (xapr **)(first);                                           \
    auto ulast = (xapr **)(last);                                             \
    if (uprev && unext)                                                       \
      xapr$ (ins) (uxpr, uprev, unext);                                       \
    else if (uprev)                                                           \
      *ulast = xapr$ (ins) (uxpr, *ufirst, *ulast);                           \
    else if (unext)                                                           \
      *ufirst = xapr$ (ins) (uxpr, *ufirst, *ulast);                          \
    else                                                                      \
      {                                                                       \
        *uxpr = 0;                                                            \
        *ufirst = *ulast = uxpr;                                              \
      }                                                                       \
    uxpr;                                                                     \
  })
#define _XLS_ins_(xpr, prev, next, first, last)                               \
  _P_XLS_ins_helper_ (uniq$ (uxpr), uniq$ (uprev), uniq$ (unext),             \
                      uniq$ (ufirst), uniq$ (ulast), xpr, prev, next, first,  \
                      last)
#define _P_XLS_rem_helper_(uxpr, unbr, ufirst, ulast, xpr, nbr, first, last)  \
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
#define _XLS_rem_(xpr, nbr, first, last)                                      \
  _P_XLS_rem_helper_ (uniq$ (uxpr), uniq$ (unbr), uniq$ (ufirst),             \
                      uniq$ (ulast), xpr, nbr, first, last)
#define _P_XLS_unshift_helper_(ufirst, xpr, first, last)                      \
  ({                                                                          \
    auto ufirst = (xapr **)(first);                                           \
    xlist$ (ins) (xpr, null, *ufirst, ufirst, last);                          \
  })
#define _XLS_unshift_(xpr, first, last)                                       \
  _P_XLS_unshift_helper_ (uniq$ (ufirst), xpr, first, last);
#define _P_XLS_shift_helper_(ufirst, ulast, first, last)                      \
  ({                                                                          \
    auto ufirst = (xapr **)(first);                                           \
    auto ulast = (xapr **)(last);                                             \
    xlist$ (rem) (*ufirst, *ulast, ufirst, ulast);                            \
  })
#define _XLS_shift_(first, last)                                              \
  _P_XLS_shift_helper_ (uniq$ (ufirst), uniq$ (ulast), first, last)
#define _P_XLS_push_helper_(ulast, xpr, first, last)                          \
  ({                                                                          \
    auto ulast = (xapr **)(last);                                             \
    xlist$ (ins) (xpr, *ulast, null, first, ulast);                           \
  })
#define _XLS_push_(xpr, first, last)                                          \
  _P_XLS_push_helper_ (uniq$ (ulast), xpr, first, last);
#define _P_XLS_pop_helper_(ufirst, ulast, first, last)                        \
  ({                                                                          \
    auto ufirst = (xapr **)(first);                                           \
    auto ulast = (xapr **)(last);                                             \
    xlist$ (rem) (*ulast, *ufirst, ufirst, ulast);                            \
  })
#define _XLS_pop_(first, last)                                                \
  _P_XLS_pop_helper_ (uniq$ (ufirst), uniq$ (ulast), first, last)

#define _P_xlsfor_helper_(f, i, var, zeroth, first, last)                     \
  for (xapr *f = (xapr *)&f, *i = (xapr *)(zeroth), *var = (xapr *)(first);   \
       f != (last); i = xapr$ (otr) (var, i), f = swap (var, i))
#define _P_xlsfor_4_(var, zeroth, first, last)                                \
  _P_xlsfor_helper_ (uniq$ (f), uniq$ (i), var, zeroth, first, last)
#define _P_xlsfor_3_(var, first, last, ...)                                   \
  _P_xlsfor_4_ (var, last, first, last)
#define _P_xlsfor_va_(a_1, a_2, a_3, a_4, argc, ...)                          \
  cat$ (_P_xlsfor_, argc##_) (a_1, a_2, a_3, a_4)
#define xlsfor$(var, xpr_1, xpr_2, ...)                                       \
  _P_xlsfor_va_ (var, xpr_1, xpr_2, __VA_ARGS__ __VA_OPT__ (, ) 4, 3)

#define _P_xlsfree_worker_(ufirst, ulast, i, first, last, ...)                \
  do                                                                          \
    {                                                                         \
      auto ufirst = (xapr **)(first);                                         \
      auto ulast = (xapr **)(last);                                           \
      xapr *i;                                                                \
      do                                                                      \
        {                                                                     \
          i = xlist$ (shift) (ufirst, ulast);                                 \
          __VA_OPT__ (__VA_ARGS__;)                                           \
          free (i);                                                           \
        }                                                                     \
      while (i);                                                              \
    }                                                                         \
  while (0)
#define _P_xlsfree_helper_(ufirst, ulast, i, first, last, ...)                \
  _P_xlsfree_worker_ (ufirst, ulast, i, first,                                \
                      last __VA_OPT__ (, __VA_ARGS__ (i)))
#define xlsfree$(first, last, ...)                                            \
  _P_xlsfree_helper_ (uniq$ (ufirst), uniq$ (ulast), uniq$ (i), first,        \
                      last __VA_OPT__ (, ) __VA_ARGS__)

/****************************** Xor linked LIST ******************************/

#define _P_memswap_helper_(up, uq, un, i, p, q, n)                            \
  do                                                                          \
    {                                                                         \
      byte *restrict up = (void *)(p);                                        \
      byte *restrict uq = (void *)(q);                                        \
      auto un = (usz)(n);                                                     \
      for (usz i = 0; i < un; ++i)                                            \
        swap (up[i], uq[i]);                                                  \
    }                                                                         \
  while (0)
#define memswap(p, q, n)                                                      \
  _P_memswap_helper_ (uniq$ (ud), uniq$ (us), uniq$ (un), uniq$ (i), p, q, n)

#define _P_memhash_helper_(umemb, usize, m, res, i, memb, size, mod)          \
  ({                                                                          \
    auto umemb = (byte *)(memb);                                              \
    auto usize = (usz)(size);                                                 \
    auto m = mod;                                                             \
    auto res = (typeof (m)){ 0 };                                             \
    for (usz i = 0; i < usize; ++i)                                           \
      res = (res << 8 ^ umemb[i]) % m;                                        \
    res;                                                                      \
  })
#define _P_memhash_3_(memb, size, mod)                                        \
  _P_memhash_helper_ (uniq$ (umemb), uniq$ (usize), uniq$ (m), uniq$ (res),   \
                      uniq$ (i), memb, size, mod)
#define _P_memhash_2_(memb, size, ...)                                        \
  _P_memhash_3_ (memb, size, const$ (tp56))
#define _P_memhash_1_(memb, ...) _P_memhash_2_ (memb, sizeof (memb))
#define _P_memhash_va_(a_1, a_2, a_3, argc, ...)                              \
  cat$ (_P_memhash_, argc##_) (a_1, a_2, a_3)
#define memhash(memb, ...)                                                    \
  _P_memhash_va_ (memb, __VA_ARGS__ __VA_OPT__ (, ) 3, 2, 1)

#define _P_strhash_helper_(ustr, m, res, i, str, mod)                         \
  ({                                                                          \
    auto ustr = (byte *)(str);                                                \
    auto m = mod;                                                             \
    auto res = (typeof (m)){ 0 };                                             \
    for (usz i = 0; ustr[i]; ++i)                                             \
      res = (res << 8 ^ ustr[i]) % m;                                         \
    res;                                                                      \
  })
#define _P_strhash_2_(str, mod)                                               \
  _P_strhash_helper_ (uniq$ (ustr), uniq$ (m), uniq$ (res), uniq$ (i), str,   \
                      mod)
#define _P_strhash_1_(str, ...) _P_strhash_2_ (str, const$ (tp56))
#define _P_strhash_va_(a_1, a_2, argc, ...)                                   \
  cat$ (_P_strhash_, argc##_) (a_1, a_2)
#define strhash(str, ...)                                                     \
  _P_strhash_va_ (str, __VA_ARGS__ __VA_OPT__ (, ) 2, 1)

/******************************** d-ary heap *********************************/

#define heap$(cmd) _HP_##cmd##_

#define _P_HP_siftup_helper_(base, width, d, i, j, _base, _width, compar, _d, \
                             _i)                                              \
  do                                                                          \
    {                                                                         \
      auto base = (void *)(_base);                                            \
      auto width = (usz)(_width);                                             \
      auto d = (usz)(_d);                                                     \
      auto i = (usz)(_i);                                                     \
      usz j;                                                                  \
      while (i                                                                \
             && compar (base + width * (j = (i - 1) / d), base + width * i)   \
                    > 0)                                                      \
        {                                                                     \
          memswap (base + width * j, base + width * i, width);                \
          i = j;                                                              \
        }                                                                     \
    }                                                                         \
  while (0)
#define _HP_siftup_(_base, _width, compar, _d, _i)                            \
  _P_HP_siftup_helper_ (uniq$ (base), uniq$ (width), uniq$ (d), uniq$ (i),    \
                        uniq$ (j), _base, _width, compar, _d, _i)

#define _P_HP_siftdown_helper_(base, nel, width, d, i, m, r, k, j, _base,     \
                               _nel, _width, compar, _d, _i)                  \
  do                                                                          \
    {                                                                         \
      auto base = (void *)(_base);                                            \
      auto nel = (usz)(_nel);                                                 \
      auto width = (usz)(_width);                                             \
      auto d = (usz)(_d);                                                     \
      auto i = (usz)(_i);                                                     \
      if (nel < 2)                                                            \
        break;                                                                \
      usz m = (nel - 2) / d;                                                  \
      while (i <= m)                                                          \
        {                                                                     \
          usz r = i * d + 1;                                                  \
          usz k = nel - r < d ? nel : r + d;                                  \
          for (usz j = r + 1; j < k; ++j)                                     \
            if (compar (base + width * r, base + width * j) > 0)              \
              r = j;                                                          \
          if (compar (base + width * i, base + width * r) > 0)                \
            memswap (base + width * i, base + width * r, width);              \
          i = r;                                                              \
        }                                                                     \
    }                                                                         \
  while (0)
#define _HP_siftdown_(_base, _nel, _width, compar, _d, _i)                    \
  _P_HP_siftdown_helper_ (uniq$ (base), uniq$ (nel), uniq$ (width),           \
                          uniq$ (d), uniq$ (i), uniq$ (m), uniq$ (r),         \
                          uniq$ (k), uniq$ (j), _base, _nel, _width, compar,  \
                          _d, _i)

#define _P_HP_heapify_helper_(base, nel, width, d, i, _base, _nel, _width,    \
                              compar, _d)                                     \
  do                                                                          \
    {                                                                         \
      auto base = (void *)(_base);                                            \
      auto nel = (usz)(_nel);                                                 \
      auto width = (usz)(_width);                                             \
      auto d = (usz)(_d);                                                     \
      if (nel < 2)                                                            \
        break;                                                                \
      usz i = (nel - 2) / d + 1;                                              \
      do                                                                      \
        _HP_siftdown_ (base, nel, width, compar, d, --i);                     \
      while (i);                                                              \
    }                                                                         \
  while (0)
#define _HP_heapify_(_base, _nel, _width, compar, _d)                         \
  _P_HP_heapify_helper_ (uniq$ (base), uniq$ (nel), uniq$ (width), uniq$ (d), \
                         uniq$ (i), _base, _nel, _width, compar, _d)

/******************************** d-ary heap *********************************/

#ifndef _S_BSTNOD_
#define _S_BSTNOD_ 1
struct bstnod
{
  union
  {
    struct
    {
      struct bstnod *left;
      struct bstnod *right;
    };
    struct bstnod *child[2];
  };
  struct bstnod *parent;
};
#endif /* _S_BSTNOD_ */

/************************************ I/O ************************************/

#if !defined _P_UNLOCKED_STDIO_                                               \
    && (defined __USE_POSIX199506                                             \
        || (defined getchar_unlocked && defined getc_unlocked                 \
            && defined putchar_unlocked && defined putc_unlocked))
#define _P_UNLOCKED_STDIO_ 1
#define _P_getchar_worker_ getchar_unlocked
#define _P_getc_worker_ getc_unlocked
#define _P_putchar_worker_ putchar_unlocked
#define _P_putc_worker_ putc_unlocked
#elif defined _WIN32
#define _P_UNLOCKED_STDIO_ 32
#define _P_getchar_worker_ _getchar_nolock
#define _P_getc_worker_ _getc_nolock
#define _P_putchar_worker_ _putchar_nolock
#define _P_putc_worker_ _putc_nolock
#endif
#if (_P_UNLOCKED_STDIO_ + 0) == 1                                             \
    && (defined __USE_GNU                                                     \
        || (defined fgets_unlocked && defined fputs_unlocked))
#undef _P_UNLOCKED_STDIO_
#define _P_UNLOCKED_STDIO_ 3
#define _P_fgets_worker_ fgets_unlocked
#define _P_fputs_worker_ fputs_unlocked
#endif

/* fallback */

#ifndef _P_getchar_worker_
#define _P_getchar_worker_ getchar
#endif
#ifndef _P_getc_worker_
#define _P_getc_worker_ getc
#endif
#ifndef _P_putchar_worker_
#define _P_putchar_worker_ putchar
#endif
#ifndef _P_putc_worker_
#define _P_putc_worker_ putc
#endif
#ifndef _P_fgets_worker_
#define _P_fgets_worker_ fgets
#endif
#ifndef _P_fputs_worker_
#define _P_fputs_worker_ fputs
#endif

#ifndef EOL
#define EOL 10
#endif

#if (_P_UNLOCKED_STDIO_ + 0) != 0 || !defined getchar && !defined getc
#define _P_getchar_1_(stream) _P_getc_worker_ (stream)
#define _P_getchar_0_(...) _P_getchar_worker_ ()
#define _P_getchar_va_(a_1, argc, ...) cat$ (_P_getchar_, argc##_) (a_1)
#undef getchar
#define getchar(...) _P_getchar_va_ (__VA_ARGS__ __VA_OPT__ (, ) 1, 0)
#undef getc
#define getc(...) getchar (__VA_ARGS__)
#endif

#if (_P_UNLOCKED_STDIO_ + 0) != 0 || !defined putchar && !defined putc
#define _P_putchar_2_(c, stream) _P_putc_worker_ (c, stream)
#define _P_putchar_1_(c, ...) _P_putchar_worker_ (c)
#define _P_putchar_0_(...) _P_putchar_worker_ (EOL)
#define _P_putchar_va_(a_1, a_2, argc, ...)                                   \
  cat$ (_P_putchar_, argc##_) (a_1, a_2)
#undef putchar
#define putchar(...) _P_putchar_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#undef putc
#define putc(...) putchar (__VA_ARGS__)
#endif

#define _P_ungetc_2_(c, stream) ungetc (c, stream)
#define _P_ungetc_1_(c, ...) ungetc (c, stdin)
#define _P_ungetc_0_(...) ungetc (EOL, stdin)
#define _P_ungetc_va_(a_1, a_2, argc, ...)                                    \
  cat$ (_P_ungetc_, argc##_) (a_1, a_2)
#define ungetc(...) _P_ungetc_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#define ungetchar(...) ungetc (__VA_ARGS__)

#define _P_getc_delimited_helper_(c, r, i, delim, ...)                        \
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
#define _P_getc_delimited_(delim, ...)                                        \
  _P_getc_delimited_helper_ (uniq$ (c), uniq$ (r), uniq$ (i),                 \
                             delim __VA_OPT__ (, ) __VA_ARGS__)

#define _P_gets_3_(str, length, stream)                                       \
  _P_fgets_worker_ (str, (iptr)(length), stream)
#define _P_gets_2_(str, length, ...) _P_gets_3_ (str, length, stdin)
#define _P_gets_1_(str, ...) _P_gets_2_ (str, countof (str))
#define _P_gets_va_(a_1, a_2, a_3, argc, ...)                                 \
  cat$ (_P_gets_, argc##_) (a_1, a_2, a_3)
#define _P_getvs_helper_(ud, ups, sz, cap, str, ch, ncap, s, delimiter,       \
                         psize, stream)                                       \
  ({                                                                          \
    auto ud = (char const *const)(delimiter);                                 \
    auto ups = (usz *)((byte *)0 + (uptr)(psize));                            \
    usz sz = 0, cap = dynarr$ (0, 2);                                         \
    char *str = malloc (cap);                                                 \
    while (str)                                                               \
      {                                                                       \
        int ch = _P_getc_delimited_ (ud, stream);                             \
        if (ch == EOF)                                                        \
          break;                                                              \
        usz ncap = dynarr$ (cap, sz + 2);                                     \
        char *s = ncap == cap ? str : realloc (str, cap = ncap);              \
        if (likely (s))                                                       \
          s[sz++] = ch;                                                       \
        else                                                                  \
          free (str);                                                         \
        str = s;                                                              \
      }                                                                       \
    if (likely (str))                                                         \
      {                                                                       \
        str[sz] = 0;                                                          \
        if (ups)                                                              \
          *ups = sz;                                                          \
      }                                                                       \
    str;                                                                      \
  })
#define _P_getvs_3_(delimiter, psize, stream)                                 \
  _P_getvs_helper_ (uniq$ (ud), uniq$ (ups), uniq$ (sz), uniq$ (cap),         \
                    uniq$ (str), uniq$ (ch), uniq$ (ncap), uniq$ (s),         \
                    delimiter, psize, stream)
#define _P_getvs_2_(delimiter, psize, ...)                                    \
  _P_getvs_3_ (delimiter, psize, stdin)
#define _P_getvs_1_(delimiter, ...) _P_getvs_2_ (delimiter, null)
#define _P_getvs_0_(...) _P_getvs_1_ ("\r\n")
#define _P_getvs_va_(a_1, a_2, a_3, argc, ...)                                \
  cat$ (_P_getvs_, argc##_) (a_1, a_2, a_3)
#define getvs(...) _P_getvs_va_ (__VA_ARGS__ __VA_OPT__ (, ) 3, 2, 1, 0)
#define getvstr(...) getvs (__VA_ARGS__)
#ifdef __GNUC__
#define _P_gets_g_(str, ...)                                                  \
  choose$ (__builtin_constant_p (str),                                        \
           getvs (str __VA_OPT__ (, ) __VA_ARGS__),                           \
           _P_gets_va_ (str, __VA_ARGS__ __VA_OPT__ (, ) 3, 2, 1))
#define gets(...) tail$ (getvs () __VA_OPT__ (, _P_gets_g_ (__VA_ARGS__)))
#else
#define gets(...)                                                             \
  tail$ (getvs () __VA_OPT__ (, _P_gets_va_ (__VA_ARGS__, 3, 2, 1)))
#endif
#define getstr(...) gets (__VA_ARGS__)

#define _P_puts_2_(str, stream) _P_fputs_worker_ (str, stream)
#define _P_puts_1_(str, ...) _P_fputs_worker_ (str, stdout)
#define _P_puts_0_(...) puts ("")
#define _P_puts_va_(a_1, a_2, argc, ...) cat$ (_P_puts_, argc##_) (a_1, a_2)
#define puts(...) _P_puts_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#define putstr(...) puts (__VA_ARGS__)

#define _P_peekchar_helper_(c, ...)                                           \
  ({                                                                          \
    int c = getc (__VA_ARGS__);                                               \
    ungetc (c __VA_OPT__ (, ) __VA_ARGS__);                                   \
    c;                                                                        \
  })
#define peekchar(...)                                                         \
  _P_peekchar_helper_ (uniq$ (c) __VA_OPT__ (, ) __VA_ARGS__)
#define peekc(...) peekchar (__VA_ARGS__)

/* quick decimal integer I/O */

#define _P_getdec_helper_(j, s, ch, type, ...)                                \
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
#define _P_getdec_2_(type, stream)                                            \
  _P_getdec_helper_ (uniq$ (j), uniq$ (s), uniq$ (ch), type, stream)
#define _P_getdec_1_(type, ...) _P_getdec_2_ (type, )
#define _P_getdec_0_(...) _P_getdec_1_ (int)
#define _P_getdec_va_(a_1, a_2, argc, ...)                                    \
  cat$ (_P_getdec_, argc##_) (a_1, a_2)
#define getdec(...) _P_getdec_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#define getd(...) getdec (__VA_ARGS__)

#define _P_putdec_helper_(j, s, sta, ptr, i, ...)                             \
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
  _P_putdec_helper_ (uniq$ (j), uniq$ (s), uniq$ (sta), uniq$ (ptr),          \
                     i __VA_OPT__ (, ) __VA_ARGS__)
#define putd(i, ...) putdec (i __VA_OPT__ (, ) __VA_ARGS__)

#define getint(...) getdec (__VA_ARGS__)
#define geti(...) getd (__VA_ARGS__)
#define putint(i, ...) putdec (i __VA_OPT__ (, ) __VA_ARGS__)
#define puti(i, ...) putd (i __VA_OPT__ (, ) __VA_ARGS__)

#define _P_seekchar_helper_(uc, ch, c, stream)                                \
  ({                                                                          \
    auto uc = c;                                                              \
    int ch;                                                                   \
    do                                                                        \
      ch = getc (stream);                                                     \
    while (ch != uc && ch != EOF);                                            \
    ch;                                                                       \
  })
#define _P_seekchar_2_(c, stream)                                             \
  _P_seekchar_helper_ (uniq$ (uc), uniq$ (ch), c, stream)
#define _P_seekchar_1_(c, ...) _P_seekchar_2_ (c, )
#define _P_seekchar_0_(...) _P_seekchar_1_ (EOL)
#define _P_seekchar_va_(a_1, a_2, argc, ...)                                  \
  cat$ (_P_seekchar_, argc##_) (a_1, a_2)
#define seekchar(...) _P_seekchar_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)
#define seekc(...) seekchar (__VA_ARGS__)

#define _P_seekint_helper_(ui, j, i, ...)                                     \
  ({                                                                          \
    auto ui = i;                                                              \
    typeof (ui) j;                                                            \
    do                                                                        \
      j = geti (typeof (ui) __VA_OPT__ (, ) __VA_ARGS__);                     \
    while (j != ui && peekc (__VA_ARGS__) != EOF);                            \
    j;                                                                        \
  })
#define seekint(i, ...)                                                       \
  _P_seekint_helper_ (uniq$ (ui), uniq$ (j), i __VA_OPT__ (, ) __VA_ARGS__)
#define seeki(i, ...) seekint (i __VA_OPT__ (, ) __VA_ARGS__)

#define _P_cout_(a)                                                           \
  choose$ (ipe$ (a), ({                                                       \
             puts (choose$ (ipe$ (a), a, ""));                                \
             (void)0;                                                         \
           }),                                                                \
           ({                                                                 \
             puti (choose$ (ipe$ (a), 0, a));                                 \
             (void)0;                                                         \
           }))
#define _P_cout_helper_(a, b)                                                 \
  a;                                                                          \
  putchar (' ');                                                              \
  _P_cout_ (b);
#define _P_cout_n_(a, ...)                                                    \
  do                                                                          \
    {                                                                         \
      __VA_OPT__ ($reduce)                                                    \
      (__VA_OPT__ (_P_cout_helper_, ) _P_cout_ (a) __VA_OPT__ (, )            \
           __VA_ARGS__);                                                      \
    }                                                                         \
  while (0)
#define cout(...)                                                             \
  ({                                                                          \
    __VA_OPT__ (_P_cout_n_ (__VA_ARGS__));                                    \
    putchar ();                                                               \
    (void)0;                                                                  \
  })

#define _P_cerr_(a)                                                           \
  choose$ (ipe$ (a), ({                                                       \
             puts (choose$ (ipe$ (a), a, ""), stderr);                        \
             (void)0;                                                         \
           }),                                                                \
           ({                                                                 \
             puti (choose$ (ipe$ (a), 0, a), stderr);                         \
             (void)0;                                                         \
           }))
#define _P_cerr_helper_(a, b)                                                 \
  a;                                                                          \
  putchar (' ', stderr);                                                      \
  _P_cerr_ (b);
#define _P_cerr_n_(a, ...)                                                    \
  do                                                                          \
    {                                                                         \
      __VA_OPT__ ($reduce)                                                    \
      (__VA_OPT__ (_P_cerr_helper_, ) _P_cerr_ (a) __VA_OPT__ (, )            \
           __VA_ARGS__);                                                      \
    }                                                                         \
  while (0)
#define cerr(...)                                                             \
  ({                                                                          \
    __VA_OPT__ (_P_cerr_n_ (__VA_ARGS__));                                    \
    putchar (EOL, stderr);                                                    \
    (void)0;                                                                  \
  })

/************************************ I/O ************************************/

/************************ Miller-Rabin primality test ************************/

#define _P_isprime_helper_(ui, res, u, t, tn, j, stn, v, s, i)                \
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
        u32 const tn[]                                                        \
            = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };           \
        for (usz j = 0; j < countof (tn); ++j)                                \
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
  _P_isprime_helper_ (uniq$ (ui), uniq$ (res), uniq$ (u), uniq$ (t),          \
                      uniq$ (tn), uniq$ (j), uniq$ (stn), uniq$ (v),          \
                      uniq$ (s), i)

/************************ Miller-Rabin primality test ************************/

/***************************** Mersenne Twister ******************************/

#define _P_mt_va_(name, ...) _MT_##name##_
#define mt$(...) _P_mt_va_ (__VA_ARGS__ __VA_OPT__ (, ) u64)

#define _MT_NN_ 312
#define _MT_MM_ 156
#define _MT_MATRIX_A_ UINT64_C (0xb5026f5aa96619e9)
#define _MT_UM_ UINT64_C (0xffffffff80000000)
#define _MT_LM_ UINT64_C (0x7fffffff)

#if (MERSENNE_TWISTER_64_IMPL + 0) == 0
#undef MERSENNE_TWISTER_64_IMPL
#define MERSENNE_TWISTER_64_IMPL 1

#ifdef _REENTRANT
static __thread u64 _MT_mt_[_MT_NN_];
static __thread int _MT_mti_ = _MT_NN_ + 1;
#else
static u64 _MT_mt_[_MT_NN_];
static int _MT_mti_ = _MT_NN_ + 1;
#endif

static inline void
_MT_srand_ (u64 _MT_seed_)
{
  _MT_mt_[0] = _MT_seed_;
  for (_MT_mti_ = 1; _MT_mti_ < _MT_NN_; ++_MT_mti_)
    _MT_mt_[_MT_mti_]
        = (UINT64_C (6364136223846793005)
               * (_MT_mt_[_MT_mti_ - 1] ^ (_MT_mt_[_MT_mti_ - 1] >> 62))
           + _MT_mti_);
}

static inline void
_MT_init_ (u64 _MT_init_key_[], u64 _MT_key_length_)
{
  unsigned int _MT_i_, _MT_j_;
  u64 _MT_k_;
  _MT_srand_ (UINT64_C (19650218));
  _MT_i_ = 1;
  _MT_j_ = 0;
  _MT_k_ = (_MT_NN_ > _MT_key_length_ ? _MT_NN_ : _MT_key_length_);
  for (; _MT_k_; --_MT_k_)
    {
      _MT_mt_[_MT_i_] = (_MT_mt_[_MT_i_]
                         ^ ((_MT_mt_[_MT_i_ - 1] ^ (_MT_mt_[_MT_i_ - 1] >> 62))
                            * UINT64_C (3935559000370003845)))
                        + _MT_init_key_[_MT_j_] + _MT_j_;
      ++_MT_i_;
      ++_MT_j_;
      if (_MT_i_ >= _MT_NN_)
        {
          _MT_mt_[0] = _MT_mt_[_MT_NN_ - 1];
          _MT_i_ = 1;
        }
      if (_MT_j_ >= _MT_key_length_)
        _MT_j_ = 0;
    }
  for (_MT_k_ = _MT_NN_ - 1; _MT_k_; --_MT_k_)
    {
      _MT_mt_[_MT_i_] = (_MT_mt_[_MT_i_]
                         ^ ((_MT_mt_[_MT_i_ - 1] ^ (_MT_mt_[_MT_i_ - 1] >> 62))
                            * UINT64_C (2862933555777941757)))
                        - _MT_i_;
      ++_MT_i_;
      if (_MT_i_ >= _MT_NN_)
        {
          _MT_mt_[0] = _MT_mt_[_MT_NN_ - 1];
          _MT_i_ = 1;
        }
    }
  _MT_mt_[0] = UINT64_C (1) << 63;
}

static inline u64
_MT_rand_ ()
{
  int _MT_i_;
  u64 _MT_x_;
#ifdef _REENTRANT
  static __thread u64 _MT_mag01_[2] = { UINT64_C (0), _MT_MATRIX_A_ };
#else
  static u64 _MT_mag01_[2] = { UINT64_C (0), _MT_MATRIX_A_ };
#endif
  if (_MT_mti_ >= _MT_NN_)
    {
      if (_MT_mti_ == _MT_NN_ + 1)
        _MT_srand_ (UINT64_C (5489));
      for (_MT_i_ = 0; _MT_i_ < _MT_NN_ - _MT_MM_; ++_MT_i_)
        {
          _MT_x_
              = (_MT_mt_[_MT_i_] & _MT_UM_) | (_MT_mt_[_MT_i_ + 1] & _MT_LM_);
          _MT_mt_[_MT_i_] = _MT_mt_[_MT_i_ + _MT_MM_] ^ (_MT_x_ >> 1)
                            ^ _MT_mag01_[(int)(_MT_x_ & UINT64_C (1))];
        }
      for (; _MT_i_ < _MT_NN_ - 1; ++_MT_i_)
        {
          _MT_x_
              = (_MT_mt_[_MT_i_] & _MT_UM_) | (_MT_mt_[_MT_i_ + 1] & _MT_LM_);
          _MT_mt_[_MT_i_] = _MT_mt_[_MT_i_ + (_MT_MM_ - _MT_NN_)]
                            ^ (_MT_x_ >> 1)
                            ^ _MT_mag01_[(int)(_MT_x_ & UINT64_C (1))];
        }
      _MT_x_ = (_MT_mt_[_MT_NN_ - 1] & _MT_UM_) | (_MT_mt_[0] & _MT_LM_);
      _MT_mt_[_MT_NN_ - 1] = _MT_mt_[_MT_MM_ - 1] ^ (_MT_x_ >> 1)
                             ^ _MT_mag01_[(int)(_MT_x_ & UINT64_C (1))];
      _MT_mti_ = 0;
    }
  _MT_x_ = _MT_mt_[_MT_mti_++];
  _MT_x_ ^= (_MT_x_ >> 29) & UINT64_C (0x5555555555555555);
  _MT_x_ ^= (_MT_x_ << 17) & UINT64_C (0x71d67fffeda60000);
  _MT_x_ ^= (_MT_x_ << 37) & UINT64_C (0xfff7eee000000000);
  _MT_x_ ^= (_MT_x_ >> 43);
  return _MT_x_;
}

#endif /* MERSENNE_TWISTER_64_IMPL */

#define _P_MT_seed_2_(a_1, a_2) _MT_init_ (a_1, a_2)
#define _P_MT_seed_1_(a_1, ...) _MT_srand_ (a_1)
#define _P_MT_seed_0_(...) _MT_srand_ (macro$ (trng))
#define _P_MT_seed_va_(a_1, a_2, argc, ...)                                   \
  cat$ (_P_MT_seed_, argc##_) (a_1, a_2)
#define _MT_seed_(...) _P_MT_seed_va_ (__VA_ARGS__ __VA_OPT__ (, ) 2, 1, 0)

/* mt$ (u64) generates a random number on [0, 2 ** 64)-interval */
#define _MT_u64_ _MT_rand_ ()
/* mt$ (i64) generates a random number on [0, 2 ** 63)-interval */
#define _MT_i64_ ((i64)(_MT_rand_ () >> 1))
/* mt$ (real) generates a random number on [0, 1]-real-interval */
#define _MT_real_ ((_MT_rand_ () >> 11) * (1.0 / 9007199254740991.0))
/* mt$ (rea) generates a random number on [0, 1)-real-interval */
#define _MT_rea_ ((_MT_rand_ () >> 11) * (1.0 / 9007199254740992.0))
/* mt$ (eal) generates a random number on (0, 1]-real-interval */
#define _MT_eal_ (1.0 - (_MT_rand_ () >> 11) * (1.0 / 9007199254740992.0))
/* mt$ (ea) generates a random number on (0, 1)-real-interval */
#define _MT_ea_ (((_MT_rand_ () >> 12) + 0.5) * (1.0 / 4503599627370496.0))

#define _P_mt19937_1_(type)                                                   \
  _Generic ((typeof (type)){ 0 },                                             \
      u64: _MT_u64_,                                                          \
      i64: _MT_i64_,                                                          \
      real: _MT_rea_,                                                         \
      default: (void)0)
#define _P_mt19937_0_(...) _P_mt19937_1_ (u64)
#define _P_mt19937_va_(a_1, argc, ...) cat$ (_P_mt19937_, argc##_) (a_1)
/* C++ style of mt19937 */
#define mt19937(...) _P_mt19937_va_ (__VA_ARGS__ __VA_OPT__ (, ) 1, 0)

/***************************** Mersenne Twister ******************************/
