# this script to check if the kernel image and dtb file exist on the virsd_card then boot

# if both doesn't exist then will boot from the server using the TFTP 

## first of all let's create the script 

![Screenshot from 2024-07-28 05-23-38](https://github.com/user-attachments/assets/069ebfd4-96ac-48a7-ae60-5248f015d64c)

## if we tried to run this script it will give an error we have to convert it to an image 

### using the mkimage tool in the u-boot 

		mkimage -A arm -T script -C none -n "booting" -d /path/to/source/script /path/to/destination

- [-A] : used for the Architecture 

- [-T] : used for the type 

- [-C] : used for compression type 

- [-n] : used for naming 

- [-d] : used as indecation for the source path 

### we should edit the environment variable bootcmd and load the script.img by it 

		=> editenv bootcmd 
		
		=> edit: fatload mmc 0:1 0x60100000 script.img; setenv kernel_addr_r 0x60200000; saveenv; source 0x60100000

		=> saveenv
		
![Screenshot from 2024-07-28 05-37-21](https://github.com/user-attachments/assets/abae9de8-f3d8-46a8-8685-702cc1d629c7)

- now once we open the qemu the bootcmd will load the script and the script will run 

## now our automation script is ready we have to put it in the bootable partition of the virtual sd_card

## lets test it 

### i won't put the zImage and vexpress in the virtual sd_card and put them in the server 

- lets see what happens in this case 

![Screenshot from 2024-07-28 05-31-44](https://github.com/user-attachments/assets/3c4d3899-6a21-46d0-932f-ea4045358828)

![Screenshot from 2024-07-28 05-31-54](https://github.com/user-attachments/assets/e02c7c41-115b-423a-93a2-fa1af42f1170)

- run this command in the u-boot directory to open the qemu 

		sudo qemu-system-arm -M vexpress-a9 -m 128M --nographic --kernel u-boot --sd ~/sd_ard/sd.img 
		
		-net tap,script=./qemu-ifup -net nic
		
- this command will open the qemu and the bootcmd loads the script and runs 

### in this image we will find that the script failed to load from the sd_card cause the files doesn't exist  

![Screenshot from 2024-07-28 05-42-25](https://github.com/user-attachments/assets/4a1f19e6-94c9-4c43-af6d-29899fc40650)

### here we find that the connection between the server host machine and the qemu was successful 

### and started to load the zImage and dtb file from the server then kernel started 

![Screenshot from 2024-07-28 05-42-32](https://github.com/user-attachments/assets/91b34d6e-d9b3-4537-b510-049c7416ac23)

### finally we find that the kernel got panic cause as we mentioned before there is no root file system 

![Screenshot from 2024-07-28 05-42-37](https://github.com/user-attachments/assets/e09e856b-8674-40ec-a90c-ddf0dc9f0433)


## lastly if we put the zImage and dtb file in the sd_card specially in the FAT partition 

## the booting will start from the sd_card due to the script 





