#include <gtk/gtk.h>
#include "my_function.h"

// Forward declarations for menu actions
void on_edit_data_pasien_clicked(GtkWidget *widget, gpointer data);
void on_edit_riwayat_clicked(GtkWidget *widget, gpointer data);
void on_info_pasien_clicked(GtkWidget *widget, gpointer data);
void on_pendapatan_klinik_clicked(GtkWidget *widget, gpointer data);
void on_info_pasien_pertahun_clicked(GtkWidget *widget, gpointer data);
void on_tanggal_clicked(GtkWidget *widget, gpointer data);

// Forward declarations for submenu actions
void on_edit_data_pasien_edit_clicked(GtkWidget *widget, gpointer data);
void on_edit_data_pasien_hapus_clicked(GtkWidget *widget, gpointer data);
void on_edit_data_pasien_cari_clicked(GtkWidget *widget, gpointer data);
void on_edit_data_pasien_tambah_clicked(GtkWidget *widget, gpointer data);

void on_edit_riwayat_edit_clicked(GtkWidget *widget, gpointer data);
void on_edit_riwayat_hapus_clicked(GtkWidget *widget, gpointer data);
void on_edit_riwayat_cari_clicked(GtkWidget *widget, gpointer data);
void on_edit_riwayat_tambah_clicked(GtkWidget *widget, gpointer data);

// Forward declaration for common functions
void on_back_to_main_menu(GtkWidget *widget, gpointer data);

// Main window
GtkWidget *main_window;
GtkWidget *main_box;

void clear_window() {
    GList *children, *iter;

    children = gtk_container_get_children(GTK_CONTAINER(main_box));
    for (iter = children; iter != NULL; iter = g_list_next(iter)) {
        gtk_widget_destroy(GTK_WIDGET(iter->data));
    }
    g_list_free(children);
}

void create_main_menu() {
    clear_window();

    GtkWidget *button;
    //fitur 1
    button = gtk_button_new_with_label("Edit Data Pasien");
    g_signal_connect(button, "clicked", G_CALLBACK(on_edit_data_pasien_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);
    //fitur 2
    button = gtk_button_new_with_label("Edit Riwayat");
    g_signal_connect(button, "clicked", G_CALLBACK(on_edit_riwayat_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);
    //fitur 3
    button = gtk_button_new_with_label("Info Pasien");
    g_signal_connect(button, "clicked", G_CALLBACK(on_info_pasien_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);
    //fitur 4
    button = gtk_button_new_with_label("Pendapatan Klinik");
    g_signal_connect(button, "clicked", G_CALLBACK(on_pendapatan_klinik_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);
    //fitur 5
    button = gtk_button_new_with_label("Info Pasien Per Tahun");
    g_signal_connect(button, "clicked", G_CALLBACK(on_info_pasien_pertahun_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);
    //fitur 6
    button = gtk_button_new_with_label("Cek Pasien perlu datang");
    g_signal_connect(button, "clicked", G_CALLBACK(on_tanggal_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);
    
    gtk_widget_show_all(main_window);
}

// Function to create submenus for "Edit Data Pasien" and "Edit Riwayat"
void create_submenu(const char *title, GCallback edit_callback, GCallback hapus_callback, GCallback cari_callback, GCallback tambah_callback) {
    clear_window();

    GtkWidget *label = gtk_label_new(title);
    gtk_box_pack_start(GTK_BOX(main_box), label, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Edit");
    g_signal_connect(button, "clicked", edit_callback, NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Hapus");
    g_signal_connect(button, "clicked", hapus_callback, NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Cari");
    g_signal_connect(button, "clicked", cari_callback, NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Tambah");
    g_signal_connect(button, "clicked", tambah_callback, NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Kembali");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_edit_data_pasien_clicked(GtkWidget *widget, gpointer data) {
    create_submenu("Edit Data Pasien", G_CALLBACK(on_edit_data_pasien_edit_clicked), G_CALLBACK(on_edit_data_pasien_hapus_clicked), G_CALLBACK(on_edit_data_pasien_cari_clicked), G_CALLBACK(on_edit_data_pasien_tambah_clicked));
}

void on_edit_riwayat_clicked(GtkWidget *widget, gpointer data) {
    create_submenu("Edit Riwayat", G_CALLBACK(on_edit_riwayat_edit_clicked), G_CALLBACK(on_edit_riwayat_hapus_clicked), G_CALLBACK(on_edit_riwayat_cari_clicked), G_CALLBACK(on_edit_riwayat_tambah_clicked));
}

void on_info_pasien_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *label = gtk_label_new("Pasien ini sedang tidak available");
    gtk_box_pack_start(GTK_BOX(main_box), label, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Kembali");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_pendapatan_klinik_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *label = gtk_label_new("Data belum tersedia");
    gtk_box_pack_start(GTK_BOX(main_box), label, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Kembali");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_info_pasien_pertahun_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Masukkan tahun");
    gtk_box_pack_start(GTK_BOX(main_box), entry, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Kembali");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_tanggal_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry_day = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_day), "Masukkan hari");
    gtk_box_pack_start(GTK_BOX(main_box), entry_day, TRUE, TRUE, 0);

    GtkWidget *entry_month = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_month), "Masukkan bulan");
    gtk_box_pack_start(GTK_BOX(main_box), entry_month, TRUE, TRUE, 0);

    GtkWidget *entry_year = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_year), "Masukkan tahun");
    gtk_box_pack_start(GTK_BOX(main_box), entry_year, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry_day);
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry_month);
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry_year);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Kembali");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

//fitur 1 edit data pasien
void on_edit_data_pasien_edit_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *grid;
    GtkWidget *id_label, *type_label, *change_label;
    GtkWidget *id_entry, *type_entry, *change_entry;

    // Create a new dialog with buttons
    dialog = gtk_dialog_new_with_buttons("Edit Data Pasien",
                                         GTK_WINDOW(main_window),
                                         GTK_DIALOG_MODAL,
                                         "_Submit", GTK_RESPONSE_ACCEPT,
                                         "_Close", GTK_RESPONSE_REJECT,
                                         NULL);

    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Create and add labels and entry fields to the grid
    id_label = gtk_label_new("ID Pasien:");
    type_label = gtk_label_new("Tipe Data yang Akan Diubah:");
    change_label = gtk_label_new("Perubahan:");

    id_entry = gtk_entry_new();
    type_entry = gtk_entry_new();
    change_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), type_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), type_entry, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), change_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), change_entry, 1, 2, 1, 1);

    // Show all widgets in the dialog
    gtk_widget_show_all(dialog);

    // Run the dialog and capture the response
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_ACCEPT) {
        // Retrieve text from the entry fields and call miaw function
        const char *id = gtk_entry_get_text(GTK_ENTRY(id_entry));
        const char *type = gtk_entry_get_text(GTK_ENTRY(type_entry));
        const char *change = gtk_entry_get_text(GTK_ENTRY(change_entry));
        ubah_data_pasien(id , type , change);

        ;
    }

    // Destroy the dialog after handling the response
    gtk_widget_destroy(dialog);
}


