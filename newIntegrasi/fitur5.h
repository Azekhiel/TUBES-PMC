#include "baca.h"

// int tahunMulai() {
//     if (head_riwayatDatang == NULL) {
//         return 0; 
//     }
//     riwayatDatang *current = head_riwayatDatang;
//     int tahunMin = atoi(strrchr(current->tanggal, ' ')); 
//     while (current != NULL) {
//         int tahun = atoi(strrchr(current->tanggal, ' '));
//         if (tahun < tahunMin) {
//             tahunMin = tahun;
//         }
//         current = current->next;
//     }
//     return tahunMin;
// }

int cekTahun(char tahun[4]);
int cekDiagnosa(char diagnosa[100]);
int cekBulan(char bulan[20]);
void bubbleSort(int arr[], int num[], int n);
void sortMaximum(int count[8][12], int diagnosa);
void fitur5();

int cekTahun (char tahun[4]){
    if (tahun == NULL){
        return 0;
    }
    ;
if (strstr(tahun,"2022")!=NULL){
        return 22;
    } 
    else if (strstr(tahun,"2023")!=NULL){
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

// Function to sort array in descending order
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

// Function to display the sorted maximum values in a GTK dialog
void display_max_values(GtkWidget *parent, int count[][12], int diagnosa, int tahun , char *namapenyakit) {
    // Create GTK dialog
    GtkWidget *dialog, *content_area, *grid, *label;
    dialog = gtk_dialog_new_with_buttons(namapenyakit,
                                         GTK_WINDOW(parent),
                                         GTK_DIALOG_MODAL,
                                         "_NEXT=>", GTK_RESPONSE_OK,
                                         NULL);
    content_area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(content_area), grid);

    // Prepare month names
    const char* monthNames[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni",
                                  "Juli", "Agustus", "September", "Oktober", "November", "Desember"};

    // Sort and display values
    int sortedArray[12];
    int monthArray[12];
    for (int i = 0; i < 12; i++) {
        sortedArray[i] = count[diagnosa][i];
        monthArray[i] = i + 1;
    }
    bubbleSort(sortedArray, monthArray, 12);

    // Add labels to the grid
    for (int i = 0; i < 12; i++) {
        label = gtk_label_new(NULL);
        gchar *text = g_strdup_printf("%s | %d", monthNames[monthArray[i] - 1], sortedArray[i]);
        gtk_label_set_text(GTK_LABEL(label), text);
        g_free(text);
        gtk_grid_attach(GTK_GRID(grid), label, 0, i, 1, 1);
    }

    gtk_widget_show_all(dialog);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}


void fitur5(GtkWidget *widget) {
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

        tahun = cekTahun(strtahun);
        diagnosa = cekDiagnosa(current->diagnosis);
        bulan = bulanSama(strbulan);

        if (tahun == 22 && diagnosa > 0 && diagnosa <= 4 && bulan > 0 && bulan <= 12){
            count[diagnosa - 1][bulan - 1] += 1;
        } else if (tahun == 23 && diagnosa > 0 && diagnosa <= 4 && bulan > 0 && bulan <= 12){
            count[diagnosa + 3][bulan - 1] += 1;
        }
        
        current = current->next;
    }

    // Display results in GTK dialogs
    display_max_values(widget, count, 0, 22 , "Dehidrasi 2022");
    display_max_values(widget, count, 1, 22 , "Masuk angin 2023");
    display_max_values(widget, count, 2, 22 , "Keseleo 2022");
    display_max_values(widget, count, 3, 22 , "pusing 2022");
    display_max_values(widget, count, 4, 23 , "Dehidrasi 2023");
    display_max_values(widget, count, 5, 23, "Masuk angin 2023 ");
    display_max_values(widget, count, 6, 23 , "Keseleo 2023");
    display_max_values(widget, count, 7, 23 , "Pusing 2023");
}
