# 시간 초과가 뜨는 버전.....ㅠㅠ
# 구현은 되었음..
import sys

length = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
quest_num = int(sys.stdin.readline())
result = []

for i in range(quest_num):
    quest = list(map(int, sys.stdin.readline().split()))
    result = []
    is_palidrome = True
    
    for idx in range(quest[0] - 1, quest[1]):
        result.append(arr[idx])

    for j in range(len(result) // 2):
        # print(result[j], result[-1 - j], i)
        if result[j] != result[-1 - j]:
            is_palidrome = False
            break
    
    if is_palidrome:
        result.append(1)
    else:
        result.append(0)
