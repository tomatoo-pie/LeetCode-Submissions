import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mapp = {}

        for i in range(len(nums)):
            mapp[nums[i]] = mapp.get(nums[i],0) + 1
        
        heap = []

        for key,freq in mapp.items():
            t = (freq,key)
            if(len(heap) < k):
                heapq.heappush(heap,t)
            else:
                heapq.heappush(heap,t)
                heapq.heappop(heap)
                
        
        lst = []

        for i in heap:
            lst.append(i[1])

        return lst