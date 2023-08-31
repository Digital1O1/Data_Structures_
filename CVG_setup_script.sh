sudo apt-get update 
sudo apt-get upgrade
sudo apt-get install -y g++
sudo apt-get install -y make
sudo apt-get install -y cmake
sudo apt-get install -y libopencv-dev
sudo apt-get install -y mesa-common-dev freeglut3-dev
cd ~
wget https://github.com/wxWidgets/wxWidgets/releases/download/v3.1.5/wxWidgets-3.1.5.zip
mkdir wxWidgets

cd wxWidgets 
sudo apt-get install -y libgtk-3-dev build-essential
mkdir gtk-build
mv wxWidgets-3.1.5.zip wxWidgets
unzip wxWidgets-3.1.5.zip
cd gtk-build/
../configure --with-opengl --disable-shared --enable-unicode
sudo make
sudo make install

sudo apt-get install -y libssl-dev
sudo apt-get install -y libboost1.67-all
sudo apt-get install -y mesa-common-dev freeglut3-dev
sudo apt-get install -y libftgl-dev
sudo apt-get install -y libfreetype6-dev

cd ~
git clone https://github.com/DCMTK/dcmtk.git 
cd dcmtk
git checkout tags/DCMTK-3.6.7
mkdir build
cd build
cmake ..
make -j8
sudo make install

cd ~
git clone https://github.com/raspberrypi/userland.git
cd userland
sudo ./buildme

cd ~
cd Desktop 
git clone https://github.com/UTSW-Achilefu-Lab/CVG-Tietronix.git
cd CVG-Tietronix
sudo make moves

sudo make clean 
sudo make