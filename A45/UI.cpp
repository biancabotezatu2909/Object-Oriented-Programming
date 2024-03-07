#include "UI.h"
#include <string>

using namespace std;
//TODO: Validation, see in watchlist the likes
void UI::printMenu()
{
	cout << endl;
	cout << "1 - Administrator mode." << endl;
	cout << "2 - User mode." << endl;
	cout << "0 - Exit." << endl;
}

void UI::printAdministratorModeMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add movie." << endl;
	cout << "\t 2 - Delete movie." << endl;
	cout << "\t 3 - Update movie." << endl;
	cout << "\t 4 - Display all." << endl;
	cout << "\t 0 - Back." << endl;
}

void UI::printUserModeMenu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - See all the movies by selecting a genre." << endl;
	cout << "\t 2 - Delete a movie from the watchlist." << endl;
	cout << "\t 3 - Display the watchlist." << endl;
	cout << "\t 0 - Back." << endl;
}




bool UI::validateGenre(const std::string& genre)
{
	if (genre != "Crime" && genre != "Thriller" && genre != "Science Fiction" && genre != "Historical" && genre != "Comedy" && genre != "Drama")
		return false;
	return true;
}

bool UI::validateYearOfRelease(int year)
{
	if (year<0 || year > 2023)
		return false;
	return true;
}

bool UI::validateNrLikes(int likes)
{
	if (likes < 0)
		return false;
	return true;
}


bool UI::validateSource(const std::string& source)
{
	if (source[0] != 'h' || source[1] != 't' || source[2] != 't' || source[3] != 'p' ||
		source[4] != 's' || source[5] != ':' || source[6] != '/' || source[7] != '/')
		return false;
	if (source.find("www.") == std::string::npos && source.find(".com") == std::string::npos)
		return false;
}

/*DynamicVector UI::fillWithTenMovies()
{
	return this->service.getAllMoviesInRepo();
}*/


void UI::addMovieToRepo()
{
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);
	
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	
	while (this->validateGenre(genre) == false)
	{
		cout << "The genre doesn't exist. Try again. " << "\n";
		cout << "Enter the genre: ";
		getline(cin, genre);
	}
	int yearOfRelease;
	cout << "Enter the year of release: ";
	cin >> yearOfRelease;
	while (this->validateYearOfRelease(yearOfRelease) == false)
	{
		cout << "Invalid year. Try again. " << "\n";
		cout << "Enter the year of release: ";
		cin >> yearOfRelease;
	}
	int numberOfLikes;
	cout << "Enter the number of likes: ";
	cin >> numberOfLikes;
	while (this->validateNrLikes(numberOfLikes) == false)
	{
		cout << "Invalid number of likes. Try again. " << "\n";
		cout << "Enter number of likes: ";
		cin >> numberOfLikes;
	}

	cin.ignore();
	cout << "Trailer link: ";
	std::string link;
	cin >> link;

	while (this->validateSource(link) == false)
	{
		cout << "Invalid input for the source. Try again. " << "\n";
		cout << "Trailer link: ";
		cin >> link;
	}

	bool check;
	check = this->service.addMovieToRepository(title, genre, yearOfRelease, numberOfLikes, link);
	while (check == false)
	{
		cout << "The movie already exists. Try another one.\n";
		cout << "Enter the title: ";
		std::string title;
		cin >> title;

		cout << "Enter the genre: ";
		std::string genre;
		cin >> genre;

		int yearOfRelease;
		cout << "Enter the year of release: " << endl;
		cin >> yearOfRelease;
		while (this->validateYearOfRelease(yearOfRelease) == false)
		{
			cout << "Invalid number of likes. Try again. " << "\n";
			cout << "Enter number of likes: ";
			cin >> yearOfRelease;
		}

		int numberOfLikes;
		cout << "Enter the number of likes: " << endl;
		cin >> numberOfLikes;
		while (this->validateNrLikes(numberOfLikes) == false)
		{
			cout << "Invalid number of likes. Try again. " << "\n";
			cout << "Enter number of likes: ";
			cin >> numberOfLikes;
		}

		cin.ignore();
		cout << "Trailer link: ";
		std::string link;
		cin >> link;
		check = this->service.addMovieToRepository(title, genre, yearOfRelease, numberOfLikes, link);

	}
}

