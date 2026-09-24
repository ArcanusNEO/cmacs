# `cmacs.h` Code Map

## Purpose And Source

- Current source: `cmacs.h` (3182 lines). An installed copy may exist at `/usr/local/include/cmacs.h`; upstream is `https://raw.github.com/ArcanusNEO/cmacs/master/cmacs.h`.
- This is an index for the current header, not an API contract. Line numbers are navigation aids. Always inspect the active header before relying on an argument order, return value, evaluation count, side effect, or ownership rule.
- The header intentionally has no top-level include guard; repeated inclusion in the same translation unit is expected to be idempotent. Local guards and implementation switches prevent duplicate declarations or definitions.
- Use this map when a project already includes `cmacs.h` or explicitly asks for it. Do not introduce the header into otherwise ordinary ISO C code only for convenience.
- Prefer a facility already provided by the header over reimplementing its aliases, cleanup logic, containers, hashing, or random-number support.

## Style And Compilation

- Follow the project's formatter or style. Otherwise use GNU C style with two-space indentation, no tabs, and a space before a call's opening parenthesis; use the same style in documentation examples.
- The header primarily targets GCC/Clang GNU C. Use a GNU dialect such as `-std=gnu11` or newer, while noting that `__VA_OPT__` may require a newer compiler mode. It uses statement expressions, `__typeof__`, `__auto_type`, GNU attributes, `__COUNTER__`, and computed goto. Do not assume strict ISO C or MSVC compatibility.
- The header defines `_GNU_SOURCE`, but feature-test macros must precede all libc headers to be reliable. Define it in compiler flags or before any system include when GNU libc declarations matter.
- In C, it defines or remaps `auto`, `null`, `restrict`, `generic`, `atomic`, and `asm`. Treat these as library/compiler extensions, not neutral ISO C spellings. On Windows it also defines `WIN32_LEAN_AND_MEAN`, `NOMINMAX`, and `NOINTERFACE` before including `<windows.h>`; these definitions remain visible to the including translation unit.
- Freestanding mode includes only a limited set of standard headers and disables the built-in smart-pointer and entropy implementations by default. Their wrappers are unusable unless compatible implementations are supplied.

## Naming

| Form | Meaning and use |
| --- | --- |
| `foo$`, `foo$ (...)` | Public utility or command-dispatch macro; prefer these entry points. |
| `macro$`, `static$`, `const$` | Token-paste helpers that form `_P_*`, `_S_*`, and `_C_*`; they do not make the resulting name a stable API. |
| `_P_*`, `_S_*`, `_C_*` | General implementation names; do not call them directly. |
| `_LS_*`, `_XAPR_*`, `_XLS_*`, `_HP_*`, `_BST_*`, `_HTB_*` | Container implementations; use `list$`, `xapr$`, `xlist$`, `heap$`, `bst$`, or `htab$`. |
| `_A5_*`, `_EN_*`, `_MT_*` | Hash, entropy, and MT implementations; use `memhash`, `strhash`, `entropy$`, `mt$`, or `mt19937`. |
| `a5$` | Exposed dispatcher to `_A5_*` implementation names; it is not a supported public entry point. Use `memhash` or `strhash`. |
| `$` | Coroutine context-object shorthand inside an `async$` body; use `$.field` to access the current context. |

The `$` character is part of the public naming convention. A dispatcher such as `htab$ (ins)` expands to an operation that is then called with its own arguments.

## Types And Environment

| Lines | Area | Main entries |
| --- | --- | --- |
| 18-93 | Hosted/freestanding headers and Unix/Windows selection | `macro$ (PLATFORM)`, `macro$ (UNIX)`, `macro$ (WINDOWS)` |
| 95-153 | C/C++ keyword remaps and integer, pointer, size, character, and floating aliases | `null`, `auto`, `generic`, `atomic`, `byte`, `word`, `i8/u8` through `i128/u128`, `iptr/uptr`, `isz/usz`, `c8/c16/c32`, `real`, `f16/f32/f64/f128`, `isto/usto/fsto` |
| 155-286 | Compile-time failure, naming helpers, and prime constants | `todo$`, `macro$`, `static$`, `const$`, `const$ (p2)` through `const$ (p64)`, `const$ (tp3)` through `const$ (tp64)` |

