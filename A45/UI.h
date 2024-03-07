#ifndef UI_H
#define UI_H
#pragma once
#include "Service.h"
//#include "Validator.h"

class UI
{
private:
	Service service;
	//Validator* validator;

public:
	UI(const Service& s) : service(s) {} 

	void run();

private:
	static void printMenu();
	static void printAdministratorModeMenu();
	static void printUserModeMenu();

	void addMovieToRepo();
	void deleteMovieFromRepo();
	void updateMovieInRepo();

	void displayAllMoviesRepo();
	void displayAllMoviesWatchlist();
	void addMovieToWatchlist();
	void removeMovieFromWatchlist();
	void addAllMoviesByGenreToWatchlist();

	void getAllMoviesByGenre();

	bool validateGenre(const std::string& genre);
	bool validateYearOfRelease(int year);
	bool validateSource(const std::string& source);
	bool validateNrLikes(int likes);
	//DynamicVector fillWithTenMovies();


};

#endif
