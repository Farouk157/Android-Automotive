# booting manually from the virtual SD_card 

## we have created our own virtual SD_card you can check it out from this link

(https://github.com/Farouk157/Android-Automotive/tree/main/Embedded_Linux/virtual_sd_card)

## I installed and configured our bootloader which is u-boot here is the link

(https://github.com/Farouk157/Android-Automotive/tree/main/Embedded_Linux/u_boot)

## I installed the emulator qemu also at the last link with u-boot

## I installed my needed kernel which is linux, customized it and generated the zImage and dtb file

(https://github.com/Farouk157/Android-Automotive/tree/main/Embedded_Linux/customize_kernel) 

## Now i need to boot that kernel from the virtual SD_card using the u-boot and trace it with qemu

1. lets take our zImage and put it into the bootable partition boot in the virtual sd_card 

![Screenshot from 2024-07-27 08-26-35](https://github.com/user-attachments/assets/56045754-13d8-4871-9e84-38fcb355bc23)

2. lets do the same with the vexpress_p2v_ca9.dtb copy it to the bootable FAT boot partition

![Screenshot from 2024-07-27 08-30-19](https://github.com/user-attachments/assets/240ad791-88c5-45bc-b9a9-7094692feb6b)

3. I'm ready now to launch the qemu and start booting manually 

- I can run the qemu with that command 

		qemu-system-arm -M vexpress-a9 -m 128M --nographic -kernel u-boot -sd ~/sd_ard/sd.img  
		
![Screenshot from 2024-07-27 08-33-52](https://github.com/user-attachments/assets/5a8a7233-1fc8-4f70-b9bb-ac87c8c95459)

4. check the mmc dev connected or not

![Screenshot from 2024-07-27 08-35-27](https://github.com/user-attachments/assets/a67204d7-f336-45ed-b0d2-484726d18b2a)

5. I will load the zImage now from bootable partition of the sd_card

		fatload mmc 0:1 ${kernel_addr_r} zImage

- run this command to make sure that it's loaded 

		md ${kernel_addr_r}
		
![Screenshot from 2024-07-27 08-39-32](https://github.com/user-attachments/assets/f2c210e3-ab89-4926-afdc-6a5c8f54f92c)

6. I will load the vexpress-v2p-ca9.dtb now from bootable partition of the sd_card

		fatload mmc 0:1 ${fdt_addr_r} vexpress-v2p-ca9.dtb

- run this command to make sure that it's loaded 

		md ${fdt_addr_r}
		
![Screenshot from 2024-07-27 08-42-42](https://github.com/user-attachments/assets/30a18466-0f6f-4eaa-b55e-c78e44586652)

7. now we can try to start the kernel by using this command 

		bootz ${kernel_addr_r} - ${fdt_addr_r}
		
![Screenshot from 2024-07-27 08-47-49](https://github.com/user-attachments/assets/61f4dd65-d504-496b-979d-1e95c2bd5e35)


## if you got that kernel panic means everything is going fine till now 

## it gives panic cause its only need for the root filesystem to work 

## so now out virtual SD_Card, U-boot , Qemu and customized kernel is working fine.

## Done 

	


