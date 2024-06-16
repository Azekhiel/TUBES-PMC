#include <gtk/gtk.h>
#include <string.h>

// Struct to hold form data
typedef struct {
    GtkWidget *entry_name;
    GtkWidget *entry_nim;
    GtkWidget *entry_dob;
    GtkWidget *window;
    GtkWidget *view_grid;
    GtkWidget *form_grid;
    GtkWidget *label_view_name;
    GtkWidget *label_view_nim;
    GtkWidget *label_view_dob;
} FormData;

// Callback function to print the form data and switch to view mode
void on_save_button_clicked(GtkWidget *widget, gpointer data) {
    FormData *form_data = (FormData *)data;

    const gchar *name = gtk_entry_get_text(GTK_ENTRY(form_data->entry_name));
    const gchar *nim = gtk_entry_get_text(GTK_ENTRY(form_data->entry_nim));
    const gchar *dob = gtk_entry_get_text(GTK_ENTRY(form_data->entry_dob));

    g_print("Name: %s\n", name);
    g_print("NIM: %s\n", nim);
    g_print("Date of Birth: %s\n", dob);

    gtk_label_set_text(GTK_LABEL(form_data->label_view_name), name);
    gtk_label_set_text(GTK_LABEL(form_data->label_view_nim), nim);
    gtk_label_set_text(GTK_LABEL(form_data->label_view_dob), dob);

    gtk_widget_hide(form_data->form_grid);
    gtk_widget_show(form_data->view_grid);
}

// Callback function to switch to edit mode
void on_edit_button_clicked(GtkWidget *widget, gpointer data) {
    FormData *form_data = (FormData *)data;

    gtk_widget_hide(form_data->view_grid);
    gtk_widget_show(form_data->form_grid);
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *form_grid;
    GtkWidget *view_grid;
    GtkWidget *label_name;
    GtkWidget *label_nim;
    GtkWidget *label_dob;
    GtkWidget *entry_name;
    GtkWidget *entry_nim;
    GtkWidget *entry_dob;
    GtkWidget *button_save;
    GtkWidget *label_view_name;
    GtkWidget *label_view_nim;
    GtkWidget *label_view_dob;
    GtkWidget *button_edit;

    FormData form_data;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Form Application");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Connect the destroy signal of the window to gtk_main_quit to close the application
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a grid to arrange form widgets
    form_grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(form_grid), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(form_grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), form_grid);

    // Create labels and entries for name, NIM, and date of birth
    label_name = gtk_label_new("Name:");
    gtk_grid_attach(GTK_GRID(form_grid), label_name, 0, 0, 1, 1);
    entry_name = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(form_grid), entry_name, 1, 0, 2, 1);

    label_nim = gtk_label_new("NIM:");
    gtk_grid_attach(GTK_GRID(form_grid), label_nim, 0, 1, 1, 1);
    entry_nim = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(form_grid), entry_nim, 1, 1, 2, 1);

    label_dob = gtk_label_new("Date of Birth:");
    gtk_grid_attach(GTK_GRID(form_grid), label_dob, 0, 2, 1, 1);
    entry_dob = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(form_grid), entry_dob, 1, 2, 2, 1);

    // Save the entry widgets in the form_data struct
    form_data.entry_name = entry_name;
    form_data.entry_nim = entry_nim;
    form_data.entry_dob = entry_dob;
    form_data.window = window;
    form_data.form_grid = form_grid;

    // Create a save button
    button_save = gtk_button_new_with_label("Save");
    gtk_grid_attach(GTK_GRID(form_grid), button_save, 1, 3, 1, 1);

    // Connect the save button click event to the callback function
    g_signal_connect(button_save, "clicked", G_CALLBACK(on_save_button_clicked), &form_data);

    // Create a grid to arrange view widgets
    view_grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(view_grid), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(view_grid), TRUE);
    gtk_container_add(GTK_CONTAINER(window), view_grid);

    label_view_name = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(view_grid), label_view_name, 0, 0, 1, 1);

    label_view_nim = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(view_grid), label_view_nim, 0, 1, 1, 1);

    label_view_dob = gtk_label_new("");
    gtk_grid_attach(GTK_GRID(view_grid), label_view_dob, 0, 2, 1, 1);

    button_edit = gtk_button_new_with_label("Edit");
    gtk_grid_attach(GTK_GRID(view_grid), button_edit, 0, 3, 1, 1);

    form_data.view_grid = view_grid;
    form_data.label_view_name = label_view_name;
    form_data.label_view_nim = label_view_nim;
    form_data.label_view_dob = label_view_dob;

    // Connect the edit button click event to the callback function
    g_signal_connect(button_edit, "clicked", G_CALLBACK(on_edit_button_clicked), &form_data);

    // Initially show the form grid and hide the view grid
    gtk_widget_show(form_grid);
    gtk_widget_hide(view_grid);

    // Show all widgets in the window
    gtk_widget_show_all(window);

    // Main loop
    gtk_main();

    return 0;
}

