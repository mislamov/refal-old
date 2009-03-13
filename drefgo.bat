@echo off
del  %1.xml
refgo refal_scaner.rsl %1
bin\debug\refal51.exe %1.xml
rem | grep '####:'
pause
exit
