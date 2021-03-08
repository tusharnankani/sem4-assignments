# * Display all filenames beginning with character ‘a’ and displays its contents

for file in a*
do
    echo -e "\nIn $file:" 
    cat $file
done
