#include "Watchlist.h"
#include "Movie.h"

Watchlist::Watchlist()
{
	this->current = 0;
}

void Watchlist::add(const Movie& movie)
{
	this->movies.add(movie);
}
/*
void Watchlist::remove(std::string& title, std::string& genre)
{
	for (int i = 0; i < this->movies.getSize(); ++i)
		if (this->movies.get(i).getTitle() == title && this->movies.get(i).getGenre() == genre) {
			this->movies.remove(i);
			break;
}
*/



void Watchlist::remove(int position)
{
	if (position >= 0 && position <= this->getSizeWatchlist())
	{
		this->movies.remove(position);
	}
}

Movie Watchlist::getCurrentMovie(const std::string& title, const std::string& genre)
{
	DynamicVector moviesWatchlist;
	Movie m;
	moviesWatchlist = this->getMoviesFromWatchlist();
	for (int i = 0; i < moviesWatchlist.getSize(); i++)
		if (moviesWatchlist.get(i).getTitle() == title && moviesWatchlist.get(i).getGenre() == genre)
		{
			m = moviesWatchlist.get(i);
			//break;
		}
	return m;
}

/*void Watchlist::play()
{
	// TODO
}

void Watchlist::next()
{
	// TODO
}*/

bool Watchlist::isEmpty()
{
	return this->movies.getSize() == 0;
}

int Watchlist::getSizeWatchlist()
{
	return this->movies.getSize();
}

DynamicVector Watchlist::getMoviesFromWatchlist()
{
	return this->movies;
}

bool Watchlist::checkIfIsInWatchlist(Movie& m)
{
	DynamicVector moviesWatchlist;
	bool found = false;
	moviesWatchlist = this->getMoviesFromWatchlist();
	for (int i = 0; i < moviesWatchlist.getSize(); i++)
		if (moviesWatchlist.get(i).getTitle() == m.getTitle() && moviesWatchlist.get(i).getGenre() == m.getGenre())
		{
			found = true;
			//break;
		}
	return found;

}

int Watchlist::findPositionForMovie(const std::string& title, const std::string& genre)
{
	DynamicVector moviesWatchlist;
	int position = -1;
	moviesWatchlist = this->getMoviesFromWatchlist();
	for (int i = 0; i < moviesWatchlist.getSize(); i++)
		if (moviesWatchlist.get(i).getTitle() == title && moviesWatchlist.get(i).getGenre() == genre)
		{
			position = i;
			//break;
		}
	return position;
}

void Watchlist::updateLike(Movie& m)
{
	for (int i = 0; i < this->movies.getSize(); i++)
		if (this->movies.get(i).getTitle() == m.getTitle() && this->movies.get(i).getGenre() == m.getGenre())
			this->updateMovie(m.getTitle(), m.getGenre(), m.getYearOfRelease(), m.getnumberOfLikes() + 1, m.getSource());
}

void Watchlist::updateMovie(const std::string& title, const std::string& genre, const int newYearOfRelease, const int newNumberOfLikes, const std::string& newSource)
{
	int position;
	Movie m{ title, genre, newYearOfRelease, newNumberOfLikes, newSource };
	position = this->findPositionForMovie(title, genre);
	if (position != -1)
		this->movies.update(position, m);
}



