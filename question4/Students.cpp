#include "Students.hpp"

Students::Students() :
studentList({})
{
}

Students::~Students()
{
}

void Students::addStudent(Student newStudent)
{
	// Iterating among all students. Needed because two students cannot have the same Id.
	for (Student& student : this->studentList)
	{
		// Checking if the id of the current student is the same as the id of the student that needs to be add.
		if (student.getId() == newStudent.getId())
		{
			// Prevent the user that two student with the same Id cannot be added to the same group. Should not happen.
			cout << "Two students with the same Id cannot be in the same students group." << endl;

			// Return void to avoid looping for nothing and to not add the student.
			return;
		}
	}

	// If this line is reached, it means that there is no student in this students class with this id.
	this->studentList.push_back(newStudent);
}

void Students::updateStudentInformation(int id, string name, string sex, int age)
{
	// Iterating among all students.
	for (Student& student : this->studentList)
	{
		// Checking if the current student has the good id.
		if (student.getId() == id)
		{
			// For each attribute, we check that the information needs to be update to avoid erasing it.
			if (name != "")
				student.setName(name);
			if (sex != "")
				student.setSex(sex);
			if (age != -1)
				student.setAge(age);

			// Return void to avoid looping for nothing.
			return;
		}
	}
}

void Students::deleteStudent(int id)
{
	// The offset is needed to know the 'index' of the element to delete.
	int currentOffset = 0;

	// Iterating among all students.
	for (Student& student : this->studentList)
	{
		// Checking if the current student has the good id.
		if (student.getId() == id)
		{
			// If it's the case, we can delete this student.
			this->studentList.erase(studentList.begin() + currentOffset);

			// Return void to avoid looping for nothing.
			return;
		}
		// Increasing the offset.
		currentOffset++;
	}
}

void Students::sortStudentByName()
{
	// Because I overwrite the operator < from the Student class by saying that < states only by looking at the name.
	// I can use the sort function on studentList which contains element from the Student class.
	sort(this->studentList.begin(), studentList.end());
}

void Students::printStudents()
{
	if (this->studentList.size() == 0)
	{
		cout << "No Student in the list !" << endl;
		return;
	}
	// Iterating among all students.
	for (Student& student : this->studentList)
	{
		// Writing in the terminal the information concerning the student.
		cout << "Id: " << student.getId() << "\tName: " << student.getName() ;
		cout << "\tSex: " << student.getSex() << "\tAge: " << student.getAge() << endl;
	}
}

void Students::readStudentsDataFromTXT(string intputFileName)
{
	// Instantiation of a fstream object which is a file.
	fstream readingFile;

	// Opening the file in reading mode.
	readingFile.open(intputFileName,ios::in);

	// Checking if the file is correctly opened.
	if (readingFile.is_open())
	{
		// Instantiation of a string that will represent the successive lines.
		string currentLine;

		// Looping while we can get the following line (while another exists in fact).
		while(getline(readingFile, currentLine))
		{
			// Call a private function that returns a Student from a line given by the input.
			this->addStudent(this->getStudentFromASingleLine(currentLine));
		}

		// Closing the file because we do not need it anymore.
		readingFile.close();
	}
}

void Students::writeStudentsDataToTXT(string outputFileName)
{
	// Instantiation of a fstream object which is a file.
	fstream writingFile;

	// Opening the file in reading mode.
	writingFile.open(outputFileName,ios::out);

	// Checking if the file is correctly opened.
	if (writingFile.is_open())
	{
		// Iterating among all students.
		for (Student& student : this->studentList)
		{
			// Writing in the terminal the textFile information concerning the current student.
			writingFile << student.getId() << "\t" << student.getName() << "\t" << student.getSex() << "\t" << student.getAge() << endl;
		}
		// Closing the file because we do not need it anymore.
		writingFile.close();
	}
}

Student Students::getStudentFromASingleLine(string inputLine)
{
	// inputLine looks like "1\tErwan\tM\t23\n"
	// Which represents ID Name Sex Age

	// Variables to retrieve from the line.
    int id, age;
    string name, sex;

    // Create the object that contains the information separated by the \t.
    stringstream data(inputLine);

    // Sending the information to the variables, in the right order.
    data >> id >> name >> sex >> age;

    // Creating a student which contains all information.
    Student newStudent = Student(id, name, sex, age);

	return newStudent;
}
