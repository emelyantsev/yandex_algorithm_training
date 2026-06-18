def main():
    # Считываем три строки ввода
    first_line = input().strip()
    second_line = input().strip()
    place = int(input().strip())
    
    # Разбиваем строки по двоеточию
    first = first_line.split(':')
    second = second_line.split(':')
    
    # Преобразуем в целые числа
    a = int(first[0])
    b = int(first[1])
    c = int(second[0])
    d = int(second[1])

    assert a >= 0 and a <= 5 and b >= 0 and b <= 5 and c >= 0 and c <= 5 and d >= 0 and d <= 5
    assert place == 1 or place == 2
    
    score = 0
    
    # Если сумма голов первой команды меньше суммы голов второй
    if (a + c) < (b + d):
        score += (b + d) - (a + c)
        c += score
    
    # Если суммы голов равны
    if (a + c) == (b + d):
        if place == 1:
            if c > b:
                pass  # ничего не делаем
            else:
                score += 1
        elif place == 2:
            if a > d:
                pass  # ничего не делаем
            else:
                score += 1
    
    print(score)

if __name__ == "__main__":
    main()