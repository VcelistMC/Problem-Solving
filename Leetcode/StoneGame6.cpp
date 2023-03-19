#include <iostream>
#include <numeric>

int sum(int arr[]){
    
}


int solve(int stones[]){
    bool maxmizing = true;
    int currSum = accumlate();
    int aliceSum = 0;
    int bobSum = 0;
    //[5,3,1,4,2]
    while(stones.Count() != 0){
        int leftmostStone = 0;
        int rightmostStone = stones.Count() - 1;
        int indToRemove = 0;
        if(maxmizing)
        {
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

int main(int argc, char const *argv[])
{

}
