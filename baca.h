#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma once

//No,Nama Lengkap,Alamat,Kota,Tempat Lahir,Tanggal Lahir,Umur (th),No BPJS,ID Pasien
typedef struct dataPasien{
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
typedef struct biayaTindakan{
    int no;
    char aktivitas[255];
    int biaya;
    struct biayaTindakan *next;
} biayaTindakan;
biayaTindakan *head_biayaTindakan = NULL;

//No,Tanggal,ID Pasien,Diagnosis,Tindakan,Kontrol,Biaya (Rp)
typedef struct riwayatDatang{
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
    int temp;
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ada %s\n", filename);
        return;
    }
    char line[255];
    fgets(line, sizeof(line), file);
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
        temp = strlen(newNode->id);
        newNode->id[temp-1] = '\0';

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
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("File tidak ada %s\n", filename);
        return;
    }
    char line[255];
    char temp[255];
    fgets(line, sizeof(line), file);
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
        if (newNode->biaya ==0){
            strcpy(temp,token);
            token =strtok(NULL,",");
            strcat(temp,token);
            char *cleaned = temp + 1;
            cleaned[strlen(cleaned)-2]='\0';
            newNode->biaya = atoi(cleaned);
        }

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
        newNode->biaya = atoi(token);
        

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

void rapikanFormatDataPasien(){
    char temp_tanggal[255];
    char temp_tahun[10];
    char temp_bulan[16];
    char tahun[20];
    dataPasien *current = head_dataPasien;
    while (current!= NULL){
        if (strstr(current->tanggal_lahir,"Jan")!=NULL){
            strcpy(temp_bulan,"Januari ");
        }
        else if (strstr(current->tanggal_lahir,"Feb")!=NULL){
            strcpy(temp_bulan,"Februari ");
        }

        else if (strstr(current->tanggal_lahir,"Mar")!=NULL){
            strcpy(temp_bulan,"Maret ");
        }

        else if (strstr(current->tanggal_lahir,"Apr")!=NULL){
            strcpy(temp_bulan,"April ");
        }

        else if (strstr(current->tanggal_lahir,"Mei")!=NULL){
            strcpy(temp_bulan,"Mei ");
        }

        else if (strstr(current->tanggal_lahir,"Jun")!=NULL){
            strcpy(temp_bulan,"Juni ");
        }

        else if (strstr(current->tanggal_lahir,"Jul")!=NULL){
            strcpy(temp_bulan,"Juli ");
        }

        else if (strstr(current->tanggal_lahir,"Agu")!=NULL){
            strcpy(temp_bulan,"Agustus ");
        }

        else if (strstr(current->tanggal_lahir,"Sep")!=NULL){
            strcpy(temp_bulan,"September ");
        }

        else if (strstr(current->tanggal_lahir,"Okt")!=NULL){
            strcpy(temp_bulan,"Oktober ");
        }

        else if (strstr(current->tanggal_lahir,"Nov")!=NULL){
            strcpy(temp_bulan,"November ");
        }

        else if (strstr(current->tanggal_lahir,"Des")!=NULL){
            strcpy(temp_bulan,"Desember ");
        }

            temp_tanggal[0] = current->tanggal_lahir[0];
            if ((current->tanggal_lahir[1] >= '0' && current->tanggal_lahir[1] <= '9')) {
                temp_tanggal[1] = current->tanggal_lahir[1];
                temp_tanggal[2] = ' ';
            } else {
                temp_tanggal[1] = ' ';
                temp_tanggal[2] = '\0';
            }            
            temp_tanggal[3] = '\0';

        int temp1 = strlen(current->tanggal_lahir);
        int j = 0;

        for (int i = temp1 - 4; i < temp1; ++i) {
            temp_tahun[j] = current->tanggal_lahir[i];
            ++j;
        }
        temp_tahun[j] = '\0';

        if (current->tanggal_lahir[temp1 - 3] == '-') {
            strcpy(temp_tahun, strrchr(current->tanggal_lahir, '-') + 1);
            if (atoi(temp_tahun) <= 24) {
                strcpy(tahun, "20");
                strcat(tahun, temp_tahun);
            } else {
                strcpy(tahun, "19");
                strcat(tahun, temp_tahun);
            }
        } else {
            strcpy(tahun, temp_tahun);
        }

        strcat(temp_tanggal, temp_bulan);
        strcat(temp_tanggal, tahun);
        strcpy(current->tanggal_lahir, temp_tanggal);

        current = current->next;
    }
}


