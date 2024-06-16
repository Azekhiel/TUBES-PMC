#include <gtk/gtk.h>

// Forward declarations
void switch_to_window1(GtkWidget *widget, gpointer data);
void switch_to_window2(GtkWidget *widget, gpointer data);

GtkWidget *window1;
GtkWidget *window2;

void switch_to_window1(GtkWidget *widget, gpointer data) {
    gtk_widget_show_all(window1);
    gtk_widget_hide(window2);
}

void switch_to_window2(GtkWidget *widget, gpointer data) {
    gtk_widget_show_all(window2);
    gtk_widget_hide(window1);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Window 1
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window1), "Window 1");
    gtk_window_set_default_size(GTK_WINDOW(window1), 300, 200);
    g_signal_connect(window1, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *button1 = gtk_button_new_with_label("Go to Window 2");
    g_signal_connect(button1, "clicked", G_CALLBACK(switch_to_window2), NULL);
    gtk_container_add(GTK_CONTAINER(window1), button1);

    // Window 2
    window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window2), "Window 2");
    gtk_window_set_default_size(GTK_WINDOW(window2), 300, 200);
    g_signal_connect(window2, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *button2 = gtk_button_new_with_label("Go to Window 1");
    g_signal_connect(button2, "clicked", G_CALLBACK(switch_to_window1), NULL);
    gtk_container_add(GTK_CONTAINER(window2), button2);

    gtk_widget_show_all(window1);

    gtk_main();

    return 0;
}

