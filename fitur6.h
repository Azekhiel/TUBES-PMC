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

void fitur6() {
  /*
   * Fungsi menerima input tanggal sekarang dari user
   * Fungsi mengprint pasien yang harus datang sekarang
   * FUngsi mengprint pasien yang harus datang dalam range 1 minggu kedepan*/ 

  // Input dari user date
    int hari, bulan, tahun;
    printf("Masukkan tanggal sekarang (hari bulan tahun): ");
    scanf("%d %d %d", &hari, &bulan, &tahun);

    // Program menghitung tanggal kedepan (diperlukan untuk mengprint pasien yang perlu datang 1 minggu kedepan)
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
}
