@echo off
del win_shake.exe
gcc main.c -o "win_shake.exe" -O3 -mwindows -s -fomit-frame-pointer
@REM win_shake.exe