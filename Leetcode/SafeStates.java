import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class SafeStates{
    private boolean dfs(int[][] graph, int node, HashMap<Integer, Boolean> safeMap) {
        if(safeMap.get(node) != null)
            return safeMap.get(node);

        safeMap.put(node, false);
        boolean isSafe = true;
        for(Integer sibling: graph[node]){
            isSafe = (dfs(graph, sibling, safeMap) && isSafe);
        }

        safeMap.replace(node, isSafe);
        return isSafe;
    }
    
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> res = new ArrayList<>();
        HashMap<Integer, Boolean> safeNodes = new HashMap<>();
        for(int i = 0; i < graph.length; i++){
            dfs(graph, i, safeNodes);
        }
        for(int i = 0; i < graph.length; i++){
            if(safeNodes.get(i))
                res.add(i);
        }
        return res;
    }

    public static void main(String[] args) {
        SafeStates states = new SafeStates();
        int[][] arr = new int[][]{
            new int[]{1,2},
            new int[]{2,3},
            new int[]{5},
            new int[]{0},
            new int[]{5},
            new int[]{},
            new int[]{}
        };
        states.eventualSafeNodes(arr);
    }
}