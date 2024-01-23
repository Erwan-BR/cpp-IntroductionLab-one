#include "Scholar.hpp"

Scholar::Scholar(int id, string name, string address, string domain) :
	// Uses the constructor of the parent classes.
	Person(id, name, address, domain)
{
	// Writing some information that concerns scholars only.
	this->personCategory = "Student";
	this->nameOfStudyCategory = "Specialty";
}

Scholar::Scholar() :
	// Uses the constructor of the parent classes.
	Person()
{
	// Writing some information that concerns scholars only.
	this->personCategory = "Student";
	this->nameOfStudyCategory = "Specialty";
}

Scholar::~Scholar()
{
}

