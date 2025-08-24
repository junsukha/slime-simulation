# slime-simulation

## Original code: https://github.com/FelipesCoding/slime_mold/tree/main
The original code uses sfml over version 2.x while this repo uses 3.0.
I also use vcpkg to install sfml. 

To use sfml v.3.0, I made minor changes in the code such as the way using functions as there're some changes between sfml v.2.x and v.3.0.


## Build Instructions
1. Clone the repository:
- git clone this repo
2. CD into the newly cloned directory
- cd ./slime-simulation
3. Install dependencies with Vcpkg
- vcpkg install
4. Get the vcpkg cmake toolchain file path
- vcpkg integrate install
- This will output something like : CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake"
5. Create a build directory
- mkdir build
6. Configure project with CMake
- cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
- Use the vcpkg cmake toolchain path from above
7. Build the project
- cmake --build build
8. Run the program
The executables will be located in the build folder