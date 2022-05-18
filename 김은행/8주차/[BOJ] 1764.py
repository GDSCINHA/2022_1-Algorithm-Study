N, M = map(int, input().split())

N_list = [input() for i in range(N)]
M_list = [input() for i in range(M)]

d = list(set(N_list) & set(M_list))

print(len(d))

for name in sorted(d): print(name)