Use `usz` for sizes and indices, `isz` for signed differences, and note that `real` is `double`. `i128/u128` and `f16/f128` fall back when unsupported, so their advertised width is not unconditional. `c8/c16/c32` are least-width integer types.

## Macro And Expression Utilities

| Lines | Area | Main entries |
| --- | --- | --- |
| 288-319 | Stringification, concatenation, unique names, parentheses, rescanning | `quote$`, `cat$`, `uniq$`, `lp$`, `rp$`, `paren$`, `unparen$`, `scan$` |
| 320-850 | Variadic macro reduction and list access | `$reduce`, `car$`, `cdr$`, `head$`, `tail$` |
| 852-972 | Type inference and compile-time/type selection | `typeof`, `signedof`, `signedwich`, `signed$`, `unsigned$`, `empty$`, `count$`, `typewarn$`, `ice$`, `ace$`, `choose$`, `ovre$`, `ovrt$`, `umax$`, `umin$`, `likely`, `unlikely`, `typematch$`, `countof`, `ipe$`, `ape$` |
| 893-901 | Pointer and packet layout conversion | `offsetof`, `container_of`, `packetof`, `dataof` |
| 974-1079 | Attributes, runtime reduction, arithmetic, swap, lambdas, scoped loops | `dense$`, `inline$`, `pure$`, `unused$`, `defer$`, `weak$`, `sum$`, `prod$`, `reduce$`, `max`, `min`, `swap`, `lambda`, `with$` |

`$reduce` is a preprocessor fold; `reduce$` is a statement-expression fold whose reducer mutates an accumulator. Read lines 320-850 and 992-1010 before supplying a custom reducer. `countof` accepts an actual array, not a pointer. Unselected `choose$` and `typematch$` expressions are not evaluated, but their expanded syntax and types must still be valid where the compiler requires it.

`car$` and `head$` select the first variadic argument; `cdr$` emits all arguments after the first (as a comma-separated token sequence), while `tail$` folds with `cdr$` to select the last argument.

`signedwich` (spelled exactly this way in the header) converts a native integer expression to the corresponding type of opposite signedness. `signed$` and `unsigned$` are the preferred intent-revealing wrappers.

## Cleanup, Allocation, And Pseudo-Objects

| Lines | Area | Main entries |
| --- | --- | --- |
| 1081-1181 | Cleanup attributes and ownership transfer | `smartptr`, `autoinst`, `smartinst`, `autointf`, `smartintf`, `smartfs`, `autofd`, `deinit$`, `delete$`, `$revoke`, `revoke$`, `$eject`, `eject$`, `move` |
| 1183-1214 | Size-summing allocation wrappers | `malloc$`, `calloc$`, `realloc$`, `alloca$` |
| 1216-1274 | Function tables, classes, traits, and interfaces | `fn$`, `$fn`, `mbr$`, `fx$`, `$fx`, `call$`, `class$`, `new$`, `def$`, `trait$`, `invoke$`, `inject$` |

- Cleanup declarations release their value at scope exit. Do not release the same value manually unless ownership was first transferred with `move` or the managed variable was reset.
- `$revoke` and `$eject` perform only the inner release step used by `revoke$` and `eject$`; the suffixed wrappers additionally free the outer interface or vtable allocation and are normally the intended entry points.
- `autoinst` and `smartinst` require the `class$` layout, whose first field is a deinitializer function pointer. They are unsafe for arbitrary objects.
- `autofd` currently has an implementation only on Unix. Initialize it to `-1`, not `0`; cleanup closes every nonnegative descriptor. `move` resets a moved descriptor to `-1` and a moved pointer to `null`.
- `malloc$`, `calloc$`, and nonzero `realloc$` abort on allocation failure. `realloc$ (ptr, 0)` frees `ptr`. `alloca$` only performs saturating size addition before stack allocation; it cannot detect stack exhaustion and should be limited to small, controlled sizes.
- `new$` differs from `malloc$`: allocation or initialization failure returns `null`.

