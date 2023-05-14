echo "input decimal: "
read decimal
hex=$(echo "obase = 16 ; ibase = 10 ; $decimal" |bc)
binary=$(echo "obase =2 ; ibase =10 ; $decimal" |bc)
echo "hexadecimal :"$hex
echo "binary :"$binary