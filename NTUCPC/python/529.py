x = (int)(input())
while x != 1:
  print(x, "-> ", end = '')
  if x % 2 == 1:
    x = 3 * x + 1
  else:
    x //= 2
print(1, "->", "end")