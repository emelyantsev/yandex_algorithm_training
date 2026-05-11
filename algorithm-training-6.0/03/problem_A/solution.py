

def get_open(c : str) -> str:

    if c == '}':
        return '{'
    elif c == ']':
        return '['
    elif c == ')':
        return '('
    else:
        assert False  

s = input()

chars = []

ans = True

for c in s:

    if c == '{' or c == '[' or c == '(':

        chars.append(c)

    else:
        
        if len(chars) > 0 and chars[-1] == get_open(c):
            chars.pop()
        else:
            ans = False
            break


if not ans or len(chars) != 0:

    print('no')

else:
    print('yes')


        

