import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Set;

public class WaterAndJug {
    public boolean canMeasureWater(int j1, int j2, int t) {
        if(t > j1 + j2)
            return false;
        
        int[] possibleMoves = {j1, -j1, j2, -j2};
        Deque<Integer> q = new ArrayDeque<>();
        q.offer(0);
        Set<Integer> visited = new HashSet<>();
        visited.add(0);

        while (!q.isEmpty()) {
            int curr = q.poll();
            if(curr == t) return true;
            for(int move: possibleMoves){
                int pT = curr + move;
                if(pT < 0 || pT > j1 + j2) continue;
                if(!visited.contains(pT)){
                    visited.add(pT);
                    q.offer(pT);
                }
            }
        }
        return false;
    }
}
