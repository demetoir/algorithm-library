@echo off
set problem=cranksft
set alias=c
set testlib=..\..\testlib
if [%1] == [] (
    call tall as a
    goto quit
)

for /l %%i in (1,1,9) do call t.bat 0%%i %1 %2
for /l %%i in (10,1,99) do call t.bat %%i %1 %2

:quit