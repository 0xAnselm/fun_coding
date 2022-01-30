from socket import SOL_ALG
import numpy as np
import re
from shapely.geometry import Point
from shapely.geometry.polygon import Polygon
import matplotlib.pyplot as plt
from shapely import wkt

x_1 = [5, 4, 35]
x_2 = [15, 4, 20]
s_1 = [1, 0, 0]
s_2 = [0, 1, 0]
s_3 = [0, 0, 1]
RHS = [480, 160, 1190]
vertices = [(0, 0), (0, 32), (12, 28), (26, 14), (34, 0)]


def buildb():
    b = np.array([RHS]).T
    return b


def buildA():
    A = np.array([x_1, x_2, s_1, s_2, s_3]).T
    return A


def permutationFactory():
    ind = ["x1", "x2", "s1", "s2", "s3"]
    indS = ""
    for x in ind:
        indS += x.rjust(4)
    print(indS)
    print("-"*20)
    c = 0
    permVectors = []
    for i in range(pow(2, 5)+1):
        if 3 == bin(i)[2:].count('1'):
            a = bin(i)[2:]
            a = a.rjust(5, "0")
            permVectors.append(a)
            l = ""
            for o in a:
                l += "   " + o
            print(l)
            c += 1
            if c % 5 == 0:
                print("-"*20)
    return permVectors


def calcLGS(A, b, pV):
    mySolutions = []
    for i in range(len(pV)):
        ind = [m.start() for m in re.finditer('1', pV[i])]
        # print(int("0b"+pV[i], 2), pV[i])
        A_B = A[:, ind]
        x = np.linalg.solve(A_B, b)
        if pV[i][0] == '0':
            x[0] = 0 
        if pV[i][1] == '0':
            x[1] = 0 
        mySolutions.append(x)
        # print("x1:", x[0], "x2:", x[1])
    return mySolutions


def checkFeasibleSolution(sol):
    poly = Polygon(vertices)
    # x,y = poly.exterior.xy
    # plt.plot(x,y)
    # plt.savefig('test.png')
    for s in sol:
        x1 = s[0][0]
        x2 = s[1][0]
        p = Point(x1, x2)
        print(wkt.dumps(p, rounding_precision=0).rjust(15), "ist im Polytope:", poly.touches(p))


def main():
    pV = permutationFactory()
    print("Solving LGS")
    print("-"*20)
    A = buildA()
    b = buildb()
    sol = calcLGS(A, b, pV)
    print("Checking for feasible Solution")
    print("-"*20)
    checkFeasibleSolution(sol)
    print("-"*20)


if __name__ == "__main__":
    main()
