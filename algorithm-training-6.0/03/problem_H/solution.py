n = int(input())

stack = []
prefix = [0]

for _ in range(n):
    op = input().strip()
    if op[0] == '+':
        x = int(op[1:])
        stack.append(x)
        prefix.append(prefix[-1] + x)
    elif op[0] == '-':
        print(stack.pop())
        prefix.pop()
    else:
        k = int(op[1:])
        print(prefix[-1] - prefix[-k - 1])

