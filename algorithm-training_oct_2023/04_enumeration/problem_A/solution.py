from typing import List, Optional
import sys

def next_permute(L : List[int] ) -> Optional[List[int]]:
    
    for i in range(len(L)-1, 0, -1):

        if L[i] > L[i-1]:

            for j in range(len(L)-1, i-1, -1):
                if L[j] > L[i-1]:
                    L[j], L[i-1] = L[i-1], L[j]
                    break

            l = i
            r = len(L) - 1
            while l < r:
                L[l], L[r] = L[r], L[l]
                l += 1
                r -= 1

            return L
    
    return None


def print_list(L : List[int]) -> None:

    sys.stdout.write("".join(map(str, L)))
    sys.stdout.write("\n")


N = int(input())

L = [i for i in range(1, N+1)]

print_list(L)

while (L := next_permute(L)) is not None:

    print_list(L)

