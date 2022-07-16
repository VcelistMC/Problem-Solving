public class DailyTemp {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] daysArr = new int[n];
        for (int tmp = 0; tmp < n; tmp++) {
            int days = 1, nextTmp = tmp + 1;
            while(nextTmp < n){
                if(temperatures[nextTmp] <= temperatures[tmp]){
                    days++;
                    nextTmp++;
                    if(nextTmp >= n){
                        days = 0;
                        break;
                    }
                }
                else{
                    break;
                }
                
            }
            daysArr[tmp] = nextTmp < n? days: 0;
        }
        return daysArr;
    }

    static void printArr(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    public static void main(String[] args) {
        DailyTemp sol = new DailyTemp();
        DailyTemp.printArr(sol.dailyTemperatures(new int[] { 73, 74, 75, 71, 69, 72, 76, 73 }));

    }
}