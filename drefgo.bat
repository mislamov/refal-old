del  %1.xml
refgo refal_scaner.rsl %1
bin\debug\rm_loader.exe %1.xml | grep ':####'
pause
exit
