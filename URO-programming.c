#include <stdio.h>
#include <string.h>

int hitung(int i, char j[2], int k);

int main()
{
    // Deklarasi variabel
    int a, b, c;
    char x[2];
    char y[2];

    // Keterangan operator
    printf("Operator:\n\n");
    printf("Penjumlahan (+)\nPengurangan (-)\nPerkalian (*)\n");
    printf("Pengulangan (AC)\nMenutup program (END)\n\n");
    
    // Input kalkulasi pertama
    printf("Angka: "); scanf("%d", &a);
    printf("Operator: "); scanf("%s", x);

    // Cek Operator
    if(strcmp(x,"END") == 0){
        printf("Terima kasih telah menggunakan kalkulator.");
        return 0;
    }
    while(strcmp(x,"AC") == 0){
        a = 0;
        printf("\n%d", a);
        printf("\nAngka: "); scanf("%d", &a);
        printf("Operator: "); scanf("%s", x);
    }
    while(strcmp(x,"+") != 0 && strcmp(x,"-") != 0 && strcmp(x,"*") != 0){
        printf("Operator invalid.");
        printf("\nOperator: "); scanf("%s", x);
    }

    printf("Angka: "); scanf("%d", &b);

    // Menentukan hasil
    c = hitung(a, x, b);
    printf("\n%d", c);

    // Tampilkan hasil, atau input kalkulasi kedua
    printf("\nOperator: "); scanf("%s", y);

    while (strcmp(y,"END") != 0){  
        // Menjadikan hasil = bilangan pertama
        a = c;

        // Cek Operator
        while(strcmp(y,"AC") == 0){
            a = 0;
            printf("\n%d", a);
            printf("\nAngka: "); scanf("%d", &a);
            printf("Operator: "); scanf("%s", y);
        }
        while (strcmp(y,"+") != 0 && strcmp(y,"-") != 0 && strcmp(y,"*") != 0){
            if(strcmp(x,"END") == 0){
                printf("Terima kasih telah menggunakan kalkulator.");
                return 0;
            }
            printf("Operator invalid.");
            printf("\nOperator: "); scanf("%s", y);
        }
        // Memasukkan bilangan kedua
        printf("Angka: "); scanf("%d", &b);

        // Menentukan hasil
        c = hitung (a, y, b);
        printf("\n%d",c);

        // Tampilkan hasil, atau input kalkulasi kedua
        printf("\nOperator: "); scanf("%s", y);
    }
    printf("Terima kasih telah menggunakan kalkulator.");
    return 0;
}

int hitung(int i, char j[2], int k)
{
    int hasil;

    // Pembacaan nilai operator
    if (strcmp(j,"+") == 0){
        hasil = i + k;
    }
    else if (strcmp(j,"-") == 0){
        hasil = i - k;
    }
    else if (strcmp(j,"*") == 0){
        hasil = i * k;
    }
    return hasil;
}