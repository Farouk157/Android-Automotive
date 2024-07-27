# Downloading and configuring our u-boot 

u-boot is an unified bootloader used to flashing new software or updating software with new features 

bootloader in general reads the partition table in the MBR / GPT to identify the active (bootable) partition.

It loads the boot sector of the active partition into DRAM.

1) loads the kernel into the DRAM and pass the control to the kernel

2) loading boot image from FAT partition into memory and running diagnostics

## we will use the U-boot to boot our kernel on the qemu and Raspberry pi

## so we need to install and configure the U-boot on our host machine 

1. Cloning the U-boot Repository

		git clone git@github.com:u-boot/u-boot.git

2. Go to U-boot directory

		cd ~/u-boot/u-boot/

### Now we need to configure the u-boot with the specs that we need 

3. for me i will configure the u-boot for my toolchain vexpress-ca9

	- Set the cross compiler into environment variables to enable the U-boot to use it
		
		export CROSS_COMPILE=path/to/cross/compiler/arm-cortexa9_neon-linux-musleabihf-
	
	- for me and the path that the toolchain exists 
	
		export CROSS_COMPILE=~/x-tools/arm-cortexa9_neon-linux-musleabihf/bin/arm-cortexa9_neon-linux-musleabihf-

![Screenshot from 2024-07-26 23-19-01](https://github.com/user-attachments/assets/b107905a-f182-4313-ba6d-844feebf362a)
	
4. we need to set the architecture as our target 

		export ARCH=arm

![Screenshot from 2024-07-26 23-19-21](https://github.com/user-attachments/assets/064e5108-5a4d-450e-a700-0ccc1075e4cb)

5. Use the default configurations of ARM Vexpress Cortex A9
	
		make vexpress_ca9x4_defconfig

![Screenshot from 2024-07-26 23-26-46](https://github.com/user-attachments/assets/44be8810-6c50-456d-a5e2-b99c84329610)

### now we can start out menuconfig to change and customiz the needed features

6. open the menuconfig 

		make menuconfig 

![Screenshot from 2024-07-27 00-09-20](https://github.com/user-attachments/assets/fc70d27a-2915-41d4-baf8-73401a7a40df)

### let's configure some important command line interfaces

7. open the command line interface 

![Screenshot from 2024-07-27 05-48-54](https://github.com/user-attachments/assets/d2427795-63a9-4d43-9044-429b5fa3a9e1)

### let's configure some important environment commands

8. select the environment commands 

![Screenshot from 2024-07-27 05-54-05](https://github.com/user-attachments/assets/adfdb8f1-6574-414e-a0a5-eb86fc80a486)

9. let's add editenv command to help us edit on the u-boot environment variables 

![Screenshot from 2024-07-27 05-56-10](https://github.com/user-attachments/assets/f745fcb4-39be-4a7b-99d9-43e97b154a7c)

10. Store the environment variable inside file call uboot.env

![Screenshot from 2024-07-27 05-59-06](https://github.com/user-attachments/assets/c1028c5b-b32f-492a-b8cd-db5f24c37e8f)

![Screenshot from 2024-07-27 06-01-44](https://github.com/user-attachments/assets/d067e163-f233-4669-b80c-23dd82c84837)

### configuring the memory commands 

11. configure memory commands 

![Screenshot from 2024-07-27 06-05-15](https://github.com/user-attachments/assets/f3eb8ccd-b5f9-4b6c-9f56-f47ae1b6c897)

![Screenshot from 2024-07-27 06-05-59](https://github.com/user-attachments/assets/e2f7e826-86e2-43db-8687-fabd8fb69c04)

![Screenshot from 2024-07-27 06-06-17](https://github.com/user-attachments/assets/de6b97e6-3795-4586-8b51-71c90f01e103)

![Screenshot from 2024-07-27 06-06-22](https://github.com/user-attachments/assets/5f35b8d4-f752-4a6f-b5e1-bc19f387042b)

12. configure the device access commands then activate lsblk 

![Screenshot from 2024-07-27 06-10-27](https://github.com/user-attachments/assets/4c646940-8454-4a44-b81e-9a082485e4ac)

![Screenshot from 2024-07-27 06-10-45](https://github.com/user-attachments/assets/652b04e3-a412-45bb-b323-8e28b52df014)

13. configure the name of the block device for the enironment by default it's mmc you can change it 

![Screenshot from 2024-07-27 06-15-01](https://github.com/user-attachments/assets/ab461c13-0b10-45a8-9fc0-c6b72507e386)

14. configure the partition where the FAT is store to 0:1

![Screenshot from 2024-07-27 06-15-01](https://github.com/user-attachments/assets/088c9b57-bb61-4ff7-87f1-a6f177c42650)

- then write 0:1

![Screenshot from 2024-07-27 06-16-33](https://github.com/user-attachments/assets/efd7591f-2b89-4373-8dd9-b1e77b717c05)

15. configure the time delay to auto boot as you want i left it 2 as the default 

![Screenshot from 2024-07-27 06-19-41](https://github.com/user-attachments/assets/cfc95002-cb3d-42ad-bf94-fcb575e1aa06)

![Screenshot from 2024-07-27 06-20-16](https://github.com/user-attachments/assets/7fc13254-1ad2-41bd-8c90-60b857602908)

![Screenshot from 2024-07-27 06-20-22](https://github.com/user-attachments/assets/e561c70e-da53-47aa-a4bf-5255b36b44fe)

16. then we can change the default value of the bootcmd variable that runs when we open the u-boot as we want 

17. finally we can save and make 

![Screenshot from 2024-07-27 06-23-29](https://github.com/user-attachments/assets/c609d435-c9fb-4c69-88c2-6a2b339cc555)

![Screenshot from 2024-07-27 06-26-29](https://github.com/user-attachments/assets/536e755c-63ce-47ec-8c4c-166b0df6b062)

### our bootloader U-boot is configured as we want and ready to be used !!


## we need to install Qemu Emulator to test our u-boot on it 

1. installing Qemu for the first time

		sudo apt install qemu-system-arm
		
2. Make sure the qemu-system-arm installed correctly run this command 

		qemu-system-arm --version
		
![Screenshot from 2024-07-27 06-30-17](https://github.com/user-attachments/assets/149c93eb-61e1-48a6-9965-bd17dfb98c99)

## Now our Emulator qemu is ready to emulate our machine 

## we can now test booting from the SD_card and TFTF protocol 

## but let's customize the kernel first to get the needed zImage and .dtb file

		








 	

