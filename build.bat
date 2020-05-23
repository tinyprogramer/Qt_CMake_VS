@echo off

::delete build dir
if "%1"=="delete" goto _DEL

if not exist build md build

cd build
cmake -A x64 -DCMAKE_CONFIGURATION_TYPES=Release ..
cd ..
goto _END


:_DEL
rd build/s/q
goto _END


:_END