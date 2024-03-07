#ifndef SERVICE_H
#define SERVICE_H
#pragma once
#include "Repository.h"
#include "Watchlist.h"

class Service
{
private:
	Repository& repo;
	Watchlist watchlist;

public:
	Service(Repository& r) : repo{ r } {}

	Repository& getRepo() const { return repo; }
	Watchlist getWatchlist() const { return watchlist; }

	DynamicVector getAllMoviesInRepo() const;

	// Adds a movie with the given data to the movie repository.
	bool addMovieToRepository(const std::string& title, const std::string& genre, const int yearOfRelease, const int numberOfLikes, const std::string& source);

	
	// Deletes a movie with the given data to the movie repository.
	bool deleteMovieFromRepository(const std::string& title, const std::string& genre);

	// Updates a movie with the given data to the movie repository.
	bool updateMovieInRepository(const std::string& title, const std::string& genre, const int newYearOfRelease, const int newNumberOfLikes, const std::string& newSource);

	
	/*
		Adds a given movie to the current watchlist.
		Input: movie - Movie, the movie must belong to the repository.
		Output: the movie is added to the watchlist.
	*/

	// Adds all the movies from the repository, that have the given genre, to the current watchlist.
	//void addAllMoviesByGenreToWatchlist(const std::string& genre);

	DynamicVector getAllMoviesInRepoByGenre(const std::string& genre) ;

	void startWatchlist();
	void nextMovieWatchlist();

	void updateLike(Movie& movie);

	void addMovieToWatchlist(Movie& m);

	Movie removeMovieFromWatchlist(const std::string& title, const std::string& genre);

	DynamicVector getAllMoviesFromWatchlist();

	int getSizeWatchlist();

	bool checkIsInWatchlist(Movie& m);

	void updateLikeWatchlist(Movie& m);

	int getRepoSize();

	DynamicVector getAllMoviesFromRepo() const;
};

#endif