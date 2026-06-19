#pragma once
#include "control/Autopilot/Autopilot.h"
#include "control/FlightControlsManager/FlightControlsManager.h" // Used for FlightCommand
#include "data/sensors/CommunicationManager/CommunicationPayload.h"
#include "global/GlobalHeader.h"
#include <RF24.h>

class CommunicationManager {
  public:
    CommunicationManager();
    void periodic();
    void init();

    boolean newFlightCommandAvailable;
    FlightCommand getLatestFlightCommand();

    boolean newTrimAvailable;
    AutopilotSetting getLatestAutopilotSetting();

    boolean newAutopilotSettingAvailable;
    TrimCommand getLatestTrimCommand();

  private:
    RF24 radio;
    FlightCommand latestFlightCommand;
    AutopilotSetting latestAutopilotSetting;
    TrimCommand latestTrimCommand;
};