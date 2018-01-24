#ifndef __RMUTEX_H__
#define __RMUTEX_H__

// using critical section on windows

namespace RPTR {
class Mutex {
public:
  Mutex();
  ~Mutex();

  void lock();

  // return true if the mutex could be locked
  bool trylock();

  void unlock();

private:
  struct RMutex_data;

  RMutex_data *m_data;
};
}

#endif /* __RMUTEX_H__ */
