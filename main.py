""" Sudoku Solver

This is a small recursion backtracking fun exercise inspired by the video "Python Sudoku Solver" of youtube channel: Computerphile. 
Matrix is indexed by [x,y], where x denotes row, and y column number.
Written in Python 3.8.5

TO DO:
 - Validity checker (is Soduko grid and values valid)
 - Configure for every symmetrical Sudoku grid with dimension n^2
"""

import math

grid = [[5, 3, 0, 0, 7, 0, 0, 0, 0],
        [6, 0, 0, 1, 9, 5, 0, 0, 0],
        [0, 9, 8, 0, 0, 0, 0, 6, 0],
        [8, 0, 0, 0, 6, 0, 0, 0, 3],
        [4, 0, 0, 8, 0, 3, 0, 0, 1],
        [7, 0, 0, 0, 2, 0, 0, 0, 6],
        [0, 6, 0, 0, 0, 0, 2, 8, 0],
        [0, 0, 0, 4, 0, 9, 0, 0, 5],
        [0, 0, 0, 0, 8, 0, 0, 7, 9]]


def pretty_print(grid):
    """Pretty printing function, works for every symmetrical matrix with dimension n^2 | n>1

    Keyword arguments:
    grid -- the symmetrical Sudoku grid
    """
    n = len(grid)
    sqrt_n = int(math.sqrt(len(grid)))
    for x in range(0, n):
        line = ""
        if (x % sqrt_n == 0 and x > 1):
            line += ("-"*(n+sqrt_n+1))
            line += "\n"
        for y in range(0, n):
            if (y % sqrt_n == 0):
                line += "|" + str(grid[x][y])
            else:
                line += str(grid[x][y])
        line += "|"
        print(line)


def possible(x, y, n):
    """Function to check if its possible to place (int) n at position [x,y] in matrix or grid. n is allowed to be place when 3 criteria are met. sqrt_n denotes n of n^2. 
    1: n doesnt appear in row
    2: n doesnt appear in column
    3: n doesnt appear in respective square

    Keyword arguments:
    x -- row number of grid
    y -- column number of grid
    n -- number to check
    """
    global grid
    sqrt_n = int(math.sqrt(len(grid)))
    square_x = x // sqrt_n
    square_y = y // sqrt_n
    square_as_row = []  # stores a sqaure as a row to check if n appears
    column_as_row = []  # stores a sqaure as a row to check if n appears

    # check the squares
    for i in range(square_x*sqrt_n, square_x*sqrt_n+sqrt_n):
        for j in range(square_y*sqrt_n, square_y*sqrt_n+sqrt_n):
            square_as_row.append(grid[i][j])

    # convert column as list
    for i in range(len(grid)):
        column_as_row.append(grid[i][y])

    if (n in grid[x]):
        return False
    if (n in column_as_row):
        return False
    if (n in square_as_row):
        return False
    return True


def possibl_alternative(x, y, n):
    """Alternative function to check if its possible to place (int) n at position [x,y] in matrix or grid. n is allowed to be place when 3 criteria are met. sqrt_n denotes n of n^2. Version from the youtube video
    1: n doesnt appear in row
    2: n doesnt appear in column
    3: n doesnt appear in respective square

    Keyword arguments:
    x -- row number of grid
    y -- column number of grid
    n -- number to check
    """
    global grid
    for i in range(0, 9):
        if grid[x][i] == n:
            return False
    for i in range(0, 9):
        if grid[i][y] == n:
            return False
    x0 = (x//3)*3
    y0 = (y//3)*3
    for i in range(0, 3):
        for j in range(0, 3):
            if grid[x0+i][y0+j] == n:
                return False
    return True


def solve():
    """" Rescursive approach which uses backtracking to check if value n is a possible solution for index [x,y]. If so, place [x,y]=n and call solve() to check for next empty spot, i.e. [x,y]=0. If possible() reached numbers over 9 then no solution was found, grid[x,y] is reset to 0 and the path in the call tree is left (return)  
    """
    global grid
    for x in range(9):
        for y in range(9):
            if grid[x][y] == 0:
                for n in range(1, 10):
                    if possible(x, y, n):
                        grid[x][y] = n
                        solve()
                        grid[x][y] = 0
                return
    pretty_print(grid)


def main():
    print("Solving Sudoku")
    solve()


if __name__ == "__main__":
    main()
