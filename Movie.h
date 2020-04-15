#pragma once
#include <string>

using namespace std;

class Movie {
	friend class MovieRepository;


private:

	string title;
	string genre;
	int year;
	int likes;

	//A link to a trailer of the movie
	string trailer;

public:

	//Define the equality operator for this object
	friend bool operator == (Movie m1, Movie m2);

	//Define the "put to" operator for this object
	friend ostream& operator << (ostream&, Movie m1);
	
	Movie(string title, string genre, int year, int likes, string trailer);

	//Method to transform user input into a Movie object
	static Movie takeMovieInput();
	
	//Adds 1 like to the movie's likes
	void likeMovie();

};

