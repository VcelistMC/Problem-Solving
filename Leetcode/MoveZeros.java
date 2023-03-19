import java.util.ArrayList;

public class MoveZeros {
    public static void moveZeroes(int[] nums) {
        int j = 0;
        int i = 0;
        for(i = 0; i < nums.length; i++){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
            }
        }
        for(; j < i; j++){
            nums[j] = 0;
        }
    }
    public static void main(String[] args) {
        int nums[] = {0,0,0,0};
        moveZeroes(nums);
        for(Integer i: nums)
            System.out.print(i + " ");
    }
}
