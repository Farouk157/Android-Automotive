# initRAMfs Task 

## 1. we create a directory for initRAM 

		mkdir initRam		
		
![1](https://github.com/user-attachments/assets/cbd962a9-6029-40ed-ba80-98795ead0a45)

## 2. I sync all the content of the rootfs i have created before to the new directory 

		sudo rsync -av ~/sd_card/rootfs/ .
		
![2](https://github.com/user-attachments/assets/d0e412a6-9e2d-418e-9b24-aa4f79996793)

![3](https://github.com/user-attachments/assets/891d34c9-b221-4f4a-9fc5-2bd419676224)

## 3. changing the owner for the system user to the root 

		sudo chown -R root:root initRam/
		
![4](https://github.com/user-attachments/assets/d300746d-6506-4c42-bb3a-51c8377750ac)

## 4. I archived the content of the directory 
	
		find . | cpio -ov --owner root:root > ~/temp/archive.cpio
		
![5](https://github.com/user-attachments/assets/3f1009ac-d479-4db8-88cc-92a795aa4959)

## 5. compress the archived format 

		gzip archive.cpio
		
![6](https://github.com/user-attachments/assets/96cd5fc3-f1a8-4529-ba76-97fa1c6c9350)

## 6. then make an image from the compressed file 

		mkimage -A arm -T ramdisk -O linux archive.cpio.gz RAM_FS 

![9](https://github.com/user-attachments/assets/c3cf52bb-7c22-4f08-b334-101118573aae)

## 7. copy this image and put it in the FAT bootable partition 

## 8. run the qemu 

![10](https://github.com/user-attachments/assets/ea76d6d7-3ac9-4a7c-870a-3ad70a93022c)

## 9. set the enviroment variable initRamfs_addr_r 

		setenv initRamfs_addr_r 0x60200000

## 10. start loading the kernel image and dtb file and also the image we made for the initRAM

		fatload mmc 0:1 ${kernel_addr_r} zImage
		
		fatload mmc 0:1 ${fdt_addr_r} vexpress-v2n-ca9.dtb 
		
		fatload mmc 0:1 ${initRam_addr_r} RAM_FS

## 11. finally booting the kernel 

		bootz ${kernel_addr_r} - ${fdt_addr_r} - ${initRam_addr_r}

![11](https://github.com/user-attachments/assets/38d3d4ea-6be2-4605-9127-06090d7b0f76)

## 12. the kernel booted successfully and opened the shell 

![12](https://github.com/user-attachments/assets/3eb3f163-880f-4002-96fd-d3a5b98fd32a)

## Done 

