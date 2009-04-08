@echo off
cls
echo "" > %1.xml
del  %1.xml
echo %1
..\bin\debug\refal51.exe %1.
pause

