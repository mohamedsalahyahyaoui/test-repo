#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "verif.h"


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *window1 ;
    GtkWidget *window2 ;
    GtkWidget *entry1;
    GtkWidget *entry2;
    GtkWidget *label1;
    GtkComboBox *combobox1;
    window1 = lookup_widget(GTK_WIDGET(button),"window1");
    entry1 = lookup_widget(GTK_WIDGET(button),"entry1");
    entry2 = lookup_widget(GTK_WIDGET(button),"entry2");
    label1 = lookup_widget(GTK_WIDGET(button),"label1");
    combobox1 = lookup_widget(GTK_WIDGET(button),"combobox1");

    char password[100];
    char login[100];
    char* combotext;

    combotext = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1));
    gtk_label_set_text(GTK_LABEL(label1),combotext);
    strcpy(login,gtk_entry_get_text(GTK_ENTRY(entry1)));
    strcpy(password,gtk_entry_get_text(GTK_ENTRY(entry2)));
    window2 = create_window2();
    if ((verifier(login,password))==-1)
        {
            gtk_widget_show (window2);
        }
    else if ((verifier(login,password))==1)
        {
        gtk_widget_show(window2);
        }
}

void
on_combobox2_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}

