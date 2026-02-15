@echo off
nasm -O3 -f win64 api.asm -o api.obj
gcc -shared api.obj -o ZdfSDK\api.dll -Ofast -static -static-libgcc -s -Wl,--subsystem,windows
g++ zdf.cpp -o ZdfSDK\zdf.exe -Ofast -static -static-libgcc -static-libstdc++ -s
echo Standalone binaries created in ZdfSDK.
pause