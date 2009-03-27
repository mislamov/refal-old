@echo off
del  fn.ref.xml
del  %1.xml
rem refgo refal_scaner.rsl %1
bin\debug\refal51.exe %1
rem | grep '####:'
pause
exit
