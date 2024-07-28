# In this task we want to get the rootfs from the BusyBox and boot our kernel from SD_card

## Download BusyBox

		git clone https://github.com/mirror/busybox.git
		
## set out tool-chain and Architecture 

		export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-

		export ARCH=arm
		
## configure the busybox

		make menuconfig 

![Screenshot from 2024-07-28 06-45-18](https://github.com/user-attachments/assets/954294b0-5104-4cd7-a5ca-9d90b88d4c59)
		
- configure it as static building 

![Screenshot from 2024-07-28 06-45-34](https://github.com/user-attachments/assets/8d788641-14f1-40ef-8c23-6cc631d453d8)

- save and run that command 

		make 

![Screenshot from 2024-07-28 06-52-25](https://github.com/user-attachments/assets/b67ed0d1-96aa-476d-b353-84ed5a9e37b6)

## generate the binaries of rootfs 

		make install 

![Screenshot from 2024-07-28 06-53-04](https://github.com/user-attachments/assets/6119da7b-468f-4494-8331-66b8eef27fa7)

- here is the file that contains my binaries of rootfs

![Screenshot from 2024-07-28 06-54-47](https://github.com/user-attachments/assets/d40ec600-1421-42a8-94df-d127be8f8fd9)

![Screenshot from 2024-07-28 06-56-03](https://github.com/user-attachments/assets/1107d960-6fc4-46ad-9ddc-f0dc60316b4c)

## creating my rootfs and taking these generated binaries copy 

		mkdir rootfs 
		
		rsync -a ~/busybox/busybox/_include/* ~/rootfs
		
![Screenshot from 2024-07-28 06-59-02](https://github.com/user-attachments/assets/6f7a16c2-4caa-44d3-8b3e-ce736a367f73)


## creating the additional directories 

		mkdir boot root home dev etc proc lib sys srv mnt 

![Screenshot from 2024-07-28 07-03-35](https://github.com/user-attachments/assets/3a13ba6e-91cf-404b-aadd-ecbc8797aa04)

## Create a startup script called rcS in etc/init.d/ to do initialization tasks when booting the kernel

		mkdir rootfs/etc/init.d
		
		touch rootfs/etc/init.d/rcS
		
## writing the startup rcS script 

		#!/bin/sh
		
		mount -t proc nodev /proc
		
		mount -t sysfs nodev /sys

![Screenshot from 2024-07-28 07-09-08](https://github.com/user-attachments/assets/48a487d6-3f85-454f-8b7b-162d8295c9a0)

- make that script executable 

![Screenshot from 2024-07-28 07-09-55](https://github.com/user-attachments/assets/136380d0-6010-4bb2-9dbc-bc01514ed3d0)


## Create a Configuration file called inittab in etc directory

		touch etc/inittab
		
## write that configuration file inittab

		vim inittab 
		

		::sysinit:/etc/init.d/rcS

		ttyAMA0::askfirst:-/bin/sh

		::restart:/sbin/init
		
![Screenshot from 2024-07-28 07-14-05](https://github.com/user-attachments/assets/ade189fb-2531-4b18-8f6e-638bd039a99f)

## checking the owner of the rootfs change it to be the root not the host user 

		ls -lh rootfs 
		
![Screenshot from 2024-07-28 07-16-34](https://github.com/user-attachments/assets/da8683b9-34a6-4767-9fc0-b242f6a1dc8f)

		chown root:root rootfs 
		
![Screenshot from 2024-07-28 07-18-25](https://github.com/user-attachments/assets/fe2c28c5-d3a3-40da-ba55-4bb5ddfe13db)

## now mount the p2 of the sd_card on the rootfs directory we made 

		mount /dev/loop5p2 ~/sd_ard/rootfs
		
![Screenshot from 2024-07-28 07-22-15](https://github.com/user-attachments/assets/98b77fe4-2e1f-410a-b2c0-c67f10c2cfa6)

![Screenshot from 2024-07-28 07-27-08](https://github.com/user-attachments/assets/a29e4037-8bad-4a47-9581-6acc93d53781)

## putting the zImage of the kernel and the dtb file in the FAT bootable partition of sd_card 

## lets test booting the kernel using the u-boot and qemu 

		qemu-system-arm -M vexpress-a9 -m 128M --nographic --kernel u-boot --sd ~/sd_card/sd.img 
		
![Screenshot from 2024-07-28 07-39-38](https://github.com/user-attachments/assets/1d6c90c4-10ec-47a4-bd37-358e7a3faddf)

### 1. set the environement variables 

		setenv bootargs 'console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw rootwait init=/sbin/init'
		
![Screenshot from 2024-07-28 07-51-30](https://github.com/user-attachments/assets/8eda7b85-dc79-4de7-8165-c51b46e3ed19) 

### 2. loading the zImage in the kernel_address

		fatload mmc 0:1 ${kernel_addr_r} zImage
			
![Screenshot from 2024-07-28 07-41-19](https://github.com/user-attachments/assets/9f30468d-03f1-43f5-849c-7ecb28af84ce)
 
### 3. loading the dtb file

		fatload mmc 0:1 ${fdt_addr_r} vexpress-v2p-ca9.dtb

![Screenshot from 2024-07-28 07-43-50](https://github.com/user-attachments/assets/1c73ed4e-fa4b-454e-a6ed-1b72f335bd04)



### 4. lets boot the kernel now !

		bootz ${kernel_addr_r} - ${fdt_addr_r} 

![Screenshot from 2024-07-28 07-52-51](https://github.com/user-attachments/assets/127e360c-1710-4911-b6cb-8c1048c68024)

### 5. the kernel booted successfully and the shell opened so we can use the commands 

![Screenshot from 2024-07-28 08-21-55](https://github.com/user-attachments/assets/4d87cd1d-278c-4dcf-b593-1cfde571f07d)

## Done 





