#include <stdio.h>

using namespace std;

int answer_blue = 0;
int answer_white = 0;

void Divide(int **arr, int start_row, int start_col, int n){
    bool check = true;

    if(n == 1){
        if(arr[start_row][start_col] == 1)
            answer_blue++;
        else
            answer_white++; 
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[start_row][start_col] != arr[start_row + i][start_col + j])
                check = false;
        }
    }

    if(check){
        if(arr[start_row][start_col] == 1){
            answer_blue++;
            return;
        }
        else{
            answer_white++;
            return;
        }
    }
    else{
        Divide(arr, start_row, start_col, n/2);
        Divide(arr, start_row, start_col + n/2, n/2);
        Divide(arr, start_row + n/2, start_col, n/2);
        Divide(arr, start_row + n/2, start_col + n/2, n/2);
    }
}

int main() {
    int n;
    int **arr;

    scanf("%d", &n);

    arr = new int*[n];

    for(int i=0; i<n; i++){
        arr[i] = new int[n];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    Divide(arr, 0, 0, n);

    printf("%d\n%d", answer_white, answer_blue);

    for(int i=0; i<n; i++){
        delete []arr[i];
    }

    delete []arr;

    return 0;
}