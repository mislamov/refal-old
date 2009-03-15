@echo off
echo "" > %1.xml
del  %1.xml
echo :####:  %1
refgo ..\refal_scaner.rsl %1
..\bin\debug\refal51.exe %1.xml 
exit
