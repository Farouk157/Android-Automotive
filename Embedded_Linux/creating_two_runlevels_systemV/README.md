# Creating Two run levels using the systemV as an init process

## i created the application in that path 

		/usr/bin/app 

- here is the content of the app 
	
		#!/bin/sh 

		while true
		
			do 
			
				echo "Hello Farouk the app is running in level [1]" >> /etc/output
				
			sleep 50
			
		done 
		
![Screenshot from 2024-08-05 04-36-27](https://github.com/user-attachments/assets/ed4a525a-fe8d-418a-94f7-4c48cf227804)

- this application suppose to start echo the last line and redirect it into another created file in the output 

- i created that file [ /etc/output ] just to check at the end if the running level is working or not 


- we have to make that file [ app ] executable 

		chmod +x app 
		
![Screenshot from 2024-08-05 04-37-23](https://github.com/user-attachments/assets/d8e794f1-de54-4b8f-ab7d-52c0c455eeb6)

## now we need to create a script that will specify if that app is [S] start or [K] killed 

		touch /etc/inid.d/application
		
- here is the implementation of that application script 
		
		#!/bin/sh

		DAEMON=/usr/bin/app
		
		NOPLUGIN_OPTION=""
		
		SSD_OPTIONS="--oknodo --quiet --exec $DAEMON -- $NOPLUGIN_OPTION"

		case "$1" in 
		
		start)
		
			echo "turnning on the application" 
			
			start-stop-daemon --start --background $SSD_OPTIONS
			
			;; 
			
		stop)
		
			echo "turnning off the application"
			
			start-stop-daemon --stop --background $SSD_OPTIONS

			;;
		
		*)
		
			echo "Usage: $0 {start|stop}"
			
			exit 1
			
			;;

		esac 
		
		exit 0
		
![Screenshot from 2024-08-05 04-38-10](https://github.com/user-attachments/assets/2cc6c9f1-6f1e-416b-9902-d4ac95e36a63)

- we have to make that script executable too 
		
		chmod +x application
		
![Screenshot from 2024-08-05 04-38-28](https://github.com/user-attachments/assets/0da23dc1-3018-4fc9-9885-75af771b2dc4)
		
## i will create the run levels that i want now 

		mkdir /etc/rc1.d 
		
		mkdir /etc/rc2.d 
		
- i created 2 run levels

![Screenshot from 2024-08-05 04-49-25](https://github.com/user-attachments/assets/565b417d-f20d-4bbe-bdf3-eca3777b2215)
			 
- i will now make soft link inside these run levels on the application script

		ln -s /etc/init.d/application S01application 
		
![Screenshot from 2024-08-05 04-50-34](https://github.com/user-attachments/assets/bd4cc795-2fae-4761-a865-c6332489e6a0)
		
		ln -s /etc/init.d/application K01application 

![Screenshot from 2024-08-05 04-51-14](https://github.com/user-attachments/assets/459b7815-73ab-4136-a044-bdc1ddda1cde)

- let's illustrate the meaning of these 2 lines
	
		[ ln -s ] => means: i'm creating a soft link 
		
		[ /etc/init.d/application ] => means: the source that i will link on 
		
		[ S ] => stands for start 
		
		[ 01 ] => stands for the periority 
		
		[ application ] => the name of the link
		
		
		[ K ] => stands for kill 
		
		the rest is the same 
		
- in short i will start my app when i move to run level 1, 

then i will kill it when i move to run level 2		 



## we have to create the rc.c script that will loop on the whole softlinked scripts inside the specified run level

		touch /etc/rc.c 
		
- here is the implementation of that rc.c script 

		#!/bin/sh
		
		# Check if one argument is provided
		
		if [ $# -ne 1 ]; then
		
			echo "Usage: $0 <runlevel>"
			
			exit 1
		fi

		folder="/etc/rc$1.d"

		# Process scripts starting with K
		
		for script in "$folder"/K??*; do
		
		[ -f "$script" ] || continue
		
		case "$script" in
		
			*.sh)
			
			. "$script" stop
			
		;;
		
		*)
		
		"$script" stop
		
		;;
		
		esac
		
		done

		# Process scripts starting with S
		
		for script in "$folder"/S??*; do
		
			[ -f "$script" ] || continue
			
			case "$script" in
			
				*.sh)
				
					. "$script" start
					
				;;
				
			*)
				
				"$script" start
				
				;;
				
		esac
		
		done

![Screenshot from 2024-08-05 05-14-26](https://github.com/user-attachments/assets/6f4eb9e1-edac-45c0-beb0-5599ca7a52dd)


## i will now update the inittab file 

- i will add the run levels that i want 

		vi /etc/inittab
		
![Screenshot from 2024-08-05 05-06-30](https://github.com/user-attachments/assets/fbc92c71-dfa1-4593-a7d0-ad2c36ae355e)
		

## now we can move between the 2 run levels let's check that together 

- run the level 1 that starts my app 

		init 1 
		
![Screenshot from 2024-08-05 05-09-17](https://github.com/user-attachments/assets/23203ef1-70eb-4c15-a68e-81b06ddaa576)

- run the level 2 that stops my app
		
		init 2 
		
![Screenshot from 2024-08-05 05-09-29](https://github.com/user-attachments/assets/9147b814-3327-4be3-9f1b-bcb70b773966)


## here is the content that redirected to the output file cause it was working in daemon mode 

![Screenshot from 2024-08-05 05-11-16](https://github.com/user-attachments/assets/ba5f399d-7fc3-4217-98c7-94f714ccd9d1)
		


## Done 		
		
