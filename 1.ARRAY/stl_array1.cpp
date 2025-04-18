/*
   ----------------------------------------------------------------------------
   C++ STL Array: Detailed Notes and Example Code with Element Access,
   Modification, "Deletion", and "Insertion" (via Assignment)
   ----------------------------------------------------------------------------

   Overview:
     - std::array is a fixed-size sequential container introduced in C++11,
       defined in the <array> header.
     - It wraps a native, static array into a class template that stores its size,
       ensuring safe element access and providing many convenient member functions.
     - Underlying implementation: A contiguous block of memory like a native array.

   Declaration & Initialization:
     - Syntax:
           std::array<data_type, size> name;
       Example:
           std::array<int, 5> arr;
     - Initialization using an initializer list:
           std::array<int, 5> arr {1, 2, 3, 4, 5};

   Member Functions and Operations (with Complexity and Use Cases):

     1. operator[](i)
          - Direct subscript access to the element at index i.
          - Complexity: O(1); no bounds checking.
          - Usage: arr[i]

     2. at(i)
          - Access element at index i with runtime bounds checking.
          - Complexity: O(1); throws std::out_of_range for invalid index.
          - Usage: arr.at(i)

     3. std::get<>
          - A free (non-member) function provided in <tuple> (and re-exported by <array>).
          - Requires a compile-time constant index.
          - Complexity: O(1); the index is validated at compile time.
          - Usage: std::get<index>(arr)

     4. front() and back()
          - Return the first and last elements respectively.
          - Complexity: O(1).
          - Usage: arr.front(), arr.back()

     5. size() and max_size()
          - Return the number of elements and the maximum capacity (for std::array, both are equal).
          - Complexity: O(1).
          - Usage: arr.size(), arr.max_size()

     6. data()
          - Returns a pointer to the underlying array.
          - Complexity: O(1).
          - Usage: arr.data()

     7. begin() / end(), empty()
          - Provide iterator support and an empty check.
          - Complexity: O(1).
          - Usage: arr.begin(), arr.end(), arr.empty()

     8. fill(val)
          - Assigns the value 'val' to every element in the array.
          - Complexity: O(n).
          - Usage: arr.fill(val)

     9. swap(other)
          - Exchanges the contents with another std::array of the same type and size.
          - Complexity: O(n).
          - Usage: arr.swap(other)

   Fixed-Size Constraints & "Insertion":
     - std::array has a fixed size determined at compile time.
     - It does not provide a dynamic insert() function (like std::vector) because
       its capacity cannot change.
     - You can, however, modify an existing element. For example, in an array
       where only part of the elements are "used" (or initialized), you can assign
       a value to a free (default-initialized) slot.
 
   Simulated "Deletion":
     - As the size is fixed, deletion is simulated by shifting elements and
       marking unused slots with a default value.

   ----------------------------------------------------------------------------
*/

#include <iostream>
#include <array>
#include <tuple>      // For std::get
#include <stdexcept>  // For std::out_of_range
#include <algorithm>  // For std::remove and std::fill

using namespace std;

