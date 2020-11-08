//https://programmers.co.kr/learn/courses/30/lessons/42747?language=java

import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        
        Arrays.sort(citations);
        
        for(int i = 0; i<citations.length; ++i){
            if(citations.length -i <= citations[i]){
                return citations.length -i;
            }
        }
        
        return answer;
    }
}