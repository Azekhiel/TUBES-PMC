#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baca.h"

void insert(dataPasien *prev_node, dataPasien *new_data)
{
    dataPasien* new_node = (dataPasien*)malloc(sizeof(dataPasien));
    new_node->no = new_data->no;
    strcpy(new_node->nama, new_data->nama);
    strcpy(new_node->alamat, new_data->alamat);
    strcpy(new_node->kota, new_data->kota);
    strcpy(new_node->tempat_lahir, new_data->tempat_lahir);
    strcpy(new_node->tanggal_lahir, new_data->tanggal_lahir);
    new_node->umur = new_data->umur;
    strcpy(new_node->noBPJS, new_data->noBPJS);
    strcpy(new_node->id, new_data->id);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

int deletekey(dataPasien **head, char key[11])
{
    dataPasien *cur_node = *head;
    dataPasien *prev_node = NULL;

    if (strcmp((*head)->id, key) == 13)
    {
        *head = (*head)->next;
        free(cur_node);
        return 1;
    }
    else
    {
        while (cur_node != NULL && strcmp(cur_node->id, key) != 13)
        {
            prev_node = cur_node;
            cur_node = cur_node->next;
        }

        if (cur_node != NULL)
        {
            prev_node->next = cur_node->next;
            free(cur_node);
            return 1;
        }
        return 0;
    }
}

int tambah_data_pasien(dataPasien *dp2)
{
    // int jumlah;
    // printf("Masukkan jumlah pasien yang akan ditambah : ");
    // scanf("%d",&jumlah);

    //debugging tool
    printf("\nnama input : %s \n" , dp2->nama);
    printf("umur input : %s \n" , dp2->nama);
    printf("tempat tanggal lahir input : %s \n" , dp2->nama);

    dataPasien *temp = head_dataPasien;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    int nomor = temp->no;

    for(int i = 0;i<1;i++)
    {
        
        dp2->no = nomor+i+1;
        dp2->next = NULL;

        insert(temp,dp2);
        return 1;
    }
    return 0;
    // printf("\n");
    // printf("Tambah data pasien berhasil");
    // printf("\n");
}
int ubah_data_pasien(const char *ubahid , const char *headerdata , const char *perubahan)
{
    int ub;
    int result = 0;
    //char ubahid[11], headerdata[13];
    char namadpn[50], namablkg[50], jalan[2], nmjln[255], nojln[10];
    char kdpn[5], nmkt[50], hari[2], bulan[10], tahun[5], bpjsb[13], iddpn[2], idblkg[9];

    //debugging tool
    printf("\nUbahid : %s \n" , ubahid);
    printf("header data : %s \n" , headerdata);
    printf("perubahan : %s \n" , perubahan);

    dataPasien *current = head_dataPasien;
    while (current != NULL)
    {   
        printf("\n %s:%s\n =>resulr string cmp : %d" ,ubahid , current->id , strcmp(current->id, ubahid));
        if (strcmp(current->id, ubahid) == 0 ||strcmp(current->id, ubahid) == 13)
        {   
            if (strcmp(headerdata, "nama") == 0)
            {
                printf("Masukkan data nama baru pasien : ");
                sscanf(perubahan , "%s %s", namadpn, namablkg);
                sprintf(current->nama, "%s %s", namadpn, namablkg);
                result = 1;
            }
            else if (strcmp(headerdata, "alamat") == 0)
            {
                printf("Masukkan data alamat baru pasien : ");
                sscanf(perubahan , "%s %s %s", jalan, nmjln, nojln);
                sprintf(current->alamat, "%s %s %s", jalan, nmjln, nojln);
                result = 1;
            }
            else if (strcmp(headerdata, "kota") == 0)
            {
                printf("Masukkan data kota baru pasien : ");
                sscanf(perubahan , "%s %s", kdpn, nmkt);
                sprintf(current->kota, "%s %s", kdpn, nmkt);
                result = 1;
            }
            else if (strcmp(headerdata, "tempat_lahir") == 0)
            {
                printf("Masukkan data tempat lahir baru pasien : ");
                sscanf(perubahan ,"%s %s", kdpn, nmkt);
                sprintf(current->tempat_lahir, "%s %s", kdpn, nmkt);
                result = 1;
            }
            else if (strcmp(headerdata, "tanggal_lahir") == 0)
            {
                printf("Masukkan data tanggal lahir baru pasien : ");
                sscanf(perubahan ,"%s %s %s", hari, bulan, tahun);
                sprintf(current->tanggal_lahir, "%s %s %s", hari, bulan, tahun);
                result = 1;
            }
            else if (strcmp(headerdata, "umur") == 0)
            {
                printf("Masukkan data umur baru pasien : ");
                sscanf(perubahan , "%d", &ub);
                current->umur = ub;
                result = 1;
            }
            else if (strcmp(headerdata, "noBPJS") == 0)
            {
                printf("Masukkan data nomor BPJS baru pasien : ");
                sscanf(perubahan,"%s", bpjsb);
                strcpy(current->noBPJS, bpjsb);
                result = 1;
            }
            else if (strcmp(headerdata, "id") == 0)
            {
                printf("Masukkan data id baru pasien : ");
                sscanf(perubahan , "%s %s", iddpn, idblkg);
                sprintf(current->id, "%s %s", iddpn, idblkg);
                result = 1;
            }
            printf("\nProses mencari ID ketemu , result : %d\n" , result);
            break;
        }
        current = current->next;
    }
    return result;
    
}

int hapus_data_pasien(const char *hapusid)
{
    //debugging tool
    printf("\nhapusID : %s \n" , hapusid);
    

    char *hapusid_pasien ;
    strcpy(hapusid_pasien , hapusid);
    int result = deletekey(&head_dataPasien,hapusid_pasien);
    printf("\n");
    printf("Hapus data pasien berhasil");
    printf("\n");
    return result;
}

dataPasien *cari_data_pasien(const char *cariid)
{
    // char cariid[11];
    // printf("Masukkan id pasien yang ingin dicari : ");
    // getchar(); 
    // scanf("%[^\n]", cariid);
    // printf("\n");

    //debugging tool
    printf("\ncariiD : %s \n" , cariid);

    dataPasien *current = head_dataPasien;
    while(current != NULL && strcmp(current->id,cariid)!=13)
    {
        current = current->next;
    }
    printf("Nomor Pasien : %d\n",current->no);
    printf("Nama Pasien : %s\n",current->nama);
    printf("Alamat Pasien : %s\n",current->alamat);
    printf("Kota Pasien : %s\n",current->kota);
    printf("Tempat Lahir Pasien : %s\n",current->tempat_lahir);
    printf("Tanggal Lahir Pasien : %s\n",current->tanggal_lahir);
    printf("Umur Pasien : %d\n",current->umur);
    printf("Nomor BPJS Pasien : %s\n",current->noBPJS);
    printf("ID Pasien : %s\n",current->id);
    printf("\n");
    return current;
}