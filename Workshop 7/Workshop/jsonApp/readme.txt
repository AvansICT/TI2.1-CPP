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

7. Download the nlohmann json library
wget https://github.com/nlohmann/json/archive/refs/tags/v3.12.0.zip

8. Unzip the nlohmann json library 
unzip v3.12.0.zip -d TI2.1-CPP-main/Workshop\ 7/

9. navigate to the unzipped folder
cd TI2.1-CPP-main/Workshop\ 7/Workshop/jsonApp/

10. Create a build folder, copy json example file and navigate to it
mkdir build
cp data.json build/
cd build

11. Make sure g++ is used as C++ compiler
   (note: for c files use the gcc compiler must be used)
export CXX=/usr/bin/g++

12. Run cmake
cmake ..

13. Run make
make

14. Run the program
./jsonApp
