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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         cd build.linux
make
cd ..
cd test
make
cd ..
build.linux/nachos -x test/cat
build.linux/nachos -x test/copy
build.linux/nachos -x test/concatenate
build.linux/nachos -x test/cat -d u
cd build.linux
make
cd ..
build.linux/nachos -x test/cat -d u
cd build.linux
make
cd ..
build.linux/nachos -x test/cat -d u
cd build.linux
make
cd ..
cd build.linux
make
cd ..
cd test
make
cd ..
build.linux/nachos -x test/cat -d u
cd test
make
cd ..
build.linux/nachos -x test/cat -d u
cd test
make
cd ..
build.linux/nachos -x test/cat -d u
cd build.linux
make
cd ..
build.linux/nachos -x test/cat -d u
cd test
make
cd ..
build.linux/nachos -x test/concatenate -d u
cd build.linux
make
cd ..
cd test
make
cd ..
build.linux/nachos -x test/cat
cd test
make
cd ..
build.linux/nachos -x test/cat
cd test
make
cd ..
build.linux/nachos -x test/cat
cd test
make
cd ..
build.linux/nachos -x test/copy
cd test
make
cd ..
build.linux/nachos -x test/concatenate
git remote add origin https://github.com/Zudarr/HDH_Project.git
git branch -M main
git push -u origin main
git remote set-url origin git://https://github.com/Zudarr/HDH_Project.git
git branch -M main
git push -u origin main
git remote remove origin
