#include "H_output.h"


string Check_string()
{
	string Input;
	while (true)
	{
		getline(cin, Input);
		regex Pattern_the_empoty_input("(\\s*)");

		// - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		if (regex_match(Input, Pattern_the_empoty_input) == false)
		{
			regex Pattern_the_correct_symble("^[а-яА-ЯёЁa-zA-Z0-9/:._ ]+$");

			// - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			if (regex_match(Input, Pattern_the_correct_symble) == true)
			{
				regex Pattern_of_allowed_names("\\b(con|aux|prn|com|lpt|nul)\\b((\\.)*(\\w)*)*");

				for (int i = NULL; i < Input.size(); i++) Input[i] = tolower(Input[i]);

				// - // - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				if (regex_match(Input, Pattern_of_allowed_names) == false) return Input;

				// - // - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				else cout << "Ошибка: вы ввели зарезервированное имя. Повторите попытку ввода." << endl;
			}

			// - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			else cout << "Ошибка: вы ввели запрещенный символ. Повторите попытку ввода." << endl;
		}
		// - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		else  cout << "Ошибка: вы оставили ввод пустым. Повторите попытку ввода." << endl;
	}
}

bool Is_valid_filename(string& Filename) 
{
	regex pattern(".+\\.txt$");
	return regex_match(Filename, pattern);
}

bool Is_only_read(string Filename)
{
	if (_access(Filename.c_str(), 2)) return true;
	else return false;
}

bool Is_file_exists(string Filename)
{
	if (!_access(Filename.c_str(), 0)) return true;
	else return false;
}

void saveTheArray(int* array_)
{
	ofstream file;
	string filename;
	bool isFileCorrect = true;
	do
	{
		cout << "Введите имя файла: ";
		filename = Check_string();
		// - / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		if (!Is_valid_filename(filename))
		{
			cout << "Ошибка: Неверный формат файла - " << Filename_of_input_file[i] << endl;
			isFileCorrect = false;
		}

		// - / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		if (!Is_file_exists(filename)
		{
			cout << "Ошибка: Не существует файл - " << Filename_of_input_file[i] << endl;
				isFileCorrect = false;
		}

		if (!Is_only_read(filename)
		{
			cout << "Ошибка: Не существует файл - " << Filename_of_input_file[i] << endl;
				isFileCorrect = false;
		}
	} while (isFileCorrect)

	file.open(filename);

	for (int i = NULL; i < array_.size(); i++) file << array_[i] << " ";

	file.close();


}

