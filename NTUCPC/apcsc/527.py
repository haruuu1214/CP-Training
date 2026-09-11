a, b, c = map(int, input().split())
if a > b:
  a, b = b, a
if b > c:
  b, c = c, b
if a > b:
  a, b = b, a
if a + b <= c:
  print("Oh! No!")
elif a * a + b * b < c * c:
  print("Obtuse")
elif a * a + b * b == c * c:
  print("Right")
else:
  print("Acute")