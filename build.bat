@echo off
REM devenv laund debugger
REM devenv /NoSplash /Run msvc/BabyMath.sln

REM MSVC DEBUG BUILD
MSBuild msvc/main.vcxproj -t:Rebuild -p:Configuration=Debug -nologo -maxCpuCount -verbosity:quiet

