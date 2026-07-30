n = (int)(input())
a = list(map(int, input().split()))
mx = -1
smx = 0
mxcnt = -1
smxcnt = 0
for x in a:
    if x > mx:
        smx = mx
        smxcnt = mxcnt
        mx = x
        mxcnt = 1
    elif x == mx:
        mxcnt += 1
    elif x > smx:
        smx = x
        smxcnt = 1
    elif x == smxcnt:
        smxcnt += 1
if mxcnt >= 2:
    print(mx)
else:
    print(smx)