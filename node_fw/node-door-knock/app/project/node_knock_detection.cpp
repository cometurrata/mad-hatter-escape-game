#include <stdint.h>
#include <SmingCore.h>

#include "http_client.h"
#include "knockdetection.h"
#include "tasks.h"

static Timer sensorTimer;

bool infoSent = false;

void sendKnockDetection(void)
{
    if (getKnockDetected())
    {
        debugf("Knock Detected");
        nodeDoorKnock.setSolved(true).sendUpdateNow();
    }
}

void nodeKnockDetectionInit(void)
{
    knockDetectionInit();
    pinMode(0, OUTPUT);
    digitalWrite(0, HIGH);
    sensorTimer.initializeMs(100, &sendKnockDetection).start();
}

