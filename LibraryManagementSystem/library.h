#pragma once

#include "book.h"
#include "user.h"
#include <bits/stdc++.h>
using namespace std;

class Library{
public:
    map<int,Book> books;
    map<int,User> users;

    // Library();

    void AddBook(int book_id, string book_title, string book_author,int count);
    void AddUser(int user_id, string user_name);

    bool  IssueBook(int user_id ,int book_id);
    bool  ReturnBook(int user_id ,int book_id);
    Book* FindBookById(int book_id);
    User* FindUserById(int user_id);

};