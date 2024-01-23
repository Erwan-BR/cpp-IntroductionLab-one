#include <string>
#include <iostream>

#include "Person.hpp"

using namespace std;

#ifndef QUESTION2_TEMPORARYTEACHER_HPP_
#define QUESTION2_TEMPORARYTEACHER_HPP_

class TemporaryTeacher : public Person
{
	public:
		TemporaryTeacher(int id, string name, string address, string domain);
		TemporaryTeacher();
		virtual ~TemporaryTeacher();
};

#endif /* QUESTION2_TEMPORARYTEACHER_HPP_ */
