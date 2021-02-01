fin = open('angry.in', 'r')
fout = open('angry.out', 'w')

N, K = [int(i) for i in fin.readline().split()]
hay = []

for i in range(N):
    hay.append(int(fin.readline()))

hay.sort()

lo = 0
hi = 500000000

while lo < hi:
    r = int((lo + hi) / 2)

    # Check if r is valid
    cows = 1 # Number of cows used
    x = hay[0] + r # Location of current cow
    for i in range(1, N):
        if hay[i] > x + r:
            cows += 1
            x = hay[i] + r
    
    if cows > K: # R value needs too many cows (is lower than minimum)
        lo = r + 1
    else: # R value is greater than or equal to minimum
        hi = r

fout.write(str(lo))

fout.close()