fin = open('traffic.in', 'r')
fout = open('traffic.out', 'w')

types = []
lbounds = [] # lower bounds
ubounds = [] # upper bounds
N = int(fin.readline())

for i in range(N):
    line = fin.readline().split()
    types.append(line[0])
    lbounds.append(int(line[1]))
    ubounds.append(int(line[2]))

minf = 0
maxf = 1000000;
for i in reversed(range(N)): # Iterating in reverse to get the initial flow range
    if types[i] == "on":
        minf = max(minf - ubounds[i], 0);
        maxf -= lbounds[i];
    elif types[i] == "off":
        minf += lbounds[i];
        maxf += ubounds[i];
    else:
        minf = max(minf, lbounds[i]);
        maxf = min(maxf, ubounds[i]);

fout.write(str(minf) + ' ' + str(maxf) + '\n')

minf = 0
maxf = 1000000;
for i in range(N): # Iterating normally to get the ending range
    if types[i] == "on":
        minf += lbounds[i];
        maxf += ubounds[i];
    elif types[i] == "off":
        minf = max(minf - ubounds[i], 0);
        maxf -= lbounds[i];
    else:
        minf = max(minf, lbounds[i]);
        maxf = min(maxf, ubounds[i]);

fout.write(str(minf) + ' ' + str(maxf))

fout.close()