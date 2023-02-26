# 1,000 이하의 소수를 나열하기 (알고리즘 개선 2)

counter = 0             # 곱셈 + 나눗셈 횟수 카운트
ptr = 0                 # 이미 찾은 소수의 개수
prime = [None] * 500    # 소수를 저장하는 배열

prime[ptr] = 2          # 2는 소수
ptr += 1       

prime[ptr] = 3          # 3은 소수
ptr += 1


for n in range(5, 1001, 2):
    i = 1
    while prime[i] * prime[i] <= n:
        counter += 2
        if n % prime[i] == 0:
            break
        i += 1
    else:                   # 끝가지 나누어 떨어지지 않으면
        prime[ptr] = n      # 소수이므로 소수 배열에 등록한다.
        ptr += 1
        counter += 1

for i in range(ptr):
    print(prime[i])
print(f'나눗셈을 실행한 횟수 : {counter}')
