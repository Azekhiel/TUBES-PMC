#include <string.h>
#include <stdio.h>
#include "baca.h"

void simpanDataPasien(char *filename) {
    char header[][30] = {"No", "Nama Lengkap", "Alamat", "Kota", "Tempat Lahir", "Tanggal Lahir", "Umur (th)", "No BPJS", "ID Pasien"};
    int i=1;
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s.\n", filename);
        return;
    }
    dataPasien *current = head_dataPasien;
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n", header[0],header[1],header[2],header[3],header[4],header[5],header[6],header[7],header[8]);    
    while (current != NULL) {
        fprintf(file, "%d,%s,%s,%s,%s,%s,%d,%s,%s\n", i, current->nama, current->alamat, current->kota,
                current->tempat_lahir, current->tanggal_lahir, current->umur, current->noBPJS, current->id);
        current = current->next;
        ++i;
    }
    fclose(file);
}

void simpanRiwayatDatang(char *filename) {
    char header[][20]={"No","Tanggal","ID Pasien","Diagnosis","Tindakan","Kontrol","Biaya (Rp)"};
    int i=1;
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s untuk penulisan.\n", filename);
        return;
    }
    riwayatDatang *current = head_riwayatDatang;
    fprintf(file, "%s,%s,%s,%s,%s,%s,%s\n", header[0],header[1],header[2],header[3],header[4],header[5],header[6]);    
    while (current != NULL) {
        fprintf(file, "%d,%s,%s,%s,%s,%s,%d\n", i, current->tanggal, current->id, current->diagnosis, current->tindakan, current->kontrol, current->biaya);
        current = current->next;
        ++i;
    }
    fclose(file);
}

void simpan(char *file1, char *file2) {
    simpanDataPasien(file1);
    simpanRiwayatDatang(file2);   
}
