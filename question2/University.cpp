#include "University.hpp"

University::University():
	people({})
{
}

University::~University()
{
	// Iterating among everyone of the University.
	for (Person* person: people)
	{
		// Delete the pointer associated to the person.
		delete person;
	}
}

void University::addPerson(string personCategory, int id, string name, string address, string domain)
{
	// Two person cannot have the same id in the university. We have to check that the id of the new person is not already on our person list.

	// Iterating among everyone of the University.
	for (Person* person: people)
	{
		if (id == person->getId())
		{
			cout << "An user with this ID is already on the university." << endl ;
			return;
		}
	}

	// Now we are sure that nobody has this id in the school.

	Person* newPerson = nullptr;

	// s, f and t will be what the user can type into the terminal to add a new person to the new unievrsity.

	// If the user typed s, he wants to initialize a scholar.
	if (personCategory == "s")
		newPerson = new Scholar();

	// If the user typed f, he wants to initialize a full-time teacher.
	else if (personCategory == "f")
		newPerson = new FullTeacher();

	// If the user typed t, he wants to initialize a temporary.
	else if (personCategory == "t")
		newPerson = new TemporaryTeacher();

	// This case should never arrived as long the input is controlled before the call to this function.
	else
	{
		cout << "An error occurred !" << endl ;
		return;
	}

	// Setting newPerson information.
	newPerson->setId(id);
	newPerson->setName(name);
	newPerson->setAddress(address);
	newPerson->setDomain(domain);

	// Adding the newPerson to the list of person in the school.
	people.push_back(newPerson);
}

void University::addPerson(Person* newPerson)
{
	// Two person cannot have the same id in the university. We have to check that the id of the new person is not already on our person list.

	// Iterating among everyone of the University.
	for (Person* person: people)
	{
		if (newPerson->getId() == person->getId())
		{
			cout << "An user with this ID is already on the university." << endl ;
			return;
		}
	}

	// Now we are sure that nobody has this id in the school.

	// Adding the new Person into the actual list.
	people.push_back(newPerson);
}

void University::displayAllPerson()
{
	// Iterating among everyone of the University.
	for (Person* currentPerson: people)
	{
		// Display all information concerning the currentperson.
		cout << "Status: " << currentPerson->getPersonCategory() << endl;
		cout << currentPerson->getNameOfStudyCategory() << ": " << currentPerson->getDomain() << endl;
		cout << "Name: " << currentPerson->getName() << endl ;
		cout << "Address: " << currentPerson->getAddress() << endl ;
		cout << "Id: " << currentPerson->getId() << endl << endl ;
	}
}

vector<Person*> University::getPeople()
{
	return this->people;
}
