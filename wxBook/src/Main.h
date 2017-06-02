#pragma once

#include <wx/app.h>
#include <wx/frame.h>
#include <wx/event.h>
#include <wx/panel.h>
#include <wx/stattext.h>

class MainApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MainFrame : public wxFrame
{
public:
	MainFrame(wxFrame* parent);
	void OnMouseMove(wxMouseEvent& evt);
	void OnLeftMouseDown(wxMouseEvent& evt);
private:
	int GetLines();
private:
	wxPoint m_delta;
	wxStaticText* m_text;
	wxDECLARE_EVENT_TABLE();
};
