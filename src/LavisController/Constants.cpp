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

// Interrupts

// Units

// Properties

// Parameters

// Functions

// Callbacks

// Errors
}
}
