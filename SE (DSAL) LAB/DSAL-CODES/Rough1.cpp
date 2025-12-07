#include<iostream>

using namespace std;

class node{
    public:
    string name;
    string telephone;
    int key;
    public:
    node(){
        key = 0;

    }
    friend class Hash;
};

int hashfunction(string s){
    int sum=0;
    for (int i = 0; s[i] != '\0'; i++)
        sum = sum + s[i];
        cout<<"sum"<<sum;
    return sum%10;
}

class Hash{
    public:
    node data[10];
    int size = 10;
    int index;
    string name;
    string telephone;

    public:
    Hash(){
        for(int i = 0;i<size;i++){
            data[i].name = "---";
            data[i].telephone = "000";
        }
    }

    void create(string n,string tele){
        //
        int k;
        index = hashfunction(n);
     
        for(int i=0;i<size;i++){
            if(data[index].key == 0 ){
                data[index].key = index;
                data[index].name = n;
                data[index].telephone = tele;
                break;
            }
            else{index = (index+1)%size;}
        }
        cout<<"Stored";
    }

    void display(){
            cout<<"\n\tKey"<<"\t\tName\t\tTelephone No.";
        for(int i =0;i<size;i++){
            cout<<"\n\t"<<data[i].key
            <<"\t\t"<<data[i].name
            <<"\t\t"<<data[i].telephone;
        }
    }

    void update(string n){
        int index = hashfunction(n);
        int flag =0;
        for(int i=0;i<size;i++){
            if(data[index].name==n){
                flag =1;
                break;

            }else{index=(index+1)%10;}
        }
        if(flag==1){
            cout<<"Enter New Name : ";
            cin>>data[index].name;
            cout<<"Enter New Telephone number";
            cin>>data[index].telephone;
            cout<<"Record Updated";
            

        }else{cout<<"Record Not Found";}

    }

    void search(string n){
        int index = hashfunction(n);

        for(int i=0;i<size;i++){
            if(data[index].name == n){
                cout<<"Record Found";
                cout<<"Name : "<<data[index].name;
                cout<<"Telephone No : "<<data[index].telephone;
                break;
            }
            else{
                index=(index+1)%10;
                }
        }
    }

    void delete1(string n){
        int index = hashfunction(n);

        for(int i=0;i<size;i++){
            if(data[index].name==n){
                data[index].key=0;
                data[index].name="--";
                data[index].telephone="00";
                cout<<"Record Delete success";
                break;
            }else{index=(index+1)%10;}
        }
    }

};

int main(){
    Hash h;
    string n;
    string tele;
    int key,ch,loop;
    loop = 1;

    
    while(loop){
        //
        cout<<"\n-------Menu------"<<endl
        <<"1 : Create\n2 : Display\n3 : search\n4 : Update\n5 : Delete\n6 : Exit\nEnter Choice : ";
    cin>>ch;
        switch(ch){
        case 1:
            cout<<"Enter Name : ";
            cin>>n;
            cout<<"Enter TelePhone Number : ";
            cin>>tele;
            h.create(n,tele);
            break;
        case 2:
            h.display();
            break;
        case 3:
            cout<<"Enter name to search : ";
            cin>>n;
            h.search(n);
            break;
        case 4:
            cout<<"Enter name to Update : ";
            cin>>n;
            h.update(n);
            break;
        case 5:
            cout<<"Enter name to delete : ";
            cin>>n;
            h.delete1(n);
            break;
        case 6:
            loop = 0;
            break;
        default:
            cout<<"Wrong choice";
            break;
        }
    }
    return 0;
}