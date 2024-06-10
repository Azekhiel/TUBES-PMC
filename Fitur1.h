#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <baca.h>

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

void tambah_data_pasien(dataPasien *dp)
{
    int jumlah;
    printf("Masukkan jumlah pasien yang akan ditambah : ");
    scanf("%d",&jumlah);

    dataPasien *temp = dp;
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
        scanf("%s",dp2->nama);
        printf("Masukkan alamat pasien : ");
        scanf("%s",dp2->alamat);
        printf("Masukkan kota pasien : ");
        scanf("%s",dp2->kota);
        printf("Masukkan tempat lahir pasien : ");
        scanf("%s",dp2->tempat_lahir);
        printf("Masukkan tanggal lahir pasien : ");
        scanf("%s",dp2->tanggal_lahir);
        printf("Masukkan umur pasien : ");
        scanf("%d",&dp2->umur);
        printf("Masukkan nomorBPJS pasien : ");
        scanf("%s",dp2->noBPJS);
        printf("Masukkan id pasien : ");
        scanf("%s",dp2->id);
        dp2->next = NULL;

        insert(dp,dp2);
    }
}

void ubah_data_pasien(dataPasien *dp)
{
    //belum selesai
    char ubahid[11],headerdata[13],databaru[255];
    printf("Masukkan id pasien yang datanya ingin diubah : ");
    scanf("%s",ubahid);
    printf("Masukkan data yang ingin diubah : ");
    scanf("%s",headerdata);
    printf("Masukkan data yang baru : ");
    scanf("%s",databaru);
}

void hapus_data_pasien(dataPasien *dp)
{
    char hapusid[11];
    printf("Masukkan id pasien yang ingin dihapus : ");
    scanf("%s",hapusid);
    deletekey(&dp,hapusid);
}

void cari_data_pasien(dataPasien *dp)
{
    char cariid[11];
    printf("Masukkan id pasien yang ingin dicari : ");
    scanf("%s",cariid);

    while(strcmp(dp->id,cariid)!=0)
    {
        dp = dp->next;
    }
    printf("Nomor Pasien : %d\n",dp->no);
    printf("Nama Pasien : %s\n",dp->nama);
    printf("Alamat Pasien : %s\n",dp->alamat);
    printf("Kota Pasien : %s\n",dp->kota);
    printf("Tempat Lahir Pasien : %s\n",dp->tempat_lahir);
    printf("Tanggal Lahir Pasien : %s\n",dp->tanggal_lahir);
    printf("Umur Pasien : %d\n",dp->umur);
    printf("Nomor BPJS Pasien : %s\n",dp->noBPJS);
    printf("ID Pasien : %s\n",dp->id);
}