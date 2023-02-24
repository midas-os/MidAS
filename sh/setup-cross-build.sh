# Sets up building a cross-compiler.
# More information at: https://wiki.osdev.org/GCC_Cross-Compiler
# This script primarily runs on Linux, Windows users must run in Virtual Machine or WSL

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"
