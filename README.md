## ADUL
What is ADUL? Now ADUL is just a compilation of some small utilities written by me or taken from other places. In theory they can be useful in any project

# Latest stable version: 0.1.1

# Main points

Main points:
1. This library name stands by Alivka's Different Utilities Library.
2. This library is compilation of some utilities
3. This library also contains tinyxml2 c++ library source files
4. These utilities aren't really well written but may be useful in some scenarios

# Utilities

Utilities:
1. tinyxml2 library source files for working with .xml format files
2. logs module that provides interface for printing logs to any output stream
3. time module for time managing and measuring
4. exceptions module which is compilation of some maybe useful exceptions classes
5. BitVector class


# Notes

Notes:
1. tinyxml2 is not my library, but I find it very useful!
I put it here cause it is compact and i would like to keep it in easy access

# Documentation

The documentation was generated via doxygen tool and [Doxygen-Awesome theme](https://github.com/jothepro/doxygen-awesome-css.git)

Documentation can be found in docs/html/index.

In documentation you can see also private and protected attributes and methods because I think that user should know more about how API he uses work under the hood and with such additional information it can be easier to understand the API functionulity 

I didn't want to add Doxygen-Awesome as dependency so just putted all necessary files into the doxytheme folder

# Build
To build the **ADUL** project using the provided `CMakeLists.txt`, follow these steps:

---

### **1. Basic Build (Linux/macOS/Windows)**
#### **Step 1: Create a Build Directory**
```bash
mkdir build
cd build
```

#### **Step 1: Generate Build Files**
```bash
cmake -S . -B build
```
#### **Step 3: Compile the Project**
```bash
cd build
```
```bash
cmake --build .  # Builds all targets (shared/static libs)
```
- **MinGW (Windows)**:  
  ```bash
  mingw32-make
  ```

#### **Outputs**:
Output will be in either build/lib or build/bin directories depending on your os

---

### **2. Custom Build Options**
#### **Disable Shared/Static Libs**  
Use CMake options to control library types:  
```bash
cmake -S . -B build -DADUL_BUILD_SHARED_LIBS=OFF    # Disable shared libs
cmake -S . -B build -DADUL_BUILD_STATIC_LIBS=OFF    # Disable static libs
```

#### **Set Install Prefix**  
Install to a custom directory (e.g., `$HOME/adul-install`):  
```bash
cmake -S . -B build -DCMAKE_INSTALL_PREFIX=$HOME/adul-install
```

---

### **3. Install the Library**
After building, install headers and libraries to the system or a custom path:  
```bash
cmake --build build --target install  # Requires install prefix or sudo
```
- **Default Install Paths**:
  - Headers: `/usr/local/include` (Linux/macOS)
  - Libraries: `/usr/local/lib`
  - Binaries: `/usr/local/bin`

---

### **4. Use the Library in Another Project**
To use ADUL in your project, add this to your `CMakeLists.txt`:
```cmake
find_package(ADUL REQUIRED)
target_link_libraries(your_target ADUL::ADUL_shared)  # or ADUL::ADUL_static
```
Set `CMAKE_PREFIX_PATH` if ADUL is installed in a non-default location:  
```bash
cmake .. -DCMAKE_PREFIX_PATH=/path/to/adul-install
```

---

### **5. Clean the Build**
```bash
cd build
rm -rf *       # Delete all generated files (Linux/macOS)
# OR
cmake --build build --target clean  # Clean compiled binaries
```

---

### **Troubleshooting**
1. **Missing Headers**: Ensure headers are installed or include paths are set correctly.  
2. **Shared Library Not Found (Linux)**: Add the library path to `LD_LIBRARY_PATH`:  
   ```bash
   export LD_LIBRARY_PATH=/path/to/ADUL/lib:$LD_LIBRARY_PATH
   ```
3. **Windows DLL Issues**: Place `ADUL.dll` in the same directory as your executable.

---

This workflow supports cross-platform builds and allows you to integrate the library seamlessly into other CMake projects.

# To-do and plans

To-do and plans:

# Possible plans

Possible plans:
1. Adding implementations of some algorithms and data structures
(only possible plan because some of them are already implemented in STL)
2. Creating tests for the project
(small chance that i will do it because i am just the definition of word laziness)

# License
This project is licensed under the MIT License.

MIT License

Copyright (c) 2025 Alivka

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.


# Third-Party Sources
This project includes [tinyxml2](https://github.com/leethomason/tinyxml2), 
which is licensed under the zlib License. See [LICENSE-TINYXML2](LICENSE-TINYXML2) for details.

# Third-Party Sources documentations
See [tinyxml2 online documentation](https://leethomason.github.io/tinyxml2/)

# Changelog:
Changelog:
Version 0.1.0: first release(at least I think so) with few little utilities inside
