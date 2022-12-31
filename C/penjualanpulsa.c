#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct
{
    char nama[50], nomor[15], operator[25];
    int hargaPembelian, hargaPenjualan, totalPembelian, totalPenjualan;
}Data;

void cover() // Fungsi untuk Menampilkan Nama Author
{
    printf("===============================\n");
    printf("Project Semester 1             \n");
    printf("Nama  : \n");
    printf("NIM   : \n"); 
    printf("Kelas : \n");
    printf("Absen : \n");
    printf("===============================\n");
}

void menuOperator(){
    printf("==========================================\n");
    printf("=========== Welcome to MyPulsa ===========\n");
    printf("==========================================\n");
    printf("Silahkan Pilih Operator Anda : \n");
    printf("1. Telkomsel\n");
    printf("2. XL\n");
    printf("3. Indosat\n");
    printf("4. Axis\n");
    printf("5. 3\n");
    printf("6. Smartfren\n");
    printf("7. by.U\n");
}

void menuNominal(){
    printf("==========================================\n");
    printf("=========== Welcome to MyPulsa ===========\n");
    printf("==========================================\n");
    printf("Silahkan Pilih Nominal Pengisian : \n");
    printf("1. 5.000\n");
    printf("2. 10.000\n");
    printf("3. 20.000\n");
    printf("4. 25.000\n");
    printf("5. 50.000\n");
    printf("6. 75.000\n");
    printf("7. 100.000\n");
}

void printData(Data *data, int n);

