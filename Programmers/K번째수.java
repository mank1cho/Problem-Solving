//https://programmers.co.kr/learn/courses/30/lessons/42748?language=java

import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i = 0; i<commands.length; ++i){
            int a = commands[i][0];
            int b = commands[i][1];
            int c = commands[i][2];
            
            ArrayList<Integer> tmp = new ArrayList<>();
            for(int j = a-1; j<b; ++j){
                tmp.add(array[j]);
            }
            Collections.sort(tmp);
            answer[i] = tmp.get(c-1);
        }
        return answer;
    }
}