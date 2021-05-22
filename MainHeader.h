#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

#include "ArrayToSort.h"
#define rcastcc reinterpret_cast<const char*>
#define rcastc reinterpret_cast<char*>

using namespace std;

static const int  NUM_MAX_SIZE = 1000;

void saveDate(ostream& out);
void getNumbersAndFilesNames(int& n, int& k, string& inputFileName, string& outputFileName);
void loadArrayFromFile(int* arrayToSort, int n, istream& in);