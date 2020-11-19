all:
	gcc main.c app.c appwin.c -o prog `pkg-config --cflags --libs gtk+-3.0`
