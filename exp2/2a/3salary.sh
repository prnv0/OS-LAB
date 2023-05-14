echo "input basic salary:"
read base
if [ $base -lt 1500 ]
then
hra=$(echo "scale=2; $base*0.1" |bc)
da=$(echo "scale=2; $base*0.9" |bc)
gross=$(echo "scale=2; $base+$hra+$da" |bc)
else
hra=500
da=$(echo "scale=2; $base*0.98" |bc)
gross=$(echo "scale=2; $base+$hra+$da" |bc)
fi
echo "gross salary is":$gross