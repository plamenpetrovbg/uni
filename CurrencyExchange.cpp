#include <iostream> // for cout/cin
#include <string> // for string
#include <fstream> // for file I/O

using namespace std;

struct change {
	string currencyname; // Име на валутата
	string ISOcode; // ISO код на валутата
	double buy; // Курс на покупка
	double sell; // Курс на продажба
	double availability; // Наличност
	double transactionmaxbuy; // Максимална сума за покупка
	double transactionmaxsell; // Максимална сума за продажба
	string istraded; // Дали се търгува с валутата
	double margin; // Маржа
};

void menu() 
{
	cout << "1. Add new currency" << endl; // Добавяне на нова валута
	cout << "2. Show on screen" << endl; // Показване на валутите на екрана
	cout << "3. Search and show on screen" << endl; // Търсене и показване на валута на екрана
	cout << "4. Sort without showing on screen" << endl; // Сортиране без показване на валутите на екрана
	cout << "5. File managment" << endl; // Управление на файловете
	cout << "6. Exit" << endl; // Изход от програмата
}

void dmenu() {
	cout << "1. Find currency with the lowest availability " << endl; // Намиране на валута с най-ниска наличност
	cout << "2. Search by ISO code" << endl; // Търсене по ISO код
	cout << "3. Exit" << endl; // Изход от менюто
}

void fmenu() {
	cout << "1. Save to file " << endl; // Записване във файл
	cout << "2. Load from file" << endl; // Четене от файл
	cout << "3. Exit" << endl; // Изход от менюто
}

void add(change arr[], int i) 
{
	cout << endl; // Празен ред
	cout << "Enter the name of the currency: "; // Въвеждане на име на валута
	cin >> arr[i].currencyname; // Записване на име на валута
	cout << "Enter the ISO code of the currency: "; // Въвеждане на ISO код на валута
	cin >> arr[i].ISOcode; // Записване на ISO код на валута
	cout << "Enter the buy price of the currency: "; // Въвеждане на курс на покупка на валута
	cin >> arr[i].buy; // Записване на курс на покупка на валута
	cout << "Enter the sell price of the currency: "; // Въвеждане на курс на продажба на валута
	cin >> arr[i].sell; // Записване на курс на продажба на валута
	cout << "Enter the availability of the currency: "; // Въвеждане на наличност на валута
	cin >> arr[i].availability; // Записване на наличност на валута
	cout << "Enter the maximum amount to buy of the currency: "; // Въвеждане на максимална сума за покупка на валута
	cin >> arr[i].transactionmaxbuy;; // Записване на максимална сума за покупка на валута
	cout << "Enter the maximum amount to sell of the currency: "; // Въвеждане на максимална сума за продажба на валута
	cin >> arr[i].transactionmaxsell; // Записване на максимална сума за продажба на валута
	cout << "Enter if the currency is traded: "; // Въвеждане дали се търгува с валутата
	cin >> arr[i].istraded; // Записване дали се търгува с валутата
	cout << endl; // Празен ред
	arr[i].margin = arr[i].sell - arr[i].buy; // Изчисляване на маржата
}

void show(change arr[], int n)
{
	for (int i = 0; i < n; i++) //фор цикъл
	{
		cout << endl; // Празен ред
		cout << "Name of the currency: " << arr[i].currencyname << endl; // Име на валута
		cout << "ISO code of the currency: " << arr[i].ISOcode << endl; // ISO код на валута
		cout << "Buy price of the currency: " << arr[i].buy << endl; // Курс на покупка на валута
		cout << "Sell price of the currency: " << arr[i].sell << endl; // Курс на продажба на валута
		cout << "Availability of the currency: " << arr[i].availability << endl; // Наличност на валута
		cout << "Maximum amount to buy of the currency: " << arr[i].transactionmaxbuy << endl; // Максимална сума за покупка на валута
		cout << "Maximum amount to sell of the currency: " << arr[i].transactionmaxsell << endl; // Максимална сума за продажба на валута
		cout << "Margin of the currency: " << arr[i].margin << endl; // Маржа на валута
		cout << "If the currency is traded: " << arr[i].istraded << endl; // Дали се търгува с валутата
		cout << endl; // Празен ред
	}
}