void UI::deleteMovieFromRepo()
{
	bool check;
	cout << "Enter the title: ";
	std::string title;
	getline(cin, title);

	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);

	while (this->validateGenre(genre) == false)
	{
		cout << "The genre doesn't exist. Try again. " << "\n";
		cout << "Enter the genre: ";
		getline(cin, genre);
	}
	check = this->service.deleteMovieFromRepository(title, genre);
	while (check == false)
	{
		cout << "This movie does not exist. Try another one."<<"\n";
		cout << "Enter the title: ";
		std::string title;
		getline(cin, title);

		cout << "Enter the genre: ";
		std::string genre;
		getline(cin, genre);
		check = this->service.deleteMovieFromRepository(title, genre);
	}

}

void UI::updateMovieInRepo()
{
	
	cout << "Enter the title of the movie you want to update: ";
	std::string title;
	getline(cin, title);

	cout << "Enter the genre of the movie you want to update: ";
	std::string genre;
	getline(cin, genre);
	while (this->validateGenre(genre) == false)
	{
		cout << "The genre doesn't exist. Try again. " << "\n";
		cout << "Enter the genre: ";
		getline(cin, genre);
	}

	int yearOfRelease;
	cout << "Enter the new year of release: ";
	cin >> yearOfRelease;
	while (this->validateYearOfRelease(yearOfRelease) == false)
	{
		cout << "Invalid year. Try again. " << "\n";
		cout << "Enter the year of release: ";
		cin >> yearOfRelease;
	}

	int numberOfLikes;
	cout << "Enter the new number of likes: ";
	cin >> numberOfLikes;
	while (this->validateNrLikes(numberOfLikes) == false)
	{
		cout << "Invalid number of likes. Try again. " << "\n";
		cout << "Enter number of likes: ";
		cin >> numberOfLikes;
	}

	cin.ignore();
	cout << "Enter the new trailer link: ";
	std::string link;
	cin >> link;

	while (this->validateSource(link) == false)
	{
		cout << "Invalid input for the source. Try again. " << "\n";
		cout << "Trailer link: ";
		cin >> link;
	}
	bool check;
	check = this->service.updateMovieInRepository(title, genre, yearOfRelease, numberOfLikes, link);
	while (check == false)
	{
		cout << "The movie does not exist. Try another one.\n";
		cout << "Enter the title of the movie you want to update: ";
		std::string title;
		cin >> title;

		cout << "Enter the genre of the movie you want to update: ";
		std::string genre;
		getline(cin, genre);

		int yearOfRelease;
		cout << "Enter the new year of release: ";
		cin >> yearOfRelease;

		int numberOfLikes;
		cout << "Enter the new number of likes: ";
		cin >> numberOfLikes;


		cin.ignore();
		cout << "Enter the new trailer link: ";
		std::string link;
		getline(cin, link);
		check = this->service.updateMovieInRepository(title, genre, yearOfRelease, numberOfLikes, link);

	}
}

void UI::displayAllMoviesRepo()
{
	cout << "\n";
	cout << "------------------------------------------------------------------M O V I E S------------------------------------------------------------------" << "\n";
	int size;
	DynamicVector movies = this->service.getAllMoviesInRepo();
	size = this->service.getAllMoviesInRepo().getSize();
	//size = this->service.getAllMoviesFromRepo().getSize();
	for (int i = 0; i < size; i++)
	{
		Movie m = movies.get(i);
		cout << m.toString() << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------"<<"\n";
	}
	cout << "\n";
}

