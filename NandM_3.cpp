#include <stdio.h>

using namespace std;

void BackTrack(int val, int n, int m, int *arr, int size) {
    arr[size++] = val;
    if(size != m){
        for(int i=1; i<n + 1; i++){
            BackTrack(i, n, m, arr, size);
        }
    }
    else {
        for(int i=0; i<m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
}

int main(){
    int n, m;
    int arr[8];

    scanf("%d %d", &n, &m);

    for(int i=1; i<n + 1; i++){
        BackTrack(i, n, m, arr, 0);
    }
}