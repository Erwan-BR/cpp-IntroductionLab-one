#include <array>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>

#include "Student.hpp"

using namespace std;

#ifndef QUESTION4_STUDENTS_HPP_
#define QUESTION4_STUDENTS_HPP_

class Students
{
	private:
		vector<Student> studentList;

		Student getStudentFromASingleLine(string inputLine);

	public:
		Students();
		virtual ~Students();

		void addStudent(Student newStudent);
		void updateStudentInformation(int id, string name, string sex, int age);
		void deleteStudent(int id);
		void sortStudentByName();
		void printStudents();
		void readStudentsDataFromTXT(string intputFileName);
		void writeStudentsDataToTXT(string outputFileName);
};

#endif /* QUESTION4_STUDENTS_HPP_ */
