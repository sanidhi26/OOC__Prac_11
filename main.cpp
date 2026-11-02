
#include <iostream>
#include <exception>
using namespace std;

// Custom exception class
class InvalidAgeException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Invalid Age! Age must be 18 or above.";
    }
};

// Person class
class Person
{
private:
    int age;

public:
    void getAge()
    {
        cout << "Enter your age: ";
        cin >> age;

        if (age < 18)
        {
            throw InvalidAgeException();
        }

        cout << "Valid age. Person is eligible." << endl;
    }
};

// Division function
double division(int a, int b)
{
    if (b == 0)
    {
        throw "Division by zero is not allowed!";
    }

    return (double)a / b;
}

int main()
{
    int a, b;

    // Division by zero exception
    cout << "Enter two numbers: ";
    cin >> a >> b;

    try
    {
        cout << "Division = " << division(a, b) << endl;
    }
    catch (const char* msg)
    {
        cout << "Exception: " << msg << endl;
    }

    // Invalid age exception
    Person p;

    try
    {
        p.getAge();
    }
    catch (const InvalidAgeException& e)
    {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

