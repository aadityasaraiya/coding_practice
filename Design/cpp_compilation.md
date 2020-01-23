# C++ Compilation process

## Key Terms

1. **Source code**- Consists of the C++ code which you have written. It will include pre-processor directives and macros which will be resolved in the pre-processing stage.

2. **Object files**- The C++ source file is compiled into an object file. The object files can then be linked to an executable, shared objects libraries, static libraries (just an archive of multiple object files)

This wiki covers the key steps involved in compilation of a C++ file.

## Preprocessing

Pre-processing step involves resolving the pre-processor directives in that particular C++ file. This includes:

* Header files are not passed into the compiler, only source file are. Hence, the header files need to be pasted directly into the source file which are being compiled. 
* Replacing the `#include` and `#define` with their replacements. `#define` is replaced with its provided constant value and `#include` is replaced with the whole `.h` file.
* Macros are also substituted directly.
* After this process, the file is a 'pure C++' file. Tokens are utilized by the compiler in order to be able to backtrack to the respective source if there are any errors.
* The pre-processed code is called a **translation unit**.
* The translation unit becomes bigger and bigger with more included header files. 


## Compilation 

* At a general level, compilation involves the process of converting source code to machine level assembly instructions. 

### Source files Exporting and Importing symbols 

* In order to support overloading, C++ mangles all the exported symbols on compilation. 'Mangling' here means adding random characters in order to separate functions. 

## Linkers
* The core of this step is to **create a single executable file from multiple object files**. 
* Symbols are imported from some other object file. In order to successfully get through the compilation process, we need to **link** the curent object with the one from which the symbols were imported. This would lead to a `missing symbols error`. 
* Linkers only understand C code. Hence, the mangled C++ symbols need to be demangled by the linker. 


## Misc.
* Guarded headers are used to prevent duplication of headers. 
* Const-ness of variables matters only if they are passed by reference. Variables which are passed by value will be modified internally. However, that change will only be till the local scope of the function.


* **Difference between static libraries and shared libraries**

  1. Static libraries, do consist of multiple resuable functions. However, they are all 'locked' inside the executable. 
  2. Shared libraries, on the other hand, includes object files which exist as separate files outside the executable file. 