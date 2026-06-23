grid = []

for i in range(8):

    line = input().strip()

    grid.append(line)


used = set()

for i in range(8):

    for j in range(8):

        if grid[i][j] == 'R':


            used.add((i,j))

            for k in range(i+1, 8):

                used.add((k,j))

                if grid[k][j] == 'R' or grid[k][j] == 'B':
                    break

            for k in range(i-1, -1, -1):

                used.add((k,j))

                if grid[k][j] == 'R' or grid[k][j] == 'B':
                    break

            
            for k in range(j+1, 8):

                used.add((i, k))

                if grid[i][k] == 'R' or grid[i][k] == 'B':
                    break

            for k in range(j-1, -1, -1):

                used.add((i,k))

                if grid[i][k] == 'R' or grid[i][k] == 'B':
                    break

        elif grid[i][j] == 'B':

            used.add((i,j))

            for k in range(1, 8):

                ii = i + k
                jj = j + k

                if ii > 7 or ii < 0 or jj > 7 or jj < 0:
                    break

                used.add((ii,jj))

                if grid[ii][jj] == 'R' or grid[ii][jj] == 'B':
                    break

            for k in range(1, 8):

                ii = i + k
                jj = j - k

                if ii > 7 or ii < 0 or jj > 7 or jj < 0:
                    break

                used.add((ii,jj))

                if grid[ii][jj] == 'R' or grid[ii][jj] == 'B':
                    break

            for k in range(1, 8):

                ii = i - k
                jj = j + k

                if ii > 7 or ii < 0 or jj > 7 or jj < 0:
                    break

                used.add((ii,jj))

                if grid[ii][jj] == 'R' or grid[ii][jj] == 'B':
                    break

            
            for k in range(1, 8):

                ii = i - k
                jj = j - k

                if ii > 7 or ii < 0 or jj > 7 or jj < 0:
                    break

                used.add((ii,jj))

                if grid[ii][jj] == 'R' or grid[ii][jj] == 'B':
                    break


res = 64 - len(used)

print(res)