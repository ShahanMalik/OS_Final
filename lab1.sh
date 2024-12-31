read -p "Enter the name of a file or directory: " item

if [ -e "$item" ]; then
    if [ -f "$item" ]; then
        echo "$item is a regular file."
    elif [ -d "$item" ]; then
        echo "$item is a directory."
    fi

    ls -l "$item"
else
    echo "$item does not exist."
fi