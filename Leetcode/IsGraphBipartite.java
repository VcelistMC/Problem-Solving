import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * IsGraphBipartite
 */
public class IsGraphBipartite {

    public boolean isBipartite(int[][] graph) {
        int N = graph.length;
        int[] color = new int[N];
        
        
        for(int i = 0; i < N; i++) {
            if(color[i] == 0) {
                color[i] = 1;
                Queue<Integer> q = new LinkedList<>();
                q.add(i);
                while(!q.isEmpty()) {
                    int cur = q.poll();
                    for(int nb : graph[cur]) {
                        if(color[nb] == 0) {
                            color[nb] = color[cur] == 1 ? 2 : 1;
                            q.add(nb);
                        } else {
                            if(color[nb] == color[cur]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
}
