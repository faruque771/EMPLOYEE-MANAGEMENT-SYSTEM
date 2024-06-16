//#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
//#include <cstdio>
#include <fstream>
//#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<bits/stdc++.h>
using namespace std;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

class Employee_management
{
private:
    // Variables for employee details
    string name;
    char id[5];
    string designation;
    int age, salary;
    string experience;

public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

void Employee_management::menu() //Project Menu
{
    int password_user(); //login declaration
    password_user();
    //login screen
    while (true)
    {
        int choice;
        char x; // Options to choose an action
        system("cls");
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> EMPLOYE MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t\t\t 6. Exit" << endl;

        cout << "\t\t\t\t\t........................................." << endl;
        cout << "\t\t\t\t\t>> Choice Options:{ 1/ 2/ 3/ 4/ 5/ 6 }  <<" << endl;
        cout << "\t\t\t\t\t........................................." << endl;
        cout << "\n\n\n Enter Your Choice: "; // Taking the action input
//cout<< "\t\t\t__"<<endl; cin >> choice;
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
            do
            {
                insert();
                cout << "\n\n\t\t\t Add Another Employe Record Press ((Y || y)for Yes, (N || n) for NO) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            waitForEnter();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
            system("cls");
            cout << "\n\t\t\t>> EMPLOYE MANAGEMENT SYSTEM - By ERROR 404 TEAM<<\n\n\n";
            cout<<"\tThis PROJECT is done by:\n \t\t1. Ariful Hasan Adil \n \t\t2.Faruq Sadii \n \t\t3.Osman khawaja \n \t\t4. Towhid\n\n\n";
            Sleep(10000);
            exit(300);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
    }
}

void Employee_management::insert() // add data of employe
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Insert Data -------------------------------------------" << endl;
    cout << "\n Enter Name of Employee: ";
    cin >> name;
    cout << "\n Enter Employee ID [max 4 digits]: ";
    cin >> id;
    cout << "\n Enter Designation: ";
    cin >> designation;
    cout << "\n Enter Employee Age: ";
    cin >> age;
    cout << "\n Enter Employee Salary: ";
    cin >> salary;
    cout << "\n Enter Employee Experience: ";
    cin >> experience;
    file.open("Employee_Record.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
    file.close();
}

void Employee_management::display() // Display data of employe
{
    system("cls");
    int total = 1;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> salary >> experience;
        cout << "\n -------------------------------------------------------------------------------------------------\n\n";
        cout << "\n||    NAME    ||    ID    ||    DESIGNATION    ||    AGE    ||      SALARY      ||    EXPERIENCE   || \n\n";
        cout << "---------------------------------------------------------------------------------------------------\n\n";
        while (!file.eof())
        {
            cout << "\n";
            cout << total++ << ". " << name << " \t  " << id << "\t\t" << designation << "\t \t   " << age << "\t\t " << salary << "\t\t\t" << experience;
            file >> name >> id >> designation >> age >> salary >> experience;
        }
    }
    file.close();
    cout<<endl<<endl<<endl;
    waitForEnter();
}

void Employee_management::modify() // Modify data of employe
{
    system("cls");
    char checkId[5];
    int found = 0;
    fstream file, file1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Modify Data ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter employee id: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n Enter Name of Employee: ";
                cin >> name;
                cout << "\n Enter Employee ID [max 4 digits]: ";
                cin >> id;
                cout << "\n Enter Designation: ";
                cin >> designation;
                cout << "\n Enter Employee Age: ";
                cin >> age;
                cout << "\n Enter Employee Salary: ";
                cin >> salary;
                cout << "\n Enter Employee Experience: ";
                cin >> experience;
                cout << "\n\n\n\nSuccessfully Modify Details Of Employee\n\n\n";
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
                found++;
            }
            else
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
            }
            file >> name >> id >> designation >> age >> salary >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
    }
    waitForEnter();
}

void Employee_management::search() // Search data of employe
{                                  //Displays all details according to Employee's id
    system("cls");
    fstream file;
    char checkId[5];
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    cout << "\n\nEnter Employee ID: ";
    cin >> checkId;
    file >> name >> id >> designation >> age >> salary >> experience;
    if (!file)
    {
        cout << "\n\n\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n----------------------\n";
                cout << "Employee Name: " << name << "\n\n";
                cout << "Employee ID.: " << id << "\n\n";
                cout << "Employee Designation: " << designation << "\n\n";
                cout << "Employee Age: " << age << "\n\n";
                cout << "Employee Salary: " << salary << "\n\n";
                cout << "Employee Experience: " << experience << "\n";
                cout << "-----------------------\n\n\n";
            }
            file >> name >> id >> designation >> age >> salary >> experience;
        }
    }
    file.close();
    waitForEnter();
}

