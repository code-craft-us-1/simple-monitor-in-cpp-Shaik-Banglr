#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;
using std::flush;
using std::this_thread::sleep_for;
using std::chrono::seconds;

void flushMessage()
  {
  for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
    }
  }

bool isTemperatureCrtical(float temperature)
  {
  return(temperature > 102 || temperature < 95);
  }

bool isPulseOutofRange(float pulseRate)
  {
  return(pulseRate < 60 || pulseRate > 100);
  }


int vitalsOk(float temperature, float pulseRate, float spo2) {
  auto vitalsNotOkStatus = 0;
  if (isTemperatureCrtical(temperature)) {
    cout << "Temperature is critical!\n";
    flushMessage();
    return vitalsNotOkStatus;
    }
  else if (isPulseOutofRange(pulseRate)) {
    cout << "Pulse Rate is out of range!\n";
    flushMessage();
    return vitalsNotOkStatus;
    }
  else if (spo2 < 90) {
    cout << "Oxygen Saturation out of range!\n";
    flushMessage();
    return vitalsNotOkStatus;
    }
  return ~vitalsNotOkStatus;
  }