```c
smartptr char *line = gets ();
```

## Coroutines

Lines 1276-1358 provide `coroutine$`, `async$`, `$async`, `$`, `yield$`, `loop$`, `await$`, and `exit$` using GNU computed goto. The default `await$` and its helpers are defined only if `await$` is not already defined, allowing a caller-provided implementation. Inside an `async$` body, `$` expands to the current context object (`(*_CONT_)`), so `$.field` accesses a context member. The `mbr$ (savedpc)` field must start as zero, and `exit$` must appear directly at the end of every coroutine path. `exit$` resets the continuation, so another call restarts the coroutine.

`$async` stores hidden static state (thread-local only when `_REENTRANT` is defined), so one call site cannot represent several independent instances and the non-TLS form is not reentrant. Use `async$ (context)` with caller-owned, zero-initialized state when instances or concurrency matter.

The following example intentionally shows the complete brace structure required by `async$` and `exit$`. Each call yields one Fibonacci number; the first call initializes the state, and later calls resume after `yield$`.

```c
#include "cmacs.h"

coroutine$ (fib_context, {
  u64 a;
  u64 b;
  usz index;
});

u64
fibonacci (struct fib_context *fib_context, usz count) async$ (fib_context)
{
  $.a = 1;
  $.b = 1;
  for ($.index = 0; $.index < count; ++$.index)
    {
      yield$ ($.a);
      u64 next = $.a + $.b;
      $.a = $.b;
      $.b = next;
    }
  exit$ (0);
}

int
main ()
{
  struct fib_context co = { 0 };
  for (;;)
    {
      auto value = fibonacci (&co, 15);
      if (!value)
        break;
      cout (value);
    }
}
```

## Math, Bits, And Capacity

| Lines | Area | Main entries |
| --- | --- | --- |
| 1360-1540 | Integer math and powers | `gcd`, `lcm`, `abs`, `lowbit`, `qpow`, `bitwidth`, `bitfloor`, `bitceil`, `popcount` |
| 1542-1557 | Packed bit access | `bitbyte$`, `bitbit$`, `bitdo$`, `bitget$`, `bitput$`, `bitclear$`, `bitflip$` |
| 1559-1587 | Dynamic-capacity policy | `daexp$`, `dadyn$`, `dalb$`, `daub$`, `dynarr$` |

`dynarr$` computes a suggested capacity; it allocates nothing. The arithmetic macros do not generally check overflow. `qpow` requires a nonnegative exponent and a nonzero modulus when one is supplied. Bitset operations do no bounds checking, and `bitget$` returns a mask rather than a normalized Boolean.

## Storage And Containers

| Lines | Area | Main entries |
| --- | --- | --- |
| 1589-1671 | Resizable binary storage | `struct binstore`/`bsto`, `struct binslice`/`bslc`, `rebin$`, `cstrbin$` |
| 1673-1728 | Intrusive doubly linked list | `struct lsnod`, `list$ (ins)`, `list$ (rem)` |
| 1730-1760 | XOR address pair | `xapr`, `xapr$ (otr/ins/rem)` |
| 1762-1869 | Circular doubly linked XOR list, traversal, and freeing | `xlist$ (ins/rem/unshift/shift/push/pop)`, `xlsfor$`, `xlsfree$` |
| 1871-1882 | Bytewise memory swap | `memswap` |
| 2053-2130 | Generic d-ary heap | `heap$ (siftup/siftdown/heapify)` |
| 2132-2252 | Parent/size-aware splay tree | `bstnod$`, default `struct bstnod`, `bst$ (splay/ins/rem)` |
| 2254-2431 | Hash table with splay-tree buckets | `struct hnod`, `struct htab`, `htab$ ()`, `htab$ (resiz/ins/rem/find)` |

