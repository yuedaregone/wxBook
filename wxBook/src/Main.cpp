#include "Main.h"
#include "Config.h"
#include "BookFrame.h"

IMPLEMENT_APP(MainApp)

bool MainApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	Config::Get().Init();

	new BookFrame(NULL);
	return true;
}

