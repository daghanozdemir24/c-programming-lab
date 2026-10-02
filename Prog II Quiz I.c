// ad soyad
// ogrenci numarasi

#include <stdio.h>

#define N 3

// Zorunlu Fonksiyon Prototipleri
void matrisOku(int matris[N][N], const char *matrisAdi);
void matrisYazdir(int matris[N][N]);
void satirToplamlariniBul(int matris[N][N], int satirToplamlari[N]);
int enBuyukSatirToplaminiBul(int satirToplamlari[N]);
int enBuyukElemaniBul(int matris[N][N]);
void transpozAl(int kaynak[N][N], int hedef[N][N]);
void matrisCarp(int A[N][N], int B[N][N], int sonuc[N][N]);

int main(void) {
    int A[N][N];
    int B[N][N];
    int satirToplamlariA[N];
    int maxSatirToplamiA;
    int maxElemanB;
    int transpozMatris[N][N];
    int carpimSonucu[N][N];

    // 1 & 2. A matrisini al ve yazdir
    matrisOku(A, "A");
    printf("\nA matrisi:\n");
    matrisYazdir(A);

    // 3 & 4. B matrisini al ve yazdir
    matrisOku(B, "B");
    printf("\nB matrisi:\n");
    matrisYazdir(B);

    // 5. A matrisinin satir toplamlarini hesapla ve yazdir
    satirToplamlariniBul(A, satirToplamlariA);
    printf("\nA matrisinin her satirinin toplami:\n");
    for (int i = 0; i < N; i++) {
        printf("%d. satir toplami = %d\n", i + 1, satirToplamlariA[i]);
    }

    // 6. A matrisinin en buyuk satir toplami
    maxSatirToplamiA = enBuyukSatirToplaminiBul(satirToplamlariA);
    printf("\nA matrisinin en buyuk satir toplami: %d\n", maxSatirToplamiA);

    // 7. B matrisinin en buyuk elemani
    maxElemanB = enBuyukElemaniBul(B);
    printf("B matrisinin en buyuk elemani: %d\n", maxElemanB);

    // 8, 9, 10, 11, 12. Karsilastirma ve Islemler
    if (maxSatirToplamiA > maxElemanB) {
        printf("\nDaha buyuk olan deger: A matrisinin en buyuk satir toplami (%d)\n", maxSatirToplamiA);
        printf("Transpozu alinan matris: A matrisi\n");
        
        transpozAl(A, transpozMatris);
        printf("\nA matrisinin transpozu:\n");
        matrisYazdir(transpozMatris);

        printf("\nCarpilan matrisler: A^T X B\n");
        matrisCarp(transpozMatris, B, carpimSonucu);
    } else {
        printf("\nDaha buyuk olan deger: B matrisinin en buyuk elemani (%d)\n", maxElemanB);
        printf("Transpozu alinan matris: B matrisi\n");
        
        transpozAl(B, transpozMatris);
        printf("\nB matrisinin transpozu:\n");
        matrisYazdir(transpozMatris);

        printf("\nCarpilan matrisler: B^T X A\n");
        matrisCarp(transpozMatris, A, carpimSonucu);
    }

    printf("\nCarpim sonucu olusan matris:\n");
    matrisYazdir(carpimSonucu);

    return 0;
}

// 1. Matris okuma fonksiyonu
void matrisOku(int matris[N][N], const char *matrisAdi) {
    printf("%s matrisini giriniz:\n", matrisAdi);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("matris[%d][%d] = ", i, j);
            scanf("%d", &matris[i][j]);
        }
    }
}

// 2. Matris yazdirma fonksiyonu
void matrisYazdir(int matris[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", matris[i][j]);
        }
        printf("\n");
    }
}

// 3. Satir toplamlarini bulma fonksiyonu
void satirToplamlariniBul(int matris[N][N], int satirToplamlari[N]) {
    for (int i = 0; i < N; i++) {
        satirToplamlari[i] = 0;
        for (int j = 0; j < N; j++) {
            satirToplamlari[i] += matris[i][j];
        }
    }
}

// 4. En buyuk satir toplamini bulma fonksiyonu
int enBuyukSatirToplaminiBul(int satirToplamlari[N]) {
    int enBuyuk = satirToplamlari[0];
    for (int i = 1; i < N; i++) {
        if (satirToplamlari[i] > enBuyuk) {
            enBuyuk = satirToplamlari[i];
        }
    }
    return enBuyuk;
}

// 5. En buyuk elemani bulma fonksiyonu
int enBuyukElemaniBul(int matris[N][N]) {
    int enBuyuk = matris[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matris[i][j] > enBuyuk) {
                enBuyuk = matris[i][j];
            }
        }
    }
    return enBuyuk;
}

// 6. Transpoz alma fonksiyonu
void transpozAl(int kaynak[N][N], int hedef[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            hedef[j][i] = kaynak[i][j];
        }
    }
}

// 7. Matris carpma fonksiyonu
void matrisCarp(int A[N][N], int B[N][N], int sonuc[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sonuc[i][j] = 0;
            for (int k = 0; k < N; k++) {
                sonuc[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}