#ifndef TEST_H
#define TEST_H

#include <controller.h>

class Test
{
private:
    Controller *m;
public:
    Test();
    void run();
};

#endif // TEST_H
