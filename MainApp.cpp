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

	//Populate the database
	movieDatabase.addMovie(Movie("Monty Python and the Holy Grail", "Comedy", 1975, 156333, "https://www.youtube.com/watch?v=scD4_ZVDD-8"));
	movieDatabase.addMovie(Movie("Up", "Animation", 2009, 152332333, "https://www.youtube.com/watch?v=dQw4w9WgXcQ"));
	movieDatabase.addMovie(Movie("The Prestige", "Thriller", 2006, 652333, "https://www.youtube.com/watch?v=o4gHCmTQDVI"));
	movieDatabase.addMovie(Movie("Midnight Cowboy", "Buddy Drama", 1969, 342144, "https://www.youtube.com/watch?v=c412hqucHKw"));
	movieDatabase.addMovie(Movie("A Fistful of Dollars", "Spaghetti Western", 1964, 32444, "https://www.youtube.com/watch?v=HjjDOdaFZg0"));
	movieDatabase.addMovie(Movie("For A Few Dollars More", "Spaghetti Western", 1965, 55244, "https://www.youtube.com/watch?v=mLXQltR7vUQ"));
	movieDatabase.addMovie(Movie("Shawshank Redemption", "Drama", 1994, 5525444, "https://www.youtube.com/watch?v=6hB3S9bIaco"));
	movieDatabase.addMovie(Movie("The Lord of the Rings: The Fellowship of the Ring", "Fantasy", 2001, 55254444412, "https://www.youtube.com/watch?v=V75dMMIW2B4"));
	movieDatabase.addMovie(Movie("The Lord of the Rings: The Two Towers", "Fantasy", 2002, 56254444412, "https://www.youtube.com/watch?v=LbfMDwc4azU"));
	movieDatabase.addMovie(Movie("The Lord of the Rings: The Return of the King", "Fantasy", 2003, 995254444412, "https://www.youtube.com/watch?v=NUIZvAe3RBg"));
	
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