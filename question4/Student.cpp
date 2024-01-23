#include "Student.hpp"

Student::Student(int id, string name, string sex, int age) :
	id(id),
	name(name),
	sex(sex),
	age(age)
{
}

Student::~Student()
{

}

bool Student::operator<(Student& secondStudent)
{
	// Ordering alphabetically.
	return this->name < secondStudent.name;
}

// Getter

int Student::getId()
{
	return this->id;
}

string Student::getName()
{
	return this->name;
}

string Student::getSex()
{
	return this->sex;
}

int Student::getAge()
{
	return this->age;
}

// Setter

void Student::setId(int id)
{
	this->id = id;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setSex(string sex)
{
	this->sex = sex;
}

void Student::setAge(int age)
{
	this->age = age;
}
