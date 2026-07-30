a, b, c = map(int, input().split())
if a == 1:
  if b == 1:
    if c == 1 or c == 2:
      print(1)
    elif c == 3 or c == 4:
      print(2)
    else:
      print(3)
  else:
    print(4)
else:
  if b == 1:
    if c == 1 or c == 2:
      print(5)
    elif c == 3 or c == 4:
      print(6)
    else:
      print(7)
  else:
    print(8)