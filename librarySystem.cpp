#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

struct stBook {
	int id;
	string name;
	int quantity;
	
	vector<string> borrowingUsers;
	
	stBook() {
		id = 0;
		quantity = 0;
		
	}


	void  setInfo(int _id, string _name, int _quantity) {
		
		id = _id;
		name = _name;
		quantity = _quantity;

	}

	bool borrow(string userName) {
		
		if (quantity - borrowingUsers.size() == 0) {
			return 0;
		}

		borrowingUsers.push_back(userName) ;
		
		return 1;
	}


	bool back(string userName) {

		if (borrowingUsers.size() == 0)
			return 0;

		auto it = find(borrowingUsers.begin(), borrowingUsers.end(), userName);

		if (it != borrowingUsers.end()) {
			borrowingUsers.erase(it);
			return 1;

		}
		else
		{
			return 0;
		}
		
	}

};


struct stUser {
	int id;
	string name;
	set<int>  borrowedBooksIds;
	

	stUser() {
		id = 0;
	}

	void setInfo(int _id,string _name) {
		id = _id;
		name = _name;
	}

	void borrow(int bookId) {
		borrowedBooksIds.insert(bookId) ;
	}

	bool back(int bookId) {
		if (borrowedBooksIds.size() == 0)
			return 0;

		

		auto it = borrowedBooksIds.find(bookId);
		if (it == borrowedBooksIds.end())
			return 0;
	


		borrowedBooksIds.erase(it);

		return 1;

	}

};

struct stLibraryOperations {
	vector<stBook> books;
	vector<stUser> users;
	

	stLibraryOperations() {
		
	}

	void addBook(int id,string name,int quantity) {
		
		stBook book;
		book.setInfo(id, name, quantity);
		books.push_back(book);

	}

	

	void addUser(int id, string name) {
		stUser user;
		user.setInfo(id, name);
		users.push_back(user);
	}

	int findBookIdx(string bookName) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].name == bookName)
				return i;
		}

		return -1;
	}

	int findUserIdx(string userName) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].name == userName)
				return i;
		}

		return -1;
	}

	bool borrowBook(string bookName, string userName) {
	
		//find book
		int bIdx = findBookIdx(bookName);

		if (bIdx == -1) {
			return 0;
		}

		//find user
		int uIdx = findUserIdx(userName);

		if (uIdx == -1) {
			return 0;
		}

		if (!books[bIdx].borrow(userName)) {
			return 0;
		}
		users[uIdx].borrow(books[bIdx].id);

		return 1;
	}

	bool returnBook(string bookName, string userName) {

		//find book
		int bIdx = findBookIdx(bookName);

		if (bIdx == -1) {
			return 0;
		}

		//find user
		int uIdx = findUserIdx(userName);

		if (uIdx == -1) {
			return 0;
		}

		books[bIdx].back(userName);
		users[uIdx].back(books[bIdx].id);
		return 1;
	}

	bool isPrefix(string prefix, string bookName) {
		for (int i = 0; i < prefix.size(); i++) {
			if (prefix[i] != bookName[i])
				return 0;
		}
		return 1;
	}

};

bool compByName(stBook& f, stBook& s) {

	return f.name < s.name;

}

bool compById(stBook& f, stBook& s) {

	return f.id < s.id;

}

struct stLibrarySystem {

	stLibraryOperations library;

	void printMenu() {
		cout << "Library Menu;" << endl;
		cout << "1) add book\n";
		cout << "2) search books by prefix\n";
		cout << "3) print who borrowed book by name\n";
		cout << "4) print library by id book\n";
		cout << "5) print library by name\n";
		cout << "6) add user\n";
		cout << "7) user borrow book\n";
		cout << "8) user return book\n";
		cout << "9) print users\n";
		cout << "10) exist\n";


	}

