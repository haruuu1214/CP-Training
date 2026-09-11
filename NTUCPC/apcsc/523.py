a, b, c, d = map(int, input().split())
if ((a > 2 * c and max(a, b) >= d) or (b > c and max(a, b) >= d)):
  print("KATSU")
else:
  print("MAKE")