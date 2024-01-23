#include "TemporaryTeacher.hpp"

TemporaryTeacher::TemporaryTeacher(int id, string name, string address, string domain) :
	// Uses the constructor of the parent classes.
	Person(id, name, address, domain)
{
	// Writing some information that concerns temporary teachers only.
	this->personCategory = "Temporary Teacher";
	this->nameOfStudyCategory = "Teaching field";
}

TemporaryTeacher::TemporaryTeacher() :
	// Uses the constructor of the parent classes.
	Person()
{
	// Writing some information that concerns temporary teachers only.
	this->personCategory = "Temporary Teacher";
	this->nameOfStudyCategory = "Teaching field";
}


TemporaryTeacher::~TemporaryTeacher()
{
}

