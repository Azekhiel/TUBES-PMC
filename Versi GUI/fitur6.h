#include <string.h>
#include <stdlib.h>
#include "baca.h"

// Fungsi untuk mendapatkan angka bulan dari nama bulan 
int getMonthNumber(const char *namaBulan) {
    if (strcmp(namaBulan, "Januari") == 0) return 1;
    else if (strcmp(namaBulan, "Februari") == 0) return 2;
    else if (strcmp(namaBulan, "Maret") == 0) return 3;
    else if (strcmp(namaBulan, "April") == 0) return 4;
    else if (strcmp(namaBulan, "Mei") == 0) return 5;
    else if (strcmp(namaBulan, "Juni") == 0) return 6;
    else if (strcmp(namaBulan, "Juli") == 0) return 7;
    else if (strcmp(namaBulan, "Agustus") == 0) return 8;
    else if (strcmp(namaBulan, "September") == 0) return 9;
    else if (strcmp(namaBulan, "Oktober") == 0) return 10;
    else if (strcmp(namaBulan, "November") == 0) return 11;
    else if (strcmp(namaBulan, "Desember") == 0) return 12;
    else return 0; // Invalid month name
}

// Fungsi untuk membandingkan tanggal dengan range tanggal (hari1, bulan1, tahun1 hingga hari2, bulan2, tahun2)
int compareDatesRange(const char *tanggal, int hari1, int bulan1, int tahun1, int hari2, int bulan2, int tahun2) {  
    //Fungsi membandingkan char tanggal dengan range (hari1 bulan1 tahun1 - hari2 bulan2 tahun2)
    //Fungsi mereturn 0 bila tanggal dalam range
    //fungsi mereturn -1 bila tanggal kurang dari range
    //fungsi mereturn 1 bila tanggal lebih dari range

    int riwayatHari, riwayatBulan, riwayatTahun;
    char namaBulan[20]; // Untuk menyimpan nama bulan dari string tanggal

    // Membaca tanggal dalam format "hari namaBulan tahun"
    sscanf(tanggal, "%d %s %d", &riwayatHari, namaBulan, &riwayatTahun);

    // Konversi nama bulan menjadi angka
    riwayatBulan = getMonthNumber(namaBulan);

    // Melakukan perbandingan dengan range tanggal
    if (riwayatTahun > tahun2 || (riwayatTahun == tahun2 && riwayatBulan > bulan2) || 
        (riwayatTahun == tahun2 && riwayatBulan == bulan2 && riwayatHari > hari2)) {
        return 1; // Date is beyond the range
    } else if (riwayatTahun < tahun1 || (riwayatTahun == tahun1 && riwayatBulan < bulan1) || 
               (riwayatTahun == tahun1 && riwayatBulan == bulan1 && riwayatHari < hari1)) {
        return -1; // Date is before the range
    } else {
        return 0; // Date is within the range
    }
}

// Print pasien yang harus datang dalam seminggu kedepan
void printPatientsByDateRange(int hari1, int bulan1, int tahun1, int hari2, int bulan2, int tahun2) {
    riwayatDatang *currentRiwayat = head_riwayatDatang; 
    int count = 0;

    while (currentRiwayat != NULL) {
        if (compareDatesRange(currentRiwayat->tanggal, hari1, bulan1, tahun1, hari2, bulan2, tahun2) == 0) {
            // Print patient details
            printf("ID Pasien: %s\n", currentRiwayat->id);
            printf("Diagnosis: %s\n", currentRiwayat->diagnosis);
            printf("Tanggal: %s\n", currentRiwayat->tanggal);
            printf("---------------------------\n");
            count += 1;
        }
        currentRiwayat = currentRiwayat->next;
    }

    if (count == 0){
        printf("Tidak ada pasien yang perlu datang kembali");
    }
    printf("\n");
}

