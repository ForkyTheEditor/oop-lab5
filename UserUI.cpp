#include "UserUI.h"
#include <string>
#include <iostream>
#include "Movie.h"
#include "MovieRepository.h"
#include <algorithm>
#define NOMINMAX
#include <Windows.h>
#include <shellapi.h>
#include "BadInputException.h"


void UserUI::startUserProgramLoop(MovieRepository movieDatabase, MovieRepository userWatchlist) {

	bool shouldExit = false;
	std::string menuText = "\nUser mode\n1. List movies by genre\n2. View watchlist\n3. Remove from watchlist\n4. Open watchlist in notepad\n0. Exit program\n";


	while (!shouldExit) {

		std::cout << menuText;

		int userInput = -1;

		std::cout << "Your choice: ";

		//Take the user choice
		std::cin >> userInput;

		//Check if the input is incorrect 
		if (std::cin.fail()) {

			//Flush the cin
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << "Invalid input!" << std::endl;

			//Throw an error
			BadInputException b;
			throw b;

			userInput = -1;
		}

		switch (userInput) {

			case 0:
			{

				shouldExit = true;

				userWatchlist.saveToFile("userWatchlist.csv");

				std::cout << "\nGood bye!";
				break;

			}
			case 1:
			{
				std::cout << "Searched genre: ";

				std::string inputGenre;

				//Clear the cin stream
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				
				std::getline(std::cin, inputGenre);


				movieDatabase.iterateMoviesURLByGenre(inputGenre, userWatchlist);

				break;
			}
			case 2:
			{
				userWatchlist.listAllMovies();
				break;
			}
			case 3:
			{
				userWatchlist.listAllMovies();

				std::cout << "\nWhich movie do you want to remove? Enter the movie ID: ";

				//Check that the input doesn't break the program
				int movieChoice = -1;
				while (movieChoice == -1) {

					std::cin >> movieChoice;

					if (std::cin.fail()) {

						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << std::endl << "Invalid input!" << std::endl;

						movieChoice = -1;

						//Throw an error
						BadInputException b;
						throw b;

					}

				}

				std::cout << "\nDid you like the movie? Y / N:";
				std::string like;

				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				std::getline(std::cin, like);
				
				std::for_each(like.begin(), like.end(), [](char& c) {c = ::tolower(c); });

				if (like.find("y") != std::string::npos) {

					std::cout << "\nWe're glad you liked the movie!\n";
					userWatchlist.likeMovie(movieChoice);
				}

				

				userWatchlist.deleteMovie(movieChoice);
				break;
			}
			case 4:
			{

				ShellExecuteA(0, 0, "userWatchlist.csv", 0, 0, SW_SHOW);

				break;
			}
		}


	}


}