void Employee_management::deleted() // Delete data of employe
{
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
            }
            else
            {
                found++;
                cout << "\n\n\t\t\tSuccessfully Employee Data is Deleted\n";
            }
            file >> name >> id >> designation >> age >> salary >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found....Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
        waitForEnter();
    }
}

void Employee_management::waitForEnter()
{
    cout << ">>Press ENTER to go Back :: ";
    cin.get();
}

int password_user() // Employee Authentication
{
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    fstream file;
    char ch;
    system("cls");
    cout << "\n \t\t\t\t\t -------------------------------------------";
    cout << "\n\t\t\t\t\t||  WELCOME TO EMPLOYEE MANAGEMENT SYSTEM  ||";
    cout << "\n\t\t\t\t\t -------------------------------------------";
    cout << "\n\n\t\t\t\t\t   -| Press: [1] Register & [2] Login  |-";
    int selection;
    cout << "\n\nPlease Enter Value: ";
    cin >> selection;
    // if user press [1], then it would lead them to register.
    if (selection == 1)
    {
        system("cls");
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\t\t\t\t\t>> REGISTRATION EMPLOYEE <<";
        cout << "\n\t\t\t\t\t---------------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name_reg;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass_reg.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file.open("Ep_data.txt", ios::app);
        file << " " << name_reg << " " << pass_reg << "\n";
        file.close();
        cout << "\nRegistration Succesfully save";
        getch();
        password_user();
    }
    // if user press [2], then it would lead them to login.
    else if (selection == 2)
    {
        system("cls");
        file.open("Ep_data.txt", ios::in);
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\t\t\t\t\t>> LOGIN EMPLOYEE <<";
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\n\t\t\t\t\tEnter Your Name: ";
        cin >> name;
        cout << "\n\t\t\t\t\tEnter Your Password: ";
        ch = _getch();
        while (ch != 13)
        {
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file >> name_reg >> pass_reg;
        while (!file.eof())
        {
            if (pass == pass_reg && name == name_reg)
            {
                cout << "\n\n\n\t\t\t\t\t|  Verfiying EMPLOYEE  |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(10);
                    cout << "....";
                }
                cout<<endl<<endl;
                cout << "\n\nAccess Granted..\n\n";
                cout<<"Press Any Key to get access to the Menu___"<<endl;
                system("PAUSE");
                system("cls");
            }
            else
            {
                cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++)
                {
                    Sleep(500);
                    cout << "...";
                }
                cout << "\n\nAccess Aborted...\n";
                cout << "\nYou have type your Name or Password wrong\n";
                cout<<"\nOR ElSE you have not register Yet!!\n"<<endl;
                system("PAUSE");
                system("cls");
                password_user();
            }
            file >> name_reg >> pass_reg;
        }
        file.close();
    }
    else
    {
        cout << "\nInvalid Input.. Please Try Again..";
        password_user();
    }
    return 0;
}
int main()
{

     system("COLOR 80");
     int i, j;
     char symbols[] = {'@', '#', '$', '%', '&', '*', '+', '-', ':', '.', '!', '?', '/', '|', '\\', '(', ')', '[', ']', '{', '}'};
     int num_symbols = sizeof(symbols) / sizeof(symbols[0]);

     srand(time(NULL));

    // Print top border
    for (i = 0; i <= 80; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            gotoxy(i, j);
            cout<<symbols[rand() % num_symbols];
            fflush(stdout);
            Sleep(5);
        }
    }

    // Print bottom border
    for (i = 0; i <= 80; i++)
    {
        for (j = 21; j <= 24; j++)
        {
            gotoxy(i, j);
            cout<<symbols[rand() % num_symbols];
            fflush(stdout);
            Sleep(5);
        }
    }

    // Print left border
    for (i = 4; i <= 21; i++)
    {
        for (j = 1; j <= 2; j++)
        {
            gotoxy(j, i);
            cout<<symbols[rand() % num_symbols];
            fflush(stdout);
            Sleep(5);
        }
    }
    // Print right border
    for (i = 4; i <= 21; i++)
    {
        for (j = 77; j <= 80; j++)
        {
            gotoxy(j, i);
            cout<<symbols[rand() % num_symbols];
            fflush(stdout);
            Sleep(5);
        }
    }
    gotoxy(27,12);
    printf(">>WELCOME TO EMPLOYEE MANAGEMENT SYSTEM<<");
    fflush(stdout);
    Sleep(1000);
    system("cls");

    // Call the function
    Employee_management system;
    system.menu();
    return 0;
}
