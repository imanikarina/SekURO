#include <stdio.h>
#include <string.h>

int hitung(int i, char j[2], int k);
void kalkulator();
void polinomial();

int main()
{
    // Input pilihan kalkulator atau polinomial
    int pilih=0;

    while (pilih<3){
        printf("\n\nPilih salah satu opsi di bawah ini:\n 1. Kalkulator (+,-,*)\n");
        printf(" 2. Penurunan fungsi polinomial\n 3. Keluar\n");
        printf("\nPilihan Anda: ");
        scanf("%d", &pilih);

        // Pilihan
        if (pilih==1){
            kalkulator();
        }else if (pilih==2){
            polinomial();
        }else if (pilih!=3){
            printf("Pilihan invalid.\n\n");
            printf("Pilih salah satu opsi di bawah ini:\n1. Kalkulator (+,-,*)\n");
            printf("2. Penurunan fungsi polinomial\n3. Keluar\n");
            printf("\nPilihan Anda: ");
            scanf("%s", pilih);
        }
    }
    printf("\nTerima kasih telah menggunakan program ini.");
    return 0;
}

void polinomial()
{
    // Deklarasi variabel
    int m, n, koef;
    int t[100];

    // Input jumlah pangkat
    printf("\nMasukkan jumlah pangkat terbesar: ");
    scanf("%d", &m);

    // Input fungsi polinomial
    n = m;
    while (n > 0){
        printf("Koefisien x pangkat %d: ", n);
        scanf("%d", &t[n]);
        n--;
    }
    printf("Berikut ini adalah turunan dari fungsi polinomial anda: ");
    n = m;
    while (n > 1){
        koef = t[n] * m;
        m--;
        n--;
        printf("%d x^%d + ", koef, m);
    }
    koef = t[n]*m;
    n--;
    printf("%d", koef);
    return;
}

void kalkulator()
{
    // Deklarasi variabel
    int a, b, c;
    char x[2];
    char y[2];

    // Keterangan operator
    printf("\nKALKULATOR\n\nOperator:\n");
    printf(" - Penjumlahan (+)\n - Pengurangan (-)\n - Perkalian (*)\n");
    printf(" - Pengulangan (AC)\n - Menutup kalkulator (END)\n\n");
    
    // Input kalkulasi pertama
    printf("Angka: "); scanf("%d", &a);
    printf("Operator: "); scanf("%s", x);

    // Cek Operator
    if(strcmp(x,"END") == 0){
        printf("\nTerima kasih telah menggunakan kalkulator.");
        return;
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
                printf("\nTerima kasih telah menggunakan kalkulator.");
                return;
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
    printf("\nTerima kasih telah menggunakan kalkulator.");
    return;
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