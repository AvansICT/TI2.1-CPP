Linux build steps for myApp

1. Open terminal

2. Install gcc and g++ compilers
sudo apt install gcc
sudo apt install g++

3. Install cmake and make
sudo apt install cmake
sudo apt install make

4. Install unzip
sudo apt install unzip

5. Download the zip file from github
wget https://github.com/AvansICT/TI2.1-CPP/archive/refs/heads/main.zip

6. Unzip the file
unzip main.zip

7. navigate to the unzipped folder
cd TI2.1-CPP-main/Workshop\ 6/Opdracht/reductie/

8. Create a build folder and navigate to it
mkdir build
cd build

9. Make sure g++ is used as C++ compiler
   (note: for c files use the gcc compiler must be used)
export CXX=/usr/bin/g++

11. Run cmake
cmake ..

12. Run make
make

13. Run the program
./OpenMPFibonacci
