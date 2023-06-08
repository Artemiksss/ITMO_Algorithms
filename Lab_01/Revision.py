n = int(input())
nums = input().split(' ')
int_num = [int(i) for i in nums]
min_n = min(int_num)
s_no_min = []
in_min = int_num.index(min_n)
int_num.pop(in_min)
print(min_n, min(int_num))