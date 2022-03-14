def solution(board, moves):
    picked = []
    answer = 0

    for j in range(len(moves)):
        for i in range(len(board)):
            if board[i][moves[j] - 1] != 0:
                picked.append(board[i][moves[j] - 1])
                board[i][moves[j] - 1] = 0
                break

        if len(picked) >= 2 and picked[-1] == picked[-2]:
            answer += 2
            picked = picked[:-2]
        
    return answer