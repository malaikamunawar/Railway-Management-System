#include <iostream>

#include <cstring>

#include <conio.h>

#include <cstdio>

#include <fstream>

#include <sstream>

#include <iomanip>

#include <string>

using namespace std;

int p = 0;

int size;

//********************************************ARRAYS*************************************************

//TID is the Train ID

string TID[] =
    {

        "T101", "T102", "T103", "T104", "T105",

        "T106", "T107", "T108", "T109",
        "T110"};

string drivers[5];

//Drivers is an array that stores the name of drivers

//We have  a total of 10 trains

string arr_time[] =
    {

        "6am", "7am", "9pm", "10am", "11am",

        "2pm", "3pm", "5pm", "7am", "9pm"};

//stores the arrival time

string dep_time[] =
    {

        "6:15am", "7:15am", "9:15pm", "10:15am", "11:15am",

        "2:15pm", "3:15pm",
        "5:15pm", "7:10pm", "9:15pm"

};

//stores the departure time of all 10 trains

string train_name[] =
    {

        "Badar Express    ", "Badar Express    ", "Islamabad Express", "Islamabad Express",

        "Mianwali Express ", "Mianwali Express ", "Khyber Mail      ", "Khyber Mail      ",

        "Fareed Express   ", "Fareed Express   "

};

//**************************************DECLARATION OF FUNCTIONS*******************************************

void trains_available();

void add_train();

void issue_ticket(string name, int age, string address, int num);

void timetable();

void exit();


//*************************************FUNCTIONS DEFINITIONS*****************************************

void add_train(int train_no, string driver_name, string train_id, string st, string end)
{

    //int l=0;
    ofstream x("Train_no.txt", ios ::app);

    cout << "Enter train no: " << endl;

    cin >> train_no;

    if (!x.is_open())
    {
        cout << "Error. Couldn't open file" << endl;
    }

    else
    {

        while (train_no < 0 || train_no > 100)
        {
            cout << "Error. Enter valid Train number" << endl;
            cin >> train_no;
        }

        x << train_no << ",";
    }
    x.close();

    int v = 0;
    ofstream driv("Drivers_name.txt", ios ::app);
    cout << "Enter driver's name" << endl;
    cin.ignore();
    getline(cin, driver_name);
    int length = driver_name.length();

    if (!driv.is_open())
    {
        cout << "Error. Couldn't open file " << endl;
    }
    else
    {
        while (v < length)
        {
            if (((driver_name[v]) >= 65 && (driver_name[v]) <= 90) ||
                ((driver_name[v]) >= 97 && (driver_name[v]) <= 122))
            {
                for (int v = 0; v < length; v++)
                {
                }
            }
            else
            {
                cout << "invalid name " << endl;
                cout << "Enter alphabets only" << endl;
                cin >> driver_name;
            }
            v++;
            driv << driver_name[v];
        }
    }
    driv.close();

    cout << "Enter Train ID :" << endl;
    cin.ignore();
    getline(cin, train_id);
    int size = 4;
    ofstream id("Train_ID.txt", ios::app);
    //size of the string "train_id"
    if (!id.is_open())
    {
        cout << "Error. Couldn't open file " << endl;
    }
    else
    {

        for (int i = 0; i <= size; i++)
        {
            if ((train_id[0]) = 84)
            {
            }
            else
            {
                cout << "Invalid Train ID" << endl;
                cout << "Try entering an ID of formats like T101 or T102" << endl;
                cin >> train_id;
            }
        }
        id << train_id << ",";
    }

    id.close();

    ofstream s("starting_point.txt", ios ::app);
    cout << "Enter the starting point" << endl;
    cin.ignore();
    getline(cin, st);
    int st_size = st.length(); //size of the starting point
    if (!s.is_open())
    {
        cout << "Error. Couldn't open file " << endl;
    }
    else
    {
        for (int i = 0; i < st_size; i++)
        {
            if (

                ((st[i]) >= 65 && (st[i]) <= 90) ||
                ((st[i]) >= 97 && (st[i]) <= 122))
            {
            }
            else
            {
                cout << "invalid input " << endl;
                cout << "Enter alphabets only" << endl;
                cin >> st;
            }
        }
        s << "starting point is " << st << ",";
    }
    s.close();

    ofstream e("ending_point.txt", ios::app);
    cout << "Enter the ending point" << endl;
    cin.ignore();
    getline(cin, end);
    int end_size = end.length(); //size of the starting point
    if (!e.is_open())
    {
        cout << "Error. Couldn't open file " << endl;
    }
    else
    {
        for (int i = 0; i < end_size; i++)
        {
            if (

                ((end[i]) >= 65 && (end[i]) <= 90) ||
                ((end[i]) >= 97 && (end[i]) <= 122))
            {
            }
            else
            {
                cout << "invalid input " << endl;
                cout << "Enter alphabets only" << endl;
                cin >> end;
            }
        }
        e << "ending point is " << end << ",";
    }
    e.close();
    cout << "Train added successfully" << endl;
}