int main(){
    cover();
    int menu, menu1, jumlah;
    bool keluar = true;
    bool keluar1 = true;


    printf("Haaii, Masukan jumlah berapa kali anda ingin mengisi pulsa : "); scanf("%d", &jumlah);
    // int i = 0;// untuk nama pembeli

    int j = 0; //untuk operator

    Data data[jumlah];

    for (int i = 0; i < jumlah; i++){

        system("clear");
        getchar();
        printf("Masukan Nama Anda : ");
        fgets(data[i].nama, 50, stdin);
        printf("Masukan Nomor Anda : ");scanf("%s", &data[i].nomor);
        menuOperator();
        printf("Pilihan : "); scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            strcpy(data[i].operator, "Telkomsel");
            do
            {
                menuNominal();
                printf("Pilihan : "); scanf("%d", &menu1);
                
                switch (menu1)
                {
                case 1:
                    data[i].hargaPembelian = 5000;
                    data[i].hargaPenjualan = 7000;
                    data[i].totalPembelian = 5000;
                    data[i].totalPenjualan = 7000;
                    keluar1 = false;                   
                    break;
                case 2:
                    data[i].hargaPembelian = 10000;
                    data[i].hargaPenjualan = 12000;
                    data[i].totalPembelian = 10000;
                    data[i].totalPenjualan = 12000;
                    keluar1 = false;
                    break;
                case 3:
                    data[i].hargaPembelian = 20000;
                    data[i].hargaPenjualan = 22000;
                    data[i].totalPembelian = 20000;
                    data[i].totalPenjualan = 22000;
                    keluar1 = false;
                    break;
                case 4:
                    data[i].hargaPembelian = 25000;
                    data[i].hargaPenjualan = 27000;
                    data[i].totalPembelian = 25000;
                    data[i].totalPenjualan = 27000;
                    keluar1 = false;
                    break;
                case 5:
                    data[i].hargaPembelian = 50000;
                    data[i].hargaPenjualan = 52000;
                    data[i].totalPembelian = 50000;
                    data[i].totalPenjualan = 52000;
                    keluar1 = false;
                    break;
                case 6:
                    data[i].hargaPembelian = 75000;
                    data[i].hargaPenjualan = 77000;
                    data[i].totalPembelian = 75000;
                    data[i].totalPenjualan = 77000;
                    keluar1 = false;
                    break;
                case 7:
                    data[i].hargaPembelian = 100000;
                    data[i].hargaPenjualan = 100000;
                    data[i].totalPembelian = 100000;
                    data[i].totalPenjualan = 100000;
                    keluar1 = false;
                    break;
                case 8:
                    keluar1 = false;
                    break;
                
                default:
                    break;
                }
            } while (keluar1);
            
            break;
        case 2:
            strcpy(data[i].operator, "XL");
            do
            {
                menuNominal();
                printf("Pilihan : "); scanf("%d", &menu1);
                
                switch (menu1)
                {
                case 1:
                    data[i].hargaPembelian = 5000;
                    data[i].hargaPenjualan = 7000;
                    data[i].totalPembelian = 5000;
                    data[i].totalPenjualan = 7000;
                    keluar1 = false;                   
                    break;
                case 2:
                    data[i].hargaPembelian = 10000;
                    data[i].hargaPenjualan = 12000;
                    data[i].totalPembelian = 10000;
                    data[i].totalPenjualan = 12000;
                    keluar1 = false;
                    break;
                case 3:
                    data[i].hargaPembelian = 20000;
                    data[i].hargaPenjualan = 22000;
                    data[i].totalPembelian = 20000;
                    data[i].totalPenjualan = 22000;
                    keluar1 = false;
                    break;
                case 4:
                    data[i].hargaPembelian = 25000;
                    data[i].hargaPenjualan = 27000;
                    data[i].totalPembelian = 25000;
                    data[i].totalPenjualan = 27000;
                    keluar1 = false;
                    break;
                case 5:
                    data[i].hargaPembelian = 50000;
                    data[i].hargaPenjualan = 52000;
                    data[i].totalPembelian = 50000;
                    data[i].totalPenjualan = 52000;
                    keluar1 = false;
                    break;
                case 6:
                    data[i].hargaPembelian = 75000;
                    data[i].hargaPenjualan = 77000;
                    data[i].totalPembelian = 75000;
                    data[i].totalPenjualan = 77000;
                    keluar1 = false;
                    break;
                case 7:
                    data[i].hargaPembelian = 100000;
                    data[i].hargaPenjualan = 100000;
                    data[i].totalPembelian = 100000;
                    data[i].totalPenjualan = 100000;
                    keluar1 = false;
                    break;
                case 8:
                    keluar1 = false;
                    break;
                
                default:
                    break;
                }
            } while (keluar1);
            break;
        case 3:
            strcpy(data[i].operator, "Indosat");
            do
            {
                menuNominal();
                printf("Pilihan : "); scanf("%d", &menu1);
                
                switch (menu1)
                {
                case 1:
                    data[i].hargaPembelian = 5000;
                    data[i].hargaPenjualan = 7000;
                    data[i].totalPembelian = 5000;
                    data[i].totalPenjualan = 7000; 
                    keluar1 = false;                  
                    break;
                case 2:
                    data[i].hargaPembelian = 10000;
                    data[i].hargaPenjualan = 12000;
                    data[i].totalPembelian = 10000;
                    data[i].totalPenjualan = 12000;
                    keluar1 = false;
                    break;
                case 3:
                    data[i].hargaPembelian = 20000;
                    data[i].hargaPenjualan = 22000;
                    data[i].totalPembelian = 20000;
                    data[i].totalPenjualan = 22000;
                    keluar1 = false;
                    break;
                case 4:
                    data[i].hargaPembelian = 25000;
                    data[i].hargaPenjualan = 27000;
                    data[i].totalPembelian = 25000;
                    data[i].totalPenjualan = 27000;
                    keluar1 = false;
                    break;
                case 5:
                    data[i].hargaPembelian = 50000;
                    data[i].hargaPenjualan = 52000;
                    data[i].totalPembelian = 50000;
                    data[i].totalPenjualan = 52000;
                    keluar1 = false;
                    break;
                case 6:
                    data[i].hargaPembelian = 75000;
                    data[i].hargaPenjualan = 77000;
                    data[i].totalPembelian = 75000;
                    data[i].totalPenjualan = 77000;
                    keluar1 = false;
                    break;
                case 7:
                    data[i].hargaPembelian = 100000;
                    data[i].hargaPenjualan = 100000;
                    data[i].totalPembelian = 100000;
                    data[i].totalPenjualan = 100000;
                    keluar1 = false;
                    break;
                case 8:
                    keluar1 = false;
                    break;
                
                default:
                    break;
                }
            } while (keluar1);
            break;
        case 4:
            strcpy(data[i].operator, "Axis");
            do
            {
                menuNominal();
                printf("Pilihan : "); scanf("%d", &menu1);
                
                switch (menu1)
                {
                case 1:
                    data[i].hargaPembelian = 5000;
                    data[i].hargaPenjualan = 7000;
                    data[i].totalPembelian = 5000;
                    data[i].totalPenjualan = 7000;
                    keluar1 = false;                    
                    break;
                case 2:
                    data[i].hargaPembelian = 10000;
                    data[i].hargaPenjualan = 12000;
                    data[i].totalPembelian = 10000;
                    data[i].totalPenjualan = 12000;
                    keluar1 = false;
                    break;
                case 3:
                    data[i].hargaPembelian = 20000;
                    data[i].hargaPenjualan = 22000;
                    data[i].totalPembelian = 20000;
                    data[i].totalPenjualan = 22000;
                    keluar1 = false;
                    break;
                case 4:
                    data[i].hargaPembelian = 25000;
                    data[i].hargaPenjualan = 27000;
                    data[i].totalPembelian = 25000;
                    data[i].totalPenjualan = 27000;
                    keluar1 = false;
                    break;
                case 5:
                    data[i].hargaPembelian = 50000;
                    data[i].hargaPenjualan = 52000;
                    data[i].totalPembelian = 50000;
                    data[i].totalPenjualan = 52000;
                    keluar1 = false;
                    break;
                case 6:
                    data[i].hargaPembelian = 75000;
                    data[i].hargaPenjualan = 77000;
                    data[i].totalPembelian = 75000;
                    data[i].totalPenjualan = 77000;
                    keluar1 = false;
                    break;
                case 7:
                    data[i].hargaPembelian = 100000;
                    data[i].hargaPenjualan = 100000;
                    data[i].totalPembelian = 100000;
                    data[i].totalPenjualan = 100000;
                    keluar1 = false;
                    break;
                case 8:
                    keluar1 = false;
                    break;
                
                default:
                    break;
                }
            } while (keluar1);
            break;
        case 5:
            strcpy(data[i].operator, "3");
            do
            {
                menuNominal();
                printf("Pilihan : "); scanf("%d", &menu1);
                
                switch (menu1)
                {
                case 1:
                    data[i].hargaPembelian = 5000;
                    data[i].hargaPenjualan = 7000;
                    data[i].totalPembelian = 5000;
                    data[i].totalPenjualan = 7000;
                    keluar1 = false;                   
                    break;
                case 2:
                    data[i].hargaPembelian = 10000;
                    data[i].hargaPenjualan = 12000;
                    data[i].totalPembelian = 10000;
                    data[i].totalPenjualan = 12000;
                    keluar1 = false;
                    break;
                case 3:
                    data[i].hargaPembelian = 20000;
                    data[i].hargaPenjualan = 22000;
                    data[i].totalPembelian = 20000;
                    data[i].totalPenjualan = 22000;
                    keluar1 = false;
                    break;
                case 4:
                    data[i].hargaPembelian = 25000;
                    data[i].hargaPenjualan = 27000;
                    data[i].totalPembelian = 25000;
                    data[i].totalPenjualan = 27000;
                    keluar1 = false;
                    break;
                case 5:
                    data[i].hargaPembelian = 50000;
                    data[i].hargaPenjualan = 52000;
                    data[i].totalPembelian = 50000;
                    data[i].totalPenjualan = 52000;
                    keluar1 = false;
                    break;
                case 6:
                    data[i].hargaPembelian = 75000;
                    data[i].hargaPenjualan = 77000;
                    data[i].totalPembelian = 75000;
                    data[i].totalPenjualan = 77000;
                    keluar1 = false;
                    break;
                case 7:
                    data[i].hargaPembelian = 100000;
                    data[i].hargaPenjualan = 100000;
                    data[i].totalPembelian = 100000;
                    data[i].totalPenjualan = 100000;
                    keluar1 = false;
                    break;
                case 8:
                    keluar1 = false;
                    break;
                
                default:
                    break;
                }
            } while (keluar1);
            break;
        case 6:
            strcpy(data[i].operator, "Smartfren");
            do
            {
                menuNominal();
                printf("Pilihan : "); scanf("%d", &menu1);
                
                switch (menu1)
                {
                case 1:
                    data[i].hargaPembelian = 5000;
                    data[i].hargaPenjualan = 7000;
                    data[i].totalPembelian = 5000;
                    data[i].totalPenjualan = 7000;
                    keluar1 = false;                   
                    break;
                case 2:
                    data[i].hargaPembelian = 10000;
                    data[i].hargaPenjualan = 12000;
                    data[i].totalPembelian = 10000;
                    data[i].totalPenjualan = 12000;
                    keluar1 = false;
                    break;
                case 3:
                    data[i].hargaPembelian = 20000;
                    data[i].hargaPenjualan = 22000;
                    data[i].totalPembelian = 20000;
                    data[i].totalPenjualan = 22000;
                    keluar1 = false;
                    break;
                case 4:
                    data[i].hargaPembelian = 25000;
                    data[i].hargaPenjualan = 27000;
                    data[i].totalPembelian = 25000;
                    data[i].totalPenjualan = 27000;
                    keluar1 = false;
                    break;
                case 5:
                    data[i].hargaPembelian = 50000;
                    data[i].hargaPenjualan = 52000;
                    data[i].totalPembelian = 50000;
                    data[i].totalPenjualan = 52000;
                    keluar1 = false;
                    break;
                case 6:
                    data[i].hargaPembelian = 75000;
                    data[i].hargaPenjualan = 77000;
                    data[i].totalPembelian = 75000;
                    data[i].totalPenjualan = 77000;
                    keluar1 = false;
                    break;
                case 7:
                    data[i].hargaPembelian = 100000;
                    data[i].hargaPenjualan = 100000;
                    data[i].totalPembelian = 100000;
                    data[i].totalPenjualan = 100000;
                    keluar1 = false;
                    break;
                case 8:
                    keluar1 = false;
                    break;
                
                default:
                    break;
                }
            } while (keluar1);
            break;
        case 7:
            strcpy(data[i].operator, "by.U");
            do
            {
                menuNominal();
                printf("Pilihan : "); scanf("%d", &menu1);
                
                switch (menu1)
                {
                case 1:
                    data[i].hargaPembelian = 5000;
                    data[i].hargaPenjualan = 7000;
                    data[i].totalPembelian = 5000;
                    data[i].totalPenjualan = 7000;
                    keluar1 = false;                   
                    break;
                case 2:
                    data[i].hargaPembelian = 10000;
                    data[i].hargaPenjualan = 12000;
                    data[i].totalPembelian = 10000;
                    data[i].totalPenjualan = 12000;
                    keluar1 = false;
                    break;
                case 3:
                    data[i].hargaPembelian = 20000;
                    data[i].hargaPenjualan = 22000;
                    data[i].totalPembelian = 20000;
                    data[i].totalPenjualan = 22000;
                    keluar1 = false;
                    break;
                case 4:
                    data[i].hargaPembelian = 25000;
                    data[i].hargaPenjualan = 27000;
                    data[i].totalPembelian = 25000;
                    data[i].totalPenjualan = 27000;
                    keluar1 = false;
                    break;
                case 5:
                    data[i].hargaPembelian = 50000;
                    data[i].hargaPenjualan = 52000;
                    data[i].totalPembelian = 50000;
                    data[i].totalPenjualan = 52000;
                    keluar1 = false;
                    break;
                case 6:
                    data[i].hargaPembelian = 75000;
                    data[i].hargaPenjualan = 77000;
                    data[i].totalPembelian = 75000;
                    data[i].totalPenjualan = 77000;
                    keluar1 = false;
                    break;
                case 7:
                    data[i].hargaPembelian = 100000;
                    data[i].hargaPenjualan = 100000;
                    data[i].totalPembelian = 100000;
                    data[i].totalPenjualan = 100000;
                    keluar1 = false;
                    break;
                case 8:
                    keluar1 = false;
                    break;
                
                default:
                    break;
                }
            } while (keluar1);
            break;
        case 8:
            keluar = false;
            break;
        default:
            break;
        }
    }
    printData(data, jumlah);
    
}

void printData(Data *data, int n){
    int totalbeli = 0, totaljual = 0;
    printf("=========================================\n");
    printf("===========  Struk Pembelian  ===========\n");
    printf("=========================================\n");
    for (int i = 0; i < n;  i++){
        printf("\nNama : %s", data[i].nama);
        printf("Nomor : %s", data[i].nomor);
        printf("\nOperator : %s", data[i].operator);
        printf("\nNominal : %d", data[i].hargaPembelian);
        printf("\nHarga : %d\n", data[i].hargaPenjualan);
    }
    printf("\n");

    printf("=========================================\n");
    printf("====== Total Penjualan & Pembelian ======\n"); 
    printf("=========================================\n");
    for (int i = 0; i <n; i++){
        totalbeli += data[i].hargaPembelian;
        totaljual += data[i].hargaPenjualan;
    }
    printf("\nTotal Pembelian Pulsa Hari ini : %d\n", totalbeli);
    printf("Total Penjualan Pulsa Hari ini : %d\n", totaljual);
    
}