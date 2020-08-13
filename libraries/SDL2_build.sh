cd SDL2-2.0.12/build/
../configure
make all
make install

# for libSDL2-2.0.so.3 library
# https://www.gog.com/forum/xenonauts/error_libsdl220so0
sudo apt-get install libsdl2-2.0-0