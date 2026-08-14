# MCWCOS
Multi-compatible Console Windows Cover Operational System
--------------------------------------------------------
## What this application is made to be
This app is a Windows shell that acts like a desktop. It is written in C++ and uses the `windows.h` library to set the proper window size and apply the smallest font possible (a 2x2 font, because at 1x1 the window size bugs out). 

Instead of slow standard printing methods, the system utilizes a high-performance rendering engine built around the native `WriteConsoleOutputW()` API. It writes direct pixel data into a global screen buffer (`CHAR_INFO`), allowing the layout to render instantly. In this system, the character 'A' acts as a solid pseudo-pixel block. Special custom editing functions (`printSpecialA`) handle positioning, drawing, and fast buffer flushing via the `endPrintA` header file.

## Current progress (What is actually implemented)
1. It instantly prints the screen layout, which is currently displayed as a fast blue and yellow grid.
2. It includes a smart operating system detector that targets Windows 11-specific DWM (Desktop Window Manager) behavior to ensure clean window closure.
3. I have programmed the Escape key to exit the program, safely terminate the custom process layer, and restore the normal Windows desktop.
4. While AI helped me with some of the implementation details, the entire architecture, concept, and core logic are mine.

## How to run it and System Requirements
* **System Requirements:** Windows 95 up to Windows 11. For versions older than Win95, the behavior is unknown.
* **Prerequisites:** Install a C++ compiler, such as G++.

### How to run:
1. Download the program from GitHub and place it directly into the `C:/MyOS/MCWCOS/` directory.
2. Compile the file `sys.cpp` using the following command in your terminal:
   ```cmd
   g++ "C:/MyOS/MCWCOS/sys.cpp" -o "C:/MyOS/MCWCOS/MCWCOS.exe" "-Wl,--subsystem,console:4.0" -lgdi32
   ```
3. Once compilation is complete, **run** `MCWCOS.exe` **as an administrator** directly via `conhost.exe` (Windows Console Host).

## Troubleshooting (Compiler Issues)
If you encounter issues while compiling the project, check the solutions below:

### 1. 'g++' is not recognized as an internal or external command
* **Cause:** The GCC/MinGW compiler is not installed, or its path is not added to the system Environment Variables (PATH).
* **Solution:** Download and install MinGW. Then, add the `bin` folder path (e.g., `C:\MinGW\bin`) to your Windows PATH environment variables. Restart your terminal (cmd) and try again.

### 2. Access Denied (Permission Error)
* **Cause:** The output file (`.exe`) might still be running in the background, or the folder is locked by another process (like `conhost.exe`).
* **Solution:** Close all open console windows, or open Task Manager (`Ctrl + Shift + Esc`) and terminate any active `MCWCOS.exe` or `Console Window Host` processes.

### 3. No such file or directory
* **Cause:** The compiler cannot find your source file at the specified path.
* **Solution:** Make sure you are using quotes `""` for paths with spaces. Double-check your absolute path layout (e.g., `C:/MyOS/MCWCOS/sys.cpp`).

## Important Rules for the Project Directory
If you install this program to use it (and not to edit the source code), please follow these rules:
* **Do not change** file or folder names.
* **Do not delete** files or folders, except for the test folders (they do nothing and contain legacy/abandoned font experiments).
* **Do not move** files or folders.
* **Do not edit** the source code directly.

Breaking the first three rules will break the program. Breaking the fourth rule will cause undefined behavior.
