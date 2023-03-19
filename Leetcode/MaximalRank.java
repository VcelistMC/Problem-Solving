import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class MaximalRank {
    public int maximalNetworkRank(int n, int[][] roads) {
        int rank = 0;
        List<Set<Integer>> edges = new ArrayList<>();
        int[] countEdges = new int[n];
        for(int i = 0; i < n; i++)
            edges.add(new HashSet<>());
        for(int[] road: roads){
            edges.get(road[0]).add(road[1]);
            countEdges[road[0]]++;
            edges.get(road[1]).add(road[0]);
            countEdges[road[1]]++;
        }

        for(int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++) {
                rank = Math.max(rank, countEdges[i] + countEdges[j] - ((edges.get(i).contains(j) && edges.get(j).contains(i)? 1: 0)));
            }
        }

        

        return rank;
    }
}