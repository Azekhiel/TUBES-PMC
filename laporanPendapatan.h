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

void hitungBulan() {
    int pendapatanBulanan[12] = {0};
    char bulan[255];
    int monthIndex;
    riwayatDatang *current = head_riwayatDatang;
    while (current != NULL) {
        sscanf(current->tanggal, "%*d %s %*d", bulan);
        monthIndex = bulanSama(bulan);
        if (monthIndex != -1) {
            pendapatanBulanan[monthIndex] += current->biaya;
        }
        current = current->next;
    }

    printf("Monthly Revenue Report:\n");
    const char* monthNames[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    for (int i = 0; i < 12; i++) {
        printf("%s: Rp %d\n", monthNames[i], pendapatanBulanan[i]);
    }
}

void hitungTahunan() {
    int pendapatanTahunan[100] ={0}; 
    int yearMin = tahunMulai(); 
    riwayatDatang *current = head_riwayatDatang;
    int totalPendapatan=0;
    int jumlahTahun=0;
    while (current != NULL) {
        int year;
        sscanf(current->tanggal, "%*d %*s %d", &year);
        pendapatanTahunan[year - yearMin] += current->biaya;
        current = current->next;
    }

    printf("Laporan Tahunan:\n");
    for (int i = 0; i < 100; i++) {
        if (pendapatanTahunan[i] > 0) {
            printf("Tahun %d: Rp %d\n", yearMin + i, pendapatanTahunan[i]);
            jumlahTahun++;
            totalPendapatan+=pendapatanTahunan[i];
        }
    }
    printf("Pendapatan Rata-Rata Pertahun: %d", totalPendapatan/jumlahTahun);
}

int laporanPendapatan() {
    baca();
    hitungBulan();
    hitungTahunan();
    return 0;
}
