#include "BookFrame.h"
#include "Config.h"

wxBEGIN_EVENT_TABLE(BookFrame, wxFrame)
	EVT_MOTION(BookFrame::OnMouseMove)
	EVT_LEFT_DOWN(BookFrame::OnLeftMouseDown)
wxEND_EVENT_TABLE()

BookFrame::BookFrame(wxFrame* parent)
	: wxFrame(parent, wxID_ANY, "Test"
		, wxDefaultPosition, wxSize(500, 100)
		, 0 | wxFRAME_SHAPED | wxSIMPLE_BORDER | wxFRAME_NO_TASKBAR | wxSTAY_ON_TOP)
{
	InitFrame();
	Show();
}

void BookFrame::OnLeftMouseDown(wxMouseEvent& evt)
{
	//CaptureMouse();
	wxPoint pos = ClientToScreen(evt.GetPosition());
	wxPoint origin = GetPosition();
	int dx = pos.x - origin.x;
	int dy = pos.y - origin.y;
	m_delta = wxPoint(dx, dy);
}

void BookFrame::OnMouseMove(wxMouseEvent& evt)
{
	wxPoint pt = evt.GetPosition();
	if (evt.Dragging() && evt.LeftIsDown())
	{
		wxPoint pos = ClientToScreen(pt);
		Move(wxPoint(pos.x - m_delta.x, pos.y - m_delta.y));
	}
}

void BookFrame::InitBookStr()
{
}

void BookFrame::InitFrame()
{
	int w, h;
	Config::Get().GetWH(w, h);
	SetSize(w, h);
	SetBackgroundColour(wxColor(Config::Get().GetBackColor()));
	SetForegroundColour(wxColor(Config::Get().GetFrontColor()));

	int startX, startY;
	startX = startY = Config::Get().GetEdge();
	int lineHeight = Config::Get().GetFontSize() + Config::Get().GetFontSpacing();

	int lines = GetLines();
	for (int i = 0; i < lines; ++i)
	{
		wxStaticText* text = new wxStaticText(this, wxID_ANY, "", wxPoint(startX, startY - lineHeight * i));
		m_texts.push_back(text);
	}	
}

int BookFrame::GetLines()
{
	int fontSize = Config::Get().GetFontSize();
	int spacing = Config::Get().GetFontSpacing();
	wxSize size = this->GetSize();
	return size.y / (fontSize + spacing);
}


