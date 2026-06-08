#include <stdio.h>
#include <iostream>
using namespace std;

//void display(int val[], int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        cout << "Data at position " << i << " is " << val[i] << endl;
//    }
//}
//
//int main()
//{
//    const int SIZE = 10;
//
//    int arr[SIZE] = { 10, 20, 30, 40, 50 };
//
//    arr[3] = 99; // Modify element
//
//    display(arr, SIZE); // Pass array and size
//
//    cout << "size of array : " << sizeof(arr) << endl;
//    printf("End of Program !");
//
//    return 0;
//}

#include <iostream>
using namespace std;

// Define a structure with data + behavior
struct Point {
    int x;
    int y;

    // Constructor
    Point(int px, int py) : x(px), y(py) {}

    // Member function
    void display() const {
        cout << "Point is at (" << x << ", " << y << ")" << endl;
    }
};

// Function that accepts a structure by value
void printPoint(Point p) {      
    cout << "Inside printPoint: (" << p.x << ", " << p.y << ")" << endl;
}

// Function that accepts a structure by reference (efficient for larger structs)
void movePoint(Point& p, int dx, int dy) {
    p.x += dx;
    p.y += dy;
    cout << "Point moved to (" << p.x << ", " << p.y << ")" << endl;
}

int main() {
    // Create a Point object
    Point pt(10, 20);

    // Call member function
    pt.display();

    // Pass structure to another function (by value)
    printPoint(pt);

    // Pass structure to another function (by reference)
    movePoint(pt, 5, -3);

    // Verify updated values
    pt.display();

    return 0;
}