//https://programmers.co.kr/learn/courses/30/lessons/43165

class Solution {
    public int solution(int[] numbers, int target) {
        int answer = 0;
        answer = dfs(0,0,numbers,target);
        return answer;
    }
    
    public int dfs(int cnt, int now, int[] numbers, int target){
        if(cnt == numbers.length){
            if(now == target) return 1;
            return 0;
        }
        return dfs(cnt+1, now+numbers[cnt], numbers, target) + dfs(cnt+1, now-numbers[cnt], numbers, target);
    }
}