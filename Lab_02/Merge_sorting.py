def merge(a, b):
    rez = []
    N = len(a)
    M = len(b)

    i = 0
    j = 0
    while i < N and j < M:
        if a[i] <= b[j]:
            rez.append(a[i])
            i += 1
        else:
            rez.append(b[j])
            j += 1

    rez += a[i:] + b[j:]
    return rez

def merde_sort(a):
    N1 = len(a) // 2
    a1 = a[:N1]
    a2 = a[N1:]

    if len(a1) > 1:
        a1 = merde_sort(a1)
    if len(a2) > 1:
        a2 = merde_sort(a2)

    return merge(a1, a2)


n = int(input())
nums = [int(i) for i in input().split(' ')]
sort = merde_sort(nums)
print(*sort)