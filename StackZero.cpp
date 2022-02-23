#include <stdio.h>

using namespace std;

int main() {
    int k, arr[100000], check = 0;
    int sum = 0;

    scanf("%d", &k);

    for(int i=0; i<k; i++){
        scanf("%d", &arr[i]); 
    }

    for(int i = k - 1; i>=0; i--){
        if(arr[i] == 0)
            check++;
        else if(check == 0){
            sum += arr[i];
        }
        else if(arr[i] != 0){
            if(check >= 0)
                check--;
        }
    }

    printf("%d", sum);
}