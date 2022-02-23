#include <stdio.h>

using namespace std;

bool solve(char *str){
    int cnt = 0;
    for(int i=0; str[i] != '\0'; i++) {
        //')' 이 문자가 먼저 나오는 경우
        if(cnt < 0)
            return false;

        if(str[i] == '(') cnt++;
        else cnt--;
    }

    if(cnt != 0) return false;
    else return true;
}

int main() {
    int t;
    char str[50];

    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf("%s", str);

        if(solve(str))
            printf("YES\n");
        else
            printf("NO\n");
    }
}