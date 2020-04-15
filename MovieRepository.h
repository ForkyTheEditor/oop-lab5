#pragma once
#include <vector>
#include "Movie.h"

class MovieRepository {

private:

	std::vector<Movie> movieList;

public:

	//Adds a movie to the repository
	//If the movie already exists then it doesn't add it and it notifies the user on the screen
	//Parameter: The added movie
	void addMovie(Movie newMovie);

	//Deletes a movie from the repository (movies are compared by Title and Year of release, nothing else
	//Parameter: The movie to be deleted
	void deleteMovie(Movie movieToDelete);

	//Deletes a movie from the repository (movies are compared by Title and Year of release, nothing else
	//Parameter: The index of the movie to be deleted
	void deleteMovie(int index);

	//Replaces the oldMovie with newMovie
	//Parameters: The movie to be updated, The updated version of the movie
	void updateMovie(Movie oldMovie, Movie newMovie);

	//Replaces the oldMovie with newMovie
	//Parameters: The index of the movie to be updated, The updated version of the movie
	void updateMovie(int index, Movie newMovie);

	//Prints all the movies in the repository to the console
	void listAllMovies();

};