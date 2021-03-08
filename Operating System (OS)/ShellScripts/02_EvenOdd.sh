# * Write a shell program to check if a number entered is even and odd

read -p "Enter a number: " num
if [ $((num%2)) -eq 1 ]
then 
    echo "$num is odd."
else
    echo "$num is even."
fi
