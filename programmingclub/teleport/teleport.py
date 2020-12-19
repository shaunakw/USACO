A, B, X, Y = [int(i) for i in input().split()]

d1 = abs(A - B)
d2 = abs(A - X) + abs(B - Y)
d3 = abs(A - Y) + abs(B - X)
min_d = min(d1, min(d2, d3))

print(min_d)
