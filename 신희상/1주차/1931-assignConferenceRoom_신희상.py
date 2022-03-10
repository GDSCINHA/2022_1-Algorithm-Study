count = int(input())
conf = []

for i in range(count):
    a, b = map(int, input().split())
    conf.append([a, b])


conf = sorted(conf, key=lambda x: [x[1], x[0]])

answer = 0
before = 0

for i in conf:
    a, b = i[0], i[1]
    if a >= before:
        answer += 1
        before = b

print(answer)