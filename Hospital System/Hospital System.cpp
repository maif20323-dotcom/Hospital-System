/*
* =================================================================================
* Project Name  : Hospital System
* Description   : A console-based hospital management application built in C++ 
*                 using Object-Oriented Programming (OOP) concepts. Features 
*                 patient registration, doctor assignment, patient search, 
*                 and patient record listing using std::vector.
* Developer     : Eng. Mai Farag
* Architecture  : Object-Oriented Class-Based Design (OOP)
* Language      : C++
* =================================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Patient
{
private:
    string name;
    int age;
    string doctor;

public:
    Patient(string patientName, int patientAge)
    {
        name = patientName;
        age = patientAge;
        doctor = "Not Assigned";
    }

    string getName()
    {
        return name;
    }

    void assignDoctor(string doctorName)
    {
        doctor = doctorName;
    }

    void display()
    {
        cout << "Patient: " << name
             << " | Age: " << age
             << " | Doctor: " << doctor
             << endl;
    }
};

int main()
{
    vector<Patient> patients;

    int choice;

    do
    {
        cout << "\n=== Hospital System ===\n";
        cout << "1. Add Patient\n";
        cout << "2. Assign Doctor\n";
        cout << "3. Search Patient\n";
        cout << "4. Display All Patients\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1)
        {
            string name;
            int age;

            cout << "Enter patient name: ";
            cin >> name;

            cout << "Enter age: ";
            cin >> age;

            patients.push_back(Patient(name, age));

            cout << "Patient added.\n";
        }

        else if (choice == 2)
        {
            string patientName;
            string doctorName;

            cout << "Enter patient name: ";
            cin >> patientName;

            cout << "Enter doctor name: ";
            cin >> doctorName;

            bool found = false;

            for (Patient &patient : patients)
            {
                if (patient.getName() == patientName)
                {
                    patient.assignDoctor(doctorName);

                    cout << patientName
                         << " assigned to "
                         << doctorName << ".\n";

                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Patient not found.\n";
        }

        else if (choice == 3)
        {
            string name;

            cout << "Enter patient name: ";
            cin >> name;

            bool found = false;

            for (Patient &patient : patients)
            {
                if (patient.getName() == name)
                {
                    patient.display();
                    found = true;
                }
            }

            if (!found)
                cout << "Patient not found.\n";
        }

        else if (choice == 4)
        {
            if (patients.empty())
                cout << "No patients available.\n";
            else
            {
                for (Patient &patient : patients)
                {
                    patient.display();
                }
            }
        }

        else if (choice == 5)
        {
            cout << "Goodbye!\n";
        }

        else
        {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}