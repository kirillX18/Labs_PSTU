#include <iostream>
#include <cmath>

using namespace std;
// f(x) = x^3 - x - 1
// f'(x) = 3x^2 - 1
// f''(x) = 6x
// [1,2]
// ф(x) = x + l * (x^3 - x - 1)
// -1/r < l < 0, если f'(x) > 0
// 0 > l > 1/r, если f'(x) < 0
// r = max(/f'(a)/, /f'(b)/)
// l = -1/20 = -0.05
int main() {
    setlocale(LC_ALL, "RUS");
    float x, xPrev;
    double lambda = -0.05;
    x = 2; // Можно выбрать любое x0 из выбранного заранее промежутка
    xPrev = 0; // Делаем заведомо меньше x, чтобы цикл правильно сработал
    double eps = 0.000001;
    while (abs(x - xPrev) > eps) {
        xPrev = x;
        x = lambda * (pow(xPrev, 3) - xPrev - 1) + xPrev;
    }
    cout << "Корень: " << x << endl;
    return 0;
}