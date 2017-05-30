#include "Main.h"
#include "Config.h"

IMPLEMENT_APP(MainApp)

bool MainApp::OnInit()
{
	if (!wxApp::OnInit())
		return false;

	new MainFrame(NULL);
	return true;
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)	
	EVT_MOTION(MainFrame::OnMouseMove)
	EVT_LEFT_DOWN(MainFrame::OnLeftMouseDown)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(wxFrame* parent) 
	: wxFrame(parent, wxID_ANY, "Test"
		, wxDefaultPosition, wxSize(100, 100)
		, 0 | wxFRAME_SHAPED | wxSIMPLE_BORDER | wxFRAME_NO_TASKBAR | wxSTAY_ON_TOP)
{
	SetShape(wxRegion(0,0,100,100));
	
	m_text = new wxStaticText(this, wxID_ANY, "qwert", wxPoint(10, 10));
	//m_text->AppendText("12335346543");
	//this->AddChild(m_textCtrl);
	
	wxSize size = m_text->GetSize();
	
	Show();

	int w, h;
	Config::Get().GetWH(w, h);
}

void MainFrame::OnLeftMouseDown(wxMouseEvent& evt)
{
	//CaptureMouse();
	wxPoint pos = ClientToScreen(evt.GetPosition());
	wxPoint origin = GetPosition();
	int dx = pos.x - origin.x;
	int dy = pos.y - origin.y;
	m_delta = wxPoint(dx, dy);
}

void MainFrame::OnMouseMove(wxMouseEvent& evt)
{
	wxPoint pt = evt.GetPosition();
	if (evt.Dragging() && evt.LeftIsDown())
	{
		wxPoint pos = ClientToScreen(pt);
		Move(wxPoint(pos.x - m_delta.x, pos.y - m_delta.y));
	}
}

