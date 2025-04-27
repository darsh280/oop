#include <iostream>
#include <string>
using namespace std;

// Base class
class Person 
{
    protected:
        string name;
        int age;
    
    public:
        Person(string n, int a) : name(n), age(a) {}
        virtual void display() const 
        {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
        virtual ~Person() {}
};

// Derived class Student
class Student : virtual public Person 
{
    protected:  
        string rollNumber;
        string branch;
        int marks;
        float cgpa;
    
    public:
        // Constructor
        Student(string n, int a, string roll, string br, int m)
        : Person(n, a), rollNumber(roll), branch(br), marks(m) 
        {
            calculateCGPA();
        }
    
        Student() : Person("", 0), rollNumber(""), branch(""), marks(0), cgpa(0.0) {}
    
        void calculateCGPA() 
        {
            cgpa = marks / 10.0;
        }

        void display() const override 
        {
            cout << "Student Details:" << endl;
            Person::display();
            cout << "Roll Number: " << rollNumber << endl;
            cout << "Branch: " << branch << endl;
            cout << "Marks: " << marks << ", CGPA: " << cgpa << endl;
        }
    
        friend class Administration;
};

// Derived class Faculty
class Faculty : virtual public Person 
{
    protected:  
        string facultyID;
        string department;
        int salary;
    
    public:
        // Constructor
        Faculty(string n, int a, string id, string dept, int sal)
        : Person(n, a), facultyID(id), department(dept), salary(sal) {}
    
        // Default constructor needed for virtual inheritance
        Faculty() : Person("", 0), facultyID(""), department(""), salary(0) {}
    
        // Override display function
        void display() const override 
        {
            cout << "Faculty Details:" << endl;
            Person::display();
            cout << "Faculty ID: " << facultyID << endl;
            cout << "Department: " << department << endl;
            cout << "Salary: ₹" << salary << endl;
        }
    
        // Friend class declaration
        friend class Administration;
};

// Multiple inheritance
class TeachingAssistant : public Student, public Faculty 
{
    public:
        TeachingAssistant(string n, int a, string roll, string branch, int marks, string id, string dept, int sal)
        : Person(n, a), 
          Student(n, a, roll, branch, marks),
          Faculty(n, a, id, dept, sal) {}
    
    
        void display() const override 
        {
            cout << "Teaching Assistant Details:" << endl;
            Person::display();  // Display the base class data
            cout << "Roll Number: " << rollNumber << endl;
            cout << "Branch: " << branch << endl;
            cout << "Faculty ID: " << facultyID << endl;
            cout << "Department: " << department << endl;
            cout << "Salary: ₹" << salary << endl;
        }
};

class Administration 
{
    public:
        // Friend function to access private details
        void accessDetails(const Student& s, const Faculty& f) const 
        {
            cout << "Administration Friend Function:" << endl;
            cout << "Student " << s.name << " from " << s.branch << " scored " << s.marks << " marks." << endl;
            cout << "Faculty " << f.name << " teaches " << f.department << "." << endl;
        }
};

int main() 
{
    // Create objects
    Student s("Darshan", 20, "2023101", "CSE (AI-ML)", 92);
    Faculty f("Dr. A. Sharma", 45, "1001", "Computer Science", 120000);
    TeachingAssistant ta("Priya Desai", 25, "1923105", "CSE (AI-ML)", 89, "2005", "Artificial Intelligence", 35000);
    
    // Display details using virtual functions
    s.display();
    cout << endl;
    
    f.display();
    cout << endl;
    
    ta.display();
    cout << endl;
    
    // Use friend function to access private details
    Administration admin;
    admin.accessDetails(s, f);
    
    return 0;
}
