i=100
while [ $i -lt 999 ]
do
n=$i
flag=0
i=$(($i+1))
if [[ $n =~ [4-9] ]]
then
flag=0
else
echo " "$n
fi
done

# i=100
# while [ $i -lt 999 ]
# do
# n=$i
# flag=1
# while [ $n -gt 0 ]&&[ $flag -ne 0 ]
# do
# dig=$(($n%10))
# if [ $dig -eq 0 ]||[ $dig -eq 1 ]||[ $dig -eq 2 ]||[ $dig -eq 3 ]
# then
# n=$(($n/10))
# else
# flag=0
# fi
# done
# if [ $flag -eq 1 ]
# then
# echo $i
# fi
# i=$(($i+1))
# done