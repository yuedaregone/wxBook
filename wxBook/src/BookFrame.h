#pragma once
#include <wx/frame.h>
#include <wx/event.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <vector>

class BookFrame : public wxFrame
{
public:
	BookFrame(wxFrame* parent);
	void OnMouseMove(wxMouseEvent& evt);
	void OnLeftMouseDown(wxMouseEvent& evt);
private:
	int GetLines();
	void InitFrame();
private:
	wxPoint m_delta;	
	std::vector<wxStaticText*> m_texts;
	wxDECLARE_EVENT_TABLE();
};

