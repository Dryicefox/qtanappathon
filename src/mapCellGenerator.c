//Darrel
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef enum RESOURCES {
    WOOD = 1,
    SHEEP = 2,
    BRICK = 3,
    ROCK = 4,
    WHEAT = 5,};
int main (void){
    struct mapCell{
        int xcoord;
        int ycoord;
        int resourceValue;
        bool isPortCell;
        bool isCoastCell;
    };
    FILE *f1=fopen("mapCells.txt","r");
    FILE *f2=fopen("coastCells.txt","r");
    int i=0;
    struct mapCell *ptr;
    int newlines=0;
    char parser;
    char charx[10],chary[10];
    while (fscanf(f1,"%c",&parser)!=EOF){
        if (parser=='\n')
            newlines++;
    }
    struct mapCell mapCells[newlines];
    rewind(f1);
    while (fscanf(f1,"%3[^,],%s\n",charx,chary)!=EOF){
        i++;
        mapCells[i].xcoord=atoi(charx);
        mapCells[i].ycoord=atoi(chary);
    }
    i=0;
    int j=0;
    while (fscanf(f2,"%3[^,],%s\n",charx,chary)!=EOF){
        for (;i!=sizeof(mapCells);i++){
            if (atoi(charx)==mapCells[i].xcoord&&atoi(chary)==mapCells[i].ycoord){
                mapCells[i].isCoastCell=true;
                j++;
                break;
            }
        }
    }
    struct mapCell coastCells[j];
    i=0;
    for (j=0;i!=sizeof(coastCells);j++)
        if (mapCells[j].isCoastCell==true)
            coastCells[i]=mapCells[j];


    printf("youre good");
    return 0;
}
