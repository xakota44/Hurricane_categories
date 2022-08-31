//Joseph Coleman
//COP2000.0M1
//This program will read from an input file and output categorized results

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;
using std::string;
ifstream inputFile;

class Sort
{
private:
	string name[38];
	int cat[38] = {};
	string iname;
	int icat = 0;
	int size = 38;

public:
	void read();
	void swap(string& a, string& b);
	void swapCat(int& a, int& b);
};


/************Method Definitions********************/

void Sort::read()
{
	inputFile.open("FloridaHurricanes.txt");

	if (inputFile.is_open())
	{
		int i = 0;
		int a = 0;
		
		while (inputFile >> iname >> icat)
		{
				name[i++] = iname;

				cat[a++] = icat;

		}

	}
	//***************************bubbleSort***********************
	//const int size = 38;
	int index = 0;
	
	bool madeAswap = true;      // This allows the for loop to begin iterating

		for (int maxElement = size - 1; maxElement > 0 && madeAswap; maxElement--)
		{
		madeAswap = false;       // No swaps have occurred yet on this pass
		
			for (int index = 0; index < maxElement; index++)
			{
				if (name[index] > name[index + 1])
				{
				//swap
					swap(name[index], name[index + 1]);
					swapCat(cat[index], cat[index + 1]);
					madeAswap = true;
				}
			}
		}

		cout << "Florida Major Hurricanes\n\n" << "Sorted by hurricane name:\n\n" << "Name     " << "Category\n";

	for (int i = 0; i < 38; i++)
	{
		cout << setw(12) << std::left << name[i] << cat[i] << "\n";
	}

	cout << "\nEnd of results\n\n";

	inputFile.close();

}


void Sort::swap(string &a, string &b)
{
	string temp = a;
	     a = b;
	     b = temp;
}

void Sort::swapCat(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	Sort x;

	x.read();



	return 0;
}