//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef COMBINEDAPP_H
#define COMBINEDAPP_H

#include "MooseApp.h"

class CombinedApp;

template <>
InputParameters validParams<CombinedApp>();

class CombinedApp : public MooseApp
{
public:
  CombinedApp(const InputParameters & parameters);
  virtual ~CombinedApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* COMBINEDAPP_H_ */
