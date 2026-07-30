x = (int)(input())
if x == 0:
  print(0)
while x > 0:
  print(x & 1, end = '')
  x //= 2