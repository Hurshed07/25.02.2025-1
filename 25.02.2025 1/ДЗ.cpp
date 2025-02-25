#include <iostream>

using namespace std;

void printMessage() {
    cout << "Привет! Это сообщение из функции вывода строки." << endl;
}

int calculateFactorial(int n) 
{
    if (n < 0) return -1; 
    int factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

bool isPrime(int n) 
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void showMenu() 
{
    cout << "\nМеню:" << endl;
    cout << "1. Вывести сообщение" << endl;
    cout << "2. Рассчитать факториал числа" << endl;
    cout << "3. Проверить число на простоту" << endl;
    cout << "4. Выход" << endl;
    cout << "Выберите действие: ";
}

int main() 
{
    setlocale(LC_ALL, "");

    int choice, number;

    while (true) 
    {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            void (*funcPtr)() = &printMessage; 
            funcPtr(); 
            break;
        }
        case 2: {
            cout << "Введите число для расчета факториала: ";
            cin >> number;
            if (number < 0) {
                cout << "Факториал отрицательного числа не определен." << endl;
            }
            else {
                int (*funcPtr)(int) = &calculateFactorial;
                cout << "Факториал числа " << number << " равен " << funcPtr(number) << endl;
            }
            break;
        }
        case 3: {
            cout << "Введите число для проверки на простоту: ";
            cin >> number;
            bool (*funcPtr)(int) = &isPrime; 
            if (funcPtr(number)) {
                cout << "Число " << number << " является простым." << endl;
            }
            else {
                cout << "Число " << number << " не является простым." << endl;
            }
            break;
        }
        case 4: {
            cout << "Выход из программы." << endl;
            return 0;
        }
        default:
            cout << "Неверный выбор. Пожалуйста, выберите пункт из меню." << endl;
        }
    }
}