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
    fitur3();
}

void on_pendapatan_klinik_clicked(GtkWidget *widget, gpointer data) {
    fitur4();
}

void on_info_pasien_pertahun_clicked(GtkWidget *widget, gpointer data) {
    fitur5(main_window);
}

void on_tanggal_clicked(GtkWidget *widget, gpointer data) {
    fitur6();
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
        int result = ubah_data_pasien(id , type , change);
        // Show result message dialog
        GtkWidget *result_dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                                          GTK_DIALOG_DESTROY_WITH_PARENT,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_OK,
                                                          result ? "Data pasien berhasil diubah" : "Gagal meengubah data pasien , cek ID dan Tipe data");
        gtk_dialog_run(GTK_DIALOG(result_dialog));
        gtk_widget_destroy(result_dialog);

        ;
    }

    // Destroy the dialog after handling the response
    gtk_widget_destroy(dialog);
}

//Fitur 1 hapus data pasien
void on_edit_data_pasien_hapus_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *grid;
    GtkWidget *id_label;
    GtkWidget *id_entry;

    // Create a new dialog with buttons
    dialog = gtk_dialog_new_with_buttons("Hapus Pasien",
                                         GTK_WINDOW(data),
                                         GTK_DIALOG_MODAL,
                                         "_OK", GTK_RESPONSE_ACCEPT,
                                         "_Batal", GTK_RESPONSE_REJECT,
                                         NULL);

    // Get the content area of the dialog
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Create and add the label and entry field to the grid
    id_label = gtk_label_new("ID Pasien:");
    id_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);

    // Show all widgets in the dialog
    gtk_widget_show_all(dialog);

    // Run the dialog and capture the response
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_ACCEPT) {
        // Retrieve text from the entry field and call meow function
        const char *hapusid = gtk_entry_get_text(GTK_ENTRY(id_entry));
        int result = hapus_data_pasien(hapusid);
        // Show result message dialog
        GtkWidget *result_dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                                          GTK_DIALOG_DESTROY_WITH_PARENT,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_OK,
                                                          result ? "Data pasien berhasil dihapus" : "Gagal meenghapus data pasien");
        gtk_dialog_run(GTK_DIALOG(result_dialog));
        gtk_widget_destroy(result_dialog);
    }

    // Destroy the dialog after handling the response
    gtk_widget_destroy(dialog);
}

//FItur1 cari data pasien
//Fungsi untuk display data
void display_patient_data(GtkWidget *content_area, dataPasien *current) {
    char buffer[256];

    GtkWidget *label;

    snprintf(buffer, sizeof(buffer), "Nomor Pasien: %d", current->no);
    label = gtk_label_new(buffer);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    snprintf(buffer, sizeof(buffer), "Nama Pasien: %s", current->nama);
    label = gtk_label_new(buffer);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    snprintf(buffer, sizeof(buffer), "Alamat Pasien: %s", current->alamat);
    label = gtk_label_new(buffer);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    snprintf(buffer, sizeof(buffer), "Kota Pasien: %s", current->kota);
    label = gtk_label_new(buffer);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    snprintf(buffer, sizeof(buffer), "Tempat Lahir Pasien: %s", current->tempat_lahir);
    label = gtk_label_new(buffer);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    snprintf(buffer, sizeof(buffer), "Tanggal Lahir Pasien: %s", current->tanggal_lahir);
    label = gtk_label_new(buffer);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    snprintf(buffer, sizeof(buffer), "Umur Pasien: %d", current->umur);
    label = gtk_label_new(buffer);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    snprintf(buffer, sizeof(buffer), "Nomor BPJS Pasien: %s", current->noBPJS);
    label = gtk_label_new(buffer);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    snprintf(buffer, sizeof(buffer), "ID Pasien: %s", current->id);
    label = gtk_label_new(buffer);
    gtk_container_add(GTK_CONTAINER(content_area), label);

    gtk_widget_show_all(content_area);
}
//Fungsi untuk fitur sebenarnya
void on_edit_data_pasien_cari_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog;
    GtkWidget *content_area;
    GtkWidget *grid;
    GtkWidget *id_label;
    GtkWidget *id_entry;

    // Create a new dialog with buttons
    dialog = gtk_dialog_new_with_buttons("Cari Pasien",
                                         GTK_WINDOW(data),
                                         GTK_DIALOG_MODAL,
                                         "_OK", GTK_RESPONSE_ACCEPT,
                                         "_Batal", GTK_RESPONSE_REJECT,
                                         NULL);

    // Get the content area of the dialog
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Create and add the label and entry field to the grid
    id_label = gtk_label_new("ID Pasien:");
    id_entry = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), id_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 1, 1);

    // Show all widgets in the dialog
    gtk_widget_show_all(dialog);

    // Run the dialog and capture the response
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_ACCEPT) {
        // Retrieve text from the entry field and search for patient data
        const char *id = gtk_entry_get_text(GTK_ENTRY(id_entry));
        dataPasien *data_pasien = cari_data_pasien(id);

        // Remove existing widgets in the content area
        GList *children, *iter;
        children = gtk_container_get_children(GTK_CONTAINER(content_area));
        for (iter = children; iter != NULL; iter = g_list_next(iter)) {
            gtk_widget_destroy(GTK_WIDGET(iter->data));
        }
        g_list_free(children);

        // Display the patient data
        if (data_pasien != NULL) {
            display_patient_data(content_area, data_pasien);
        } else {
            GtkWidget *error_label = gtk_label_new("Data pasien tidak ditemukan.");
            gtk_container_add(GTK_CONTAINER(content_area), error_label);
            gtk_widget_show(error_label);
        }
        // Show all the new widgets
        gtk_widget_show_all(dialog);
    } else {
        gtk_widget_destroy(dialog);
    }
}

