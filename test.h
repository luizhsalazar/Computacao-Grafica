#ifndef TEST_H
#define TEST_H

#include <controller.h>
#include <polygon3d.h>

class Test
{
private:
    Controller *m;
public:
    Test();
    void run();
};

#endif // TEST_H
