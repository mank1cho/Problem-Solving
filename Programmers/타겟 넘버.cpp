//https://programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>

using namespace std;

void dfs(int cnt, int now, vector<int> &num, int target, int& answer){
    if(cnt == num.size()){
        if(now == target) answer++;
        return;
    }
    dfs(cnt+1, now+num[cnt], num, target, answer);
    dfs(cnt+1, now-num[cnt], num, target, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0,0,numbers,target,answer);
    return answer;
}