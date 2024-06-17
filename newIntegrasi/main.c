#include <stdio.h>
#include <stdlib.h>

#include "fitur1.h"
#include "fitur2.h"
#include "fitur3.h"
#include "fitur4.h"
#include "fitur5.h"
#include "fitur6.h"
#include "simpan.h"
#include "baca.h"

int main(){
    baca();
    int implementasi;
    int fitur;

    while (implementasi != 7){
        printf("Daftar implementasi : \n");
        printf("1. Data pasien yang datang ke klinik\n");
        printf("2. Riwayat pasien yang datang ke klinik\n");
        printf("3. Informasi dan riwayat medis\n");
        printf("4. Informasi laporan pendapatan\n");
        printf("5. Informasi jumlah pasien dan penyakit yang diderita\n");
        printf("6. Informasi terkait pasien yang perlu datang kembali\n");
        printf("7. Exit");
        printf("\n");
        printf("Masukkan implementasi yang diinginkan : ");
        scanf("%d", &implementasi);
        printf("\n");

        switch(implementasi){

            // Implementasi 1 data pasien yang datang ke klinik x
            case 1:
                printf("Daftar fitur : \n");
                printf("1. Menambah data pasien\n");
                printf("2. Mengubah data pasien\n");
                printf("3. Menghapus data pasien\n");
                printf("4. Mencari data pasien\n");
                printf("\n");
                printf("Masukkan fitur yang diinginkan : ");
                scanf("%d", &fitur);
                printf("\n");

                switch(fitur){

                    // Menambah data pasien yang datang ke klinik x
                    case 1:
                        tambah_data_pasien();
                        break;

                    // Mengubah data pasien yang datang ke klinik x
                    case 2:
                        ubah_data_pasien();
                        break;

                    // Menghapus data pasien yang datang ke klinik x
                    case 3:
                        hapus_data_pasien();
                        break;

                    // Mencari data pasien yang datang ke klinik x
                    case 4:
                        cari_data_pasien();
                        break;
                }
                break;


            
            // Implementasi 2 riwayat kedatangan, diagnosis, dan tindakan 
            // pada pasien yang datang ke klinik x
            case 2:
                printf("Daftar fitur :\n");
                printf("1. Menambah data riwayat kedatangan, diagnosis, dan tindakan\n");
                printf("2. Mengubah data riwayat kedatangan, diagnosis, dan tindakan\n");
                printf("3. Menghapus data riwayat kedatangan, diagnosis, dan tindakan\n");
                printf("4. Mencari data riwayat kedatangan, diagnosis, dan tindakan\n");
                printf("\n");
                printf("Masukkan fitur yang diinginkan : ");
                scanf("%d", &fitur);
                while (getchar() != '\n');

                switch(fitur){

                    // Menambah data riwayat kedatangan, diagnosis, dan tindakan
                    case 1:
                        tambahRiwayat();
                        break;

                    // Mengubah data riwayat kedatangan, diagnosis, dan tindakan
                    case 2:
                        ubahRiwayat();
                        break;

                    // Menghapus data riwayat kedatangan, diagnosis, dan tindakan
                    case 3:
                        hapusRiwayat();
                        break;

                    // Mencari data riwayat kedatangan, diagnosis, dan tindakan
                    case 4:
                        cariRiwayat();
                        break;
                }
                break;



            // Implementasi 3 memberikan informasi dan riwayat medis 
            // di klinik x kepada petugas medis
            case 3:
            fitur3();
                break;



            // Implementasi 4 mendapat informasi laporan pendapatan bulanan, tahunan, dan
            // informasi rata rata pendapatan per tahun yang didapat di klinik x
            case 4:
                fitur4();
                break;



            // Implementasi 5 mendapat informasi jumlah pasien dan penyakit yang diderita pasien
            // (diurutkan mulai dari terbesar hingga terkecil) per bulan dan per tahun
            case 5:
                fitur5();
                break;



            // Memberikan informasi kepada petugas medis terkait pasien yang perlu kembali
            case 6:
                fitur6();
                break;



            // Exit
            case 7 :
                break;
        }
    }

    simpan();




    return 0;
}