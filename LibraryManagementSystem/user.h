#pragma once

#include <bits/stdc++.h>
using namespace std;

class User {
public:
    int id;
    string name;
    set<pair<int, string>> borrowed_books; // {Id,Book_Name}
    
    User();
    User(int uid, string uname);
    void BorrowBook(int bookid, string bookName);
    bool ReturnBook(int bookid , string bookname);
    void DisplayBorrowedBooks();

};