#include "ChainedList.hpp"

ChainedList::ChainedList(int initialValue) :
	size(1)
{
	elementFromChain* firstElementFromChain = new elementFromChain;
	firstElementFromChain->currentValue = initialValue;
	firstElementFromChain->pointerToPreviousValue = nullptr;
	firstElementFromChain->pointerToNextValue = nullptr;

	this->firstElement = firstElementFromChain;
	this->lastElement = firstElementFromChain;
}

ChainedList::~ChainedList()
{
	// Getting the first element before iterating.
	elementFromChain* currentElement = this->firstElement;

	elementFromChain* nextElement = nullptr;

	// While the currentElement is not a nullpointer, we have to delete this element.
	while (currentElement != nullptr)
	{
		// Retrieving the nextElement.
		nextElement = currentElement->pointerToNextValue;

		// Delete the currentElement which is useless now.
		delete currentElement;

		// Taking the next element to loop again (if needed).
		currentElement = nextElement;
	}
}

int ChainedList::getSize()
{
	return this->size;
}

bool ChainedList::checkIfContainsValue(int searchedValue)
{
	return getIndexOfElement(searchedValue) != -1;
}

void ChainedList::addElement(int newValue)
{
	// We need to check if the chainedList is empty.
	// If it's the case, we just create a new element which is the first (and the last).
	if (this->size==0)
	{
		// Creating the element and giving to the structure the important informations.
		elementFromChain* newElement = new elementFromChain;
		newElement->currentValue = newValue;
		newElement->pointerToPreviousValue = nullptr;
		newElement->pointerToNextValue = nullptr;

		// Update class information.
		this->firstElement = newElement;
		this->lastElement = newElement;
		this->size++;
	}

	// Else, we add an element only if it is not already in the chained list.
	else if (!this->checkIfContainsValue(newValue))
	{
		// Instantiation of the new element.
		elementFromChain* newElement = new elementFromChain;
		newElement->currentValue = newValue;
		newElement->pointerToPreviousValue = this->lastElement;
		newElement->pointerToNextValue = nullptr;

		// Setting the pointer to the next value on the element which is not the last one anymore.
		this->lastElement->pointerToNextValue = newElement;

		// Setting the new last element
		this->lastElement = newElement;

		// When adding a new element, the size increase by one.
		this->size++;
	}
}

void ChainedList::deleteElement(int oldValue)
{
	int indexElementToDelete = this->getIndexOfElement(oldValue);
	// We have to delete an element only if this element is on the chained list.

	// First case : the element to delete is the first one.
	if (indexElementToDelete==0)
	{
		// First case : there is no others value in the chained list.
		if (this->size==1)
		{
			// Setting the first and last pointer to null.
			this->firstElement = nullptr;
			this->lastElement = nullptr;

			// Now the size is null because there is no value i the chained list.
			this->size = 0;
		}
		// Second case : there is some others elements in the chained list.
		else
		{
			// Retrieve the information concerning the first ahnd the second element
			elementFromChain* elementToDelete = this->firstElement;
			elementFromChain* newFirstElement = elementToDelete->pointerToNextValue;

			// The new first element must point to nothing before.
			newFirstElement->pointerToPreviousValue = nullptr;
			this->firstElement = newFirstElement;

			// Delete the element to free memory.
			delete elementToDelete;
			this->size--;
		}
	}
	// Second case : the element to delete is the last one. Ir cannot be the only, otherwise it would have be in the previous case (index=0, size=1
	else if (indexElementToDelete == this->size - 1)
	{
		elementFromChain* elementToDelete = this->lastElement;
		elementFromChain* newLastElement = elementToDelete->pointerToPreviousValue;
		newLastElement->pointerToNextValue = nullptr;
		this->lastElement = newLastElement;

		delete elementToDelete;
		this->size -= 1;
	}

	else if (indexElementToDelete != -1)
	{
		elementFromChain* currentElement = this->firstElement->pointerToNextValue;

		// We have to go to the right index to get the value.
		for (int index = 1; index < indexElementToDelete; index++)
		{
			currentElement = currentElement->pointerToNextValue;
		}
		// Now, the currentElement is the element to delete. We have to update the information of the previous and the next one.
		currentElement->pointerToPreviousValue->pointerToNextValue = currentElement->pointerToNextValue;
		currentElement->pointerToNextValue->pointerToPreviousValue = currentElement->pointerToPreviousValue;

		// Delete the useless structure to free memory.
		delete currentElement;
		this->size--;
	}
}

void ChainedList::displayAllElements()
{

	// If the chained list is empty, we display the information to the user.
	if (this->size == 0)
		cout << "There is nothing to display !" << endl;
	else
	{
		// Index to know the position easily.
		int index = 0;

		// currentElementFromChain is used to loop.

		elementFromChain* currentElementFromChain = this->firstElement;

		// Looping while the element is not null.
		while (currentElementFromChain != nullptr)
		{
			// Printing some information in the terminal.
			cout << "Element n°" << index << ". Current value: " << currentElementFromChain->currentValue << "\tPrevious address: " ;
			cout << currentElementFromChain->pointerToPreviousValue << "\tCurrent address: " << currentElementFromChain << "\tNext Address: " << currentElementFromChain->pointerToNextValue << endl;

			// Retrieve the next element.
			currentElementFromChain = currentElementFromChain->pointerToNextValue;

			// Update the index.
			index++;
		}
	}
}

int ChainedList::getIndexOfElement(int searchedValue)
{
	// The return value is -1 if the value is not in the chained list.
	int defaultValue = -1;

	// If there are some elements in the list, we will have to iterate from the first element to the last one.
	if (this->size != 0)
	{
		int indexOfCurrentPosition = 0;

		// Getting the informations from the first element
		elementFromChain* currentElementFromChain = this->firstElement;

		while (currentElementFromChain != nullptr)
		{
			if (currentElementFromChain->currentValue == searchedValue)
				return indexOfCurrentPosition;
			indexOfCurrentPosition++;
			currentElementFromChain = currentElementFromChain->pointerToNextValue;
		}
	}
	return defaultValue;
/*





		// Checking if the first element is the searched value.
		if (currentElementFromChain->currentValue == searchedValue)
		{
			returnValue = indexOfCurrentPosition;
		}
		// Else, we iterate on the next values starting by the 2nd one, then the 3rd, ...
		else
		{
			// Checking if there is a next value.
			// It will end at a moment because the chained list is not infinite.
			while (currentElementFromChain->pointerToNextValue != nullptr)
			{
				indexOfCurrentPosition++;
				// Getting the next element from the chained list.
				currentElementFromChain = currentElementFromChain->pointerToNextValue;

				// Checking if the current element is the searched value.
				if (currentElementFromChain->currentValue == searchedValue)
				{
					returnValue = indexOfCurrentPosition;
				}
			}
		}
	}
	return returnValue;*/
}

