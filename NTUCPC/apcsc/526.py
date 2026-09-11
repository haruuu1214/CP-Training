a1, a2, a3, a4 = map(int, input().split())
b1, b2, b3, b4 = map(int, input().split())
a3 += a1
a4 += a2
b3 += b1
b4 += b2
if max(a1, b1) < min(a3, b3) and max(a2, b2) < min(a4, b4):
  print("Yes")
else:
  print("No")