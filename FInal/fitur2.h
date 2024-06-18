#include "baca.h"
//No,Tanggal,ID Pasien,Diagnosis,Tindakan,Kontrol,Biaya (Rp)
void printRiwayat(riwayatDatang *tes) {
    printf("Tanggal: %s\nID Pasien: %s\nDiagnosis: %s\nTindakan: %s\nKontrol: %s\nBiaya: %d\n", 
           tes->tanggal, tes->id, tes->diagnosis, tes->tindakan, tes->kontrol, tes->biaya);
}

void hapusRiwayat(){
    riwayatDatang *current = head_riwayatDatang;
    riwayatDatang *prev = NULL;
    char idPasien[255];
    char hapus;
    printf("Masukkan ID Pasien: ");
    fgets(idPasien,sizeof(idPasien),stdin);
    idPasien[strcspn(idPasien, "\n")] = '\0'; 
    
    while (current!=NULL){
        if (strcmp(current->id,idPasien)==0 && prev!=NULL){
            printRiwayat(current);
            printf("Hapus (Y/N): ");
            scanf("%c",&hapus);
            getchar();
            if (hapus=='Y'){
                prev->next = current->next;
            }
        }
        if (strcmp(current->id,idPasien)==0 && prev==NULL){
            printRiwayat(current);
            printf("Hapus (Y/N): ");
            scanf("%c",&hapus);
            getchar();
            if (hapus=='Y'){
                head_riwayatDatang = current->next;
            }            
        }
        prev = current;
        current = current->next;        
    }
}
//No,Tanggal,ID Pasien,Diagnosis,Tindakan,Kontrol,Biaya (Rp)
void ubahRiwayat(){
    riwayatDatang *current = head_riwayatDatang;
    char idPasien[255];
    char ubah;
    printf("Masukkan ID Pasien: ");
    fgets(idPasien,sizeof(idPasien),stdin);
    idPasien[strcspn(idPasien, "\n")] = '\0'; 
    int i=1;

    while (current!=NULL){
        if (strcmp(current->id,idPasien)==0){
            printf("Data Pasien (%s) ke-%d\n",idPasien,i);
            printRiwayat(current);
            printf("Ubah Riwayat(Y/N): ");
            scanf("%c",&ubah);
            getchar();
            if (ubah=='Y'){    
                printf("Tanggal: ");
                fgets(current->tanggal,sizeof(current->tanggal),stdin);
                current->tanggal[strcspn(current->tanggal, "\n")] = '\0'; 

                printf("Diagnosis: ");
                fgets(current->diagnosis,sizeof(current->diagnosis),stdin);
                current->diagnosis[strcspn(current->diagnosis, "\n")] = '\0'; 

                printf("Tindakan: ");
                fgets(current->tindakan,sizeof(current->tindakan),stdin);
                current->tindakan[strcspn(current->tindakan, "\n")] = '\0'; 

                printf("Kontrol: ");
                fgets(current->kontrol,sizeof(current->kontrol),stdin);
                current->kontrol[strcspn(current->kontrol, "\n")] = '\0'; 

                printf("Biaya (Rp): ");
                scanf("%d",&current->biaya);
                getchar();
                printf("\n");
                i++;
            }
        }
        current = current->next;        
    }
}
//No,Tanggal,ID Pasien,Diagnosis,Tindakan,Kontrol,Biaya (Rp)
void tambahRiwayat(){
    riwayatDatang *current = head_riwayatDatang;
    riwayatDatang *newNode = (riwayatDatang *)malloc(sizeof(riwayatDatang));
    newNode->next = NULL;

    int i =1;    
    if (current == NULL) {
        head_riwayatDatang = newNode;
    } 
    else {
        while (current->next != NULL) {
            current = current->next;
            i++;
        }
        current->next = newNode;
        i++;
    }    
    newNode->no = i;
    printf("Tanggal:");
    fgets(newNode->tanggal,sizeof(newNode->tanggal),stdin);
    newNode->tanggal[strcspn(newNode->tanggal, "\n")] = '\0'; 
    printf("ID Pasien:");
    fgets(newNode->id,sizeof(newNode->id),stdin);
    newNode->id[strcspn(newNode->id, "\n")] = '\0'; 
    printf("Diagnosis:");
    fgets(newNode->diagnosis,sizeof(newNode->diagnosis),stdin);
    newNode->diagnosis[strcspn(newNode->diagnosis, "\n")] = '\0';

    printf("Tindakan:");
    fgets(newNode->tindakan,sizeof(newNode->tindakan),stdin);
    newNode->tindakan[strcspn(newNode->tindakan, "\n")] = '\0';
    printf("Kontrol:");
    fgets(newNode->kontrol,sizeof(newNode->kontrol),stdin);
    newNode->kontrol[strcspn(newNode->kontrol, "\n")] = '\0';
    printf("Biaya:");
    scanf("%d",&newNode->biaya);
}

void cariRiwayat(){
    riwayatDatang *current = head_riwayatDatang;
    char idPasien[255];
    printf("Masukkan ID Pasien: ");
    fgets(idPasien,sizeof(idPasien),stdin);
    idPasien[strcspn(idPasien, "\n")] = '\0'; 

    while (current!=NULL){
        if (strcmp(current->id,idPasien)==0){
            printf("Riwayat kedatangan pasien dengan ID %s adalah:\n",current->id);
            printf("Pasien datang pada tanggal: %s\nDiagnosis pasien: %s\nTindakan yang diterima pasien: %s\nPasien kontrol pada tanggal: %s\n",current->tanggal,current->diagnosis,current->tindakan,current->kontrol);
            break;
        }
        current = current->next;        
    }
}   
