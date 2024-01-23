#include <array>
#include <iostream>
#include <vector>
#include "elementFromChain.hpp"

using namespace std;

#ifndef CHAINEDLIST_HPP_
#define CHAINEDLIST_HPP_

class ChainedList
{
	private:
		elementFromChain* firstElement;
		elementFromChain* lastElement;
		int size;

	public:
		ChainedList(int initialValue);
		virtual ~ChainedList();

		int getSize();
		bool checkIfContainsValue(int searchedValue);
		void addElement(int newValue);
		void deleteElement(int oldValue);
		void displayAllElements();
		int getIndexOfElement(int searchedValue);
};

#endif /* CHAINEDLIST_HPP_ */
