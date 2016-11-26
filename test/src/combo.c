#include "combo.h"
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

void fill_combo_box(GtkComboBox *combo){
	FILE *f;
	f = fopen("combo.txt","r");
	char string[100];
	while ( fscanf(f," %s \n",string) != EOF){
		gtk_combo_box_append_text(combo,string);
		
	}
	fclose(f);
}