void search(change arr[], int n)
{
	string search; // Деклариране на променлива за търсене
	cout << "Enter the ISO code you want to search: "; // Въвеждане на ISO код за търсене
	cin >> search;	// Записване на ISO код за търсене
	for (int i = 0; i < n; i++) 
	{
		if (arr[i].ISOcode == search) 
		{
			cout << endl; // Празен ред
			cout << "Name of the currency: " << arr[i].currencyname << endl; // Име на валута
			cout << "ISO code of the currency: " << arr[i].ISOcode << endl; // ISO код на валута
			cout << "Buy price of the currency: " << arr[i].buy << endl; // Курс на покупка на валута
			cout << "Sell price of the currency: " << arr[i].sell << endl; // Курс на продажба на валута
			cout << "Availability of the currency: " << arr[i].availability << endl; // Наличност на валута
			cout << "Maximum amount to buy of the currency: " << arr[i].transactionmaxbuy << endl; // Максимална сума за покупка на валута
			cout << "Maximum amount to sell of the currency: " << arr[i].transactionmaxsell << endl; // Максимална сума за продажба на валута
			cout << "Margin of the currency: " << arr[i].margin << endl; // Маржа на валута
			cout << "If the currency is traded: " << arr[i].istraded << endl; // Дали се търгува с валутата
			cout << endl; // Празен ред
		}
	}
}

void min_availability(change arr[], int n) { // Функция за намиране на валута с минимална наличност
	int min = arr[0].availability; // Минимална наличност
	for (int i = 0; i < n; i++) 
	{
		if (arr[i].availability < min) 
		{
			min = arr[i].availability; // Записване на минимална наличност
		}
	}
	cout << "The currency with the lowest availability is" << endl; // Извеждане на съобщение
	for (int i = 0; i < n; i++) 
	{
		if (arr[i].availability == min) 
		{
			cout << endl; // Празен ред
			cout << "Name of the currency: " << arr[i].currencyname << endl; // Име на валута
			cout << "ISO code of the currency: " << arr[i].ISOcode << endl; // ISO код на валута
			cout << "Buy price of the currency: " << arr[i].buy << endl; // Курс на покупка на валута
			cout << "Sell price of the currency: " << arr[i].sell << endl; // Курс на продажба на валута
			cout << "Availability of the currency: " << arr[i].availability << endl; // Наличност на валута
			cout << "Maximum amount to buy of the currency: " << arr[i].transactionmaxbuy << endl; // Максимална сума за покупка на валута
			cout << "Maximum amount to sell of the currency: " << arr[i].transactionmaxsell << endl; // Максимална сума за продажба на валута
			cout << "Margin of the currency: " << arr[i].margin << endl; // Маржа на валута
			cout << "If the currency is traded: " << arr[i].istraded << endl; // Дали се търгува с валутата
			cout << endl; // Празен ред
		}
	}
}

void sort(change arr[], int n) //bubble sort
{
	int i, j; // Деклариране на променливи
	for (i = 0; i < n - 1; i++) // Сортиране на валутите по наличност

		for (j = 0; j < n - i - 1; j++) 
			if (arr[j].margin < arr[j + 1].margin) 
				swap(arr[j], arr[j + 1]); // Размяна на елементите
}

