// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>

#include <InternetButton.h>

// Make an InternetButton object
InternetButton button = InternetButton();

void setup() {
  // initialize the InternetButton
  button.begin();

  // Create an API endpoint to turn off lights
  // Particle.function takes 2 parameters
  // Parameter 1 = NAME OF API ENDPOINT
  // Parameter 2 = FUNCTION YOU WANT TO RUN WHEN
  //  PERSON VISITS THE ENDPOINT
  Particle.function("turnLightsOff", lightOff);
  Particle.function("turnLightsOn", lightOn);
  Particle.function("rainbow", special);
  Particle.function("lights", controlLights);
}

void loop() {
}


// Example of using a function with parameters
int controlLights(String cmd) {
  if (cmd == "on") {
    button.allLedsOn(0,0,255);
    return 1;
  }
  else if (cmd == "off") {
    button.allLedsOff();
    return 1;
  }
  else if (cmd=="special") {
    button.rainbow(20);
    return 1;
  }
  // function returns -1 if person does NOT
  // use the "on" or "off" command
  return -1;
}


// Template of an exposed functions
int lightOff(String cmd) {
  button.allLedsOff();
  return 1;
}

// Turn light on
int lightOn(String cmd) {
  button.allLedsOn(255,255,255);
  return 1;     // 1 = success, 0 = error
}
int special(String cmd) {
  button.rainbow(20);
  return 1;
}

