/*
This experiment is to clear out the confusion about reference and pointer(including raw and smart pointer).
Want to see the difference when:
1. Using reference and pointer with primitive types such as int, bool, char
2. Using reference and pointer with container such as vector, queue, deque, map
3. Using reference and pointer as arguments in function
*/

#include <iostream>
#include <thread>

void refTest(int &a, const int& b, int * p, int modify_value) {
    std::cout << "calling refTest " << std::endl;
    std::cout << "address of reference a: " << &a << std::endl;
    std::cout << "address of const reference b: " << &b << std::endl;
    std::cout << "address of pointer p: " << &p << std::endl << std::endl;

    std::cout << "content of a: " << a << std::endl;
    std::cout << "content of b: " << b << std::endl;
    std::cout << "content of p - pointer to a: " << p << std::endl;

    //Try to modify
    a = modify_value;
    std::cout << "content of a: " << a << std::endl;
    std::cout << "content of b: " << b << std::endl;
    std::cout << "value of p: " << *p << std::endl;
    std::cout << "end calling refTest " << std::endl;
}

void threadSafeTest(std::atomic<int>& ap, int modify_value) {
    std::thread::id _id = std::this_thread::get_id();
    std::cout << "\ncalling threadSafeTest " << std::endl;
    std::cout << "This is thread:" << _id << std::endl;
    
    std::cout << "address of atomic ap: " << &ap << std::endl << std::endl;
    std::cout << "content of atomic ap: " << ap << std::endl;
    //Try to modify
    ap = modify_value;
    std::cout << "value of ap: " << ap << std::endl;
    std::cout << "end calling threadSafeTest " << std::endl;
}

void testThread(int *p,int modify_value) {
    std::thread::id _id = std::this_thread::get_id();
    std::cout << "This is thread:" << _id << std::endl;
    int &ta = *p;
     std::cout << "address of ta reference to a: " << &ta << std::endl;
     std::cout << "content of ta reference to a: " << ta << std::endl;
    refTest(ta, ta, p, modify_value);

    return;
}

void sabotage(int *p,int modify_value) {
    std::thread::id _id = std::this_thread::get_id();
    std::cout << "This is thread:" << _id << std::endl;
    int &ta = *p;
     std::cout << "address of ta reference to a: " << &ta << std::endl;
     std::cout << "content of ta reference to a: " << ta << std::endl;
    refTest(ta, ta, p, modify_value);

    return;
}

int main() {
    int a = 10;
    int &b = a;
    int *p = &a;

    /*
    After inspecting the result,
    we can see that b (reference to a) is just an alias of a since they have the same address

    */
    std::cout << "address of a: " << &a << std::endl;
    std::cout << "address of b reference a: " << &b << std::endl;
    std::cout << "address of p - pointer to a: " << &p << std::endl << std::endl;

    std::cout << "content of a: " << a << std::endl;
    std::cout << "content of b: " << b << std::endl;
    std::cout << "content of p - pointer to a: " << p << std::endl;

    refTest(a, a, &a, 123);
    refTest(a, a, &a, 456);

    // std::thread thread_obj(refTest, a, a, &a, 333);
    // thread_obj.join();
    //There is a data race happened, this is not thread safe
    std::thread t1(testThread, &a, 199);
    std::thread t2(sabotage, &a, 320);
    t2.join();
    t1.join();
    
    std::cout << "Attempting threadsafe\n";
    std::atomic<int> cp = 777;

    std::cout << "address of atomic cp: " << &cp << std::endl;
    std::cout << "content of atomic cp: " << cp << std::endl;
    std::thread ts1(threadSafeTest, std::ref(cp), 222);
    std::thread ts2(threadSafeTest, std::ref(cp), 333);
    ts1.join();
    ts2.join();

    cp = 777;


    std::cout << "\n\n----------Try to reverse the join order to see what happen---------\n\n"; 
    std::thread ts3(threadSafeTest, std::ref(cp), 222);
    std::thread ts4(threadSafeTest, std::ref(cp), 333);
    ts4.join();
    ts3.join();

    return 0;
}