import sys

input_file = open('input.txt')
sys.stdin = input_file

#############################################


l = list( map( int, input().split() ) )
assert len(l) == 3

x = l[0]
y = l[1]
z = l[2]

print( 0 if x <= 12 and y <= 12 and x != y else 1  )


################################################

if input_file: input_file.close()