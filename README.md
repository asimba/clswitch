# clswitch  

This program allows you to use 'Caps Lock' key (in MS Windows OS) as a hotkey to switch the keyboard language layout (to toggle 'Caps Lock' mode you can use 'Ctrl+Caps Lock' keys combination).  

---  
Notes:  
_**1) Build instructions (MinGW):**_  
i686-w64-mingw32-g++ -mwindows -static -s -fdata-sections -ffunction-sections -fno-asynchronous-unwind-tables -ffreestanding -nostdlib -Os -Wl,--gc-sections,--strip-all,--entry=_startup -o clswitch32.exe clswitch.c -lkernel32 -luser32  
_or_  
x86_64-w64-mingw32-g++ -mwindows -static -s -fdata-sections -ffunction-sections -fno-asynchronous-unwind-tables -ffreestanding -nostdlib -Os -Wl,--gc-sections,--strip-all,--entry=startup -o clswitch64.exe clswitch.c -lkernel32 -luser32  
  
_**2) Installation:**_  
There is no any automatic install scripts or functions, so you must run the selected executable file manually or you may create link for it in the "Startup" folder ("C:\Users\<user name>\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup")  
  
_**3) Prebuilt binaries:**_ [statically linked x86](https://github.com/asimba/clswitch/releases/download/v1.1/clswitch32.7z) / [statically linked x64](https://github.com/asimba/clswitch/releases/download/v1.1/clswitch64.7z) (_**Warning:**_ Due to the use of the 'SetWindowsHookEx' function, some antivirus programs may give false positive warnings.)  
