#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Структура узла дерева
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Функция для вставки нового элемента в дерево
Node* insert(Node* root, int value) {
    if (!root) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Функция для проверки, является ли число простым
bool isPrime(int number) {
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

// Функция для проверки, является ли узел листом
bool isLeaf(Node* node) {
    return node && !node->left && !node->right;
}

// Функция для подсчета количества простых листьев
int countPrimeLeaves(Node* root) {
    if (!root) return 0;
    if (isLeaf(root) && isPrime(root->data)) {
        return 1;
    }
    return countPrimeLeaves(root->left) + countPrimeLeaves(root->right);
}

// Функция для нахождения суммы элементов в диапазоне [a; b]
int sumInRange(Node* root, int a, int b) {
    if (!root) return 0;
    int sum = 0;
    if (root->data >= a && root->data <= b) {
        sum += root->data;
    }
    if (root->data > a) {
        sum += sumInRange(root->left, a, b);
    }
    if (root->data < b) {
        sum += sumInRange(root->right, a, b);
    }
    return sum;
}

// Функция для удаления дерева и освобождения памяти
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Функция для вывода дерева на консоль
void printTree(Node* root, int space = 0, int indent = 4) {
    if (root == nullptr) {
        return;
    }
    space += indent;
    printTree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) {
        cout << " ";
    }
    cout << root->data << "\n";
    printTree(root->left, space);
}

int main() {
    setlocale(0, "");

    Node* root = nullptr;
    int value;

    // Ввод значений до нуля
    cout << "Введите последовательность целых чисел, заканчивающуюся нулем:" << endl;
    while (cin >> value && value != 0) {
        root = insert(root, value);
    }

    // Вывод дерева
    cout << "Двоичное дерево поиска:" << endl;
    printTree(root);

    // Подсчет количества простых листьев
    int primeLeafCount = countPrimeLeaves(root);
    cout << "Количество простых листьев: " << primeLeafCount << endl;

    // Если количество простых листьев четное, находим сумму элементов в диапазоне [a; b]
    if (primeLeafCount % 2 == 0) {
        int a, b;
        cout << "Введите значения a и b для диапазона [a; b]:" << endl;
        cin >> a >> b;
        int rangeSum = sumInRange(root, a, b);
        cout << "Сумма элементов в диапазоне [" << a << "; " << b << "]: " << rangeSum << endl;
    }

    // Очистка памяти
    deleteTree(root);
    return 0;
}
