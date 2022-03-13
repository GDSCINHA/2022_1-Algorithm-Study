def solution(array, commands):
    answer = []
    for arr in commands:
        a,b,c=arr[0],arr[1],arr[2]
        cnt=array[a-1:b]
        cnt.sort()
        answer.append(cnt[c-1])
    return answer