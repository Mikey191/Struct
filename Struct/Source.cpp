//Создать структуру видеомагазина
// Название фильма
// Режиссер
// Жанр
// Рейтинг популярности
// Цена диска
// 
// Возможности
// Поиск по названию
// Поиск по жанру
// Поиск по режесеру 
// самый популярный фильм в жанре
// Показ всех записей
// добавление нового фильма
//

#include <iostream>
#include <string>
using namespace std;

struct videomag
{
	char title[50];//название
	char producer[50];//режесер
	char genre[20];//жанр
	double score;//рейтинг популярности
	double price;//цена диска
};

void printFilm(videomag a)
{
	cout << "Title : " << a.title << endl;
	cout << "Producer  : " << a.producer << endl;
	cout << "Genre : " << a.genre << endl;
	cout << "Score : " << a.score << endl;
	cout << "Price : " << a.price << endl;
}

void searchTitle(videomag* a, int n)
{
	cout << "Enter title: " << endl;
	videomag s;
	cin >> s.title;

	for (size_t i = 0; i < n; i++)
	{
		if (strcmp(a[i].title, s.title) == 0)
			printFilm(a[i]);
	}
	system("pause");
}


void searchGenre(videomag* a, int n)
{
	cout << "Enter genre: " << endl;
	videomag s;
	cin >> s.genre;

	for (size_t i = 0; i < n; i++)
	{
		if (strcmp(a[i].genre, s.genre) == 0)
			printFilm(a[i]);
	}
	system("pause");
}


void searchProducer(videomag* a, int n)
{
	cout << "Enter producer: " << endl;
	videomag s;
	cin >> s.producer;

	for (size_t i = 0; i < n; i++)
	{
		if (strcmp(a[i].producer, s.producer) == 0)
			printFilm(a[i]);
	}
	system("pause");
}


void mostPopularFilm(videomag a[], int n)
{
	int mp = 0;

	int tmp = a[0].score;

	for (size_t i = 0; i < n; i++)
	{

		if (a[i].score > tmp)
		{
			tmp = a[i].score;
			mp = i;
		}
	}
	cout << "Most popular film: " << a[mp].title << endl;
	cout << "Reiting: " << tmp << endl;
	system("pause");
}


void showAll(videomag a[], int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << "Film : " << a[i].title << endl;
		cout << "Producer : " << a[i].producer << endl;
		cout << "Genre : " << a[i].genre << endl;
		cout << "Score : " << a[i].score << endl;
		cout << "Price : " << a[i].price << endl;

	}
	system("pause");
}

videomag addFilm()
{
	videomag f;

	cout << " enter title: ";
	cin >> f.title;
	cout << " enter producer: ";
	cin >> f.producer;
	cout << " enter genre: ";
	cin >> f.genre;
	cout << " enter score: ";
	cin >> f.score;
	cout << " enter price: ";
	cin >> f.price;

	return f;
}


int main()
{
	videomag* dateFilms = nullptr;
	int n = 0;
	dateFilms = new videomag[1];
	dateFilms[n++] = addFilm();
	int k;
	do
	{
		system("cls");
		cout << "pls enter number:" << endl;
		cout << "1 - search title" << endl;
		cout << "2 - search genre" << endl;
		cout << "3 - search producer" << endl;
		cout << "4 - most popular film" << endl;
		cout << "5 - show all film" << endl;
		cout << "6 - add film" << endl;
		cout << "0 - exit menu" << endl;
		cin >> k;
		switch (k)
		{
		case 1:
			searchTitle(dateFilms, n);
			break;
		case 2:
			searchGenre(dateFilms, n);
			break;
		case 3:
			searchProducer(dateFilms, n);
			break;
		case 4:
			mostPopularFilm(dateFilms, n);
			break;
		case 5:
			showAll(dateFilms, n);
			break;
		case 6:
			videomag * tmp;
			tmp = dateFilms;
			dateFilms = new videomag[n + 1];
			for (size_t i = 0; i < n; i++)
			{
				dateFilms[i] = tmp[i];
			}
			dateFilms[n++] = addFilm();
			delete[] tmp;
			break;
		}
	} while (k != 0);

	delete[]dateFilms;

	return 0;
}