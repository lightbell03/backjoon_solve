#include <stdio.h>
#include <iostream>

using namespace std;

int arr[2000000];

class Queue {
private:
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    void Push(int val){
        arr[rear++] = val;
    }

    bool Empty(){
        if(front == rear)
            return true;
        else 
            return false;
    }

    int Pop(){
        if(this->Empty())
            return -1;

        return arr[front++];
    }

    int Front(){
        if(this->Empty())
            return -1;
        return arr[front];
    }

    int Back(){
        if(this->Empty()){
            return -1;
        }
        return arr[rear - 1];
    }

    int Size(){
        if(this->Empty())
            return 0;
        return rear - front;
    }
};

int main() {
    int n, input_val;
    char str[10];
    Queue q;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", str);
        
        if(str[0] == 'p'){
            if(str[1] == 'u'){
                scanf("%d", &input_val);
                q.Push(input_val);
            }
            else{
                printf("%d\n", q.Pop());
            }
        }
        else if(str[0] == 'e'){
            if(q.Empty()){
                printf("1\n");
            }
            else printf("0\n");
        }
        else if(str[0] == 's'){
            printf("%d\n", q.Size());
        }
        else if(str[0] == 'f'){
            printf("%d\n", q.Front());
        }
        else if(str[0] == 'b'){
            printf("%d\n", q.Back());
        }
    }
}