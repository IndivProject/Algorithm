#include <stdio.h>
#include <stdlib.h>
#define ArrayLength 10

int mapArray[ArrayLength][ArrayLength] = {0, };
int roomCount = 0;
int currentRoomCount = 0;
int currentWidth = 0;
int currentHeight = 0;

void CreateRoom(int index){
    int isRoomCreated = rand()%2;
    if(isRoomCreated == 0) return;
    switch(index){
        case 0:
            if(mapArray[currentWidth][currentHeight-1] == 1) return; 
            mapArray[currentWidth][currentHeight-1] = 1;
            break;
        case 1:
            if(mapArray[currentWidth+1][currentHeight] == 1) return; 
            mapArray[currentWidth+1][currentHeight] = 1;
            break;
        case 2:
            if(mapArray[currentWidth][currentHeight+1] == 1) return; 
            mapArray[currentWidth][currentHeight+1] = 1;
            break;
        case 3:
            if(mapArray[currentWidth-1][currentHeight] == 1) return; 
            mapArray[currentWidth-1][currentHeight] = 1;
            break;
    }
    currentRoomCount--;
    roomCount--;
    return;
}

void CreateMap(){
    for (int i = 0; i < 4; i++)
    {
        CreateRoom(i);
    }
    if(currentRoomCount > 0) CreateMap();
    return;
}

void CreateStartRoom(){
    for (int i = 0; i < ArrayLength; i++)
    {
        for (int j = 0; j < ArrayLength; j++)
        {
            if(mapArray[i][j] == 1){ 
                mapArray[i-1][j] = 2;
                return;
            }
        }
    }
}

void CreateFinishRoom(){
    for (int i = 0; i < ArrayLength; i++)
    {
        for (int j = 0; j < ArrayLength; j++)
        {
            if(mapArray[i][j] == 1){ 
                currentWidth = i;
                currentHeight = j;
            }
        }
    }
    mapArray[currentWidth+1][currentHeight] = 3;
}

int main(){
    roomCount = rand()%2 + 5; //랜덤 값
    currentWidth = ArrayLength / 2;
    currentHeight = ArrayLength / 2;
    mapArray[currentWidth][currentHeight] = 1;
    while(roomCount > 0){
        currentRoomCount = 2;
        CreateMap();
        if(mapArray[currentWidth][currentHeight+1] == 1) 
            currentHeight = currentHeight + 1;
        else if(mapArray[currentWidth-1][currentHeight] == 1) 
            currentWidth = currentWidth - 1;
        else if(mapArray[currentWidth][currentHeight-1] == 1) 
            currentHeight = currentHeight - 1;
        else if(mapArray[currentWidth+1][currentHeight] == 1) 
            currentWidth = currentWidth + 1;
    }

    CreateStartRoom();
    CreateFinishRoom();

    for (int i = 0; i < ArrayLength; i++)
    {
        for (int j = 0; j < ArrayLength; j++)
        {
            printf("%d ", mapArray[i][j]);
        }
        printf("\n");
    }
    return 0;
}