public class SearchInsertPosition {
    public static int searchInsert(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        int mid = low + ((high - low) / 2);
        while (low < high) {
            if(target == nums[mid]){
                return mid;
            }
            else if(target < nums[mid]){
                high = mid-1;
                mid = low + ((high - low) / 2);
            }
            else{
                low = mid+1;
                mid = low + ((high - low) / 2);
            }
        }
        if(target <= nums[low])
            return low;
        else
            return low+1;
    }
    public static void main(String[] args) {
        int[] nums = {1,3};
        int target = 0;
        System.out.println(searchInsert(nums, target));
    }
}
