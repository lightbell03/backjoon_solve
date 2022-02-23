#include <iostream>
#include <string>
#include <stdio.h>
#include <stack>

using namespace std;

int main() {
    int n, val;
    stack<int> s;
    string command, arg_1, arg_2;

    scanf("%d", &n);
    cin.ignore();       //숫자형 변수는 '\n'을 담지 못하므로 입력버퍼에 남아있어
                        //getline에서 읽어들일 수 있으므로 cin.ignore()로 버퍼를 비워줌

    for(int i=0; i<n; i++){
        getline(cin, command);
        
        if(command.size() > 5){
            arg_1 = command.substr(0, 4);
            arg_2 = command.substr(5);
        }
        else
            arg_1 = command;
        
        if(arg_1 == "push"){
            s.push(stoi(arg_2));
        }
        else if(arg_1 == "pop"){
            if(s.empty())
                printf("-1\n");
            else{
                printf("%d\n", s.top());
                s.pop();
            }
        }
        else if(arg_1 == "size"){
            printf("%d\n", s.size());
        }
        else if(arg_1 == "empty"){
            s.empty() ? printf("1\n") : printf("0\n");
        }
        else if(arg_1 == "top"){
            if(s.empty()) printf("-1\n");
            else printf("%d\n", s.top());
        }
    }
}