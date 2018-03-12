// ----------------------------------------------------------------------------
// Constants.cpp
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#include "Constants.h"


namespace lavis_controller
{
namespace constants
{
CONSTANT_STRING(device_name,"lavis_controller");

CONSTANT_STRING(firmware_name,"LavisController");
// Use semantic versioning http://semver.org/
const modular_server::FirmwareInfo firmware_info =
{
  .name_ptr=&firmware_name,
  .version_major=1,
  .version_minor=0,
  .version_patch=0,
};

const size_t air_puffer_channel = 0;

// Clients
const size_t power_switch_controller_address[1] =
  {
   3,
  };

// Interrupts

// Units

// Properties

// Parameters
CONSTANT_STRING(on_off_state_parameter_name,"on_off_state");
CONSTANT_STRING(on_off_state_on,"ON");
CONSTANT_STRING(on_off_state_off,"OFF");
modular_server::SubsetMemberType on_off_state_subset[ON_OFF_STATE_SUBSET_LENGTH] =
  {
    {.cs_ptr=&on_off_state_on},
    {.cs_ptr=&on_off_state_off},
  };

// Functions
CONSTANT_STRING(set_client_property_values_function_name,"setClientPropertyValues");
CONSTANT_STRING(set_air_puffer_function_name,"setAirPuffer");

// Callbacks

// Errors
}
}
