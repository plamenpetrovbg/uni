#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct books
{
	string ISBN = "00000";                      // международен стандартен номер на книга
	string name = "BookPlaceholder";            // име на книгата
	string author = "AuthorPlaceholder";        // автор на книгата
	double price = 0;                           // цена на книгата
	int quantity = 0;                           // количество на книгата
	int year = 0;                               // година на издаване на книгата
	string publisher = "PublisherPlaceholder";  // издателство на книгата
	int times_taken = 0;
	int availability = 0;
};

void menu() {
	cout << "|----|----------------------------------------------------------------------|" << endl;
	cout << "| 01 | Добавяне на книга                                                    |" << endl;
	cout << "| 02 | Извеждане на екрана                                                  |" << endl;
	cout << "| 03 | Търсене и Извеждане                                                  |" << endl;
	cout << "| 04 | Подреждане на основния масив с книги, без да се извежда на екрана    |" << endl;
	cout << "| 05 | Управление на файл                                                   |" << endl;
	cout << "| 06 | Допълнение първо                                                     |" << endl;
	cout << "| 07 | Допълнение второ                                                     |" << endl;
	cout << "| 08 | Изход                                                                |" << endl;
	cout << "|----|----------------------------------------------------------------------|" << endl;
	cout << endl;
}

void minimenu() {
	cout << endl;
	cout << "|----|--------------------------------------|" << endl;
	cout << "| 01 | Търсене на книги по автор            |" << endl;
	cout << "| 02 | Извеждане на най-евтини книги        |" << endl;
	cout << "| 03 | Обратно към главното меню            |" << endl;
	cout << "|----|--------------------------------------|" << endl;
}

void minimenu2() {
	cout << endl;
	cout << "|----|--------------------------------------|" << endl;
	cout << "| 01 | Извеждане на масива с книги във файл |" << endl;
	cout << "| 02 | Въвеждане на масива с книги от файл  |" << endl;
	cout << "| 03 | Обратно към главното меню            |" << endl;
	cout << "|----|--------------------------------------|" << endl;
}

void minimenu3() {
	cout << endl;
	cout << "|----|----------------------------------------------------------------------------------------------------------------|" << endl;
	cout << "| 01 | Извеждане на книгите в подреден ред по името на автора и година на издаване, без да се променя основния масив. |" << endl;
	cout << "| 02 | Търсене и извеждане на книгите по въведена година на издаване и издателство                                    |" << endl;
	cout << "| 03 | Обратно към главното меню                                                                                      |" << endl;
	cout << "|----|----------------------------------------------------------------------------------------------------------------|" << endl;
}

void minimenu4() {
	cout << endl;
	cout << "|----|--------------------------------------|" << endl;
	cout << "| 01 | Заемане на книга                     |" << endl;
	cout << "| 02 | Връщане на книга                     |" << endl;
	cout << "| 03 | Обратно към главното меню            |" << endl;
	cout << "|----|--------------------------------------|" << endl;
}

void bookadd(books arr[], int i) {
	{
			cout << endl;
			cout << "Книга номер: " << i + 1 << endl;
			cout << endl;
			cout << "Международен стандартен номер на книгата (ISBN): ";
			cin >> arr[i].ISBN;
			cout << "Име на книгата: ";
			cin >> arr[i].name;
			cout << "Автор на книгата: ";
			cin >> arr[i].author;
			cout << "Цена на книгата: ";
			cin >> arr[i].price;
			cout << "Количество: ";
			cin >> arr[i].quantity;
			cout << "Година: ";
			cin >> arr[i].year;
			cout << "Издателство: ";
			cin >> arr[i].publisher;
			do
			{
				cout << "Наличност: ";
				cin >> arr[i].availability;
				if (arr[i].availability > 5)
				{
					cout << "Книгата може да има наличност от 0 до 5 броя!" << endl;
				}
			} while (arr[i].availability > 5 || arr[i].availability < 0);
			
			cout << endl;
	}
}

void bookshow(books arr[], int n) {
	
	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << "Книга номер: " << i + 1 << endl;
		cout << endl;
		cout << "Международен стандартен номер на книгата (ISBN): ";
		cout << arr[i].ISBN << endl;
		cout << "Име на книгата: ";
		cout << arr[i].name << endl;
		cout << "Автор на книгата: ";
		cout << arr[i].author << endl;
		cout << "Цена на книгата: ";
		cout << arr[i].price << "лв." << endl;
		cout << "Количество: ";
		cout << arr[i].quantity << endl;
		cout << "Година: ";
		cout << arr[i].year << endl;
		cout << "Издателство: ";
		cout << arr[i].publisher << endl;
		cout << "Наличност: ";
		cout << arr[i].availability << endl;
		cout << "Брой заемания: ";
		cout << arr[i].times_taken << endl;
		cout << endl;
	}
}

