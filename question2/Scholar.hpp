#include <string>
#include <iostream>

#include "Person.hpp"

using namespace std;

#ifndef QUESTION2_SCHOLAR_HPP_
#define QUESTION2_SCHOLAR_HPP_

class Scholar : public Person
{
	public:
		Scholar(int id, string name, string address, string domain);
		Scholar();
		virtual ~Scholar();
};

#endif /* QUESTION2_SCHOLAR_HPP_ */
