#include "Tests.h"
#include "DynamicVector.h"
#include "Watchlist.h"
#include "Repository.h"
#include "Service.h"
#include "Movie.h"
#include "stdio.h"
#include "assert.h"

using namespace std;

void testDynamicVector()
{
    // Test the constructor
    DynamicVector v1(10);
    assert(v1.getSize() == 0);

    // Test the copy constructor
    v1.add(Movie("Title1", "Genre1", 2000, 2500, "Link1"));
    DynamicVector v2(v1);
    assert(v2.getSize() == 1);
    assert(v2.get(0).getTitle() == "Title1");
    assert(v2.get(0).getGenre() == "Genre1");
    assert(v2.get(0).getYearOfRelease() == 2000);
    assert(v2.get(0).getnumberOfLikes() == 2500);
    assert(v2.get(0).getSource() == "Link1");

    // Test the assignment operator
    DynamicVector v3(20);
    v3 = v2;
    assert(v3.getSize() == 1);
    assert(v3.get(0).getTitle() == "Title1");
    assert(v3.get(0).getGenre() == "Genre1");
    assert(v3.get(0).getYearOfRelease() == 2000);
    assert(v3.get(0).getSource() == "Link1");

    // Test the add function
    v1.add(Movie("Title2", "Genre2", 2001, 3700, "Link2"));
    assert(v1.getSize() == 2);
    assert(v1.get(0).getTitle() == "Title1");
    assert(v1.get(0).getGenre() == "Genre1");
    assert(v1.get(0).getYearOfRelease() == 2000);
    assert(v1.get(0).getnumberOfLikes() == 2500);
    assert(v1.get(0).getSource() == "Link1");
    //second movie
    assert(v1.get(1).getTitle() == "Title2");
    assert(v1.get(1).getGenre() == "Genre2");
    assert(v1.get(1).getYearOfRelease() == 2001);
    assert(v1.get(1).getnumberOfLikes() == 3700);
    assert(v1.get(1).getSource() == "Link2");

    // Test the resize function
    DynamicVector v4(1);
    v4.add(Movie("Title1", "Genre1", 2000, 5000, "Link1"));
    v4.add(Movie("Title2", "Genre2", 2001, 7000, "Link2"));
    assert(v4.getSize() == 2);
    assert(v4.getCapacity() == 2);
    v4.add(Movie("Title3", "Genre3", 2002, 8000, "Link3"));
    assert(v4.getSize() == 3);
    assert(v4.getCapacity() == 4);
    v4.add(Movie("Title4", "Genre4", 2003, 1000, "Link4"));
    assert(v4.getSize() == 4);
    assert(v4.getCapacity() == 4);
    v4.add(Movie("Title5", "Genre5", 2004, 500, "Link5"));
    assert(v4.getSize() == 5);
    assert(v4.getCapacity() == 8);

    // Test the remove function
    DynamicVector v5(2);
    v5.add(Movie("Title1", "Genre1", 2000, 100000, "Link1"));
    v5.add(Movie("Title2", "Genre2", 2001, 6500, "Link2"));
    v5.remove(0);
    assert(v5.getSize() == 1);
    cout << "The Dynamic Vector Test went ok\n";

}


void testMovie()
{
    // Test the default constructor
    Movie m1;
    assert(m1.getTitle() == "");
    assert(m1.getGenre() == "");
    assert(m1.getYearOfRelease() == 0);
    assert(m1.getnumberOfLikes() == 0);
    assert(m1.getSource() == "");

    // Test the constructor with parameters
    Movie m2("The Matrix", "Science Fiction", 1999, 10000, "https://www.youtube.com/watch?v=m8e-FF8MsqU");
    assert(m2.getTitle() == "The Matrix");
    assert(m2.getGenre() == "Science Fiction");
    assert(m2.getYearOfRelease() == 1999);
    assert(m2.getnumberOfLikes() == 10000);
    assert(m2.getSource() == "https://www.youtube.com/watch?v=m8e-FF8MsqU");

    // Test the setters
    Movie m3("Title", "Genre", 1980, 0, "Link1");
    m3.setnumberOfLikes(300);
    assert(m3.getnumberOfLikes(), 300);
    m3.setYearOfRelease(2000);
    assert(m3.getYearOfRelease(), 2000);
    m3.setSource("newLink");
    assert(m3.getSource() == "newLink");

    // Test the play() function (manual verification required)
    //m2.play();

    // Test the toString() function
    std::string expectedOutput = "Title: The Matrix | Genre: Science Fiction | Year of Release: 1999 | Number of Likes: 10000 | Link: https://www.youtube.com/watch?v=m8e-FF8MsqU";
    std::string output = m2.toString();
    assert(output == expectedOutput);

   
    cout << "The Movie Test went OK\n";
}

