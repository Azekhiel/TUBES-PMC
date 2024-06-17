#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baca.h"

typedef struct {
    char diagnosis[255];
    char tahun[5];
    char bulan[10];
    int count;
} DiagnosisBulanTahun;

int compare(const void* a, const void* b){
    DiagnosisBulanTahun* A = (DiagnosisBulanTahun*)a;
    DiagnosisBulanTahun* B = (DiagnosisBulanTahun*)b;

    int compareDiagnosis = strcmp(A->diagnosis, B->diagnosis);
    if (compareDiagnosis != 0){
        return compareDiagnosis;
    }

    int compareTahun = strcmp(A->tahun, B->tahun);
    if (compareTahun != 0){
        return compareTahun;
    }

    int compareCount = B->count - A->count; 
    if (compareCount != 0) {
        return compareCount;
    }

    int compareBulan = strcmp(A->bulan, B->bulan);
    return compareBulan;
}

void countAndSort(riwayatDatang* head){
    riwayatDatang* current = head;
    DiagnosisBulanTahun Array[100];
    int uniqueCount = 0;

    while(current != NULL){
        char line[255];
        strcpy(line, current->kontrol);
        strtok(line, " ");
        char *bulan = strtok(NULL, " ");
        char *tahun = strtok(NULL, " ");

        int found = 0;
        for (int i = 0; i < uniqueCount; i++){
            if (strcmp(Array[i].diagnosis, current->diagnosis)==0 && strcmp(Array[i].tahun, tahun)==0 && strcmp(Array[i].bulan, bulan)==0){
                Array[i].count++;
                found = 1;
                break;
            }
        }

        if (!found){
            strcpy(Array[uniqueCount].diagnosis, current->diagnosis);
            strcpy(Array[uniqueCount].tahun, tahun);
            strcpy(Array[uniqueCount].bulan, bulan);
            Array[uniqueCount].count = 1;
            uniqueCount++;
        }

        current = current->next;
    }

    qsort(Array, uniqueCount, sizeof(DiagnosisBulanTahun), compare);

    for (int i = 0; i < uniqueCount; i++) {
        if (i == 0 || strcmp(Array[i].diagnosis, Array[i-1].diagnosis) != 0) {
            printf("Diagnosis: %s\n", Array[i].diagnosis);
        }
        if (i == 0 || strcmp(Array[i].tahun, Array[i-1].tahun) != 0 || strcmp(Array[i].diagnosis, Array[i-1].diagnosis) != 0) {
            printf("  Tahun: %s\n", Array[i].tahun);
        }
        printf("    Bulan: %-10s| Jumlah: %d\n", Array[i].bulan, Array[i].count);
    }
    printf("\n");
}

void fitur5(){
    countAndSort(head_riwayatDatang);
}