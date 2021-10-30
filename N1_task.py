print('Ведите трёхзначное число')
x = int(input())
if 100 <= x <= 999:
    Max = 0 
    a = x // 100
    b = (x // 10) % 10
    c = x % 10
    for s in range(3):
        x = 100 * a + 10 * b + c
        print(x)
        if x > Max:
            Max = x
        z = b
        b = c
        c = z
        x = 100 * a + 10 * b + c
        print(x)
        if x > Max:
            Max = x
        z = c
        c = a
        a = z
    print('Максимальное',Max)         
else:
    print('Вы вели не трёхзначное число')       