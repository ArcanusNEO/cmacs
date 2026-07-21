<h1 align="center"><strong>CMACS</strong></h1>

**Clang MACroS** is a single-header toolbox of C metaprogramming
macros, data structures, and algorithms for GCC/Clang.

```c
#include "cmacs.h"
int
main ()
{
  cout ("Hello, world!");
}
```

## Requirements

1. **GCC or Clang** (relies on `__typeof__`, statement expressions,
  `__attribute__`, `__builtin_*`, computed goto, `__int128`, etc.)
2. **C11 or later**
3. (Optional) Build with `-fwrapv -fms-extensions` for better user
  experience

## What's inside

#### Metaprogramming

variadic `reduce$`/`$reduce`, `typeof`/`choose$`/`typematch$`,
`sum$`/`prod$`, `max`/`min`...

#### Memory & objects
   
checked `malloc$`/`calloc$`/`realloc$` (abort on OOM), scope guard
(`with$`), cleanup-based `defer$`, `smartptr`, a pseudo class system
(`class$`, `new$`, `call$`), traits/vtables, computed-goto coroutines
(`async$`/`$async`, `yield$`, `await$`)...

#### Data structures

dynamic-array growth policy (`dynarr$`), binary store (`bsto`), doubly
& XOR linked lists, bitset, d-ary heap, splay tree, splay-bucketed
hash table...

#### Algorithms & numerics

`gcd`/`lcm`, `abs`, `qpow`, `bitceil`, `memhash`/`strhash`,
Miller-Rabin `isprime`...

#### Randomness

OS-CSPRNG-based (`getentropy`/`/dev/urandom`/`BCryptGenRandom`)
`entropy$`, Mersenne Twister (`mt$`, `mt19937`) auto-seeds from
`entropy$`...

#### I/O

unlocked stdio wrappers, fast decimal `getdec`/`putdec`, safe line
reader `gets`, and Python-style `cout`/`cerr`...

## Conventions

1. Public macros name with `$` (`list$`, `$revoke`) or are common
  names (`swap`, `countof`), `_*_` prefixes/suffixes are reserved for
  implementation details (which may or may not be used)
2. Header-defined `static` state (Mersenne Twister, `$async`, etc.) is
  per translation unit, define `_REENTRANT` for thread-local state

## License

BSD 0-Clause, see [LICENSE](LICENSE).
