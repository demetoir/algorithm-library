@echo off
if exist gen%1.dpr (
    dcc32 -cc gen%1.dpr
)
if exist gen%1.exe (
    gen%1 > %1
)
if exist %1 (
    copy %1 highways.in > nul
    ..\h_as
    copy highways.out %1.a > nul
    ..\checkh %1 highways.out %1.a
)