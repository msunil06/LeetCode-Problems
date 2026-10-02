class Solution:
    def containsNearbyDuplicate(self, nums: list[int], k: int) -> bool:
        map = {}
        for i , val in enumerate(nums):
            if val in map and abs(i-map[val])<=k:
                return True
            map[val]=i
        return False
        