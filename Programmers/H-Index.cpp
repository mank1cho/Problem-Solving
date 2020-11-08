//https://programmers.co.kr/learn/courses/30/lessons/42747?language=cpp

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());

    for(int i = 0; i<citations.size(); ++i){
        if(citations.size()-i <= citations[i]) return citations.size()-i;
    }
    
    return answer;
}