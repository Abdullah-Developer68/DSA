#include <iostream>
#include <vector>
using namespace std;

// --- Common methods for vectors

// size: returns the number of elements currently stored in the vector
// push_back: appends an element to the end of the vector, increasing its size
// pop_back: removes the last element from the vector, decreasing its size
// front: returns a reference to the first element in the vector (meaning the vector does not gets removed)
// back: returns a reference to the last element in the vector
// at: returns a reference to the element at a given index with bounds checking

int main()
{
    vector<int> vec; // 0
    vector<int> vec2 = {1, 2, 3};
    //    (size, value at each index)
    vector<int> vec3(3, 0);

    // This will give segmentation fault (means we are accessing a place in memory that is not possible because we don't have permission for it )
    // cout << vec[0];

    cout << "This is for vector 2" << endl;
    cout << vec2[0] << endl;

    // printing elements of vector 3 using for each loop
    cout << "The following is the result for vector 3" << endl;

    for (int val : vec3)
    {
        cout << "Value: " << val << endl;
        // type of val is equal to type of vec3
        cout << "Type of iterator: " << typeid(val).name() << endl;
    }
    return 0;
}