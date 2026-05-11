
line = input().split()

stack = []

for item in line:

    if item == '+':

        val2 = stack[-1]
        stack.pop()
        val1 = stack[-1]
        stack.pop()

        stack.append(val1+val2)
    elif item == '-':

        val2 = stack[-1]
        stack.pop()
        val1 = stack[-1]
        stack.pop()

        stack.append(val1-val2)

    elif item == '*':

        val2 = stack[-1]
        stack.pop()
        val1 = stack[-1]
        stack.pop()

        stack.append(val1*val2)

    else:


        stack.append(int(item))


assert len(stack) == 1

print(stack[0])