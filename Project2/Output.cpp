#include "H_output.h"

enum _bool { True_ = 1, False_ = 2 };

int Check_int()
{
	int Input = 0;
	cin >> Input;
	while (cin.fail())
	{
		cout << "������������ ����. ��������� ������� >>" << endl;
		cin.clear();
		while (getchar() != '\n');
		cin >> Input;
	}
	while (getchar() != '\n');
	return Input;
}

string Check_string()
{
	string Input;
	while (true)
	{
		cin >> Input;

		regex Pattern_the_empoty_input("(\\s*)");

		// - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		if (regex_match(Input, Pattern_the_empoty_input) == false)
		{
			regex Pattern_the_correct_symble("^[�-��-߸�a-zA-Z0-9/:._ ]+$");

			// - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			if (regex_match(Input, Pattern_the_correct_symble) == true)
			{
				regex Pattern_of_allowed_names("\\b(con|aux|prn|com|lpt|nul)\\b((\\.)*(\\w)*)*");

				for (int i = NULL; i < Input.size(); i++) Input[i] = tolower(Input[i]);

				// - // - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				if (regex_match(Input, Pattern_of_allowed_names) == false) return Input;

				// - // - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				else cout << "������: �� ����� ����������������� ���. ��������� ������� �����." << endl;
			}

			// - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
			else cout << "������: �� ����� ����������� ������. ��������� ������� �����." << endl;
		}
		// - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		else  cout << "������: �� �������� ���� ������. ��������� ������� �����." << endl;
	}
}

bool Is_valid_filename(string& Filename) 
{
	regex pattern(".+\\.txt$");
	return regex_match(Filename, pattern);
}

bool Is_only_read(string Filename)
{
	if (_access(Filename.c_str(), 2)) return false;
	else return true;
}

bool Is_file_exists(string Filename)
{
	if (!_access(Filename.c_str(), 0)) return true;
	else return false;
}

void saveTheArray(int* Array, int sizeArray)
{
	ofstream file;
	string filename;
	bool isFileCorrect = true;
	do
	{
		isFileCorrect = true;
		cout << "������� ��� �����: ";
		filename = Check_string();
		// - / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		if (!Is_valid_filename(filename))
		{
			cout << "������: �������� ������ ����� - " << filename << endl;
			isFileCorrect = false;
			continue;
		}

		// - / - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
		if (!Is_file_exists(filename))
		{
			int Creat_the_new_file = NULL;
			bool Choise_entered = false;
			do
			{
				cout << "��������: ����� �� ����������! ������� ������� ����� ���� � ������ ������?" << endl << "1 - ��." << endl << "2 - ���." << endl;
				Creat_the_new_file = Check_int();

				// - // - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				if (Creat_the_new_file == True_) { file.open(filename); file.close(); Choise_entered = true; }

				// - // - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				else if (Creat_the_new_file == False_) Choise_entered = true;

				// - // - // - // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
				else { cout << "������: ������������ ����! ��������� ������� �����." << endl; system("pause"); }
			} while (!Choise_entered);

			if (Creat_the_new_file == False_) continue;
		}

		if (!Is_only_read(filename))
		{
			cout << "������: ���� � ������ ������. ������ ���������� - " << filename << endl;
			isFileCorrect = false;
		}
	} while (!isFileCorrect);

	file.open(filename);

	for (int i = NULL; i < sizeArray; i++) file << Array[i] << " ";

	file.close();


}

