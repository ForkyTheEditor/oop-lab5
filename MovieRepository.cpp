#include "MovieRepository.h"
#include "Movie.h"
#include <iostream>
#define NOMINMAX
#include <Windows.h>
#include <shellapi.h>
#include <fstream>
#include <sstream>
#include "BadInputException.h"


void MovieRepository::saveToFile(std::string filename) {

	std::ofstream output_file;
	output_file.open(filename, std::ios::out);


	//Write movies to file one by one
	//Separate them by newline
	for (int i = 0; i < movieList.size(); i++) {

		output_file << movieList[i].serialize() << std::endl;
	}

	output_file.close();

}

void MovieRepository::loadFromFile(std::string filename) {

	std::ifstream input_file;
	input_file.open(filename, std::ios::in);

	std::string line;

	//Loop through the file and add all the movies to the list
	while (std::getline(input_file,line)) {

		std::stringstream stream = std::stringstream(line);

		std::string newTitle;
		std::string newGenre;
		std::string newStringYear;
		std::string newStringLikes;
		std::string newTrailer;

		std::getline(stream, newTitle, ',');
		std::getline(stream, newGenre, ',');
		std::getline(stream, newStringYear, ',');
		std::getline(stream, newStringLikes, ',');
		std::getline(stream, newTrailer, ',');

		int newYear = std::stoi(newStringYear);
		int newLikes = std::stoi(newStringLikes);

		Movie newMovie = Movie(newTitle, newGenre, newYear, newLikes, newTrailer);

		movieList.push_back(newMovie);

	}
}

void MovieRepository::addMovie(Movie newMovie) {

	for (int i = 0; i < movieList.size(); i++) {

		//Only add the movie if it isnt in the list
		if (newMovie == movieList[i]) {

			std::cout << "Movie is already in the database!\n";
			return;

		}

	}

	this->movieList.push_back(newMovie);

}

void MovieRepository::deleteMovie(Movie movieToDelete) {

	//Iterate through the list to find the movie
	for (int i = 0; i < movieList.size(); i++) {

		if (movieList[i] == movieToDelete) {

			movieList.erase(movieList.begin() + i);
			return;
		}
	}
}

void MovieRepository::deleteMovie(int index) {

	//Delete at index
	if (index > 0 && index < movieList.size() - 1) {

		movieList.erase(movieList.begin() + index);
		return;
	}

	std::cout << "Invalid movie index!";

}


void MovieRepository::updateMovie(Movie oldMovie, Movie newMovie) {

	for (int i = 0; i < movieList.size(); i++) {

		if (movieList[i] == oldMovie) {

			movieList[i] = newMovie;
			return;
		}
	}
}

void MovieRepository::updateMovie(int index, Movie newMovie) {

	if (index >= 0 && index < movieList.size()) {

		movieList[index] = newMovie;
		return;
	}

	std::cout << "Invalid movie index!";

		
	
}

void MovieRepository::listAllMovies() {

	for (int i = 0; i < movieList.size(); i++) {

		std::cout << std::to_string(i) + ". " <<  movieList[i] << std::endl; 

	}


}

void MovieRepository::listMoviesByGenre(std::string genre) {

	if (genre.empty()) {

		listAllMovies();
		return;
	}

	for (int i = 0; i < movieList.size(); i++) {

		if (movieList[i].genre == genre) {

			std::cout << movieList[i] << std::endl;

		}

	}


}

void MovieRepository::iterateMoviesURLByGenre(std::string genre, MovieRepository& watchlist) {

	//Iterate over all the movies
	for (int i = 0; i < movieList.size(); i++) {
		//Check if there is a genre or if you should iterate over all the movies
		if (!genre.empty()) {

			if (movieList[i].genre == genre) {

				std::cout << movieList[i] << std::endl;

				std::cout << "Playing trailer...\n";

				//Open the browser with the trailer

				ShellExecuteA(0, 0, movieList[i].trailer.c_str(), 0, 0, SW_SHOW);

				std::cout << "1. Add the movie to your watchlist\n2. Skip movie\n0. Exit to main menu\n";

				int watchlistOption = -1;

				while (watchlistOption == -1) {

					std::cout << "\Your choice: ";
					std::cin >> watchlistOption;

					if (std::cin.fail()) {

						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << std::endl << "Invalid input!" << std::endl;

						watchlistOption = -1;

						//Throw an error
						BadInputException b;
						throw b;


					}
				}
				//Check user input
				switch (watchlistOption) {

					case 0:
					{
						return;
					}

					case 1:
					{
						//Add to watchlist
						watchlist.addMovie(movieList[i]);
						break;
					}
					case 2:
					{
						//Keep going
						break;
					}


				}


			}

		}
		else {
			std::cout << movieList[i] << std::endl;

			std::cout << "Playing trailer...\n";

			//Open the browser with the trailer
			ShellExecuteA(0, 0, movieList[i].trailer.c_str(), 0, 0, SW_SHOW);

			std::cout << "1. Add the movie to your watchlist\n2. Skip movie\n0. Exit to main menu\n";

			int watchlistOption = -1;

			while (watchlistOption == -1) {

				std::cout << "\Your choice: ";
				std::cin >> watchlistOption;

				if (std::cin.fail()) {

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << std::endl << "Invalid input!" << std::endl;

					watchlistOption = -1;

				}
			}
			//Check user input 
			switch (watchlistOption) {

				case 0:
				{
					return;
				}

				case 1:
				{
					//Add to watchlist
					watchlist.addMovie(movieList[i]);
					break;
				}
				case 2:
				{
					//Keep going
					break;
				}


			}


		}
		

	}


}

void MovieRepository::likeMovie(int index) {

	if (index >= 0 && index < movieList.size()) {

		movieList[index].likeMovie();
		return;
	}

	std::cout << "Invalid index!\n";
	

}