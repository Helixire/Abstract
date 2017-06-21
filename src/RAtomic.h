#ifndef __RATOMIC_H__
#define __RATOMIC_H__

#include "RMutex.h"

namespace RPTR
{
  template<typename T>
  class Atomic
  {
  public:
    Atomic() {}
    Atomic(T val) : m_data(val) {}

    T get()
    {
      T ret;

      m_mut.lock();
      ret = m_data;
      m_mut.unlock();
      return ret;
    }

    void operator=(T &val)
    {
      m_mut.lock();
      m_data = val;
      m_mut.unlock();
    }

  private:
    T     m_data;
    Mutex m_mut;
  };
}



#endif /* !__RATOMIC_H__ */
