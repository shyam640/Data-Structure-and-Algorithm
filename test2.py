val1, val2 = [int(i) for i in input().split()]
column = [0] + [int(i) for i in input().split()]
border = [-1] + [-1 for i in range(val1)]
praj = set()
l = []
for i in range(val2):
    id, a, b, c, d = input().split(",")
    id = int(id[8:])
    a = float(a)
    b = int(b[2:])
    c = int(c[2:])
    d = int(d[2:])
    l.append([a, id, 1, b])
    l.append([a, id, 2, c])
    l.append([a, id, 3, d])
l.sort(key=lambda x: (-x[0], x[1], x[2]))

for i in l:
    if i[1] not in praj:
        if column[i[3]] > 0:
            column[i[3]] -= 1
            border[i[3]] = i[0]
            praj.add(i[1])
column = [[column[i], i, border[i]] for i in range(1, len(column))]
column.sort(key=lambda x:(-x[0], x[1], x[2]))
d = 0
for i in l:
    if i[1] not in praj:
        while d < len(column) and column[d][0] <= 0:
            d += 1
        if d < len(column):
            column[d][0] -= 1
            if column[d][2] == -1:
                column[d][2] = 100
            column[d][2] = min(column[d][2], i[0])
            praj.add(i[1])
column.sort(key=lambda x:-x[2])

for i in column:
    if i[2] != -1:
        print("C-" + str(i[1]), i[2])
    else:
        print("C-" + str(i[1]), "n/a")