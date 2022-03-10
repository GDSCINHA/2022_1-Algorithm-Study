sticks = int(input())
stick = []

for i in range(sticks):
    stick.append(int(input()))

count = 0
biggest = 0
for i in range(len(stick)-1, 0, -1):
    if stick[i] > biggest:
        biggest = stick[i]
        count += 1

print(count)
