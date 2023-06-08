s = int(input())
nums = input().split(' ')
int_nums = [int(i) for i in nums]
k = 0
for i in range(1, len(int_nums) - 1):
    if (int_nums[i] > int_nums[i-1]) and (int_nums[i] > int_nums[i+1]):
        k += 1
print(k)