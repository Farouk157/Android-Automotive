# Mount Root File System through server using NFS and TFTP 

## installing the nfs server 

1. Install NFS Debian Package

		sudo apt install nfs-kernel-server
		
![Screenshot from 2024-07-28 15-36-31](https://github.com/user-attachments/assets/61612ad8-e865-44b7-b4d0-23904171c407)


2. Check If NFS Installed successfully

		systemctl status nfs-kernel-server
		
![Screenshot from 2024-07-28 15-38-37](https://github.com/user-attachments/assets/79233868-0970-45c5-9825-5f05e771f556)

3. check if the NFS server is listening on the default port (2049)

		ss -tulpen | grep 2049
		
![Screenshot from 2024-07-28 15-41-40](https://github.com/user-attachments/assets/319d1b94-6b90-4a9d-a064-4134428b150d)

4. Check NFS Kernel Modules: Ensure that the NFS kernel modules are loaded.

		lsmod | grep nfs

![Screenshot from 2024-07-28 15-42-35](https://github.com/user-attachments/assets/9e135b8b-87b8-480b-a196-fafc6d289a5b)
		
		
5. Check the NFS configuration file 

		cat /etc/exports
		
![Screenshot from 2024-07-28 16-44-43](https://github.com/user-attachments/assets/76057f13-9eba-4a1b-97ec-8bb22deaa2be)

##  Mount Root File System through NFS server

1. putting the rootfs that i have created before on the server 

		mkdir /srv/nfs-share
		
		sudo rsync -av rootfs_directories/static_rootfs/ /srv/nfs-share/

![Screenshot from 2024-07-28 16-50-06](https://github.com/user-attachments/assets/9d5426b0-c760-42b0-9782-1e0f0ddb001d)

![Screenshot from 2024-07-28 16-50-13](https://github.com/user-attachments/assets/9eb64854-84e3-40bf-9211-2b675a5169c8)

2. get the ip of the host machine (server) 

		ip a 

- for my case the ip address is -> 192.168.56.101

![Screenshot from 2024-07-28 16-53-10](https://github.com/user-attachments/assets/e56a2727-0f66-4298-9186-202f604b1275)


- i will choose the ip for the the target qemu as -> 192.168.56.102

- and the netmask will be -> 255.255.255.0

3. configuring the nfs through the file we mentioned /etc/exports

		sudo vim /etc/exports 
		
- insert the path to the rootfs that created on the server and specify the ip that can use it 

		/srv/nfs-share 192.168.56.102(rw,no_root_squash,no_subtree_check)
		
![Screenshot from 2024-07-28 16-59-46](https://github.com/user-attachments/assets/1f6e531d-ca46-4a3f-ba46-ceeb1adbc9c1)


4. Refresh the exports configuration file to update it by

		sudo exportfs -r
		
## running the Qemu

		sudo qemu-system-arm -M vexpress-a9 -m 128M -nographic -kernel u-boot -sd ~/sd_card/sd.img 
		
		-net tap,script=./qemu-ifup -net nic 
		
- now qemu started 

- set the environment variables 

		setenv serverip  192.168.56.101
		
		setenv ipaddr  192.168.56.102
		
		setenv netmask 255.255.255.0
		
![Screenshot from 2024-07-28 17-11-32](https://github.com/user-attachments/assets/7bbcfb60-1ec5-4918-8482-4b5685586474)
		
- set the bootargs variable with

		console=ttyAMA0  root=/dev/nfs ip=192.168.56.102:::::eth0 
		
		nfsroot=192.168.56.101:/srv/nfs-share,nfsvers=3,tcp rw init=/sbin/init
		
![Screenshot from 2024-07-28 17-14-05](https://github.com/user-attachments/assets/8a759c0d-bcc1-4d8f-b32b-554282413e77)


## loading the kernel image from the tftp server 

		tftp ${kernel_addr_r} zImage 
		
![Screenshot from 2024-07-28 17-16-54](https://github.com/user-attachments/assets/d7ba58e6-62a7-476a-8a84-ff39aea04fd3)

## loading the dtb file from the tftp server

		tftp ${fdt_addr_r} vexpress-v2p-ca9.dtb
		
![Screenshot from 2024-07-28 17-18-49](https://github.com/user-attachments/assets/b4feed32-b282-464e-970b-047ed6307c63)

## Boot the Kernel and mount rootfs from NFS server

		bootz ${kernel_addr_r} - ${fdt_addr_r}
		
## the kernel started without any problem

## the shell open and we can run the needed commands 

![Screenshot from 2024-07-28 17-29-53](https://github.com/user-attachments/assets/63abc3b8-5bc2-432a-8515-94d3d8e020e3)

![Screenshot from 2024-07-28 17-30-11](https://github.com/user-attachments/assets/3fe8af42-ec9f-489e-b93a-57e6a7af0972)

# Done 

