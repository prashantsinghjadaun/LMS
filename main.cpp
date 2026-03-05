#include <iostream>
#include <vector>
using namespace std;

struct Book{
    int id;
    string title;
    bool issued;
};

vector<Book> library;

void addBook(){

    Book b;

    cout<<"Enter Book ID: ";
    cin>>b.id;

    cout<<"Enter Book Title: ";
    cin.ignore();
getline(cin,b.title);

    b.issued=false;

    library.push_back(b);

    cout<<"Book Added Successfully\n";
}

int main(){

    int choice;

    while(true){

        cout<<"\nLibrary Management System\n";
        cout<<"1 Add Book\n";
        cout<<"2 Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
            addBook();

        else if(choice==2)
            break;

        else
            cout<<"Invalid choice\n";
    }

    return 0;
}