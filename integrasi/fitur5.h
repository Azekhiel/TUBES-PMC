#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baca.h"

int cekTahun (char tahun[4]){
    if (tahun == NULL){
        return 0;
    }

    if (strstr(tahun,"2022")!=NULL){
        return 22;
    } else if (strstr(tahun,"2023")!=NULL){
        return 23;
    } else {
        return 0;
    }
}

int cekDiagnosa (char diagnosa[100]){
    if (diagnosa == NULL){
        return 0;
    }

    if (strstr(diagnosa,"Dehidrasi")!=NULL){
        return 1;
    } else if (strstr(diagnosa,"Masuk Angin")!=NULL){
        return 2;
    } else if (strstr(diagnosa,"Keseleo")!=NULL){
        return 3;
    } else if (strstr(diagnosa,"Pusing")!=NULL){
        return 4;
    } else {
        return 0;
    }
}

int cekBulan (char bulan[20]){
    if (bulan == NULL){
        return 0;
    }

    if (strstr(bulan,"Januari")!=NULL){
        return 1;
    } else if (strstr(bulan,"Februari")!=NULL){
        return 2;
    } else if (strstr(bulan,"Maret")!=NULL){
        return 3;
    } else if (strstr(bulan,"April")!=NULL){
        return 4;
    } else if (strstr(bulan,"Mei")!=NULL){
        return 5;
    } else if (strstr(bulan,"Juni")!=NULL){
        return 6;
    } else if (strstr(bulan,"Juli")!=NULL){
        return 7;
    } else if (strstr(bulan,"Agustus")!=NULL){
        return 8;
    } else if (strstr(bulan,"September")!=NULL){
        return 9;
    } else if (strstr(bulan,"Oktober")!=NULL){
        return 10;
    } else if (strstr(bulan,"November")!=NULL){
        return 11;
    } else if (strstr(bulan,"Desember")!=NULL){
        return 12;
    } else {
        return 0;
    }
}

void bubbleSort(int arr[], int num[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                int temp_num = num[j];
                num[j] = num[j+1];
                num[j+1] = temp_num;
            }
        }
    }
}

void sortMaximum(int count[8][12], int diagnosa){
    int sortedArray[12];
    int monthArray[12];
    for (int i = 0; i < 12; i++) {
        sortedArray[i] = count[diagnosa][i];
        monthArray[i] = i + 1;
    }

    bubbleSort(sortedArray, monthArray, 12);

    for (int i = 0; i < 12; i++){
        switch(monthArray[i]){
            case 1:
                printf("Jan | %d \n", sortedArray[i]);
                break;
            case 2:
                printf("Feb | %d \n", sortedArray[i]);
                break;
            case 3:
                printf("Mar | %d \n", sortedArray[i]);
                break;
            case 4:
                printf("Apr | %d \n", sortedArray[i]);
                break;
            case 5:
                printf("May | %d \n", sortedArray[i]);
                break;
            case 6:
                printf("Jun | %d \n", sortedArray[i]);
                break;
            case 7:
                printf("Jul | %d \n", sortedArray[i]);
                break;
            case 8:
                printf("Aug | %d \n", sortedArray[i]);
                break;
            case 9:
                printf("Sep | %d \n", sortedArray[i]);
                break;
            case 10:
                printf("Oct | %d \n", sortedArray[i]);
                break;
            case 11:
                printf("Nov | %d \n", sortedArray[i]);
                break;
            case 12:
                printf("Dec | %d \n", sortedArray[i]);
                break;
        }
    }
    printf("\n");
}

void fitur5(){
    riwayatDatang *current = head_riwayatDatang;
    int count[8][12] = {0};
    int tahun, diagnosa, bulan;
    char line[30];
    char *strhari;
    char *strbulan;
    char *strtahun;
    while (current != NULL){
        strcpy(line, current->kontrol);
        strhari = strtok(line, " ");
        strbulan = strtok(NULL, " ");
        strtahun = strtok(NULL, " ");

        printf("%s %s %s \n", strhari, strbulan, strtahun);

        tahun = cekTahun(strtahun);
        diagnosa = cekDiagnosa(current->diagnosis);
        bulan = cekBulan(strbulan);

        if (tahun == 22 && diagnosa > 0 && diagnosa <= 4 && bulan > 0 && bulan <= 12){
            count[diagnosa - 1][bulan - 1] += 1;
        } else if (tahun == 23 && diagnosa > 0 && diagnosa <= 4 && bulan > 0 && bulan <= 12){
            count[diagnosa + 3][bulan - 1] += 1;
        }
        
        current = current->next;
    }

    for (int i = 0; i < 8; i++){
        printf ("%d : ", i);
        for (int j = 0; j < 12; j++){
            printf("%d ", count[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 8; i++){
        switch(i){
            case 0:
                printf("Dehidrasi 2022\n");
                sortMaximum(count,i);
                break;
            case 1:
                printf("Masuk Angin 2022\n");
                sortMaximum(count,i);
                break;
            case 2:
                printf("Keseleo 2022\n");
                sortMaximum(count,i);
                break;
            case 3:
                printf("Pusing 2022\n");
                sortMaximum(count,i);
                break;
            case 4:
                printf("Dehidrasi 2023\n");
                sortMaximum(count,i);
                break;
            case 5:
                printf("Masuk Angin 2023\n");
                sortMaximum(count,i);
                break;
            case 6:
                printf("Keseleo 2023\n");
                sortMaximum(count,i);
                break;
            case 7:
                printf("Pusing 2023\n");
                sortMaximum(count,i);
                break;
        }
    }
    sortMaximum(count,0);
}
