Aplikasi dicompile arch linux
untuk merun program , jalan command berikut

cd ~/Versi GUI

sudo pacman -S gtk3

gcc pkg-config --cflags gtk+-3.0 app app.c pkg-config --libs gtk+-3.0

./app