- Most containers are intrusive: embed nodes in caller-owned objects and use `container_of` to recover the object. The library normally does not allocate or free those objects. `xlsfree$` is an exception: it calls `free` on each XOR node, so each node must itself be a valid allocation base.
- Each XOR node stores the XOR of the addresses of its two neighboring `xapr` words; `xapr$ (otr) (node, known_neighbor)` recovers the other neighbor.
- `xlist$` is circular and maintains caller-owned `xapr *first` and `xapr *last` endpoints as the logical wraparound boundary pair. A singleton has itself as both neighbors, and in a two-node ring each node has the other node as both neighbors, so a zero XOR link is valid in both cases and does not mean that the node is detached.
- `xlist$ (ins)` uses a null `prev` or `next` argument to select the logical front or back insertion point; those null values are control inputs and are not stored as neighbors in the circular list.
- `xlsfor$ (var, first, last)` starts with `last` as the preceding node and stops after visiting `last`, traversing one complete logical span from `first` through `last`.
- Pass node-link addresses and addresses of the `first` and `last` endpoint variables to list operations. `xlist$ (rem)` returns the removed node-link address and requires a known neighbor for an interior node.
- XOR lists depend on implementation-defined pointer/integer round trips and are not strictly portable ISO C.
- `memswap` requires two valid, non-overlapping regions.
- Heap operations require `d > 0`, `width > 0`, valid indices and storage, and a comparator matching the elements.
- A hash table's internal bucket count is always a power of two. `htab$ (resiz)` accepts any requested size, clamps it to at least 16, and rounds it up. A zero request frees the table but not its nodes. `htab$ (rem)` requires a node that is currently in that table.
- `rebin$ ()` creates size 4; `rebin$ (size)` creates a store; and `rebin$ (ptr)` is treated as resize-to-zero, which frees `ptr`. Resize an existing store explicitly with `rebin$ (ptr, new_size)`.
- `rebin$`, `cstrbin$`, and `htab$ (resiz)` can fail without freeing the old allocation (except explicit zero-size operations). Assign through a temporary and replace the original pointer only on success.

## Hashing And Strings

| Lines | Area | Main entries |
| --- | --- | --- |
| 1884-1999 | Internal 64-bit A5 hash | use public `memhash` or `strhash` |
| 2001-2051 | Hash wrappers and bounded string copy | `memhash`, `strhash`, `stpscpy` |

`memhash (array)` hashes the complete array, while `memhash (ptr)` hashes only `sizeof *ptr` bytes. Use `memhash (&object, sizeof object[, seed])` or `memhash (ptr, length[, seed])` for explicit data, and `strhash (str[, seed])` for NUL-terminated strings. The same array-versus-pointer size inference applies to one-argument `entropy$`.

`stpscpy (dst, src, dend)` requires non-overlapping source and destination; `dend` is the destination's one-past-end pointer. A nonempty destination is NUL-terminated. The return value points to that NUL on a complete copy and is `null` on truncation or when no destination byte is available.

A5 hash is not a cryptographic hash, password hash, or MAC.

## I/O

| Lines | Area | Main entries |
| --- | --- | --- |
| 2433-2488 | Clang structure dumping and stdio worker selection | `putpacket`, `putp`, `EOL` |
| 2490-2620 | Character, string, and delimited I/O | `getchar`/`getc`, `putchar`/`putc`, `ungetc`/`ungetchar`, `getvs`/`getvstr`, `gets`/`getstr`, `puts`/`putstr`, `peekchar`/`peekc` |
| 2621-2709 | Fast decimal integer I/O and searching | `getdec`/`getd`, `putdec`/`putd`, `getint`/`geti`, `putint`/`puti`, `seekchar`/`seekc`, `seekint`/`seeki` |
| 2711-2765 | Simple line output | `cout`, `cerr` |

