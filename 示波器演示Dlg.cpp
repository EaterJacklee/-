#include "stdafx.h"
#include "示波器演示.h"
#include "示波器演示Dlg.h"
#include "mmsystem.h"
#include <math.h>
#pragma comment(lib,"winmm.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
char flag=0;

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnClose();
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
	
	, m_ch1_ampt(4)
	, m_ch1_feq(1)
	, m_ch1_vert(0)

	, m_ch2_ampt(0)
	, m_ch2_feq(0)
	, m_ch2_vert(0)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)

	DDX_Control(pDX, IDC_SCOPE2, m_wndScope2);
	DDX_Control(pDX, IDC_SCOPE, m_wndScope);
	//}}AFX_DATA_MAP


	DDX_Control(pDX, IDC_COMBO2, m_ch1_style);
	DDX_Control(pDX, IDC_COMBO1, m_ch1_type);
	DDX_Control(pDX, IDC_COMBO3, m_ch1_width);
	DDX_Control(pDX, IDC_COMBO5, m_ch1_color);

	DDX_Control(pDX, IDC_COMBO4, m_ch2_type);
	DDX_Control(pDX, IDC_COMBO8, m_ch2_width);
	DDX_Control(pDX, IDC_COMBO10, m_ch2_color);
	DDX_Control(pDX, IDC_COMBO7, m_ch2_style);

	DDX_Text(pDX, IDC_EDIT2, m_ch1_feq);
	DDX_Text(pDX, IDC_EDIT5, m_ch1_vert);
	DDV_MinMaxFloat(pDX, m_ch1_vert, -100, 100);
	DDX_Control(pDX, IDC_SPIN1, m_ch1_spin_ampt);
	//DDX_Control(pDX, IDC_SPIN2, m_ch1_spin_feq);
	//DDX_Control(pDX, IDC_SPIN3, m_ch1_spin_vert);
	DDX_Text(pDX, IDC_EDIT1, m_ch1_ampt);
	DDV_MinMaxFloat(pDX, m_ch1_ampt, 0, 10);
	DDX_Text(pDX, IDC_EDIT3, m_ch2_ampt);
	DDX_Text(pDX, IDC_EDIT4, m_ch2_feq);
	DDX_Text(pDX, IDC_EDIT6, m_ch2_vert);
	DDX_Control(pDX, IDC_SPIN4, m_ch2_spin_ampt);

	DDX_Control(pDX, IDC_SPIN5, m_ch2_spin_feq);
	DDX_Control(pDX, IDC_SPIN6, m_ch2_spin_vert);
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP

	ON_WM_CLOSE()

	

	ON_BN_CLICKED(IDC_BUTTON1, &CMyDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CMyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMyDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMyDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMyDlg::OnBnClickedButton7)
	ON_CBN_SETFOCUS(IDC_COMBO2, &CMyDlg::OnCbnSetfocusCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CMyDlg::OnCbnSelchangeCombo2)
	ON_CBN_SETFOCUS(IDC_COMBO1, &CMyDlg::OnCbnSetfocusCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMyDlg::OnCbnSelchangeCombo1)
	ON_CBN_SETFOCUS(IDC_COMBO4, &CMyDlg::OnCbnSetfocusCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CMyDlg::OnCbnSelchangeCombo4)
	ON_BN_CLICKED(IDC_BUTTON8, &CMyDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMyDlg::OnBnClickedButton9)
	ON_CBN_SETFOCUS(IDC_COMBO3, &CMyDlg::OnCbnSetfocusCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CMyDlg::OnCbnSelchangeCombo3)
	ON_CBN_SETFOCUS(IDC_COMBO5, &CMyDlg::OnCbnSetfocusCombo5)
	ON_CBN_SELCHANGE(IDC_COMBO5, &CMyDlg::OnCbnSelchangeCombo5)




