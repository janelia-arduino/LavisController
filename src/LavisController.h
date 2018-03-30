// ----------------------------------------------------------------------------
// LavisController.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef LAVIS_CONTROLLER_H
#define LAVIS_CONTROLLER_H
#include <ArduinoJson.h>
#include <JsonStream.h>
#include <Array.h>
#include <Vector.h>
#include <ConstantVariable.h>
#include <Functor.h>

#include <ModularClient.h>
#include <PowerSwitchController.h>

#include <ModularServer.h>
#include <ModularDeviceBase.h>
#include <AudioController.h>

#include "LavisController/Constants.h"


class LavisController : public AudioController
{
public:
  LavisController();
  virtual void setup();

  void setAirPuffer(const ConstantString * const on_off_state_ptr);

private:
  modular_server::Property properties_[lavis_controller::constants::PROPERTY_COUNT_MAX];
  modular_server::Parameter parameters_[lavis_controller::constants::PARAMETER_COUNT_MAX];
  modular_server::Function functions_[lavis_controller::constants::FUNCTION_COUNT_MAX];
  modular_server::Callback callbacks_[lavis_controller::constants::CALLBACK_COUNT_MAX];

  ModularClient * power_switch_controller_ptr_;

  // Handlers
  void setClientPropertyValuesHandler();
  void setAirPufferHandler();

};

#endif
