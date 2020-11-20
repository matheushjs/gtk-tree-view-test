all:
	glib-compile-resources app.gresource.xml --target=resources.c --generate-source
	gcc main.c app.c appwin.c resources.c -o prog `pkg-config --cflags --libs gtk+-3.0`
