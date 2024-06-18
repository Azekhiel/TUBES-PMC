#include "baca.h"
//No,Tanggal,ID Pasien,Diagnosis,Tindakan,Kontrol,Biaya (Rp)
void printRiwayat(riwayatDatang *tes) {
    printf("Tanggal: %s\nID Pasien: %s\nDiagnosis: %s\nTindakan: %s\nKontrol: %s\nBiaya: %d\n", 
           tes->tanggal, tes->id, tes->diagnosis, tes->tindakan, tes->kontrol, tes->biaya);
}

void show_message_dialog(GtkWindow *parent, const char *message) {
    GtkWidget *dialog = gtk_message_dialog_new(parent,
                                               GTK_DIALOG_DESTROY_WITH_PARENT,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "%s", message);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

void hapusRiwayat() {
    GtkWidget *dialog, *content_area, *entry;
    const char *idPasien;
    riwayatDatang *current = head_riwayatDatang;
    riwayatDatang *prev = NULL;
    gboolean found = FALSE;

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

        // Search for the patient and prompt for deletion confirmation
        while (current != NULL) {
            if (strcmp(current->id, idPasien) == 0) {
                found = TRUE;
                printRiwayat(current);

                // Confirmation dialog
                GtkWidget *confirm_dialog = gtk_message_dialog_new(NULL,
                                                                   GTK_DIALOG_MODAL,
                                                                   GTK_MESSAGE_QUESTION,
                                                                   GTK_BUTTONS_YES_NO,
                                                                   "Do you want to delete this record?");
                gint response = gtk_dialog_run(GTK_DIALOG(confirm_dialog));
                gtk_widget_destroy(confirm_dialog);

                if (response == GTK_RESPONSE_YES) {
                    if (prev != NULL) {
                        prev->next = current->next;
                    } else {
                        head_riwayatDatang = current->next;
                    }
                    free(current);
                    show_message_dialog(NULL, "Record deleted successfully.");
                    gtk_widget_destroy(dialog);
                    return;
                }
            }
            prev = current;
            current = current->next;
        }

        if (!found) {
            show_message_dialog(NULL, "Patient ID not found.");
        }
    }

    gtk_widget_destroy(dialog);
}

//Ubah riwayat untuk GTK
void on_edit_button_clicked(GtkButton *button, gpointer user_data , GtkWidget *main_window) {
    riwayatDatang *patient = (riwayatDatang *)user_data;

    GtkWidget *dialog = gtk_dialog_new_with_buttons("Edit Patient Record",
                                                    NULL,
                                                    GTK_DIALOG_MODAL,
                                                    "_OK", GTK_RESPONSE_OK,
                                                    "_Cancel", GTK_RESPONSE_CANCEL,
                                                    NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *grid = gtk_grid_new();

    gtk_container_add(GTK_CONTAINER(content_area), grid);

    GtkWidget *tanggal_label = gtk_label_new("Tanggal: ");
    GtkWidget *tanggal_entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(tanggal_entry), patient->tanggal);

    GtkWidget *diagnosis_label = gtk_label_new("Diagnosis: ");
    GtkWidget *diagnosis_entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(diagnosis_entry), patient->diagnosis);

    GtkWidget *tindakan_label = gtk_label_new("Tindakan: ");
    GtkWidget *tindakan_entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(tindakan_entry), patient->tindakan);

    GtkWidget *kontrol_label = gtk_label_new("Kontrol: ");
    GtkWidget *kontrol_entry = gtk_entry_new();
    gtk_entry_set_text(GTK_ENTRY(kontrol_entry), patient->kontrol);

    GtkWidget *biaya_label = gtk_label_new("Biaya (Rp): ");
    GtkWidget *biaya_entry = gtk_entry_new();
    char biaya_str[20];
    sprintf(biaya_str, "%d", patient->biaya);
    gtk_entry_set_text(GTK_ENTRY(biaya_entry), biaya_str);

    gtk_grid_attach(GTK_GRID(grid), tanggal_label, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), tanggal_entry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), diagnosis_label, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), diagnosis_entry, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), tindakan_label, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), tindakan_entry, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), kontrol_label, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), kontrol_entry, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), biaya_label, 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), biaya_entry, 1, 4, 1, 1);

    gtk_widget_show_all(dialog);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_OK) {
        strcpy(patient->tanggal, gtk_entry_get_text(GTK_ENTRY(tanggal_entry)));
        strcpy(patient->diagnosis, gtk_entry_get_text(GTK_ENTRY(diagnosis_entry)));
        strcpy(patient->tindakan, gtk_entry_get_text(GTK_ENTRY(tindakan_entry)));
        strcpy(patient->kontrol, gtk_entry_get_text(GTK_ENTRY(kontrol_entry)));
        patient->biaya = atoi(gtk_entry_get_text(GTK_ENTRY(biaya_entry)));
    }

    gtk_widget_destroy(dialog);
}
//Fungsi mengubah riwayat
void ubahRiwayat(GtkWidget *main_window) {
    riwayatDatang *current = head_riwayatDatang;
    GtkWidget *dialog = gtk_dialog_new_with_buttons("Enter Patient ID",
                                                    NULL,
                                                    GTK_DIALOG_MODAL,
                                                    "_OK", GTK_RESPONSE_OK,
                                                    "_Cancel", GTK_RESPONSE_CANCEL,
                                                    NULL);
    GtkWidget *content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    GtkWidget *entry = gtk_entry_new();
    gtk_container_add(GTK_CONTAINER(content_area), entry);
    gtk_widget_show_all(dialog);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_OK) {
        const char *idPasien = gtk_entry_get_text(GTK_ENTRY(entry));
        int i = 1;
        while (current != NULL) {
            if (strcmp(current->id, idPasien) == 0) {
                on_edit_button_clicked(NULL, current , main_window);
                i++;
            }
            current = current->next;
        }
    }

    gtk_widget_destroy(dialog);
}

