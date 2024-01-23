#ifndef STRUCTURECHAIN_HPP_
#define STRUCTURECHAIN_HPP_

struct elementFromChain
{
	int currentValue;
	elementFromChain* pointerToPreviousValue;
	elementFromChain* pointerToNextValue;
};

#endif /* STRUCTURECHAIN_HPP_ */
