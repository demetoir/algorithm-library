@echo off
if [%2] == [] (
    call t %1 al a
    goto quit
)
if exist do%1.dpr (
    call dcc32 -cc -M -U%testlib% -I%testlib% do%1.dpr
)
if exist do%1.exe (
    do%1 > %1
)
if exist %1 (
    copy %1 %problem%.in > nul
    ..\%alias%_%2.exe
    copy %problem%.out %1.%3 > nul
    ..\check%alias% %problem%.in %problem%.out %1.a
)
:quit