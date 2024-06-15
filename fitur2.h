#include "baca.h"

void hapusRiwayat(){
    riwayatDatang *current = head_riwayatDatang;
    riwayatDatang *prev = NULL;
    char idPasien[255];
    fgets(idPasien,sizeof(idPasien),stdin);

    
    while (current!=NULL){
        if (strcmp(current->id,idPasien)==0 && prev!=NULL){
            prev->next = current->next;
        }
        prev = current;
        current = current->next;        
    }
}
//No,Tanggal,ID Pasien,Diagnosis,Tindakan,Kontrol,Biaya (Rp)
void ubahRiwayat(){
    riwayatDatang *current = head_riwayatDatang;
    char idPasien[255];
    fgets(idPasien,sizeof(idPasien),stdin);

    while (current!=NULL){
        if (strcmp(current->id,idPasien)==0){
            printf("Tanggal: ");
            fgets(current->tanggal,sizeof(255),stdin);
            printf("ID Pasien: ");
            fgets(current->id,sizeof(255),stdin);
            printf("Diagnosis: ");
            fgets(current->diagnosis,sizeof(255),stdin);
            printf("Tindakan: ");
            fgets(current->tindakan,sizeof(255),stdin);
            printf("Kontrol: ");
            fgets(current->kontrol,sizeof(255),stdin);
            printf("Biaya (Rp): ");
            scanf("%d",&current->biaya);
            break;
        }
        current = current->next;        
    }
}
void tambahRiwayat(){
    
}
