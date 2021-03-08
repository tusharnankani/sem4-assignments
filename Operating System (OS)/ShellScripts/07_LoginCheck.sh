# * Write a shell program to check validity of a username and password with a function defined in the code  

function check
{
    if [[ $username == "ADMIN" && $password == "123456" ]]
    then
        bool=1
    else
        bool=0
    fi
}
read -p "Enter the username: " username
read -p "Enter the password: " password
check
if (($bool==1))
then
    echo "Username and Password verified."
else
    echo "Username and Password not verified."
fi