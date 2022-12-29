read a
k=`expr $a % 2`
if test $k -eq 0
then
    echo "$a is an even number"
else
    echo "$a is an odd number"
fi