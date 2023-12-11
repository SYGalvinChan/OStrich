# Learnings

## Introductions
This file shall document the concepts learnt and issues faced, ideally will be updated daily.

### Set up Development Environment
Run `Systeminfo` in the command prompt to view information about your system.

Here are the specifications of my system:
OS Name: Microsoft Windows 10 Pro
System Manufacturer: MSI
System Model: MS-7A40
System Type: x64-based PC
Processor: AMD Ryzen

I will be using Windows Subsystem for Linuxi, Ubuntu distribution for development. When launching Ubuntu,
I faced "Error: 0x80370102" which required me to boot to BIOS and enable Virtualization. This setting was found under` SVM`.
### Cross Compiler
Since I am targeting to implement OStrich on a Raspberry Pi 4 which uses an ARM processor, I need a compiler that takes in my C/C++ code and outputs ARM instructions.
Hence a cross compiler is nessecary for this project. I downloaded a pre-built GCC toolchain from https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads, under x86_64 Linux hosted cross compilers -> AArch64 ELF bare-metal target (aarch64-none-elf). I then extracted the file using `tar -xf <file-name>`
