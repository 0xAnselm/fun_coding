import random

# My implementation of deciding algorithm for Aufgabe 1.4 Lastwagen (ueber-)laden
# Runtime: O(n log n) + O(n log n) + O(n) = O(n log n) < o(n^2) 

def payload_decider(L, G, n=10) -> bool:
    L = sorted(L) # O(n log n) 
    G = sorted(G) # O(n log n)
    print("LKW Max Freight:", L, "\nWeight:".ljust(17), G)
    i = 0
    while (i < n): # at most O(n)
        if(L[i] >= G[i]):
            i += 1
        else:
            print("Matching not possible")
            return False
    return True


def main():
    n = 10
    # random.Random(10) #  <- this is seed yo
    L = random.sample(range(0, 100), n)
    G = random.sample(range(0, 100), n)
    result = payload_decider(L, G, n)
    print("Computer says:", result)


if __name__ == "__main__":
    main()
