t = (int)(input())
for tt in range(t):
  n = (int)(input())
  if (n * (n + 1) / 2) % 2 == 1:
    print("Bob")
  else:
    print("Alice")