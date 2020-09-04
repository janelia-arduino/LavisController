// ----------------------------------------------------------------------------
// LavisController.cpp
//
//
// Authors:
// Peter Polidoro peterpolidoro@gmail.com
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
  power_switch_controller_ptr_ = &(createClientAtAddress(power_switch_controller::constants::device_name,constants::power_switch_controller_address));

  // Variable Setup

  // Set Device ID
  modular_server_.setDeviceName(constants::device_name);

  // Add Hardware

  // Pins

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
  modular_server::Function & set_client_property_values_function = modular_server_.createFunction(constants::set_client_property_values_function_name);
  set_client_property_values_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&LavisController::setClientPropertyValuesHandler));
  set_client_property_values_function.setResultTypeObject();

  modular_server::Function & set_air_puffer_function = modular_server_.createFunction(constants::set_air_puffer_function_name);
  set_air_puffer_function.attachFunctor(makeFunctor((Functor0 *)0,*this,&LavisController::setAirPufferHandler));
  set_air_puffer_function.addParameter(on_off_state_parameter);

  // Callbacks
}

void LavisController::setAirPuffer(const ConstantString * const on_off_state_ptr)
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
// ArduinoJson::JsonArray
// ArduinoJson::JsonObject
// const ConstantString *
//
// For more info read about ArduinoJson parsing https://github.com/janelia-arduino/ArduinoJson
//
// modular_server_.property(property_name).getValue(value) value type must match the property default type
// modular_server_.property(property_name).setValue(value) value type must match the property default type
// modular_server_.property(property_name).getElementValue(element_index,value) value type must match the property array element default type
// modular_server_.property(property_name).setElementValue(element_index,value) value type must match the property array element default type

void LavisController::setClientPropertyValuesHandler()
{
  modular_server_.response().writeResultKey();

  modular_server_.response().beginObject();

  bool call_was_successful;

  modular_server_.response().writeKey(power_switch_controller::constants::device_name);
  modular_server_.response().beginArray();
  power_switch_controller_ptr_->call(modular_server::constants::set_properties_to_defaults_function_name,
    modular_server::constants::all_array);
  call_was_successful = power_switch_controller_ptr_->callWasSuccessful();
  modular_server_.response().write(call_was_successful);
  modular_server_.response().endArray();

  modular_server_.response().endObject();
}

void LavisController::setAirPufferHandler()
{
  const ConstantString * on_off_state_ptr;
  modular_server_.parameter(constants::on_off_state_parameter_name).getValue(on_off_state_ptr);

  setAirPuffer(on_off_state_ptr);
}
