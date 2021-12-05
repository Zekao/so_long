#!/bin/bash -e
sudo apt-get install -yqq clang
sudo apt-get install -yqq libbsd-dev
sudo apt-get install -yqq libx11-dev
sudo apt-get install -yqq libxext-dev
sudo git clone https://github.com/42Paris/minilibx-linux.git minilibx && cd minilibx
sudo ./configure
sudo mkdir -p  /usr/X11/lib  /usr/local/lib  /usr/X11/include /usr/local/include  /usr/X11/man/man3  /usr/local/man/man3
sudo cp libmlx_Linux.a  /usr/X11/lib/ &&  cp libmlx_Linux.a  /usr/local/lib/
sudo cp mlx.h /usr/X11/include/. && cp mlx.h /usr/local/include/.
sudo cp man/man3/mlx*.1  /usr/X11/man/man3 && cp man/man3/mlx* /usr/local/man/man3