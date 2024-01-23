#include "Person.hpp"

Person::Person(int id, string name, string address, string domain) :
	id(id),
	name(name),
	address(address),
	domain(domain),
	personCategory(""),
	nameOfStudyCategory("")
{
}

Person::Person() :
		id(0),
		name(""),
		address(""),
		domain(""),
		personCategory(""),
		nameOfStudyCategory("")
{
}

Person::~Person()
{
}

// Getter

int Person::getId()
{
	return this->id;
}

string Person::getName()
{
	return this->name;
}

string Person::getAddress()
{
	return this->address;
}

string Person::getDomain()
{
	return this->domain;
}

string Person::getPersonCategory()
{
	return this->personCategory;
}

string Person::getNameOfStudyCategory()
{
	return this->nameOfStudyCategory;
}

// Setter

void Person::setId(int id)
{
	this->id = id;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setAddress(string address)
{
	this->address = address;
}

void Person::setDomain(string domain)
{
	this->domain = domain;
}
