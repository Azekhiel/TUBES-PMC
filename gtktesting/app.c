#include <gtk/gtk.h>

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

    button = gtk_button_new_with_label("Edit Data Pasien");
    g_signal_connect(button, "clicked", G_CALLBACK(on_edit_data_pasien_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Edit Riwayat");
    g_signal_connect(button, "clicked", G_CALLBACK(on_edit_riwayat_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Info Pasien");
    g_signal_connect(button, "clicked", G_CALLBACK(on_info_pasien_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Pendapatan Klinik");
    g_signal_connect(button, "clicked", G_CALLBACK(on_pendapatan_klinik_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Info Pasien Per Tahun");
    g_signal_connect(button, "clicked", G_CALLBACK(on_info_pasien_pertahun_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Tanggal");
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

void on_edit_data_pasien_edit_clicked(GtkWidget *widget, gpointer data) {
    clear_window();

    GtkWidget *entry_id = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_id), "Masukkan ID Pasien");
    gtk_box_pack_start(GTK_BOX(main_box), entry_id, TRUE, TRUE, 0);

    GtkWidget *entry_name = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_name), "Masukkan Nama Baru");
    gtk_box_pack_start(GTK_BOX(main_box), entry_name, TRUE, TRUE, 0);

    GtkWidget *entry_address = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_address), "Masukkan Alamat Baru");
    gtk_box_pack_start(GTK_BOX(main_box), entry_address, TRUE, TRUE, 0);

    GtkWidget *entry_birth_date = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_birth_date), "Masukkan Tempat Tanggal Lahir Baru");
    gtk_box_pack_start(GTK_BOX(main_box), entry_birth_date, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Submit");
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry_id);
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry_name);
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry_address);
    g_signal_connect(button, "clicked", G_CALLBACK(on_back_to_main_menu), entry_birth_date);
    gtk_box_pack_start(GTK_BOX(main_box), button, TRUE, TRUE, 0);

    GtkWidget *back_button = gtk_button_new_with_label("Kembali");
    g_signal_connect(back_button, "clicked", G_CALLBACK(on_back_to_main_menu), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), back_button, TRUE, TRUE, 0);

    gtk_widget_show_all(main_window);
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

