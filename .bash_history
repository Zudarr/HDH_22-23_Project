dir
ls
clear
ls
ll
pwd
ls
mkdir nachos
pwd
sudo apt-get install build-essential
dpkg --print-architecture
sudo dpkg --add-architecture i386
ls
clear
zudarr@nachos:~$
sudo apt-get install gcc-multilib g++-multilib
sudo apt-get install lib32ncurses5 lib32z1
sudo apt-get install gcc-4.8 gcc-4.8-multilib g++-4.8 g++-4.8-multilib
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 40
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 40
gcc -v
g++ -v
ls
cd nachos
wget https://www.fit.hcmus.edu.vn/~ntquan/os/assignment/nachos_40.tar.gz
ls
wget https://www.fit.hcmus.edu.vn/~ntquan/os/assignment/mips-decstation.linux-xgcc.gz
wget https://www.fit.hcmus.edu.vn/~ntquan/os/assignment/nachos-gcc.diff.gz
ls
tar zxvf nachos_40.tar.gz
ls
tar zxvf mips-decstation.linux-xgcc.gz
tar zxvf nachos-gcc.diff.gz
ls
patch -p0 < nachos-gcc.diff
ls
cd NachOS-4.0
cd code/build.linux
make depend
make
./nachos
ll
ls
cd ..
clear
cd ..
ll
cd coff2noff
make
cd ../code/test
make
../build.linux/nachos -x halt
ifconfig
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         