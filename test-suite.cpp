#include <iostream>
#include <list>
#include "RThread.h"
#include "RSemaphore.h"
#include "RMutex.h"


struct osef
{
    char    c;
    RPTR::Semaphore &s;
    RPTR::Mutex     &m;
};

void func(osef *a)
{
    int i;
    int j;
    
    for (i = 0; i < 4; ++i)
    {
        a->s.wait();
        a->m.lock();
        std::cout << a->c << std::endl;
        a->m.unlock();
        for (j = 0; j < 200000; ++j);
    }
}

int main(int ac, char **av)
{
    RPTR::Semaphore     s;
    RPTR::Mutex         m;
    osef            d[] = {{'a', s, m}, {'b', s, m}, {0, s, m}};
    int             i;
    RPTR::Thread    *thread;
    
    for (i = 0; d[i].c; ++i);
    thread = new RPTR::Thread[i];
    for (i = 0; d[i].c; ++i)
        thread[i].start((void (*)(void *))func, d + i);
    std::cout << "Starting" << std::endl;
    s.add(8);
    for (i = 0; d[i].c; ++i)
        thread[i].join();
    std::cout << "out" << std::endl;
    delete [] thread;
    return (0);
}
