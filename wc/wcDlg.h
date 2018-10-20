// wcDlg.h : header file
//

#if !defined(AFX_WCDLG_H__3E619460_176E_4CBB_9F39_0094E19F1993__INCLUDED_)
#define AFX_WCDLG_H__3E619460_176E_4CBB_9F39_0094E19F1993__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWcDlg dialog

class CWcDlg : public CDialog
{
// Construction
public:
	CWcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWcDlg)
	enum { IDD = IDD_WC_DIALOG };
	CString	m_editFileName;
	CString	m_editResult;
	CString	m_editChar;
	int		m_charNum;
	int		m_wordNum;
	int		m_blankLineNum;
	int		m_codeLineNum;
	int		m_referLineNum;
	int		m_lineNum;
	CString	m_fileList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnLookResult();
	afx_msg void OnCheck();
	afx_msg void OnChangeEditFileName();
	afx_msg void OnChangeEdit7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WCDLG_H__3E619460_176E_4CBB_9F39_0094E19F1993__INCLUDED_)
