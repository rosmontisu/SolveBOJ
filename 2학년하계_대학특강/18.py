def solution(start, end):
    answer = 0
    for i in range(start, end + 1):
        answer += i
    return answer