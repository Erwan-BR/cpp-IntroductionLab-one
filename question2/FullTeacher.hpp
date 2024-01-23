#include <string>
#include <iostream>

#include "Person.hpp"

using namespace std;

#ifndef QUESTION2_FULLTEACHER_HPP_
#define QUESTION2_FULLTEACHER_HPP_

class FullTeacher : public Person
{
	public:
		FullTeacher(int id, string name, string address, string domain);
		FullTeacher();
		virtual ~FullTeacher();
};

#endif /* QUESTION2_FULLTEACHER_HPP_ */
