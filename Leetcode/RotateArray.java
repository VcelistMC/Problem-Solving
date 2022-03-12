import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class RotateArray {
    public void rotate(int[] nums, int k) {
        Queue<Integer> queue = new LinkedList<Integer>();
        for(int i = nums.length-1; i >= 0; i--)
            queue.add(nums[i]);
        
        while(k != 0){
            int num = queue.poll();
            queue.add(num);
            k--;
        }
        for(int i = nums.length-1; i >= 0; i--)
            nums[i] = queue.poll();
    }
    public static void main(String[] args) {
        RotateArray rotateArray = new RotateArray();
        rotateArray.rotate(new int[]{1,2,3,4,5,6,7}, 3);
    }
}
