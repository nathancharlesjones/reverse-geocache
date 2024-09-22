#ifndef MAIN_H
#define MAIN_H

// Initialize any required hardware or hardware-specific features. I.e.
//   - x86: Create Qt window
//   - MCU: Set up GPIO (for button, LCD, servo) and UART (for GPS module)
//          Configure interrupts
//
void initHardware(void);

// BLOCKING function call. Returns only when a "button" event (real or simulated)
// occurs.
//
void wait_for_button(void);

// Show a message to the user.
//
void display(const char * /* msg */);

// Retrieve the current location of the reverse geocache; this is a BLOCKING function
// call. Store the float value of the latitude and longitude (in decimal degrees) at 
// the two locations given in the function arguments.
//
void getLocation(float* /* lat */, float* /* long */);

// Calculate the distance (in meters) between the two sets of positions given. Latitude
// and longitude values should be in decimal degrees.
//
float distanceBetween(float /* lat1 */, float /* long1 */, float /* lat2 */, float /* long2 */);

// Unlock the reverse geocache.
//
void unlock(void);

#endif /* MAIN_H */