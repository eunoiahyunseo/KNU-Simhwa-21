prime_list = []
count = 0
input_number = int(input("숫자를 입력해주세요"))
for i in range(1, input_number + 1):
    if input_number == i:
        prime_list.append(i)
        count += 1
    elif input_number % i == 0:
        prime_list.append(i)
        count += 1
    
print(prime_list)