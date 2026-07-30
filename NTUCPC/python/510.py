x = (int)(input())
print(x // 3600)
print((x - x // 3600 * 3600) // 60)
print(x % 60)