void filesave(change arr[], int& n, int& x)
{
	ofstream currency("currency.bin", ios::out | ios::binary); // Отваряне на файл
	currency.write((char*)&n, sizeof(int)); // Записване на броя на валутите
	currency.write((char*)&x, sizeof(int)); // Записване на броя на търгуваните валути

	for (int i = 0; i < n; i++) 
	{
		size_t size = arr[i].currencyname.size(); // Записване на името на валутата
		currency.write((char*)&size, sizeof(size)); // Записване на размера на името на валутата
		currency.write((char*)&(arr[i].currencyname[0]), size); // Записване на името на валутата

		size = arr[i].ISOcode.size(); // Записване на ISO кода на валутата
		currency.write((char*)&size, sizeof(size));	// Записване на размера на ISO кода на валутата
		currency.write((char*)&(arr[i].ISOcode[0]), size); // Записване на ISO кода на валутата

		currency.write((char*)&arr[i].buy, sizeof(double)); // Записване на курса на покупка на валутата
		currency.write((char*)&arr[i].sell, sizeof(double)); // Записване на курса на продажба на валутата
		currency.write((char*)&arr[i].availability, sizeof(double));  // Записване на наличността на валутата
		currency.write((char*)&arr[i].transactionmaxbuy, sizeof(double)); // Записване на максималната сума за покупка на валутата
		currency.write((char*)&arr[i].transactionmaxsell, sizeof(double)); // Записване на максималната сума за продажба на валутата
		currency.write((char*)&arr[i].margin, sizeof(double)); // Записване на маржата на валутата

		size = arr[i].istraded.size(); // Записване на дали се търгува с валутата
		currency.write((char*)&size, sizeof(size)); // Записване на размера на дали се търгува с валутата
		currency.write((char*)&(arr[i].istraded[0]), size); // Записване на дали се търгува с валутата
	}

	currency.close(); // Затваряне на файл
}

void fileload(change arr[], int& n, int& x) 
{
	ifstream currency("currency.bin", ios::in | ios::binary); // Отваряне на файл
	currency.read((char*)&n, sizeof(int)); // Четене на броя на валутите
	currency.read((char*)&x, sizeof(int)); // Четене на броя на търгуваните валути
	
	for (int i = 0; i < n; i++)		
	{
		size_t size; // Деклариране на променлива
		currency.read((char*)&size, sizeof(size_t)); // Четене на размера на името на валутата
		arr[i].currencyname.resize(size); // Промяна на размера на името на валутата
		currency.read((char*)&(arr[i].currencyname[0]), size); // Четене на името на валутата

		currency.read((char*)&size, sizeof(size_t)); // Четене на размера на ISO кода на валутата
		arr[i].ISOcode.resize(size); // Промяна на размера на ISO кода на валутата
		currency.read((char*)&(arr[i].ISOcode[0]), size); // Четене на ISO кода на валутата

		currency.read((char*)&arr[i].buy, sizeof(double)); // Четене на курса на покупка на валутата
		currency.read((char*)&arr[i].sell, sizeof(double));	// Четене на курса на продажба на валутата
		currency.read((char*)&arr[i].availability, sizeof(double)); // Четене на наличността на валутата
		currency.read((char*)&arr[i].transactionmaxbuy, sizeof(double)); // Четене на максималната сума за покупка на валутата
		currency.read((char*)&arr[i].transactionmaxsell, sizeof(double)); // Четене на максималната сума за продажба на валутата
		currency.read((char*)&arr[i].margin, sizeof(double)); // Четене на маржата на валутата

		currency.read((char*)&size, sizeof(size_t)); // Четене на размера на дали се търгува с валутата
		arr[i].istraded.resize(size); // Промяна на размера на дали се търгува с валутата
		currency.read((char*)&(arr[i].istraded[0]), size); // Четене на дали се търгува с валутата
	}
	currency.close(); // Затваряне на файл
}

