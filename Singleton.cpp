#include <iostream>
using namespace std;

class Singleton
{
private:
	static Singleton* instance;

	// Private constructor to prevent instantiation
	Singleton() {
		cout << "Singleton Instance Created" << endl;
	}
public:
	static Singleton* getInstance() {
		if (instance == nullptr) {
			instance = new Singleton();
		}
		return instance;
	}
	void showMessage() {
		cout << "Hello from Singleton!" << endl;
	}

	//Singleton(Singleton& other) = delete; // Prevent copy-construction
	//void operator=(const Singleton&) = delete; // Prevent assignment
	//Singleton(Singleton&& other) = delete; // Prevent move-construction
	//void getInstance(Singleton&&) = delete; // Prevent move-assignment

};
Singleton* Singleton::instance = nullptr;
int main()
{
	Singleton* singleton1 = Singleton::getInstance();
	singleton1->showMessage();
	return EXIT_SUCCESS;
}