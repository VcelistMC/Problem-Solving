import java.util.ArrayList;

public class SquareSortedArray {
    public static int[] solve(int[] arr){
        ArrayList<Integer> sol = new ArrayList<>();
        for(int i = 0; i < arr.length; i++){
            int num = (int) Math.pow(arr[i], 2);
            if(sol.isEmpty()){
                sol.add(num);
                continue;
            }
            sol.add(0);
            int j;
            for(j = i-1; j >= 0 && num < sol.get(j); j--){
                sol.set(j+1, sol.get(j));
            }
            sol.set(j+1, num);
        }


        return sol.stream().mapToInt(i -> i).toArray();
    }

    public static void main(String[] args) {

    }
}


// 1 2 4 5 6 0
// num = 3
// i = 5
// j = 5