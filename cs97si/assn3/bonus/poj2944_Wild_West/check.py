#coding=utf-8



n, m = map(int, raw_input().split())



rects = []
for i in range(n):
  x, y, z = map(int, raw_input().split())
  rects.append((x, y, z))

total = 0
for x in range(m):
  for y in range(m):
    for z in range(m):
      isIn = False
      for (rx, ry, rz) in rects:
        if x < rx and y < ry and z < rz:
          isIn = True
          break
      if isIn:
        total += 1
print m * m * m - total
