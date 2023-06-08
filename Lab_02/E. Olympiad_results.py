num = int(input())
people = []
for i in range(num):
    people.append([int(i) for i in input().split(' ')])
for i in range(num):
    for j in range(num - 1):
        if people[j][1] < people[j + 1][1]:
            people[j], people[j + 1] = people[j + 1], people[j]
        elif people[j][1] == people[j + 1][1]:
            if people[j][0] > people[j + 1][0]:
                people[j], people[j + 1] = people[j + 1], people[j]

for i in range(num):
    print(people[i][0], people[i][1])