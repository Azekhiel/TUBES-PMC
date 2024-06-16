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

void deletekey(dataPasien **head, char key[11])
{
    dataPasien *cur_node = *head;
    dataPasien *prev_node = NULL;

    if (strcmp((*head)->id, key) == 0)
    {
        *head = (*head)->next;
        free(cur_node);
    }
    else
    {
        while (cur_node != NULL && strcmp(cur_node->id, key) != 0)
        {
            prev_node = cur_node;
            cur_node = cur_node->next;
        }

        if (cur_node != NULL)
        {
            prev_node->next = cur_node->next;
            free(cur_node);
        }
    }
}

void tambah_data_pasien()
{
    int jumlah;
    printf("Masukkan jumlah pasien yang akan ditambah : ");
    scanf("%d",&jumlah);

    dataPasien *temp = head_dataPasien;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    int nomor = temp->no;

    for(int i = 0;i<jumlah;i++)
    {
        dataPasien *dp2 = (dataPasien*)malloc(sizeof(dataPasien));
        dp2->no = nomor+i+1;
        printf("Masukkan nama pasien : ");
        getchar(); 
        scanf("%[^\n]", dp2->nama);
        printf("Masukkan alamat pasien : ");
        getchar(); 
        scanf("%[^\n]", dp2->alamat);
        printf("Masukkan kota pasien : ");
        getchar(); 
        scanf("%[^\n]", dp2->kota);
        printf("Masukkan tempat lahir pasien : ");
        getchar(); 
        scanf("%[^\n]", dp2->tempat_lahir);
        printf("Masukkan tanggal lahir pasien : ");
        getchar(); 
        scanf("%[^\n]", dp2->tanggal_lahir);
        printf("Masukkan umur pasien : ");
        scanf("%d",&dp2->umur);
        printf("Masukkan nomorBPJS pasien : ");
        scanf("%s",dp2->noBPJS);
        printf("Masukkan id pasien : ");
        getchar(); 
        scanf("%[^\n]", dp2->id);
        dp2->next = NULL;

        insert(temp,dp2);
    }
}

void ubah_data_pasien()
{
    int ub;
    char ubahid[11], headerdata[13];
    char namadpn[50], namablkg[50], jalan[2], nmjln[255], nojln[10];
    char kdpn[5], nmkt[50], hari[2], bulan[10], tahun[5], bpjsb[13], iddpn[2], idblkg[9];

    printf("Masukkan id pasien yang datanya ingin diubah : ");
    getchar(); 
    scanf("%[^\n]", ubahid);
    printf("Masukkan data yang ingin diubah : ");
    scanf("%s", headerdata);

    dataPasien *current = head_dataPasien;
    while (current != NULL)
    {
        if (strcmp(current->id, ubahid) == 0)
        {
            if (strcmp(headerdata, "nama") == 0)
            {
                printf("Masukkan data nama baru pasien : ");
                scanf("%s %s", namadpn, namablkg);
                sprintf(current->nama, "%s %s", namadpn, namablkg);
            }
            else if (strcmp(headerdata, "alamat") == 0)
            {
                printf("Masukkan data alamat baru pasien : ");
                scanf("%s %s %s", jalan, nmjln, nojln);
                sprintf(current->alamat, "%s %s %s", jalan, nmjln, nojln);
            }
            else if (strcmp(headerdata, "kota") == 0)
            {
                printf("Masukkan data kota baru pasien : ");
                scanf("%s %s", kdpn, nmkt);
                sprintf(current->kota, "%s %s", kdpn, nmkt);
            }
            else if (strcmp(headerdata, "tempat_lahir") == 0)
            {
                printf("Masukkan data tempat lahir baru pasien : ");
                scanf("%s %s", kdpn, nmkt);
                sprintf(current->tempat_lahir, "%s %s", kdpn, nmkt);
            }
            else if (strcmp(headerdata, "tanggal_lahir") == 0)
            {
                printf("Masukkan data tanggal lahir baru pasien : ");
                scanf("%s %s %s", hari, bulan, tahun);
                sprintf(current->tanggal_lahir, "%s %s %s", hari, bulan, tahun);
            }
            else if (strcmp(headerdata, "umur") == 0)
            {
                printf("Masukkan data umur baru pasien : ");
                scanf("%d", &ub);
                current->umur = ub;
            }
            else if (strcmp(headerdata, "noBPJS") == 0)
            {
                printf("Masukkan data nomor BPJS baru pasien : ");
                scanf("%s", bpjsb);
                strcpy(current->noBPJS, bpjsb);
            }
            else if (strcmp(headerdata, "id") == 0)
            {
                printf("Masukkan data id baru pasien : ");
                scanf("%s %s", iddpn, idblkg);
                sprintf(current->id, "%s %s", iddpn, idblkg);
            }
            break;
        }
        current = current->next;
    }
}

void hapus_data_pasien()
{
    char hapusid[11];
    printf("Masukkan id pasien yang ingin dihapus : ");
    getchar(); 
    scanf("%[^\n]", hapusid);
    deletekey(&head_dataPasien,hapusid);
}

void cari_data_pasien()
{
    char cariid[11];
    printf("Masukkan id pasien yang ingin dicari : ");
    getchar(); 
    scanf("%[^\n]", cariid);

    dataPasien *current = head_dataPasien;
    while(strcmp(current->id,cariid)!=0)
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
}