There is a bug in Rhythmbox application, which is caused by a GtkTreeView widget that is catching the same signal twice.

The GtkTreeView has a nice embedded feature, which is a search box that appears when:
	- The GtkTreeView has the focus
	- The user presses a letter key, indicating they want to type a search string

This requires the GtkTreeView to listen to the key_pressed signal. The problem is that in Rhythmbox it is answering to the signal twice, thus adding double letters to the associated GtkEntry.