- `putpacket` and `putp` exist only under Clang.
- This section may redefine libc names including `getchar`, `getc`, `putchar`, `putc`, `ungetc`, and `puts`. `puts (text)` does not append a newline; `puts ()`, `putc ()`, or `putc (EOL)` emits one.
- `getvs ([delimiter[, psize[, stream]]])` dynamically allocates its result and compares delimiter bytes as unsigned values, so bytes above `0x7f` match consistently when plain `char` is signed. Its default delimiter stops at CR or LF and consumes LF after CR when they form CRLF. EOF can produce an allocated empty string rather than `null`.
- Under GCC, `gets` chooses dynamic delimiter input only when its first argument is compile-time constant; otherwise it selects fixed-buffer input. Use `gets (buffer)` only with an actual array, never a plain pointer. Non-GNU builds do not provide the constant-delimiter dispatch.
- `seekchar` converts byte-sized search values through `unsigned char`, preserving high-bit byte values when plain `char` is signed; wider search values are converted to `int`.
- Decimal input performs no validation or overflow reporting. `cout` and `cerr` accept NUL-terminated strings and integer values suitable for `putdec`; do not pass arbitrary pointers, floating values, or data requiring format control.

## Primes, Time, Entropy, And Randomness

| Lines | Area | Main entries |
| --- | --- | --- |
| 2769-2822 | Miller-Rabin primality test | `isprime` |
| 2824-2981 | CPU/monotonic timing, jitter, and system entropy | `timestamp$`, `cputick$`, `monotime$`, `jitter$`, `entropy$` |
| 2983-3182 | 64-bit Mersenne Twister | `mt$ (seed)`, `mt$ (u64/i64/real/rea/eal/ea)`, `mt19937` |

- `isprime` is intended for integer inputs no wider than 64 bits and is not a deterministic 128-bit primality test. Its deterministic guarantee for 64-bit inputs requires native `__int128`; without it, `u128` falls back to `uintmax_t`, modular squaring may overflow, and 64-bit results are not guaranteed.
- `timestamp$` returns `0` if `clock_gettime` fails; failure is therefore indistinguishable from a legitimate zero timestamp.
- `entropy$ (buffer[, size])` returns `0` on CSPRNG success and `-1` on failure; a failed large request may have modified part of the buffer. Only zero-argument `entropy$ ()` falls back to an in-process pseudo-random mix. Do not treat that fallback as a CSPRNG.
- Seed MT with `mt$ (seed) (seed_value)` or `mt$ (seed) (key_array, key_count)`. Generate values with `mt$ (u64)`, `mt$ (i64)`, `mt$ (real)` (`[0,1]`), `mt$ (rea)` (`[0,1)`), `mt$ (eal)` (`(0,1]`), or `mt$ (ea)` (`(0,1)`). `mt19937 ()` returns `u64`; `mt19937 (u64/i64/real)` accepts only those exact types.
- MT is not cryptographically secure. Its header-defined state is separate in each translation unit and is thread-local only when `_REENTRANT` is defined.

## Implementation Switches

Define these before including `cmacs.h`:

| Macro | Default | Nonzero value |
| --- | --- | --- |
| `SMART_POINTER_IMPL` | Enabled in hosted C; disabled in freestanding C | Omits built-in cleanup functions |
| `A5HASH_IMPL` | Enabled | Omits built-in A5 functions |
| `ENTROPY_IMPL` | Enabled in hosted C; disabled in freestanding C | Omits built-in entropy functions |
| `MERSENNE_TWISTER_64_IMPL` | Enabled | Omits built-in MT64 functions and state |
| `RECURSIVE_REDUCE_MACRO` | Uses the expanded 256-step reduction | Selects recursive rescanning, which may compile more slowly |

`-1` is the conventional disabling value, but the implementation test is simply nonzero. Public wrappers still refer to omitted implementation symbols, so provide compatible declarations and definitions before using them. Leave the switches at their defaults unless controlling code size or supplying an external implementation intentionally.

## Agent Workflow

1. Use this map to identify candidate public entries and source ranges.
2. Read the public macro, called helpers, nearby comments, and platform branch in the active `cmacs.h`.
3. Confirm arguments, result, evaluation count, ownership, failure behavior, and compiler requirements. Do not infer them from the macro name.
4. Compile a minimal GNU C probe for overloaded macros, cleanup, container mutation, I/O redefinitions, coroutines, or platform-dependent behavior.
5. Implement a new facility only after confirming the header lacks it.
6. Recheck line ranges and behavior whenever `cmacs.h` changes.