//No,Tanggal,ID Pasien,Diagnosis,Tindakan,Kontrol,Biaya (Rp)
// Function to add a new patient record
void tambahRiwayat() {
    riwayatDatang *current = head_riwayatDatang;
    riwayatDatang *newNode = (riwayatDatang *)malloc(sizeof(riwayatDatang));
    newNode->next = NULL;
    int i = 1;

    // If the list is empty, set the new node as the head
    if (current == NULL) {
        head_riwayatDatang = newNode;
    } else {
        // Traverse to the end of the list and append the new node
        while (current->next != NULL) {
            current = current->next;
            i++;
        }
        current->next = newNode;
        i++;
    }
    newNode->no = i;

    // Create a dialog for inputting the new patient record
    GtkWidget *dialog, *content_area, *grid;
    GtkWidget *tanggal_entry, *id_entry, *diagnosis_entry, *tindakan_entry, *kontrol_entry, *biaya_entry;
    dialog = gtk_dialog_new_with_buttons("Tambah Riwayat",
                                         NULL,
                                         GTK_DIALOG_MODAL,
                                         "_OK", GTK_RESPONSE_OK,
                                         "_Cancel", GTK_RESPONSE_CANCEL,
                                         NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Create entry widgets for each field
    tanggal_entry = gtk_entry_new();
    id_entry = gtk_entry_new();
    diagnosis_entry = gtk_entry_new();
    tindakan_entry = gtk_entry_new();
    kontrol_entry = gtk_entry_new();
    biaya_entry = gtk_entry_new();

    // Attach labels and entry widgets to the grid
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Tanggal:"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), tanggal_entry, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("ID Pasien:"), 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Diagnosis:"), 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), diagnosis_entry, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Tindakan:"), 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), tindakan_entry, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Kontrol:"), 0, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), kontrol_entry, 1, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Biaya:"), 0, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), biaya_entry, 1, 5, 1, 1);

    gtk_widget_show_all(dialog); // Show the dialog

    // If the user clicks OK, retrieve the input and store it in the new node
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
        strcpy(newNode->tanggal, gtk_entry_get_text(GTK_ENTRY(tanggal_entry)));
        strcpy(newNode->id, gtk_entry_get_text(GTK_ENTRY(id_entry)));
        strcpy(newNode->diagnosis, gtk_entry_get_text(GTK_ENTRY(diagnosis_entry)));
        strcpy(newNode->tindakan, gtk_entry_get_text(GTK_ENTRY(tindakan_entry)));
        strcpy(newNode->kontrol, gtk_entry_get_text(GTK_ENTRY(kontrol_entry)));
        newNode->biaya = atoi(gtk_entry_get_text(GTK_ENTRY(biaya_entry)));

        // Show a success message
        show_message_dialog(GTK_WINDOW(dialog), "Record added successfully.");
    } else {
        // If the user cancels, free the allocated memory
        free(newNode);
        show_message_dialog(GTK_WINDOW(dialog), "Record addition canceled.");
    }

    gtk_widget_destroy(dialog); // Destroy the dialog after closing
}


// Function to create and show the table with patient history
void show_patient_history(GtkWindow *parent, const char *idPasien) {
    GtkWidget *dialog, *content_area, *scrolled_window, *grid;
    GtkWidget *label;
    riwayatDatang *current = head_riwayatDatang;
    gboolean found = FALSE;
    int row = 1;

    // Create a dialog for displaying the patient history
    dialog = gtk_dialog_new_with_buttons("Patient History",
                                         parent,
                                         GTK_DIALOG_MODAL,
                                         "_OK", GTK_RESPONSE_OK,
                                         NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled_window, 600, 400);
    gtk_container_add(GTK_CONTAINER(content_area), scrolled_window);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), grid);

    // Set up column labels
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("No"), 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Tanggal"), 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Diagnosis"), 2, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Tindakan"), 3, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Kontrol"), 4, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Biaya"), 5, 0, 1, 1);

    // Traverse the linked list and add rows to the grid for matching records
    while (current != NULL) {
        if (strcmp(current->id, idPasien) == 0) {
            found = TRUE;

            // Adding the record to the table
            char buffer[10];
            snprintf(buffer, sizeof(buffer), "%d", current->no);
            label = gtk_label_new(buffer);
            gtk_grid_attach(GTK_GRID(grid), label, 0, row, 1, 1);

            label = gtk_label_new(current->tanggal);
            gtk_grid_attach(GTK_GRID(grid), label, 1, row, 1, 1);

            label = gtk_label_new(current->diagnosis);
            gtk_grid_attach(GTK_GRID(grid), label, 2, row, 1, 1);

            label = gtk_label_new(current->tindakan);
            gtk_grid_attach(GTK_GRID(grid), label, 3, row, 1, 1);

            label = gtk_label_new(current->kontrol);
            gtk_grid_attach(GTK_GRID(grid), label, 4, row, 1, 1);

            snprintf(buffer, sizeof(buffer), "%d", current->biaya);
            label = gtk_label_new(buffer);
            gtk_grid_attach(GTK_GRID(grid), label, 5, row, 1, 1);

            row++;
        }
        current = current->next;
    }

    if (!found) {
        show_message_dialog(parent, "Patient ID not found.");
        gtk_widget_destroy(dialog);
        return;
    }

    gtk_widget_show_all(dialog);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

// Function to search for a patient record
void cariRiwayat() {
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
        show_patient_history(GTK_WINDOW(dialog), idPasien);
    }

    gtk_widget_destroy(dialog);
}