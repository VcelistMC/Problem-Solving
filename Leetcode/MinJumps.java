import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class MinJumps {
    // enum JumpType {
    // FORWARD,
    // BACKWARD;
    // }
    // class Pair {
    // public Integer first;
    // public JumpType second;
    // Pair(Integer f, JumpType s){
    // this.first = f;
    // this.second = s;
    // }
    // @Override
    // public String toString() {
    // return first + ", " + second;
    // }
    // }

    public int minimumJumps(int[] forbidden, int a, int b, int x) {
        int jumps = 1;
        int currLocation = 0;
        int[] forwardMove, backwardMove;
        int upperBound = x + a + b;
        Queue<int[]> q = new LinkedList<>();
        HashSet<int[]> visited = new HashSet<>();
        for (Integer integer : forbidden) {
            visited.add(new int[] { integer, 1 });
            visited.add(new int[] { integer, -1 });
            upperBound = Math.max(upperBound, integer + a + b);
        }

        forwardMove = new int[] { currLocation + a, 1 };
        q.offer(forwardMove);
        

        while (!q.isEmpty()) {
            int l = q.size();
            for (int i = 0; i < l; i++) {
                int[] curr = q.poll();
                currLocation = curr[0];
                if (currLocation == x) {
                    return jumps + 1;
                }

                forwardMove = new int[] { currLocation + a, 1 };
                backwardMove = new int[] { currLocation - b, -1 };

                if (visited.add(forwardMove) && forwardMove[0] <= upperBound) {
                    q.offer(forwardMove);
                }
                if (curr[1] == 1 && visited.add(backwardMove) && backwardMove[0] >= 0) {
                    q.offer(backwardMove);
                }
            }
            jumps++;
        }
        return -1;
    }

    public static void main(String[] args) {
        MinJumps jumps = new MinJumps();
        HashSet<int[]> set = new HashSet<>();
        int forbidden[] = new int[] { 162, 118, 178, 152, 167, 100, 40, 74, 199, 186, 26, 73, 200, 127, 30, 124, 193,
                84, 184, 36, 103, 149, 153, 9, 54, 154, 133, 95, 45, 198, 79, 157, 64, 122, 59, 71, 48, 177, 82, 35, 14,
                176, 16, 108, 111, 6, 168, 31, 134, 164, 136, 72, 98 };
        int a = 29;
        int b = 98;
        int x = 80;
        System.out.println(jumps.minimumJumps(forbidden, a, b, x));

    }
}