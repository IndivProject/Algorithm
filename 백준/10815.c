#include <stdio.h>

// void sort(int list[], int n){
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j <= i; j++){
//             if (list[i] < list[j]){
//                 list[i] ^= list[j];
//                 list[j] ^= list[i];
//                 list[i] ^= list[j];
//             }
//         }
//     }
// }

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


int search(int start, int mid, int end, int value, int list[]){
    // printf("%d %d %d %d\n\n",value, list[start], list[mid], list[end]);
    // printf("%d %d %d %d\n\n",value, start, mid, end);
    if(start == mid || end == mid) {
        return 0;
    }

    if(list[start] == value || list[end] == value || list[mid] == value) return 1;

    if(list[mid] > value){
        return search(start, (start+mid)/2,mid, value,list);
    }else{
        return search(mid,  (mid+end)/2, end,value,list);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int num[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&num[i]);
    mergeSort(num, 0, n-1); 


    int m,k;
    scanf("%d",&m);
    for (int i = 0; i < m; i++){ // m
        scanf("%d",&k);
        printf("%d\n",search(0,(n/2), n-1,k,num));
    }
    
    return 0;
}