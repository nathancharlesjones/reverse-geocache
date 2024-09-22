#include "main.h"
//#include "../libraries/TinyGPS-13/TinyGPS.h"

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
 
class MyFrame : public wxFrame
{
public:
    MyFrame();
    wxButton *Button;
};
 
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
 
MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Simulated Reverse Geocache")
{
    Button = new wxButton(this, wxID_ANY, _T("Button"), wxDefaultPosition, wxDefaultSize, 0);
}

IMPLEMENT_APP_NO_MAIN(MyApp);
//static TinyGPS gps;

void initHardware(void)
{
	//IMPLEMENT_APP_NO_MAIN(MyApp);
}

void wait_for_button(void)
{
	while(1);
}

void display(const char* msg)
{
	//asdf
}

void getLocation(float* p_lat, float* p_long)
{
	//asdf
}

float distanceBetween(float lat1, float long1, float lat2, float long2)
{
	//return gps.distance_between(lat1, long1, lat2, long2);
	return 0.0;
}

void unlock(void)
{
	display("Servo unlocked!");
}