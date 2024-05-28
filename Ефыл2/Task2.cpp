#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//функция для вычисления количества элементов в векторе, равных elem
int countOfElements(vector<int> numbers, int elem) {
	int count = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == elem) {
			count++;
		}
	}
	return count;
}

int main()
{
	setlocale(0, "");
	//открываем файл f для чтения
	ifstream fin("f");
	
	//если файл не найден, выводим соответствующую надпись
	if (!fin.is_open()) {
		cout << "Файл не найден.";
	}
	vector<int> numbers;
	string stringNum;
	//цикл до конца файла
	while (!fin.eof())
	{	//чтение строки в stringNum до тех пор, пока не встретит пробел
		getline(fin, stringNum, ' ');
		//если прочитанная строка пуста - пропускаем итерацию цикла
		if (stringNum.empty()) continue;
		//stoi => String TO Int, перевод из строки в число
		int number = stoi(stringNum);
		//добавляем элемент в массив numbers
		numbers.push_back(stoi(stringNum));	
	}
	//массив с уникальными значениями
	vector<int> uniqueNumbers;
	for (int i = 0; i < numbers.size(); i++)
	{	//если содержит только один элемент, то добавляем число в уникальное
		if(countOfElements(numbers, numbers[i])==1)
			uniqueNumbers.push_back(numbers[i]);
	}
	//закрываем стрим
	fin.close();

	//открываем файл для записи
	ofstream fout("o");
	//записываем уникальные значения в вектор uniqueNumbers
	for (int i = 0; i < uniqueNumbers.size(); i++)
	{
		fout << uniqueNumbers[i] << ' ';
	}
	//закрываем стрим
	fout.close();
}