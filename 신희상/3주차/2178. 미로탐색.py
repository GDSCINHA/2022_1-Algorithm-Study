from collections import deque

a, b = map(int, input().split())

maze = []

for i in range(a):
    maze.append(list(map(int, input())))

# 이동할 네 가지 방향 정의 (상, 하, 좌, 우)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# deque 생성
Q = deque()
Q.append((0, 0))

while Q:
    x, y = Q.popleft()

    # 현재 위치에서 4가지 방향으로 위치 확인
    for i in range(4):
        cx = x + dx[i]
        cy = y + dy[i]

        # 위치가 벗어나면 안되기 때문에 조건 추가
        if cx < 0 or cx >= a or cy < 0 or cy >= b:
            continue

        # 벽이므로 진행 불가
        if maze[cx][cy] == 0:
            continue

        # 벽이 아니므로 이동
        if maze[cx][cy] == 1:
            maze[cx][cy] = maze[x][y] + 1
            Q.append((cx, cy))

# 마지막 값에서 카운트 값을 뽑는다.
print(maze[a - 1][b - 1])

