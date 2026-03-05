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
void showBooks(){

    if(library.empty()){
        cout<<"No books in library\n";
        return;
    }

    for(auto &b : library){

        cout<<"ID: "<<b.id<<" ";
        cout<<"Title: "<<b.title<<" ";

        if(b.issued)
            cout<<"(Issued)";
        else
            cout<<"(Available)";

        cout<<endl;
    }
}
void searchBook(){

    int id;
    cout<<"Enter Book ID to search: ";
    cin>>id;

    for(auto &b : library){

        if(b.id == id){

            cout<<"Book Found\n";
            cout<<"Title: "<<b.title<<" ";

            if(b.issued)
                cout<<"(Issued)";
            else
                cout<<"(Available)";

            cout<<endl;

            return;
        }
    }

    cout<<"Book not found\n";
}

int main(){

    int choice;

    while(true){

        cout<<"1 Add Book\n";
        cout<<"2 Show Books\n";
        cout<<"3 Search Book\n";
        cout<<"4 Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
    addBook();

else if(choice==2)
    showBooks();

else if(choice==3)
    searchBook();

else if(choice==4)
    break;

        else
            cout<<"Invalid choice\n";
    }

    return 0;
}