void on_edit_data_pasien_tambah_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog, *content_area;
    GtkWidget *grid;
    GtkWidget *entry_no, *entry_nama, *entry_alamat, *entry_kota, *entry_tempat_lahir, *entry_tanggal_lahir, *entry_umur, *entry_noBPJS, *entry_id;

    // Create a new dialog with buttons
    dialog = gtk_dialog_new_with_buttons("Tambah Pasien",
                                         GTK_WINDOW(data),
                                         GTK_DIALOG_MODAL,
                                         "_OK", GTK_RESPONSE_ACCEPT,
                                         "_Batal", GTK_RESPONSE_REJECT,
                                         NULL);

    // Get the content area of the dialog
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Create and add the entry fields to the grid
    entry_no = gtk_entry_new();
    entry_nama = gtk_entry_new();
    entry_alamat = gtk_entry_new();
    entry_kota = gtk_entry_new();
    entry_tempat_lahir = gtk_entry_new();
    entry_tanggal_lahir = gtk_entry_new();
    entry_umur = gtk_entry_new();
    entry_noBPJS = gtk_entry_new();
    entry_id = gtk_entry_new();

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Isi data berikut untuk menambah pasien"), 0, 0, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Nama Pasien:"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_nama, 1, 1, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Alamat Pasien:"), 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_alamat, 1, 2, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Kota Pasien:"), 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_kota, 1, 3, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Tempat Lahir Pasien:"), 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_tempat_lahir, 1, 4, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Tanggal Lahir Pasien:"), 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_tanggal_lahir, 1, 5, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Umur Pasien:"), 0, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_umur, 1, 6, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Nomor BPJS Pasien:"), 0, 7, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_noBPJS, 1, 7, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("ID Pasien:"), 0, 8, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_id, 1, 8, 1, 1);

    // Show all widgets in the dialog
    gtk_widget_show_all(dialog);

    // Run the dialog and capture the response
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_ACCEPT) {
        // Allocate memory for new dataPasien
        dataPasien *new_data = g_malloc(sizeof(dataPasien));
        new_data->next = NULL;

        // Retrieve data from entries and set it to new_data
        new_data->no = 0;
        strcpy(new_data->nama, gtk_entry_get_text(GTK_ENTRY(entry_nama)));
        strcpy(new_data->alamat, gtk_entry_get_text(GTK_ENTRY(entry_alamat)));
        strcpy(new_data->kota, gtk_entry_get_text(GTK_ENTRY(entry_kota)));
        strcpy(new_data->tempat_lahir, gtk_entry_get_text(GTK_ENTRY(entry_tempat_lahir)));
        strcpy(new_data->tanggal_lahir, gtk_entry_get_text(GTK_ENTRY(entry_tanggal_lahir)));
        new_data->umur = atoi(gtk_entry_get_text(GTK_ENTRY(entry_umur)));
        strcpy(new_data->noBPJS, gtk_entry_get_text(GTK_ENTRY(entry_noBPJS)));
        strcpy(new_data->id, gtk_entry_get_text(GTK_ENTRY(entry_id)));

        // Call the tambah function
        int result = tambah_data_pasien(new_data);

        // Show result message dialog
        GtkWidget *result_dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                                          GTK_DIALOG_DESTROY_WITH_PARENT,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_OK,
                                                          result ? "Data pasien berhasil ditambah." : "Gagal menambah data pasien.");
        gtk_dialog_run(GTK_DIALOG(result_dialog));
        gtk_widget_destroy(result_dialog);

        // Free new_data if tambah failed
        if (!result) {
            g_free(new_data);
        }
    }
    gtk_widget_destroy(dialog);
}

//Fitur2 edit riwayat
void on_edit_riwayat_edit_clicked(GtkWidget *widget, gpointer data) {
    ubahRiwayat(main_window);
}

//Fitur2 hapus riwayat 
void on_edit_riwayat_hapus_clicked(GtkWidget *widget, gpointer data) {
    hapusRiwayat();
}

void on_edit_riwayat_cari_clicked(GtkWidget *widget, gpointer data) {
    cariRiwayat();
}

void on_edit_riwayat_tambah_clicked(GtkWidget *widget, gpointer data) {
    tambahRiwayat();
}

void on_back_to_main_menu(GtkWidget *widget, gpointer data) {
    create_main_menu();
}

int main(int argc, char *argv[]) {
    baca("DataPMC20232024 - Data Pasien.csv","DataPMC20232024 - Biaya Tindakan.csv","DataPMC20232024 - Riwayat Datang, Diag,, Tindakan.csv");
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

