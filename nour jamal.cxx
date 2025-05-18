#include<iostream>
using namespace std;
int main()
{
 const int MAX_BOOKS = 100;
int bookIds[MAX_BOOKS];
string bookTitles[MAX_BOOKS];
string bookAuthors[MAX_BOOKS];
bool bookStatus[MAX_BOOKS];
int bookCount = 0;
 while (true) {
 displayMenu();
 int choice;
 cin >> choice;
 
 switch (choice) {
 case 1:
 addBook();
 break;
 case 2:
 displayBooks();
 break;
 case 3:
 borrowBook();
 break;
 case 4:
 returnBook();
 break;
 case 5:
 cout << "thank you" << endl;
 return 0;
 default:
 cout <<"error"<< endl;
 }
 }
}
 
void addBook() {
 if (bookCount >= MAX_BOOKS) {
 cout << "the library is full." << endl;
 return;
 }
 
 cout << "add a new book " << endl;
 cout << "enter the id book :";
 int id;
 cin >> id;
 
 for (int i = 0; i < bookCount; i++) {
 if (bookIds[i] == id) {
cout << "there is book has same the id." << endl;
 return;
 }
 }
 
 cout << "enter the title book: ";
 string title;
 cin >> title;
 
 cout << "enter the name of author : ";
 string author;
 cin >> author;
 
 bookIds[bookCount] = id;
 bookTitles[bookCount] = title;
 bookAuthors[bookCount] = author;
 bookStatus[bookCount] = false; 
 
 bookCount++;
 cout << "the book is add successful " << endl;
}
void displayBooks() {
 if (bookCount == 0) {
 cout << "the library is embity ." << endl;
return

 
 cout << "Book list" << endl;
 Cout <<ID" "Title" "Author" "Status << endl;
 
 for (int i = 0; i < bookCount; i++) {
 
 cout << bookIds[i] << " " << bookTitles[i] << " " << bookAuthors[i] << endl;
 }
}
void borrowBook() {
 if (bookCount == 0) {
 cout << "the library is embity." << endl;
 return;
 }
 
 cout << "Enter the ID of the book you want to borrow.: ";
 int id;
 cin >> id;
 
 bool found = false;
 for (int i = 0; i < bookCount; i++) {
 if (bookIds[i] == id) {
 found = true;
 if (bookStatus[i]) {
 cout << "The book is borrowed" << endl;
 } else {
 bookStatus[i] = true;
 cout << " The book has been successfully borrowed." << endl;
 }
 break;
 }
 }
 
 if (!found) {
 cout << "No book with the requested ID." << endl;
 }
}
void returnBook() {
 if (bookCount == 0) {
 cout << "the library is embity ." << endl;
 return;
 }
 
 cout << " Enter the ID of the book you want to return:"<<endl;
 int id;
 cin >> id;
 
 bool found = false;
 for (int i = 0; i < bookCount; i++) {
 if (bookIds[i] == id) {
 	found= true;
 if (!bookStatus[i]) {
 cout << " This book is currently not available for borrowing." << endl;
 } else {
 bookStatus[i] = false;
 cout << " The book has been returned successfully" << endl;
 }
 break;
 }
 }
 
 if (!found) {
 cout << " No book with the requested ID << endl;
 }
}
 return 0;