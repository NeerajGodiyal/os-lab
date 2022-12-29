echo "Enter a number"
read a
i=2
flag=0
while test $i -le `expr $a / 2`
do
    if test `expr $a % $i` -eq 0
    then
        flag=1
    fi
    i=`expr $i + 1`
done
if test $flag -eq 1
    then
    echo "$a is not a prime number"
else
    echo "$a is a prime number"
fi