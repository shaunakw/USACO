@echo off
title Creating USACO files...

echo.
echo USACO File Generator
echo.

if [%1] == [] goto :noName
if [%2] == [] goto :noLoc
cd %DEVELOPER%\USACO
python create.py %1 %2 %3 %4 %5 %6
goto :exit

:noName
echo Please choose a problem name.
goto :exit

:noLoc
echo Please choose a location for the files.

:exit
echo.