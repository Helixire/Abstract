#ifndef __RLOCKER_H__
#define __RLOCKER_H__

#include "RMutex.h"

namespace RPTR
{
  class Locker
  {
  public:
    Locker(Mutex &mut);
    ~Locker();
  private:
    Mutex &m_mut;
  };
}

#endif /* !__RLOCKER_H__ */
