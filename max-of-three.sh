echo "Ayam Dobhal | Section C | University Roll Number 2016685\n"
echo "Enter 3 numbers"
read a b c

if test $a -gt $b
then
    if test $a -gt $c
    then
        echo "$a is the greatest."
    else
        echo "$c is the greatest."
    fi
else
    if test $b -gt $c
    then
        echo "$b is the greatest."
    else
        echo "$c is the greatest."
    fi
fi