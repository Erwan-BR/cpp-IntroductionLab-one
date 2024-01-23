#include "main.hpp"

int main()
{
	// Creating some students.
	Student firstStudent = Student(1, "Marc", "M", 20);
	Student secondStudent = Student(2, "Julie", "F", 30);
	Student thirdStudent = Student(3, "Philippe", "M", 40);

	// Creating a student class.
	Students studentsClass ;

	cout << "An empty class has been created !" << endl;

	// Adding those student to the class.
	studentsClass.addStudent(firstStudent);
	studentsClass.addStudent(secondStudent);
	studentsClass.addStudent(thirdStudent);

	cout << endl << "Three students have been added to the class. Let's take a look:" << endl;

	// Display all students from the class in the terminal.
	studentsClass.printStudents();


	// Sort the student of the list.
	studentsClass.sortStudentByName();

	cout << endl << "The students have been sorted alphabetically. Here is the sorted list:" << endl;

	// Display all students (sorted) from the class in the terminal.
	studentsClass.printStudents();


	// Modifying information of Marc, and a student that is not in the list
	studentsClass.updateStudentInformation(3, "Antoine", "", -1);
	studentsClass.updateStudentInformation(7, "Joker", "", -1);

	cout << endl << "A student from the class changed is name, and another one tried to do so but he is not in the class! " ;
	cout << "Here is the modified list :" << endl ;

	studentsClass.printStudents();


	// Sort the student of the list.
	studentsClass.sortStudentByName();

	cout << endl << "After the name change of Philippe, we have to ordre the class again!" << endl;

	// Display all students (with the modification) from the class in the terminal.
	studentsClass.printStudents();


	// Adding some elements to the class thanks to another file.
	studentsClass.readStudentsDataFromTXT("students_input.txt");

	cout << endl << "A lot of student joined the class thanks to an input file. Here is the new list of student:" << endl;

	// Display all students (with the new students) from the class in the terminal.
	studentsClass.printStudents();


	// Writing all out class into an output file.
	studentsClass.writeStudentsDataToTXT("students_output.txt");

	cout << endl << "Before leaving the terminal, we have to save all of our data. Let's keep them in an output file!" << endl;
   return 0;
}
