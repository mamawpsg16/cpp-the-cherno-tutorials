#pragma once  // Ensures this file is included only once during compilation

// Iterator class for the Vector
template<typename Vector>
class VectorIterator {
public:
    using valueType = typename Vector::valueType; // Type of elements in the Vector
    using pointerType = valueType*;              // Pointer to element type
    using referenceType = valueType&;            // Reference to element type

public:
    // Constructor to initialize iterator with a pointer to the Vector's data
    VectorIterator(pointerType ptr) :m_ptr(ptr) {}

    // Prefix increment operator (++it)
    VectorIterator& operator++() {
        m_ptr++;  // Move pointer to next element
        return *this; // Return updated iterator
    }

    // Postfix increment operator (it++)
    VectorIterator operator++(int) {
        VectorIterator iterator = *this;  // Copy current iterator state
        ++(*this);  // Increment current iterator
        return iterator;  // Return old iterator state
    }

    // Prefix decrement operator (--it)
    VectorIterator& operator--() {
        m_ptr--;  // Move pointer to previous element
        return *this;
    }

    // Postfix decrement operator (it--)
    VectorIterator operator--(int) {
        VectorIterator iterator = *this;
        --(*this);  // Decrement current iterator
        return iterator;
    }

    // Subscript operator to access element at offset index
    referenceType operator[](int index) {
        return *(m_ptr + index);
    }

    // Member access operator to access element members directly
    pointerType operator->() {
        return m_ptr;
    }

    // Dereference operator to access value pointed by iterator
    referenceType operator*() {
        return *m_ptr;
    }

    // Equality comparison
    bool operator==(const VectorIterator& other) const {
        return m_ptr == other.m_ptr;
    }

    // Inequality comparison
    bool operator!=(const VectorIterator& other) const {
        return m_ptr != other.m_ptr;
    }

private:
    pointerType m_ptr;  // Pointer to element in the Vector
};

// Dynamic array (Vector) implementation with custom iterator
template<typename T>
class Vector {
public:
    using valueType = T;  // Type of elements stored in the vector
    using iterator = VectorIterator<Vector<T>>;  // Custom iterator type

public:
    // Constructor initializes the vector with a small initial capacity
    Vector() {
        reallocate(2);  // Allocate space for 2 elements initially
    }

    // Adds an element to the end of the vector (by copy)
    void pushBack(const T& value) {
        if (m_size >= m_capacity) {  // Reallocate if the vector is full
            reallocate(m_capacity + m_capacity / 2);  // Increase capacity by 1.5x
        }
        m_data[m_size] = value;  // Store value at current size
        m_size++;  // Increase size
    }

    // Adds an element to the end of the vector (by move)
    void pushBack(T&& value) {
        if (m_size >= m_capacity) {
            reallocate(m_capacity + m_capacity / 2);
        }
        m_data[m_size] = std::move(value);  // Use move semantics
        m_size++;
    }

    // Constructs an element in-place at the end of the vector
    template<typename... Arguments>
    T& emplaceBack(Arguments&&... args) {
        if (m_size >= m_capacity) {
            reallocate(m_capacity + m_capacity / 2);
        }
        // Construct the new element directly in memory
        new(&m_data[m_size]) T(std::forward<Arguments>(args)...);
        return m_data[m_size++];  // Return reference to the new element
    }

    // Removes the last element from the vector
    void popBack() {
        if (m_size > 0) {
            m_size--;  // Decrease size
            m_data[m_size].~T();  // Explicitly call the destructor of the removed element
        }
    }

    // Clears all elements from the vector
    void clear() {
        for (size_t i = 0; i < m_size; i++) {
            m_data[i].~T();  // Call destructor for each element
        }
        m_size = 0;  // Reset size
    }

    // Accessor for elements by index (const for read-only)
    const T& operator[](size_t index) const {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");  // Bounds check
        }
        return m_data[index];
    }

    // Accessor for elements by index (modifiable)
    T& operator[](size_t index) {
        if (index >= m_size) {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    // Returns the number of elements in the vector
    size_t size() const {
        return m_size;
    }

    // Returns iterator pointing to the start of the vector
    iterator begin() {
        return iterator(m_data);
    }

    // Returns iterator pointing to the end of the vector
    iterator end() {
        return iterator(m_data + m_size);
    }

    // Destructor to free memory and destroy elements
    ~Vector() {
        clear();  // Destroy all elements
        ::operator delete(m_data, m_capacity * sizeof(T));  // Deallocate memory
    }

private:
    // Reallocates memory to increase capacity
    void reallocate(size_t newCapacity) {
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));  // Allocate new memory

        if (newCapacity < m_size) {
            m_size = newCapacity;  // Adjust size to fit within new capacity
        }

        for (size_t i = 0; i < m_size; i++) {
            new(&newBlock[i]) T(std::move(m_data[i]));  // Move elements to new block
        }

        for (size_t i = 0; i < m_size; i++) {
            m_data[i].~T();  // Destroy old elements
        }

        ::operator delete(m_data, m_capacity * sizeof(T));  // Free old memory
        m_data = newBlock;
        m_capacity = newCapacity;  // Update capacity
    }

private:
    T* m_data = nullptr;  // Pointer to data array
    size_t m_size = 0;    // Number of elements in vector
    size_t m_capacity = 0;  // Current allocated capacity
};
