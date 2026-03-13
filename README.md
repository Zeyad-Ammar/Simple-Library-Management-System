<h1>Simple Library Management System (C++)</h1>

A console-based Library Management System implemented in C++.
This project was built as a practice exercise while learning data structures, structs, STL containers, and system design in C++.
The system allows managing books and users, borrowing and returning books, and searching the library collection.

<h3>Features</h3>
<img width="449" height="365" alt="image" src="https://github.com/user-attachments/assets/7f101108-e482-4439-951b-344e93c0ee48" />

Add new books to the library<br>
Add new users<br>
Borrow books<br>
Return borrowed books<br>
Search books by name prefix<br>
Display who borrowed a specific book<br>
List books sorted by ID<br>
List books sorted by name<br>
Display all users and their borrowed books<br>

<h2>System Design</h2>

<h3>The system is built using several structures:</h3>

<h3>stBook<br></h3>
Represents a book in the library.<br>

<h4>Attributes:</h4>
id → Book ID
name → Book name
quantity → Total copies
borrowingUsers → List of users currently borrowing the book

<h4>Functions:</h4>

Borrow a book
Return a book

<h3>stUser</h3>

Represents a user of the library.

<h4>Attributes:</h4>

id → User ID
name → User name
borrowedBooksIds → Set of borrowed book IDs

<h4>Functions:</h4>

Borrow a book
Return a book

<h3>stLibraryOperations</h3>

<h4>Handles core library logic such as:</h4>

Adding books<br>
Adding users<br>
Borrowing books<br>
Returning books<br>
Searching books<br>
Finding users/books<br>

<h3>stLibrarySystem</h3>

Handles the user interface and menu interaction.

<h3>Concepts Practiced</h3>

This project helped me practice:

C++ Structs<br>
STL containers<br>
vector<br>
set<br>
Algorithms<br>
sort<br>
find<br>
Basic object-like design using structs<br>
Searching and sorting<br>
Menu-driven console systems<br>
