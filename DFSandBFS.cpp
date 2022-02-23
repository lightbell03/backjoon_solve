#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> dfs_answer;
vector<int> bfs_answer;

class Graph { 
private:
    int v;
    vector<int>* adj;
    bool* visited;
    queue<int> q;
public:
    Graph(int v){
        this->v = v;
        visited = new bool[v + 1];
        adj = new vector<int>[v + 1];
    }
    
    void init_visited(){
        for(int i=0; i<v + 1; i++)
            visited[i]= false;
    }

    void insert_edge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
        visited[v] = false;
    }

    void sort_list(){
        for(int i=0; i<v + 1; i++)
            sort(adj[i].begin(), adj[i].end());
    }

    void DFS_serch(int v){
        visited[v] = true;

        dfs_answer.push_back(v);

        for(int i=0; i<adj[v].size(); i++){
            if(!visited[adj[v][i]])
                DFS_serch(adj[v][i]);
        }
    }

    void BFS_serch(int v){
        q.push(v);
        visited[v] = true;
        bfs_answer.push_back(v);

        while(!q.empty()){
            int next = q.front();

            for(int i=0; i<adj[next].size(); i++){
                if(!visited[adj[next][i]]){
                    q.push(adj[next][i]);
                    visited[adj[next][i]] = true;
                    bfs_answer.push_back(adj[next][i]);
                }
            }
            q.pop();
        }
    }
};

int main() {
    int n, m, start_num;
    int v, w;

    scanf("%d %d %d", &n, &m, &start_num);

    Graph g(n);

    for(int i=0; i<m; i++){
        scanf("%d %d", &v, &w);
        g.insert_edge(v, w);
    }

    g.sort_list();

    g.DFS_serch(start_num);
    g.init_visited();
    g.BFS_serch(start_num);

    for(int i=0; i<dfs_answer.size(); i++){
        printf("%d ", dfs_answer[i]);
    }
    printf("\n");
    for(int i=0; i<bfs_answer.size(); i++){
        printf("%d ", bfs_answer[i]);
    }   
}