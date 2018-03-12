// ----------------------------------------------------------------------------
// LavisController.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "../LavisController.h"


using namespace lavis_controller;

LavisController::LavisController()
{
}

void LavisController::setup()
{
  // Parent Setup
  AudioController::setup();

  // Reset Watchdog
  resetWatchdog();

  // Clients Setup
  power_switch_controller_ptr_ = &(createClientAtAddress(constants::power_switch_controller_address));

  // Variable Setup

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware

  // Interrupts

  // Add Firmware
  modular_server_.addFirmware(constants::firmware_info,
                              properties_,
                              parameters_,
                              functions_,
                              callbacks_);

  // Properties

  // Parameters
  modular_server::Parameter & on_off_state_parameter = modular_server_.createParameter(constants::on_off_state_parameter_name);
  on_off_state_parameter.setTypeString();
  on_off_state_parameter.setSubset(constants::on_off_state_subset);

  // Functions
  modular_server::Function & set_air_puffer_function = modular_server_.createFunction(constants::set_air_puffer_function_name);
  set_air_puffer_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&LavisController::setAirPufferHandler));
  set_air_puffer_function.addParameter(on_off_state_parameter);

  // Callbacks
}

void LavisController::setAirPuffer(ConstantString * const on_off_state_ptr)
{
  if (on_off_state_ptr == &constants::on_off_state_on)
  {
    power_switch_controller_ptr_->call(power_switch_controller::constants::set_channel_on_function_name,
                                       constants::air_puffer_channel);
  }
  else
  {
    power_switch_controller_ptr_->call(power_switch_controller::constants::set_channel_off_function_name,
                                       constants::air_puffer_channel);
  }
}

// Handlers must be non-blocking (avoid 'delay')
//
// modular_server_.parameter(parameter_name).getValue(value) value type must be either:
// fixed-point number (int, long, etc.)
// floating-point number (float, double)
// bool
// const char *
// ArduinoJson::JsonArray *
// ArduinoJson::JsonObject *
// const ConstantString *
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.property(property_name).getValue(value) value type must match the property default type
// modular_server_.property(property_name).setValue(value) value type must match the property default type
// modular_server_.property(property_name).getElementValue(element_index,value) value type must match the property array element default type
// modular_server_.property(property_name).setElementValue(element_index,value) value type must match the property array element default type

void LavisController::setAirPufferHandler()
{
  const char * on_off_state_str;
  modular_server_.parameter(constants::on_off_state_parameter_name).getValue(on_off_state_str);
  Serial << "on_off_state_str = " << on_off_state_str << "\n";
  // ConstantString * on_off_state_ptr = stringToOn_Off_StatePtr(on_off_state_str);
}
