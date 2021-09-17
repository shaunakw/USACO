nums = []

for i in input().split():
    nums.append(int(i))

nums.sort()

a = nums[0]
b = nums[1]
c = nums[6] - a - b

print(a, b, c)

