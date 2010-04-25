@echo off
sh -c "for i in `ls *.ref`; do echo $i; cmd //C drefgo.bat $i; done"
del *.xml
