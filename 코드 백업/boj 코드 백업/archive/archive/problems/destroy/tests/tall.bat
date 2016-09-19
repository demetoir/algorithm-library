@echo off
dcc32 -cc shuffle.dpr
if [%1] == [] (
    call tall as a
    goto quit
)
if [%2] == [] (
    if [%1] == [as] (
         call tall as a
         goto quit
    )
    if [%1] == [gk] (
         call tall gk b
         goto quit
    )
    if [%1] == [nd] (
         call tall nd d
         goto quit
    )
    if [%1] == [al] (
         call tall al e
         goto quit
    )
    if [%1] == [mb] (
         call tall mb f
         goto quit
    )
)

for /l %%i in (1,1,9) do call t.bat 0%%i %1 %2
for /l %%i in (10,1,99) do call tsh.bat %%i %1 %2

:quit