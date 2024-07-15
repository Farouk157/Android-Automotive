#!/bin/bash

if [ $# -lt 1 ]; then
	echo "sorry the source directory for ${$0} is not provided"
	exit 1
fi

SRC="$1"

if [ ! -d "$SRC" ]; then
	echo "Error this "${SRC}" is not a directory"
	exit 1
fi

img_dir="$SRC/images"
doc_dir="$SRC/documents"
oth_dir="$SRC/others"

mkdir -p "$img_dir"
mkdir -p "$doc_dir"
mkdir -p "$oth_dir"


organize_files() {
    local file="$1"
    local base_name="$(basename "$file")"
    local extension="${base_name##*.}"  # Extract file extension

    case "$extension" in
        jpg|png|gif)
            mv "$file" "$img_dir"
            ;;
        txt|doc|pdf)
            mv "$file" "$doc_dir"
            ;;
        *)
            mv "$file" "$oth_dir"
            ;;
    esac
}


for file in "$SRC"/*
do
	if [ -f "$file" ]; then
		organize_files "$file"
	fi
done

echo "Files organized successfully!"


