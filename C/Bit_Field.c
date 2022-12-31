#include <stdio.h>
#include <stdlib.h>

struct convert
{
    /* data di deklarasi kan hanya untuk 8 bit = 0 - 255 */
    unsigned int num : 8;
};

int main(){
    int number;
    printf("Masukan angka : "); scanf("%d", &number);
    // obj.num = number;
    struct convert obj = {number};

    int start, end, j=0;
    char hexa[] = "0123456789ABCDEF";
    char hex[1024];

    while (obj.num != 0)
    {
        /* code */
        start = obj.num / 16;
        end = obj.num % 16;

        hex[j++] = hexa[end];

        obj.num = start;
    }
    printf("Bilangan Hexadecimalnya adalah ");

    for (int i = j-1; i >= 0; i--)
    {
        /* code */
        printf("%c", hex[i]);
    }
    printf("\n");
    

    
}
