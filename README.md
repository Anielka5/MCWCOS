# MCWCOS
Multi-compatible Console Windows Cover Operational System
--------------------------------------------------------
## What this application is made to be
This app is a Windows shell that acts like a desktop. It is written in C++ and uses the `windows.h` library to set the proper window size, apply the smallest font possible (a 2x2 font, because at 1x1 the window size bugs out), and set a custom font. The app also uses ANSI art to display the interface.

In my custom font, the character 'A' is just a full block. I have written special functions that change both the text color and background color to the same color using `conio.h`. I have also defined the missing `conio.h` functions using `windows.h`.

## Current progress (What is actually implemented)
1. It prints the screen, which is currently displayed as a blue and yellow grid.
2. I have programmed the Escape key to exit the program and restore the normal Windows desktop.
3. While AI helped me with most of the implementation, the entire concept and core idea are mine.

## How to run it and System Requirements
* **System Requirements:** Windows 95 or higher. For older versions of Windows, the behavior is unknown.
* **Prerequisites:** Install a C++ compiler, such as G++.

### How to run:
1. Download the program from GitHub and place it directly on the `C:` drive (into the `C:\MCWCOS` directory).
2. Compile the file `moj_system.cpp` using the following command in your terminal:
   ```cmd
    g++ "C:/MyOS/MCWCOS/moj_system.cpp" -o "C:/MyOS/MCWCOS/MCWCOS.exe" "-Wl,--subsystem,console:4.0" -lgdi32
   ```
3. Once compilation is complete, **run** `MCWCOS.exe` **as an administrator**.

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
* **Solution:** Make sure you are using quotes `""` for paths with spaces. Double-check your absolute path layout (e.g., `C:/MCWCOS/moj_system.cpp`).

## Important Rules for the Project Directory
If you install this program to use it (and not to edit the source code), please follow these rules:
* **Do not change** file or folder names.
* **Do not delete** files or folders, except for the test folders (they do nothing).
* **Do not move** files or folders.
* **Do not edit** the source code directly.

Breaking the first three rules will break the program. Breaking the fourth rule will cause undefined behavior.

