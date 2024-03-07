#include "Service.h"
using namespace std;

DynamicVector Service::getAllMoviesInRepo() const
{
    return this->repo.getMovies();
}

/*DynamicVector Service::getAllMoviesFromRepo() const
{
    return this->repo.getMovies();
}*/

bool Service::addMovieToRepository(const std::string& title, const std::string& genre, const int yearOfRelease, const int numberOfLikes, const std::string& source)
{
    Movie m{title, genre,  yearOfRelease, numberOfLikes, source };
    return this->repo.addMovie(m);
}

bool Service::deleteMovieFromRepository(const std::string& title, const std::string& genre)
{
    return this->repo.deleteMovie(title, genre);
    int size;
    //size = this->getRepoSize();
}

bool Service::updateMovieInRepository(const std::string& title, const std::string& genre, const int newYearOfRelease, const int newNumberOfLikes, const std::string& newSource)
{
    return this->repo.updateMovie(title, genre, newYearOfRelease, newNumberOfLikes, newSource);
}



DynamicVector Service::getAllMoviesInRepoByGenre(const std::string& genre) 
{
    return this->repo.getMoviesByGenre(genre);
}



/*void Service::startWatchlist()
{
    this->watchlist.play();
}

void Service::nextMovieWatchlist()
{
    this->watchlist.next();
}*/

void Service::updateLike(Movie& movie)
{
    this->repo.updateLike(movie);
}


void Service::addMovieToWatchlist(Movie& movie)
{
    this->watchlist.add(movie);
}

Movie Service::removeMovieFromWatchlist(const std::string& title, const std::string& genre)
{
    int position;
    Movie m;
    position = this->watchlist.findPositionForMovie(title, genre);
    m = this->watchlist.getCurrentMovie(title, genre);
    this->watchlist.remove(position);
    return m;
}

DynamicVector Service::getAllMoviesFromWatchlist()
{
    return this->watchlist.getMoviesFromWatchlist();
}

int Service::getSizeWatchlist()
{
    return this->watchlist.getSizeWatchlist();
}

bool Service::checkIsInWatchlist(Movie& m)
{
    return this->watchlist.checkIfIsInWatchlist(m);
}

void Service::updateLikeWatchlist(Movie& m)
{
    this->watchlist.updateLike(m);
}

int Service::getRepoSize()
{
    
    return this->repo.getRepoLength();
}



