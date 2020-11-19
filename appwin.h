#ifndef _APP_WIN_H_
#define _APP_WIN_H_

#include <gtk/gtk.h>
#include "app.h"

#define APP_WINDOW_TYPE (app_window_get_type())
G_DECLARE_FINAL_TYPE (AppWindow, app_window, APP, WINDOW, GtkApplicationWindow)

AppWindow *app_window_new(App *app);

void app_window_open(AppWindow *win, GFile *file);

#endif
