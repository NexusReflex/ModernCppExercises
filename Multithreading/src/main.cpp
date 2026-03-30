#include "MultiThreading.h"
#include <thread>
#include <iostream>

int main(){

    int n = 0;

    SafeQueue queue;

    auto producer_loop = [&n](SafeQueue& my_queue, std::string name){
        std::string message = "Thread " + name + " pushing message ";
        for (int i=0; i < 50; i++){
            my_queue.push(message + std::to_string(i));
            n++;
        }
    };
    
    
    std::thread thread_1(producer_loop, std::ref(queue), "A");
    std::thread thread_2(producer_loop, std::ref(queue), "B");

    thread_1.join();
    thread_2.join();

    std::cout << "Final value of n is: " << n << std::endl;
    std::cout << "Final queue size: " << queue.size() << std::endl;

    while(auto msg = queue.pop()){
        std::cout << msg.value() << std::endl;
    }
    
}