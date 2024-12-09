@echo off
del bin\win_shake.exe
gcc main.c -o bin\win_shake.exe -O3 -mwindows -s -fomit-frame-pointer
@REM win_shake.exe