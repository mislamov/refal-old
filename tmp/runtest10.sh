cls
cp ../direfal_scaner.rsl .
for i in `ls *.ref`; do echo $i; ./drefgo10.sh $i; done
rm *.xml
sleep 1

