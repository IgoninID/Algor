#include <iostream>
#include <vector>
#include <algorithm>    

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Исходный вектор
    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // for_each 
    // Применяет функцию ко всем элементам контейнера
    cout << "Элементы массива: ";
    for_each(numbers.begin(), numbers.end(), [](int n) { // должна быть вызываемой для каждого элемента в диапазоне [first, last]
        cout << n << " ";                                // возвращаемое значение игнорируется
        });
    cout << "\n";

    // В C++ 20 добавлены constained версии алгоритмов принимающие не итераторы, а диапазон в виде объекта, например сам контейнер
    cout << "Элементы массива: ";
    ranges::for_each(numbers, [](int n){cout << n << " ";});
    cout << "\n";

    // count
    // Подсчет количества элементов равных заданнаму
    cout << "Количество 9: ";
    cout << count(numbers.begin(), numbers.end(), 9) << "\n";
    cout << "Количество 8: ";
    cout << ranges::count(numbers, 8) << "\n";

    // find
    // Поиск элемента со заданным значением, возвращает итератор указывающий на этот элемент,
    // при разыменовании найденного это будет позиция (1,2,3...)
    // при разыменовании ненайденного будет ошибка так как итератор указывает на конец контейнера
    // при вычитании начала контейнера будет индекс элемента (0,1,2...), если не найден то последний индекс контейнера
    cout << "Позиция элемента со значением 8: ";
    cout << *find(numbers.begin(), numbers.end(), 8) << "\n";
    cout << "Индекс элемента со значением 8: ";
    cout << find(numbers.begin(), numbers.end(), 8) - numbers.begin() << "\n";
    cout << "Индекс элемента со значением 15: ";
    cout << find(numbers.begin(), numbers.end(), 15) - numbers.begin() << "\n";

    cout << "Позиция элемента со значением 8: ";
    cout << *ranges::find(numbers.begin(), numbers.end(), 8) << "\n";
    cout << "Индекс элемента со значением 8: ";
    cout << ranges::find(numbers.begin(), numbers.end(), 8) - numbers.begin() << "\n";
    cout << "Индекс элемента со значением 15: ";
    cout << ranges::find(numbers.begin(), numbers.end(), 15) - numbers.begin() << "\n";

    // any_of / all_of / none_of 
    // Проверяют выполнение логического условия хотя бы для одного / всех / ни одного элемента
    bool has_even = any_of(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; });
    bool ranges_has_even = ranges::any_of(numbers, [](int n) { return n % 2 == 0; });

    bool all_positive = all_of(numbers.begin(), numbers.end(), [](int n) { return n > 0; });
    bool ranges_all_positive = ranges::all_of(numbers, [](int n) { return n > 0; });

    bool none_negative = none_of(numbers.begin(), numbers.end(), [](int n) { return n < 0; });
    bool ranges_none_negative = ranges::none_of(numbers, [](int n) { return n < 0; });

    cout << "Есть ли хотя бы одно четное число? " << (has_even ? "Да" : "Нет") << "\n";
    cout << "Есть ли хотя бы одно четное число? " << (ranges_has_even ? "Да" : "Нет") << "\n";

    cout << "Все ли числа положительные? " << (all_positive ? "Да" : "Нет") << "\n";
    cout << "Все ли числа положительные? " << (ranges_all_positive ? "Да" : "Нет") << "\n";

    cout << "Нет ли отрицательных чисел? " << (none_negative ? "Да" : "Нет") << "\n";
    cout << "Нет ли отрицательных чисел? " << (ranges_none_negative ? "Да" : "Нет") << "\n";

    // transform 
    // Преобразует каждый элемент по заданному правилу и записывает результат в новый контейнер
    vector<int> squares(numbers.size());
    transform(numbers.begin(), numbers.end(), squares.begin(), [](int n) {
        return n * n;
        });

    cout << "Квадраты элементов: ";

    for (auto x : squares) {
        cout << x << " ";
    }
    cout << "\n";
    squares.clear();

    ranges::transform(numbers, back_inserter(squares), [](int n) {
        return n * n;
        });

    cout << "Квадраты элементов: ";

    for (auto x : squares) {
        cout << x << " ";
    }
    cout << "\n";

    // copy_if 
    // Копирует только те элементы, которые удовлетворяют условию
    vector<int> even_numbers;
    copy_if(numbers.begin(), numbers.end(), back_inserter(even_numbers), [](int n) { // предикат должен возвращать bool
        return n % 2 == 0; // предикат
        });

    cout << "Только четные числа: ";
    for (auto x : even_numbers) {
        cout << x << " ";
    }
    cout << "\n";
    even_numbers.clear();
    ranges::copy_if(numbers, back_inserter(even_numbers), [](int n) { // предикат должен возвращать bool
        return n % 2 == 0; // предикат
        });

    cout << "Только четные числа: ";
    for (auto x : even_numbers) {
        cout << x << " ";
    }
    cout << "\n";

    // reverse_copy
    // копирует контейнер в обратном порядке в другой контейнер
    vector<int> rev;
    reverse_copy(numbers.begin(), numbers.end(), back_inserter(rev));
    cout << "Обратный порядок: ";
    for (auto x : rev) {
        cout << x << " ";
    }
    cout << "\n";
    rev.clear();
    ranges::reverse_copy(numbers, back_inserter(rev));
    cout << "Обратный порядок: ";
    for (auto x : rev) {
        cout << x << " ";
    }
}