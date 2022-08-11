#include <string>
#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    string phone;
    string email;
public:
    Person();
    Person(string nm, string ph, string em);
    string getName();
    string getPhone();
    string getEmail();
    void setName(string n);
    void setPhone(string p);
    void setEmail(string e);
    void printInfo();
};

Person::Person()
{
    name = "";
    phone = "";
    email = "";
}

Person::Person(string n, string p, string e)
{
    name = n;
    phone = p;
    email = e;
}

string Person::getName()
{
    return name;
}

string Person::getPhone()
{
    return phone;
}

string Person::getEmail()
{
    return email;
}

void Person::setName(string n)
{
    name = n;
}

void Person::setPhone(string p)
{
    phone = p;
}

void Person::setEmail(string e)
{
    email = e;
}

void Person::printInfo()
{
    cout << "Name: " << getName() << endl;
    cout << "Phone number: " << getPhone() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << endl;
}

class Employee :public Person
{
    string office;
    int salary;
public:
    Employee(string nm,string ph,string em, string off,int sal):Person(nm,ph,em),office(off),salary(sal)
    {
    }
    Employee(string off, int sal)
    {
        office = off;
        salary = sal;
    }
    Employee()
    {
        office = "";
        salary = 0;
    }
    string getOffice()
    {
        return office;
    }
    void setOffice(string off)
    {
        office = off;
    }
    int getSalary()
    {
        return salary;
    }
    void setSalary(int sal)
    {
        salary = sal;
    }
    void printInfo()
    {
        Person::printInfo();
        cout << "Office: " << getOffice() << endl;
        cout << "Salary: " << getSalary() << endl;
        cout << endl;
    }
};

class Faculty :public Employee
{
    string department;
    string rank;
public:
    Faculty(string nm, string ph, string em, string off, int sal, string dept, string rnk) 
    :Employee(nm, ph, em, off, sal), department(dept), rank(rnk)
    {
    }
    Faculty(string dept, string rnk)
    {
        department = dept;
        rank = rnk;
    }
    string getDepartment()
    {
        return department;
    }
    void setDepartment(string dept)
    {
        department = dept;
    }
    string getRank()
    {
        return rank;
    }
    void setRank(string rnk)
    {
        rank = rnk;
    }
    void printInfo()
    {
        Employee::printInfo();
        cout << "Department: " << getDepartment() << endl;
        cout << "Rank: " << getRank() << endl;
        cout << endl;
    }
};
class Staff :public Employee
{
    string title;
    public:
        Staff()
        {
            title = "";
        }
        Staff(string nm, string ph, string em, string off, int sal, string ttl) :Employee(nm, ph, em, off, sal)
        {
            title = ttl;
        }
        Staff(string ttl)
        {
            title = ttl;
        }
        string getTitle()
        {
            return title;
        }
        void setTitle(string ttl)
        {
            title = ttl;
        }
        void printInfo()
        {
            Employee::printInfo();
            cout << "Title: " << getTitle() << endl;
        }
};


int main()
{
    string nm;
    string ph;
    string em;
    string off;
    string ttl;
    int sal;

    cout << "What is the employees name? ";
    getline(cin, nm);
    cout << "What is the employees phone number? ";
    getline(cin, ph);
    cout << "What is the employees email? ";
    getline(cin, em);
    cout << "What office branch do you work in? ";
    getline(cin, off);
    cout << "What is your title at your job? ";
    cin >> ttl;
    cout << "What is your annual salary? $";
    cin >> sal;

    Staff p1(nm, ph, em, off, sal, ttl);

    p1.printInfo();


    return 0;
}