#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Directory
{
private:
    string companyName;
    string owner;
    int phoneNumber;
    string address;

public:
    Directory(string companyName, string owner, int phoneNumber, string address):
    companyName(companyName),
    owner(owner),
    phoneNumber(phoneNumber),
    address(address)
    {}
    
    friend ostream& operator <<(ostream& os, const Directory& ex)
    {
        os << "Company name: "<< ex.companyName<<endl;
        os << "Owner: "<< ex.owner<<endl;
        os << "PhoneNumber: "<< ex.phoneNumber<<endl;
        os << "Address: "<< ex.address<<endl;
        
        return os;
    }
    
    string getCompanyName() const
    {
        return companyName;
    }
    
    void print()
    {
        cout<<"Company name: "<<companyName<<endl;
        cout<<"Owner: "<<owner<<endl;
        cout<<"Phone number: "<<phoneNumber<<endl;
        cout<<"Address: "<<address<<endl;
        cout<<endl;
    }
    
    
};

int main()
{
    vector<Directory> directoryList;
    while (true)
    {
        int choice;
        cout<< "Good afternoon, welcome to the program directory!"<<endl;
        cout<< "1. Search for the name.\n2. Print all.\n3. Addition.\nPress 0 to exit\n\nEnter the command: ";
        cin>>choice;
        if (choice == 0)
        {
            break;
        }
        
        if (choice == 1)
        {
            cin.ignore();
            string choice;
            cout<<"Search for the name\nEnter: ";
            getline(cin, choice);
            for (size_t i = 0; i < directoryList.size(); i++)
            {
                if (directoryList[i].getCompanyName() == choice)
                {
                    directoryList[i].print();
                }
                
            }
        }
        
        if (choice == 2)
        {
            for (size_t i = 0; i< directoryList.size(); i++)
            {
                cout<<"Data: "<<i + 1<<endl;
                directoryList[i].print();
            }
        }
        
        if (choice == 3)
        {
            cin.ignore();
            string newCompanyName;
            string newOwner;
            int newPhoneNumber;
            string newAddress;
            
            cout<<"Enter new companyName: ";
            getline(cin,newCompanyName);
            
            cout<<"Enter new owner: ";
            getline(cin,newOwner);
            
            cout<<"Enter new phone number: ";
            cin >> newPhoneNumber;
            
            cin.ignore();
            cout<<"Enter new address: ";
            getline(cin,newAddress);
            
            Directory newDirectory(newCompanyName, newOwner, newPhoneNumber, newAddress);
            
            
            directoryList.push_back(newDirectory);
            
            ofstream file("/Users/ivanrulevskiy/Desktop/WL/с ++/WorkingWithFiles/WorkingWithFiles/forPrint", std::ios::app);
                        
            if (!file.is_open())
            {
                cout << "Error open file" << endl;
            }
                        
            file << newDirectory;
            
            file.close();
        }
    }
}


//    Завдання 1.
//    Створити клас ДОВІДНИК з такими полями:
//    1.  Назва фірми;
//    2.  Власник;
//    3. Телефон;
//    4. Адреса;
//
//    Реалізувати такі можливості:
//    1.  Пошук за назвою;
//    2.  Показ усіх записів;
//    3.   Додавання.
//
//    Вся інформація має зберігатися у файлі, має бути реалізована можливість додавання нових даних.
