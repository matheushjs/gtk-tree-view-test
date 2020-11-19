#include <gtk/gtk.h>

#include "app.h"
#include "appwin.h"

struct _AppWindow {
  GtkApplicationWindow parent;
};

G_DEFINE_TYPE(AppWindow, app_window, GTK_TYPE_APPLICATION_WINDOW);

static void app_window_init(AppWindow *app){
}

static void app_window_class_init(AppWindowClass *class){
}

AppWindow *app_window_new(App *app){
  return g_object_new(APP_WINDOW_TYPE, "application", app, NULL);
}

void app_window_open(AppWindow *win, GFile *file){
}
