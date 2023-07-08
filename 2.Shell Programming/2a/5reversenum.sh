echo "input:"
read num
rev=0
dig=0
while [ $num -gt 0 ]
do
dig=$(($num % 10))
rev=$(( $rev*10 + $dig))
num=$(( $num/10 ))
done
echo "reverse is:"$rev