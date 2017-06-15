#include <iostream>
#include <list>
#include "RThread.h"
#include "RMutex.h"

struct osef
{
    char    c;
    RPTR::Mutex &m;
};

void func(osef *a)
{
    int i;
    
    for (i = 0; i < 4; ++i)
    {
        a->m.lock();
        std::cout << a->c << std::endl;
        a->m.unlock();
    }
}

int main(int ac, char **av)
{
    RPTR::Mutex     m;
    osef            d[] = {{'a', m}, {'b', m}, {0, m}};
    int             i;
    RPTR::Thread    *thread;
    
    m.lock();
    for (i = 0; d[i].c; ++i);
    thread = new RPTR::Thread[i];
    for (i = 0; d[i].c; ++i)
        thread[i].start((void (*)(void *))func, d + i);
    std::cout << "Starting" << std::endl;
    m.unlock();
    for (i = 0; d[i].c; ++i)
        thread[i].join();
    std::cout << "out" << std::endl;
    return (0);
}
