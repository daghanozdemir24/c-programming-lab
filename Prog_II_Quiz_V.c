#include <stdio.h>
#include <string.h>

#define MAX_ARAC 20
#define D 4
#define LIMIT 1500.0f

// Adım 1: AracVerisi struct yapısı
typedef struct {
    char plaka[16];           // 15 karakter + null karakteri
    char soforad[31];         // 30 karakter + null karakteri
    float donemlikYakit[D];
} AracVerisi;

// Adım 2: Dinamik veri girişi
int veriGirisYap(AracVerisi filolar[]) {
    int sayi = 0;
    
    printf("Kac adet arac girilecek?: ");
    if (scanf("%d", &sayi) != 1) return 0;

    if (sayi > MAX_ARAC) {
        printf("Kapasite asildi! Maksimum %d arac girilebilir.\n", MAX_ARAC);
        sayi = MAX_ARAC;
    }

    for (int i = 0; i < sayi; i++) {
        printf("\n--- %d. Arac Bilgileri ---\n", i + 1);
        
        printf("Plaka giriniz : ");
        scanf("%15s", filolar[i].plaka);

        // Satır sonu karakterini temizle
        while (getchar() != '\n');

        printf("Sofor Adi Soyadi giriniz : ");
        fgets(filolar[i].soforad, sizeof(filolar[i].soforad), stdin);
        filolar[i].soforad[strcspn(filolar[i].soforad, "\n")] = '\0';

        printf("4 Donemlik Yakit Tuketimi (Litre):\n");
        for (int j = 0; j < D; j++) {
            printf("%d. Donem: ", j + 1);
            scanf("%f", &filolar[i].donemlikYakit[j]);
        }
    }

    return sayi;
}

// Adım 3: Tek bir aracın yıllık maliyeti
void maliyetHesapla(AracVerisi arac, float litreFiyati) {
    float toplamTuketim = 0.0f;
    for (int i = 0; i < D; i++) {
        toplamTuketim += arac.donemlikYakit[i];
    }

    float yillikMaliyet = toplamTuketim * litreFiyati;

    printf("Plaka: %-10s | Sofor: %-12s | Yillik Maliyet: %.2f TL | Toplam Tuketim: %.2f Litre\n",
           arac.plaka, arac.soforad, yillikMaliyet, toplamTuketim);
}

// Adım 4: Limit aşım raporu
void limitAsimRaporu(AracVerisi filolar[], int aracSayisi) {
    printf("\n--- LIMIT ASIM RAPORU ---\n");
    for (int i = 0; i < aracSayisi; i++) {
        float toplamTuketim = 0.0f;
        float maxTuketim = filolar[i].donemlikYakit[0];

        for (int j = 0; j < D; j++) {
            toplamTuketim += filolar[i].donemlikYakit[j];
            if (filolar[i].donemlikYakit[j] > maxTuketim) {
                maxTuketim = filolar[i].donemlikYakit[j];
            }
        }

        if (toplamTuketim > LIMIT) {
            printf("Uyari! %s (Sofor: %s) limiti asti.\n", filolar[i].plaka, filolar[i].soforad);
            printf("En yuksek tuketim su donemlerde goruldu: ");
            for (int j = 0; j < D; j++) {
                if (filolar[i].donemlikYakit[j] == maxTuketim) {
                    printf("%d. Donem ", j + 1);
                }
            }
            printf("(%.2f Litre)\n", maxTuketim);
        }
    }
}

// Adım 5: Şoför adına göre arama
void aracAra(AracVerisi filolar[], int aracSayisi) {
    int secim = 0;
    char arananSofor[31];

    while (1) {
        printf("\n--- ARAC ARAMA MENUSU ---\n");
        printf("1- Sofor adina gore ara\n");
        printf("2- Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if (secim == 2) {
            printf("\nArama menusunden cikiliyor. Iyi gunler!\n");
            break;
        } else if (secim == 1) {
            while (getchar() != '\n');

            printf("Aranan Sofor Adini giriniz: ");
            fgets(arananSofor, sizeof(arananSofor), stdin);
            arananSofor[strcspn(arananSofor, "\n")] = '\0';

            int bulundu = 0;
            for (int i = 0; i < aracSayisi; i++) {
                if (strcmp(filolar[i].soforad, arananSofor) == 0) {
                    bulundu = 1;
                    printf("\nBulunan Kayit -> Plaka: %s | Sofor: %s\n", filolar[i].plaka, filolar[i].soforad);
                    printf("Donemlik Yakit Listesi: ");
                    for (int j = 0; j < D; j++) {
                        printf("%d.D(%.2f)%s", j + 1, filolar[i].donemlikYakit[j], (j == D - 1) ? "\n" : " | ");
                    }
                }
            }

            if (!bulundu) {
                printf("Kayit bulunamadi.\n");
            }
        } else {
            printf("Gecersiz secim! Lutfen 1 veya 2 giriniz.\n");
        }
    }
}

int main() {
    AracVerisi filo[MAX_ARAC];
    int aracSayisi = veriGirisYap(filo);

    if (aracSayisi <= 0) {
        return 0;
    }

    float litreFiyati = 0.0f;
    printf("\nLutfen guncel yakit litre fiyatini giriniz (TL): ");
    scanf("%f", &litreFiyati);

    // Yıllık Maliyet Raporu
    printf("\n--- YILLIK MALIYET RAPORU ---\n");
    for (int i = 0; i < aracSayisi; i++) {
        maliyetHesapla(filo[i], litreFiyati);
    }

    // Limit Aşım Raporu
    limitAsimRaporu(filo, aracSayisi);

    // Araç Arama Menüsü
    aracAra(filo, aracSayisi);

    return 0;
}