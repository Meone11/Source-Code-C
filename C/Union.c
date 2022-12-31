#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union convert
{
    /* data */
    unsigned int num;
};

int main(){
    union convert obj;
    int number;
    printf("masukan angka : "); scanf("%d", &obj.num);
    number = obj.num;
    printf("%d Hexadecimalnya : %d\n", number, obj.num);

    int start, end, count=0; 
    char hexa[] = "0123456789ABCDEF";
    char hex[1024];
    while (number != 0){
        start = number/16;
        end = number%16;

        hex[count++] = hexa[end];

        number = start;

    }

    printf("Bilangan Hexadecimalnya adalah ");
    for (int i = count-1; i >= 0 ; i--)
    {
        /* code */
        printf("%c",hex[i]);
    }
    printf("\n");
     

}
