import sys


def main():
    
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort()

    ans = 0
    left = 0

    for right in range(n):
        while a[right] - a[left] > k:
            left += 1

        ans = max(ans, right - left + 1)

    print(ans)


if __name__ == "__main__":
    main()