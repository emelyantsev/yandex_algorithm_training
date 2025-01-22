import sys

input_file = open('input.txt')
sys.stdin = input_file

#############################################

n = int(input())

pos_nums = set(i + 1 for i in range(n))


while True:

    inp = input()

    if inp == "HELP":
        break
    else:

        s = set( map(int, inp.split() ) )
        status = input()

        if (status == "NO"):
            pos_nums = pos_nums.difference(s)
        else:
            pos_nums = pos_nums.intersection(s)


for num in sorted(pos_nums):
    print(num, end=' ')
print()

################################################

if input_file: input_file.close()