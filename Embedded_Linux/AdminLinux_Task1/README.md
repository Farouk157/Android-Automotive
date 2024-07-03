# Questions and answers 

## Q1) List three linux distributions 

Answer:
	1- Ubuntu
 
	2- Fedora
	3- Red Hat 
	4- Kali
	
## Q2) From the slides what is the man command used for ? 

Answer: 
	this man command is used for giving short reference manual for external commands only
	and not working with internal or shell commands.
	

## Q3) what is the difference between rm and rmdir using man command ? 

Answer: 
	1- rm this command is mainly used for deleting files and by default, it can't delete the directory
	   unless using the flag or option (-r) which means recursive (remove the directories and their content recusively).
	
	2- rmdir this command is used for deleting the directories if they are empty,
		(if directory is not empty the you have to use rm command with -r flag).
		

## Q4) Create the following hierarchy under your home directory (done)
	
    ### (Q) a- remove dirl1 with rmdir in one step ? 
		
Answer  -> the rmdir couldn't delete the directory because it contains a directory or content. 
        -> to overcome that we can use rm command with -r option or flag
        
    ###(Q) b- remove OldFiles using rmdir -p command ? 
    
Answer  -> failed to remove it's 'Documents/OldFiles' not a directory can't use rmdir with it 


    ###(Q) c- the output of the command pwd was /home/usr. write the absolute and relative path for the file mycv
  
Answer  -> the absolute path is: /home/usr/docs/mycv
	-> the relative path is: docs/mycv


## Q5) copy the /etc/passwd file to your directory making its name is mypasswd

Answer  -> cp /etc/passwd ~/mypasswd



## Q6) Rename this new file to be oldpasswd

Answer -> mv ~/mypasswd ~/oldpasswd



## Q7) You are in /usr/bin, list four ways to go to your home directory 
	
Answer -> 1- cd ~
	  2- cd /home/usr
	  3- cd $HOME
	  4- cd ../../home/usr



## Q8) list linux commands in /usr/bin that start with w

Answer -> using the command ls with wild cards 
		
	  ls /usr/bin/w*
	 
	 
	 
## Q9) What command type are used for ? 

Answer -> this command (type) is used to inform us about the type of the command itself
	  ( External, Internal(shell) or alias ) command.
	  
	  	
	  

## Q10) show 2 types of command filee in /usr/bin that start with lettr c 

Answer -> 
	   cat: A command used to concatenate and display files or standard input.
	   cp: A command used to copy files and directories from one location to another.
	

## Q11) using man command find the command to read file. (Note: man take option)

Answer ->  man -k read 

## Q12) what is the usage of apropos command ?

Answer -> this command is used if we don't remeber the name of a command we can 
	  give it a string that descripes the needed command and apropos helps us 
	
