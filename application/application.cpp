#include <stdio.h>  // For sprintf
#include "application.h"

void* startScheduler(void* data)
{
	while(1)
	{
		float current_lat, current_long;
		char distance_msg[32] = {0};

		wait_for_button();

		display((const char *)"Waiting for satellites...\n");
		getLocation(&current_lat, &current_long);

		float distance = distanceBetween(current_lat, current_long, destination_lat, destination_long);
		sprintf(distance_msg, "You're %f m away.\n", distance);
		display((const char *)distance_msg);
		
		if(distance < min_radius_m)
		{
			display((const char *)"Unlocked!\n");
			unlock();
		}
	}
}