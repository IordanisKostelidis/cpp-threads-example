#include <iostream>
#include <thread>
#include <unistd.h>
#include "RunnableObject.h"

void runDemo() {
    auto *first = new RunnableObject(1);
    auto *second = new RunnableObject(2);
    auto *third = new RunnableObject(3);
    auto *fourth = new RunnableObject(4);

    bool trigger = false;

    std::thread firstThread(RunnableObject::startRunnableObject, first, &trigger);
    std::thread secondThread(RunnableObject::startRunnableObject, second, &trigger);
    std::thread thirdThread(RunnableObject::startRunnableObject, third, &trigger);
    std::thread fourthThread(RunnableObject::startRunnableObject, fourth, &trigger);

    usleep(2);
    trigger = true;

    firstThread.join();
    secondThread.join();
    thirdThread.join();
    fourthThread.join();
}

int main() {
    for(int i=0;i<10;i++) {
        std::cout << "Demo No" << " " << i << std::endl;
        runDemo();
        std::cout << "************************" << std::endl;
    }

    return 0;
}