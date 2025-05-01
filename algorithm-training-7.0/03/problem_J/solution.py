import gzip


def compress( val : str ) -> bytes:

    compressed_val = gzip.compress(bytes(val, 'utf-8'))

    return compressed_val

def decompress( val: bytes ) -> str:

    return gzip.decompress(val).decode('utf-8')


command = input()

if command == "pack":

    val = input()

    compressed_val = compress(val)

    print(len(compressed_val))

    for b in compressed_val:
        print(b, end=' ')
    print()
else:

    n = int(input())
    l = list(map(int, input().split() ) )

    val = decompress(bytes(l))
    print(val)