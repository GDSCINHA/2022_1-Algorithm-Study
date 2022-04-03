from itertools import combinations 

def isprimeNumber(i):
    prime_list = []
    for idx in range(1,i+1):
        if i % idx == 0:
            
            prime_list.append(idx)
    #print(prime_list)
    if len(prime_list) <= 2:
        return True
    else:
        return False
            

def solution(nums):
    answer = 0
    c = list(combinations(nums, 3))
    
    for i in c:
        print(sum(i))
        if(isprimeNumber(i[0]+i[1]+i[2])):
            answer += 1

    return answer