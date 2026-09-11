import math
n = (int)(input())
suc = True
sq = (int)(math.floor(math.sqrt(n)))
for i in range(2, sq + 1):
  if n % i == 0:
    suc = False
    break
if n != 1 and suc == True:
  print("Yes")
else:
  print("No")