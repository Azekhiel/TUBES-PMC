#include "baca.h"

// Function to show a message dialog
void show_message_dialog_fitur3(GtkWindow *parent, const char *message) {
    GtkWidget *dialog = gtk_message_dialog_new(parent,
                                               GTK_DIALOG_DESTROY_WITH_PARENT,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "%s", message);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// Function to display patient data and history
void show_patient_data_fitur3(GtkWindow *parent, const char *idPasien) {
    dataPasien *currentPasien = head_dataPasien;
    riwayatDatang *currentRiwayat = head_riwayatDatang;
    gboolean found = FALSE;

    GtkWidget *dialog, *content_area, *grid, *label;
    dialog = gtk_dialog_new_with_buttons("Patient Data and History",
                                         parent,
                                         GTK_DIALOG_MODAL,
                                         "_OK", GTK_RESPONSE_OK,
                                         NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Search for patient data
    while (currentPasien != NULL) {
        if (strcmp(currentPasien->id, idPasien) == 13) {
            found = TRUE;
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Nama:"), 0, 0, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentPasien->nama), 1, 0, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Alamat:"), 0, 1, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentPasien->alamat), 1, 1, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Kota:"), 0, 2, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentPasien->kota), 1, 2, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Tempat Lahir:"), 0, 3, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentPasien->tempat_lahir), 1, 3, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Tanggal Lahir:"), 0, 4, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentPasien->tanggal_lahir), 1, 4, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Umur:"), 0, 5, 1, 1);
            char umurStr[10];
            sprintf(umurStr, "%d", currentPasien->umur);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(umurStr), 1, 5, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new("No. BPJS:"), 0, 6, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentPasien->noBPJS), 1, 6, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new("ID:"), 0, 7, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentPasien->id), 1, 7, 1, 1);
            break;
        }
        currentPasien = currentPasien->next;
    }

    // Display patient history in a table format
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Riwayat Diagnosis"), 0, 8, 2, 1);
    int row = 9;
    while (currentRiwayat != NULL) {
        if (strcmp(currentRiwayat->id, idPasien) == 0) {
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentRiwayat->tanggal), 0, row, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentRiwayat->diagnosis), 1, row, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentRiwayat->tindakan), 2, row, 1, 1);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(currentRiwayat->kontrol), 3, row, 1, 1);
            char biayaStr[10];
            sprintf(biayaStr, "%d", currentRiwayat->biaya);
            gtk_grid_attach(GTK_GRID(grid), gtk_label_new(biayaStr), 4, row, 1, 1);
            row++;
        }
        currentRiwayat = currentRiwayat->next;
    }

    if (found == FALSE) {
        show_message_dialog_fitur3(parent, "Patient ID not found.");
    }

    gtk_widget_show_all(dialog);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// Function to prompt for patient ID and display data
void fitur3() {
    GtkWidget *dialog, *content_area, *entry;
    const char *idPasien;

    // Prompt for Patient ID
    dialog = gtk_dialog_new_with_buttons("Enter Patient ID",
                                         NULL,
                                         GTK_DIALOG_MODAL,
                                         "_OK", GTK_RESPONSE_OK,
                                         "_Cancel", GTK_RESPONSE_CANCEL,
                                         NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    entry = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), entry);
    gtk_widget_show_all(dialog);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
        idPasien = gtk_entry_get_text(GTK_ENTRY(entry));
        show_patient_data_fitur3(GTK_WINDOW(dialog), idPasien);
    }

    gtk_widget_destroy(dialog);
}
