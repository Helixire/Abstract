#ifndef __RATOMIC_H__
#define __RATOMIC_H__

#include "RLocker.h"

namespace RPTR
{
  template<typename T>
  class Atomic
  {
  public:
    Atomic() {}
    Atomic(T val) : m_data(val) {}
    ~Atomic() {}
    T get()
    {
      T ret;
      Locker  lock(m_mut);

      ret = m_data;
      return ret;
    }

    Atomic<T> &operator=(const T &val)
    {
      Locker  lock(m_mut);

      m_data = val;
      return *this;
    }

    Atomic<T> &operator+=(const T &val)
    {
      Locker lock(m_mut);

      m_data += val;

      return *this;
    }

    Atomic<T> &operator-=(const T &val)
    {
      Locker lock(m_mut);

      m_data -= val;
      return *this;
    }

  private:
    T     m_data;
    Mutex m_mut;
  };
}



#endif /* !__RATOMIC_H__ */