void booksearchauthor(books arr[], int n){
	string x;
	cout << "Книги на автор за търсене: ";
	cin >> x;
	cout << endl << "Книги на " << x << ":" << endl;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].author == x)
		{
			cout << endl;
			cout << "Международен стандартен номер на книгата (ISBN): ";
			cout << arr[i].ISBN << endl;
			cout << "Име на книгата: ";
			cout << arr[i].name << endl;
			cout << "Цена на книгата: ";
			cout << arr[i].price << "лв." << endl;
			cout << "Количество: ";
			cout << arr[i].quantity << endl;
			cout << "Година: ";
			cout << arr[i].year << endl;
			cout << "Издателство: ";
			cout << arr[i].publisher << endl;
			cout << "Наличност: ";
			cout << arr[i].availability << endl;
			cout << "Брой заемания: ";
			cout << arr[i].times_taken << endl;
			cout << endl;
		}
	}
}

void booksminprice(books arr[], int n)
{
	double min = arr[0].price;
	for (int i = 1; i < n; i++) {
		if (arr[i].price < min) {
			min = arr[i].price;
		}
	}
	cout << "Най-евтини книги: (" << min << "лв.)" << endl;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].price == min)
		{
			cout << endl;
			cout << "Международен стандартен номер на книгата (ISBN): ";
			cout << arr[i].ISBN << endl;
			cout << "Име на книгата: ";
			cout << arr[i].name << endl;
			cout << "Автор на книгата: ";
			cout << arr[i].author << endl;
			cout << "Количество: ";
			cout << arr[i].quantity << endl;
			cout << "Година: ";
			cout << arr[i].year << endl;
			cout << "Издателство: ";
			cout << arr[i].publisher << endl;
			cout << "Наличност: ";
			cout << arr[i].availability << endl;
			cout << "Брой заемания: ";
			cout << arr[i].times_taken << endl;
			cout << endl;
		}
	}
}

void bookssort(books arr[], int n)
{	
	for (int i = 0; i < n - 1; i++){

		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j].year > arr[j + 1].year) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void readbooks(books arr[], int& bookcount, int& x) {
	ifstream Books("books.bin", ios::in | ios::binary);
	Books.read((char*)&bookcount, sizeof(int));
	Books.read((char*)&x, sizeof(int));
	
	for (int i = 0; i < bookcount; i++)
	{
		size_t lenght;
		Books.read((char*)&lenght, sizeof(size_t));
		arr[i].ISBN.resize(lenght);
		Books.read((char*)&(arr[i].ISBN[0]), lenght);
		
		Books.read((char*)&lenght, sizeof(size_t));
		arr[i].name.resize(lenght);
		Books.read((char*)&(arr[i].name[0]), lenght);
		
		Books.read((char*)&lenght, sizeof(size_t));
		arr[i].author.resize(lenght);
		Books.read((char*)&(arr[i].author[0]), lenght);

		Books.read((char*)&arr[i].price, sizeof(double));
		Books.read((char*)&arr[i].quantity, sizeof(int));
		Books.read((char*)&arr[i].year, sizeof(int));
		
		Books.read((char*)&lenght, sizeof(size_t));
		arr[i].publisher.resize(lenght);
		Books.read((char*)&(arr[i].publisher[0]), lenght);
		
		Books.read((char*)&arr[i].availability, sizeof(int));
		Books.read((char*)&arr[i].times_taken, sizeof(int));
	}
	if (Books.good()) {
		cout << "Успешно прочетохте данните от файла!" << endl;
	}
	else {
		cout << "Неуспешно прочетохте данните от файла!" << endl;
	}
	Books.close();
}

void savebooks(books arr[], int& bookcount, int& x) {
	ofstream Books("books.bin", ios::out | ios::binary);
	Books.write((char*)&bookcount, sizeof(int));
	Books.write((char*)&x, sizeof(int));

	for (int i = 0; i < bookcount; i++)
	{
		size_t lenght = arr[i].ISBN.size();
		Books.write((char*)&lenght, sizeof(lenght));
		Books.write((char*)&(arr[i].ISBN[0]), lenght);
		
		lenght = arr[i].name.size();
		Books.write((char*)&lenght, sizeof(lenght));
		Books.write((char*)&(arr[i].name[0]), lenght);
		
		lenght = arr[i].author.size();
		Books.write((char*)&lenght, sizeof(lenght));
		Books.write((char*)&(arr[i].author[0]), lenght);
		
		Books.write((char*)&arr[i].price, sizeof(double));
		Books.write((char*)&arr[i].quantity, sizeof(int));
		Books.write((char*)&arr[i].year, sizeof(int));
		
		lenght = arr[i].publisher.size();
		Books.write((char*)&lenght, sizeof(lenght));
		Books.write((char*)&(arr[i].publisher[0]), lenght);
		
		Books.write((char*)&arr[i].availability, sizeof(int));
		Books.write((char*)&arr[i].times_taken, sizeof(int));
	}
	if (Books.good()) {
		cout << "Успешно записахте данните във файла!" << endl;
	}
	else {
		cout << "Неуспешно записахте данните във файла!" << endl;

		Books.close();
	}
}

