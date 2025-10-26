#include "library.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    Library lib;
    lib.AddBook(1, "Motivation Book", "George Orwell", 5);
    lib.AddBook(2, "Harry Potter", "J.K. Rowling", 4);

    lib.AddUser(101, "Alice");
    lib.AddUser(102, "Bob");

    lib.IssueBook(101, 1);
    lib.IssueBook(101, 2);
    lib.IssueBook(102, 2);

    User* user1 = lib.FindUserById(101);
    user1->DisplayBorrowedBooks();

    lib.ReturnBook(101, 2);

    User* user2 = lib.FindUserById(101);
    user2->DisplayBorrowedBooks();
}