ON_CBN_SELCHANGE(IDC_COMBO8, &CMyDlg::OnCbnSelchangeCombo8)
ON_CBN_SELCHANGE(IDC_COMBO10, &CMyDlg::OnCbnSelchangeCombo10)
ON_CBN_SETFOCUS(IDC_COMBO8, &CMyDlg::OnCbnSetfocusCombo8)
ON_CBN_SETFOCUS(IDC_COMBO10, &CMyDlg::OnCbnSetfocusCombo10)
ON_CBN_SELCHANGE(IDC_COMBO7, &CMyDlg::OnCbnSelchangeCombo7)
ON_CBN_SETFOCUS(IDC_COMBO7, &CMyDlg::OnCbnSetfocusCombo7)
ON_EN_CHANGE(IDC_EDIT1, &CMyDlg::OnEnChangeEdit1)
ON_EN_CHANGE(IDC_EDIT2, &CMyDlg::OnEnChangeEdit2)
ON_BN_CLICKED(IDC_BUTTON3, &CMyDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON10, &CMyDlg::OnBnClickedButton10)
ON_BN_CLICKED(IDC_BUTTON11, &CMyDlg::OnBnClickedButton11)
ON_BN_CLICKED(IDC_BUTTON12, &CMyDlg::OnBnClickedButton12)
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CMyDlg::OnDeltaposSpin1)
ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, &CMyDlg::OnDeltaposSpin2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_wndScope.SetTitle("通道1");
	m_wndScope.SetValueString("幅值","m");

	m_wndScope2.SetTitle("通道2");
	m_wndScope2.SetValueString("幅值", "m");

	m_ch1_spin_ampt.SetRange(0, 10);
	//m_ch1_spin_feq.SetRange(0, 10);
	//m_ch1_spin_vert.SetRange(0, 10);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN2))->SetRange(0, 10);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN3))->SetRange(0, 10);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN4))->SetRange(0, 10);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN5))->SetRange(0, 10);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN6))->SetRange(0, 10);

							//0.02秒调用一次ontimer函数
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)		//关于信息
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())			//判断是否最小化
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()   //缺省鼠标icon
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnTimer(UINT nIDEvent) 
{
	double dTime = ::timeGetTime() / 1000.0;
	double dValue[3];

	char* end;


	if (nIDEvent	== 1)
	{
		CString strEdit_ch1_ampt;
		CEdit* pEdit_ch1_ampt = (CEdit*)GetDlgItem(IDC_EDIT1);
		pEdit_ch1_ampt->GetWindowText(strEdit_ch1_ampt);

		CString strEdit_ch1_feq;
		CEdit* pEdit_ch1_feq = (CEdit*)GetDlgItem(IDC_EDIT2);
		pEdit_ch1_feq->GetWindowText(strEdit_ch1_feq);

		CString strEdit_ch1_vert;
		CEdit* pEdit_ch1_vert = (CEdit*)GetDlgItem(IDC_EDIT5);
		pEdit_ch1_vert->GetWindowText(strEdit_ch1_vert);

		strEdit_ch1_ampt.TrimLeft();
		strEdit_ch1_ampt.TrimRight();
		strEdit_ch1_feq.TrimLeft();
		strEdit_ch1_feq.TrimRight();

		if (strEdit_ch1_ampt.IsEmpty())
		{
			;
		}
		else
		{

		ch1_ampt = atoi(strEdit_ch1_ampt);
		}

		if (strEdit_ch1_feq.IsEmpty())
		{
			;
		}
		else
		{
			
			ch1_feq = atoi(strEdit_ch1_feq);
		}

		if (strEdit_ch1_vert.IsEmpty())
		{
			;
		}
		else
		{
			ch1_vert = atoi(strEdit_ch1_vert);
		}

		if (flag == 1)		//flag  判断干扰
			dValue[0] =( ch1_ampt * sin(ch1_feq*dTime + 2) + ch1_vert) / sin(dTime);
		else dValue[0] = ch1_ampt * sin(ch1_feq*dTime + 2)+ch1_vert;		//正弦
		dValue[1] = pow((-1), (ch1_feq*int(dTime)))*ch1_ampt + ch1_vert;		//方波
		/*dValue[1] = sgn(sin(t));*/
		dValue[2] = 2 * ch1_ampt*(ch1_feq*dTime - floor(ch1_feq*dTime)) - ch1_ampt + ch1_vert;		//三角波 ?overflow

		switch (m_ch1_type.GetCurSel() )
		{
		case 0:
		{
			m_wndScope.AddValue(dTime, dValue[0]);
			m_wndScope.SetValue(dValue[0]);
			m_wndScope.UpdateCurve(); break;
		}
		case 1:
		{
			m_wndScope.AddValue(dTime, dValue[1]);
			m_wndScope.SetValue(dValue[1]);
			m_wndScope.UpdateCurve(); break;
		}
		case 2:
		{
			m_wndScope.AddValue(dTime, dValue[2]);
			m_wndScope.SetValue(dValue[2]);
			m_wndScope.UpdateCurve(); break;
		}
		default:
		{
			m_wndScope.AddValue(dTime, dValue[0]);
			m_wndScope.SetValue(dValue[0]);
			m_wndScope.UpdateCurve(); break;
		}
		}
	}
	if (nIDEvent	== 2)
	{
		CString strEdit_ch2_ampt;
		CEdit* pEdit_ch2_ampt = (CEdit*)GetDlgItem(IDC_EDIT3);
		pEdit_ch2_ampt->GetWindowText(strEdit_ch2_ampt);

		CString strEdit_ch2_feq;
		CEdit* pEdit_ch2_feq = (CEdit*)GetDlgItem(IDC_EDIT4);
		pEdit_ch2_feq->GetWindowText(strEdit_ch2_feq);

		CString strEdit_ch2_vert;
		CEdit* pEdit_ch2_vert = (CEdit*)GetDlgItem(IDC_EDIT6);
		pEdit_ch2_vert->GetWindowText(strEdit_ch2_vert);

		strEdit_ch2_ampt.TrimLeft();
		strEdit_ch2_ampt.TrimRight();
		strEdit_ch2_feq.TrimLeft();
		strEdit_ch2_feq.TrimRight();

		if (strEdit_ch2_ampt.IsEmpty())
		{
			ch2_ampt = 4;
		}
		else
		{
			ch2_ampt = static_cast<int>(strtol(strEdit_ch2_ampt, &end, 16));
		}

		if (strEdit_ch2_feq.IsEmpty())
		{
			ch2_feq = 1;
		}
		else
		{
			ch2_feq = static_cast<int>(strtol(strEdit_ch2_feq, &end, 16));
		}

		if (strEdit_ch2_vert.IsEmpty())
		{
			ch2_vert = 0;
		}
		else
		{
			ch2_vert = static_cast<int>(strtol(strEdit_ch2_vert, &end, 16));
		}

		if (flag == 1)		//flag  判断干扰
			dValue[0] = (ch2_ampt * sin(ch2_feq*dTime + 2) + ch2_vert) / sin(dTime);
		else dValue[0] = ch2_ampt * sin(ch2_feq*dTime + 2) + ch2_vert;		//正弦
		dValue[1] = pow((-1), (ch2_feq*int(dTime)))*ch2_ampt + ch2_vert;		//方波
		/*dValue[1] = sgn(sin(t));*/
		dValue[2] = 2 * ch2_ampt*(ch2_feq*dTime - floor(ch2_feq*dTime)) - ch2_ampt + ch2_vert;		//三角波 ?overflow

		switch (m_ch2_type.GetCurSel())
		{
		case 0:
		{
			m_wndScope2.AddValue(dTime, dValue[0]);
			m_wndScope2.SetValue(dValue[0]);
			m_wndScope2.UpdateCurve(); break;
		}
		case 1:
		{
			m_wndScope2.AddValue(dTime, dValue[1]);
			m_wndScope2.SetValue(dValue[1]);
			m_wndScope2.UpdateCurve(); break;
		}
		case 2:
		{
			m_wndScope2.AddValue(dTime, dValue[2]);
			m_wndScope2.SetValue(dValue[2]);
			m_wndScope2.UpdateCurve(); break;
		}
		default:
		{
			m_wndScope2.AddValue(dTime, dValue[0]);
			m_wndScope2.SetValue(dValue[0]);
			m_wndScope2.UpdateCurve(); break;
		}
		}
	}
	
	CDialog::OnTimer(nIDEvent);
}

void CMyDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(MessageBox(_T("你确认要退出吗！\n请确认是否保存参数！"), _T("提示"), MB_YESNO | MB_ICONWARNING)
		
		== IDNO)
		
		return;

	CDialog::OnClose();
}


void CMyDlg::OnClickedButton1()
{
	SetTimer(1, 20, NULL);
}


void CMyDlg::OnBnClickedButton2()
{
	
	KillTimer(1);
	m_wndScope.Clear();
}


void CMyDlg::OnBnClickedButton4()
{
	SetTimer(2, 20, NULL);
}


void CMyDlg::OnBnClickedButton5()
{
	KillTimer(2);
	m_wndScope2.Clear();
}


void CMyDlg::OnBnClickedButton6()
{
	SetTimer(1, 20, NULL);
	SetTimer(2, 20, NULL);
}


void CMyDlg::OnBnClickedButton7()
{
	KillTimer(1);
	m_wndScope.Clear();
	KillTimer(2);
	m_wndScope2.Clear();
}


void CMyDlg::OnCbnSetfocusCombo2()
{
	m_ch1_style.ResetContent();
	m_ch1_style.AddString(_T("实线"));
	m_ch1_style.AddString(_T("虚线"));
	m_ch1_style.AddString(_T("内框线"));
	m_ch1_style.AddString(_T("点线"));
	m_ch1_style.AddString(_T("点划线"));
	m_ch1_style.AddString(_T("双点划线"));
	m_ch1_style.SetCurSel(-1);
}


