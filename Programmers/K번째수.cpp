//https://programmers.co.kr/learn/courses/30/lessons/42748?language=cpp

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int csize = commands.size();
    for(int i=0; i<csize; i++){
        vector<int> s;
        for(int j=commands[i][0]-1; j<commands[i][1]; j++){
            s.push_back(array[j]);
        }
        sort(s.begin(), s.end());
        answer.push_back(s[commands[i][2]-1]);
    }
    return answer;
}