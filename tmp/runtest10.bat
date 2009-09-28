@echo off
copy D:\d-refal\direfal-010\direfal_scaner.rsl
sh -c "for i in `ls *.ref`; do echo $i; cmd //C drefgo10.bat $i; done"
del *.xml
