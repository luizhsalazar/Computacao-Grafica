#ifndef TEST_H
#define TEST_H

#include <mediator.h>

class Test
{
private:
    Mediator *m;
public:
    Test();
    void run();
};

#endif // TEST_H
