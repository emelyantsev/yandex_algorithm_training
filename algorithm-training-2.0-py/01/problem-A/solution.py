import sys

input_file = open('input.txt')
sys.stdin = input_file

#############################################


r = int(input()) 
assert r >= -128 and r <= 127

i = int(input())
assert i >= 0 and i <= 7

c = int(input())
assert c >= 0 and c <= 7

v = i

if i == 0:
    v = 3 if r != 0 else c
elif i == 1:
    v = c
elif i == 4:
    v = 3 if r != 0 else 4
elif i == 6:
    v = 0
elif i == 7:
    v = 1

print(v)


################################################

if input_file: input_file.close()