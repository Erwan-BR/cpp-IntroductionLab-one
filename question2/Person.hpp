#include <string>
#include <iostream>

using namespace std;

#ifndef QUESTION2_PERSON_HPP_
#define QUESTION2_PERSON_HPP_

class Person
{
	protected:
		int id;
		string name;
		string address;
		string domain;

		// Scholar, FullTeacher or TemporaryTeacher
		string personCategory;

		// Speciality, SearchingField, TeachingField
		string nameOfStudyCategory;

	public:
		Person(int id, string name, string address, string domain);
		Person();
		virtual ~Person();

		// Getter
		int getId();
		string getName();
		string getAddress();
		string getDomain();
		string getPersonCategory();
		string getNameOfStudyCategory();

		// Setter
		void setId(int id);
		void setName(string name);
		void setAddress(string address);
		void setDomain(string domain);

};

#endif /* QUESTION2_PERSON_HPP_ */
