#include <stdio.h>
#include <stdbool.h>

bool locked = false;

void lockServo(void);
void unlockServo(void);
bool destinationReached();

void main(void)
{
	char buffer[10];

	while(1)
	{
		scanf("%s", buffer);

		if(!locked)
		{
			locked = true;
			lockServo();
			printf("Locked!\n");
		}
		else
		{
			printf("Waiting for satellites...\n");
			if(destinationReached())
			{
				printf("Unlocked!\n");
				unlockServo();
				locked = false;
			}
		}
	}
}

void lockServo(void)
{
	printf("Servo is locked.\n");
}

void unlockServo(void)
{
	printf("Servo is unlocked.\n");
}

bool destinationReached(void)
{
	static int count = 0;
	if(++count < 10) return false;
	count = 0;
	return true;
}