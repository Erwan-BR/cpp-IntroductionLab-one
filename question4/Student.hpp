#include <array>
#include <iostream>
#include <vector>

using namespace std;

#ifndef QUESTION4_STUDENT_HPP_
#define QUESTION4_STUDENT_HPP_

class Student
{
	private:
		int id;
		string name;
		string sex;
		int age;

	public:
		Student(int id, string name, string sex, int age);
		virtual ~Student();

		// Defining an operator which will helps us to sort elements.
		bool operator<(Student& secondStudent);

		// Getter
		int getId();
		string getName();
		string getSex();
		int getAge();

		// Setter
		void setId(int id);
		void setName(string name);
		void setSex(string sex);
		void setAge(int age);
};

#endif /* QUESTION4_STUDENT_HPP_ */
