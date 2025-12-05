# Some notes on this problem

What the `__attribute__((__packed__))`?
This is a GCC compiler-specific attribute used to control the memory layout of structures and unions.
It instructs the compiler to minimize the memory footprint of the declared type by eliminating padding bytes
that would normally be inserted between members for alignment

This is weird at first glance because the `Makefile` is using `clang` rather than `gcc`, but maybe
it's also `clang` compatible.

# The assignment:

Our job is to complete all the functions in the `helpers` file, perhaps reading and trying to understand
and what are the files doing.
