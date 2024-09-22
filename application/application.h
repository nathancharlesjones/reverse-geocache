#ifndef APPLICATION_H
#define APPLICATION_H

const float destination_lat = 14;
const float destination_long = 32;
const int min_radius_m = 10;

void* startScheduler(void* /* data */);

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

#endif /* APPLICATION_H */