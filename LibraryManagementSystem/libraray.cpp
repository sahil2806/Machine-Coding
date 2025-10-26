#include "library.h"
#include <bits/stdc++.h>
using namespace std;

// Library :: Library(){}

void Library :: AddBook(int book_id, string book_title, string book_author,int count){
    Book newbook(book_id, book_title, book_author,count);
    books[book_id] = newbook;
};

void Library :: AddUser(int user_id, string user_name){
    User newuser(user_id, user_name);
    users[user_id] = newuser;
};

Book* Library :: FindBookById(int book_id){
    auto it = books.find(book_id);
    if(it != books.end()){
        return &(it->second);
    }
    return nullptr;
};

User* Library:: FindUserById(int user_id){
    auto it = users.find(user_id);
    if(it != users.end()){
        return &(it->second);
    }
    return nullptr;
}


bool Library :: IssueBook(int user_id,int book_id){
    Book* book = FindBookById(book_id);
    User* user = FindUserById(user_id);

    if(book == nullptr || user == nullptr){
        return false;
    }

    if(book->count > 0){
        book->count -= 1;
        user->BorrowBook(book_id, book->title);
        return true;
    }
    return false;
};

bool Library :: ReturnBook(int user_id,int book_id){
    Book* book = FindBookById(book_id);
    User* user = FindUserById(user_id);

    if(book == nullptr || user == nullptr){
        return false;
    }

    user->ReturnBook(book_id,book->title);
    book->count += 1;
    return true;
};