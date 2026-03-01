#include <stdio.h>

void bubbleSort(int* arr, int l) {
    int left = 0;
    int right = l - 1;
    while (left < right) {
        int swaped = 0;
        for (int i = left; i < right; i ++) {
            if(arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swaped = 1;
            }
        }
        left ++;

        if(!swaped) break;

        for (int i = right; i >= left; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swaped = 1;
            }
        }

        right --;
    }
}

int main(){
    int arr[] = {2,9,8,7,6,5,5,4,3,2,0};
    bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
        printf("%d\t", arr[i]);
    }
    
}