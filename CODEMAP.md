# `cmacs.h` Code Map

## Purpose And Source

- Current source: `cmacs.h` (3392 lines). An installed copy may exist at `/usr/local/include/cmacs.h`; upstream is `https://raw.github.com/ArcanusNEO/cmacs/master/cmacs.h`.
- This is an index for the current header, not an API contract. Line numbers are navigation aids. Always inspect the active header before relying on an argument order, return value, evaluation count, side effect, or ownership rule.
- The header intentionally has no top-level include guard; repeated inclusion in the same translation unit is expected to be idempotent. Local guards and implementation switches prevent duplicate declarations or definitions.
- Use this map when a project already includes `cmacs.h` or explicitly asks for it. Do not introduce the header into otherwise ordinary ISO C code only for convenience.
- Do not call implementation names such as `_P_*`, `_S_*`, `_C_*`, or module-specific underscore-prefixed names directly unless the task is to modify or analyze the header itself.

## Style And Compilation

- Follow the project's formatter or style. Otherwise use GNU C style with two-space indentation, no tabs, and a space before a call's opening parenthesis; use the same style in documentation examples.
- The header primarily targets GCC/Clang GNU C. Use a GNU dialect such as `-std=gnu11` or newer, while noting that `__VA_OPT__` may require a newer compiler mode. It uses statement expressions, `__typeof__`, `__auto_type`, GNU attributes, `__COUNTER__`, and computed goto. Do not assume strict ISO C or MSVC compatibility.
- The header sets the feature-test macros listed in [Types And Environment](#types-and-environment) to `1` only when they are not already defined. Feature-test macros must precede all libc headers to be reliable; define required values in compiler flags or before any system include when extension declarations matter.
- The header defines or remaps `auto`, `null`, `generic`, `atomic`, and `asm`. Treat these as library/compiler extensions, not neutral ISO C spellings. On Windows it also defines `WIN32_LEAN_AND_MEAN`, `NOMINMAX`, and `NOINTERFACE` before including `<windows.h>`; these definitions remain visible to the including translation unit.
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
| 14-37 | Feature-test macros for libc extensions | `_DEFAULT_SOURCE`, `_GNU_SOURCE`, `_BSD_SOURCE`, `_NETBSD_SOURCE`, `_OPENBSD_SOURCE`, `_DARWIN_C_SOURCE`, `_ALL_SOURCE`, `_TANDEM_SOURCE` |
| 39-119 | Hosted/freestanding headers and Unix/Windows selection | `macro$ (PLATFORM)`, `macro$ (UNIX)`, `macro$ (WINDOWS)`, `macro$ (UNKNOWN)` |
| 121-175 | Keyword remaps and integer, pointer, size, character, and floating aliases | `asm`, `null`, `n1ll`, `auto`, `generic`, `atomic`, `byte`, `word`, `i8/u8` through `i128/u128`, `iptr/uptr`, `isz/usz`, `c8/c16/c32`, `real`, `f16/f32/f64/f128`, `isto/usto/fsto` |
| 177-308 | Compile-time failure, naming helpers, and prime constants | `todo$`, `macro$`, `static$`, `const$`, `const$ (p2)` through `const$ (p64)`, `const$ (tp3)` through `const$ (tp64)` |

Use `usz` for sizes and indices, `isz` for signed differences, and note that `real` is `double`. `i128/u128` and `f16/f128` fall back when unsupported, so their advertised width is not unconditional. `c8/c16/c32` are least-width integer types.

## Macro And Expression Utilities

| Lines | Area | Main entries |
| --- | --- | --- |
| 310-342 | Stringification, concatenation, unique names, parentheses, rescanning | `quote$`, `cat$`, `uniq$`, `lparen$`, `rparen$`, `lbrace$`, `rbrace$`, `paren$`, `unparen$`, `scan$` |
| 344-879 | Variadic macro reduction and list access | `$reduce`, `car$`, `cdr$`, `head$`, `tail$` |
| 881-998 | Type inference and compile-time/type selection | `typeof`, `signedof`, `signedwich`, `signed$`, `unsigned$`, `empty$`, `count$`, `typewarn$`, `ice$`, `ace$`, `choose$`, `umax$`, `umin$`, `likely`, `unlikely`, `typematch$`, `countof`, `ipe$`, `ape$` |
| 925-933 | Pointer and packet layout conversion | `offsetof`, `container_of`, `packetof`, `dataof` |
| 1000-1111 | Unreachable code, attributes, runtime reduction, arithmetic, swap, lambdas, scoped loops | `unreachable$`, `unrch$`, `dense$`, `inline$`, `pure$`, `unused$`, `defer$`, `weak$`, `sum$`, `prod$`, `reduce$`, `max`, `min`, `swap`, `lambda`, `with$` |

`$reduce` is a preprocessor fold; `reduce$` is a statement-expression fold whose reducer mutates an accumulator. Read lines 344-879 and 1022-1040 before supplying a custom reducer. `countof` accepts an actual array, not a pointer. Unselected `choose$` and `typematch$` expressions are not evaluated, but their expanded syntax and types must still be valid where the compiler requires it.

`unreachable$ ()` and the argument-less `unrch$` both expand to `__builtin_unreachable ()`, telling the compiler that control flow cannot reach that point.

`n1ll` is `((void *)-1)`, a sentinel pointer distinct from `null`.

`car$` and `head$` select the first variadic argument; `cdr$` emits all arguments after the first (as a comma-separated token sequence), while `tail$` folds with `cdr$` to select the last argument.

`signedwich` (spelled exactly this way in the header) converts a native integer expression to the corresponding type of opposite signedness. `signed$` and `unsigned$` are the preferred intent-revealing wrappers.

`lparen$`/`rparen$` and `lbrace$`/`rbrace$` expand to literal parentheses and braces respectively.

`lambda` uses GCC nested-function syntax; Clang does not support this facility.

## Cleanup, Allocation, And Pseudo-Objects

| Lines | Area | Main entries |
| --- | --- | --- |
| 1113-1213 | Cleanup attributes and ownership transfer | `smartptr`, `autoinst`, `smartinst`, `autointf`, `smartintf`, `smartfs`, `autofd`, `deinit$`, `delete$`, `$revoke`, `revoke$`, `$eject`, `eject$`, `move` |
| 1215-1246 | Size-summing allocation wrappers | `malloc$`, `calloc$`, `realloc$`, `alloca$` |
| 1248-1306 | Function tables, classes, traits, and interfaces | `fn$`, `$fn`, `mbr$`, `fx$`, `$fx`, `call$`, `class$`, `new$`, `def$`, `trait$`, `invoke$`, `inject$` |

- Cleanup declarations release their value at scope exit. Do not release the same value manually unless ownership was first transferred with `move` or the managed variable was reset.
- `$revoke` and `$eject` perform only the inner release step used by `revoke$` and `eject$`; the suffixed wrappers additionally free the outer interface or vtable allocation.
- `class$ (name[, { fields }])` defines `struct name` whose first member is the deinitializer pointer `fx$ (deinit)`; `trait$ (name[, { fields }])` defines one whose first member is `void *mbr$ (instance)`. The optional fields argument is a braced member list such as `{ int x, y; }`, omitting it leaves only the first member.
- `autoinst` and `smartinst` require the `class$` layout, whose first field is a deinitializer function pointer. They are unsafe for arbitrary objects.
- `autofd` currently has an implementation only on Unix. Initialize it to `-1`, not `0`; cleanup closes every nonnegative descriptor. `move` resets a moved descriptor to `-1` and a moved pointer to `null`.
- `malloc$`, `calloc$`, and nonzero `realloc$` abort on allocation failure. `realloc$ (ptr, 0)` frees `ptr`. `alloca$` only performs saturating size addition before stack allocation; it cannot detect stack exhaustion.
- `new$` differs from `malloc$`: allocation or initialization failure returns `null`.

```c
smartptr char *line = gets ();
```

## Math, Bits, And Capacity

| Lines | Area | Main entries |
| --- | --- | --- |
| 1308-1490 | Integer math and powers | `gcd`, `lcm`, `abs`, `lowbit`, `qpow`, `bitwidth`, `bitfloor`, `bitceil`, `popcount` |
| 1492-1507 | Packed bit access | `bitbyte$`, `bitbit$`, `bitdo$`, `bitget$`, `bitput$`, `bitclear$`, `bitflip$` |
| 1509-1537 | Dynamic-capacity policy | `daexp$`, `dadyn$`, `dalb$`, `daub$`, `dynarr$` |

`dynarr$` computes a suggested capacity; it allocates nothing. The arithmetic macros do not generally check overflow. `qpow` requires a nonnegative exponent and a nonzero modulus when one is supplied. Bitset operations do no bounds checking, and `bitget$` returns a mask rather than a normalized Boolean.

## Storage And Containers

| Lines | Area | Main entries |
| --- | --- | --- |
| 1539-1556 | Resource descriptor | `struct descriptor` |
| 1558-1635 | Resizable binary storage | `struct binstore`/`bsto`, `rebin$`, `cstrbin$` |
| 1637-1692 | Intrusive doubly linked list | `struct lsnod`, `list$ (ins)`, `list$ (rem)` |
| 1694-1724 | XOR address pair | `xapr`, `xapr$ (otr/ins/rem)` |
| 1726-1833 | Circular doubly linked XOR list, traversal, and freeing | `xlist$ (ins/rem/unshift/shift/push/pop)`, `xlsfor$`, `xlsfree$` |
| 1835-1846 | Bytewise memory swap | `memswap` |
| 2017-2095 | Generic d-ary heap | `heap$ (siftup/siftdown/heapify)` |
| 2097-2213 | Parent/size-aware splay tree | `bstnod$`, default `struct bstnod`, `bst$ (splay/ins/rem)` |
| 2215-2392 | Hash table with splay-tree buckets | `struct hnod`, `struct htab`, `htab$ ()`, `htab$ (resiz/ins/rem/find)` |

- `struct descriptor` contains two independent anonymous unions: the first holds `isto ident`, `usto uset`, or `void *entry`; the second holds `isto iset`, `usto attr`, or `void *prop`. The first field typically refers to objects, and the second to attributes. This layout can implement a wide pointer (for example, `.entry` paired with a length in `.attr` or metadata in `.prop`) or a simplified pair of integer or pointer values.
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
| 1848-1965 | Internal 64-bit A5 hash | use public `memhash` or `strhash` |
| 1967-2015 | Hash wrappers and bounded string copy | `memhash`, `strhash`, `stpscpy` |

`memhash (array)` hashes the complete array, while `memhash (ptr)` hashes only `sizeof *ptr` bytes. Use `memhash (&object, sizeof object[, seed])` or `memhash (ptr, length[, seed])` for explicit data, and `strhash (str[, seed])` for NUL-terminated strings. The same array-versus-pointer size inference applies to one-argument `entropy$`.

`stpscpy (dst, src, dend)` requires non-overlapping source and destination; `dend` is the destination's one-past-end pointer. A nonempty destination is NUL-terminated. The return value points to that NUL on a complete copy and is `null` on truncation or when no destination byte is available.

A5 hash is not a cryptographic hash, password hash, or MAC.

## Coroutines

Lines 2394-2641 implement stackless, cooperatively driven coroutines with GNU computed goto. Each `async$` call starts or resumes execution from a label saved in its context; it does not preserve a C stack frame or provide a scheduler. The module has no header-defined state; all state lives in caller-owned contexts. Zero-initialize a context before its first call (a `coroutine$` context also needs `.mbr$ (super).bindedfp` set to its own coroutine function), keep it alive while suspended, and resume it through the same coroutine function.

The saved resume point `savedpc` encodes the lifecycle: `null` means not started, a label address means suspended, and `n1ll` (`(void *)-1`) means finished. Calling a finished context again jumps straight to the epilogue emitted by `return$` or `reset$`. A `coroutine$` context is additionally *rejected* when `bindedfp` is `null`. This is how failure travels: `reject$` and `coreject$` clear `bindedfp`, and `await$` and `batch$` propagate a rejected child to its parent.

| Entry | Role and control flow |
| --- | --- |
| `continuation$ (name[, { fields }])` | Defines a context with a saved resume address and the optional braced user fields; suitable for directly driven generators. |
| `coroutine$ (type, name[, { fields }])` | Defines a context with `struct corosuperblk`, a typed `result$` field, and the optional braced user fields for nested coroutines. A `void` result type yields a 1-byte `byte` placeholder field. |
| `async$ (kont)` and `$` | Enter or resume the context; `$` aliases the current context object, so `$.field` accesses persistent state. |
| `yield$ ([value])` | Save the next resume point and return the supplied value to the immediate caller. |
| `loop$ ([value])` | Clear the resume point and return the supplied value; the next call starts at the beginning, without resetting user fields. |
| `await$ (receiver, child, ...)` | Allocate and initialize a child context, expose it through `kont`, and yield `0`. After the parent is resumed, apply `receiver` to the child's result only if the child was not rejected, then free the child. A rejected child (`bindedfp == null`) sets the parent's `bindedfp` to `null` instead, and the parent then jumps to its epilogue and propagates the rejection to its own caller. If the parent is already rejected when it reaches `await$`, it jumps to the epilogue without allocating. Allocation failure returns `ENOMEM`. |
| `batch$ ((receiver, child, ...), ...)` | Allocate every listed child in one block, chain them through `kont`, and yield `ECHILD`. Each resume yields `EINPROGRESS` until the last child finishes; then apply each non-rejected child's `receiver` in argument order, mark the parent rejected if any child was rejected, free the block, and jump to the epilogue if the parent is rejected. If the parent is already rejected when it reaches `batch$`, it jumps to the epilogue without allocating. If the scheduler rejects the parent right after `ECHILD`, before any child has run, the parent resumes, frees the whole block without applying any `receiver`, and jumps to the epilogue. Allocation failure returns `ENOMEM`. |
| `coalloc$ (size)` / `cofree$ (ptr)` | Allocate and free the child contexts of `await$` and `batch$`. They default to `malloc` and `free` and are defined only if not already defined, so a project can supply its own pair before including the header. |
| `coreject$ (kont)` | Scheduler-side hook that rejects a context. It clears the context's `bindedfp`, marks `savedpc` as `n1ll` if the context never started, and returns the old `bindedfp`. The caller must then drive the context once more through the returned pointer so it runs its epilogue and hands control back through `kont`; a `null` result means there is nothing to drive. It is defined only if not already defined, and the header itself never calls it. |
| `resolve$ ([value])` | Finish a nested coroutine successfully, from anywhere in its body: mark it finished, set `kont` to its caller, optionally store `value` in `result$`, and jump to the epilogue emitted by `reset$`. |
| `reject$ ([statement])` | Finish a nested coroutine as failed, from anywhere in its body: mark it finished, clear `bindedfp`, set `kont` to its caller, run the optional statement (for example to record an error code), and jump to the epilogue. |
| `unwind$ ([label])` | `goto` the given label, or the epilogue when none is given. |
| `reset$ ([statement])` | Closes the body of a nested coroutine at its normal end. It defines the epilogue shared by `resolve$`, `reject$`, `unwind$`, and the `await$`/`batch$` failure paths: mark the context finished, set `kont` to its caller, run the optional statement, and return `0`. |
| `return$ ([value])` | Closes the body of a standalone `continuation$` coroutine, or of any coroutine that returns a value directly, at its normal end. It defines the epilogue, marks the context finished, and returns `value`. |

- The optional fields argument is a braced member list such as `{ u64 a, b; }`. Omitting it defines a context with only the header-defined members.
- Put every value needed across a suspension in context fields (`$.field`), not in automatic local variables.
- Do not suspend within the scope of a variable with a cleanup attribute, such as `smartptr`, `autofd`, `autoinst`, `defer$`, or `with$`. The `return` inside `yield$`, `await$`, or `batch$` runs the cleanup, and the resumed code later runs it again on an uninitialized variable.
- Do not suspend inside a statement expression or within the scope of a variable-length array; jumping into either with computed goto is undefined behavior.
- `return$` and `reset$` close the body block that follows `async$` and define the epilogue label, so each body contains exactly one of them, and neither can finish a coroutine in the middle of the body. Use `resolve$`, `reject$`, or `unwind$` there; all three jump to the epilogue. The normal flow of a `coroutine$` body ends with `reset$`; that of a `continuation$` body, or of a coroutine that returns a value directly, ends with `return$`. They need not be the last statement of the function: labelled cleanup code may follow, reached only by `goto` from earlier in the body. It can use `$`, because it is still inside the block opened by `async$`, but it is outside the braces of the body, so automatic locals of the body are out of scope.
- Completion is recorded. Once a coroutine reaches its epilogue, `savedpc` is `n1ll`, and calling the function again does not restart the body: `async$` jumps straight to the epilogue, which re-evaluates the `return$` expression or returns `0` again for `reset$`.
- `resolve$`, `reject$`, `reset$`, `await$`, and `batch$` access the `super` members, so they require a `coroutine$` context; a `continuation$` context supports only `yield$`, `loop$`, `return$`, and `unwind$`.
- A context whose `bindedfp` is `null` is rejected. `await$` and `batch$` test this every time they resume and jump to the epilogue, except when resuming from a suspension that returned `EINPROGRESS`: that point never checks the rejected state, and a context that returned `EINPROGRESS` must not be rejected. Code after a plain `yield$` does not test either, so a coroutine that can be rejected while suspended there must test `$.mbr$ (super).bindedfp` itself, or call `unwind$`.
- `yield$ ()`, `loop$ ()`, and `return$ ()` without a value expand to `return;` and are valid only in a `void` function.

### Standalone generator

A `continuation$` generator can be driven by repeatedly calling its function. In this Fibonacci example, each yielded descriptor contains a value in `.uset` with `.iset == 0`; `.iset == 1` marks completion:

```c
#include "cmacs.h"

continuation$ (context, {
  u64 a, b;
  usz index;
});

struct descriptor
fibonacci (struct context *context, usz count) async$ (context)
{
  $.a = 0;
  $.b = 1;
  for ($.index = 0; $.index < count; ++$.index)
    {
      yield$ ((struct descriptor){ .uset = $.a, .iset = 0 });
      u64 next = $.a + $.b;
      $.a = $.b;
      $.b = next;
    }
  return$ ((struct descriptor){ .iset = 1 });
}

int
main (int argc, char *argv[])
{
  struct context co = { 0 };
  for (;;)
    {
      auto ret = fibonacci (&co, 15);
      if (ret.iset)
        break;
      cout (ret.uset);
    }
}
```

### Nested coroutines and dispatch

A nested coroutine is a function `int name (void *)` whose name matches the tag of its `coroutine$` context, because `await$` and `batch$` use `child` both as `struct child` and as the `bindedfp` value. A caller-provided scheduler advances one context per `bindedfp` call and is expected to handle the return values listed in the table:

| Return | Meaning | Scheduler action |
| --- | --- | --- |
| `0` | `kont` is the next context: the child after `await$`, the caller after `resolve$`, `reject$`, or the `reset$` epilogue, or a context assigned before a manual `yield$`. | Run `kont` immediately or insert it at the front of the queue; a null `kont` ends the hand-off. |
| `ECHILD` | `batch$` created its children. The parent's `kont` points to the first child, each child's `kont` to the next, and the last child's `kont` is null. | Each child may be accepted or rejected independently, and the parent may instead be rejected as a whole. First walk the `kont` chain and collect every child before scheduling or rejecting any of them, because driving a child overwrites its own `kont`. To accept a child, schedule it. To reject a child, `coreject$` it and drive the returned function pointer; it hands control back to the parent through `kont`, and the parent is marked rejected once every child has finished. To reject the parent instead, `coreject$` it and drive the returned function pointer before any child runs: the parent resumes after `yield$ (ECHILD)`, sees `bindedfp == null`, frees the whole child block without running any child, and hands the rejection to its caller. |
| `EINPROGRESS` | The coroutine has nothing to hand off and must not be driven further by this call. A parent waiting in `batch$` yields it each time it is resumed while children are still pending; any other coroutine may also return it, for example a statically allocated root cleanup coroutine that has finished its work. | Ignore or discard the coroutine: do not requeue, drive, or reject it, because a coroutine does not check its rejected state when it returns this code. For a `batch$` parent this is also required by ownership: the parent owns the lifetime of the child block, each child resumes it exactly once by finishing, and every resume counts one finished child. A rejected child does not cancel the wait; the parent is marked rejected only after every child has finished. |
| `ENOMEM` | Allocation failed. The parent's resume point is still the allocation. | Call the parent again to retry, or reject it with `coreject$` and drive the returned function pointer: the parent resumes at the allocation, sees `bindedfp == null`, runs its epilogue, and hands the rejection to its caller. |
| `ETIMEDOUT` | The coroutine requests a timer. `srq` points to the timer parameters. | Read `srq`, arm the timer, and resume the context when it expires. |
| `EIO` | The coroutine requests asynchronous I/O. `srq` points to the request. | Read `srq`, submit the request, and resume the context when it completes. |

- Rejection is only legal where the rejected context owns nothing that is still running. The scheduler may reject the context that returned `ENOMEM`; the parent that just returned `ECHILD`, provided none of its children has been scheduled or run; or any of the children of one `ECHILD` batch, all or only some of them, each before it has run. It must then drive the pointer returned by `coreject$`. It must not reject a coroutine that returned `EINPROGRESS`, because such a coroutine is ignored or discarded and never checks its rejected state, nor a parent of an `ECHILD` batch once any child has run, because that parent owns the lifetime of its children.
- Never append the `kont` received with `0` to the back of the queue. The children of one `batch$` share a parent, so a second child can finish and append the parent again while it is still queued; inserting the same `lentry` twice corrupts the `xlist$` structure.
- In `await$ (receiver, child, ...)`, the trailing arguments initialize the child's user fields in declaration order or through designators such as `.n = 3`; the child's `result$` starts at zero. `receiver` is a prefix applied to the parenthesized result, such as `func`, `$.result$ +=`, or `(void)`.
- Each `batch$` argument is a parenthesized `await$` argument list, for example `batch$ (($.a =, f, 1), ($.b *=, g))`. All children are initialized in argument order before any of them runs, so no argument can use an earlier child's result.
- `batch$` stores a pending counter and the children back to back in one allocation. This relies on context sizes being multiples of `alignof (max_align_t)`, so children whose fields require stricter alignment may not be supported.
- A coroutine can pass optional parameters to the scheduler through `srq`. The header never sets or reads `srq` and none of its macros return `ETIMEDOUT` or `EIO`; the scheduler defines the format of the request and how results are returned.
- `srq`, `ident`, and `lentry` in `struct corosuperblk` are three views of one storage slot of equal width and alignment: a scheduling request pointer, a signed identity field, and an unsigned `xlist$` link word. The header never sets or reads that slot.
- `kont`, `error`, and `mark` in `struct corosuperblk` are likewise three views of one storage slot of equal width and alignment. The header accesses that slot only as `kont`; `error` and `mark` are integer views for scheduler bookkeeping and are never set or read by the header.
- The two scheduling slots are consecutive anonymous unions of `struct corosuperblk`. The zero-length array `byte schedex[0]` immediately precedes them at the first slot's offset, so `schedex` decays to a pointer to the start of the exchange area. The usable size is `sizeof (struct corosuperblk) - offsetof (struct corosuperblk, schedex)`, comprising the two slots (`2 * sizeof (void *)` bytes) followed by tail padding created by the struct's `alignas (max_align_t)` alignment. On a 64-bit target with 16-byte `max_align_t` that extent is 24 bytes (16 slot bytes plus 8 padding bytes); with 8-byte `max_align_t` it is exactly `2 * sizeof (void *)`. The header itself never reads or writes the area.
- `yield$` and `loop$` do not change `kont`. Before `yield$ (0);`, assign `$.mbr$ (super).kont` to the context that should run next, such as `&$` to resume the current one.
- A replacement `coalloc$` must return a null pointer on failure, which `await$` and `batch$` report as `ENOMEM`, and memory aligned for `max_align_t`, which `batch$` relies on. `cofree$` must release exactly what `coalloc$` returned; `batch$` passes it the start of the whole block, not a child address.
- `await$` and `batch$` use `coalloc$`, `cofree$`, `memcpy`, `ENOMEM`, `ECHILD`, and `EINPROGRESS`. The default allocator and these declarations come from headers that `cmacs.h` includes only in hosted mode; in freestanding mode, define `coalloc$` and `cofree$` and provide `memcpy` and the error codes.

The following Fibonacci example drives `batch$` with an `xlist$` queue:

```c
#include "cmacs.h"

coroutine$ (u64, fibonacci, { u64 n; });
int
fibonacci (void *kf) async$ ((struct fibonacci *)kf)
{
  if ($.n <= 1)
    resolve$ ($.n);
  /* await$ ($.result$ +=, fibonacci, $.n - 1); */
  /* await$ ($.result$ +=, fibonacci, $.n - 2); */
  batch$ (($.result$ +=, fibonacci, $.n - 1),
          ($.result$ +=, fibonacci, $.n - 2));
  reset$ ();
}

int
main (int argc, char *argv[])
{
  struct fibonacci root = { .mbr$ (super).bindedfp = fibonacci, .n = 15 };
  struct descriptor q = { 0 };
  xlist$ (push) (&root.mbr$ (super).lentry, &q.entry, &q.prop);
  while (q.entry)
    {
      xapr *nd = xlist$ (shift) (&q.entry, &q.prop);
      auto k = container_of (nd, struct corosuperblk, lentry);
      int (*f) (void *) = k->bindedfp;
      while (f && k)
        switch (f (k))
          {
          case ENOMEM:;
            f = coreject$ (k);
            break;
          case 0:;
            if ((k = k->kont))
              f = k->bindedfp;
            break;
          case EINPROGRESS:;
            k = null;
            break;
          case ECHILD:;
            while ((k = k->kont))
              xlist$ (push) (&k->lentry, &q.entry, &q.prop);
            break;
          case EIO:;
            f = coreject$ (k); /* TODO */
            break;
          case ETIMEDOUT:;
            f = coreject$ (k); /* TODO */
            break;
          }
    }
  cout (root.result$);
}
```

## I/O

| Lines | Area | Main entries |
| --- | --- | --- |
| 2643-2691 | Clang structure dumping and stdio worker selection | `putpacket`, `putp`, `EOL` |
| 2693-2818 | Character, string, and delimited I/O | `getchar`/`getc`, `putchar`/`putc`, `ungetc`/`ungetchar`, `getvs`/`getvstr`, `gets`/`getstr`, `puts`/`putstr`, `peekchar`/`peekc` |
| 2820-2908 | Fast decimal integer I/O and searching | `getdec`/`getd`, `putdec`/`putd`, `getint`/`geti`, `putint`/`puti`, `seekchar`/`seekc`, `seekint`/`seeki` |
| 2910-2966 | Simple line output | `cout`, `cerr` |

- `putpacket` and `putp` exist only under Clang.
- This section may redefine libc names including `getchar`, `getc`, `putchar`, `putc`, `ungetc`, and `puts`. `EOL` defaults to `10` unless defined before inclusion. `puts (text)` does not append a newline; `puts ()` emits a newline through libc `puts`, while `putc ()` or `putc (EOL)` emits `EOL`.
- `getvs ([delimiter[, psize[, stream]]])` dynamically allocates its result and compares delimiter bytes as unsigned values. Its default delimiter stops at CR or LF and consumes LF after CR when they form CRLF. EOF can produce an allocated empty string rather than `null`.
- When `__GNUC__` is defined (including in Clang's GNU-compatible modes), `gets` with arguments selects dynamic delimiter input if `__builtin_constant_p` recognizes its first argument as constant; otherwise it selects fixed-buffer input. Without `__GNUC__`, calls with arguments use fixed-buffer input. Zero-argument `gets ()` uses dynamic input in either branch. Use `gets (buffer)` only with an actual array, never a plain pointer.
- `seekchar` converts byte-sized search values through `unsigned char`, preserving high-bit byte values when plain `char` is signed; wider search values are converted to `int`.
- Decimal input performs no validation or overflow reporting. `cout` and `cerr` accept NUL-terminated strings and integer values suitable for `putdec`; do not pass arbitrary pointers, floating values, or data requiring format control.

## Primes, Time, Entropy, And Randomness

| Lines | Area | Main entries |
| --- | --- | --- |
| 2968-3021 | Miller-Rabin primality test | `isprime` |
| 3023-3185 | CPU/monotonic timing, jitter, and system entropy | `timestamp$`, `cputick$`, `monotime$`, `jitter$`, `entropy$` |
| 3193-3392 | 64-bit Mersenne Twister | `mt$ (seed)`, `mt$ ()`, `mt$ (u64/i64/real/rea/eal/ea)`, `mt19937` |

- `isprime` is intended for integer inputs no wider than 64 bits and is not a deterministic 128-bit primality test. Its deterministic guarantee for 64-bit inputs requires native `__int128`; without it, `u128` falls back to `uintmax_t`, modular squaring may overflow, and 64-bit results are not guaranteed.
- `timestamp$` returns `0` if `clock_gettime` fails; failure is therefore indistinguishable from a legitimate zero timestamp.
- `entropy$ (buffer[, size])` returns `0` on CSPRNG success and `-1` on failure; a failed large request may have modified part of the buffer. Only zero-argument `entropy$ ()` falls back to an in-process pseudo-random mix. Do not treat that fallback as a CSPRNG.
- Seed MT with `mt$ (seed) (seed_value)` or `mt$ (seed) (key_array, key_count)` using a nonempty `u64` key array. Generate values with `mt$ ()` or `mt$ (u64)` (`[0,2^64)`), `mt$ (i64)` (`[0,2^63)`), `mt$ (real)` (`[0,1]`), `mt$ (rea)` (`[0,1)`), `mt$ (eal)` (`(0,1]`), or `mt$ (ea)` (`(0,1)`). `mt19937 ()` returns `u64`; `mt19937 (u64/i64/real)` selects by type compatibility, with `mt19937 (real)` using `[0,1)` like `mt$ (rea)`. Other types yield a `void` expression.
- MT is not cryptographically secure. Its header-defined state is separate in each translation unit and is thread-local only when `_REENTRANT` is defined.

## Processor Count

Lines 3187-3191 provide `nproc$ ()`, which queries the online logical processor count with `sysconf (_SC_NPROCESSORS_ONLN)` on Unix or the active logical processor count across all processor groups with `GetActiveProcessorCount (ALL_PROCESSOR_GROUPS)` on Windows. The result is clamped to at least `1`, including when the system query fails. This is a system processor count, not a count restricted by the calling thread's CPU affinity. The macro is defined only for the Unix and Windows platform branches.

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

## Recommended Workflow

1. Use this map to identify candidate public entries and source ranges.
2. Read the public macro, called helpers, nearby comments, and platform branch in the active `cmacs.h`.
3. Confirm arguments, result, evaluation count, ownership, failure behavior, and compiler requirements. Do not infer them from the macro name.
4. Compile a minimal GNU C probe for macro-related behavior.
5. Implement a new facility only after confirming the header lacks it.
6. Recheck line ranges and behavior whenever `cmacs.h` changes.
