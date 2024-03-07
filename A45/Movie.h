#ifndef MOVIE_H
#define MOVIE_H

#pragma once
#include <iostream>
#include "string.h"


class Movie
{
private:
	std::string title;
	std::string genre;
	int yearOfRelease;
	int numberOfLikes;
	std::string source;		// trailer Link

public:
	// default constructor for a movie
	Movie();

	// constructor with parameters
	Movie(const std::string& title, const std::string& genre, const int yearOfRelease, const int numberOfLikes, const std::string& source);

	std::string getTitle() const { return title; }
	std::string getGenre() const { return genre; }
	int getYearOfRelease() const { return yearOfRelease; }
	int getnumberOfLikes() const { return numberOfLikes; }
	std::string getSource() const { return source; }

	void setTitle(const std::string& newTitle) { title = newTitle; }
	void setGenre(const std::string& newGenre) { genre = newGenre; }
	void setYearOfRelease(const int newYearOfRelease)  { yearOfRelease = newYearOfRelease; }
	void setnumberOfLikes(const int newNumberOfLikes)  { numberOfLikes = newNumberOfLikes; }
	void setSource(const std::string& newSource)  { source = newSource; }


	// Plays the current movie trailer: the page corresponding to the source link is opened in a browser.
	void play();

	// reurns a string with the Movie's data
	std::string toString();
};

#endif
