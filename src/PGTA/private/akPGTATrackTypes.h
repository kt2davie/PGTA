#pragma once

#include <private/akPGTAUUID.h>

struct PGTATrackGroup
{
    char* name;
    PGTAUUID uuid;
};

struct PGTATrackSample
{
    char* sampleName;
    int16_t id;
    char* defaultFile;
    uint64_t frequency;
    uint64_t startTime;
    float probability;
    float volumeMultiplier;

    PGTAUUID* group;
};