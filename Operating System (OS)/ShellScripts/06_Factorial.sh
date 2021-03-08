# * Write a shell program to find factorial of a number

read -p "Enter a number: " num
fac=1
for ((i=1;i<=$num;i++))
do
    fac=$((fac*i))
done
echo "$num! is $fac"
