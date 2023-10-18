#pragma once
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <io.h>

using namespace std;

void SaveArray(int* array, int sizeArray);
string GetString();
bool IsValidFilename(string& Filename);
bool IsReadOnly(string Filename);
bool IsFileExist(string Filename);

