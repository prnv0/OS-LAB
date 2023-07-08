echo "input n:"
read n
num=$(($n+1))
flag=1
while [ $flag -ne 0 ]
do
i=2
prime=1
while [ $i -lt $num ]
do
rem=$(($num%$i))
if [ $rem -eq 0 ]
then
prime=0
i=$num
else
i=$((i+1))
fi
done
if [ $prime -eq 1 ]
then
m=$num
rev=0
while [ $m -gt 0 ]
do
dig=$(($m%10))
rev=$(( $rev*10 + $dig))
m=$(($m/10))
done
if [ $rev -eq $num ]
then
echo "smallest prime number greater than "$n" which is palindromic: " $num
flag=0
fi
fi
num=$(($num+1))
done