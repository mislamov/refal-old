@echo off
del  fn.ref.xml
del  %1.xml
rem refgo refal_scaner.rsl %1
copy ..\refal_scaner.rsl .
..\bin\debug\refal51.exe %1
rem | grep '####:'
del refal_scaner.rsl
pause
gprof ..\bin\debug\refal51.exe > o.txt

exit
