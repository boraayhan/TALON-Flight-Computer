#pragma once
#include "communication/CommunicationPayload.h"
#include "control/Autopilot/Autopilot.h"
#include "global/GlobalHeader.h"
#include <RF24.h>

class CommunicationManager {
  public:
    CommunicationManager();
    void periodic();
    void init();

    bool hasNewFlightCommand();
    FlightCommand getLatestFlightCommand();

    bool hasNewTrimCommand();
    AutopilotSetting getLatestAutopilotSetting();

    bool hasNewAutopilotSetting();
    TrimCommand getLatestTrimCommand();

  private:
    RF24 radio;

    FlightCommand _latestFlightCommand;
    AutopilotSetting _latestAutopilotSetting;
    TrimCommand _latestTrimCommand;
    bool hasNewFlightCommand_;
    bool hasNewTrimCommand_;
    bool hasNewAutopilotSetting_;
};