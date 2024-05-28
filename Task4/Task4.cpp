#include <iostream>
using namespace std;

// Структура узла списка
struct Node {
    int data;        // значение узла
    Node* next;      // указатель на следующий узел
    Node(int value) : data(value), next(nullptr) {}  // конструктор узла
};

// Функция для добавления элемента в конец списка
void append(Node*& head, int value) {
    if (!head) {
        head = new Node(value);  // если список пуст, создаем новый узел как голову списка
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;  // переходим к последнему узлу списка
    }
    current->next = new Node(value);  // добавляем новый узел в конец списка
}

// Функция для проверки, является ли число простым
bool isPrime(int number) {
    if (number <= 1) return false;  // числа меньше или равные 1 не являются простыми
    if (number <= 3) return true;   // числа 2 и 3 являются простыми
    if (number % 2 == 0 || number % 3 == 0) return false;  // кратные 2 или 3 не являются простыми
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;  // проверка делимости на i и i+2
    }
    return true;  // если число не делится на вышеуказанные числа, оно является простым
}

// Функция для подсчета количества простых чисел в списке
int countPrimes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current) {
        if (isPrime(current->data)) {
            count++;  // увеличиваем счетчик, если текущий элемент является простым
        }
        current = current->next;  // переходим к следующему узлу
    }
    return count;  // возвращаем общее количество простых чисел
}

// Функция для вставки числа после узла
void insertAfter(Node* prevNode, int value) {
    if (!prevNode) return;  // если предыдущий узел отсутствует, выходим из функции
    Node* newNode = new Node(value);  // создаем новый узел
    newNode->next = prevNode->next;  // следующий узел нового узла - это следующий узел предыдущего узла
    prevNode->next = newNode;  // следующий узел предыдущего узла - это новый узел
}

// Функция для вставки количества простых чисел между двумя четными элементами
void insertPrimeCountBetweenEvens(Node* head, int primeCount) {
    Node* current = head;
    while (current && current->next) {
        if (current->data % 2 == 0 && current->next->data % 2 == 0) {
            insertAfter(current, primeCount);  // вставляем количество простых чисел между двумя четными элементами
            current = current->next; // пропускаем вставленный узел, чтобы избежать бесконечного цикла
        }
        current = current->next;  // переходим к следующему узлу
    }
}

// Функция для вывода списка
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";  // выводим данные текущего узла
        current = current->next;  // переходим к следующему узлу
    }
    cout << endl;  // добавляем перевод строки после вывода списка
}

// Функция для удаления списка и освобождения памяти
void deleteList(Node*& head) {
    Node* current = head;
    Node* next = nullptr;
    while (current) {
        next = current->next;  // сохраняем указатель на следующий узел
        delete current;  // удаляем текущий узел
        current = next;  // переходим к следующему узлу
    }
    head = nullptr;  // обнуляем голову списка после удаления всех узлов
}
int main() {
    setlocale(0, "");

    Node* head = nullptr;
    int value;

    // Ввод значений до нуля
    cout << "Введите последовательность целых чисел, заканчивающуюся нулем:" << endl;
    while (cin >> value && value != 0) {
        append(head, value);
    }

    // Вывод исходного списка
    cout << "Исходный список:" << endl;
    printList(head);

    // Подсчет количества простых чисел
    int primeCount = countPrimes(head);

    // Вставка количества простых чисел между двумя четными элементами
    insertPrimeCountBetweenEvens(head, primeCount);

    // Вывод измененного списка
    cout << "Измененный список:" << endl;
    printList(head);
    cout << "Количество простых чисел: " << primeCount << endl;
    // Очистка памяти
    deleteList(head);
    return 0;
}
/*Дана последовательность целых чисел. Маркер конца ввода - цифра ноль. Сформировать однонаправленный список на основе данной последовательности. Вставить количество простых элементов последовательности между двумя четными элементами*/