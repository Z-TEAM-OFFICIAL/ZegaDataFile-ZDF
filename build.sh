#!/bin/bash
echo -e "\e[38;5;82m[ZEGA]\e[0m Starting High-Performance Linux Build..."

# 2. Assemble the Engine Core (NASM)
# We change -f win64 to -f elf64 for Linux compatibility
nasm -O3 -f elf64 api.asm -o api.o

# 3. Link the Shared Object (libapi.so)
# We use -fPIC (Position Independent Code) which is required for Linux .so files
gcc -shared api.o -o ZdfSDK/libapi.so -Ofast -static-libgcc -s

# 4. Compile the Compiler
g++ zdf.cpp -o ZdfSDK/zdf -Ofast -static -static-libgcc -static-libstdc++ -s

echo -e "\e[38;5;82m[ZEGA SUCCESS]\e[0m Linux binaries created in ZdfSDK."