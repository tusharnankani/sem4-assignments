# * Determine if a person is eligible to vote or not 

read -p "Enter the age of the candidate: " age
if (($age >= 18));
then 
    echo "The candidate is eligible for voting."
else
    echo "The candidate is not eligible for voting."
fi
