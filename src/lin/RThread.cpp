#include "RThread.h"
#include "RException.h"
#include <pthread.h>

struct RPTR::Thread::RThread_data {
  pthread_t thread;
};

RPTR::Thread::~Thread() { delete m_data; }

void RPTR::Thread::launch_cmd(RPTR::SCommand *cmd) {
  RPTR::SCommand cur(*cmd);

  cur->execute();
}

RPTR::Thread::Thread() : m_joinable(false), m_data(new RThread_data) {}

RPTR::Thread::Thread(void (*funct)(void *), void *param)
    : m_joinable(false), m_data(new RThread_data) {
  start(funct, param);
}

RPTR::Thread::Thread(RPTR::SCommand cmd)
    : m_joinable(false), m_data(new RThread_data) {
  start(cmd);
}

void RPTR::Thread::start(void (*funct)(void *), void *param) {
  int ret;

  if (m_joinable)
    throw(ThreadException("already running a task", 1));
  if ((ret = pthread_create(&m_data->thread, NULL, (void *(*)(void *))funct,
                            param)))
    throw(ThreadException("pthread_create", ret));
  m_joinable = true;
}

void RPTR::Thread::start(RPTR::SCommand cmd) {
  start((void (*)(void *))launch_cmd, (void *)&cmd);
}

void RPTR::Thread::join() {
  int ret;

  if (!m_joinable)
    throw(ThreadException("nothing to join into", 1));
  if ((ret = pthread_join(m_data->thread, NULL)))
    throw(ThreadException("pthread_join", ret));
  m_joinable = false;
}

void RPTR::Thread::detach() {
  int ret;

  if (!m_joinable)
    throw(ThreadException("nothing to detach", 1));
  if ((ret = pthread_detach(m_data->thread)))
    throw(ThreadException("pthread_detach", ret));
}
