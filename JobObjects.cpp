#include <Windows.h>
#include <iostream>
using namespace std;

int main()
{
	HANDLE hJob = CreateJobObject(NULL, L"MyJobObject");

	if (hJob == NULL)
	{
		cout << "Failed to create Job Object. Error: " << GetLastError() << endl;
		return EXIT_FAILURE;
	}
	else
	{
		cout << "Job Object created successfully." << endl;
	}
	return EXIT_SUCCESS;
}