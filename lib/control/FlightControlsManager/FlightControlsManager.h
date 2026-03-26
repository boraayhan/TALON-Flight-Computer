#include "control/ControlSurface/ControlSurface.h"
#include "global/global_header.h"

class FlightControlsManager {
  private:
};

enum ControlSurfaces {
    AILERON_LEFT = 0,
    AILERON_RIGHT,
    ELEVATOR_LEFT,
    ELEVATOR_RIGHT,
    num_surface
};

ControlSurface surfaces[num_surface] = {
    
};