def solution(start, end, number):
    answer = 0
    for i in range(start, end+1):
        if (i%number==0):
            answer += i
    return answer