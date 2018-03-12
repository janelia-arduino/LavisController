// ----------------------------------------------------------------------------
// Constants.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef LAVIS_CONTROLLER_CONSTANTS_H
#define LAVIS_CONTROLLER_CONSTANTS_H
#include <ConstantVariable.h>
#include <AudioController.h>

#include <PowerSwitchController.h>


namespace lavis_controller
{
namespace constants
{
//MAX values must be >= 1, >= created/copied count, < RAM limit
enum{PROPERTY_COUNT_MAX=1};
enum{PARAMETER_COUNT_MAX=1};
enum{FUNCTION_COUNT_MAX=2};
enum{CALLBACK_COUNT_MAX=1};

extern ConstantString device_name;

extern ConstantString firmware_name;
extern const modular_server::FirmwareInfo firmware_info;

extern const size_t air_puffer_channel;

// Clients
extern const size_t power_switch_controller_address[1];

// Interrupts

// Units

// Properties
// Property values must be long, double, bool, long[], double[], bool[], char[], ConstantString *, (ConstantString *)[]

// Parameters
extern ConstantString on_off_state_parameter_name;
enum{ON_OFF_STATE_SUBSET_LENGTH=2};
extern ConstantString on_off_state_on;
extern ConstantString on_off_state_off;
extern modular_server::SubsetMemberType on_off_state_subset[ON_OFF_STATE_SUBSET_LENGTH];

// Functions
extern ConstantString set_client_property_values_function_name;
extern ConstantString set_air_puffer_function_name;

// Callbacks

// Errors
}
}
#include "5x3.h"
#include "3x2.h"
#endif
