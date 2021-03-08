# * Write a shell program to find sum of n numbers

read -p "Enter a number: " num
sum=0
echo "Enter $num numbers: " 
for((i=0; i<$num; i++))
do
    read -p "Enter number $((i+1)): " a
    sum=$((sum+a))
done
echo "The sum of the entered numbers is $sum"
