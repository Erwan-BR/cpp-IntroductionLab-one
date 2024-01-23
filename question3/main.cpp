#include "main.hpp"

using namespace std;

int main()
{
	// Instantiation of an element of the class.
	ChainedList manipulationOfIntegers = ChainedList(10);

	// Checking if there is only one element.
	cout << "At the beginning, there is " << manipulationOfIntegers.getSize() << " value.\n";
	cout << "Here is the value of the table:\n" ;
	manipulationOfIntegers.displayAllElements();

	cout << "--------------------------------\n" ;

	// Adding some element to check if addNewElementToChainedList works properly.
	manipulationOfIntegers.addElement(5);
	manipulationOfIntegers.addElement(8);
	manipulationOfIntegers.addElement(7);
	manipulationOfIntegers.addElement(10);

	// Making some assertions to check if getIndexOfElement works properly.
	assert(manipulationOfIntegers.getIndexOfElement(5) == 1);
	assert(manipulationOfIntegers.getIndexOfElement(7) == 3);
	assert(manipulationOfIntegers.getIndexOfElement(8) == 2);
	assert(manipulationOfIntegers.getIndexOfElement(10) == 0);
	assert(manipulationOfIntegers.getIndexOfElement(15) == -1);

	// Checking if the size increase properly.
	assert(manipulationOfIntegers.getSize() == 4);

	// Display the obtained information.
	cout << "After adding some elements, there is " << manipulationOfIntegers.getSize() << " values.\n";
	cout << "Here are the values of the table:\n" ;
	manipulationOfIntegers.displayAllElements();

	// Trying to delete an element which is not in the chainedList to check if deleteElementFromChainedList works properly.
	cout << endl << "--------------------------------Deletion of 15--------------------------------" << endl << endl;
	manipulationOfIntegers.deleteElement(15);

	// Checking if information are still good.
	assert(manipulationOfIntegers.getIndexOfElement(15) == -1);
	assert(manipulationOfIntegers.getSize() == 4);

	// Display the obtained information.
	cout << "After trying to delete the element, there is " << manipulationOfIntegers.getSize() << " values.\n";
	cout << "Here are the values of the table:\n" ;
	manipulationOfIntegers.displayAllElements();

	// Trying to delete an element which is the first one of the chainedList to check if deleteElementFromChainedList works properly.
	cout << endl << "--------------------------------Deletion of 10--------------------------------" << endl << endl;

	manipulationOfIntegers.deleteElement(10);


	// Checking if information are still good.
	assert(manipulationOfIntegers.getIndexOfElement(10) == -1);
	assert(manipulationOfIntegers.getSize() == 3);

	// Display the obtained information.
	cout << "After deleting some elements, there is " << manipulationOfIntegers.getSize() << " values.\n";
	cout << "Here are the values of the table:\n" ;
	manipulationOfIntegers.displayAllElements();

	// Trying to delete an element which is the first one of the chainedList to check if deleteElementFromChainedList works properly.
	cout << endl << "--------------------------------Deletion of 5--------------------------------" << endl << endl;

	// Try to delete an element which is not the first or the last in the chainedList to check if deleteElementFromChainedList works properly.
	manipulationOfIntegers.deleteElement(5);

	// Checking if information are still good.
	assert(manipulationOfIntegers.getIndexOfElement(5) == -1);
	assert(manipulationOfIntegers.getSize() == 2);

	// Display the obtained information.
	cout << "After deleting some elements, there is " << manipulationOfIntegers.getSize() << " values.\n";
	cout << "Here are the values of the table:\n" ;
	manipulationOfIntegers.displayAllElements();

	// Trying to delete an element which is the last position in the chainedList to check if deleteElementFromChainedList works properly.
	cout << endl << "--------------------------------Deletion of 7--------------------------------" << endl << endl;
	manipulationOfIntegers.deleteElement(7);

	// Checking if information are still good.
	assert(manipulationOfIntegers.getIndexOfElement(7) == -1);
	assert(manipulationOfIntegers.getSize() == 1);

	// Display the obtained information.
	cout << "Is there 7 in the list ? " << manipulationOfIntegers.checkIfContainsValue(7) << "\n";
	cout << "After deleting some elements, there is " << manipulationOfIntegers.getSize() << " values.\n";
	cout << "Here are the values of the table:\n" ;
	manipulationOfIntegers.displayAllElements();


	// Trying to delete the only element of the chained list to check if everything works properly.
	cout << endl << "--------------------------------Deletion of 8--------------------------------" << endl << endl;
	manipulationOfIntegers.deleteElement(8);

	// Checking if information are still good.
	assert(manipulationOfIntegers.getIndexOfElement(8) == -1);
	assert(manipulationOfIntegers.getSize() == 0);

	// Display the obtained information.
	cout << "After deleting some elements, there is " << manipulationOfIntegers.getSize() << " values.\n";
	cout << "Here are the values of the table:\n" ;
	manipulationOfIntegers.displayAllElements();

	// Trying to add an element to an chained list to check if everything works properly.
	cout << endl << "--------------------------------Addition of 6--------------------------------" << endl << endl;
	manipulationOfIntegers.addElement(6);


	// Checking if information are still good.
	assert(manipulationOfIntegers.getIndexOfElement(6) == 0);
	assert(manipulationOfIntegers.getSize() == 1);

	// Display the obtained information.
	cout << "After adding an element to the chained list (which was empty), here are the values of the table:\n" ;
	manipulationOfIntegers.displayAllElements();

	/*ManipulateInt manipulationOfIntegers = ManipulateInt(10);
	manipulationOfIntegers.deleteElementFromChainedList(10);*/
	return 0;
}
