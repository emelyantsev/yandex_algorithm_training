import sys

def solve():
    # Считываем входные данные
    try:
        a = int(input())
        b = int(input())
        c = int(input())
        d = int(input())
    except:
        return

    options = []

    # 1. Гарантируем синий комплект (нужна хотя бы 1 синяя майка и 1 синие носки)
    # Чтобы точно была синяя майка, берем все красные + 1
    options.append((b + 1, d + 1))

    # 2. Гарантируем красный комплект
    options.append((a + 1, c + 1))

    # 3. Гарантируем обе майки + любые одни носки
    # (Если возьмем и синюю, и красную майку, то любые носки дадут комплект)
    options.append((max(a, b) + 1, 1))

    # 4. Гарантируем любые одни майки + оба вида носков
    options.append((1, max(c, d) + 1))

    # Ищем вариант с минимальной суммой M + N
    min_sum = float('inf')
    best_pair = (0, 0)

    for m, n in options:
        # Проверка на физическое наличие предметов (на всякий случай)
        # Хотя по условию гарантируется, что комплект собрать можно
        if m <= a + b and n <= c + d:
            if m + n < min_sum:
                min_sum = m + n
                best_pair = (m, n)

    print(f"{best_pair[0]} {best_pair[1]}")

solve()