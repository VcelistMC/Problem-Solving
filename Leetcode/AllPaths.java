import java.util.ArrayList;
import java.util.List;

class AllPaths {
    public void dfs(int[][] graph, int node, int target, boolean[] visited, List<List<Integer>> paths, List<Integer> currPath) {
        if(visited[node])
            return;
        
        currPath.add(node);
        visited[node] = true;

        if(node == target){
            paths.add(new ArrayList<>(currPath));
            // return;
        }
        
        
        for(int neighbor: graph[node]){
            dfs(graph, neighbor, target, visited, paths, currPath);
        }
        visited[node] = false;
        currPath.remove(currPath.indexOf(node));
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int n = graph.length;
        boolean[] visited = new boolean[n];
        List<List<Integer>> paths = new ArrayList<List<Integer>>();
        List<Integer> currPath = new ArrayList<>();
        dfs(graph, 0, n-1, visited, paths, currPath);
        return paths;
    }

    public static void main(String[] args) {
        int[][] graph = {
            {1,2},
            {3},
            {3},
            {}
        };

        AllPaths paths = new AllPaths();
        System.out.println(paths.allPathsSourceTarget(graph));
    }
}