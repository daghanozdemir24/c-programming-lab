// Ad Soyad: Daghan Ozdemir
// Ogrenci Numarasi: 250201041

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define M 1024
#define N 100

int main(void) {
    char logMessage[M];
    int numbers[N];
    int count = 0;

    // Diziyi bellek fonksiyonu ile sifirla
    memset(numbers, 0, sizeof(numbers));

    // Kullanicidan log metnini al
    if (fgets(logMessage, sizeof(logMessage), stdin) == NULL) {
        return 0;
    }

    // "Kritik" kelimesi kontrolu (Buyuk/kucuk harf duyarli)
    if (strstr(logMessage, "Kritik") == NULL) {
        printf("Tehlike bulunmadi.\n");
        return 0;
    }

    // Rakam disindaki karakterleri ayirip pozitif sayilari cekme
    int i = 0;
    while (logMessage[i] != '\0' && count < N) {
        if (isdigit((unsigned char)logMessage[i])) {
            numbers[count++] = atoi(&logMessage[i]);

            // Islenen sayinin tum basamaklarini atla
            while (isdigit((unsigned char)logMessage[i])) {
                i++;
            }
        } else {
            i++;
        }
    }

    // Buyukten kucuge siralama (Selection Sort)
    for (int j = 0; j < count - 1; j++) {
        for (int k = j + 1; k < count; k++) {
            if (numbers[j] < numbers[k]) {
                int temp = numbers[j];
                numbers[j] = numbers[k];
                numbers[k] = temp;
            }
        }
    }

    // Sonuclari ekrana yazdir
    printf("Kritik Durum Tespit Edildi! Degerler:");
    for (int j = 0; j < count; j++) {
        printf(" %d", numbers[j]);
    }
    printf("\n");

    return 0;
}