	int readChoice() {
		cout << "Enter Your Choice [1 - 10]: ";
		int choice = -1;
		while (choice == -1) {
			cin >> choice;
			if (choice > 10 || choice < 1) {
				choice = -1;
			}

		}

		return choice;
	}

	void addBookScreen() {
		cout << "Enter book info: id & name & total quantity: ";
		int id; cin >> id;
		string name; cin >> name;
		int quantity; cin >> quantity;
		library.addBook(id, name, quantity);
	}

	void searchBookByPrefixScreen() {
		cout << "Enter book prefix: ";
		string prefix; cin >> prefix;

		bool found = 0;
		for (int i = 0; i < library.books.size(); i++) {
			const stBook& book = library.books[i];
			if (library.isPrefix(prefix, book.name)) {
				cout << book.name << endl;
				found = 1;
			}
		}

		if (!found) {
			cout << "No such a book with this prefix\n";
		}

	}

	void printWhoBorrowedBookScreen() {
		cout << "Enter book name: ";
		string bName; cin >> bName;

		int pos = library.findBookIdx(bName);
		if (pos == -1) {
			cout << "the book not available :(\n";
			return;
		}
		stBook theBook = library.books[pos];

		if (theBook.borrowingUsers.size() == 0) {
			cout << "No one borrowed this book\n";
		}else{
		   for (auto user:theBook.borrowingUsers) {
		   	cout << user << endl;
		   }
		}

	}

	void listLibraryById() {
		
		sort(library.books.begin(), library.books.end(), compById);
		
		for (auto book:library.books) {
			cout << "id = " << book.id << " name = " << book.name << " total quantity " << book.quantity << " total borrowed " << book.borrowingUsers.size() << endl;
		}

	}

	void listLibraryByName() {
		sort(library.books.begin(), library.books.end(), compByName);

		for (auto book : library.books) {
			cout << "id = " << book.id << " name = " << book.name << " total quantity " << book.quantity << " total borrowed " << book.borrowingUsers.size() << endl;
		}

	}

	void addUserScreen() {
		cout << "Enter user : name & national Id: ";
		string name; cin >> name;
		int id; cin >> id;

		library.addUser(id, name);

	}

	void borrowBookScreen() {

		cout << "Enter User Name and book name: ";
		string uName; cin >> uName;
		string bName; cin >> bName;

		if (!library.borrowBook(bName, uName)) {
			cout << "Error\n";
		}

	}

	void returnBookSreen() {

		cout << "Enter User name and book name: ";
		string uName; cin >> uName;
		string bName; cin >> bName;

		if (!library.returnBook(bName, uName)) {
			cout << "Error\n";
		}

	}


	void printUsersScreen() {


		for (auto user : library.users) {
			cout << "user " << user.name << " id " << user.id << " borrowed books ids: ";
			for (auto val : user.borrowedBooksIds) {
				cout << val << " ";
			}
			cout << "\n";
		}

		

	}

	void run() {
		printMenu();
		while (true) {
			int choice = readChoice();

			if (choice == 1) {
				//cout << "here add book screen";
				addBookScreen();
			}else if (choice == 2) {
				//cout << "here search book screen";
				searchBookByPrefixScreen();
			}
			else if (choice == 3) {
				//cout << "here print who borrowed book screen";
				printWhoBorrowedBookScreen();
			}
			else if (choice == 4) {
				//cout << "here print library by id screen";
				listLibraryById();
			}
			else if (choice == 5) {
				//cout << "here print library by name screen";
				listLibraryByName();
			}
			else if (choice == 6) {
			//	cout << "here add user screen";
				addUserScreen();
			}
			else if (choice ==7) {
				//cout << "here user borrow book screen";
				borrowBookScreen();
			}
			else if (choice == 8) {
				//cout << "here user return book screen";
				returnBookSreen();

			}
			else if (choice == 9) {
				//cout << "here print users screen";
				printUsersScreen();

			}
			else {
				break;
			}

		}
	}
};

int main() {
	stLibrarySystem system;
	system.run();

	return 0;
}