#include <semaphore.h>
#include <errno.h>
#include "RSemaphore.h"
#include "RException.h"

struct RPTR::Semaphore::RSemaphore_data
{
    sem_t semaphore;
};

RPTR::Semaphore::~Semaphore() 
{
    sem_destroy(&m_data->semaphore);
    delete m_data;
}

RPTR::Semaphore::Semaphore(unsigned int base) : m_data(new RSemaphore_data)
{
    if (sem_init(&m_data->semaphore, 0, base))
        throw(SemaphoreException("sem_init", errno));
}

void RPTR::Semaphore::wait()
{
    if (sem_wait(&m_data->semaphore))
        throw(SemaphoreException("sem_wait", errno));
}

bool RPTR::Semaphore::trywait()
{
    if (!sem_trywait(&m_data->semaphore))
        return (true);
    if (errno == EAGAIN)
        return (false);
    throw(SemaphoreException("sem_trywait", errno));
}

void RPTR::Semaphore::post()
{
    if (sem_post(&m_data->semaphore))
        throw(SemaphoreException("sem_post", errno));
}

int RPTR::Semaphore::get()
{
    int ret;
    
    if (sem_getvalue(&m_data->semaphore, &ret))
        throw(SemaphoreException("sem_getvalue", errno));
    return (ret);
}

void RPTR::Semaphore::add(unsigned int nb)
{
    int i;
    
    for (i = 0; i < nb; ++i)
        post();
}
