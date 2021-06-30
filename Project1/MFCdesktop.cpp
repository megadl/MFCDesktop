#include <afxwin.h>

//�Զ����ܴ�����
class CMyFrameWnd :public CFrameWnd {
	//DECLARE_MESSAGE_MAP()
protected: 
	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); 
	virtual const AFX_MSGMAP* GetMessageMap() const; 
public:
	//����һ������WM_CREATE window��Ϣ�ķ���
	LRESULT OnCREATE(WPARAM wParam, LPARAM lParam);
};


//BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
//	ON_MESSAGE(WM_CREATE, OnCREATE)
//END_MESSAGE_MAP()


PTM_WARNING_DISABLE 
const AFX_MSGMAP* CMyFrameWnd::GetMessageMap() const 
	{ return GetThisMessageMap(); } 
const AFX_MSGMAP* PASCAL CMyFrameWnd::GetThisMessageMap() 
{ 
	typedef CMyFrameWnd ThisClass;						   
	typedef CFrameWnd TheBaseClass;					   
	__pragma(warning(push))							   
	__pragma(warning(disable: 4640)) /* message maps can only be called by single threaded message pump */ 
	static const AFX_MSGMAP_ENTRY _messageEntries[] =  
	{
		{ WM_CREATE, 0, 0, 0, AfxSig_lwl, 
		(AFX_PMSG)(AFX_PMSGW) (static_cast<LRESULT(AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM)> (OnCREATE)) },

		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } 
	}; 
	__pragma(warning(pop))	
	static const AFX_MSGMAP messageMap = 
	{ &TheBaseClass::GetThisMessageMap, &_messageEntries[0] }; 
	return &messageMap; 
}								  
PTM_WARNING_RESTORE

//�Զ���Ӧ�ó�����
class CMyWinApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};

//����Ӧ�ó������ȫ�ֶ���
CMyWinApp theApp;

BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame = new CMyFrameWnd;
	pFrame->Create(NULL, "MFCCreate");
	m_pMainWnd = pFrame;
	pFrame->ShowWindow(SW_SHOW);
	pFrame->UpdateWindow();
	return TRUE;
}

LRESULT CMyFrameWnd::OnCREATE(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox("WM_CREATE��Ϣ������");
	return 0;
}
