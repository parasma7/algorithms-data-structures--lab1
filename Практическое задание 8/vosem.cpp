//задача номер 1
#include <iostream>

using namespace std;

// Функция быстрого возведения в степень
long long fast_pow(long long base, long long exp) {
    long long result = 1;
    
    while (exp > 0) {
        // Если текущий бит степени равен 1, умножаем результат на основание
        if (exp & 1) { 
            result *= base;
        }
        // Возводим основание в квадрат
        base *= base;
        // Сдвигаем степень вправо (делим на 2)
        exp >>= 1;
    }
    
    return result;
}

int main() {

    long long base, exp;
    
    // Ввод данных
    cout << "Введите основание: ";
    cin >> base;
    cout << "Введите степень: ";
    cin >> exp;
    
    // Вызов функции и вывод результата
    long long res = fast_pow(base, exp);
    
    cout << base << "^" << exp << " = " << res << endl;

    return 0;
}

//задача номер 2

#include <iostream>

using namespace std;

// Рекурсивная функция для нахождения НОД (алгоритм Евклида)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    
    // Чтение двух чисел
    cin >> a >> b;
    
    // Вывод результата
    cout << gcd(a, b) << endl;

    return 0;
}

//2 способ

#include <iostream>

using namespace std;

// Рекурсивная функция НОД через вычитание
int gcd_subtraction(int a, int b) {
    // Базовый случай: если числа равны, то это и есть НОД
    if (a == b) {
        return a;
    }
    
    // Рекурсивные шаги: вычитаем меньшее из большего
    if (a > b) {
        return gcd_subtraction(a - b, b);
    } else {
        return gcd_subtraction(a, b - a);
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    
    cout << gcd_subtraction(a, b) << endl;

    return 0;
}

//Задача номер 3

#include <iostream>

using namespace std;

void hanoi(int n, int from, int to, int aux) {
    if (n == 0) {
        return;
    }
    
    hanoi(n - 1, from, aux, to);
    
    cout << "Ingredient " << n << " move from " << from << " to " << to << endl;
    
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cin >> n;
    
    hanoi(n, 1, 3, 2);
    
    return 0;
}