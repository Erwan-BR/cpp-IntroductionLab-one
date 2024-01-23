#include "FullTeacher.hpp"

FullTeacher::FullTeacher(int id, string name, string address, string domain) :
	// Uses the constructor of the parent classes.
	Person(id, name, address, domain)
{
	// Writing some information that concerns full-time teachers only.
	this->personCategory = "Full-time Teacher";
	this->nameOfStudyCategory = "Research field";
}

FullTeacher::FullTeacher() :
	// Uses the constructor of the parent classes.
	Person()
{
	// Writing some information that concerns full-time teachers only.
	this->personCategory = "Full-time Teacher";
	this->nameOfStudyCategory = "Research field";
}

FullTeacher::~FullTeacher()
{
}

