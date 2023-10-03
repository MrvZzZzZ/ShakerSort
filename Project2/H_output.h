#pragma once
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <io.h>

using namespace std;

void saveTheArray(int* array, int sizeArray);
string Check_string();
bool Is_valid_filename(string& Filename);
bool Is_only_read(string Filename);
bool Is_file_exists(string Filename);

