echo "no. of arguments:"$#
i=$#
echo -n "arguments in reverse order:"
while [ $i -ge 1 ]
do
echo -n ${!i}" "
i=$(($i-1))
done
echo " "