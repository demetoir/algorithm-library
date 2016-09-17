@echo off
for /l %%i in (1,1,9) do call t.bat 0%%i
for /l %%i in (10,1,99) do call t.bat %%i
