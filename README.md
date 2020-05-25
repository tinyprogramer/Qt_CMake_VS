This is a HelloWolrd project for Qt,I build it in Window7
The version of softwares are:

**Qt 5.10.1**

**Visual Studio 2017**

**CMake 3.17.1**

**You can build it with following steps:**

1. clone or pull code to your computer

2. modify CMAKE\_PREFIX\_PATH in the following line in CMakeLists.txt with the **qt install path** in your own computer :

    set(CMAKE_PREFIX_PATH F:/QT/5.10.1/msvc2017_64)  

3. open cmd ***or*** git bash in the codes directory,input

     build.bat ***or*** ./build.bat  



Then you will get a subdirectory named **build** with VS project in it.

For more detailed steps and interprets you can go to [my CSDN blog](https://blog.csdn.net/qq_41961619/article/details/106288798)