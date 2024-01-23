#include "main.hpp"

using namespace std;

int main()
{
	// Instantiation of the variable that will contain the min and the max value.
	int arrayOutputValues[] = {0, 0};

	// Instantiation of an example of a tab.
	vector<int> inputTab = {-5, -10, -7, 0, 8, -9, 6, 14};

	// Writing in arrayOutputValues the min and max values.
	getMinAndMaxValuesFromTable(inputTab, arrayOutputValues);

	// Writing the values inside the table in the terminal for the user.
	cout << "Values on the table are :" << endl;
	for (int value: inputTab)
	{
		cout << value << " ; ";
	}
	cout << endl ;

	// Writing in the terminal the min and max values found.
	cout << "The min value of the example tab is " << arrayOutputValues[0] << "\n";
	cout << "The max value of the example tab is " << arrayOutputValues[1] << "\n";

	// Writing two assertion to check if the values are correct.
	assert(arrayOutputValues[0] == -10);
	assert(arrayOutputValues[1] == 14);

	return 0;
}

void getMinAndMaxValuesFromTable(vector<int> inputTab, int arrayOutputValues[])
{
	// Setting min and max to the first value.
	int minValue = inputTab[0];
	int maxValue = inputTab[0];

	// Iterating among values of the inputTab.
	for (int currentValue: inputTab)
	{
		// Checking if the current value is the lowest seen.
		if (currentValue < minValue)
			minValue = currentValue;

		// Checking if the current value is the greatest seen.
		else if (currentValue > maxValue)
			maxValue = currentValue;
	}
	// Writing the retrieved information in the output tab.
	arrayOutputValues[0] = minValue;
	arrayOutputValues[1] = maxValue;
}
