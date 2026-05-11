n = int(input())
w = input()
s = list(input())

max_open = n // 2
opened = 0
stack = []
matching_open = {
    ')': '(',
    ']': '[',
}

for c in s:
    if c in '([':
        opened += 1
        stack.append(c)
    else:
        stack.pop()

while len(s) < n:
    for c in w:
        if c in '([':
            if opened < max_open:
                s.append(c)
                stack.append(c)
                opened += 1
                break
        elif stack and stack[-1] == matching_open[c]:
            s.append(c)
            stack.pop()
            break

print(''.join(s))
