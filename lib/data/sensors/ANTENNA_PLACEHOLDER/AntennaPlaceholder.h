#pragma once

class AntennaPlaceholder
{
    public:
        AntennaPlaceholder();
        void AntennaPeriodic(); // Read and parse inputs
        void transmit(int request_id, std::string data);
};