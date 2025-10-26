# pragma once

#include <bits/stdc++.h>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int count;
    Book();
    Book(int book_id, string book_title, string book_author,int count);
};
