#include <pthread.h>
#include "RThread.h"

struct RPTR::Thread::RThread_data
{
    pthread_t   thread;
};

RPTR::Thread::~Thread() {}

RPTR::Thread::Thread(void (*funct)(void *), void *param) : m_data(new RThread_data)
{
    pthread_create(&m_data->thread, NULL, (void *(*)(void *))funct, param);
}

void RPTR::Thread::join()
{
    pthread_join(m_data->thread, NULL);
}
