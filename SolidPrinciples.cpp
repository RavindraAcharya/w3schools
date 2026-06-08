#include <iostream>
using namespace std;
#include <vector>
/*
class student
{
private : 
	string name;
	int age;
public :
		student(string s, int a)
		{
			name = s;
			age = a;
		}
		
		int getAge()
		{
			return age;
		}

		string getName()
		{
			return name;
		}

		void setName(string s)
		{
			name = s;
		}
		
		void setAge(int a)
		{
			age = a;
		}


		void display()
		{
			cout << "Name : " << this->getName() << ", Age : " << this->getAge() << endl;
		}
};

class teacher
{
	private :
	string name;
	int salary;
	public :
		teacher(string s, int sal)
		{
			name = s;
			salary = sal;
		}
		
		int getSalary()
		{
			return salary;
		}
		string getName()
		{
			return name;
		}
		void setName(string s)
		{
			name = s;
		}
		
		void setSalary(int sal)
		{
			salary = sal;
		}
		void display()
		{
			cout << "Name : " << this->getName() << ", Salary : " << this->getSalary() << endl;
		}
};

int main()
{
	cout << "Solid Principles in C++" << endl;
	student s1("Alice", 20);	
	s1.display();
	s1.setName("Ravi");
	s1.display();

	teacher t1("Mr. Smith", 50000);
	t1.display();
	return 0;
}
*/

struct Journal
{
	string name;
	vector<string> entries;

	Journal(const string& sz_name) : name(sz_name)
	{
		cout << "Journal Object Created !" << endl;
	}

	void add_entries(string& entry)
	{
		static int count = 1;
		entries.push_back(entry);

	}


};

int main()
{
	Journal J1("Ravi");
	//J1.add_entries("Ravi");
	Journal J2("Acharya");
	return EXIT_SUCCESS;
}