# creating a service unit that will run simple application when we enable and start it

## creating our application 
	
		cd my_app 

- then create the simple app here 

		vim main.c 

![1](https://github.com/user-attachments/assets/97854987-b04f-4b0c-8828-8e4c5c15f7b7)

		#include <stdio.h>
		
		#include <unistd.h>

		int main(void)
		
		{
		
			while(1)
			
			{
			
				printf("Hello from my app\n");
				
				sleep(3); // sleep for 3 seconds
				
			}
			
			return 0;

		}

![2](https://github.com/user-attachments/assets/01f7e079-b0c6-4d1d-b9a8-bc9b29ffdcf5)

![3](https://github.com/user-attachments/assets/e25ef291-3411-4d71-a45b-2d1074da42d1)


- now compile it to generate the binary object code of it

		gcc main.c -o myapp
		
- after generating the object code we can now move it to the usr binary 

		mv myapp /usr/bin
		
![4](https://github.com/user-attachments/assets/4ad429fd-bbc1-4496-9c56-c484d2502ebb)


## creating our service unit 

- navigate to the system D 
	
		cd /etc/systemd/system

- create the needed service unit name with extension [ .service ]

		sudo vim my_service.service
		
- now write the needed service as you want 

		[Unit]
		Description="this is my first service"

		[Service]

		Type=simple
		ExecStart=/usr/bin/myapp

		[Install]
		WantedBy=multi-user.target
  
![6](https://github.com/user-attachments/assets/8ce645e5-0fb5-4b85-b021-0d2e141fc989)

![5](https://github.com/user-attachments/assets/387233f8-afcd-4391-837d-59b00772bde7)


- we have created the service and the application that this service will run 


## checking the status of the service after creation
	
		sudo systemctl status my_service.service

![7](https://github.com/user-attachments/assets/10537ded-7921-436f-8349-d639ee51efe7)
 

## enable the service 

![8](https://github.com/user-attachments/assets/0520e4a7-ac54-4924-9372-f23527e24b04)


## starting the service and checking the status of the service after [ enable and start it ]

![9](https://github.com/user-attachments/assets/f2b60c21-56cf-4e40-9d90-b9c9d82cf170)


## stopping the service and checking the status of it 

![10](https://github.com/user-attachments/assets/c5bfee11-25e0-4b06-accf-ee66fb1c0505)


## Done  




	

