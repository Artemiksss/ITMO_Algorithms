import random
num = int(input())
mas = []
def quicksort(nums, fst, lst):
    if fst >= lst:
        return
    i, j = fst, lst
    pivot = nums[random.randint(fst, lst)]

    while i <= j:
        while nums[i] < pivot:
            i += 1
        while nums[j] > pivot:
            j -= 1
        if i <= j:
            nums[i], nums[j] = nums[j], nums[i]
            i, j = i + 1, j - 1
    quicksort(nums, fst, j)
    quicksort(nums, i, lst)


for i in range(num):
    first_board, last_board = [int(i) for i in input().split(' ')]
    mas.append([first_board, last_board])
quicksort(mas, 0, len(mas) - 1)
min_mas, max_mas = mas[0]
count = 0
for i in range(1, num):
    if mas[i][1] > max_mas:
        if mas[i][0] <= max_mas:
            max_mas = mas[i][1]
        else:
            count += max_mas - min_mas + 1
            min_mas, max_mas = mas[i]
count += max_mas - min_mas + 1
print(count)


