import random
A = [8, 5, 6, 1, 3, 2, 4, 7]
verify = []
B = [None] * len(A)


def mergesort(l, r):
    if (r > l):
        m = (l+r)//2
        mergesort(l, m)
        mergesort(m+1, r)
        merge(l, m, r)


def merge(l, m, r):
    global B
    for i in range(l, m+1):
        B[i] = A[i]
    for i in range(m+1, r+1):
        B[i] = A[r-i+m+1]
    i = l
    j = r
    for k in range(l, r+1):
        if B[i] < B[j]:
            A[k] = B[i]
            i = i + 1
        else:
            A[k] = B[j]
            j = j - 1

def unitTest():
    global A, verify
    l = random.randrange(1, 9, 1)
    A = [random.randrange(1, 50, 1) for i in range(l)]
    verify = A

def main():
    for i in range(50):
        unitTest()
        l = 0
        r = len(A)-1
        mergesort(l, r)
        if A == sorted(verify):
            print("passed", A)
        else:
            print("fail")
            print(A, verify)
            break


if __name__ == "__main__":
    main()
