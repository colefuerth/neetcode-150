import heapq
from typing import List

class Solution:
    def maxSlidingWindow(self, arr: List[int], k: int) -> List[int]:
        maxlist = []
        window = [[-x, i] for i, x in enumerate(arr[:k])]
        n = len(arr)
        heapq.heapify(window)
        maxlist.append(-window[0][0])
        for i in range(k, n):
            heapq.heappush(window, [-arr[i], i])
            while window[0][1] <= i - k:
                heapq.heappop(window)
            maxlist.append(-window[0][0])
        return maxlist