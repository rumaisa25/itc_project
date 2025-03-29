#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main()
{  
	const int size = 10;  
	int op;              
	int IBAN;            
	string book[size] = { "Crime and Punishment", "Little Women", "If We Were Villains", "Kite Runner", "Never Lie", "The Cruel Prince", "Anna Karenina", "Rooftops of Tehran", "The Paris Apartment", "Six of Crows" };  
	string author[size] = { "Fyodor Dostoevsky", "Louisa May Alcott", "M. L. Rio", "Khalid Huseini", "Freida McFadden", "Holly Black", "Leo Tolstoy", "Mahbod Seraji", "Lucy Foley", "Leigh Bardugo" };  
	string publisher[size] = { "Penguin Classics", "Roberts Brothers", "Flatiron Books", "Riverhead Books", "Sourcebooks", "Little Brown Books", "Penguin Classics", "New American Library", "William Morrow", "Henry Holt & Co" };  
	int pubyear[size] = { 1866, 1868, 2017, 2003, 2022, 2018, 1878, 2009, 2022, 2015 };  
	int iban[size] = { 1207, 1202, 1303, 1404, 1403, 1200, 1307, 1311, 1201, 1210 }; 
	int count[size] = { 14, 6, 9, 5, 8, 13, 7, 6, 15, 8 }; //number of copies issued or returned
	int qty[size] = { 14, 6, 9, 5, 8, 13, 7, 6, 15, 8 };  //constant number of copies
	int num;  
	int exit = 1;  
	int issue, retrn;  
	char endpro;  //variable to continue do while loop after each iteration
	do  
	{
		cout << "Library Management System Menu:" << endl;
		cout << "1. Issue a Book \n2. Return a Book \n3. Display All Books Sorted by ISBN \n4. Exit" << endl;
		cout << "Enter your choice (1-5): ";
		cin >> op;  
		system("cls");  
		switch (op)  
		{
		case 1:  
		{
					 issue = 0;  //to reset value on next iteration
					 cout << "Issue a Book:" << endl;
					 cout << left<< setw(25)<<"Name"<<setw(12)<<"IBAN"<<setw(20)<<"Copies Available"<<setw(20)<<"Copies Issued" << endl;
					 cout << "_______________________________________________________________________"<< endl;
					 for (int i = 0; i < size; i++)  
					 {
						 if (count[i] > qty[i])  
						 {
							 qty[i] = count[i];
						 }
						 cout <<left<<setw(25)<< book[i] << setw(20) << iban[i] << setw(18) << count[i] - 1 << setw(20) << qty[i] - count[i] << endl;
					 }
					 cout << "Enter IBAN of Book: ";
					 cin >> IBAN;  
					 for (int i = 0; i < size; i++)  
					 {
						 if (IBAN == iban[i])  
						 {
							 cout << "Enter Number of Copies you Need: ";
							 cin >> num;  
							 if (num < count[i])  
							 {
								 cout << "Book: '" << book[i] << "' Issued Successfully" << endl;
								 cout << "______________________________" << endl;
								 count[i] = count[i] - num;  
							 }
							 else  
							 {
								 cout << "Number of Copies Unavailable" << endl;
								 cout << "______________________________" << endl;
							 }
							 issue = 1;  
						 }
					 }
					 if (issue == 0) //if IBAN is invalid
					 {
						 cout << "IBAN not found" << endl;
						 cout << "______________________________" << endl;
					 }
					 cout << "Enter any character to Continue : ";
					 cin >> endpro;  
					 system("cls");  
		}
			break;

		case 2:  
		{
					 retrn = 0;  
					 cout << "Return a Book:" << endl;
					 cout << left<<setw(25)<<"Name"<<setw(12)<< "IBAN"<<setw(20)<<"Copies Available"<<setw(12)<<"Copies Issued" << endl;
					 cout << "______________________________________________________________________" << endl;
					 for (int i = 0; i < size; i++)  
					 {
						 if (count[i] > qty[i])  
						 {
							 qty[i] = count[i];
						 }
						 cout <<left<<setw(25)<< book[i] << setw(20) << iban[i] << setw(18) << count[i] - 1 << setw(18) << qty[i] - count[i] << endl;
					 }
					 cout << "Enter IBAN of Book: ";
					 cin >> IBAN;  
					 for (int i = 0; i < size; i++)  
					 {
						 if (IBAN == iban[i])  
						 {
							 cout << "Enter Number of Copies to Return: ";
							 cin >> num;  
							 if (num == count[i])
							 {

								 cout << "Book Returned Successfully" << endl;
								 cout << "______________________________" << endl;
								 count[i] = count[i] + num;
								 retrn = 1;
							 }
							 else{
								 cout << "Invalid entry" << endl;
							 }
						 }
					 }
					 if (retrn == 0)  
					 {
						 cout << "IBAN not found" << endl;
						 cout << "______________________________" << endl;
					 }
					 cout << "Enter any character to Continue : ";
					 cin >> endpro;  
					 system("cls");  
		}
			break;
		case 3:  
		{
					 cout << "Display All Books Sorted by ISBN:" << endl;
					 for (int i = 0; i < size; i++)  
					 {
						 for (int j = i + 1; j < size; j++)
						 {
							 if (iban[i] > iban[j])
							 {
								 string temp_book = book[j];  //sorting all arrays with respect to isbn array
								 book[j] = book[i];
								 book[i] = temp_book;

								 string temp_author = author[j];
								 author[j] = author[i];
								 author[i] = temp_author;

								 string temp_pub = publisher[j];
								 publisher[j] = publisher[i];
								 publisher[i] = temp_pub;

								 int temp_year = pubyear[j];
								 pubyear[j] = pubyear[i];
								 pubyear[i] = temp_year;

								
								 int temp_isbn = iban[j];
								 iban[j] = iban[i];
								 iban[i] = temp_isbn;

								 int temp_count = count[j];
								 count[j] = count[i];
								 count[i] = temp_count;

								 int temp_qty = qty[j];
								 qty[j] = qty[i];
								 qty[i] = temp_qty;
							 }
						 }
					 }
					 cout << left << setw(10) << "ISBN" << setw(25) << "Name" << setw(22) << "Author" << setw(18) << "Publisher" << setw(20) << "Publishing Year" << setw(10) << "Copies Available" << endl;
					 cout << "__________________________________________________________________________________________________________________" << endl;
					 for (int i = 0; i < size; i++) 
					 {
						 cout << left << setw(10) << iban[i] << setw(25) << book[i] << setw(20) << author[i] << setw(26) << publisher[i] << setw(20) << pubyear[i] << setw(10) << count[i] - 1 << endl;

					 }
					 cout << "___________________________" << endl;
					 cout << "Enter any character to Continue : ";
					 cin >> endpro;  
					 system("cls");  
		}
			break;
		
		case 4:  
		{
					 exit++;  //incrementing variable to terminate do while loop
					 cout << "Exit:" << endl;
					 cout << "Program has Ended" << endl;
					 cout << "___________________________" << endl;
		}
			break;
		default:  
		{
					  cout << "Invalid Input" << endl;
					  cout << "___________________________" << endl;
					  cout << "Enter any character to Continue : ";
					  cin >> endpro;  
					  system("cls");  
		}
		}
	} while (exit == 1);  //end of do while loop

	system("pause");  
	return 0;
}  