import java.util.*;

class Solution {
    public int solution(int n, int[][] edge) {
        int answer = 0;
        ArrayList<Integer>[] adj = new ArrayList[n+1];
        int[] dis = new int[n+1];
        
        for(int i = 1; i<n+1; ++i){
            adj[i] = new ArrayList<>();
        }
        
        for(int i = 0; i<edge.length; ++i){
            int a = edge[i][0];
            int b = edge[i][1];
            adj[a].add(b);
            adj[b].add(a);
        }
        
        Queue<Integer> q = new LinkedList<>();
        q.add(1);
        dis[1] = 1;
        int d = 0;
        while(!q.isEmpty()){
            int size = q.size();
            d++;
            while(size!=0){
                size--;
                int now = q.peek();
                q.poll();
                for(int i = 0; i<adj[now].size(); ++i){
                    int next = adj[now].get(i);
                    if(dis[next]!=0) continue;
                    dis[next] = d;
                    q.add(next);
                }
            }
        }
        
        for(int i = 1; i<n+1; ++i){
            if(dis[i] == d-1) answer++;
        }
        
        return answer;
    }
}