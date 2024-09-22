#include "main.h"
#include <pthread.h>
#include <semaphore.h>
//#include "../libraries/TinyGPS-13/TinyGPS.h"

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

float destination_lat = 14;
float destination_long = 32;
int min_radius_m = 10;

void* startScheduler(void*);

sem_t buttonSemaphore;

enum
{
	userButton = wxID_HIGHEST + 1
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit();\
private:
	pthread_t scheduler;
};
 
class MyFrame : public wxFrame
{
public:
    MyFrame();
private:
    wxButton *Button;
    void OnButtonClicked(wxCommandEvent& evt);
    wxDECLARE_EVENT_TABLE();
};
 
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    sem_init(&buttonSemaphore, 0, 0);
    pthread_create(&this->scheduler, NULL, startScheduler, NULL);
    return true;
}

BEGIN_EVENT_TABLE ( MyFrame, wxFrame )
  EVT_BUTTON ( userButton, MyFrame::OnButtonClicked )
END_EVENT_TABLE()

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Simulated Reverse Geocache")
{
    Button = new wxButton(this, userButton, _T("Button"), wxDefaultPosition, wxDefaultSize, 0);
}

void MyFrame::OnButtonClicked(wxCommandEvent& evt)
{
    sem_post(&buttonSemaphore);
    //evt.Skip();
}

wxIMPLEMENT_APP(MyApp);
//static TinyGPS gps;

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

void initHardware(void)
{
	//IMPLEMENT_APP_NO_MAIN(MyApp);
}

void wait_for_button(void)
{
	sem_wait(&buttonSemaphore);
}

void display(const char* msg)
{
	while(*msg) printf("%c", *msg++);
}

void getLocation(float* p_lat, float* p_long)
{
	*p_lat = 14;
	*p_long = 32;
}

float distanceBetween(float lat1, float long1, float lat2, float long2)
{
	//return gps.distance_between(lat1, long1, lat2, long2);
	static uint8_t idx = 0;
	float dists[] = {50, 14,36,1};
	return dists[(idx++)%4];
}

void unlock(void)
{
	display((const char *)"Servo unlocked!\n");
}