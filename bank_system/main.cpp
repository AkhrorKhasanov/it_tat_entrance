#include <iostream>
#include <fstream>
using namespace std;

void show_balance(string user_login)
{
    string name, login, password, balance;
    
    ifstream f("data.txt");
    
    
    while (f >> name >> login >> password >> balance)
    {
        if (user_login == login)
        {
            cout << balance << endl;
            break;
        }
    }
}

void deposit(string user_login, int new_balance)
{
    if (new_balance > 0)
    {
        ifstream f("data.txt");
        ofstream f2("temp.txt");
        
        string name, login, password;
        int balance;
        
        while (f >> name >> login >> password >> balance)
        {
            if (user_login == login)
            {
                balance += new_balance;
            }
            f2 << name << " " << login << " " << password << " " << balance << endl;
        }
        
        f.close();
        f2.close();
        
        remove("data.txt");
        rename("temp.txt", "data.txt");
        
        cout << "Summa muvaffaqiyatli qo'shildi" << endl;
    }
    else
    {
        cout << "Qo'yiladigan summa 0 dan katta bo'lishi kerak" << endl;
    }
}

bool is_user_registered(string user_login)
{
    bool flag = false;
    string name, login;
    
    ifstream f("data.txt");
    
    if (f)
    {
        while (f >> name >> login)
        {
            if (user_login == login)
            {
                flag = true;
                break;
            }
        }
    }
    
    return flag;
}


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


void menu()
{
    int x;
    while (true)
    {
        cout << "Iltimos, tanlang: " << endl;
        cout << "1. Ro'yxatdan o'tish" << endl;
        cout << "2. Balansni ko'rish" << endl;
        cout << "3. Pul qo'yish" << endl;
        cout << "4. Pul yechish" << endl;
        cout << "5. Chiqish" << endl;
        cin >> x;

        if (x == 1)
        {
            register_user();
            break;
        } 
        else if (x == 2)
        {
            cout << "Loginingizni kiriting: " << endl;
            string l;
            cin >> l;
            
            if (is_user_registered(l))
            {
                show_balance(l);
            }
            else
            {
                cout << "Bunday foydalanuvchi ro'yxatdan o'tmagan" << endl;
            }
            break;
        }
        else if (x == 3)
        {
            cout << "Loginingizni kiriting: " << endl;
            string l;
            cin >> l;
            
            if (is_user_registered(l))
            {
                int b;
                cout << "Summani kiriting: " << endl;
                cin >> b;
                
                deposit(l, b);
                
                
            }
            else
            {
                cout << "Bunday foydalanuvchi ro'yxatdan o'tmagan" << endl;
            }
            break;
        }
        else if (x == 4)
        {
            cout << "4" << endl;
        }
        else if (x == 5)
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
    
    menu();

    return 0;
}