echo "input a:"
read a
echo "input b:"
read b
echo "input c:"
read c
s=$a
if [ $b -lt $s ]
then
	s=$b
fi
if [ $c -lt $s ]
then
	s=$c
fi
echo "smallest is: "$s