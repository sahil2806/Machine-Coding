#include "library.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    Library lib;
    lib.AddBook(1, "1984", "George Orwell", 5);
    lib.AddBook(2, "2005", "Herry Porter", 4);

    lib.AddUser(101, "Alice");
    lib.AddUser(102, "Bob");

    lib.IssueBook(101, 1);
    lib.IssueBook(102, 2);

    User* user1 = lib.FindUserById(101);
    user1->DisplayBorrowedBooks();
}