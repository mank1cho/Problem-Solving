//https://programmers.co.kr/learn/courses/30/lessons/49189?language=cpp

#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> v[n+1];   //인접리스트
    int dis[20001] = {0}; //노드 1에서부터 거리
    
    for(int i = 0; i<edge.size(); ++i){  //인접리스트 구현
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    //bfs
    queue<int> q;
    q.push(1);
    dis[1] = 1;
    int d = 0;
    while(!q.empty()){
        d++;
        int size = q.size();
        while(size--){
            int now = q.front();
            q.pop();
            for(int i = 0; i<v[now].size(); ++i){
                if(dis[v[now][i]]) continue;
                dis[v[now][i]] = d;
                q.push(v[now][i]);
            }
        }
    }
    
    for(int i = 1; i<=n; ++i){
        if(dis[i] == d-1) answer++;
    }
    
    return answer;
}