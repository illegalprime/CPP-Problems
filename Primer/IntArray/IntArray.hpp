
class IntArray {
    public:
        // Default Constructor, from array, copy
        explicit IntArray(int sz = DEFAULT_SIZE);
                 IntArray(int* array, int array_sz);
                 IntArray(const IntArray& rhs);

        // equality and inequality operators
        bool operator==(const IntArray&) const;
        bool operator!=(const IntArray&) const;

        // Assignment operator
        IntArray& operator=(const IntArray&);

        int size() const;
        void sort();

        int min() const;
        int max() const;

        // If the value is found within the array,
        // return the index of the first occurence.
        // Otherwise return -1
        int find(int value) const;

        // Destructor!!
        ~IntArray();

        // Indexing style operator
        int& operator[](int index);

    private:
        int _size;
        int* backing;
        static const int DEFAULT_SIZE = 12;
}
