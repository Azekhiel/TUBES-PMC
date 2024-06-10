#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//No,Nama Lengkap,Alamat,Kota,Tempat Lahir,Tanggal Lahir,Umur (th),No BPJS,ID Pasien
typedef struct{
    int no;
    char nama[255];
    char alamat[255];
    char kota[255];
    char tempat_lahir[255];
    char tanggal_lahir[255];
    int umur;
    char noBPJS[12];
    char id[11];
    struct dataPasien *next;
} dataPasien;
dataPasien *head_dataPasien = NULL;

//No,Aktivitas,Biaya (Rp)
typedef struct{
    int no;
    char aktivitas[255];
    int biaya;
    struct biayaTindakan *next;
} biayaTindakan;
biayaTindakan *head_biayaTindakan = NULL;

//No,Tanggal,ID Pasien,Diagnosis,Tindakan,Kontrol,Biaya (Rp)
typedef struct{
    int no;
    char tanggal[255];
    char id[255];
    char diagnosis[255];
    char tindakan[255];
    char kontrol[255];
    int biaya;
    struct riwayatDatang *next;
} riwayatDatang;
riwayatDatang *head_riwayatDatang = NULL;

void bacaDataPasien(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ada %s\n", filename);
        return;
    }
    char line[255];
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        char *token;
        dataPasien *newNode = (dataPasien *)malloc(sizeof(dataPasien));
        token = strtok(line, ",");
        newNode->no = atoi(token);

        token = strtok(NULL, ",");
        strcpy(newNode->nama, token);

        token = strtok(NULL, ",");
        strcpy(newNode->alamat, token);

        token = strtok(NULL, ",");
        strcpy(newNode->kota, token);

        token = strtok(NULL, ",");
        strcpy(newNode->tempat_lahir, token);

        token = strtok(NULL, ",");
        strcpy(newNode->tanggal_lahir, token);

        token = strtok(NULL, ",");
        newNode->umur = atoi(token);

        token = strtok(NULL, ",");
        strcpy(newNode->noBPJS, token);

        token = strtok(NULL, ",");
        strcpy(newNode->id, token);

        newNode->next = NULL;
        if (head_dataPasien == NULL) {
            head_dataPasien = newNode;
        } 
        else {
            dataPasien *temp = head_dataPasien;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    fclose(file);
}

void bacaRiwayatDatang(char *filename) {
    // int no;
    // char tangga[255];
    // char id[255];
    // char diagnosis[255];
    // char tindakan[255];
    // char kontrol[255];
    // int biaya;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ada %s\n", filename);
        return;
    }
    char line[255];
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        char *token;
        riwayatDatang *newNode = (riwayatDatang *)malloc(sizeof(riwayatDatang));
        token = strtok(line, ",");
        newNode->no = atoi(token);

        token = strtok(NULL, ",");
        strcpy(newNode->tanggal, token);

        token = strtok(NULL, ",");
        strcpy(newNode->id, token);

        token = strtok(NULL, ",");
        strcpy(newNode->diagnosis, token);

        token = strtok(NULL, ",");
        strcpy(newNode->tindakan, token);

        token = strtok(NULL, ",");
        strcpy(newNode->kontrol, token);

        token = strtok(NULL, ",");
        newNode->biaya = atoi(token);

        newNode->next = NULL;
        if (head_riwayatDatang == NULL) {
            head_riwayatDatang = newNode;
        } 
        else {
            riwayatDatang *temp = head_riwayatDatang;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    fclose(file);
}

void bacaBiayaTindakan(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ada %s\n", filename);
        return;
    } 
    char line[255];
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        char *token;
        biayaTindakan *newNode = (biayaTindakan *)malloc(sizeof(biayaTindakan));
        token = strtok(line, ",");
        newNode->no = atoi(token);

        token = strtok(NULL, ",");
        strcpy(newNode->aktivitas, token);

        token = strtok(NULL, ",");
        newNode->biaya = token;

        newNode->next = NULL;
        if (head_biayaTindakan == NULL) {
            head_biayaTindakan = newNode;
        } 
        else {
            biayaTindakan *temp = head_biayaTindakan;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    fclose(file);
}


//buat cek isi linked list sesuain aj nanti sama data strukturny
// void printLinkedList() {
//     biayaTindakan *current = head_biayaTindakan;
//     while (current != NULL) {
//         printf("| %-2d | %-15s | %-18d|\n",
//                current->no, current->aktivitas, current->biaya);
//         current = current->next;
//     }
// }

void rapikanFormat(){
    char temp[3];
    dataPasien *current = head_dataPasien;
    while (current!= NULL){
        if (strstr(current->tanggal_lahir,"Jan")!=NULL){
            temp[0] = current->tanggal_lahir [0];
            temp[1] = current->tanggal_lahir [1];

        }
    }

}

int baca() {
    bacaDataPasien("DataPMC20232024 - Data Pasien.csv");
    bacaBiayaTindakan("DataPMC20232024 - Biaya Tindakan.csv");
    bacaRiwayatDatang("DataPMC20232024 - Riwayat Datang, Diag,, Tindakan.csv");
    // printLinkedList();
    return 0;
}
