#include "main.hpp"

using namespace std;

int main()
{
	// Initialize a student.
	Person* scholarSample = new Scholar();

	scholarSample->setId(1);
	scholarSample->setName("Erwan");
	scholarSample->setAddress("Paris");
	scholarSample->setDomain("3A");

	// Initialize a full-time teacher.
	Person* fullTimeTeacherSample = new FullTeacher();

	fullTimeTeacherSample->setId(2);
	fullTimeTeacherSample->setName("Antoine");
	fullTimeTeacherSample->setAddress("Cergy");
	fullTimeTeacherSample->setDomain("Development");

	// Initialize a temporary teacher.
	Person* partTimeTeacherSample = new TemporaryTeacher();

	partTimeTeacherSample->setId(3);
	partTimeTeacherSample->setName("Marc");
	partTimeTeacherSample->setAddress("Pontoise");
	partTimeTeacherSample->setDomain("Physics");

	// Initialize a university.
	University ensea;

	// Adding the 3 previous person into ensea.
	ensea.addPerson(scholarSample);
	ensea.addPerson(fullTimeTeacherSample);
	ensea.addPerson(partTimeTeacherSample);

	// Display a welcome message to help the user going through the terminal.
	displayWelcomeMessage();

	// Variable used to know what the user wants to do.
	string userInput;

	// Variables used when the user add someone into ensea.
	string categoryOfPersonToAdd;
	int idOfPersonToAdd;
	string nameOfPersonToAdd;
	string addressOfPersonToAdd;
	string domainOfPersonToAdd;


	// Boolean to check if the id that user want to use is already used.
	bool idAlreadyUsed = false;

	while(true)
	{
		// Displays a message to help the user to help him to know what he can do.
		displayHelpBeginning();

		// Retrieve the user input
		cin >> userInput;

		// If the user typed a, he wants to add someone into the school.
		if (userInput=="a")
		{
			// Displays a message to help the user to help him to know what he can do.
			displayHelpWhenAddingPerson();

			// Retrieve the user input
			cin >> categoryOfPersonToAdd;

			// If the user did not type s, f or t, he is advertised that the command is unknown.
			if (categoryOfPersonToAdd != "s" && categoryOfPersonToAdd != "f" && categoryOfPersonToAdd != "t")
			{
				cout << "Unknown command" << endl ;
			}

			// If the user typed s, f or t, he will have to enter information concerning the person to add.
			else
			{
				cout << "WARNING! Input doesn't support spaces." << endl;

				// Asking to the id the name of the person he wants to add.
				cout << "\nId of the person: ";
				cin >> idOfPersonToAdd;

				// Checking if this ID is already used.

				for (Person* person: ensea.getPeople())
				{
					if (person->getId() == idOfPersonToAdd)
					{
						cout << "This ID is already used ! Try using another one. To see used ID, check the person in ensea." << endl;
						idAlreadyUsed = true;
					}
				}

				if (!idAlreadyUsed)
				{
					// Asking to the user the name of the person he wants to add.
					cout << "\nName of the person: ";
					cin >> nameOfPersonToAdd;


					// Asking to the user the address of the person he wants to add.
					cout << "\nAddress of the person: ";
					cin >> addressOfPersonToAdd;

					// Asking to the user the domain (Specialty/Teaching Field/Research Field) of the person he wants to add.
					cout << "\nDomain of the person (Specialty/Teaching Field/Research Field): ";
					cin >> domainOfPersonToAdd;

					// Adding this person to the university
					ensea.addPerson(categoryOfPersonToAdd, idOfPersonToAdd, nameOfPersonToAdd, addressOfPersonToAdd, domainOfPersonToAdd);

					// Prevent the user that the person has been added.
					cout << "\nPerson added !" << endl << endl;
				}
				idAlreadyUsed = false;
			}
		}
		// If the user typed i, he want to see the information concerning person in ensea.
		else if (userInput == "i")
			ensea.displayAllPerson();

		// If the user typed e, he want to exit.
		else if (userInput == "e")
			break;

		// If the user did not type a, i or e, the command is incorrect.
		else
			cout << endl << "Unknown command" << endl ;
	}

   return 0;
}

void displayWelcomeMessage()
{
	cout << endl << "Hello ! Here, you can add people and display information concerning the ENSEA university." << endl;
	cout << "Some people are already in the school, so you can see it directly without adding anyone !" << endl;
}

void displayHelpBeginning()
{
	cout << endl << "What do you wand to do?" << endl;
	cout << "To add someone, type a. To see information concerning everyone in ENSEA, type i. To exit, type e." << endl;
}

void displayHelpWhenAddingPerson()
{
	cout << endl << "To add a student, type s. To add a full-time teacher (titulaire), type f." << endl;
	cout << "To add a temporary teacher (vacataire), type t. To exit, type e." << endl;
}
