Simple Library Management System (C++)

A console-based Library Management System implemented in C++.
This project was built as a practice exercise while learning data structures, structs, STL containers, and system design in C++.
The system allows managing books and users, borrowing and returning books, and searching the library collection.

Features

Add new books to the library
Add new users
Borrow books
Return borrowed books
Search books by name prefix
Display who borrowed a specific book
List books sorted by ID
List books sorted by name
Display all users and their borrowed books

System Design

The system is built using several structures:

stBook
Represents a book in the library.
Attributes:
id → Book ID
name → Book name
quantity → Total copies
borrowingUsers → List of users currently borrowing the book

Functions:

Borrow a book
Return a book
stUser
Represents a user of the library.

Attributes:
id → User ID
name → User name
borrowedBooksIds → Set of borrowed book IDs

Functions:

Borrow a book
Return a book
stLibraryOperations

Handles core library logic such as:

Adding books
Adding users
Borrowing books
Returning books
Searching books
Finding users/books

stLibrarySystem

Handles the user interface and menu interaction.

Concepts Practiced

This project helped me practice:

C++ Structs
STL containers
vector
set
Algorithms
sort
find
Basic object-like design using structs
Searching and sorting
Menu-driven console systems
