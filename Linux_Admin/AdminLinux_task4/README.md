# solution of LinuxAdmin_Task4

## Section 2: 

### 1) Create a supplementary (Secondary) group called pgroup with group ID of 30000

		sudo groupadd -g 30000 pgroup
	
this command is used to create a group with id (30000) and it's name is pgroup


### 2) Lock any user created account so he can't log in

		sudo passwd -l username 
	

### 3) Delete user account

		sudo userdel -r username
	

### 4) Delete group account

		sudo groupdel groupname
	

### 5) State the difference between adduser and useradd with example shown.

a)-> useradd: A low-level command used to create a new user account, 
	      
	      cause it doesn't automatically create a home directory 
	      
	      or set up other default user settings unless specified.
	      
-> example:   

		sudo useradd -m -s /bin/bash username
		
b)-> adduser: A high level command used to create a new user account, 

	      Automatically creates a home directory, sets default shell, 
	      
	      and prompts for additional user information

-> example: 

		sudo adduser username 

This command will prompt you to enter additional details such as the user’s password, 

full name, and other information.	

