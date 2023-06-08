n = int(input())
nums = input().split(' ')
x = int(input())
int_num = [int(i) for i in nums]
min_x = 100000
min_n = 0
for i in int_num:
    if abs(x - i) < min_x:
        min_x = abs(x - i)
        min_n = i
print(min_n)