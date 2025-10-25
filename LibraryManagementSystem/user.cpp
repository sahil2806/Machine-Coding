#include "user.h"
#include <bits/stdc++.h>
using namespace std;

User :: User(int uid, string uname){
    this->id = uid;
    this->name = uname;
}

void User :: BorrowBook(int bookid, string bookName){
    borrowed_books.insert({bookid, bookName});
}

bool User :: ReturnBook(int bookid , string bookname){
    auto it  = borrowed_books.find({bookid, bookname});
    if(it != borrowed_books.end()){
        borrowed_books.erase(it);
        return true;
    }
    return false;
}

void User :: DisplayBorrowedBooks(){
    for(const auto& book : borrowed_books){
        cout << "Book ID: " << book.first << ", Book Name: " << book.second << endl;
    }
}
