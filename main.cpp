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
void issueBook(){

    int id;
    cout<<"Enter Book ID to issue: ";
    cin>>id;

    for(auto &b : library){

        if(b.id == id){

            if(b.issued){
                cout<<"Book already issued\n";
            }
            else{
                b.issued = true;
                cout<<"Book issued successfully\n";
            }

            return;
        }
    }

    cout<<"Book not found\n";
}
void returnBook(){

    int id;
    cout<<"Enter Book ID to return: ";
    cin>>id;

    for(auto &b : library){

        if(b.id == id){

            if(!b.issued){
                cout<<"Book was not issued\n";
            }
            else{
                b.issued = false;
                cout<<"Book returned successfully\n";
            }

            return;
        }
    }

    cout<<"Book not found\n";
}
void showRecentBooks(){

    if(library.empty()){
        cout<<"No books in library\n";
        return;
    }

    cout<<"\nNew Arrivals\n";
    cout<<"--------------------\n";

    int start = max(0, (int)library.size() - 3);

    for(int i = start; i < library.size(); i++){
        cout<<"ID: "<<library[i].id<<" ";
        cout<<"Title: "<<library[i].title<<endl;
    }
}
void totalBooks(){

    cout<<"Total books in library: "<<library.size()<<endl;

}
int main(){

    int choice;

    cout<<"=================================\n";
    cout<<"      Library Management System\n";
    cout<<"=================================\n";

    while(true){

        cout<<"\n";

        cout<<"1 Add Book\n";
        cout<<"2 Show Books\n";
        cout<<"3 Search Book\n";
        cout<<"4 Issue Book\n";
        cout<<"5 Return Book\n";
        cout<<"6 New Arrivals\n";
        cout<<"7 Total Books\n";
        cout<<"8 Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
    addBook();

else if(choice==2)
    showBooks();

else if(choice==3)
    searchBook();

else if(choice==4)
    issueBook();

else if(choice==5)
    returnBook();

else if(choice==6)
    showRecentBooks();

else if(choice==7)
    totalBooks();

else if(choice==8)
    break;

        else
            cout<<"Invalid choice\n";
    }

    return 0;
}