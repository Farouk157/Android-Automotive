# booting manually from the TFTP (Trivial File Trasfer Protocol)

- Trivial File Transfer Protocol (TFTP) is a network protocol for exchanging files between two machines.

- TFTP is commonly used in scenarios where a lightweight file transfers.

- TFTP typically uses UDP port 69 for communication.

- In Embedded Linux booting, TFTP is used to transfer essential files like kernel image and the bootloader 

  in case of new bootloader from the server to the embedded device during the bootstrapping process. 

## Booting from the server prerequisites

	- The server must support TFTP network protocol.
	
	- U-boot must support TFTP network protocol.
	
	- The embedded Linux board must has a network interface (such as Ethernet).

## Install TFTP Package on Linux 

### 1. Install tftp package on linux

		sudo apt install tftpd-hpa
		
### 2. check the status of the TFTP through

		sudo systemctl status  tftpd-hpa  
		
![1](https://github.com/user-attachments/assets/8750d0b2-cdb7-47e0-8838-0e91c6aa3890)

### 3. there is a file will be created automatically after the installation 

- in that path	[ /etc/default ] ->>> called [tftpd-hpa]

![2](https://github.com/user-attachments/assets/1782418d-0265-4ea1-aaf8-c387c0f049ae)

- we have to edit that file and add

		from -> TFTP_OPTIONS="--secure"

![3](https://github.com/user-attachments/assets/86d74597-38b6-4292-9bf6-252cba9848b8) 

		to   -> TFTP_OPTIONS="--secure --create"
	
![4](https://github.com/user-attachments/assets/9ad8933d-cffd-46bc-b6d6-79824f5e601a)
		
### 4. there is a srv/tftp directory created automatically when installed the TFTP package on my host machine

![5](https://github.com/user-attachments/assets/e789142d-60f4-4980-bcdc-d98bfe72f4ea)

## 5. change the owner of the tftp directory from the root to the tftp system user 	

		chown tftp:tftp tftp
		
![6](https://github.com/user-attachments/assets/90a525bc-7606-429c-aba5-fcf5d7f23290)
	  
## I installed and configured our bootloader which is u-boot here is the link

(https://github.com/Farouk157/Android-Automotive/tree/main/Embedded_Linux/u_boot)

## I installed the emulator qemu also at the last link with u-boot

## I installed my needed kernel which is linux, customized it and generated the zImage and dtb file

(https://github.com/Farouk157/Android-Automotive/tree/main/Embedded_Linux/customize_kernel) 

### 6. I have to copy the zImage of my customized kernel and the vexpress-v2p-ca9.dtb file into /srv/tftp

![7](https://github.com/user-attachments/assets/7fade26f-8aae-4e83-b0dd-4975929cd15f)

### 7. now my host machine is the server that i will load from and i'm using qemu as a target 

### 8. I need to connect the host machine with the target to be able to load image from the server 

### 9. I have to get the IP address of the server [ host machine ] 

		ip a

![8](https://github.com/user-attachments/assets/6d1b4f79-9b9c-4e52-b16e-bcd3e64de372)

### 10. now i got the ip of the server or host machine 

### 11. i will create the server network interface script in the u-boot directory called ( qemu-ifup )

- this script represents the ip of the tap or server network interface
		
		#! /bin/bash
		
		ip a add IP_ADDRESS dev $1 
		
		ip link set $1 up 
		
![9](https://github.com/user-attachments/assets/fed83c17-d1fa-4df3-976c-c8f9f92580da)

### 12. I have to make that script executable 

		chmod +x qemu-ifup 
		
![10](https://github.com/user-attachments/assets/9b660aa7-d246-4340-966f-ea6a64e9ceef)

### 13. I will set the target network interface (NIC) ip inside the qemu

- i should be greater than the server ip by 1, 2 or 3 ( i used incremented by 1) 

### 14. Now i can run the qemu and connect it with the server host machine 

		qemu-system-arm -M vexpress-a9 -m 128M --nographic --kernel u-boot --sd ~/sd_card/sd.img 
		
		-net tap,script=./qemu-ifup -net nic 
		
![11](https://github.com/user-attachments/assets/11a8921d-a36d-4538-9a61-221ddf238112)

- qemu will start here 

![12](https://github.com/user-attachments/assets/cd86b655-d28e-48cb-ab09-c70efea34afb)

### 15. now i'm on the target and i need to configure the ip for the target network interface 

- i will set 2 environment variables for the ip addresses of the server and also the target (qemu)

		=> setenv serverip 192.168.56.101   

		=> setenv ipaddr 192.168.56.102 

		=> setenv netmask 255.255.255.0 

![13](https://github.com/user-attachments/assets/fe3459af-723f-4b91-97cc-52734019ebf7)
   
### 16. now i'm going to load the zImage into the Kernel_Addr using the TFTP 

		tftp ${kernel_addr_r} zImage
		
![14](https://github.com/user-attachments/assets/ffd1ab1a-2329-4015-8a55-a1e16a984434)

### 17. im going to load the vexpress-v2p-ca9.dtb file int the fdt_addr using TFTP 

		tftp ${fdt_addr_r} vexpress-v2p-ca9.dtb

![15](https://github.com/user-attachments/assets/1f554d76-d572-46ac-8756-d49d29e55879)

### 18. finally we can boot the kernel 

		bootz ${kernel_addr_r} - ${fdt_addr_r}

![16](https://github.com/user-attachments/assets/ba783dbb-9c05-455d-bb3e-31e8dc1e9396)


## the kernel started successfully but got panic as you see cause it still needs the root file system

## Done !

		

