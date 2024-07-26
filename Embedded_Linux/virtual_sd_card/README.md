# this task aims to creating a virtual sd_card

here is the steps for creating a virtual sd_card on linux assuming size is 1GB

## 1) we need to create the file itself 

		mkdir ~/sd_card 
		touch sd.img

## 2) now we need to specify the size we want to the file 
	
		dd if=/dev/zero of=~/sd_card/sd.img bs=1M count=1024
		
![Screenshot from 2024-07-26 07-26-37](https://github.com/user-attachments/assets/439c5531-f11e-4d6f-bbfc-ccfa9bcc5f4f)


## 3) now we need to configure the partions and thier types 

		cfdisk sd.img 

![Screenshot from 2024-07-26 07-29-04](https://github.com/user-attachments/assets/70f60a41-e443-4c57-9bca-5a37c7d3baff)

-> then we choose the type to be dos

![Screenshot from 2024-07-26 07-29-24](https://github.com/user-attachments/assets/de24ff34-af23-43c0-9883-0184feabe3ce)

-> another configuration will be open 

![Screenshot from 2024-07-26 07-29-39](https://github.com/user-attachments/assets/e9568929-8305-4fa6-aea7-bb2d864b6cf3)

-> now we can create the new partitions and specify size and type for them 

### in my case i need to create 2 partitions boot partition and must be a FAT

### and rootfs partition and must be of type ext4 

-> let's see creating boot partition step by step 

a- click on new 

![Screenshot from 2024-07-26 07-29-39](https://github.com/user-attachments/assets/b186eaf0-76d8-4ea8-8479-3f76841bb352)

b- specify the size you want for the boot partition 

![Screenshot from 2024-07-26 07-34-24](https://github.com/user-attachments/assets/6f19fc8e-f4c4-4bf4-90c5-2837e45104ea)

c- make the bootable partition as primary 

![Screenshot from 2024-07-26 07-34-30](https://github.com/user-attachments/assets/30003ad6-f5da-4f68-8db3-a86f578d85a3)

d- make it bootable by clicking on bootable then you find a ( * ) added under Boot column 

![Screenshot from 2024-07-26 07-39-19](https://github.com/user-attachments/assets/bf351e48-7bb0-46a8-95d5-510433c9bf86)

e- choose the type by clicking on the type then select the type FAT 16

![Screenshot from 2024-07-26 07-40-30](https://github.com/user-attachments/assets/fdda1da2-a4e9-46a0-82d5-6746099735fd)

f- lastly make it writable by clicking on write then type yes 

-> now we nedd to create the rootfs partition 

a- create new partition as last from new 

![Screenshot from 2024-07-26 07-44-03](https://github.com/user-attachments/assets/934fe697-3ad7-467c-aad1-0a5ab69332f0)

b- give it the size asuming it's 800M

![Screenshot from 2024-07-26 07-44-58](https://github.com/user-attachments/assets/7aab023c-3bdb-4583-9db5-9c745bd06950)

c- then choose it to be extended cause it's not a bootale partition

![Screenshot from 2024-07-26 07-45-46](https://github.com/user-attachments/assets/bad5a51b-d48c-4a26-b411-cbf70013a4ef)

d- make it writable by clicking on write then type yes 

![Screenshot from 2024-07-26 07-47-29](https://github.com/user-attachments/assets/009eaa86-ffc6-47d5-90dc-d601af1c305e)

e- choose the partition type which is going to be ext4 but here we choose linux which represents (EXT4) 

![Screenshot from 2024-07-26 07-48-36](https://github.com/user-attachments/assets/35b06016-eadf-4f76-bf56-2c429072b6e3)

### the configuration is over now congrats.

## 4) now we need to Emulate the sd.img as a Storage Device (SD card) using the loop devices 

this command is used to ask the kernal to find an empty loop device and asign it to the sd.img 
	
		sudo losetup -f --show --partscan sd.img
		
 ![Screenshot from 2024-07-26 07-53-28](https://github.com/user-attachments/assets/3201d0fb-bcbf-4094-952d-ea19cabe3ca5)

that means that this sd.img is using now the loop 17 to be a virtual sd_card (device)

to make sure from that we can use the command 
		
		lsblk | grep loop17
		
![Screenshot from 2024-07-26 07-55-10](https://github.com/user-attachments/assets/c2b3ff77-08de-4ae4-b12a-499352674cce)

## 5) we need to assign the formating of the partitions we have created 

-> for the bootable partition which is boot directory it must be FAT as we mentioned 

		sudo mkfs.vfat -F 16 -n boot /dev/loop17p1
		
![Screenshot from 2024-07-26 08-01-13](https://github.com/user-attachments/assets/a1e1accb-1a49-4680-82d2-04284c30d92f)

-> for the rootfs partition we said it should be ext4 

		sudo mkfs.ext4 -L rootfs /dev/loop17p2
		
![Screenshot from 2024-07-26 08-04-04](https://github.com/user-attachments/assets/e69cb79e-850a-4185-8d00-1f6dad589f7c)

## 6) now we need to mount the 2 partitions on new 2 directories 

		mkdir ~/sd_ard/boot 
		
		mkdir ~/sd_ard/rootfs 
		
		mount /dev/loop17p1 boot
		
		mount /dev/loop17p2 rootfs
		
![Screenshot from 2024-07-26 08-11-03](https://github.com/user-attachments/assets/7ee884e6-9759-4e6e-9d94-883fddea6edd)

## finally we have created a virtual sd_card successfully 


 
