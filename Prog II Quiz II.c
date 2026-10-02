/*
 * Ogrenci No : 250201041
 * Ad Soyad   : Daghan Ozdemir
 */

#include <stdio.h>

#define N 4

void matrisOku(int *ptr);
void matrisYazdir(const int *ptr);
void matrisAnaliz(int *ptr, int *altToplam, int *ustCarpim, int *kosegenToplam, int *disCerceveMax, double *genelOrtalama);

int main(void) {
    int mat[N][N];
    
    int altToplam = 0;
    int ustCarpim = 1;
    int kosegenToplam = 0;
    int disCerceveMax = 0;
    double genelOrtalama = 0.0;

    printf("4x4 Matrisi giriniz:\n");
    matrisOku((int *)mat);

    printf("\nGirilen Matris:\n");
    matrisYazdir((int *)mat);

    matrisAnaliz((int *)mat, &altToplam, &ustCarpim, &kosegenToplam, &disCerceveMax, &genelOrtalama);

    printf("\n--- Analiz Sonuclari ---\n");
    printf("1. Alt Ucgen Toplami: %d\n", altToplam);
    printf("2. Ust Ucgen Carpimi: %d\n", ustCarpim);
    printf("3. Ana Kosegen Toplami: %d\n", kosegenToplam);
    printf("4. Dis Cerceve En Buyuk Eleman: %d\n", disCerceveMax);
    printf("5. Matrisin Genel Ortalamasi: %.2f\n", genelOrtalama);

    return 0;
}

void matrisOku(int *ptr) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("matris[%d][%d] = ", i, j);
            scanf("%d", (ptr + (i * N + j)));
        }
    }
}

void matrisYazdir(const int *ptr) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", *(ptr + (i * N + j)));
            if (j < N - 1) {
                printf("\t| ");
            }
        }
        printf("\n\n");
    }
}

void matrisAnaliz(int *ptr, int *altToplam, int *ustCarpim, int *kosegenToplam, int *disCerceveMax, double *genelOrtalama) {
    int toplamEleman = N * N;
    int elemanlarToplami = 0;
    int carpimBasladi = 0;

    *altToplam = 0;
    *ustCarpim = 1;
    *kosegenToplam = 0;
    *disCerceveMax = *ptr;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int deger = *(ptr + (i * N + j));
            
            // Genel ortalama icin eleman toplami
            elemanlarToplami += deger;

            // 1. Alt Ucgen Toplami (i > j)
            if (i > j) {
                *altToplam += deger;
            }
            // 2. Ust Ucgen Carpimi (j > i ve deger != 0)
            else if (j > i) {
                if (deger != 0) {
                    *ustCarpim *= deger;
                    carpimBasladi = 1;
                }
            }
            // 3. Ana Kosegen Toplami (i == j)
            else {
                *kosegenToplam += deger;
            }

            // 4. Dis Cerceve Max (0. veya 3. satir/sutun)
            if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
                if (deger > *disCerceveMax) {
                    *disCerceveMax = deger;
                }
            }
        }
    }

    if (!carpimBasladi) {
        *ustCarpim = 0;
    }

    // 5. Genel Ortalama
    *genelOrtalama = (double)elemanlarToplami / toplamEleman;
}