void on_edit_data_pasien_hapus_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Masukkan ID");
    gtk_box_pack_start(GTK_BOX(main_box), entry, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    GtkWidget *back_button = gtk_button_new_with_label("Kembali");
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), back_button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_edit_data_pasien_cari_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Masukkan ID");
    gtk_box_pack_start(GTK_BOX(main_box), entry, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    GtkWidget *label = gtk_label_new("Data tidak ditemukan");
    gtk_box_pack_start(GTK_BOX(main_box), label, TRUE, TRUE, 0);

    GtkWidget *back_button = gtk_button_new_with_label("Kembali");
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), back_button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_edit_data_pasien_tambah_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Masukkan ID");
    gtk_box_pack_start(GTK_BOX(main_box), entry, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    GtkWidget *back_button = gtk_button_new_with_label("Kembali");
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), back_button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_edit_riwayat_edit_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Masukkan ID");
    gtk_box_pack_start(GTK_BOX(main_box), entry, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    GtkWidget *back_button = gtk_button_new_with_label("Kembali");
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), back_button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_edit_riwayat_hapus_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Masukkan ID");
    gtk_box_pack_start(GTK_BOX(main_box), entry, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    GtkWidget *back_button = gtk_button_new_with_label("Kembali");
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), back_button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_edit_riwayat_cari_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Masukkan ID");
    gtk_box_pack_start(GTK_BOX(main_box), entry, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    GtkWidget *label = gtk_label_new("Data tidak ditemukan");
    gtk_box_pack_start(GTK_BOX(main_box), label, TRUE, TRUE, 0);

    GtkWidget *back_button = gtk_button_new_with_label("Kembali");
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), back_button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_edit_riwayat_tambah_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), "Masukkan ID");
    gtk_box_pack_start(GTK_BOX(main_box), entry, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    GtkWidget *back_button = gtk_button_new_with_label("Kembali");
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), back_button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
}

void on_back_to_main_menu(GtkWidget *widget, gpointer data) {
    create_main_menu();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(main_window), "Main Menu");
    gtk_window_set_default_size(GTK_WINDOW(main_window), 300, 200);
    g_signal_connect(main_window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(main_window), main_box);

    create_main_menu();

    gtk_widget_show_all(main_window);
    gtk_main();

    return 0;
}

