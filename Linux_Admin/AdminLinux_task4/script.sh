#!/bin/bash

# Variables
USER_NAME="yourName"
GROUP_NAME="FamilyName"

# Check if the user already exists
if id "$USER_NAME" &>/dev/null; then
    echo "User '$USER_NAME' already exists."
else
    echo "User '$USER_NAME' does not exist."
    echo "Creating user '$USER_NAME'..."
    sudo useradd "$USER_NAME"
    if [ $? -eq 0 ]; then
        echo "User '$USER_NAME' created successfully."
    else
        echo "Failed to create user '$USER_NAME'."
        exit 1
    fi
fi

# Check if the group already exists
if getent group "$GROUP_NAME" &>/dev/null; then
    echo "Group '$GROUP_NAME' already exists."
else
    echo "Group '$GROUP_NAME' does not exist."
    echo "Creating group '$GROUP_NAME'..."
    sudo groupadd "$GROUP_NAME"
    if [ $? -eq 0 ]; then
        echo "Group '$GROUP_NAME' created successfully."
    else
        echo "Failed to create group '$GROUP_NAME'."
        exit 1
    fi
fi

# Add the user to the group
echo "Adding user '$USER_NAME' to group '$GROUP_NAME'..."
sudo usermod -aG "$GROUP_NAME" "$USER_NAME"
if [ $? -eq 0 ]; then
    echo "User '$USER_NAME' added to group '$GROUP_NAME' successfully."
else
    echo "Failed to add user '$USER_NAME' to group '$GROUP_NAME'."
    exit 1
fi

# Display user and group information
echo "Displaying information for user '$USER_NAME':"
id "$USER_NAME"

echo "Displaying information for group '$GROUP_NAME':"
getent group "$GROUP_NAME"
