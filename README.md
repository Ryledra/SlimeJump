 # Slime Jump

 A 2D vertical jump platformer

 # Dependencies

   C++ Compiler with compatibilty to C++17 Standard.

   GLFW installed.

   The correct verion of libglfw.dylib for your system (OS & CPU architecture) must be within the build environment library path. See https://github.com/glfw/glfw for details. lib/libglfw_installation is a bash script that will download, compile, extract and cleanup, a valid copy of these files for MacOS 12.6 onwards; use `echo export LIBRARY_PATH=$LIBRARY_PATH:${PWD} >> ~/.zprofile` to add location to build environment path.

 # To Build

 From the project root directory, run the command:

   `make`

 To rebuild the project, use the command:

   `make clean && make`

 # To Run

 From the project root directory, run the command:

   `./bin/SlimeJump`