void books_sort_author_and_year(books arr[], int n) {
	books temp[50];
	for (int i = 0; i < n; i++) {
		temp[i].ISBN = arr[i].ISBN;
		temp[i].name = arr[i].name;
		temp[i].author = arr[i].author;
		temp[i].price = arr[i].price;
		temp[i].quantity = arr[i].quantity;
		temp[i].year = arr[i].year;
		temp[i].publisher = arr[i].publisher;
		temp[i].availability = arr[i].availability;
		temp[i].times_taken = arr[i].times_taken;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (temp[j].author > temp[j + 1].author) {
				swap(temp[j], temp[j + 1]);
			}
		}
	}
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (temp[j].author == temp[j + 1].author) {
				if (temp[j].year > temp[j + 1].year) {
					swap(temp[j], temp[j + 1]);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << "Международен стандартен номер на книгата (ISBN): ";
		cout << temp[i].ISBN << endl;
		cout << "Име на книгата: ";
		cout << temp[i].name << endl;
		cout << "Автор на книгата: ";
		cout << temp[i].author << endl;
		cout << "Количество: ";
		cout << temp[i].quantity << endl;
		cout << "Година: ";
		cout << temp[i].year << endl;
		cout << "Издателство: ";
		cout << temp[i].publisher << endl;
		cout << "Наличност: ";
		cout << temp[i].availability << endl;
		cout << "Брой заемания: ";
		cout << temp[i].times_taken << endl;
		cout << endl;
		cout << endl;
	}
	
	
}

void books_show_by_year_and_publisher(books arr[], int n)
{
	int a;
	string b;
	cout << "Година на публикуване на книга: ";
	cin >> a;
	cout << "Издателство на книга: ";
	cin >> b;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].year == a)
		{
			if (arr[i].publisher == b)
			{
				cout << endl;
				cout << "Международен стандартен номер на книгата (ISBN): ";
				cout << arr[i].ISBN << endl;
				cout << "Име на книгата: ";
				cout << arr[i].name << endl;
				cout << "Автор на книгата: ";
				cout << arr[i].author << endl;
				cout << "Количество: ";
				cout << arr[i].quantity << endl;
				cout << "Година: ";
				cout << arr[i].year << endl;
				cout << "Издателство: ";
				cout << arr[i].publisher << endl;
				cout << endl;
			}
		}
	}
}

void books_lend(books arr[], int n){
	string x;
	cout << "Въведете ISBN код на книгата която искате да заемете: ";
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].ISBN == x)
		{
			if (arr[i].availability > 1 && arr[i].availability < 5)
			{
				cout << "Успешно книгата беше заета!" << endl;
				arr[i].availability = arr[i].availability - 1;
				arr[i].times_taken = arr[i].times_taken + 1;
			}
			else if(arr[i].availability = 0)
			{
				cout << "Книгата няма налични копия!" << endl;
			}
		    else
		    {
			cout << "Книга с този ISBN не присъства в нашия каталог!" << endl;
		    }
		}
	}
}

void books_return(books arr[], int n) {
	string x;
	cout << "Въведете ISBN код на книгата която искате да върнете: ";
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].ISBN == x)
		{
			if (arr[i].times_taken > 0)
			{
				cout << "Успешно книгата беше върната!" << endl;
				arr[i].availability = arr[i].availability + 1;
			}
			else
			{
				cout << "Книга с този ISBN не е била заемана!" << endl;
			}
		}
		
	}
}