void rapikanFormatRiwayatDatang_Tanggal(){
    char temp_tanggal[100];
    char temp_tahun[10];
    char temp_bulan[16];
    char tahun[20];
    riwayatDatang *current = head_riwayatDatang;
    while (current!= NULL){
        if (strstr(current->tanggal,"Jan")!=NULL){
            strcpy(temp_bulan,"Januari ");
        }
        else if (strstr(current->tanggal,"Feb")!=NULL){
            strcpy(temp_bulan,"Februari ");
        }

        else if (strstr(current->tanggal,"Mar")!=NULL){
            strcpy(temp_bulan,"Maret ");
        }

        else if (strstr(current->tanggal,"Apr")!=NULL){
            strcpy(temp_bulan,"April ");
        }

        else if (strstr(current->tanggal,"Mei")!=NULL){
            strcpy(temp_bulan,"Mei ");
        }

        else if (strstr(current->tanggal,"Jun")!=NULL){
            strcpy(temp_bulan,"Juni ");
        }

        else if (strstr(current->tanggal,"Jul")!=NULL){
            strcpy(temp_bulan,"Juli ");
        }

        else if (strstr(current->tanggal,"Agu")!=NULL){
            strcpy(temp_bulan,"Agustus ");
        }

        else if (strstr(current->tanggal,"Sep")!=NULL){
            strcpy(temp_bulan,"September ");
        }

        else if (strstr(current->tanggal,"Okt")!=NULL){
            strcpy(temp_bulan,"Oktober ");
        }

        else if (strstr(current->tanggal,"Nov")!=NULL){
            strcpy(temp_bulan,"November ");
        }

        else if (strstr(current->tanggal,"Des")!=NULL){
            strcpy(temp_bulan,"Desember ");
        }
            temp_tanggal[0] = current->tanggal[0];
            if ((current->tanggal[1] >= '0' && current->tanggal[1] <= '9')) {
                temp_tanggal[1] = current->tanggal[1];
                temp_tanggal[2] = ' ';
            } else {
                temp_tanggal[1] = ' ';
                temp_tanggal[2] = '\0';
            }            
            temp_tanggal[3] = '\0';

        int temp1 = strlen(current->tanggal);
        int j = 0;

        for (int i = temp1 - 4; i < temp1; ++i) {
            temp_tahun[j] = current->tanggal[i];
            ++j;
        }
        temp_tahun[j] = '\0';

        if (current->tanggal[temp1 - 3] == '-') {
            strcpy(temp_tahun, strrchr(current->tanggal, '-') + 1);
            if (atoi(temp_tahun) <= 24) {
                strcpy(tahun, "20");
                strcat(tahun, temp_tahun);
            } else {
                strcpy(tahun, "19");
                strcat(tahun, temp_tahun);
            }
        } else {
            strcpy(tahun, temp_tahun);
        }

        strcat(temp_tanggal, temp_bulan);
        strcat(temp_tanggal, tahun);
        strcpy(current->tanggal, temp_tanggal);

        current = current->next;
    }
}

