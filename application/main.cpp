#include <stdio.h>
#include "main.h"

float destination_lat = 14;
float destination_long = 32;
int min_radius_m = 10;

int main(void)
{
	initHardware();

	while(1)
	{
		float current_lat, current_long;
		char distance_msg[32] = {0};

		wait_for_button();

		display((const char *)"Waiting for satellites...\n");
		getLocation(&current_lat, &current_long);

		float distance = distanceBetween(current_lat, current_long, destination_lat, destination_long);
		sprintf(distance_msg, "You're %f m away.\n", distance);
		display(distance_msg);
		
		if(distance < min_radius_m)
		{
			display("Unlocked!\n");
			unlock();
		}
	}

	return 0;
}