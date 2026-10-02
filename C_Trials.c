#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sayac(char* );
int i=0, j=0;
int kelimeara(char* ,char*);

struct GodRule{

char isim[50];
char soyisim[50];
int sinif;
int ogrNo;
float sinavNotu;

};


int main()/*
{
    int sonuc;
    char anacumle[100];
    char aranan[20];

    fgets(anacumle,sizeof(anacumle),stdin);

    fgets(aranan,sizeof(aranan),stdin);

    sayac(aranan);



    sonuc=kelimeara(anacumle, aranan);
    if(sonuc == 1){
        printf("Aranan kelime cumlede vardir.");
    }else{
    printf("Aranan kelime cumlenin icinde yoktur.");
    }

    return 0;
}


int sayac(char* sayilacak){

int i=0;

for(;sayilacak[i]!='\0';i++)
{

}

return i;
}



int kelimeara(char* anacumle,char* aranan){
int aranum=sayac(aranan);
int ananum=sayac(anacumle);


    for(i=0;i<ananum-aranum;i++)
    {
        for(j=0;j<aranum;j++){

            if(anacumle[i+j] != aranan[j]){
                break;
            }
            else{
                return 1;
            }
        }

    }
    return 0;

}


*/


/*
{
    char bellek[25];

    printf("%02d/%02d/%d\n", 5, 4, 2024);


    printf("%-10s - %5d TL\n", "Elma", 25);

    printf("\n\n");

    sprintf(bellek, "Sýcaklýk: %d derece", 25);
    printf("%s\n ",bellek);

int a = 50;
float b = 99.9558;
char c[] = "deneme";
printf("%10d\n", a);
printf("%10f\n", b);
printf("%10s\n", c);



int x = 50;
int y = 150;
printf("%06d\n", x);
printf("%06d\n", y);

float t = 99.95580;
// virgulden sonraki basamak sayisi
printf("%.4f\n", t);
printf("%.2f\n", t);
printf("%10.3f\n\n", t);

printf("------------\n\n");

char p[] = "deneme";
printf("0:%s:\n", p); // Normal
printf("1:%10s:\n", p); // 10 karakterlik alan saga dayali
printf("2:%.3s:\n", p); // ilk 3 karakter
printf("3:%-10s:\n", p); // 10 karakterlik alan sola dayali
printf("4:%10.3s:\n", p); // 10 karakterlik alan ilk 3 karakter
printf("5:%.3s:\n", p+2); // [2,5] arasi karakteri yazdir


printf("\n\n-----------\n\n");

int i = 50;
float j = 99.9558;
1printf("/************ stringe yazdirma ****************\n");
char s1[30];
sprintf(s1, "sprintf ornek. %d %.2f", i, j);
printf("%s\n", s1);



printf("/************ string'den okuma ****************\n");
char s2[] = "aaa 10 7.5";
printf("s2: %s\n", s2);
char x1[20];
int y1;
float z1;
sscanf(s2, "%s %d %f", x1, &y1, &z1);
printf("x: %s\n", x1);
printf("y: %d\n", y1);
printf("z: %f\n", z1);
}
*/

{
    struct GodRule x;

    printf("Lutfen ogrencinin isim soyisim ogrenci no'sunu sinifini ve sinav notunu girirniz...");

    scanf("%s %s %d %d %f",&x.isim,&x.soyisim,&x.ogrNo,&x.sinif,&x.sinavNotu);

    printf("Isim : %s\n",x.isim);

    printf("Soyisim : %s\n",x.soyisim);

    printf("Ogrenci No : %d\n",x.ogrNo);

    printf("Sinifi : %d. Sinif \n",x.sinif);

    printf("Sinav Notu : %f\n",x.sinavNotu);




}