int main()
{
	int choice, choice_d, choice_f, howmany, x = 0, currencycount = 0; // Деклариране на променливи
	change currency[50]; // Деклариране на масив от структури
	fileload(currency, currencycount, x);
	do {
		cout << endl; // Празен ред
		menu(); // Извикване на менюто
		cout << endl; // Празен ред
		cout << "Enter your choice: "; // Избор на опция
		cin >> choice; // Въвеждане на опция
		cout << endl; // Празен ред

		switch (choice) 
		{
		case 1: // Добавяне на валута
			cout << "How many currencies do you want to add: ";	// Въвеждане на броя на валутите
			cin >> howmany; // Въвеждане на броя на валутите
			cout << endl; // Празен ред
			currencycount = currencycount + howmany; // Промяна на броя на валутите
			if (currencycount > 50) { // Проверка дали броя на валутите е по-голям от 50
				cout << "Max currencies are 50!" << endl; // Максималният брой валути е 50
				currencycount = currencycount - howmany; // Промяна на броя на валутите
				break; // Прекратяване на операцията
			}
			for (x; x < currencycount; x++) { // Цикъл за въвеждане на валутите
				add(currency, x); // Извикване на функцията за добавяне на валута
			}
			break; // Прекратяване на операцията
		case 2: // Изписване на валути
			if (currencycount <= 0) { // Проверка дали броя на валутите е по-малък или равен на 0
				cout << "There are no currencies!" << endl; // Няма валути
				break; // Прекратяване на операцията
			} 
			show(currency, currencycount); // Извикване на функцията за показване на валутите
			break; // Прекратяване на операцията
		case 3: // Търсене на валута
			if (currencycount <= 0) { // Проверка дали броя на валутите е по-малък или равен на 0
				cout << "There are no currencies!" << endl; // Няма валути
				break; // Прекратяване на операцията
			} 
			dmenu(); // Извикване на менюто за редактиране
			cout << endl; // Празен ред
			cout << "Enter your choice: "; // Избор на опция
			cin >> choice_d; // Въвеждане на опция
			cout << endl; // Празен ред
			switch (choice_d) 
			{
			case 1: // Най-малка наличност
				min_availability(currency, currencycount); // Извикване на функцията за минимална наличност
				break; // Прекратяване на операцията
			case 2: // Търсене
				search(currency, currencycount); // Извикване на функцията за търсене на валута
				break; // Прекратяване на операцията
			case 3: // Редактиране на наличност на валута
				break; // Прекратяване на операцията
			default: // Невалидна опция
				cout << "Wrong choice!" << endl; // Невалидна опция
				break; // Прекратяване на операцията
			}
		case 4: // Подреждане
			if (currencycount <= 0) { // Проверка дали броя на валутите е по-малък или равен на 0
				cout << "There are no currencies!" << endl; // Няма валути
				break; // Прекратяване на операцията
			}
			sort(currency, currencycount); // Извикване на функцията за сортиране на валутите
			break; // Прекратяване на операцията
		case 5: // Запазване или Четене от файл
			fmenu(); // Извикване на менюто за филтриране
			cout << endl; // Празен ред
			cout << "Enter your choice: "; // Избор на опция
			cin >> choice_f; // Въвеждане на опция
			cout << endl; // Празен ред
			switch (choice_f) 
			{
			case 1: // Филтриране на валутите по име
				filesave(currency, currencycount, x); // Извикване на функцията за запис във файл
				break; // Прекратяване на операцията
			case 2: // Филтриране на валутите по курс
				fileload(currency, currencycount, x); // Извикване на функцията за зареждане от файл
				break; // Прекратяване на операцията
			case 3: // Филтриране на валутите по наличност
				break; // Прекратяване на операцията
			default: // Невалидна опция
				cout << "Wrong choice!" << endl; // Невалидна опция
				break; // Прекратяване на операцията
			} 
			break;	// Прекратяване на операцията
		case 6: // Изход от програмата
			filesave(currency, currencycount, x);
			return 0; // Прекратяване на програмата
			break; // Прекратяване на операцията
		default: // Невалидна опция
			cout << "Wrong choice!" << endl; // Невалидна опция
			break; // Прекратяване на операцията
		} 
	} while (choice < 6 || choice > 6); // Условие за изход от цикъла
}