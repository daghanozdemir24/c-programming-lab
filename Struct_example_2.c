#include <stdio.h>
#include <string.h>

struct Ogrenci {
    char adSoyad[50];
    int ogrenciNo;
    int sinif;
    float ortalama;
};

int KayitEkle(char kayitDizisi[][200], int mevcutKayitSayisi, struct Ogrenci yeniOgr);

int main() {
    char kayitlar[100][200];
    int kayitSayisi = 0;
    struct Ogrenci yeniOgr;
    char secim;

    printf("--- Kocaeli Universitesi Ogrenci Kayit Sistemi ---\n");

    do {
        int basarili = 0;
        while (!basarili) {
            printf("\nOgrenci No Giriniz: ");
            scanf("%d", &yeniOgr.ogrenciNo);

            printf("Ogrenci ad-soyad Giriniz: ");
            scanf(" %[^\n]s", yeniOgr.adSoyad);

            printf("Sinif Giriniz: ");
            scanf("%d", &yeniOgr.sinif);

            printf("Ortalama Giriniz: ");
            scanf("%f", &yeniOgr.ortalama);

            // --- DETAYLI KONTROL VE UYARI KISMI ---
            int hataVar = 0;
            int yil = yeniOgr.ogrenciNo / 10000000;

            if (yil < 18 || yil > 24) {
                printf("-> HATA: Ogrenci no yili (2018-2024) gecersiz!\n");
                hataVar = 1;
            }

            if (strlen(yeniOgr.adSoyad) > 20) {
                printf("-> HATA: Ad-Soyad maksimum 20 karakter olmalidir!\n");
                hataVar = 1;
            }

            if (yeniOgr.sinif < 1 || yeniOgr.sinif > 4) {
                printf("-> HATA: Sinif 1 ile 4 arasinda olmalidir!\n");
                hataVar = 1;
            }

            if (yeniOgr.ortalama < 0.0 || yeniOgr.ortalama > 4.0) {
                printf("-> HATA: Ortalama 0.00 ile 4.00 arasinda olmalidir!\n");
                hataVar = 1;
            }

            if (hataVar == 0) {
                kayitSayisi = KayitEkle(kayitlar, kayitSayisi, yeniOgr);
                printf("Ogrenci basariyla kaydedildi!\n");
                basarili = 1;
            } else {
                printf("Ogrenci hatali girildi bilgileri tekrar giriniz!\n");
            }
        }

        printf("\nBaska ogrenci eklemek ister misiniz? (e/h): ");
        scanf(" %c", &secim);

    } while (secim == 'e' || secim == 'E');

    printf("\n%-15s %-20s %-7s %-10s\n", "OgrenciNo", "Ad-Soyad", "Sinif", "Ortalama");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < kayitSayisi; i++) {
        printf("%s\n", kayitlar[i]);
    }

    return 0;
}

int KayitEkle(char kayitDizisi[][200], int mevcutKayitSayisi, struct Ogrenci yeniOgr) {
    sprintf(kayitDizisi[mevcutKayitSayisi], "%d\t%-20s\t%d\t%.2f",
            yeniOgr.ogrenciNo, yeniOgr.adSoyad, yeniOgr.sinif, yeniOgr.ortalama);
    return mevcutKayitSayisi + 1;
}