/*
   ----------------------------------------------------------------------------
   C++ STL Vector - Comprehensive Documentation and Working Examples
   ----------------------------------------------------------------------------

   Overview:
     std::vector is a dynamic array that stores a collection of elements of the
     same type in contiguous memory. It automatically resizes as elements are
     inserted or deleted. It is defined in the <vector> header file.
     
   All Member Functions (with brief descriptions):

   1. Element Insertion & Removal:
      - push_back()      : Adds an element at the end (O(1) amortized).
      - pop_back()       : Removes the last element (O(1)).
      - insert()         : Inserts element(s) at a specified position (O(n)).
      - emplace()        : Constructs and inserts an element at a specified position.
      - emplace_back()   : Constructs and inserts an element at the end.
      - assign()         : Replaces all elements with new ones (from value or range).
      - erase()          : Removes element(s) from a specified position or range.
      - clear()          : Removes all elements.

   2. Capacity & Memory Management:
      - size()           : Returns the number of elements.
      - max_size()       : Returns the maximum number of elements that can be held.
      - capacity()       : Returns the size of allocated storage.
      - empty()          : Checks if the vector is empty.
      - reserve()        : Requests change in capacity.
      - resize()         : Changes the number of elements.
      - shrink_to_fit()  : Requests to reduce capacity to size.

   3. Element Access:
      - operator[]      : Fast access by index (no bounds checking).
      - at()            : Access element by index with bounds checking.
      - front()         : Accesses the first element.
      - back()          : Accesses the last element.
      - data()          : Returns a direct pointer to the underlying array.

   4. Iterators:
      - begin(), end()         : Return iterator to the first and past-the-end element.
      - rbegin(), rend()       : Return reverse iterators.
      - cbegin(), cend()       : Return constant (read-only) iterators.
      - crbegin(), crend()     : Return constant reverse iterators.

   5. Miscellaneous:
      - swap()          : Swaps the contents with another vector.
      - get_allocator() : Returns a copy of the allocator object.
      
   Additional Points:
      - Vectors support 2D (and multi-dimensional) arrays by nesting std::vector.
      - When passing vectors to functions, always consider passing by reference
        to avoid unnecessary copying.

   ----------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>    // For std::find, std::remove, etc.
#include <iterator>     // For iterator functions
#include <stdexcept>    // For exception handling

using namespace std;

int main() {
    // ============================================================
    // Section A: Initialization and assign() Constructors
    // ============================================================
    {
        cout << "Section A: Initialization and assign()\n";

        // Empty vector:
        vector<int> vEmpty;
        
        // Initializer list:
        vector<int> vInit = { 1, 4, 2, 3, 5 };
        cout << "vInit (initializer list): ";
        for (int v : vInit) cout << v << " ";
        cout << "\n";

        // Vector with fixed size and default value:
        vector<int> vFixed(5, 9);  // five elements, all 9
        cout << "vFixed (5 elements of 9): ";
        for (int v : vFixed) cout << v << " ";
        cout << "\n";

        // Using assign() to set vector contents:
        vector<int> vAssign;
        vAssign.assign(3, 100);    // assign three elements of value 100
        cout << "vAssign (assign 3 elements of 100): ";
        for (int v : vAssign) cout << v << " ";
        cout << "\n\n";
    }

    // ============================================================
    // Section B: Capacity & Memory Management Functions
    // ============================================================
    {
        cout << "Section B: Capacity and Memory Management\n";

        vector<int> vCap = {1,2,3,4,5,6,7};
        cout << "vCap (initial): ";
        for (int v : vCap) cout << v << " ";
        cout << "\n";

        cout << "Size: " << vCap.size() << "\n";
        cout << "Capacity: " << vCap.capacity() << "\n";

        vCap.reserve(20);
        cout << "After reserve(20), Capacity: " << vCap.capacity() << "\n";

        vCap.resize(10);  // resize to 10 elements; new elements are value-initialized (0 for int)
        cout << "After resize(10), vCap: ";
        for (int v : vCap) cout << v << " ";
        cout << "\n";

        vCap.shrink_to_fit();
        cout << "After shrink_to_fit(), Capacity: " << vCap.capacity() << "\n";
        cout << "Is vCap empty? " << (vCap.empty() ? "Yes" : "No") << "\n\n";
    }

    // ============================================================
    // Section C: Element Access Functions
    // ============================================================
    {
        cout << "Section C: Element Access Functions\n";

        vector<int> vAccess = { 100, 200, 300, 400, 500 };

        // operator[]
        cout << "First element using operator[]: " << vAccess[0] << "\n";

        // at() with bounds checking
        try {
            cout << "Second element using at(): " << vAccess.at(1) << "\n";
            // Uncomment next line to see exception:
            // cout << vAccess.at(10) << "\n";
        } catch (const out_of_range &e) {
            cout << "Exception: " << e.what() << "\n";
        }

        // front() and back()
        cout << "Front element: " << vAccess.front() << "\n";
        cout << "Back element: " << vAccess.back() << "\n";

        // data()
        cout << "First element via data(): " << *(vAccess.data()) << "\n\n";
    }

    // ============================================================
    // Section D: Iterator Functions
    // ============================================================
    {
        cout << "Section D: Iterator Functions\n";

        vector<int> vIter = { 10, 20, 30, 40, 50 };
        
        // begin() and end()
        cout << "Forward iteration (begin/end): ";
        for (auto it = vIter.begin(); it != vIter.end(); ++it)
            cout << *it << " ";
        cout << "\n";

        // rbegin() and rend() for reverse iteration
        cout << "Reverse iteration (rbegin/rend): ";
        for (auto rit = vIter.rbegin(); rit != vIter.rend(); ++rit)
            cout << *rit << " ";
        cout << "\n";

        // constant iterators: cbegin() and cend()
        cout << "Const iteration (cbegin/cend): ";
        for (auto cit = vIter.cbegin(); cit != vIter.cend(); ++cit)
            cout << *cit << " ";
        cout << "\n";

        // constant reverse iterators: crbegin() and crend()
        cout << "Const reverse iteration (crbegin/crend): ";
        for (auto crit = vIter.crbegin(); crit != vIter.crend(); ++crit)
            cout << *crit << " ";
        cout << "\n\n";
    }

    // ============================================================
    // Section E: Modifiers (Insertion, Emplacement, Deletion, Clear, Swap)
    // ============================================================
    {
        cout << "Section E: Modifiers\n";

        vector<int> vMod = { 10, 20, 30, 40, 50 };
        cout << "Initial vMod: ";
        for (int v : vMod) cout << v << " ";
        cout << "\n";

        // push_back(): insert at end
        vMod.push_back(60);
        cout << "After push_back(60): ";
        for (int v : vMod) cout << v << " ";
        cout << "\n";

        // insert(): insert at a specific position
        // Insert 15 at beginning
        vMod.insert(vMod.begin(), 15);
        cout << "After insert at beginning (15): ";
        for (int v : vMod) cout << v << " ";
        cout << "\n";

        // emplace_back(): construct in-place at end
        vMod.emplace_back(70);
        cout << "After emplace_back(70): ";
        for (int v : vMod) cout << v << " ";
        cout << "\n";

        // emplace(): construct in-place at specific position
        // Insert 35 at index 3
        vMod.emplace(vMod.begin() + 3, 35);
        cout << "After emplace at index 3 (35): ";
        for (int v : vMod) cout << v << " ";
        cout << "\n";

        // pop_back(): remove last element
        vMod.pop_back();
        cout << "After pop_back(): ";
        for (int v : vMod) cout << v << " ";
        cout << "\n";

        // erase(): remove element at a specific position, e.g., remove element at index 2
        vMod.erase(vMod.begin() + 2);
        cout << "After erase at index 2: ";
        for (int v : vMod) cout << v << " ";
        cout << "\n";

        // clear(): remove all elements
        vector<int> vClear = { 1, 2, 3, 4, 5 };
        vClear.clear();
        cout << "After clear(), vClear size: " << vClear.size() << "\n";

        // swap(): exchange contents of two vectors
        vector<int> vA = { 1, 2, 3 };
        vector<int> vB = { 4, 5, 6 };
        cout << "Before swap:\nvA: ";
        for (int v : vA) cout << v << " ";
        cout << "\nvB: ";
        for (int v : vB) cout << v << " ";
        cout << "\n";
        vA.swap(vB);
        cout << "After swap:\nvA: ";
        for (int v : vA) cout << v << " ";
        cout << "\nvB: ";
        for (int v : vB) cout << v << " ";
        cout << "\n\n";
    }

    // ============================================================
    // Section F: Allocator Functions: get_allocator()
    // ============================================================
    {
        cout << "Section F: Allocator Access\n";

        vector<int> vAlloc = { 10, 20, 30 };
        // Get a copy of the allocator
        auto alloc = vAlloc.get_allocator();
        // Allocate raw memory for 3 ints (uninitialized)
        int* p = alloc.allocate(3);
        // Construct elements in allocated memory
        alloc.construct(p, 100);
        alloc.construct(p + 1, 200);
        alloc.construct(p + 2, 300);
        cout << "Values from allocated memory: ";
        for (int i = 0; i < 3; i++) {
            cout << *(p + i) << " ";
        }
        cout << "\n";
        // Destroy and deallocate memory
        alloc.destroy(p);
        alloc.destroy(p + 1);
        alloc.destroy(p + 2);
        alloc.deallocate(p, 3);
        cout << "\n";
    }

    // ============================================================
    // Section G: Multidimensional Vector (2D Vector)
    // ============================================================
    {
        cout << "Section G: 2D Vector Example\n";
        
        // Create a 2D vector (vector of vectors)
        vector<vector<int>> matrix = {
            { 1, 2, 3 },
            { 4, 5, 6 },
            { 7, 8, 9 }
        };
        cout << "2D Vector (Matrix):\n";
        for (const auto &row : matrix) {
            for (int val : row)
                cout << val << " ";
            cout << "\n";
        }
        cout << "\n";
    }
    
    // ============================================================
    // Section H: Passing Vector to a Function (By Reference)
    // ============================================================
    {
        cout << "Section H: Passing Vector to a Function\n";

        // Define a lambda to print a vector
        auto printVector = [](const vector<int>& vec) {
            for (int v : vec)
                cout << v << " ";
            cout << "\n";
        };

        vector<int> vPass = { 11, 22, 33, 44, 55 };
        cout << "Vector vPass: ";
        printVector(vPass);
        cout << "\n";
    }

    return 0;
}
