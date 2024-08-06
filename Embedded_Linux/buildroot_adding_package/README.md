# creating new package and adding it to the buildroot then customize my own distro and generate it 


## download and clone the build root 

![1](https://github.com/user-attachments/assets/9dda9f5f-5724-47be-9cfb-1ae46569e170)

## creating new package for buildroot 

- 1. we go to the package directory inside the buildroot 
	
		cd buildroot/package
		
![2](https://github.com/user-attachments/assets/3af9d868-76ee-4d04-b7f1-20e34b63f129)
		
- 2. create new directory then create inside it the 4 files 
	
		mkdir my_details 
		
		touch main.cpp app.mk Config.in Makefile
		
![3](https://github.com/user-attachments/assets/1604e7ec-2dbb-4d96-ae1f-a75c6948cada)
	
- 3. write you application inside the main.cpp 
	
![4](https://github.com/user-attachments/assets/d6e25531-706a-42e2-b01b-d91461eff23d)
		
- 4. write the Makefile 

![5](https://github.com/user-attachments/assets/73e9cd26-4bd0-42be-a3af-6852c106d3fa)
		
- 5. write the app.mk file 

![6](https://github.com/user-attachments/assets/808430b8-79f1-4dda-a61f-619dea10c313)
		
- 6. write the Config.in file to add you package to the configuration of the buildroot 

![7](https://github.com/user-attachments/assets/91d9ecc6-936c-4c7d-b707-6d270c8ebb86)
		
- 7. then go back to the package directory and open the Config.in file and add you package 
	
		cd ../
		
		vim Config.in 
		
		source "package/my_details/Config.in"
	
![8](https://github.com/user-attachments/assets/8854d622-a4d8-413e-81a0-e5a95656eeca)

- 8. now we back to the buildroot directory and open the menuconfig 

		cd ../
		
		make menuconfig 
		
![9](https://github.com/user-attachments/assets/eceb60e0-6630-4d3f-b755-8ef7f583bd5e) 
		
- 9. we go to the target packages the place we put our package inside 
		
![10](https://github.com/user-attachments/assets/04aec195-96ac-439e-b803-1227781f5b7a)
		
- 10. we will find our package here we can check on it to add it press [Y] 

![11](https://github.com/user-attachments/assets/bc9fc2dd-1d3b-40d3-920d-83852e9a13a6)
		
![12](https://github.com/user-attachments/assets/029f3f48-7f98-49b2-b50f-15d25a9b2b2e)


## now save and exit you added you package


## in case we didn't finish customization of out distro yet we back to menu config and let's make some config together 

![13](https://github.com/user-attachments/assets/8eccf1ad-bb22-41b1-9c69-f8e1ec8d835e)
		
- from target options: 

	- we can select target architecture 
	
![14](https://github.com/user-attachments/assets/da212540-8c6f-47c7-bf62-44974f508bfe)
		
![15](https://github.com/user-attachments/assets/1db05e8f-d6fe-479d-bfb5-fa48d07bec12)

- from toolchain 
		
![16](https://github.com/user-attachments/assets/a242fa97-eb51-4669-935b-a0f07e82590f)
		
	- choosing the c library to be glibc 
	
![17](https://github.com/user-attachments/assets/53ed7a3e-f487-4615-a131-f67a376a5f5f)
		
![18](https://github.com/user-attachments/assets/4b25f5fc-9818-4ba3-86eb-224a195833f5)
		
	- then enable the c++ 

![19](https://github.com/user-attachments/assets/8ad72409-6809-4b3f-9dc8-ea0a9bd8863b)
		
- from system configuration 

![20](https://github.com/user-attachments/assets/09630169-64be-42fd-9789-21e9d6dc7e47)
		
	- set Init system to systeV
		
![21](https://github.com/user-attachments/assets/61aa6d83-f280-4d3f-a00b-7d94f5dbae4d)
		
![22](https://github.com/user-attachments/assets/f01a3347-2303-4a1d-96b0-49ebf32e9d1d)
	
	- then set the user password 
	
![23](https://github.com/user-attachments/assets/db13497c-a32e-4a23-9169-275e54490245)

- go to the target package again we already checked our created package and added it 

![24](https://github.com/user-attachments/assets/ad50bf6d-729b-4c79-bff1-bc13eefe1fd5)

![25](https://github.com/user-attachments/assets/a882784a-0e63-403f-a6e3-cd8c14f2f10c)
	
	- go to development tools 
	
![26](https://github.com/user-attachments/assets/d1230269-5805-44f9-82cc-1ccef341da45)
		
	    -> check git, grep and make 
	
![27](https://github.com/user-attachments/assets/ccbde275-e4b9-4e00-8da6-f544b998fd95)
		
![28](https://github.com/user-attachments/assets/951842ae-652e-4981-8cec-6c256695a23d)

![29](https://github.com/user-attachments/assets/d7f5a4b2-4686-4249-a25b-1b342c2e0d90)
		
	- go to games 
	
![30](https://github.com/user-attachments/assets/79e90807-7a71-403e-a083-87af38a9d51e)
		
	   -> select chocolate-doom game 
	   
![31](https://github.com/user-attachments/assets/e35acca1-7d5b-4b3b-975f-eaf1f5244540)
	   	
	- go to text editors and viewers and add nano and vim    

![32](https://github.com/user-attachments/assets/1a184a2d-d54b-4c5a-9272-c13b0e168794)
		
![33](https://github.com/user-attachments/assets/7596ea5a-8e8d-4eb5-9bea-2939c0741f87)
		
![34](https://github.com/user-attachments/assets/f4798a7c-de5d-4811-9dc5-7ae226de5175)
		
## now we are ready to save 

![38](https://github.com/user-attachments/assets/ac06e621-fbd3-4a03-9831-e8493ed88905)	
		 
![39](https://github.com/user-attachments/assets/e55cf857-79c9-405f-8ee5-d080a2f99e5a)

![40](https://github.com/user-attachments/assets/42379c43-9122-43f7-9868-aae9e49bf4d0)


## now we go to the buildroot directory and make it

		cd buildroot 
		
		make 
		
### [ note ] -> it will take so much time from 3 to 5 hours depends on you computer specs 

![41](https://github.com/user-attachments/assets/315abe24-9dbf-4e3a-85a0-0a8973703739)
		
## after the make is finish we will find this 

![42](https://github.com/user-attachments/assets/e7bddb6a-e158-4d87-966c-704cc3da42ac)
		
## let's navigate and see out image and dtb files and start-qemu 

		cd ~/buildroot/output/image/
		
		ls 
		
![43](https://github.com/user-attachments/assets/ce0b1de7-7502-41ee-b6e8-d773e0ddc34a)
		
## start our distro using the qemu 

		./start-qemu.sh
		
		
## sign in using 

		buildroot login: root 
		
		password: you_password_you put in configuration
		
![44](https://github.com/user-attachments/assets/6a67043c-3d3a-46d3-aa30-0edd4ed56972)
		
## welcome to your own customized distro !!!
		
![45](https://github.com/user-attachments/assets/048b3187-6671-4851-b3c6-b8b81ef0ea91)
		
## let's make sure from our added application that we created as a package in /usr/bin 

		ls /usr/bin 
		
	- here is myapp 

![46](https://github.com/user-attachments/assets/1027c498-fd87-4b76-ad02-2dedc2907df2)
		
## run it and watch the output 

![47](https://github.com/user-attachments/assets/a5904031-3598-4e07-a332-7afe4b5592f6)
		


## congrats 

## Done 


		

		
  
