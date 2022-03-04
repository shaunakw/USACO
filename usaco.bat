@echo off

echo USACO File Generator

if [%1] == [] (
    echo Please choose a location for the files.
) else (
    if [%2] == [] (
        echo Please choose a problem name.
    ) else (
        python generate.py %*
    )
)