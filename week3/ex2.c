#include <stdio.h>
void bubble_sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n -1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return;
}
int main(){
    int arr[4] = {6, 2, 3, 5};
    bubble_sort(arr, 4);
    for(int i = 0; i < 4; i++)
        printf("%d ", arr[i]);
    return 0;
}