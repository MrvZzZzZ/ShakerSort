#include "Sort.h"
#include "TestData.h"
#include "H_output.h"

using namespace std;

bool File_Exists(string FileName) {
	const char* path = FileName.c_str();
	if (!_access(path, 0)) {
		return true;
	}
	else {
		return false;
	}
}

void LoadingTestData() {
	string path;
	ifstream file;
	string temp;
	int sizeArray = 0;
	int UserChoise = 0;
	int input = 0;
	int* arrayOfNumbers = nullptr;
	do {
		cout << "�������� ������ ���������� ������� �����:" << endl << "1 - ��������� ������ ���������� ������� � ��������� �� -100 �� 100"
			<< endl << "2 - ��������� ������ ���������� �� �����" << endl << ">";
		cin >> UserChoise;
		switch (UserChoise) {
		case 1:
			cout << "������� ������ �������:" << endl << ">";
			cin >> sizeArray;
			while (sizeArray <= 0) {
				cout << "������������ �������� ������� �������, ������� ������ ����� ������ ����" << endl << ">";
				cin >> sizeArray;
			}
			arrayOfNumbers = new int[sizeArray];
			for (int i = 0; i < sizeArray; i++) {
				arrayOfNumbers[i] = -100 + rand() % 201;
			}
			ShakerSort(arrayOfNumbers, sizeArray);
			break;
		case 2:
			cout << "������� ���� �����:" << endl << "> ";
			cin >> path;
			while (!File_Exists(path)) {
				cout << "������ ��� �������� �����! ���������� ������ ���� �����." << endl << "> ";
				cin >> path;
			}
			file.open(path);
			cout << "���� ������� ������!" << endl;
			while (!file.eof()) {
				if ((input = file.get()) == ' ' || input == EOF) { sizeArray++; }
			}
			file.clear();
			file.seekg(0);
			arrayOfNumbers = new int[sizeArray];
			for (int i = 0; i < sizeArray; i++) {
				file >> arrayOfNumbers[i];
			}
			ShakerSort(arrayOfNumbers, sizeArray);
			break;
		default:
			cout << "������ ������ ��� � ����, ���������� ��� ���" << endl;
			break;
		}
	} while (UserChoise != 1 && UserChoise != 2);
	saveTheArray(arrayOfNumbers, sizeArray);

	DeleteArray(arrayOfNumbers);
}

void DeleteArray(int*& numbers)
{
	delete[] numbers;
	numbers = nullptr;
}