#include <string>
#include <iostream>
#include <vector>

#include "Person.hpp"
#include "FullTeacher.hpp"
#include "Scholar.hpp"
#include "TemporaryTeacher.hpp"

using namespace std;

#ifndef QUESTION2_UNIVERSITY_HPP_
#define QUESTION2_UNIVERSITY_HPP_

class University
{
	private:
		vector<Person*> people;

	public:
		University();
		virtual ~University();
		void addPerson(string personCategory, int id, string name, string address, string domain);
		void addPerson(Person* newPerson);
		void displayAllPerson();

		// Getter
		vector<Person*> getPeople();
};

#endif /* QUESTION2_UNIVERSITY_HPP_ */
