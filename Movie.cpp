#include "Movie.h"
#include <iostream>
#include <string>

Movie::Movie(std::string newTitle, std::string newGenre, int newYear, int newLikes, std::string newTrailer) {

	this->title = newTitle;
	this->genre = newGenre;
	this->year = newYear;
	this->likes = newLikes;
	this->trailer = newTrailer;


}

bool operator == (Movie m1, Movie m2) {

	//Only compare movies by Title and Year of release
	if (m1.title == m2.title && m1.year == m2.year) {

		return true;
	}

	return false;
}

std::ostream& operator << (std::ostream& os, Movie m1) {

	os << m1.title + " (" + std::to_string(m1.year) + ") " + "Genre: " + m1.genre + "; Likes: " + std::to_string(m1.likes);

	return os;

}


std::string Movie::serialize() {

	std::string returnString;

	returnString = this->title + "," + this->genre + "," + std::to_string(this->year) + "," + std::to_string(this->likes) + "," + this->trailer;
	
	return returnString;

}

Movie Movie::takeMovieInput() {

	//Flush the cin..
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string newTitle = "";

	std::cout << "\nMovie's title: ";
	std::getline(std::cin, newTitle);

	std::string newGenre = "";

	std::cout << "\nMovie's genre: ";
	std::getline(std::cin, newGenre);


	int newYear = -1;

	while (newYear == -1) {

		std::cout << "\nRelease year: ";
		std::cin >> newYear;

		if (std::cin.fail()) {

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << "Invalid input!" << std::endl;

			newYear = -1;

		}
	}

	//Clear the console input
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int newLikes = -1;

	while (newLikes == -1) {

		std::cout << "\nLikes: ";
		std::cin >> newLikes;

		if (std::cin.fail()) {

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl << "Invalid input!" << std::endl;

			newLikes = -1;

		}
		std::cin.clear();

	}

	std::string newTrailer = "";

	std::cout << "\nTrailer link: ";
	std::cin >> newTrailer;

	return Movie(newTitle, newGenre, newYear, newLikes, newTrailer);


}

void Movie::likeMovie() {

	likes++;

}