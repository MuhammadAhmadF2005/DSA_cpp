import sys
from functools import lru_cache
data=sys.stdin.read().split()
if not data:
    sys.exit(0)
it=0


N=int(data[it]);it+=1

##
## for i in range(0, n):
##  if
##


vals=[int(data[it+i]) for i in range(N)];it+=N
vals.sort(reverse=True)
M=int(data[it]);it+=1
turns=[]
for _ in range(M):
    eng=data[it];act=data[it+1];it+=2
    turns.append((eng,act))
s=vals[:M]
@lru_cache(None)
def solve(turn,l):
    if turn==M:
        return 0
    r = M-1 - (turn - l)
    if l>r:
        return 0
    eng,act=turns[turn]
    if act=="pick":
        val=s[l]
        return val + solve(turn+1,l+1) if eng=='A' else -val + solve(turn+1,l+1)
    else:
        opt1=solve(turn+1,l+1)
        opt2=solve(turn+1,l)
        return max(opt1,opt2) if eng=='A' else min(opt1,opt2)
ans=solve(0,0)
if ans>0:
    print("A",abs(ans))
else:
    print("B",abs(ans))
