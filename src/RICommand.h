#ifndef RICOMMAND_H
#define RICOMMAND_H

#include <memory>

namespace RPTR {
class ICommand {
public:
  virtual ~ICommand() {}
  virtual void execute() = 0;
};

typedef std::shared_ptr<ICommand> SCommand;
}

#endif // RICOMMAND_H
