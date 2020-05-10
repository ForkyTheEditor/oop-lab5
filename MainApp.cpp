#include <iostream>
#include "Movie.h"
#include "MovieRepository.h"
#include "AdminUI.h"
#include "UserUI.h"


int main() {

	
	std::cout << "Notflix: Netflix without actual movies v0.1\n\n";
	

	AdminUI adminUIObject = AdminUI();
	UserUI userUIObject = UserUI();
	MovieRepository movieDatabase = MovieRepository();
	MovieRepository userWatchlist = MovieRepository();

	//Load the databases from the files
	movieDatabase.loadFromFile("movieDatabase.txt");
	userWatchlist.loadFromFile("userWatchlist.txt");
	
	std::cout << "0. Admin mode\n1. User mode\n";

	int userInput = -1;

	while (userInput == -1) {

		std::cout << "Your choice: ";

		//Take the user choice
		std::cin >> userInput;

		//Check if the input is incorrect 
		if (std::cin.fail()) {

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << "Invalid input!" << std::endl;

			userInput = -1;
		}

		switch (userInput) {

		case 0: 
		{
			//Start the program in the admin mode
			adminUIObject.startAdminProgramLoop(movieDatabase);
			break;
		}
		case 1:
		{
			//Start the program in the user mode
			userUIObject.startUserProgramLoop(movieDatabase, userWatchlist);
			break;
		}


		}


	}
	
}