d, n = map(int, input().split())
oven = list(map(int, input().split()))
doughs = list(map(int, input().split()))
 
for i in range(1, len(oven)):
    if oven[i] > oven[i-1]:
        oven[i] = oven[i-1]
 
 
piled_loc = 0
lp, rp = 0, len(oven)-1
for dough in doughs:
    is_piled = False
 
    while lp <= rp:
        mid = (lp+rp) // 2
        diameter = oven[mid]
        if diameter >= dough:
            lp = mid + 1
            piled_loc = mid
            is_piled = True
        else:
            rp = mid - 1
 
    if not is_piled:
        piled_loc = -1
        break
 
    lp = 0
    rp = piled_loc - 1
 
 
if piled_loc == -1:
    print(0)
else:
    print(piled_loc+1)