void rapikanFormatRiwayatDatang_Kontrol(){
    char temp_kontrol[100];
    char temp_tahun[10];
    char temp_bulan[16];
    char tahun[20];
    riwayatDatang *current = head_riwayatDatang;
    while (current!= NULL){
        if (strstr(current->kontrol,"Jan")!=NULL){
            strcpy(temp_bulan,"Januari ");
        }
        else if (strstr(current->kontrol,"Feb")!=NULL){
            strcpy(temp_bulan,"Februari ");
        }

        else if (strstr(current->kontrol,"Mar")!=NULL){
            strcpy(temp_bulan,"Maret ");
        }

        else if (strstr(current->kontrol,"Apr")!=NULL){
            strcpy(temp_bulan,"April ");
        }

        else if (strstr(current->kontrol,"Mei")!=NULL){
            strcpy(temp_bulan,"Mei ");
        }

        else if (strstr(current->kontrol,"Jun")!=NULL){
            strcpy(temp_bulan,"Juni ");
        }

        else if (strstr(current->kontrol,"Jul")!=NULL){
            strcpy(temp_bulan,"Juli ");
        }

        else if (strstr(current->kontrol,"Agu")!=NULL){
            strcpy(temp_bulan,"Agustus ");
        }

        else if (strstr(current->kontrol,"Sep")!=NULL){
            strcpy(temp_bulan,"September ");
        }

        else if (strstr(current->kontrol,"Okt")!=NULL){
            strcpy(temp_bulan,"Oktober ");
        }

        else if (strstr(current->kontrol,"Nov")!=NULL){
            strcpy(temp_bulan,"November ");
        }

        else if (strstr(current->kontrol,"Des")!=NULL){
            strcpy(temp_bulan,"Desember ");
        }
            temp_kontrol[0] = current->kontrol[0];
            if ((current->kontrol[1] >= '0' && current->kontrol[1] <= '9')) {
                temp_kontrol[1] = current->kontrol[1];
                temp_kontrol[2] = ' ';
            } else {
                temp_kontrol[1] = ' ';
                temp_kontrol[2] = '\0';
            }            
            temp_kontrol[3] = '\0';

        int temp1 = strlen(current->kontrol);
        int j = 0;

        for (int i = temp1 - 4; i < temp1; ++i) {
            temp_tahun[j] = current->kontrol[i];
            ++j;
        }
        temp_tahun[j] = '\0';

        if (current->kontrol[temp1 - 3] == '-') {
            strcpy(temp_tahun, strrchr(current->kontrol, '-') + 1);
            if (atoi(temp_tahun) <= 24) {
                strcpy(tahun, "20");
                strcat(tahun, temp_tahun);
            } else {
                strcpy(tahun, "19");
                strcat(tahun, temp_tahun);
            }
        } else {
            strcpy(tahun, temp_tahun);
        }

        strcat(temp_kontrol, temp_bulan);
        strcat(temp_kontrol, tahun);
        strcpy(current->kontrol, temp_kontrol);

        current = current->next;
    }
}

// void printDataPasien() {
//     dataPasien *current = head_dataPasien;
//     while (current != NULL) {
//         printf("| %-2d | %-15s | %-18s | %-13s | %-14s | %-13s | %-4d | %-10s | %-9s |\n",
//                current->no, current->nama, current->alamat, current->kota, current->tempat_lahir,
//                current->tanggal_lahir, current->umur, current->noBPJS, current->id);
//         current = current->next;
//     }
// }

void printDataPasien() {
    riwayatDatang *current = head_riwayatDatang;
    while (current != NULL) {
        printf("| %d |\n",current->biaya);
        current = current->next;
    }
}

void baca() {
    bacaDataPasien("DataPMC20232024 - Data Pasien.csv");
    bacaBiayaTindakan("DataPMC20232024 - Biaya Tindakan.csv");
    bacaRiwayatDatang("DataPMC20232024 - Riwayat Datang, Diag,, Tindakan.csv");
    rapikanFormatDataPasien();
    rapikanFormatRiwayatDatang_Tanggal();
    rapikanFormatRiwayatDatang_Kontrol();
    // printDataPasien();
}
