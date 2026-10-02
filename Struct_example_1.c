#include <stdio.h>
#include <stdlib.h>

struct date{
int day;
int month;
int year;

};


int main()
{
    struct date old;
    struct date now;

    char name[50];
    char key;

    do{


    printf("Name");
    scanf("%s",name);

    printf("Please enter a date of a birth");
    scanf("%d%d%d",&old.day,&old.month,&old.year);

    printf("Please enter a date of today");
    scanf("%d%d%d",&now.day,&now.month,&now.year);

    if(old.day>now.day){
        now.day+=30;
        now.month-=1;
    }
    if(old.month>now.month){
        now.month+=12;
        now.year-=1;
    }
    printf("%s is a %d day, %d month,%d year alive\n\n",name,now.day-old.day,now.month-old.month,now.year-old.year);

    printf("If you wanna resume the program, Press to 'x' key\n");
    scanf(" %c",&key);

}while(key=='x');


    return 0;
}
