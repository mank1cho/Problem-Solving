//https://programmers.co.kr/learn/courses/30/lessons/42746?language=java

import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        ArrayList<String> alist = new ArrayList<>();
        for(int i = 0; i<numbers.length; ++i){
            alist.add(Integer.toString(numbers[i]));
        }
        Collections.sort(alist, new cmp());
        for(int i = 0; i<alist.size(); ++i){
            answer+=alist.get(i);
        }
        if(answer.charAt(0) == '0') return "0";
        return answer;
    }
}

class cmp implements Comparator<String>{
    @Override
    public int compare(String a, String b){
        String x = a+b;
        String y = b+a;
        return y.compareTo(x);
    }
}