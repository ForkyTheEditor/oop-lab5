#include "AdminUI.h"
#include <iostream>
#include <string>
#include "Movie.h"
#include "MovieRepository.h"

void AdminUI::startAdminProgramLoop(MovieRepository movieDatabase) {

	bool shouldExit = false;
	std::string menuText = "\nAdmin Mode\n1. Add Movie\n2. Update Movie\n3. Delete Movie\n4. List all movies\n\n0. Exit program\n";


	//The main loop of the program
	while (!shouldExit) {

		std::cout << menuText;

		int userInput = -1;

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
				
				shouldExit = true;
				
				movieDatabase.saveToFile("movieDatabase.txt");


				std::cout << "\nGood bye!";
				break;

			}
			case 1:
			{
				Movie movieToAdd = Movie::takeMovieInput();

				movieDatabase.addMovie(movieToAdd);
				break;


			}
			case 2:
			{

				movieDatabase.listAllMovies();
				
				std::cout << "\nWhich movie do you want to update? Enter the movie ID: ";
				
				//Check that the input doesn't break the program
				int movieChoice = -1;
				while (movieChoice == -1) {

					std::cin >> movieChoice;

					if (std::cin.fail()) {

						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << std::endl << "Invalid input!" << std::endl;

						movieChoice = -1;

					}

				}

				std::cout << "\nInput the updated version of the movie\n";

				Movie newMovie = Movie::takeMovieInput();

				movieDatabase.updateMovie(movieChoice, newMovie);

				break;

			}
			case 3:
			{
				movieDatabase.listAllMovies();

				std::cout << "\nWhich movie do you want to delete? Enter the movie ID: ";

				//Check that the input doesn't break the program
				int movieChoice = -1;
				while (movieChoice == -1) {

					std::cin >> movieChoice;

					if (std::cin.fail()) {

						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << std::endl << "Invalid input!" << std::endl;

						movieChoice = -1;

					}

				}

				movieDatabase.deleteMovie(movieChoice);
				break;

			}
			case 4:
			{

				movieDatabase.listAllMovies();
				break;

			}



		}


	}


}