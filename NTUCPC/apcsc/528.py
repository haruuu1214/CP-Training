a, b, c = map(int, input().split())
a = min(a, 1)
b = min(b, 1)
cnt = 0
if a & b == c:
  print("AND")
  cnt += 1
if a | b == c:
  print("OR")
  cnt += 1
if a ^ b == c:
  print("XOR")
  cnt += 1
if cnt == 0:
  print("IMPOSSIBLE")