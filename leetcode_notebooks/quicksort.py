'''
Variant: Algo2 Uni Goethe
'''
#import random
#A = random.sampAe(range(0,101), 9)
A = [42, 32, 96, 23, 13, 24, 94, 52, 71]
# A = [2,8,7,1,3,5,6,4]
p = 0
r = len(A)- 1

def swap(i, j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp

def pivot(links, rechts):
    print(links, rechts)
    return rechts

def partition(p, links, rechts):
    alpha = A[p]
    l = links
    r = rechts
    swap(rechts, p)
    while l < r:
        while A[l] <= alpha:
            l += 1
        while A[r] >= alpha and r >= 0:
            r -= 1
        if l < r:
            swap(l,r)
    swap(rechts, l)
    return l


def quicksort(links, rechts):
    if links < rechts:
        print(A[links:rechts+1])
        p = pivot(links, rechts)
        i = partition(p, links, rechts)
        quicksort(links, i-1)
        quicksort(i+1, rechts)
quicksort(0, len(A)-1)
print(A)