void trains_available()
{

    cout << "Please pick one of the train according to your route" << endl;

    cout << "    Train Name                Route            " << endl;

    cout << "1-  Badar Express        (LHR to Multan Cantt.)" << endl;

    cout << "2-  Badar Express        (Multan Cantt. to LHR)" << endl;

    cout << "3-  Islamabad Express    (LHR to Rawalpindi)" << endl;

    cout << "4-  Islamabad Express    (Rawalpindi TO LHR" << endl;

    cout << "5-  Mianwali Express     (LHR to Mari Indus)" << endl;

    cout << "6-  Mianwali Express     (Mari Indus to LHR)" << endl;

    cout << "7-  Khyber Mail          (LHR to Peshawar Cantt)" << endl;

    cout << "8-  Khyber Mail          (Peshawar Cantt to LHR)" << endl;

    cout << "9-  Fareed Express       (LHR to Karachi City)" << endl;

    cout << "10- Fareed Express       (Karachi City to LHR)" << endl;
}

void issue_ticket(string name, int age, string address, int num, int s, string m)
{
    //ofstream h("nameofpassengers.txt", ios ::app);
    int length = name.length();
    cout << "Enter your Name" << endl;
    cin.ignore();
    getline(cin, name);
    /*if (h.is_open())
    {
        cout << "Error. Couldn't open file " << endl;
    }
    else
    {
*/
    for (int i = 0; i < length; i++)
    {
    
        if (

            ((name[i]) >= 65 && (name[i]) <= 90) ||
            ((name[i]) >= 97 && (name[i]) <= 122))
        {
        }
        else
        {
            cout << "invalid name " << endl;
            cout << "Enter alphabets only" << endl;
            cin >> name;
        }
    }

    cout << "Enter your age" << endl;

    cin >> age;

    while (age > 120 && age < 0)
    {
        cout << "Error. Invalid age Try again" << endl;
        cin >> age;
    }

    cout << "Enter your area/locality: " << endl;

    cin >> address;

    int address_length = address.length();

    for (int i = 0; i < length; i++)
    {
        if (
            ((address[i]) >= 65 && (address[i]) <= 90) ||
            ((address[i]) >= 97 && (address[i]) <= 126))
        {
        }
        else
        {
            cout << "Enter valid district" << endl;
            cout << "(only alphabets are allowed)" << endl;
            cin >> address;
        }
    }

    {
        cout << "Please pick one of the train according to your destination" << endl;

        cout << "    Train Name                Route                  " << endl;

        cout << "1-  Badar Express        (LHR to Multan Cantt.)" << endl;

        cout << "2-  Badar Express        (Multan Cantt. to LHR)" << endl;

        cout << "3-  Islamabad Express    (LHR to Rawalpindi)" << endl;

        cout << "4-  Islamabad Express    (Rawalpindi TO LHR" << endl;

        cout << "5-  Mianwali Express     (LHR to Mari Indus)" << endl;

        cout << "6-  Mianwali Express     (Mari Indus to LHR)" << endl;

        cout << "7-  Khyber Mail          (LHR to Peshawar Cantt)" << endl;

        cout << "8-  Khyber Mail          (Peshawar Cantt to LHR)" << endl;

        cout << "9-  Fareed Express       (LHR to Karachi City)" << endl;

        cout << "10- Fareed Express       (Karachi City to LHR)" << endl;

        cout << "Enter Number: " << endl;

        cin >> num;

        switch (num)

        {

        case 1:

            cout << "You've chosen Badar Express" << endl;

            cout << "Train ID : T101" << endl;

            cout << "It goes from Lahore to Multan Cantt." << endl;

            cout << "30 seats are available in the train" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cin.clear();

            cout << "Here is your Ticket" << endl;

            cout << "Name :              " << name << endl;

            cout << "Age  :              " << age << endl;

            cout << "Locality:           "

                 << address << endl;

            cout << "Train name:         "
                 << "Badar Express" << endl;

            cout << "Train ID :          "
                 << "T101" << endl;

            cout << "Seat no: 120" << endl;

            break;

        case 2:

            cout << "You've chosen Badar Express" << endl;

            cout << "Train ID : T102" << endl;

            cout << "It goes from Multan Cantt. to LHR" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cout << "Here is your Ticket" << endl;

            cout << "Name :              " << name << endl;

            cout << "Age  :              " << age << endl;

            cout << "Locality:           " << address << endl;

            cout << "Train name:         "
                 << "Badar Express" << endl;

            cout << "Train ID :          "
                 << "T102" << endl;

            cout << "Seat no: 120" << endl;
            break;

        case 3:

            cout << "You've chosen Islamabad Express" << endl;

            cout << "Train ID : T103" << endl;

            cout << "It goes from LHR to Rawalpindi" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cout << "Here is your Ticket" << endl;

            cout << "Name :              " << name << endl;

            cout << "Age  :              " << age << endl;

            cout << "Locality:           " << address << endl;

            cout << "Train name:         "
                 << "Islamabad Express" << endl;

            cout << "Train ID :          "
                 << "T103" << endl;

            cout << "Seat no: 120" << endl;

            break;

        case 4:

            cout << "You've chosen Islamabad Express" << endl;

            cout << "Train ID : T104" << endl;

            cout << "It goes from Rawalpindi TO LHR" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cout << "Here is your Ticket" << endl;

            cout << "Name :              " << name << endl;

            cout << "Age  :              " << age << endl;

            cout << "Locality:           " << address << endl;

            cout << "Train name:         "
                 << "Islamabad Express" << endl;

            cout << "Train ID :          "
                 << "T104" << endl;

            cout << "Seat no: 120" << endl;

            break;

        case 5:

            cout << "You've chosen Mianwali Express" << endl;

            cout << "Train ID : T105" << endl;

            cout << "It goes from LHR to Mari Indus" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cout << "Here is your Ticket" << endl;

            cout << "Name :              " << name << endl;

            cout << "Age  :              " << age << endl;

            cout << "Locality:           " << address << endl;

            cout << "Train name:         "
                 << "Mianwali Express" << endl;

            cout << "Train ID :          "
                 << "T105" << endl;

            cout << "Seat no: 120" << endl;

            break;

        case 6:

            cout << "You've chosen Mianwali Express" << endl;

            cout << "Train ID : T106" << endl;

            cout << "It goes from Mari Indus to LHR" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cout << "Here is your Ticket" << endl;

            cout << "Name :              " << name << endl;

            cout << "Age  :              " << age << endl;

            cout << "Locality:           " << address << endl;

            cout << "Train name:         "
                 << "Mianwali Express" << endl;

            cout << "Train ID :          "
                 << "T106" << endl;

            cout << "Seat no: 120" << endl;

            break;

        case 7:

            cout << "You've chosen Khyber Mail" << endl;

            cout << "Train ID : T107" << endl;

            cout << "It goes from LHR to Peshawar Cantt" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cout << "Here is your Ticket" << endl;

            cout << "Name :              " << name << endl;

            cout << "Age  :              " << age << endl;

            cout << "Locality:           " << address << endl;

            cout << "Train name:         "
                 << "Khyber Mail" << endl;

            cout << "Train ID :          "
                 << "T107" << endl;

            cout << "Seat no: 120" << endl;

            break;

        case 8:

            cout << "You've chosen Khyber Mail" << endl;

            cout << "Train ID : T108" << endl;

            cout << "It goes from Peshawar Cantt to LHR" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cout << "Here is your Ticket" << endl;

            cout << "Name :              " << name << endl;

            cout << "Age  :              " << age << endl;

            cout << "Locality:           " << address << endl;

            cout << "Train name:         "
                 << "Khyber Mail" << endl;

            cout << "Train ID :          "
                 << "T108" << endl;

            cout << "Seat no: 120" << endl;

            break;

        case 9:

            cout << "You've chosen Fareed Express" << endl;

            cout << "Train ID : T109" << endl;

            cout << "It goes from LHR to Karachi City" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cout << "Here is your Ticket" << endl;

            cout << "Name :              "
                 << name << endl;

            cout << "Age  :              "
                 << age << endl;

            cout << "Locality:           "
                 << address << endl;

            cout << "Train name:         "
                 << "Fareed Express" << endl;

            cout << "Train ID :          "
                 << "T109" << endl;

            cout << "Seat no: 120" << endl;

            break;

        case 10:

            cout << "You've chosen Fareed Express" << endl;

            cout << "Train ID : T110" << endl;

            cout << "It goes from Karachi City to LHR" << endl;

            cout << "issuing your Ticket...." << endl;

            system("pause");

            cout << "Here is your Ticket" << endl;

            cout << "Name :              " << name << endl;

            cout << "Age  :              " << age << endl;

            cout << "Locality:           " << address << endl;

            cout << "Train name:         "
                 << "Fareed Express" << endl;

            cout << "Train ID :          "
                 << "T110" << endl;

            cout << "Seat no: 120" << endl;

            break;

        default:

            cout << "Invalid input" << endl;

            break;
        }
    }
}

