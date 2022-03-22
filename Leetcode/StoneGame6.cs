public class Solution {
    public int StoneGameVII(int[] stones) {
        bool maxmizing = true;
        int currSum = stones.Sum();
        int aliceSum = 0;
        int bobSum = 0;
        //[5,3,1,4,2]
        while(stones.Count() != 0){
            int leftmostStone = 0;
            int rightmostStone = stones.Count() - 1;
            int indToRemove = 0;
            if(maxmizing)
            {
                maxmizing.
                int aliceSumWithLeftStoneRemd = aliceSum + (currSum - stones[leftmostStone]);
                int aliceSumWithRightStoneRemd = aliceSum + (currSum - stones[rightmostStone]);
                if(aliceSumWithRightStoneRemd > aliceSumWithLeftStoneRemd)
                {
                    aliceSum = aliceSumWithRightStoneRemd;
                    indToRemove = rightmostStone;
                }
                else
                {
                    aliceSum = aliceSumWithLeftStoneRemd;
                    indToRemove = leftmostStone;
                }
            }
            else
            {
                
            }
        }
    }
}