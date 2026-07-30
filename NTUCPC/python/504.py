import math
pi = math.pi
a, b, c, d = map(int, input().split())
print((a + b * c) % d)
print("%6f" %round(a / b + c / d, 6))
print("%6f" %round(math.sin((a - b) * pi / 180) * math.cos((c - d) * pi / 180), 6))
print("%6f" %round(math.sqrt(abs(a * b - c * d)), 6))
print("%6f" %round(math.log10(a * b * c * d), 6))