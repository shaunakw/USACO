fin = open('moocast.in', 'r')
fout = open('moocast.out', 'w')

N = int(fin.readline())
cows = [] # array of (x, y, power)  

for i in range(N):
    line = [int(x) for x in fin.readline().split()] # read entire line into array
    cows.append(line)

adjList = [[]] * N # initialize with N empty arrays
for i in range(N):
    for j in range(N):
        if i == j:
            continue

        dx = abs(cows[i][0] - cows[j][0]) # difference in x-coordinates
        dy = abs(cows[i][1] - cows[j][1]) # difference in y-coordinates

        if dx * dx + dy * dy <= cows[i][2] * cows[i][2]: # cow i can reach cow j
            adjList[i].append(j)

visited = []
def dfs(node):
    if visited[node]:
        return
    visited[node] = True

    for i in adjList[node]:
        dfs(i)

maxcows = 1
for i in range(N):
    visited = [False] * N # initialize with N false values
    dfs(i)

    total = 0 # total cows reached
    for j in range(N):
        if visited[j]:
            total += 1
    
    maxcows = max(maxcows, total)

fout.write(str(maxcows))
fout.close()