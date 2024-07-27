# customize kernel 

## what is kernel ?

- kernel is a software manager that manage the hardware resources, it lays between the user space layer and hardware

- when the user space wants to access the hardware to run a specific process the application must invoke

a system call to the Kernel and the kernel will handel the rest 


## in my task i'm going to use the Linux Kernel 

## let's setup and customize the linux kernel 

1. Download Linux Kernel

		git clone --depth=1 git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
		
![Screenshot from 2024-07-27 07-05-35](https://github.com/user-attachments/assets/11301640-464b-4ee0-abfd-32d1933016e3)

2. let's specific the kernel to our target vexpress_ca9

		export CROSS_COMPILE=path/to/cross/compiler/arm-cortexa9_neon-linux-musleabihf-

- for me: 
		
		export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-

![Screenshot from 2024-07-27 07-10-36](https://github.com/user-attachments/assets/b24df276-d97f-45f9-abab-e3ea936de31b)

3. set the Architecture 

		export ARCH=arm

![Screenshot from 2024-07-27 07-11-49](https://github.com/user-attachments/assets/621be1e7-6f8b-44a1-9c76-beeec434287a)

4. Then Run Make to configure the Vexpress a9

		make vexpress_defconfig

![Screenshot from 2024-07-27 07-13-56](https://github.com/user-attachments/assets/d258fb76-fd0c-4b1d-b6b8-3eb9978d0102)

### we are ready now to start the kernel menuconfig and customize it as we need to generate our image 

5. open the kernel menuconfig 

		make menuconfig 

![Screenshot from 2024-07-27 07-16-31](https://github.com/user-attachments/assets/dd8f09fe-1627-4bc0-be3f-37b1f93d2e50)

6. let's select the compression mode of our image to (XZ) instead of Gzip 

6.1. go to general setting then kernel compression mode

![Screenshot from 2024-07-27 07-18-31](https://github.com/user-attachments/assets/ba995a7a-3edf-4ec5-8518-65bf8974fe28)

6.2. select XZ 
	
![Screenshot from 2024-07-27 07-19-37](https://github.com/user-attachments/assets/e029fba8-f911-4641-8675-eea27f1c680a)

7. let's configure the devtmpfs (device temporary filesystem)

7.1. go to Device Drivers 

![Screenshot from 2024-07-27 07-23-05](https://github.com/user-attachments/assets/2655b938-e094-44af-b8d5-ec45e0339427)

7.2. go to generic driver options 

![Screenshot from 2024-07-27 07-24-12](https://github.com/user-attachments/assets/6c303c10-08f4-47b5-af86-6682e96cb1cc)

7.3. activate Automount devtmpfs at /dev, after the kernel mounted the rootfs 

![Screenshot from 2024-07-27 07-25-48](https://github.com/user-attachments/assets/b4b153c4-3a2e-4c8e-b024-ce4b6e70816a)

8. let's build and our kernel and generate our compressed zImage and .dtb files

		make -j4 zImage modules dtbs  
		
![Screenshot from 2024-07-27 07-33-38](https://github.com/user-attachments/assets/7c4ff02c-6355-4139-a7f1-42c87d5dcd56)


## we now have our customized kernel image

![Screenshot from 2024-07-27 07-56-44](https://github.com/user-attachments/assets/0edf6f0a-fe94-477c-b722-c0f3dd8b9cc4)

9. we can find our zImage here 

		/home/farouk/kernel/linux/arch/arm/boot

![Screenshot from 2024-07-27 08-00-21](https://github.com/user-attachments/assets/d6ba89ba-0690-4aba-bb1f-f3c48d8c7de1)

10. we can find out vexpress_n2v_ca9.dtb file here 

		/home/farouk/kernel/linux/arch/arm/boot/dts/arm
		
![Screenshot from 2024-07-27 08-03-05](https://github.com/user-attachments/assets/4a88be9f-cf16-4726-bc9b-a63c76fe8b48)

## Done !!