void testWatchlist()
{
    Watchlist w;
    int position;
    Movie m1("Title1", "Genre1", 2000, 4000, "Link1");
    w.add(m1);
    assert(w.isEmpty() == false);
    assert(w.getSizeWatchlist() == 1);
    assert(w.getMoviesFromWatchlist().getSize() == 1);
    assert(w.checkIfIsInWatchlist(m1) == true);
    position = w.findPositionForMovie(m1.getTitle(), m1.getGenre());
    w.remove(position);
    assert(w.getSizeWatchlist() == 0);
    w.add(m1);
    w.updateMovie("Title1", "Genre1", 1999, 3000, "Link2");
    assert(w.getMoviesFromWatchlist().get(0).getnumberOfLikes() == 3000);
    w.updateLike(m1);
    assert(w.getMoviesFromWatchlist().get(0).getnumberOfLikes() == 4001);
    cout << "The Watchlist Test went OK\n";
}

void testRepository()
{
    Repository repo;
    Movie m1("Title1", "Genre1", 2000, 4000, "Link1");
    repo.addMovie(m1);

    Movie m2("Title2", "Genre2", 1920, 8000, "Link2");
    repo.addMovie(m2);
    assert(repo.getRepoLength() == 2);

    int position;
    position = repo.findPositionByTitleAndGenre("Title1", "Genre1");
    assert(position == 0);
    repo.deleteMovie("Title1", "Genre1");
    assert(repo.getRepoLength() == 1);

    assert(repo.updateMovie("Title2", "Genre2", 1950, 100, "newLink") == true);
    assert(repo.getMovies().get(position).getYearOfRelease() == 1950);
    assert(repo.getMovies().get(position).getnumberOfLikes() == 100);
    assert(repo.getMovies().get(position).getSource() == "newLink");

    assert(repo.updateMovie("NoTitle", "NoGenre", 0, 0, "NoLink") == false);

    assert(repo.checkMovieInRepo("Title2", "Genre2") == true);
    assert(repo.getMoviesByGenre("Comedy").getSize() == 3);

    Movie movie;
    movie = repo.getMovies().get(0);
    repo.updateLike(movie);
    assert(repo.getMovies().get(0).getnumberOfLikes() == 101);
    assert(repo.getMoviesByGenre("").getSize() == 11);

    assert(repo.deleteMovie("Inexistent", "Inexistent") == false);
    cout << "The Repository Test went OK\n";

}

void testService()
{
    /*TODO
    * addAllMoviesByGenreToWatchlist
    * startWatchlist
    * nextMovieWatchlist    
    */
    Repository repo;
    Movie m1("Title1", "Genre1", 2000, 4000, "Link1");
    repo.addMovie(m1);
    Service service(repo);
    assert(service.getAllMoviesInRepo().getSize() == 11);

    //service.addMovieToRepository("Title32", "Genre32", 1980, 4000, "Link2");
    assert(service.addMovieToRepository("Title2", "Genre2", 1980, 4000, "Link2") == true);
    assert(service.getAllMoviesInRepo().getSize() == 12);


    //service.deleteMovieFromRepository("Title2", "Genre2");
    assert(service.deleteMovieFromRepository("Title2", "Genre2") == true);
    assert(service.getAllMoviesInRepo().getSize() == 11);

    service.updateMovieInRepository("Title1", "Genre1", 1950, 100, "newLink");
   
    assert(service.getAllMoviesInRepo().get(0).getYearOfRelease() == 1950);
    assert(service.getAllMoviesInRepo().get(0).getnumberOfLikes() == 100);
    assert(service.getAllMoviesInRepo().get(0).getSource() == "newLink");


 
    assert(service.getAllMoviesInRepoByGenre("Comedy").getSize() == 3);

    Movie movie;
    movie = service.getAllMoviesInRepo().get(0);
    service.updateLike(movie);
    assert(service.getAllMoviesInRepo().get(0).getnumberOfLikes() == 101);

    // Test Watchlist functions
    Movie m3("Title3", "Genre3", 1000, 4000, "Link3");
    service.addMovieToWatchlist(m3);
    assert(service.getWatchlist().isEmpty() == false);
    assert(service.getSizeWatchlist() == 1);
    assert(service.checkIsInWatchlist(m3) == true);
    Movie m4;
    m4 = service.removeMovieFromWatchlist("Title3", "Genre3");
    assert(service.getSizeWatchlist() == 0);

    service.addMovieToWatchlist(m3);
    service.updateLikeWatchlist(m3);
    assert(service.getAllMoviesFromWatchlist().get(0).getnumberOfLikes() == 4001);
    assert(service.getRepoSize() == 11);

    cout << "The Service Test went OK\n";
}

void testAll()
{
    testDynamicVector();
    testMovie();
    testWatchlist();
    testRepository();
    testService();
}
