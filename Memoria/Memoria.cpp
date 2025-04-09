#include <iostream>
#include <chrono>
#include "MemoryPool.h"

using namespace std;
using namespace std::chrono;

void pool();
void stack();
void heap();

int main()
{
    auto number{ 10000000 };
    MemoryPool<int>::init(number);

    
   
    
    auto start = high_resolution_clock::now();

    for (size_t i = 0; i < number; i++)
    {
        stack();

    }
    auto end = high_resolution_clock::now();
    cout << "\nStack:";
    cout << duration_cast<milliseconds>(end - start).count() <<  " Milliseconds" << '\n';




    start = high_resolution_clock::now();

    for (size_t i = 0; i < number; i++)
    {
        heap();

    }
    end = high_resolution_clock::now();
    cout << "\nHeap:";
    cout << duration_cast<milliseconds>(end - start).count() << " Milliseconds" << '\n';


    start = high_resolution_clock::now();

    for (size_t i = 0; i < number; i++)
    {
        pool();

    }
    end = high_resolution_clock::now();
    cout << "\nPool:";
    cout << duration_cast<milliseconds>(end - start).count() << " Milliseconds" << '\n';
    



    
    
}

void pool() {

    MemoryPool<int>* bloco1 = MemoryPool<int>::malloc();
    *bloco1->get() = 42;
    MemoryPool<int>::mdelete(bloco1);

}

void stack() {
    int a = 42;
}

void heap() {
	int* a = new int(42);
	delete a;
}

