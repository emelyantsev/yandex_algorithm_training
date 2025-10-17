from sys import exit


class PrimeCalculator :

    def __init__(self, N : int) -> None:

        self.max_num = N
        self.vals = [True for i in range(N+1)]

        self.vals[0] = False
        self.vals[1] = False

        for i in range(2, N+1) :

            if self.vals[i]:

                step = self.vals[i]

                for j in range(i+step, N+1, step):

                    self.vals[j] = False

    def is_prime(self, num : int) -> bool:

        assert num > 0 and num <= self.max_num

        return self.vals[num]




N = int(input())

if N <= 3:
    print(1)
    exit(0)

calc = PrimeCalculator(N)

dp = [None, True, True, True]

for i in range(4, N+1):

    win = False

    for j in range(1, 4):

        num = i - j

        if not calc.is_prime(num) and dp[num] == False:

            win = True
            break
    
    dp.append(win)


print( 1 if dp[-1] else 2)
    
