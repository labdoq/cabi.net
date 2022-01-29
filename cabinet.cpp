#include <iostream>
#include <string>
#include <conio.h>
 
using namespace std;

int CURRENT_USER_ID = 367;
int COUNT;

string users[5][2];

string hesh(string pas) {
    for (int i = 0; i < pas.length(); i++)
        pas[i] = int(pas[i]) - 19 + i;
    return pas;
}



int first_menu()
{
    int var;
    cout << "1. Authorization" << endl;
    cout << "2. Registration" << endl;
    cout << "3. Infromation about current user" << endl;
    cout << "4. Exit" << endl;
    cout << "> ";
    cin >> var;

    return var;
}


void Registration() {
    string pass;
   
    system("cls");

    cout << endl << "_______Registration_______" << endl;
    cout << "Login: ";
    cin >> users[COUNT][0];
    cout << "Password: ";
    cin >> pass;

    users[COUNT][1] = hesh(pass);
    pass = "";
   
    COUNT++;
}

void Authorization() {
    string login, password;
    int i = 0;
    int user_id = 0;

    system("cls");

    cout << endl << "_______Authorization_______" << endl;

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;
 
    for (i; i < 5; i++)
    {
        if (users[i][0] == login)
        {
            user_id = i;
            break;
        }
    }
	
    while (users[user_id][0] != login || users[user_id][1] != hesh(password)) {
    	
        system("cls");
        cout << "This user does not exist! Press ESC to exit." << endl;
        if (_getch() == 27) {
        	break;
		}
     }

    password = "";
   
    CURRENT_USER_ID = user_id;
}

void info() {
	int check;
    while (check != 27)
    {
	
		system("cls");

    	cout << "_______Current user_______" << endl;
    	if(CURRENT_USER_ID != 367)
    	{
			cout << users[CURRENT_USER_ID][0] << endl;
		}
    	cout << "Press ESC to exit.";
    	
    	check = getch();
	}
}

int main_page()
{
    system("cls");

    int variant;
    variant = first_menu();

    switch (variant)
    {
    case 1:
        Authorization();
        break;
    case 2:
        Registration();
        break;
    case 3:
        info();
        break;
    case 4:
        break;
    }

    return variant;
}

void Welcome() {
    for (int i = 0; i < 5; i++) {
        cout << "Login: " << users[i][0] << "  " << "Password: " << users[i][1] << endl;
    }
}


int main() {
    int check_exit = 0;

    while (check_exit != 4)
    {
        check_exit = main_page();
    }
   
}
