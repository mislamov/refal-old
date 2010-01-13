
@echo off
cls
echo "" > %1.xml
del  %1.xml
echo %1
..\direfal-010\debug\direfal-010.exe %1.
pause

