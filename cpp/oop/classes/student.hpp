#ifndef STUDENT_HPP
#define STUDENT_HPP
#include<string>

// User definied data type which represents blueprint for objects
// An empty class occupies 1 size, at least 1 size is required to get a memory address. if size will be 0 then multiple objects will have same memory address.
class student {
    private:
        std::string name;

    public:
        // constructor
        student (std::string name);

        // destructor
        ~student();

        // returns name
        std::string getName();
};

#endif 