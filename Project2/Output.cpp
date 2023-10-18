#include "Output.h"

enum CreateNewFile 
{ 
	CreateNewFileCommand = 1,
	SkipCreateFileCommand = 2 
};

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int GetInt()
{
	int userInput = 0;
	cin >> userInput;

	while (cin.fail())
	{
		cout << "Некорректный ввод. Повторите попытку >>" << endl;
		cin.clear();

		while (getchar() != '\n');
		
		cin >> userInput;
	}

	while (getchar() != '\n');

	return userInput;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
string GetString()
{
	string userInput;
	while (true)
	{
		cin >> userInput;
		regex emptyInputPattern("(\\s*)");

		if (regex_match(userInput, emptyInputPattern) == false)
		{
			regex correctSymbolPattern("^[а-яА-ЯёЁa-zA-Z0-9/:._ ]+$");

			if (regex_match(userInput, correctSymbolPattern) == true)
			{
				regex allowedNamesPattern("\\b(con|aux|prn|com|lpt|nul)\\b((\\.)*(\\w)*)*");

				for (int i = NULL; i < userInput.size(); i++)
				{
					userInput[i] = tolower(userInput[i]);
				}

				if (regex_match(userInput, allowedNamesPattern) == false)
				{
					return userInput;
				}
				else cout << "Ошибка: вы ввели зарезервированное имя. Повторите попытку ввода." << endl;
			}
			else cout << "Ошибка: вы ввели запрещенный символ. Повторите попытку ввода." << endl;
		}
		else  cout << "Ошибка: вы оставили ввод пустым. Повторите попытку ввода." << endl;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="Filename"></param>
/// <returns></returns>
bool IsValidFilename(string& filename) 
{
	regex pattern(".+\\.txt$");
	return regex_match(filename, pattern);
}

bool IsReadOnly(string filename)
{
	if (_access(filename.c_str(), 2))
	{
		return false;
	}
	else return true;
}

bool IsFileExist(string filename)
{
	if (!_access(filename.c_str(), 0))
	{
		return true;
	}
	else return false;
}

void SaveArray(int* Array, int sizeArray)
{
	ofstream file;
	string filename;
	bool isFileCorrect = true;

	do
	{
		isFileCorrect = true;
		cout << "Введите имя файла: ";
		filename = GetString();

		if (!IsValidFilename(filename)) //что ожидается для вывода ошибки
		{
			cout << "Ошибка: Неверный формат файла - " << filename << endl;
			isFileCorrect = false;
			continue;
		}

		if (!IsFileExist(filename)) //что ожидается для входа в if
		{
			int userInput = NULL;
			bool isChoiceMade = false;

			do
			{
				cout << "Внимание: файла не существует! Желаете создать новый файл с данным именем?" << endl << "1 - Да." << endl << "2 - Нет." << endl;
				userInput = GetInt();

				if (userInput == CreateNewFileCommand) 
				{ 
					file.open(filename); 
					file.close();
					isChoiceMade = true;
				}
				else if (userInput == SkipCreateFileCommand)
				{
					isChoiceMade = true;
				}
				else 
				{ 
					cout << "Ошибка: некорректной ввод! Повторите попытку ввода." << endl; 
					system("pause");
				}
			} 
			while (!isChoiceMade);

			if (userInput == SkipCreateFileCommand) 
				continue;
		}

		if (!IsReadOnly(filename)) //что ожидается для вывода ошибки
		{
			cout << "Ошибка: Файл в режиме чтения. Запись невозможна - " << filename << endl;
			isFileCorrect = false;
		}
	}
	while (!isFileCorrect);

	file.open(filename);

	for (int i = NULL; i < sizeArray; i++)
	{
		file << Array[i] << " ";
	}

	file.close();
}

