#!/bin/bash

# Check if .bashrc exists in the user's home directory
if [ -f "$HOME/.bashrc" ]; then
    echo "Appending environment variables to .bashrc..."

    # Append HELLO variable with the value of HOSTNAME
    echo "export HELLO=$HOSTNAME" >> "$HOME/.bashrc"

    # Append LOCAL variable with the value of whoami command
    echo "LOCAL=\$(whoami)" >> "$HOME/.bashrc"	

    echo "Environment variables appended."
else
    echo "No .bashrc file found in $HOME directory."
    
fi

# Open another terminal
echo "Opening another terminal..."


gnome-terminal & disown

echo "New terminal opened."
