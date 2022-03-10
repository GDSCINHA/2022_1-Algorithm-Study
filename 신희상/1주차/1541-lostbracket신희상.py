text = input()

text = text.split('-')
array = []


for i in range(0, len(text)):
    array.append(sum(list(map(int, text[i].split('+')))))

answer = array[0]
for i in range(1, len(text)):
    answer -= array[i]

print(answer)
