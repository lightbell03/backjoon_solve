#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;

class ComputerNet{
private:
    vector<vector<int>> com_vec;
    bool *infected;
public:
    ComputerNet(int computer_num){
        infected = new bool[computer_num + 1];
        //컴퓨터는 1번부터 시작
        for(int i=0; i<computer_num + 1; i++){
            com_vec.push_back(vector<int>());
            infected[i] = false;
        }
    }

    void InsertComputer(int com_1, int com_2){
        com_vec[com_1].push_back(com_2);
        com_vec[com_2].push_back(com_1);
    }

    void InfectComputer_DFS(int val) {
        infected[val] = true;
        //1번 컴퓨터는 세지 않음
        if(val != 1)
            answer++;

        for(int i = 0; i<com_vec[val].size(); i++){
            if(infected[com_vec[val][i]] == false)
                InfectComputer_DFS(com_vec[val][i]);
        }
    }
    
    void InfectComputer_BFS(int val) {
        queue<int> q;

        q.push(val);

        while(!q.empty()){
            int tmp = q.front();

            if(infected[tmp] == false){
                infected[tmp] = true;
                
                if(tmp != 1)
                    answer++;

                for(int i=0; i<com_vec[tmp].size(); i++){
                    q.push(com_vec[tmp][i]);
                }
            }

            q.pop();
        }
    }
};

int main() {
    int computer_num, linked_computer_num;
    int com_1, com_2;

    scanf("%d", &computer_num);
    scanf("%d", &linked_computer_num);

    ComputerNet com(computer_num);

    for(int i=0; i<linked_computer_num; i++){
        scanf("%d %d", &com_1, &com_2);

        com.InsertComputer(com_1, com_2);
    }

    com.InfectComputer_BFS(1);
    printf("%d", answer);
}