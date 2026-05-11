
import sys
from typing import List


op_priorites = { 
    '+' : 1 ,
    '-' : 1 , 
    '*' : 2
}

def toRpn(expression: List[str]) -> List[str]:

    stack = []
    result = []

    for token in expression:

        if token == '(':
            stack.append(token)

        elif token == ')':

            while True:

                if len(stack) == 0:
                    raise SyntaxError

                if stack[-1] != '(':
                    result.append( stack[-1] )
                    stack.pop()
                else:
                    stack.pop()
                    break
                

        elif token.isdigit():

            result.append(token)

        elif token == '+' or token == '-' or token == '*':

            while len(stack) > 0 and stack[-1] != '(' and op_priorites[token] <= op_priorites[stack[-1]]:
                result.append(stack[-1])
                stack.pop()

            stack.append(token)

        else:

            raise SyntaxError

    while len(stack) > 0:

        if stack[-1] == '(':

            raise SyntaxError

        else:

            result.append(stack[-1])
            stack.pop()

    return result


def tokenize(expression : str) -> List[str] :

    result = []

    cur_digit = str()

    for i in range(len(expression)):

        if expression[i].isdigit():

            if expression[i-1].isdigit():

                cur_digit += expression[i]
            else:

                cur_digit = expression[i]

            if i == len(expression) - 1 or not expression[i+1].isdigit():

                result.append(cur_digit)

            
        elif expression[i] in { '+', '-', '*', '(', ')' }:

            result.append(expression[i])

        elif expression[i].isspace():

            pass
        else:
            raise SyntaxError


    return result


def calc_rpn( expression : List[str]) -> int:

    line = expression 

    stack = []

    for item in line:

        if item == '+':

            if len(stack) < 2:
                raise SyntaxError

            val2 = stack[-1]
            stack.pop()
            val1 = stack[-1]
            stack.pop()

            stack.append(val1+val2)
        elif item == '-':

            if len(stack) < 2:
                raise SyntaxError

            val2 = stack[-1]
            stack.pop()
            val1 = stack[-1]
            stack.pop()

            stack.append(val1-val2)

        elif item == '*':

            if len(stack) < 2:
                raise SyntaxError

            val2 = stack[-1]
            stack.pop()
            val1 = stack[-1]
            stack.pop()

            stack.append(val1*val2)

        else:

            stack.append(int(item))

    if len(stack) != 1:

        raise SyntaxError

    return stack[-1]



if __name__ == '__main__':

    line = input()

    try:

        expression = tokenize(line)

    except SyntaxError as e:

        print('WRONG')
        sys.exit(0)

    
    try:

        rpn_expression = toRpn(expression)

    except SyntaxError as e:

        print('WRONG')
        sys.exit(0)

    try:

        val = calc_rpn(rpn_expression)

    except SyntaxError as e:

        print('WRONG')
        sys.exit(0)

    print(val)