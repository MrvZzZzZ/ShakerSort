#include "Sort.h"
#include "Menu.h"
#include "Output.h"

using namespace std;

enum FillingMethod
{
	ConsoleFillCommand = 1,
	FileFillCommand = 2
};

bool IsFileExistMenu(string FileName) //объеденить с аналогичной функцией в Output.cpp
{
	const char* path = FileName.c_str();

	if (!_access(path, 0)) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void FillMassiveFromFile(int*& numbers, int& sizeArray)
{
	string userInputPath;
	ifstream file;
	int separatorCounter = 0;

	cout << "Введите путь файла:" << endl << "> ";
	cin >> userInputPath;

	while (!IsFileExistMenu(userInputPath))
	{
		cout << "Ошибка при открытии файла! Попробуйте ввести путь снова." << endl << "> ";
		cin >> userInputPath;
	}

	file.open(userInputPath);
	cout << "Файл успешно открыт!" << endl;

	while (!file.eof())
	{
		if ((separatorCounter = file.get()) == ' ' || separatorCounter == EOF)
		{
			sizeArray++;
		}
	}

	file.clear();
	file.seekg(0);
	numbers = new int[sizeArray];

	for (int i = 0; i < sizeArray; i++)
	{
		file >> numbers[i];
	}
}

void FillMassiveFromConsole(int*& numbers, int& sizeArray)
{
	cout << "Введите размер массива:" << endl << ">";
	cin >> sizeArray;

	while (sizeArray <= 0)
	{
		cout << "Некорректное значение размера массива, введите другое число больше нуля" << endl << ">";
		cin >> sizeArray;
	}

	numbers = new int[sizeArray];

	for (int i = 0; i < sizeArray; i++)
	{
		numbers[i] = -100 + rand() % 201;
	}
}

void StartProgramm() 
{
	int sizeArray = 0;
	int userChoise = 0;
	int* numbers = nullptr;

	do
	{
		cout << "Выберите способ заполнения массива чисел:" << endl << "1 - Заполнить массив случайными числами в диапазоне от -100 до 100"
			<< endl << "2 - Заполнить массив значениями из файла" << endl << ">";
		cin >> userChoise;

		switch (userChoise) 
		{
			case ConsoleFillCommand:
				FillMassiveFromConsole(numbers, sizeArray);
				ShakerSort(numbers, sizeArray);
				break;

			case FileFillCommand:
				FillMassiveFromFile(numbers, sizeArray);
				ShakerSort(numbers, sizeArray);
				break;

			default:
				cout << "Такого пункта нет в меню, попробуйте еще раз" << endl;
				break;
		}
	} 
	while (userChoise != 1 && userChoise != 2);

	SaveArray(numbers, sizeArray);
	DeleteArray(numbers);
}

void DeleteArray(int*& numbers)
{
	delete[] numbers;
	numbers = nullptr;
}