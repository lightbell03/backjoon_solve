#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void BackTrack(int val, int n, int m, vector<int> v){
    for(int i=0; i<v.size(); i++){
        if(v[i] == val)
            return;        
    }
    v.push_back(val);

    if(v.size() == m) {
        for(int i=0; i<v.size(); i++){
            printf("%d ", v[i]);
        }
        printf("\n");
        v.clear();
        return;
    }
    else{
        for(int i=1; i<n + 1; i++){
            BackTrack(i, n, m, v);
        }
    }
}

int main(){
    int n, m;
    vector<int> v;

    scanf("%d %d", &n, &m);

    for(int i=1; i<n + 1; i++){
        BackTrack(i, n, m, v);
    }
}