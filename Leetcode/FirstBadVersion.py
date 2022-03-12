from pip import main


def isBadVersion(version):
    return version >= 2
class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        lo = 1
        hi = n
        while(lo <= hi):
            mid = int(lo + ((hi-lo) / 2))
            isBad = isBadVersion(mid)
            if(isBad):
                hi = mid-1
            else:
                lo = mid+1
        return lo

sol = Solution()
print(sol.firstBadVersion(3))