a, b, c = map(int, input().split())
res = (a + b + c) / 3
if 90 <= res:
  print("A+")
elif 85 <= res:
  print("A")
elif 80 <= res:
  print("A-")
elif 77 <= res:
  print("B+")
elif 73 <= res:
  print("B")
elif 70 <= res:
  print("B-")
else:
  print("F")