#ifndef WATCHLIST_H
#define WATCHLIST_H


#pragma once
#include "DynamicVector.h"
class Watchlist
{
private:
	DynamicVector movies;
	int current;

public:
	Watchlist();

	// Adds a movie to the watchlist.
	void add(const Movie& movie);

	//Removes a movie from the watchlist
	//void remove(std::string& title, std::string& genre);

	void remove(int position);

	// Returns the movie that is currently rolling.
	Movie getCurrentMovie(const std::string& title, const std::string& genre);

	// Starts the movie trailers - plays the first trailer.
	void play();

	// Plays the next trailer in the database.
	void next();

	// Checks if the databse is empty.
	bool isEmpty();

	int getSizeWatchlist();

	DynamicVector getMoviesFromWatchlist();

	bool checkIfIsInWatchlist(Movie &m);

	int findPositionForMovie(const std::string& title, const std::string& genre);

	void updateLike(Movie& m);

	void updateMovie(const std::string& title, const std::string& genre, const int newYearOfRelease, const int newNumberOfLikes, const std::string& newSource);
};

#endif