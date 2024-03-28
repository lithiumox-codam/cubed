#!/bin/bash

# Specify the folder containing PNG files
folder_path="textures/sanic"

# Specify the color you want to make transparent
color_to_transparent="107,107,107" # Example: White color in RGB format

# Loop through each PNG file in the folder
for file in "$folder_path"/*.png; do
    # Set the specified color to transparent
    convert "$file" -transparent "rgb($color_to_transparent)" "${file%.png}.png"
done

echo "Transparency applied to all PNG files in the folder."
