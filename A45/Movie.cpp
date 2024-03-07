#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>
#include <string>

Movie::Movie() : title(""), genre(""), yearOfRelease{}, numberOfLikes{}, source("") {}



Movie::Movie(const std::string& title, const std::string& genre, const int yearOfRelease, const int numberOfLikes, const std::string& source)
{
	this->title = title;
	this->genre = genre;
	this->yearOfRelease = yearOfRelease;
	this->numberOfLikes = numberOfLikes;
	this->source = source;
}


void Movie::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getSource().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::string Movie::toString()
{
	//"Title: The Matrix | Genre: Science Fiction | Year of Release: 1999 | Number of Likes: 10000";
	return "Title: " + this->getTitle() + " | Genre: " + this->getGenre() + " | Year of Release: " + std::to_string(this->yearOfRelease) + " | Number of Likes: " + std::to_string(this->numberOfLikes) + " | Link: " + this->getSource();
	//return this->getTitle() + " - " + this->getGenre() + ", year of release: " + std::to_string(this->yearOfRelease) + ", number of likes: " + std::to_string(this->numberOfLikes) + ", " + this->getSource();
}
