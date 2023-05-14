
echo "input lower bound:"
read a
echo "input upper bound:"
read b
i=$a
echo "the armstrong numbers between $a and $b are:"
while [ $i -le $b ]
do
num=$i
n=$num
power=0
while [ $n -gt 0 ]
do
power=$(($power+1))
n=$(($n/10))
done
n=$num
sum=0
while [ $n -gt 0 ]
do
dig=$(($n%10))
j=0
val=1
while [ $j -lt $power ]
do
val=$(($val*$dig))
j=$(($j+1))
done
sum=$(($sum+$val))
n=$(($n/10))
done
if [ $num -eq $sum ]
then
echo $num
fi
i=$(($i+1))
done