void UI::displayAllMoviesWatchlist()
{
	cout << "\n";
	cout << "----------------------------------------------------------------W A T C H L I S T---------------------------------------------------------------" << "\n";
	DynamicVector moviesWatchlist = this->service.getAllMoviesFromWatchlist();
	cout << moviesWatchlist.getSize();
	for (int i = 0; i < moviesWatchlist.getSize(); i++)
	{
		Movie m = moviesWatchlist.get(i);
		cout << m.toString() << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << "\n";

	}
	cout << "\n";
}


void UI::removeMovieFromWatchlist()
{
	char answer;
	int position;
	Movie movie;
	cout << "Enter the title of the movie you want to remove: ";
	std::string title;
	getline(cin, title);
	cin.ignore();

	cout << "Enter the genre of the movie you want to remove: ";
	std::string genre;
	getline(cin, genre);

	cout << "Did you liked the movie?" << "\n";
	
	cout << "Y - Yes"<<"\n";

	cout << "N - No"<<"\n";
	cin >> answer;

	if (answer == 'Y')
	{
		movie = this->service.removeMovieFromWatchlist(title, genre);
		this->service.updateLike(movie);

	}
}



void UI::getAllMoviesByGenre()
{
	char answer;
	cout << "Enter the genre: ";
	std::string genre;
	getline(cin, genre);
	DynamicVector movies;
	movies = this->service.getAllMoviesInRepo();
	movies = this->service.getAllMoviesInRepoByGenre(genre);
	bool loop = true;
	while (loop == true)
	{
		for (int i = 0; i < movies.getSize(); i++)
		{
			Movie m = movies.get(i);
			if (this->service.checkIsInWatchlist(m) == true)
			{
				cout << m.toString() << "\n";
				cout << "--->ADDED" << "\n" << "\n";
			}

			if (this->service.checkIsInWatchlist(m) == false)
			{
				cout << m.toString() << "\n";
				cout << "Do you like this movie?" << '\n';
				cout << "Y - Yes " << "\n";
				cout << "N - No " << "\n";
				m.play();
				cout << "Your answer: ";
				cin >> answer;
				cin.ignore();
				if (answer == 'Y')
				{
					this->service.updateLike(m);
					this->service.updateLikeWatchlist(m);//doesnt update the watchlist
					cout << "Do you want to add it in your watchlist?" << "\n";
					cout << "Y - Yes " << "\n";
					cout << "N - No " << "\n";
					cin >> answer;
					if (answer == 'Y')
						this->service.addMovieToWatchlist(m);
					else
						if (answer == 'N')
							continue;
					while (answer != 'Y' && answer != 'N') {
						cout << "Wrong input. Try again." << "\n";
						cin >> answer;
						if (answer == 'Y')
							this->service.addMovieToWatchlist(m);
						else
							if (answer == 'N')
								continue;
					}
				}
				else if (answer == 'N')
					continue;

			}
		}
		cout << "Type 'N' (Next) if you want to look again." << "\n";
		cout << "Type anything if you are done watching movies of this genre." << "\n";
		cin >> answer;
		if (answer != 'N')
		{
			break;
			loop = false;
		}
		else
			loop = true;
	}

	}




void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;

		// repository management
		if (command == 1)
		{
			this->service.getAllMoviesInRepo();
			while (true)
			{
				UI::printAdministratorModeMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->addMovieToRepo();
				break;
				case 2:
					this->deleteMovieFromRepo();
					break;
				case 3:
					this->updateMovieInRepo();
					break;
				case 4:
					this->displayAllMoviesRepo();
				}
			}
		}

		// watchlist management
		if (command == 2)
		{
			while (true)
			{
				UI::printUserModeMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				cin.ignore();
				if (commandRepo == 0)
					break;
				switch (commandRepo)
				{
				case 1:
					this->getAllMoviesByGenre();
					break;
				case 2:
					this->removeMovieFromWatchlist();
					break;
				case 3:
					this->displayAllMoviesWatchlist();
				}
			}
		}
	}
}