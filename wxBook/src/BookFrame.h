#pragma once
#include <wx/frame.h>
#include <wx/event.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <vector>

typedef struct _Line
{
	std::wstring* content;
	int count;
}Line;

class BookFrame : public wxFrame
{
public:
	BookFrame(wxFrame* parent);
	void OnMouseMove(wxMouseEvent& evt);
	void OnLeftMouseDown(wxMouseEvent& evt);
	void OnLeftMouseUp(wxMouseEvent & evt);
	void OnRightMouseDown(wxMouseEvent & evt);
	void OnRightMouseUp(wxMouseEvent & evt);
	void OnKeyDown(wxKeyEvent & evt);
private:
	void InitBookStr();
	void InitFrame();
	int TestMaxWords();
	int GetTextWidth();
	int GetLines();
	bool CheckWidthOver(const std::wstring & str, int limitWidth);
	std::vector<Line*> ConvertStringToPage(const wchar_t * wchars, int index, int lineLimit);
	void NextPage();
	void PrePage();
	bool CheckHasContent(const std::vector<Line*> strs);
private:
	wxPoint m_delta;	
	std::vector<wxStaticText*> m_texts;
	std::wstring* m_bookStr;
	wxStaticText* m_calcText;
	int m_maxPerRank = 0;

	int m_curContentIndex = 0;
	int m_curContentLength = 0;

	wxDECLARE_EVENT_TABLE();
};

