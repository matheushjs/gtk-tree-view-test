#include <gtk/gtk.h>

#include "app.h"
#include "appwin.h"

struct _App {
  GtkApplication parent;
};

G_DEFINE_TYPE(App, app, GTK_TYPE_APPLICATION);

static void app_init (App *app) {
}

static void app_activate (GApplication *app) {
  AppWindow *win;

  win = app_window_new (APP_CAST (app));
  gtk_window_present (GTK_WINDOW (win));
}

static void
app_open (GApplication  *app,
          GFile        **files,
          gint           n_files,
          const gchar   *hint)
{
  GList *windows;
  AppWindow *win;
  int i;

  windows = gtk_application_get_windows (GTK_APPLICATION (app));
  if (windows)
    win = APP_WINDOW (windows->data);
  else
    win = app_window_new (APP_CAST (app));

  for (i = 0; i < n_files; i++)
    app_window_open (win, files[i]);

  gtk_window_present (GTK_WINDOW (win));
}

static void app_class_init (AppClass *class) {
  G_APPLICATION_CLASS (class)->activate = app_activate;
  G_APPLICATION_CLASS (class)->open = app_open;
}

App * app_new (void) {
  return g_object_new (APP_TYPE,
                       "application-id", "org.gtk.app",
                       "flags", G_APPLICATION_HANDLES_OPEN,
                       NULL);
}
