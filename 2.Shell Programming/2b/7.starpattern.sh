echo "input n:"
read n
temp=$n
i=1
val=0
while [ $i -le $n ]
do
	j=0
	num=$(($n - $i))
	# echo $num
	val=$(($num / 2))
	while [ $j -lt $val ]
	do
		echo -n " "
		j=$(($j+1))
	done
	k=1
	while [ $k -le $i ]
	do
		echo -n "*"
		k=$(($k+1))
	done
	j=0
	while [ $j -lt $val ]
	do
		echo -n " "
		j=$(($j+1))
	done
	echo
	i=$(($i+2))
done

i=$(($n-2))

while [ $i -gt 0 ]
do
	j=0
	num=$(($n - $i))
	val=$(($num / 2))
	while [ $j -lt $val ]
	do
		echo -n " "
		j=$(($j+1))
	done
	k=1
	while [ $k -le $i ]
	do
		echo -n "*"
		k=$(($k+1))
	done

	j=0
	while [ $j -lt $val ]
	do
		echo -n " "
		j=$(($j+1))
	done
	echo
	i=$(($i-2))
done
