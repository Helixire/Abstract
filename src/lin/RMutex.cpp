#include "RMutex.h"
#include "RException.h"
#include <pthread.h>

struct RPTR::Mutex::RMutex_data {
  pthread_mutex_t mutex;
};

RPTR::Mutex::~Mutex() {
  pthread_mutex_destroy(&m_data->mutex);
  delete m_data;
}

RPTR::Mutex::Mutex() : m_data(new RMutex_data) {
  int ret;

  if ((ret = pthread_mutex_init(&m_data->mutex, 0)))
    throw(MutexException("pthread_mutex_init", ret));
}

void RPTR::Mutex::lock() {
  int ret;

  if ((ret = pthread_mutex_lock(&m_data->mutex)))
    throw(MutexException("pthread_mutex_lock", ret));
}

bool RPTR::Mutex::trylock() {
  return ((pthread_mutex_trylock(&m_data->mutex)) == EBUSY ? false : true);
}

void RPTR::Mutex::unlock() {
  int ret;

  if ((ret = pthread_mutex_unlock(&m_data->mutex)))
    throw(MutexException("pthread_mutex_unlock", ret));
}
