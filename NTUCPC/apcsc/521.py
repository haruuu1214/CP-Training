a, b, c = map(int, input().split())
if max(a, b, c) >= 90 and (a + b + c) / 3 >= 60 and min(a, b, c) >= 40:
  print('Y')
else:
  print('N')