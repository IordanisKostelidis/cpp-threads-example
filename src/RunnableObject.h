//
// Created by ikostelidis on 4/26/21.
//

#ifndef CPP_THREADS_EXAMPLE_RUNNABLEOBJECT_H
#define CPP_THREADS_EXAMPLE_RUNNABLEOBJECT_H


class RunnableObject {
private:
    int myId;
public:
    RunnableObject(int myId);

public:
    void run(const bool *trigger);

public:
    static void startRunnableObject(RunnableObject *obj, bool *trigger) {
        obj->run(trigger);
    }
};


#endif //CPP_THREADS_EXAMPLE_RUNNABLEOBJECT_H
