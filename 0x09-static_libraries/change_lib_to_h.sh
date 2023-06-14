#!/bin/bash

# Change all instances of "lib" to "h" in all C files in the current directory and its subdirectories.

for file in *.c; do
  # Read the file.
  contents=$(cat "$file")

  # Replace all instances of "lib" with "h".
  new_contents=$(echo "$contents" | sed "s/lib/h/g")

  # Write the file back.
  echo "$new_contents" > "$file"
done
