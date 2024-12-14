#include <stdio.h>
//합병(병합) 정렬 - merge sort

void sort(int list[], int start, int center, int length){
    float len = length;
    int cpArr[length]; // 값을 넣은 새 list

    for (int i = 0, a1=0, a2 = 0; i < length; i++){
        if(a1 < len/2){
            if(a2 < length/2){
                if(list[start+a1] < list[center+a2]) { //divide된 idx값을 기준으로 큰지 작은지 확인
                    cpArr[i] = list[start+a1];
                    a1++;
                }
                else{
                    cpArr[i] = list[center+a2];
                    a2++;
                }
            }else{
                cpArr[i] = list[start+a1];
                a1++;
            }
        }else{
            cpArr[i] = list[center+a2];
            a2++;
        }
    }
    for (int i = 0; i < length; i++,start++)
        list[start] = cpArr[i]; //정렬후 다시 리스트에 집어넣기
    
}

void mergeSort(int list[], int start, int end){
    if(end - start >= 1){
        int center = (start + end) /2;
        mergeSort(list, start, center); //divide (재귀로 호출해도 length가 1보다 작거나 같으면 재귀가 끊기기 때문에 괜찮음)
        mergeSort(list, center+1, end); //divide
        sort(list, start, center+1, end-start+1); //divide된 값을 기준으로 sort시작(재귀로 인해 제일 큰건 마지막에 실행)
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int list[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    mergeSort(list,0,n-1);

     for (int i = 0; i < n; i++)
        printf("%d ",list[i]);
    return 0;
}