void timetable()
{
    cout << "Train ID       Train name                 Arrival time         Departure time  " << endl;
    for (int i = 0; i < 10; i++)
    {

        cout << TID[i]
             << "      "
             << train_name[i]
             << "            "
             << arr_time[i]
             << "            "
             << dep_time[i]
             << endl;
    }
}

void exit()
{
    system("cls");
}

//*****************************************MAIN FUNCTION*******************************************

int main()
{

    cout << "*******************************************************************" << endl;

    cout << "                     WELCOME TO PAKISTAN RAILWAYS                  " << endl;

    cout << "*******************************************************************" << endl;

    string n;

    string add;

    int a;

    a = 0;

    string name;

    int d;

    string function;

    while (a = 100)
    {
        cout << "Press A to add train" << endl;

        cout << "Press S to show all the trains available" << endl;

        cout << "Press B to book a ticket" << endl;

        cout << "Press T to see the trains time table" << endl;

        cout << "Press E to exit" << endl;

        char i;

        cin >> i;

        if (i == 'A' or i == 'a')

        {

            add_train(d, name, name, name, name);
        }

        else if (i == 's' or i == 'S')

        {

            trains_available();
        }

        else if (i == 'B' or i == 'b')

        {

            issue_ticket(name, d, name, d, d, name);
        }

        else if (i == 'T' or i == 't')

        {

            timetable();
        }

        else if (i == 'E' or i == 'e')

        {
            exit();
        }

        else

        {
            cout << "invalid input" << endl;
        }

        char key;

        cout << "Taking you back to the menu" << endl;

        system("pause");
    }

    return 0;
}
