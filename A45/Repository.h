#ifndef REPOSITORY_H
#define REPOSITORY_H

#pragma once
#include "Movie.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector movies;
public:
	
	/*
		Default constructor.
		Initializes an object of type repository.
	*/
	Repository() {}

	/*
		Adds a movie to the repository.
		Input: m - Movie.
		Output: the movie is added to the repository.
	*/

	bool addMovie(const Movie& m);
	/*
		Deletes a movie from the repository based on the given data.
		Input: title - string, genre - string.
		Output: the movie is deleted from the repository.
	*/
	bool deleteMovie(const std::string& title, const std::string& genre);

	/*
		Updates a movie in the repository based on the given data.
		Input: title - string, genre - string, newYearOfRelease - int, newNumberOfLikes - int, newSource - string.
		Output: the movie is updated in the repository.
	*/
	bool updateMovie(const std::string& title, const std::string& genre, const int newYearOfRelease, const int newNumberOfLikes, const std::string& newSource);

	/*
		Checks if a movie exists in the repository.
	*/
	bool checkMovieInRepo(const std::string& title, const std::string& genre);

	/*
		Finds a movie, by title and genre.
		Input: title, genre - string
		Output: the movie that was found, or an "empty" movie (all fields empty0), if nothing was found.
	*/
	Movie findByTitleAndGenre(const std::string& title, const std::string& genre);

	/*
		Finds the position in the repo for a movie, by title and genre.
		Input: title, genre - string
		Output: the position if the movie was found, -1 otherwise.
	*/

	int findPositionByTitleAndGenre(const std::string& title, const std::string& genre);

	/*
	* returns the length of the repository
	*/
	int getRepoLength();

	/*
	* DynamicVector getMovies() const { return movies; }
	*/
	Movie getRepo(int position);

	/*
	* Returns the vector of movies.
	*/ 
	DynamicVector getMovies();

	/*
	* Initializes the repository with 10 movies.
	*/
	void addTenMovies();

	/*
	* Returns a vector of movies of a specified genre.
	*/
	DynamicVector getMoviesByGenre(const std::string& genre);
	/*
	* Updates the number of likes for a movie when the user likes it.
	*/
	void updateLike(Movie& movie);


	DynamicVector getMoviesFromRepo();
};
#endif