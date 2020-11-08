//https://programmers.co.kr/learn/courses/30/lessons/42746?language=cpp

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i = 0; i<numbers.size(); ++i){
        v.push_back(to_string(numbers[i]));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 0; i<v.size(); ++i){
        answer+=v[i];
    }
    
    if(answer[0]=='0') return "0";
    
    return answer;
}