void CMyDlg::OnCbnSelchangeCombo2()
{		
		switch (m_ch1_style.GetCurSel())
		{
		
		case 0: 	m_wndScope.style = PS_SOLID;		break;
		case 1:		m_wndScope.style = PS_DASH; 		break;
		case 2:		m_wndScope.style = PS_INSIDEFRAME; 	break;
		case 3: 	m_wndScope.style = PS_DOT;			break;
		case 4:		m_wndScope.style = PS_DASHDOT;		break;
		case 5: 	m_wndScope.style = PS_DASHDOTDOT;	break;
		default:	m_wndScope.style = PS_SOLID;
		}
	
}


void CMyDlg::OnCbnSetfocusCombo1()
{
	m_ch1_type.ResetContent();
	m_ch1_type.AddString(_T("正弦波"));
	m_ch1_type.AddString(_T("方波"));
	m_ch1_type.AddString(_T("三角波"));
	m_ch1_type.SetCurSel(-1);
}


void CMyDlg::OnCbnSelchangeCombo1()
{

}


void CMyDlg::OnCbnSetfocusCombo4()
{
	m_ch2_type.ResetContent();
	m_ch2_type.AddString(_T("正弦波"));
	m_ch2_type.AddString(_T("方波"));
	m_ch2_type.AddString(_T("三角波"));
	m_ch2_type.SetCurSel(-1);
}


void CMyDlg::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton8()
{
	flag = 1;
	AfxMessageBox("开启干扰");
}


void CMyDlg::OnBnClickedButton9()
{
	flag = 0;
	AfxMessageBox("滤除干扰");
}





void CMyDlg::OnCbnSetfocusCombo3()
{
	m_ch1_width.ResetContent();
	m_ch1_width.AddString(_T("1像素"));
	m_ch1_width.AddString(_T("2像素"));
	m_ch1_width.AddString(_T("3像素"));
	m_ch1_width.SetCurSel(-1);
}


void CMyDlg::OnCbnSelchangeCombo3()
{
	switch (m_ch1_width.GetCurSel())
	{
	case 0: 	m_wndScope.width = 1;		break;
	case 1:		m_wndScope.width = 2; 		break;
	case 2:		m_wndScope.width = 3; 		break;
	default:	m_wndScope.width = 1;
	}
}


void CMyDlg::OnCbnSetfocusCombo5()
{
	m_ch1_color.ResetContent();
	m_ch1_color.AddString(_T("红"));
	m_ch1_color.AddString(_T("绿"));
	m_ch1_color.AddString(_T("蓝"));
	m_ch1_color.SetCurSel(-1);
}


void CMyDlg::OnCbnSelchangeCombo5()
{
	switch (m_ch1_color.GetCurSel())
	{

	case 0: 	m_wndScope.color = RGB(255,0,0);		break;
	case 1:		m_wndScope.color = RGB(0, 255, 0); 		break;
	case 2:		m_wndScope.color = RGB(0, 0, 255); 		break;
	default:	m_wndScope.color = RGB(255, 0, 0);
	}
}




void CMyDlg::OnCbnSetfocusCombo8()
{
	m_ch2_width.ResetContent();
	m_ch2_width.AddString(_T("1像素"));
	m_ch2_width.AddString(_T("2像素"));
	m_ch2_width.AddString(_T("3像素"));
	m_ch2_width.SetCurSel(-1);
}



void CMyDlg::OnCbnSelchangeCombo8()
{
	switch (m_ch2_width.GetCurSel())
	{
	case 0: 	m_wndScope2.width = 1;		break;
	case 1:		m_wndScope2.width = 2; 		break;
	case 2:		m_wndScope2.width = 3; 		break;
	default:	m_wndScope2.width = 1;
	}
}


void CMyDlg::OnCbnSelchangeCombo10()
{
	switch (m_ch2_color.GetCurSel())
	{

	case 0: 	m_wndScope2.color = RGB(255, 0, 0);		break;
	case 1:		m_wndScope2.color = RGB(0, 255, 0); 		break;
	case 2:		m_wndScope2.color = RGB(0, 0, 255); 		break;
	default:	m_wndScope2.color = RGB(255, 0, 0);
	}
}



void CMyDlg::OnCbnSetfocusCombo10()
{
	m_ch2_color.ResetContent();
	m_ch2_color.AddString(_T("红"));
	m_ch2_color.AddString(_T("绿"));
	m_ch2_color.AddString(_T("蓝"));
	m_ch2_color.SetCurSel(-1);
}


