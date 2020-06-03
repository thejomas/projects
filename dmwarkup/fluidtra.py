n = int(input())
tanks = [[None] * 4] * n
maxi = 0
for i in range(n):
    tanks[i] = input().split()
    for j in range(4):
        tanks[i][j] = int(tanks[i][j])
#    maxi = max(tanks[i][0]+tanks[i][3], maxi)

print(maxi)
output = [0] * n
for i in range(n-1):
    if (tanks[i][0]+tanks[i][3] >= tanks[i+1][0]+tanks[i+1][3]):
        output[i] = tanks[i][3]
    else:
        #output[i] = abs(tanks[i][0] - tanks[i+1][0]) + tanks[i+1][3]
        output[i] = max(maxi-tanks[i][0], output[i])

output[n-1] = tanks[n-1][3]

for out in output:
    print(out)
