<h1 align="center"><strong>CMACS</strong></h1>

**Clang MACroS** is a single-header C toolbox for GNU-style metaprogramming, resource management, data structures, algorithms, I/O, hashing, entropy, and pseudo-random number generation.

```c
#include "cmacs.h"

int
main ()
{
  cout ("Hello, world!");
}
```

## Requirements

- GCC or Clang with the GNU extensions used by `cmacs.h`, including `__typeof__`, statement expressions, attributes, built-ins, `__VA_OPT__`, and computed goto.
- A GNU C mode such as `-std=gnu11` or newer; support for individual facilities still depends on the compiler and target.
- `-fwrapv -fms-extensions` is optional but improves compatibility with some macros.

## Contents

- Metaprogramming and type utilities, including variadic reduction, compile-time selection, type matching, arithmetic helpers, and scope guards.
- Cleanup-based resource management, checked allocation wrappers, pseudo-classes and traits, and computed-goto coroutines.
- Bitsets, resizable binary storage, intrusive linked lists, d-ary heaps, splay trees, and hash tables.
- Integer and bit algorithms, A5 hashing, Miller-Rabin primality testing, system entropy, and a 64-bit Mersenne Twister.
- Convenience I/O wrappers for characters, strings, decimal integers, and simple line output.

Most public macros either contain `$` or use familiar names such as `swap` and `countof`. Names with implementation prefixes or underscore-delimited forms are internal unless the documentation explicitly says otherwise. Header-defined state, including Mersenne Twister and `$async` state, is per translation unit and becomes thread-local only when `_REENTRANT` is defined.

## Documentation

- [AGENTS.md](AGENTS.md) defines repository guidance for AI coding agents, including style rules and how to use the library documentation safely.
- [CODEMAP.md](CODEMAP.md) indexes the public facilities in `cmacs.h` and records important compiler, ownership, failure, and portability constraints. It is a navigation aid; `cmacs.h` remains the source of truth.

## License

Original CMACS code is licensed under BSD 0-Clause. `cmacs.h` includes third-party components under MIT and BSD 3-Clause; their license notices are retained in the source.

See [LICENSE](LICENSE) and `cmacs.h` for details.
