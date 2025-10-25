#include "book.h"
#include <bits/stdc++.h>
using namespace std;

Book::Book(int book_id, string book_title, string book_author,int count){
    this->id = book_id;
    this->title = book_title;
    this->author = book_author;
    this->count = count;
}