#ifndef _APP_H_
#define _APP_H_

#define APP_TYPE (app_get_type())
G_DECLARE_FINAL_TYPE (App, app, APP, CAST, GtkApplicationWindow)

App * app_new (void);

#endif
