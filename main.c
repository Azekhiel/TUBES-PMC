#include <stdio.h>
#include <stdlib.h>

#include "my_function.h"

// Cara nge execute code
// ketik di terminal
// gcc -o my_program main.c my_function.c
// ./my_program


int main(){
    int implementasi;
    int fitur;

    while (implementasi != 7){
        printf("Masukkan implementasi yang diinginkan : ");
        scanf("%d", &implementasi);
        printf("\n");

        switch(implementasi){

            // Implementasi 1 data pasien yang datang ke klinik x
            case 1:
                printf("Masukkan fitur yang diinginkan : ");
                scanf("%d", &fitur);

                switch(fitur){

                    // Menambah data pasien yang datang ke klinik x
                    case 1:
                        // Contoh 
                        myFunction();
                        break;

                    // Mengubah data pasien yang datang ke klinik x
                    case 2:
                        break;

                    // Menghapus data pasien yang datang ke klinik x
                    case 3:
                        break;

                    // Mencari data pasien yang datang ke klinik x
                    case 4:
                        break;
                }
                break;


            
            // Implementasi 2 riwayat kedatangan, diagnosis, dan tindakan 
            // pada pasien yang datang ke klinik x
            case 2:
                printf("Masukkan fitur yang diinginkan : ");
                scanf("%d", fitur);

                switch(fitur){

                    // Menambah data riwayat kedatangan, diagnosis, dan tindakan
                    case 1:
                        break;

                    // Mengubah data riwayat kedatangan, diagnosis, dan tindakan
                    case 2:
                        break;

                    // Menghapus data riwayat kedatangan, diagnosis, dan tindakan
                    case 3:
                        break;

                    // Mencari data riwayat kedatangan, diagnosis, dan tindakan
                    case 4:
                        break;
                }
                break;



            // Implementasi 3 memberikan informasi dan riwayat medis 
            // di klinik x kepada petugas medis
            case 3:
                break;



            // Implementasi 4 mendapat informasi laporan pendapatan bulanan, tahunan, dan
            // informasi rata rata pendapatan per tahun yang didapat di klinik x
            case 4:
                break;



            // Implementasi 5 mendapat informasi jumlah pasien dan penyakit yang diderita pasien
            // (diurutkan mulai dari terbesar hingga terkecil) per bulan dan per tahun
            case 5:
                break;



            // Memberikan informasi kepada petugas medis terkait pasien yang perlu kembali
            case 6:
                break;



            // Exit
            case 7 :
                break;
        }
    }




    return 0;
}