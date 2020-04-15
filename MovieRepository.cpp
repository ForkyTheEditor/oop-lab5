#include "MovieRepository.h"
#include "Movie.h"
#include <iostream>

void MovieRepository::addMovie(Movie newMovie) {

	for (int i = 0; i < movieList.size(); i++) {

		if (newMovie == movieList[i]) {

			std::cout << "Movie is already in the database!\n";
			return;

		}

	}

	this->movieList.push_back(newMovie);

}

void MovieRepository::deleteMovie(Movie movieToDelete) {

	for (int i = 0; i < movieList.size(); i++) {

		if (movieList[i] == movieToDelete) {

			movieList.erase(movieList.begin() + i);
			return;
		}
	}
}

void MovieRepository::deleteMovie(int index) {

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