void showPatientsByDateRangeDialog(int hari1, int bulan1, int tahun1, int hari2, int bulan2, int tahun2) {
    riwayatDatang *currentRiwayat = head_riwayatDatang; // Mengganti ini dengan inisialisasi dari program utama
    int count = 0;

    // Buat dialog baru
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Pasien Berdasarkan Rentang Tanggal",
                                                    GTK_WINDOW(NULL),
                                                    GTK_DIALOG_MODAL,
                                                    "_OK",
                                                    GTK_RESPONSE_OK,
                                                    NULL);

    // Konten dari dialog
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Buat grid untuk menampilkan data dalam bentuk tabel
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_container_set_border_width(GTK_CONTAINER(grid), 10);
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Judul kolom tabel
    GtkWidget *label_id = gtk_label_new("ID Pasien");
    GtkWidget *label_diagnosis = gtk_label_new("Diagnosis");
    GtkWidget *label_tanggal = gtk_label_new("Tanggal");
    gtk_grid_attach(GTK_GRID(grid), label_id, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_diagnosis, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_tanggal, 2, 0, 1, 1);

    int row = 1;

    // Tampilkan data pasien dalam tabel
    while (currentRiwayat != NULL) {
        if (compareDatesRange(currentRiwayat->tanggal, hari1, bulan1, tahun1, hari2, bulan2, tahun2) == 0) {
            // Tambahkan data pasien ke dalam tabel
            GtkWidget *id_label = gtk_label_new(currentRiwayat->id);
            GtkWidget *diagnosis_label = gtk_label_new(currentRiwayat->diagnosis);
            GtkWidget *tanggal_label = gtk_label_new(currentRiwayat->tanggal);

            gtk_grid_attach(GTK_GRID(grid), id_label, 0, row, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), diagnosis_label, 1, row, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), tanggal_label, 2, row, 1, 1);

            // Atur padding dan alignment label
            gtk_widget_set_margin_start(id_label, 5);
            gtk_widget_set_margin_end(id_label, 5);
            gtk_widget_set_margin_start(diagnosis_label, 5);
            gtk_widget_set_margin_end(diagnosis_label, 5);
            gtk_widget_set_margin_start(tanggal_label, 5);
            gtk_widget_set_margin_end(tanggal_label, 5);

            // Tingkatkan jumlah baris
            row++;

            count += 1;
        }
        currentRiwayat = currentRiwayat->next;
    }

    // Jika tidak ada data yang ditemukan
    if (count == 0) {
        GtkWidget *no_data_label = gtk_label_new("Tidak ada pasien yang perlu datang kembali");
        gtk_grid_attach(GTK_GRID(grid), no_data_label, 0, row, 3, 1);
        row++;
    }

    // Tampilkan semua widget dalam dialog
    gtk_widget_show_all(dialog);

    // Jalankan dialog
    gtk_dialog_run(GTK_DIALOG(dialog));

    // Setelah selesai, hancurkan dialog
    gtk_widget_destroy(dialog);
}

int daysInMonth(int month, int year){
    switch(month){
        case 2:
            if((year % 4 == 0 && year % 100 !=0) || (year % 400 == 0)){
                return 28;
            } else {
                return 28;
            }
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}
void on_response(GtkDialog *dialog, gint response_id, gpointer user_data) {
    if (response_id == GTK_RESPONSE_OK) {
        // Ambil nilai dari GtkEntry
        GtkWidget *day_entry = GTK_WIDGET(user_data);
        GtkWidget *month_entry = g_object_get_data(G_OBJECT(day_entry), "month_entry");
        GtkWidget *year_entry = g_object_get_data(G_OBJECT(day_entry), "year_entry");

        const gchar *day_str = gtk_entry_get_text(GTK_ENTRY(day_entry));
        const gchar *month_str = gtk_entry_get_text(GTK_ENTRY(month_entry));
        const gchar *year_str = gtk_entry_get_text(GTK_ENTRY(year_entry));

        // Konversi ke integer
        int hari = atoi(day_str);
        int bulan = atoi(month_str);
        int tahun = atoi(year_str);

        // Lakukan pemrosesan seperti pada fungsi fitur6() asli
        int nextHari = hari + 7;
        int nextBulan = bulan;
        int nextTahun = tahun;

        int jmlh_hr_bln_ini = daysInMonth(bulan, tahun);

        if (nextHari > jmlh_hr_bln_ini) {
            nextHari -= jmlh_hr_bln_ini;
            nextBulan++;
            if (nextBulan > 12) {
                nextBulan = 1;
                nextTahun++;
            }
        }

        // Print patients yang perlu datang 1 minggu kedepan
        printf("\nPasien yang perlu datang kembali dalam 1 minggu kedepan (%d %d %d - %d %d %d):\n",
               hari, bulan, tahun, nextHari, nextBulan, nextTahun);
        printPatientsByDateRange(hari, bulan, tahun, nextHari, nextBulan, nextTahun);

        // Menampilkan dialog
        showPatientsByDateRangeDialog(hari, bulan, tahun, nextHari, nextBulan, nextTahun);
    }

    // Tutup dialog setelah selesai
    gtk_widget_destroy(GTK_WIDGET(dialog));
}

void fitur6() {
    // Buat dialog
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Input Tanggal",
                                                    GTK_WINDOW(NULL),
                                                    GTK_DIALOG_MODAL,
                                                    "OK",
                                                    GTK_RESPONSE_OK,
                                                    NULL);

    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    // Buat entry untuk tanggal, bulan, tahun
    GtkWidget *day_entry = gtk_entry_new();
    GtkWidget *month_entry = gtk_entry_new();
    GtkWidget *year_entry = gtk_entry_new();

    gtk_entry_set_placeholder_text(GTK_ENTRY(day_entry), "Masukkan tanggal (DD)");
    gtk_entry_set_placeholder_text(GTK_ENTRY(month_entry), "Masukkan bulan (MM)");
    gtk_entry_set_placeholder_text(GTK_ENTRY(year_entry), "Masukkan tahun (YYYY)");

    // Susun entry dalam grid
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    gtk_grid_attach(GTK_GRID(grid), day_entry, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), month_entry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), year_entry, 2, 0, 1, 1);

    // Simpan entry month dan year sebagai data di day_entry
    g_object_set_data(G_OBJECT(day_entry), "month_entry", month_entry);
    g_object_set_data(G_OBJECT(day_entry), "year_entry", year_entry);

    // Connect tombol OK ke fungsi callback
    g_signal_connect(dialog, "response", G_CALLBACK(on_response), day_entry);

    // Tampilkan dialog
    gtk_widget_show_all(dialog);
}
