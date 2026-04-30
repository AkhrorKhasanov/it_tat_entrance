#include <iostream>
#include <fstream>
using namespace std;




void register_user()
{
    string name, login, password, new_name, new_login, new_password;
    int balance = 0;
    bool is_registered = false;

    while (!is_registered)
    {
        bool has_login = false;
        cout << "Iltimos, ism kiriting: " << endl;
        cin >> new_name;

        cout << "Iltimos, login kiriting: " << endl;
        cin >> new_login;

        cout << "Iltimos, parol kiriting: " << endl;
        cin >> new_password;

        ifstream f("data.txt");

        if (f)
        {

            while (f >> name >> login >> password)
            {
                if (login == new_login)
                {
                    cout << "Bunday login mavjud. Qaytadan ro'yxatdan o'ting." << endl;
                    has_login = true;
                    break;

                }
            }
            if (!has_login)
            {
                ofstream k("data.txt", ios::app);
                k << new_name << " " << new_login << " " << new_password << " " << balance << endl;
                k.close();
                is_registered = true;
                cout << "Siz ro'yxatdan o'tdingiz" << endl;
            }
        }
        else
        {
            ofstream k("data.txt", ios::app);
            k << new_name << " " << new_login << " " << new_password << " " << balance << endl;
            k.close();
            is_registered = true;
            cout << "Siz ro'yxatdan o'tdingiz" << endl;
        }
    }

    
}

void register_or_login()
{
    int x;
    while (true)
    {
        cout << "Iltimos, tanlang: " << endl;
        cout << "1. Ro'yxatdan o'tish" << endl;
        cout << "2. Tizimga kirish" << endl;
        cout << "3. Chiqish" << endl;
        cin >> x;

        if (x == 1)
        {
            cout << "Ro'yxatdan o'tish" << endl;
            register_user();
            break;
        } 
        else if (x == 2)
        {
            cout << "2" << endl;
            break;
        }
        else if (x == 3)
        {
            cout << "Tizimdan chiqdingiz." << endl;
            break;
        }
        else
        {
            cout << "To'g'ri tanlov kiriting!" << endl;
        }
        
    }
}

void menu()
{
    int x;
    while (true)
    {
        cout << "Iltimos, tanlang: " << endl;
        cout << "1. Balansni ko'rish" << endl;
        cout << "2. Pul qo'yish" << endl;
        cout << "3. Pul yechish" << endl;
        cout << "4. Chiqish" << endl;
        cin >> x;

        if (x == 1)
        {
            cout << "1" << endl;
            break;
        } 
        else if (x == 2)
        {
            cout << "2" << endl;
            break;
        }
        else if (x == 3)
        {
            cout << "3" << endl;
            break;
        }
        else if (x == 4)
        {
            cout << "Tizimdan chiqdingiz." << endl;
            break;
        }
        else
        {
            cout << "To'g'ri tanlov kiriting!" << endl;
        }
        
    }
}


int main() 
{
    
    register_or_login();

    return 0;
}