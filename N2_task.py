import random
x = random.randint(1,100)
flag = False
i = 0
while (i <= 6) and (flag == False):
    i += 1
    print('Попытайтесь угадать число')
    n = int(input())
    if n > x:
        print('Данное число больше чем загадонное')
    else:
        if n < x:
            print('Данное число меньше чем загадонное')
        else:
            print('Вы угадали')
            flag = True
if i == 7:
    print('Все попытки потрачены')
            
            
    