length = int(input())
txt = input()

dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]  # [x,y], // 왜인지 모르겠는데 이렇게 하니까 됐어요, 임의수정함
status = 2
map = [[0, 0]]  # 0,0 부터 시작

for i in txt:
    dx_ = dx[status % 4]
    dy_ = dy[status % 4]

    if i == 'R':
        status += 1
    elif i == 'L':
        status -= 1
    elif i == 'F':
        last = map[len(map) - 1]
        map.append([last[0] + dx_, last[1] + dy_])

x_d = []
y_d = []

for x, y in map:
    x_d.append(x)
    y_d.append(y)

x_s = set(x_d)
y_s = set(y_d)
print(x_s)
x_m = min(x_s)
y_m = min(y_s)
array = [['' for row in range(len(y_s))] for col in range(len(x_s))]

for i in range(len(map)):
    map[i][0] -= x_m
    map[i][1] -= y_m

for i in range(len(array)):
    for j in range(len(array[i])):

        if [i, j] in map:
            array[i][j] = '.'
        else:
            array[i][j] = '#'

    print("".join(array[i]))
