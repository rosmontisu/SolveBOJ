import math

def solution(start, end):
    answer = 0

    if (start < 2):
        start = 2

    for i in range(start, end + 1):
        is_prime = True
        for j in range(2, int(math.sqrt(i)) + 1):
            if (i%j == 0):
                is_prime = False
                break
        if is_prime == True:
            answer += 1

    return answer
