inp = open('whereami.in', 'r')
out = open('whereami.out', 'w')

N = int(inp.readline())
farms = inp.readline()

k = N
for i in range(1, N):
    substrings = []
    duplicate = False
    for j in range(N - i + 1):
        if farms[j:j+i] in substrings:
            duplicate = True
            break
        substrings.append(farms[j:j+i])
    if not duplicate:
        k = i
        break

out.write(str(k))
out.close()