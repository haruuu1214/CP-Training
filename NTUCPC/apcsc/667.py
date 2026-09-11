t = (int)(input())

fir = -1
lst = -1
llink = []
rlink = []
for i in range(100001):
  llink.append(0)
  rlink.append(0)
for tt in range(t):
  arr = list(map(int, input().split()))
  op = arr[0]
  if op == 1:
    n = arr[1]
    if fir == -1:
      fir = lst = n
    else:
      llink[fir] = n
      rlink[n] = fir
      fir = n
  elif op == 2:
    n = arr[1]
    if fir == -1:
      fir = lst = n
    else:
      rlink[lst] = n
      llink[n] = lst
      lst = n
  elif op == 3:
    n, a = arr[1], arr[2]
    if llink[a] == 0 and rlink[a] == 0 and fir != a and lst != a:
      print('peko')
    else:
      # {left, n, a}
      left = llink[a]
      if left != 0:
        rlink[left] = n
        llink[n] = left
      else:
        fir = n
      llink[a] = n
      rlink[n] = a
  elif op == 4:
    n, a = arr[1], arr[2]
    if llink[a] == 0 and rlink[a] == 0 and fir != a and lst != a:
      print('peko')
    else:
      # {a, n, right}
      right = rlink[a]
      if right != 0:
        llink[right] = n
        rlink[n] = right
      else:
        lst = n
      llink[n] = a
      rlink[a] = n
  elif op == 5:
    n = arr[1]
    if llink[n] == 0 and rlink[n] == 0 and fir != n and lst != n:
      print('peko')
    else:
      if fir == n:
        print('NULL')
      else:
        print(llink[n])
  elif op == 6:
    n = arr[1]
    if llink[n] == 0 and rlink[n] == 0 and fir != n and lst != n:
      print('peko')
    else:
      if lst == n:
        print('NULL')
      else:
        print(rlink[n])
  else:
    n = arr[1]
    if llink[n] == 0 and rlink[n] == 0 and fir != n and lst != n:
      print('peko')
    else:
      left = llink[n]
      right = rlink[n]
      if left == 0 and right == 0:
        fir = lst = -1
      elif left == 0:
        llink[right] = 0
        fir = right
      elif right == 0:
        rlink[left] = 0
        lst = left
      else:
        rlink[left] = right
        llink[right] = left
      llink[n] = rlink[n] = 0