int main()
{
	int n, x = 0, bookcount = 0, function, q = 0, file = 0, dop1 = 0, dop2 = 0;
	books book[100];
	readbooks(book, bookcount, x);
	cout << "|----|----------------------------------------------------------------------|" << endl;
	cout << "| 00 |                     ДОМАШНА СЕМЕСТРИАЛНА РАБОТА                      |" << endl;
	do {
		menu();
		cout << "Изберете функция: ";
		cin >> function;

		switch (function)
		{
		case 1: // Добавяне на книга
			cout << endl;
			cout << "Добавяне на книга:" << endl;
			cout << "Колко книги искате да добавите?: ";
			cin >> n;

			bookcount = bookcount + n;
			if (bookcount > 100) {
				bookcount = bookcount - n;
				cout << "Максималният брой книги е 100! " << "(" << 100 - bookcount << " свободни места)" << endl;
				cout << endl;
				break;
			}
			if (n <= 0) {
				cout << "Числото трябва да е по-голямо от 0!" << endl;
				cout << endl;
				bookcount = bookcount - n;
				break;
			}

			for (x; x < bookcount; x++) {
				bookadd(book, x);
			}
			break; // Добавяне на книга

		case 2: // Извеждане на екрана
			cout << endl;
			cout << "Извеждане на екрана:" << endl;
			if (bookcount <= 0)
			{
				cout << "Няма добавени книги!" << endl;
				cout << endl;
				break;
			}
			bookshow(book, bookcount);
			break; // Извеждане на екрана

		case 3: // Търсене на книга
			cout << endl;
			cout << "Търсене и Извеждане" << endl;
			if (bookcount <= 0)
			{
				cout << "Няма добавени книги!" << endl;
				cout << endl;
				break;
			}
			minimenu();
			cout << endl;
			cout << "Изберете функция: ";
			cin >> q;
			cout << endl;
			switch (q)
			{
			case 1: // Търсене по автор
				booksearchauthor(book, bookcount);
				break; // Търсене по автор

			case 2: // Показване на най-евтини книги
				booksminprice(book, bookcount);
				break; // Показване на най-етини книги

			case 3: // Изход
				break; // Изход

			default: // Грешка
				cout << endl;
				cout << "Грешка! Невалидна функция!" << endl;
				break;
			}break;

		case 4: // Подреждане на книгите
			cout << endl;
			cout << "Подреждане на основния масив с книги, без да се извежда на екрана" << endl;
			if (bookcount <= 0)
			{
				cout << "Няма добавени книги!" << endl;
				cout << endl;
				break;
			}
			bookssort(book, bookcount);
			break; // Подреждане на книгите

		case 5: // Управление на файл
			cout << endl;
			cout << "Управление на файл" << endl;
			cout << endl;
			minimenu2();
			cout << endl;
			cout << "Изберете функция: ";
			cin >> file;
			switch (file)
			{
			case 1:
				if (bookcount <= 0)
				{
					cout << "Няма добавени книги!" << endl;
					cout << endl;
					break;
				}
				savebooks(book, bookcount, x);
				break;

			case 2:
				readbooks(book, bookcount, x);
				break;

			case 3:
				cout << "Обратно към главното меню" << endl;
				break;
			default:
				break;
			}
			break; // Управление на файл

		case 6: // Допълнение първо
			minimenu3();
			cout << endl;
			cout << "Изберете функция: ";
			cin >> dop1;
			switch (dop1)
			{
			case 1:
				cout << endl;
				cout << "Извеждане на книгите в подреден ред по името на автора и година на издаване, без да се променя основния масив." << endl;
				if (bookcount <= 0)
				{
					cout << "Няма добавени книги!" << endl;
					cout << endl;
					break;
				}
				books_sort_author_and_year(book, bookcount);
				break;

			case 2:
				cout << endl;
				cout << "Търсене и извеждане на книгите по въведена година на издаване и издателство" << endl;
				if (bookcount <= 0)
				{
					cout << "Няма добавени книги!" << endl;
					cout << endl;
					break;
				}
				books_show_by_year_and_publisher(book, bookcount);
				break;
			case 3:
				cout << "Обратно към главното меню" << endl;
				break;
				
			default:
				break;
				
			} break; // Допълнение първо

		case 7: // Допълнение второ
			cout << endl;
			cout << "Заемане на книга" << endl;
			
			minimenu4();
			cout << endl;
			cout << "Изберете функция: ";
			cin >> dop2;
			switch (dop2)
			{
			case 1:
				if (bookcount <= 0)
				{
					cout << "Няма добавени книги!" << endl;
					cout << endl;
					break;
				}
				books_lend(book, bookcount);
				break;
			case 2:
				if (bookcount <= 0)
				{
					cout << "Няма добавени книги!" << endl;
					cout << endl;
					break;
				}
				books_return(book, bookcount);
				break;
			default:
				break;
			}
			break; //Допълнение второ

		case 8: // Изход
			cout << endl;
			cout << "Изход от програмата" << endl;
			savebooks(book, bookcount, x);
			return 0;
			break; // Изход

		default: // Грешка
			cout << endl;
			cout << "Грешка! Невалидна функция!" << endl;
			cout << endl;
		}
		
	}while (function < 8 || function > 8);
	return 0;
}
