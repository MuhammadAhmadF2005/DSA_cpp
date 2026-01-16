class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        hFences.sort()
        vFences.sort()
        
        h_size=set()
        hFences=[1]+hFences+[m]
        vFences=[1]+vFences+[n]
        
        for i in range(1,len(hFences)):
            for j in range(i):
                h_size.add(hFences[i]-hFences[j])
        
        max_length=-1
        
        for i in range(1,len(vFences)):
            for j in range(i):
                if vFences[i]-vFences[j] in h_size:
                    max_length=max(max_length,vFences[i]-vFences[j])
        
        return max_length if max_length==-1 else max_length**2 % (10**9 +7)