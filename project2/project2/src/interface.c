/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window1 (void)
{
  GtkWidget *window1;
  GtkWidget *fixed1;
  GtkWidget *entry1;
  GtkWidget *entry2;
  GtkWidget *entry3;
  GtkWidget *name;
  GtkWidget *roll;
  GtkWidget *branch;
  GtkWidget *add;
  GtkWidget *exit;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), _("window1"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (window1), fixed1);

  entry1 = gtk_entry_new ();
  gtk_widget_show (entry1);
  gtk_fixed_put (GTK_FIXED (fixed1), entry1, 208, 56);
  gtk_widget_set_size_request (entry1, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry1), 8226);

  entry2 = gtk_entry_new ();
  gtk_widget_show (entry2);
  gtk_fixed_put (GTK_FIXED (fixed1), entry2, 208, 128);
  gtk_widget_set_size_request (entry2, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry2), 8226);

  entry3 = gtk_entry_new ();
  gtk_widget_show (entry3);
  gtk_fixed_put (GTK_FIXED (fixed1), entry3, 208, 200);
  gtk_widget_set_size_request (entry3, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (entry3), 8226);

  name = gtk_label_new (_("NAME:"));
  gtk_widget_show (name);
  gtk_fixed_put (GTK_FIXED (fixed1), name, 48, 64);
  gtk_widget_set_size_request (name, 60, 17);

  roll = gtk_label_new (_("ROLL:"));
  gtk_widget_show (roll);
  gtk_fixed_put (GTK_FIXED (fixed1), roll, 56, 128);
  gtk_widget_set_size_request (roll, 60, 17);

  branch = gtk_label_new (_("BRANCH:"));
  gtk_widget_show (branch);
  gtk_fixed_put (GTK_FIXED (fixed1), branch, 64, 200);
  gtk_widget_set_size_request (branch, 70, 17);

  add = gtk_button_new_with_mnemonic (_("ADD"));
  gtk_widget_show (add);
  gtk_fixed_put (GTK_FIXED (fixed1), add, 96, 248);
  gtk_widget_set_size_request (add, 70, 29);

  exit = gtk_button_new_with_mnemonic (_("EXIT"));
  gtk_widget_show (exit);
  gtk_fixed_put (GTK_FIXED (fixed1), exit, 208, 248);
  gtk_widget_set_size_request (exit, 69, 29);

  g_signal_connect ((gpointer) add, "clicked",
                    G_CALLBACK (on_add_clicked),
                    NULL);
  g_signal_connect ((gpointer) exit, "clicked",
                    G_CALLBACK (on_exit_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (window1, entry1, "entry1");
  GLADE_HOOKUP_OBJECT (window1, entry2, "entry2");
  GLADE_HOOKUP_OBJECT (window1, entry3, "entry3");
  GLADE_HOOKUP_OBJECT (window1, name, "name");
  GLADE_HOOKUP_OBJECT (window1, roll, "roll");
  GLADE_HOOKUP_OBJECT (window1, branch, "branch");
  GLADE_HOOKUP_OBJECT (window1, add, "add");
  GLADE_HOOKUP_OBJECT (window1, exit, "exit");

  return window1;
}

