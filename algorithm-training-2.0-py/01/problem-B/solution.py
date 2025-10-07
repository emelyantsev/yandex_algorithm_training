import sys

input_file = open('input.txt')
sys.stdin = input_file

#############################################


l = list( map( int, input().split() ) )

assert len(l) == 3

N = l[0]
a = min(l[1], l[2])
b = max(l[1], l[2])

assert a != b

v1 = b - a - 1
v2 = N + a - b - 1

print( min(v1, v2) )




################################################

if input_file: input_file.close()