#include "LynxApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<LynxApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

LynxApp::LynxApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  LynxApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  LynxApp::associateSyntax(_syntax, _action_factory);
}

LynxApp::~LynxApp()
{
}

// External entry point for dynamic application loading
extern "C" void LynxApp__registerApps() { LynxApp::registerApps(); }
void
LynxApp::registerApps()
{
  registerApp(LynxApp);
}

// External entry point for dynamic object registration
extern "C" void LynxApp__registerObjects(Factory & factory) { LynxApp::registerObjects(factory); }
void
LynxApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void LynxApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { LynxApp::associateSyntax(syntax, action_factory); }
void
LynxApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
