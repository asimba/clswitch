# clswitch  

This program allows you to use 'Caps Lock' key (in MS Windows OS) as a hotkey to switch the keyboard language layout (to toggle 'Caps Lock' mode you can use 'Ctrl+Caps Lock' keys combination).  

---  
Notes:  
_**1) Build instructions (MinGW):**_  
i686-w64-mingw32-gcc -mwindows -static -s -fdata-sections -ffunction-sections -fno-asynchronous-unwind-tables -Os -o clswitch32.exe clswitch.c -Wl,--gc-sections,--strip-all  
_or_  
x86_64-w64-mingw32-gcc -mwindows -static -s -fdata-sections -ffunction-sections -fno-asynchronous-unwind-tables -Os -o clswitch64.exe clswitch.c -Wl,--gc-sections,--strip-all  
  
_**2) Installation:**_  
There is no any automatic install scripts or functions, so you must run the selected executable file manually or you may create link for it in the "Startup" folder ("C:\Users\<user name>\AppData\Roaming\Microsoft\Windows\Start Menu\Programs\Startup")  
  
_**3) Prebuilt binaries:**_ [statically linked x86](https://github.com/asimba/clswitch/releases/download/v1.0/clswitch32.7z) / [statically linked x64](https://github.com/asimba/clswitch/releases/download/v1.0/clswitch64.7z)
