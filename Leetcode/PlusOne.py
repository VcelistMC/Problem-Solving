class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        carry = 1
        for currIndex in range(len(digits)-1, -1, -1):
            sum = digits[currIndex] + carry
            if sum < 10:
                digits[currIndex] = sum
                carry = 0
            else:
                newSum = sum % 10
                carry = sum // 10
                digits[currIndex] = newSum
            if(carry == 0):
                break
        
        if(carry != 0):
            digits.insert(0, carry)
        return digits


sol = Solution()
print(sol.plusOne([0]))
