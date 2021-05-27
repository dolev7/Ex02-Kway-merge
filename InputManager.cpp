#include "MainHeader.h"

void getNumbersAndFilesNames(int& n, int& k, string& inputFileName, string& outputFileName)
{
	string errorName;

	cout << "Please enter the amount of numbers (n)" << endl;
	cin >> n;
	cout << "Please enter k parameter" << endl;
	cin >> k;
	if (n <= 0 || k <= 1)
	{
		throw (errorName = "n must be a positive number, k must be bigger than 1");
	}
	if (k > n)
	{
		throw (errorName = "k must be smaller or equal to n");
	}

	cout << "Please enter the input file name" << endl;
	cin >> inputFileName;
	cout << "Please enter the output file name" << endl;
	cin >> outputFileName;

}

void loadArrayFromFile(int* arrayToSort, int n, istream& in)
{
	string errorName;
	char numberReadFromFile[NUM_MAX_SIZE];
	char currentDigitFromFile = 0;
	int currentDigitIndex;
	for (int i = 0; i < n; i++)
	{
		currentDigitIndex = 0;
		currentDigitFromFile = 0;
		while (currentDigitFromFile != '\n')
		{
			in.read(rcastc(&currentDigitFromFile), sizeof(currentDigitFromFile));
			if (currentDigitFromFile == '-' && currentDigitIndex > 0)
			{
				throw (errorName = "- wasn't the first char");
			}

			//check that character frox text is expected
			if ((currentDigitFromFile < '0' || currentDigitFromFile > '9') && currentDigitFromFile != '\n' && currentDigitFromFile != '-')
			{
				throw (errorName = "A number in the file was invalid");
			}

			// in case of enter, mark the end of string
			if (currentDigitFromFile == '\n')
			{
				numberReadFromFile[currentDigitIndex] = '\0';
			}

			numberReadFromFile[currentDigitIndex] = currentDigitFromFile;
			currentDigitIndex++;
			if (in.peek() == EOF)
			{
				// check if EOF is sooner than expected
				if (i != n - 1)
				{
					throw (errorName = "there were fewer number in text file than n value");
				}
				else
				{
					numberReadFromFile[currentDigitIndex] = '\0';
					break;
				}
			}
		}

		arrayToSort[i] = atoi(numberReadFromFile);
	}

}