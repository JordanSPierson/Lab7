// Lab7-<pierso5>.cpp
// Lab 7 

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::cin;
using std::endl;

#include "winTimer.h"
#include "RandomUtilities.h"
#include "ContainerPrinting.h"

int main()
{
	cout << "Enter size for numbers: ";
	int n = 0;
	cin >> n;
	if (n <= 0)
	{
		//break;
	}
	cout << "Enter seed for rand: ";
	unsigned int seed;
	cin >> seed;
	srand(seed);

	// Construct a sorted list of numbers
	Timer get;
	get.start();

	vector<double> numbers = getNums(n, -n, n);
	vector<double> numbers1 = getNums(n, -n, n);
	vector<double> numbers2 = getNums(n, -n, n);
	vector<double> numbers3 = getNums(n, -n, n);
	vector<double> numbers4 = getNums(n, -n, n);
	vector<double> numbers5 = getNums(n, -n, n);

	get.stop();
	cout << "Constructed in " << get() << " seconds"
		<< endl;

	bubbleSort(numbers, numbers.size());


	if (n < 10)
		cout << numbers << endl << endl;
}

vector<double>
getNums(size_t listSize, double minNum, double maxNum)
{
	vector<double> theList;
	for (size_t i = 0; i < listSize; ++i)
	{
		theList.push_back(randReal(minNum, maxNum));
	}

	//sort(begin(theList), end(theList));

	return theList;
}

// BubbleSort function taken from:
// https://www.geeksforgeeks.org/cpp-program-for-bubble-sort/
//
void bubbleSort(vector<double> arr, int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
}

void swap(double *xp, double *yp)
{
	double temp = *xp;
	*xp = *yp;
	*yp = temp;
}