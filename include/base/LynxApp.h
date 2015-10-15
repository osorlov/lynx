#ifndef LYNXAPP_H
#define LYNXAPP_H

#include "MooseApp.h"

class LynxApp;

template<>
InputParameters validParams<LynxApp>();

class LynxApp : public MooseApp
{
public:
  LynxApp(InputParameters parameters);
  virtual ~LynxApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LYNXAPP_H */
