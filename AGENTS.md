# Global Constraints

- If a C or C++ project specifies neither a style nor a formatter, use GNU style. Apply the same style to code examples in documentation.
- For C projects that include `cmacs.h`:
  - Read `CODEMAP.md` (may exist at `/usr/local/src/cmacs/CODEMAP.md`) first to locate candidate public APIs.
  - Then inspect the relevant definitions and call context in the active `cmacs.h`. The map is only an index; the header is the source of truth.
  - Prefer existing `cmacs.h` facilities over duplicate implementations.
  - Do not call implementation names such as `_P_*`, `_S_*`, `_C_*`, or module-specific underscore-prefixed names directly unless the task is to modify or analyze the header itself.