int main() {
    // ---------------------------------------------------------
    // Part 1: Standard std::array Operations and Element Access
    // ---------------------------------------------------------
    
    // Declaration and Initialization
    array<int, 5> arr { 1, 2, 3, 4, 5 };

    // 1. Using operator[] (no bounds checking)
    cout << "Elements using operator[]:" << endl;
    for (size_t i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";

    // 2. Using at() with bounds checking
    cout << "Access via at():" << endl;
    try {
        cout << "Element at index 2: " << arr.at(2) << "\n";
        // Uncomment the next line to see an exception if index is out-of-range:
        // cout << "Element at index 10: " << arr.at(10) << "\n";
    }
    catch (const out_of_range &e) {
        cout << "Exception caught: " << e.what() << "\n";
    }
    cout << "\n";

    // 3. Using std::get<> (compile-time constant index)
    cout << "Access via std::get<>:" << endl;
    cout << "Element at index 2: " << std::get<2>(arr) << "\n\n";

    // 4. Using front() and back() to access first and last elements
    cout << "Using front() and back():" << endl;
    cout << "First element: " << arr.front() << "\n";
    cout << "Last element: " << arr.back() << "\n\n";

    // 5. Using size() and max_size()
    cout << "Size of array: " << arr.size() << "\n";
    cout << "Maximum size of array: " << arr.max_size() << "\n\n";

    // 6. Accessing underlying array using data()
    int* pData = arr.data();
    cout << "First element via data(): " << *pData << "\n\n";

    // 7. Iterating using begin() and end()
    cout << "Elements using iterators (begin()/end()):" << endl;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n\n";

    // 8. Checking if the array is empty using empty()
    cout << "Is array empty? " << (arr.empty() ? "Yes" : "No") << "\n\n";

    // 9. Using fill() to set all elements to a new value
    arr.fill(10);
    cout << "Array after fill(10): ";
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << "\n\n";

    // 10. Using swap() to exchange content with another array
    array<int, 5> arr2 { 5, 4, 3, 2, 1 };
    cout << "Second array before swap: ";
    for (auto x : arr2)
        cout << x << " ";
    cout << "\n";
    
    arr.swap(arr2);
    cout << "First array after swap: ";
    for (auto x : arr)
        cout << x << " ";
    cout << "\n";
    cout << "Second array after swap: ";
    for (auto x : arr2)
        cout << x << " ";
    cout << "\n\n";

    // Detailed demonstration of element access using operator[], at(), and std::get<>
    cout << "Detailed element access demonstration:" << endl;
    for (size_t i = 0; i < arr.size(); i++) {
        cout << "Index " << i << ": ";
        cout << "operator[] = " << arr[i] << ", at() = " << arr.at(i);
        // Using std::get<> requires compile-time constant indices.
        switch(i) {
            case 0: cout << ", std::get = " << std::get<0>(arr); break;
            case 1: cout << ", std::get = " << std::get<1>(arr); break;
            case 2: cout << ", std::get = " << std::get<2>(arr); break;
            case 3: cout << ", std::get = " << std::get<3>(arr); break;
            case 4: cout << ", std::get = " << std::get<4>(arr); break;
            default: cout << ", std::get = N/A"; break;
        }
        cout << "\n";
    }
    cout << "\n";

    // ---------------------------------------------------------
    // Part 2: "Deleting" an Element from a Fixed-Size std::array
    // ---------------------------------------------------------
    // Note: std::array has fixed size, so deletion must be simulated by shifting.
    
    // Example A: Manual deletion by index (shifting left)
    array<int, 5> arrDel { 100, 200, 300, 400, 500 };
    cout << "Array before deletion (manual shift): ";
    for (auto x : arrDel)
        cout << x << " ";
    cout << "\n";

    size_t indexToDelete = 2; // Delete element at index 2 (value 300)
    for (size_t i = indexToDelete; i < arrDel.size() - 1; i++) {
        arrDel[i] = arrDel[i+1];
    }
    // Mark the last element as 0 (default value) to indicate deletion.
    arrDel[arrDel.size()-1] = 0;

    cout << "Array after deletion at index 2 (manual shift): ";
    for (auto x : arrDel)
        cout << x << " ";
    cout << "\n\n";

    // Example B: Using std::remove to "delete" a specific value
    array<int, 7> arrRemove { 1, 2, 3, 4, 3, 6, 7 };  // Contains two '3's.
    cout << "Array before std::remove (removing value 3): ";
    for (auto x : arrRemove)
        cout << x << " ";
    cout << "\n";

    // remove() rearranges the elements so that those not equal to 3 appear first.
    auto newEnd = remove(arrRemove.begin(), arrRemove.end(), 3);
    // Fill the "removed" section with 0 to indicate unused space.
    fill(newEnd, arrRemove.end(), 0);

    cout << "Array after std::remove (value 3 removed): ";
    for (auto x : arrRemove)
        cout << x << " ";
    cout << "\n\n";

    // ---------------------------------------------------------
    // Part 3: Modifying / "Inserting" Elements in a Fixed-Size std::array
    // ---------------------------------------------------------
    // Note: std::array does not support a dynamic insert() since the size is fixed.
    // Instead, you can modify an element at an index that is default or unused.
    // For example, if an array is partially initialized, you can assign a value
    // to an unassigned position.

    // Create a partially initialized array (last two elements default to 0).
    array<int, 5> arrPartial { 100, 200, 300 };
    cout << "Partially initialized array:" << endl;
    for (auto x : arrPartial)
        cout << x << " ";
    cout << "\n";

    // "Insert" a value by assigning to an element that is still 0.
    // Here, we consider index 3 as available.
    arrPartial[3] = 400;
    cout << "After inserting 400 at index 3:" << endl;
    for (auto x : arrPartial)
        cout << x << " ";
    cout << "\n";

    // You can also "modify" an element at any valid index.
    // For example, change the element at index 1.
    arrPartial[1] = 250;
    cout << "After modifying index 1 to 250:" << endl;
    for (auto x : arrPartial)
        cout << x << " ";
    cout << "\n";

    return 0;
}
