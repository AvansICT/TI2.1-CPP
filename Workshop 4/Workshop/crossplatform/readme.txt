Linux build steps

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
unzip TI2.1-CPP-main.zip

7. navigate to the unzipped folder
cd /TI2.1-CPP-main/Workshop\ 4/Workshop/crossplatform/

8. Create a build folder and navigate to it
mkdir build
cd build

9. Make sure gcc is used as compiler
export CXX=/usr/bin/gcc

9. Run cmake
cmake ..

10. Run make
make

11. Run the program
./MyApp
