#include "Repository.h"
#include <string>

using namespace std;

bool Repository::addMovie(const Movie& m)
{
	if(checkMovieInRepo(m.getTitle(), m.getGenre()) == true) // already in repo
		return false;
	this->movies.add(m);
	return true;
}

bool Repository::deleteMovie(const std::string& title, const std::string& genre)
{
	int position, size;
	
	position = findPositionByTitleAndGenre(title, genre);
	if (position != -1) // if movie exists
	{
		this->movies.remove(position);
		size = this->getRepoLength();
		return true;
	}
	
	return false;
}

bool Repository::updateMovie(const std::string& title, const std::string& genre, const int newYearOfRelease, const int newNumberOfLikes, const std::string& newSource)
{
	Movie m{ title, genre, newYearOfRelease, newNumberOfLikes, newSource };
	int position;
	position = findPositionByTitleAndGenre(title, genre);
	if (position != -1)// if movie exists
		return this->movies.update(position, m);
	else
		return false;
}

bool Repository::checkMovieInRepo(const std::string& title, const std::string& genre)
{
	int position;
	position = findPositionByTitleAndGenre(title, genre);
	if (position != -1)
		return true;
	else
		return false;

}

int Repository::findPositionByTitleAndGenre(const std::string& title, const std::string& genre)
{
	int position = -1;
	for (int i = 0; i < this->getRepoLength(); i++)
		if (this->movies.get(i).getTitle() == title && this->movies.get(i).getGenre() == genre)
			position = i;
	return position;
}

int Repository::getRepoLength()
{
	return this->movies.getSize();
		
}


DynamicVector Repository::getMovies()
{
	addTenMovies();
	return this->movies;
}


/*DynamicVector Repository::getMoviesFromRepo()
{
	//addTenMovies();
	return this->movies;
}*/


void Repository::addTenMovies()
{
	Movie m1{ "Scarface", "Crime", 1983, 2500, "https://www.youtube.com/watch?v=lZMIrD36MG8" };
	Movie m2{ "Shrek", "Comedy", 2001, 3000,  "https://www.youtube.com/watch?v=CwXOrWvPBPk" };
	Movie m3{ "Avatar", "Science Fiction", 2009, 2000, "https://www.youtube.com/watch?v=CM79GTEm2ps" };
	Movie m4{ "Schindler's List", "Historical", 1993, 7000, "https://www.youtube.com/watch?v=gG22XNhtnoY" };
	Movie m5{ "Pulp Fiction", "Crime", 1994, 8800, "https://www.youtube.com/watch?v=s7EdQ4FqbhY" };
	Movie m6{ "Forrest Gump", "Drama", 1994, 8800, "https://www.youtube.com/watch?v=bLvqoHBptjg" };
	Movie m7{ "Fight Club", "Thriller", 1999, 8700, "https://www.youtube.com/watch?v=qtRKdVHc-cE" };
	Movie m8{ "Green Mile", "Thriller", 1999, 8400, "https://www.youtube.com/watch?v=Ki4haFrqSrw" };
	Movie m9{ "Ratatouille", "Comedy", 2007, 7000, "https://www.youtube.com/watch?v=NgsQ8mVkN8w" };
	Movie m10{ "Coco", "Comedy", 2017, 9100, "https://www.youtube.com/watch?v=Ga6RYejo6Hk" };

	this->addMovie(m1);
	this->addMovie(m2);
	this->addMovie(m3);
	this->addMovie(m4);
	this->addMovie(m5);
	this->addMovie(m6);
	this->addMovie(m7);
	this->addMovie(m8);
	this->addMovie(m9);
	this->addMovie(m10);

}

DynamicVector Repository::getMoviesByGenre(const std::string& genre)
{
	DynamicVector moviesByGenre;
	if (genre == "")
		return this->getMovies();
	for (int i = 0; i < this->getRepoLength(); i++)
		if (this->movies.get(i).getGenre() == genre)
			moviesByGenre.add(this->movies.get(i));

	return moviesByGenre;
}

void Repository::updateLike(Movie& movie)
{
	for (int i = 0; i < this->movies.getSize(); i++)
		if (this->movies.get(i).getTitle() == movie.getTitle() && this->movies.get(i).getGenre() == movie.getGenre())
			this->updateMovie(movie.getTitle(), movie.getGenre(), movie.getYearOfRelease(), movie.getnumberOfLikes() + 1, movie.getSource());


}

