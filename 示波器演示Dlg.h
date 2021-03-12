
#if !defined(AFX_DLG_H__F844B126_01B5_11D9_ADC4_000C6E800FC7__INCLUDED_)
#define AFX_DLG_H__F844B126_01B5_11D9_ADC4_000C6E800FC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////

#include "Scope.h"

class CMyDlg : public CDialog
{
// Construction
public:
	CMyDlg(CWnd* pParent = NULL);	// standard constructor
	char ch1_ampt = 4;	//Õñ·ù
	char ch1_feq = 1;	//ÆµÂÊ
	char ch1_vert = 0;
	char ch2_ampt = 4;	//Õñ·ù
	char ch2_feq = 1;	//ÆµÂÊ
	char ch2_vert = 0;
	CString	s_ch1_ampt;
	CString	s_ch1_vert;
	CString	s_ch1_feq;
	CString	s_ch1_color;
	CString	s_ch1_style;
	CString	s_ch1_width;
	CString	s_ch1_type;
	// Dialog Data
	//{{AFX_DATA(CMyDlg)
	enum { IDD = IDD_MY_DIALOG };
	CScope	m_wndScope2;
	CScope	m_wndScope;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnClose();


	afx_msg void OnBnClickedButton1();
	afx_msg void OnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();

	afx_msg void OnCbnSetfocusCombo2();
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox m_ch1_type;
	afx_msg void OnCbnSetfocusCombo1();
	afx_msg void OnCbnSelchangeCombo1();

	afx_msg void OnCbnSetfocusCombo4();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();

	CComboBox m_ch1_width;
	afx_msg void OnCbnSetfocusCombo3();
	afx_msg void OnCbnSelchangeCombo3();
	CComboBox m_ch1_color;
	afx_msg void OnCbnSetfocusCombo5();
	afx_msg void OnCbnSelchangeCombo5();

	afx_msg void OnCbnSelchangeCombo6();
	afx_msg void OnCbnSetfocusCombo6();
	afx_msg void OnCbnSelchangeCombo9();

	CComboBox m_color;

	afx_msg void OnCbnSelchangeCombo8();
	afx_msg void OnCbnSelchangeCombo10();
	CComboBox m_ch2_type;
	CComboBox m_ch1_style;
//	CComboBox m_ch2_style;
//	CComboBox m_ch2_style;
	CComboBox m_ch2_width;
	CComboBox m_ch2_color;
	afx_msg void OnCbnSetfocusCombo8();
	afx_msg void OnCbnSetfocusCombo10();
	CComboBox m_ch2_style;
	afx_msg void OnCbnSelchangeCombo7();
	afx_msg void OnCbnSetfocusCombo7();
//	int m_ampt;
//	CSpinButtonCtrl m_spin;
//	afx_msg void OnEnChangeEdit1();
//	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	float m_ch1_ampt;
	float m_ch1_feq;
	float m_ch1_vert;
	CSpinButtonCtrl m_ch1_spin_ampt;
	CSpinButtonCtrl m_ch1_spin_feq;
	CSpinButtonCtrl m_ch1_spin_vert;
	afx_msg void OnDeltaposSpin1(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnDeltaposSpin2(NMHDR *pNMHDR, LRESULT *pResult);
	float m_ch2_ampt;
	float m_ch2_feq;
	float m_ch2_vert;
	CSpinButtonCtrl m_ch2_spin_ampt;

	CSpinButtonCtrl m_ch2_spin_feq;
	CSpinButtonCtrl m_ch2_spin_vert;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__F844B126_01B5_11D9_ADC4_000C6E800FC7__INCLUDED_)
