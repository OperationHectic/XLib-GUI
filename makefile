compile:
	g++ -o xlib_main xlib_main.cpp -L/usr/X11/lib -lX11 -lstdc++

run:
	./xlib_main
