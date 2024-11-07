## nihil

Nihil is an extremely basic template for Mega Drive development to mix assembly and C in an easy way. It's basically a barebones Mega Drive development environment. It includes a simple linker script, basic startup code and basic VDP functions like resetting, clearing VRAM, CRAM and VSRAM and uploading data to CRAM and VRAM.

### Structure

The runtime process is as follows:

- Low ROM areas like reset vectors and the ROM header are in `lorom.68k`. The initial stack pointer is set to $FFFFE0, error handlers are set to a dummy label that does nothing. Other vectors like traps are not set at all; this is for you to set up and provides extremely barebones startup.

- The entry point is in `sysrt.68k`. This clears Work RAM, tries to omit TMSS in systems that have it and copies the .data region to RAM, for C sources to have non-const initialized variables. Then it jumps to main: There's `main.c` and `main_asm.68k`. You can set the jump to main to the ASM source or the C source, these are just examples that show both ASM and C work.

### Toolchain

Assembler: `vasm-psi-x`, a version of vasm that tries to mimic asm68k's syntax. Essentially like using the old asm68k but can produce ELF objects. This is maintained by NaotoNTP, go check his GitHub.
Compiler: `m68k-elf-gcc`, the GNU C Compiler targeted towards m68k. Maintained by andwn, check his repo as well.

When you have these tools installed, make sure to add them to your PATH. The makefile expects to call them from anywhere.