void CMyDlg::OnCbnSelchangeCombo7()
{
	 switch (m_ch2_style.GetCurSel())
	{
	case 0: 	m_wndScope2.style = PS_SOLID;			break;
	case 1:		m_wndScope2.style = PS_DASH; 			break;
	case 2:		m_wndScope2.style = PS_INSIDEFRAME; 	break;
	case 3: 	m_wndScope2.style = PS_DOT;				break;
	case 4:		m_wndScope2.style = PS_DASHDOT;			break;
	case 5: 	m_wndScope2.style = PS_DASHDOTDOT;		break;
	default:	m_wndScope2.style = PS_SOLID;
	}
}


void CMyDlg::OnCbnSetfocusCombo7()
{
	m_ch2_style.ResetContent();
	m_ch2_style.AddString(_T("实线"));
	m_ch2_style.AddString(_T("虚线"));
	m_ch2_style.AddString(_T("内框线"));
	m_ch2_style.AddString(_T("点线"));
	m_ch2_style.AddString(_T("点划线"));
	m_ch2_style.AddString(_T("双点划线"));
	m_ch2_style.SetCurSel(-1);
}





void CMyDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton3()
{
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, "D:\\parameter.ini");

	s_ch1_ampt.Format("%d", ch1_ampt);
	WritePrivateProfileString("ch1", "ch1_ampt", s_ch1_ampt, lpPath);
	s_ch1_feq.Format("%d", ch1_feq);
	WritePrivateProfileString("ch1", "ch1_feq", s_ch1_feq, lpPath);
	s_ch1_vert.Format("%d", ch1_vert);
	WritePrivateProfileString("ch1", "ch1_vert", s_ch1_vert, lpPath);
	s_ch1_color.Format("%u", (DWORD)m_wndScope.color);
	WritePrivateProfileString("ch1", "color", s_ch1_color, lpPath);
	s_ch1_style.Format("%s", m_wndScope.style);
	WritePrivateProfileString("ch1", "style", s_ch1_style, lpPath);
	s_ch1_width.Format("%d", m_wndScope.width);
	WritePrivateProfileString("ch1", "width", s_ch1_width, lpPath);


	delete[] lpPath;
	AfxMessageBox("保存参数成功!\n参数保存在parameter.ini");
}


void CMyDlg::OnBnClickedButton10()
{
	LPTSTR lpPath = new char[MAX_PATH];

	strcpy(lpPath, "D:\\parameter.ini");
	

	ch1_ampt = GetPrivateProfileInt("ch1", "ch1_ampt", 1, lpPath);
	ch1_feq = GetPrivateProfileInt("ch1", "ch1_feq", 1, lpPath);
	ch1_vert = GetPrivateProfileInt("ch1", "ch1_vert", 0, lpPath);
	m_wndScope.color = GetPrivateProfileInt("ch1", "color", RGB(0,0,255), lpPath);
	m_wndScope.style = GetPrivateProfileInt("ch1", "style", PS_SOLID, lpPath);
	m_wndScope.width = GetPrivateProfileInt("ch1", "width", 1, lpPath);


	delete[] lpPath;
	AfxMessageBox("读取参数成功!\n曲线参数已恢复");
}


void CMyDlg::OnBnClickedButton11()
{
	WinExec("放大镜.exe", SW_SHOW);// TODO: 在此添加控件通知处理程序代码
}


void CMyDlg::OnBnClickedButton12()
{
	UpdateData();
	HWND target = ::FindWindow(NULL, "放大镜");
	if (NULL == target)
	{
		AfxMessageBox("Not find");
		return;
	}

	::SendMessage(target, WM_CLOSE, 0, 0);
}


void CMyDlg::OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	//LPNMUPDOWN pNMUpDown = (NM_UPDOWN*)pNMHDR;
	//UpdateData(TRUE);
	//m_ch1_ampt += (float)pNMUpDown->iDelta * 0.5f;
	//if (m_ch1_ampt < 0)
	//	m_ch1_ampt = 0;
	//if (m_ch1_ampt > 10)
	//	m_ch1_ampt = 10;
	//
	//UpdateData(FALSE);
	
	*pResult = 0;
}


void CMyDlg::OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);

	//UpdateData(TRUE);
	//m_ch1_feq += (float)pNMUpDown->iDelta * 0.5f;
	//if (m_ch1_feq < 0)
	//	m_ch1_feq = 10;
	//if (m_ch1_feq > 10)
	//	m_ch1_feq = 0;
	//UpdateData(FALSE);


	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
}
