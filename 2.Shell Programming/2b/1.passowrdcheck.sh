echo "input string:"
read str
len=${#str}
if [ $len -ge 8 ]
then
if [[ $str =~ [A-Z] ]]
then
if [[ $str =~ [a-z] ]]
then
if [[ $str =~ [0-9] ]]
then
if [[ $str =~ "_" ]]
then
echo "Strong Password"
else
echo "Weak Password"
fi
else
echo "Weak Password"
fi
else
echo "Weak Password"
fi
else
echo "Weak Password"
fi
else
echo "Weak Password"
fi