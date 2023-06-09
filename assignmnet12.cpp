// Company maintains employee information as employee ID, name, designation and salary. Allow user to add, delete information of employee. Display information of particular employee. If employee does not exist an appropriate message is displayed. If it is, then the system displays the employee details. Use index sequential file to maintain the data.

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class employee
{
public:
    char name[20];
    int id;
    char des[20];
    float salary;
};

class index
{
public:
    int emp_id;
    int position;
};

class admin
{
public:
    void store()
    {
        int i = 0;
        char choice;
        employee worker = employee();
        index in_worker = index();
        ofstream Sout;
        ofstream Iout;

        Sout.open("sequencial.txt", ios::out | ios::binary);
        Iout.open("index.txt", ios::out | ios::binary);
        do
        {
            cout << "\n\tEnter a Name of Employee     : ";
            cin >> worker.name;
            cout << "\n\tEnter ID of Employee    : ";
            cin >> worker.id;
            cout << "\n\tEnter a Designation of Employee : ";
            cin >> worker.des;
            cout << "\n\tEnter a Salary of Employee  : ";
            cin >> worker.salary;
            Sout.write((char *)&worker, sizeof(employee));
            in_worker.emp_id = worker.id;
            in_worker.position = i;
            Iout.write((char *)&in_worker, sizeof(index));
            i++;
            cout << "\n\tDo You Want to Add More Records: ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');
        Sout.close();
        Iout.close();
    }
    void display()
    {
        employee temp1 = employee();
        index temp2 = index();
        ifstream Sin;
        ifstream Iin;
        int i = 0;
        Sin.open("sequencial.txt", ios::in | ios::binary);
        Iin.open("index.txt", ios::in | ios::binary);
        Sin.seekg(0, ios::beg);
        Iin.seekg(0, ios::beg);
        while (Iin.read((char *)&temp2, sizeof(index)))
        {
            i = temp2.position * sizeof(employee);
            Sin.seekg(i, ios::beg);
            Sin.read((char *)&temp1, sizeof(employee));
            if (temp1.id != -1)
                cout << "\n\t" << temp1.name << "\t" << temp1.id << "\t" << temp1.des << "\t" << temp1.salary;
        }
        Sin.close();
        Iin.close();
    }
    void search()
    {
        int searchId;
        cout << "\nEnter the ID of the employee to search: ";
        cin >> searchId;

        employee temp1 = employee();
        index temp2 = index();
        ifstream Sin;
        ifstream Iin;
        bool found = false;

        Sin.open("sequencial.txt", ios::in | ios::binary);
        Iin.open("index.txt", ios::in | ios::binary);
        Sin.seekg(0, ios::beg);
        Iin.seekg(0, ios::beg);

        while (Iin.read((char *)&temp2, sizeof(index)))
        {
            if (temp2.emp_id == searchId)
            {
                int position = temp2.position * sizeof(employee);
                Sin.seekg(position, ios::beg);
                Sin.read((char *)&temp1, sizeof(employee));
                if (temp1.id != -1)
                {
                    cout << "\nEmployee Found:\n";
                    cout << "Name: " << temp1.name << endl;
                    cout << "ID: " << temp1.id << endl;
                    cout << "Designation: " << temp1.des << endl;
                    cout << "Salary: " << temp1.salary << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found)
            cout << "Employee with ID " << searchId << " not found." << endl;

        Sin.close();
        Iin.close();
    }
    void deleteRecord()
    {
        int deleteId;
        cout << "\nEnter the ID of the employee to delete: ";
        cin >> deleteId;

        employee temp1 = employee();
        index temp2 = index();
        fstream Sfile, Ifile;
        bool found = false;

        Sfile.open("sequencial.txt", ios::in | ios::out | ios::binary);
        Ifile.open("index.txt", ios::in | ios::out | ios::binary);
        Sfile.seekg(0, ios::beg);
        Ifile.seekg(0, ios::beg);

        while (Ifile.read((char *)&temp2, sizeof(index)))
        {
            if (temp2.emp_id == deleteId)
            {
                int position = temp2.position * sizeof(employee);
                Sfile.seekg(position, ios::beg);
                Sfile.read((char *)&temp1, sizeof(employee));
                if (temp2.emp_id != -1)
                {
                    // Mark the employee record as deleted
                    temp1.id = -1;
                    Sfile.seekp(position, ios::beg);
                    Sfile.write((char *)&temp1, sizeof(employee));

                    // Remove the index record
                    temp2.emp_id = -1;
                    Ifile.seekp(Ifile.tellg() - sizeof(index));
                    Ifile.write((char *)&temp2, sizeof(index));

                    cout << "\nEmployee with ID " << deleteId << " has been deleted." << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found)
            cout << "Employee with ID " << deleteId << " not found." << endl;

        Sfile.close();
        Ifile.close();
    }
};

int main()
{
    admin obj;
    obj.store();
    obj.display();
    obj.search();
    obj.deleteRecord();
    obj.display();

    return 0;
}