#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baca.h"

int tahunMulai() {
        if (head_riwayatDatang == NULL) {
            return 0; 
        }
        riwayatDatang *current = head_riwayatDatang;
        int tahunMin = atoi(strrchr(current->tanggal, ' ')); 
        while (current != NULL) {
            int tahun = atoi(strrchr(current->tanggal, ' '));
            if (tahun < tahunMin) {
                tahunMin = tahun;
            }
            current = current->next;
        }
        return tahunMin;
}

// Function to convert month name to index
int bulanSama(char* bulan) {
    if (strcmp(bulan, "Januari") == 0) return 0;
    if (strcmp(bulan, "Februari") == 0) return 1;
    if (strcmp(bulan, "Maret") == 0) return 2;
    if (strcmp(bulan, "April") == 0) return 3;
    if (strcmp(bulan, "Mei") == 0) return 4;
    if (strcmp(bulan, "Juni") == 0) return 5;
    if (strcmp(bulan, "Juli") == 0) return 6;
    if (strcmp(bulan, "Agustus") == 0) return 7;
    if (strcmp(bulan, "September") == 0) return 8;
    if (strcmp(bulan, "Oktober") == 0) return 9;
    if (strcmp(bulan, "November") == 0) return 10;
    if (strcmp(bulan, "Desember") == 0) return 11;
    return -1;
}

// Function to calculate monthly income and show in a GTK dialog
void show_monthly_and_yearly_income(GtkWidget *parent) {
    int pendapatanBulanan[12] = {0};
    char bulan[255];
    int monthIndex;
    riwayatDatang *current = head_riwayatDatang;

    // Calculate monthly income
    while (current != NULL) {
        sscanf(current->tanggal, "%*d %s %*d", bulan);
        monthIndex = bulanSama(bulan);
        if (monthIndex != -1) {
            pendapatanBulanan[monthIndex] += current->biaya;
        }
        current = current->next;
    }

    // Create GTK dialog
    GtkWidget *dialog, *content_area, *grid, *label;
    dialog = gtk_dialog_new_with_buttons("Laporan Pendapatan",
                                         GTK_WINDOW(parent),
                                         GTK_DIALOG_MODAL,
                                         "_OK", GTK_RESPONSE_OK,
                                         NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
    // Display monthly income
    const char* monthNames[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni",
                                  "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    for (int i = 0; i < 12; i++) {
        label = gtk_label_new(NULL);
        gchar *text = g_strdup_printf("%s: Rp %d", monthNames[i], pendapatanBulanan[i]);
        gtk_label_set_text(GTK_LABEL(label), text);
        g_free(text);
        gtk_grid_attach(GTK_GRID(grid), label, 0, i, 1, 1);
    }

    // Calculate yearly income
    int pendapatanTahunan[100] = {0};
    int yearMin = tahunMulai(); // Assume tahunMulai function is defined elsewhere
    current = head_riwayatDatang;
    int totalPendapatan = 0;
    int jumlahTahun = 0;

    while (current != NULL) {
        int year;
        sscanf(current->tanggal, "%*d %*s %d", &year);
        pendapatanTahunan[year - yearMin] += current->biaya;
        current = current->next;
    }

    // Display yearly income
    for (int i = 0; i < 100; i++) {
        if (pendapatanTahunan[i] > 0) {
            label = gtk_label_new(NULL);
            gchar *text = g_strdup_printf("Tahun %d: Rp %d", yearMin + i, pendapatanTahunan[i]);
            gtk_label_set_text(GTK_LABEL(label), text);
            g_free(text);
            gtk_grid_attach(GTK_GRID(grid), label, 0, i + 12, 1, 1);
            jumlahTahun++;
            totalPendapatan += pendapatanTahunan[i];
        }
    }

    // Display average yearly income
    label = gtk_label_new(NULL);
    gchar *averageText = g_strdup_printf("Pendapatan Rata-Rata Pertahun: Rp %d", totalPendapatan / jumlahTahun);
    gtk_label_set_text(GTK_LABEL(label), averageText);
    g_free(averageText);
    gtk_grid_attach(GTK_GRID(grid), label, 0, 112, 1, 1);

    gtk_widget_show_all(dialog);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// Function to handle the feature in GTK dialog
void fitur4() {
    show_monthly_and_yearly_income(NULL);
}
