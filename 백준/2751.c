#include <stdio.h>

// void sort(int *arr1, int *arr2, int len){
//     int cpArr[len];
//     for (int i = 0, a1=0, a2 = 0; i < len*2; i++)
//     {
//         if(a1 < len && arr1[a1] < arr2[a2]){
//             cpArr[i] = arr1[a1];
//             a1++;
//         }else{
//             if(a2 < len) cpArr[i] = arr2[a2];
//             else{
//                 cpArr[i] = arr1[a1];
//                 a1++;
//             }
//             a2++;
//         }
//     }

//      for (int i = 0; i < 6; i++){
//         printf("%d ",cpArr[i]);
//     }
// }   6, 5, 3, 1, 8, 7, 2, 4

void sort(int list[], int start, int center, int length){
    float len = length;
    int cpArr[length];
    // printf("\nlength : %.f\n",len/2);

    for (int i = 0, a1=0, a2 = 0; i < length; i++){
        if(a1 < len/2){
            if(a2 < length/2){
                if(list[start+a1] < list[center+a2]) {
                    cpArr[i] = list[start+a1];
                    // printf("1 %d / ",list[start+a1]);
                    a1++;
                }
                else{
                    cpArr[i] = list[center+a2];
                    // printf("2 %d / ",list[center+a2]);
                    a2++;
                }
            }else{
                cpArr[i] = list[start+a1];
                // printf("3 %d / ",list[start+a1]);
                a1++;
            }
        }else{
            cpArr[i] = list[center+a2];
            // printf("4 %d %d / ",list[center+a2], a2);
            a2++;
        }
    }
    
    // printf("\n");
    for (int i = 0, idx= start; i < length; i++,start++){
        // printf("%d ",cpArr[i]);
        list[start] = cpArr[i];
    }
    // printf("\n\n");
    
}

void mergeSort(int list[], int start, int end){
    if(end - start >= 1){
        int center = (start + end) /2;
        mergeSort(list, start, center);
        mergeSort(list, center+1, end);
        sort(list, start, center+1, end-start+1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int list[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    // printf("------\n");

    mergeSort(list,0,n-1);

     for (int i = 0; i < n; i++)
        printf("%d ",list[i]);
    return 0;
}