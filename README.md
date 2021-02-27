# Loop n' Loops
A CS101 project developed by Sankalp Bhamare, utilizing the simplecpp library.

The project features many OOPS concepts and C++ functionality, it also uses basic threading. ( essential for most game developemnet ).

To get started read the instruction on how to compile.
##Compile

To compile the source code use the command specified below.

`s++ *.cpp */*.cpp */*/*.cpp */*/*/*.cpp -I. -pthread`


    -I. : is to clarify the inclusion of header files in the current directory
    -pthread : is required for the multithreaded part used by the code.


> This command may not be that nice as it involes using '*' in listing all c++.


In the project there is also a run script attached which invokes the above without using wildcards.

##CMake
This project has cmake support , but you would need to open cmake file and make few changes:
1. You would need to include the simplecpp header file directory , this cannot be auto configured as it is system dependent.
2. X11 libraries must be properly linked check the path specified in the cmake file and your system files to make sure it matches.

> Project has been tested on Ubuntu 20.02 and 18.02.
> Macos and Windows OS users are adviced to use Method 1 for compilation of code as it is more easy.


##Binaries

Binary built on ubuntu 18.02 is available here.

 [binary_LoopNLoopsUbuntu18.02](www.google.com)
 
> Compatible with 18.02 and Up.