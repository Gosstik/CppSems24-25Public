# Boost

### Installation

Boost official docs: [link](https://www.boost.org/doc/libs/1_87_0/more/getting_started/unix-variants.html).
`Boost.build` docs: [link](https://www.boost.org/doc/libs/1_87_0/tools/build/doc/html/index.html#bbv2.overview.invocation).

Check installation of boost with command:

```bash
sudo dpkg -l | grep boost
apt list --installed | grep boost
```

Install with `apt` packet manager:

```bash
# search for files
sudo apt-cache search boost | grep boost
sudo apt-cache search libboost1.

# install library
sudo apt-get install libboost-all-dev # default version
sudo apt-get install libboost-dev     # default lightweight version
sudo apt-get install -y libboost1.74-dev
```

Check installed [version](https://stackoverflow.com/questions/3708706/how-to-determine-the-boost-version-on-a-system):

```bash
dpkg -s libboost-dev | grep 'Version'
dpkg -s libboost-all-dev | grep 'Version'
```

### Run program

```bash
# download from source
tar --bzip2 -xf /path/to/boost_1_82_0.tar.bz2
cd path/to/boost_1_82_0 # default is /usr/local/boost_1_82_0
./bootstrap.sh --help # to select options
./bootstrap.sh        # build
./b2 install          # install

clang++ -I path/to/boost_1_82_0 example.cpp
```

### Find sources

```bash
sudo find / -name "boost"

ls /usr/include/boost/
find /usr/include/boost/ -name "bind"
```
