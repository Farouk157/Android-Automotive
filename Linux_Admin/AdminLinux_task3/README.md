# solution of LinuxAdmin_Task3

## Section 1:

1- first of all i created my bash script 

2- before running i tried to print the variables to make sure that they don't exist in the .bashrc file

here is the output of that test printed nothing

![1](https://github.com/user-attachments/assets/54f1b018-9e63-4f5f-96e0-12c2fff8244c)


3- then i run my bash script 

![2](https://github.com/user-attachments/assets/4314a336-f5d7-4ac6-85c5-11d0bdf7e343)


4- after running the script it will add the variables to the .bashrc and run a new terminal

![3](https://github.com/user-attachments/assets/7b472c09-6945-4746-a827-fc95d6552800)

5- after oppenning another terminal and trying to print the variables they already printed with the values

![4](https://github.com/user-attachments/assets/de287a05-24d9-41f7-aa4d-5457bcb47141)



## section 2: 

### 1- List the user commands and redirect the output to /tmp/commands.list

![5](https://github.com/user-attachments/assets/3b3b873a-f728-49de-a79d-fc738599c728)



### 2- Edit in your profile to display date at login and change your prompt permanently.

- first of all i will open the .bashrc file and add the date command to print it with any terminal will open

![Screenshot from 2024-07-18 21-22-36](https://github.com/user-attachments/assets/a4c21058-3ee7-4064-9794-d5ff9781030b)

- after adding that line we can change the prompet as we want from the PS1 variable as we want it to be

i left it as default 

![Screenshot from 2024-07-18 21-23-33](https://github.com/user-attachments/assets/0c6dc009-b99c-4f1b-926d-cc5ea8232455)

- finally we can save and close the .bashrc and open a new terminal we will get the changes

with evry terminal will open 

![Screenshot from 2024-07-18 21-24-16](https://github.com/user-attachments/assets/036d85d0-299d-482f-a286-30b94db639c1)



### 3- What is the command to count the word in a file or number of file in directory.

	-> we can use [ wc -w file_name ] to get the number of words inside the file 

![Screenshot from 2024-07-18 21-30-48](https://github.com/user-attachments/assets/7860e353-41c5-4155-acf7-464215cefc1d)

	-> we can use [ ls -lh file_path | grep "^-" | wc -l ] to get the number of files in a directory
	
![Screenshot from 2024-07-18 21-36-15](https://github.com/user-attachments/assets/141fc892-8405-47e7-999a-4bd8b778a7e7)

	-> finally to get the number of user commands we can use: 
	
		[ls -lh /usr/bin/ | grep "^-" | wc -l ]
		
![Screenshot from 2024-07-18 21-40-30](https://github.com/user-attachments/assets/398ac267-9c4b-4424-90c9-0980b7226ce6)



### 4- What happens if you execute:

a- cat filename1 | cat filename2
	
	-> cat filename1 : will get the content of the filename1 but it will print it 
	   	           
	   	           will pass it by piping as an input to cat filename2
	   
	   cat filename2 : will print the content of the filename2 only cause content of filename1 isn't 
	   			
	   		   a valid input to it 
	  
	  [ so only content of filename2 will appear on the terminal ] 

b- ls | rm

	-> in fact this line should execute normally the ls command lists all the content of the working directory
	
	   and won't show it on the terminal cause of the piping they all will be input to the rm command 
	   
	  [ but in fact this rm command for some security won't work, gives missing operand and won't delete any !!]
	  
	  so always avoid using piping with that line ( ls | rm )
	  
![Screenshot from 2024-07-18 21-48-15](https://github.com/user-attachments/assets/2368e856-c0ba-4745-a0be-56600525eca0)

c- ls /etc/passwd | wc –l

	-> prints only the file number and only 1 exists in fact with that name
	
![Screenshot from 2024-07-18 21-49-23](https://github.com/user-attachments/assets/12fe6f2e-e569-46a6-ba92-30ac77757d61)



### 5- Write a command to search for all files on the system that, its name is “.profile”.

	-> [ locate file_name ]
	
![Screenshot from 2024-07-18 21-51-21](https://github.com/user-attachments/assets/59599836-0600-489d-a27f-0dfe8feaf0cc)



### 6- List the inode numbers of /, /etc, /etc/hosts.

	-> inode of (/) [ ls -id / ]
	
![Screenshot from 2024-07-18 21-52-56](https://github.com/user-attachments/assets/579ba4b2-b0fe-4a79-a6c4-f7fd1e822a57)

	-> inode of (/etc) [ ls -id /etc ]
	
![Screenshot from 2024-07-18 21-53-26](https://github.com/user-attachments/assets/ac99e0b7-84f3-4e53-987c-4984ef14a126)

	-> inode of (/etc/hosts) [ ls -id /etc/hosts ]
	
![Screenshot from 2024-07-18 21-54-07](https://github.com/user-attachments/assets/c7622b5f-4cb5-46da-94e3-8666113fc348)



### 7- Create a symbolic link of /etc/passwd in /boot.

	-> [ ln -s /etc/passwd /boot/mysoft ]
	
![Screenshot from 2024-07-18 21-59-49](https://github.com/user-attachments/assets/01d22271-c8c3-4783-a730-3e4a45b55187)



### 8- Create a hard link of /etc/passwd in /boot. Could you? Why?

	-> Creating a hard link of /etc/passwd in /boot is not possible
	
	-> /etc/passwd and /boot are likely on different filesystems, we cannot create a hard link between them.
	
	   Hard links are limited to the same filesystem due to the way inodes and filesystem structures are managed.
	   


### 9- Echo \ it will jump to the next line, and will print >

###    Notice the prompt ”>” what is that? and how can you change it from “>” to “:”.

	-> finding [ > ] after echo \ indecates that the shell still need input from user 
	
	-> we can change it to [ : ] using the PS1 variable in the .bashrc file 
	

	 
 
