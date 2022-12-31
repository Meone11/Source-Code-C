#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int a,b,c,d,jum;
        char provider[30][30]={"Telkomsel","XL         ","Indosat      ","Axis     ","3        ","Smartfren"};
        int nominal[30]={5000,10000,20000,30000,50000,100000};
        char nama[20][20],nomor[20][20],opsel[20][20];
        int jawab1,biaya[20],pulsa[20];
        int harga[20]={7000,12000,22000,32000,52000,102000};
        char jawab2;
        for(a=0;a<50;a++)
        {
            printf("Masukkan Nama : ");
            scanf("%s",&nama[a]);
            printf("Daftar Operator:\n");
            printf("=================\n");
            printf("|Operator\t|\n");
            printf("=================\n");
            for(b=0;b<6;b++)
            {
                printf("|%s\t|\n",provider[b]);
                }
                printf("==================\n");
                printf("Masukkan Operator(nama): ");
                scanf("%s",&opsel[a]);
            printf("Masukkan Nomor: ");
            scanf("%s",&nomor[a]);
            printf("daftar nominal:\n");
            printf("==================\n");
            printf("|No.\t|nominal |\n");
            printf("==================\n");
            for(c=0;c<6;c++)
            {
                printf("|%d.    \t|%d\t     |\n",c+1,nominal[c]);
            }
            printf("==================\n");
            ulang1:
            printf("Masukkan nominal(1-6): ");
            scanf("%d",&jawab1);
            switch(jawab1)
            {
                case 1:
                pulsa[a]=nominal[0];
                biaya[a]=harga[0];
                break;
                case 2:
                pulsa[a]=nominal[1];
                biaya[a]=harga[1];
                break;
                case 3:
                pulsa[a]=nominal[2];
                biaya[a]=harga[2];
                break;
                case 4:
                pulsa[a]=nominal[3];
                biaya[a]=harga[3];
                break;
                case 5:
                pulsa[a]=nominal[4];
                biaya[a]=harga[4];
                break;
                case 6:
                pulsa[a]=nominal[5];
                biaya[a]=harga[5];
                break;
                default:
                printf("Masukkan Jawaban yang benar!\n");
                goto ulang1;
                break;
            }
            ulang2:
            printf("Ingin Masukkan lagi?(Y/N): ");
            scanf("%s",&jawab2);
            if(jawab2=='Y')
            {
                system("clear");
            continue;
            }
            else if(jawab2=='N')
            {
                jum=a+1;
                break;
                }
                else
                {
                printf("Masukkan jawaban yang benar!\n");
                goto ulang2;
                }
            }
    printf("=========================================STRUK PEMBAYARAN PULSA================================\n");
    printf("===============================================================================================\n");
printf("|No.\t|Nama\t   |Operator\t   |Nomor\t|Nominal\t|harga\tZ\t|\n");
printf("|-------|----------|---------------|------------|---------------|---------------|\n");
for(d=0;d<jum;d++)
    {
    printf("|%d.\t|%s\t   |%s   \t   |%s \t|%d\t\t|%d\t\t|\n",d+1,nama[d],opsel[d],nomor[d],pulsa[d],biaya[d]);
}
printf("===============================================================================================\n");
printf("\t\t\t\t   ~~~Terimakasih~~~\n");
return 0;
}
