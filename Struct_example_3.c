#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N=20;

struct AdayInfo{
char name[100];
char surname[100];
int age;
int note;
float OBP;

};

struct MulakatInfo{
char interwiewer[100];
int interwiewDate;
struct AdayInfo aday;
int interwiewNote;
int day;
int month;
int year;


};

void MainMenu();

int main(){

    srand(time(NULL));

        struct MulakatInfo x[30];
        struct MulakatInfo temp;



    char* namePool[]={"Kenan","Daghan","Kerem","Cristiano","Neymar","Lionel","Demba","Thomas"};
    char* surnamePool[]={"Yildiz","Ozdemir","Akturkoglu","Ronaldo","Jr","MESSI","Ba","Muller"};
    char* interwiewerPool[]={"Gareth Bale","Iker Casillas","Zlatan Ibrahimovic","Paolo Maldini","Ricardo Quaresma","Robert Lewandowski","Luka Modric","Luiz Suarez"};


    printf("%11s %13s %7s %9s %8s %13s %19s %11s\n", "ISIM|", "SOYISIM|", "  YAS|", "  PUANI|", "OBP|", "TARIH|", "    MULAKATCI|", "      MULAKAT NOTU|");
    printf("------------------------------------------------------------------------------------------------------\n");

    for(int i=0;i<N;i++){


    int random1= rand()%8;
    int random2= rand()%8;
    int random3= rand()%8;


   // struct MulakatInfo x[30];

    sprintf(x[i].interwiewer,"%s",interwiewerPool[random3]);
    sprintf(x[i].aday.name,"%s",namePool[random1]);
    sprintf(x[i].aday.surname,"%s",surnamePool[random2]);

    x[i].aday.age=20+rand()%15;
    x[i].aday.OBP = ((float)rand() / RAND_MAX) * 4.0;
    x[i].aday.note=rand()%101;
    x[i].interwiewNote=rand()%101;

    x[i].day= 1 + rand()%28;
    x[i].month= 1 + rand()%12;
    x[i].year= 2020 + rand()%7;

    }

//    struct MulakatInfo temp;

    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-i-1;j++){

        int degistir=0;

        if(x[j].year>x[j+1].year)
	{
            degistir=1;
        }
	else if(x[j].year==x[j+1].year)
	{
                if(x[j].month>x[j+1].month)
		{
                degistir=1;
                }
			else if(x[j].month==x[j+1].month)
			{
                    		if(x[j].day>x[j+1].day)
				{
                    		degistir=1;
                    		}
                	}	
        	}
		
                if (degistir) 
		{
                temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;
		}

        }
    }
    for(int k=0;k<N;k++){
        MainMenu(x[k],k);
        }




    return 0;
}

void MainMenu(struct MulakatInfo x, int i){

//printf("%11s %13s %7s %9s %8s %13s %19s %11s\n", "ISIM|", "SOYISIM|", "  YAS|", "  PUANI|", "OBP|", "TARIH|", "    MULAKATCI|", "      MULAKAT NOTU|");
  //  printf("------------------------------------------------------------------------------------------------------\n");

    // Veriler
    // %-10s gibi ifadeler sola yaslı ve düzgün kolonlar olusturur
    // %.2f virgülden sonra 2 basamak gösterir
    printf("%d %11s %13s %5d %7d %11.2f   %3d.%02d.%-6d  %18s  %10d",i+1 , x.aday.name, x.aday.surname, x.aday.age, x.aday.note, x.aday.OBP, x.day, x.month, x.year, x.interwiewer, x.interwiewNote);
    if(x.interwiewNote<=75){
        printf("     --FAIL--\n");
    }else{
        printf("     --PASS--\n");
    }

}