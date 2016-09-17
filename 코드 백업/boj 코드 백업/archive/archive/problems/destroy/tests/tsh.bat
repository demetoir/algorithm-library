@echo off
if [%2] == [] (
    call t %1 as a
    goto quit
)
if exist gen%1.dpr (
    dcc32 -cc gen%1.dpr
)
if exist gen%1.exe (
    gen%1 | shuffle > %1
)
if exist %1 (
    copy %1 destroy.in > nul
    run -t 2s ../d_%2.exe
    if not [%3] == [] (
        copy destroy.out %1.%3 > nul
    )
    ..\checkd destroy.in destroy.out %1.a
)
:quit