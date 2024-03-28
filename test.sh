#!/bin/bash

# Navigate to the folder containing the files
cd ~/Downloads/Animation

# Iterate over each file in the folder
for file in *; do
    # Check if the file name contains the pattern '-'
    if [[ $file == *-* ]]; then
        # Extract the part after the last '-'
        new_name="${file##*-}"

        # Rename the file
        mv "$file" "${new_name}"

        echo "Renamed ${file} to ${new_name}"
    fi
done
