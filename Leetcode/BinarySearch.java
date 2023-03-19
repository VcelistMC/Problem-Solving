public class BinarySearch{
    public static int search(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        int mid = low + ((high - low) / 2);
        while (low <= high) {
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
        return -1;
    }
    public static void main(String[] args) {
        int[] nums = {5};
        int target = 5;
        System.out.println(search(nums, target));
    }
}