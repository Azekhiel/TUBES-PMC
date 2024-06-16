#include "baca.h"

void fitur3() {
    /*
     * Fungsi menerima input ID pasien dari user
     * Fungsi mengeprint data pasien dari dataPasien
     * FUngsi mengeprint riwayat diagnostik dengan format diagnostik -- tanggal dari riwayatDatang*/
    char input_id_pasien[11]; // Fixed size to store the input ID
    printf("Silahkan input ID pasien: ");
    scanf("%s", input_id_pasien);

    // Print data pasien based on ID
    dataPasien *currentPasien = head_dataPasien; // Mengambil head dari dataPasien

    while (currentPasien != NULL) {
        if (strcmp(currentPasien->id, input_id_pasien) == 0) {
            // Found the patient, print their details
            printf("Data Pasien:\n");
            printf("Nama: %s\n", currentPasien->nama);
            printf("Alamat: %s\n", currentPasien->alamat);
            printf("Kota: %s\n", currentPasien->kota);
            printf("Tempat Lahir: %s\n", currentPasien->tempat_lahir);
            printf("Tanggal Lahir: %s\n", currentPasien->tanggal_lahir);
            printf("Umur: %d\n", currentPasien->umur);
            printf("No. BPJS: %s\n", currentPasien->noBPJS);
            printf("ID: %s\n", currentPasien->id);
            break; // Exit loop once found
        }
        currentPasien = currentPasien->next;
    }

    // Print riwayat diagnosis based on ID
    riwayatDatang *currentRiwayat = head_riwayatDatang; // Mengambil head dari riwayatDatang

    printf("\nRiwayat Diagnosis:\n");
    while (currentRiwayat != NULL) {
        if (strcmp(currentRiwayat->id, input_id_pasien) == 0) {
            // Print diagnosis and tanggal from riwayatDatang
            printf("%s -- %s\n", currentRiwayat->diagnosis, currentRiwayat->tanggal);
        }
        currentRiwayat = currentRiwayat->next;
    }
}

