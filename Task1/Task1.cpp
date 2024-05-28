#include <iostream>
#include <vector>
using namespace std;

int main()
{
	setlocale(0, "");
	//сид для случайного числа = значение в миллисекундах с 01.01.1970
	srand(time(NULL));
	//создаем вектор чисел
	vector<int> numbers;
	
	//среднее арифметическое
	double average = 0;
	
	//добавляем случайное число в вектор 10 раз
	for (int i = 0; i < 10; i++)
	{
		numbers.push_back(rand() % 100);
		//добавляем число в среднее арифметическое
		average += numbers[i];
		cout << numbers[i] << "\t";
	}
	//затем поделим сумму чисел на размер вектора
	average /= numbers.size();
	//сумма позиций элементов вектора, которые больше среднего арифметического
	int sumOfPositions = 0;
	
	for (int i = 0; i < numbers.size(); i++)
	{
		//если число больше среднего, добавляем позицию числа в сумму позиций
		if (numbers[i] > average) {
			sumOfPositions += i;
		}
	}
	cout << "\nСреднее арифметическое: " << average << endl;
	cout << "Сумма позиций элементов вектора, больших среднего арифметического:" << sumOfPositions << endl;
}