public class Mnotonic_arr {
    public static boolean isMonotonic(int[] nums) {
        // 1 if increasing, 0 if not
        Boolean isIncreasing = null;
        int currNum = nums[0];
        int prevNum = nums[0];
        for(int i = 1; i < nums.length; i++){
            currNum = nums[i];
            if(currNum == prevNum)
                continue;
            if(isIncreasing == null)
                isIncreasing = (currNum > prevNum)? true: false;
            else{
                if(isIncreasing != (currNum > prevNum))
                    return false;
            }
            prevNum = currNum;
        }
        return true;
    }
}