file=$1
while read -r f1 f2 f3 f4
do
if [ $f2 -ge 50 ]&&[ $f3 -ge 50 ]&&[ $f4 -ge 50 ]
then
echo "$f1 PASS"
else
echo "$f1 FAIL"
fi
done<$file