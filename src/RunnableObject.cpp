//
// Created by ikostelidis on 4/26/21.
//

#include <unistd.h>
#include <ctime>
#include <iostream>
#include "RunnableObject.h"

RunnableObject::RunnableObject(int myId) : myId(myId) {

}

void RunnableObject::run(const bool *trigger) {
    while (true) {
        if (*trigger) {
            break;
        }

        usleep(100000 * 2);
    }

    std::time_t t = std::time(nullptr);   // get time now
    std::tm *now = std::localtime(&t);
    std::cout << (now->tm_year + 1900) << '-'
              << (now->tm_mon + 1) << '-'
              << now->tm_mday << ' '
              << now->tm_hour << ':'
              << now->tm_min << ':'
              << now->tm_sec << ' '
              << "By obj with id = " << this->myId
              << "\n";
}
