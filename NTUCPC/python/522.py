a, b, c, d = map(int, input().split())
if (a & c) != 0 or (b & d) != 0:
  print('MAKE')
else:
  print('KATSU')