#pragma once
#include <string>

class Movie {
	friend class MovieRepository;


private:

	std::string title;
	std::string genre;
	int year;
	int likes;

	//A link to a trailer of the movie
	std::string trailer;

public:

	//Define the equality operator for this object
	friend bool operator == (Movie m1, Movie m2);

	//Define the "put to" operator for this object
	friend std::ostream& operator << (std::ostream&, Movie m1);
	
	//Returns a serialized string ready for save
	std::string serialize();
	
	Movie(std::string title, std::string genre, int year, int likes, std::string trailer);

	//Method to transform user input into a Movie object
	static Movie takeMovieInput();
	
	//Adds 1 like to the movie's likes
	void likeMovie();

};

