// wcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "wc.h"
#include "wcDlg.h"
#include<io.h>
#include<Afx.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<io.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

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
// CWcDlg dialog

CWcDlg::CWcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWcDlg)
	m_editFileName = _T("");
	m_editResult = _T("");
	m_editChar = _T("");
	m_charNum = 0;
	m_wordNum = 0;
	m_blankLineNum = 0;
	m_codeLineNum = 0;
	m_referLineNum = 0;
	m_lineNum = 0;
	m_fileList = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWcDlg)
	DDX_Text(pDX, IDC_EDIT1, m_editFileName);
	DDV_MaxChars(pDX, m_editFileName, 100);
	DDX_Text(pDX, IDC_EDIT7, m_charNum);
	DDX_Text(pDX, IDC_EDIT8, m_wordNum);
	DDX_Text(pDX, IDC_EDIT10, m_blankLineNum);
	DDX_Text(pDX, IDC_EDIT11, m_codeLineNum);
	DDX_Text(pDX, IDC_EDIT12, m_referLineNum);
	DDX_Text(pDX, IDC_EDIT9, m_lineNum);
	DDX_Text(pDX, IDC_EDIT13, m_fileList);
	DDV_MaxChars(pDX, m_fileList, 3000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWcDlg, CDialog)
	//{{AFX_MSG_MAP(CWcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnCheck)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEditFileName)
	ON_EN_CHANGE(IDC_EDIT7, OnChangeEdit7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWcDlg message handlers

BOOL CWcDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWcDlg::OnPaint() 
{
	if (IsIconic())
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
HCURSOR CWcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWcDlg::OnOK() 
{
	CDialog::OnOK();
	// TODO: Add extra validation here
	
	
}

void CWcDlg::OnLookResult() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	UpdateData(FALSE);
}

//空行
    int count_blankLine(CString file)
	{
	   FILE *f;
      int blCount= 0;
      int ch_num = 0;
      char ch;
	  fflush(stdin);
      f = fopen(file, "r");
       if(NULL==(f=fopen(file,"r")))
	   {
       printf("文件为空");
	   }
       else
           while (!feof(f))
		   {
             ch= fgetc(f);
             if (ch=='\n'){
                if (ch_num<= 1)
                    blCount++;
                    ch_num = 0;
			 }
             else if (ch!=' '&&ch!='\t')
                    ch_num++;
		   }
		   if(f!=NULL)
           fclose(f);
	   return blCount;
	}

	//代码行
	int count_codeLine(CString file)
	{   
		FILE *fp;
		fflush(stdin);
		fp=fopen(file,"r");
		int clCount=0;
		char a;
		if(NULL==fp)
		{
		  printf("文件为空\n");
		}else{
			while((a=fgetc(fp))!=EOF){
				 if(a==';')
					 clCount++;	  
			}
		}
		if(fp!=NULL)
		fclose(fp);
	  
	   return clCount;
	}
	//注释行
    int count_noteLine(CString file)
	{
	    FILE *f;
        int ch_num = 0;
		int nlCount=0;
        char ch;
		fflush(stdin);
        f=fopen(file, "r");
        if(NULL==(f=fopen(file,"r")))
		{
         printf("文件为空\n");
		}
      else
         while (!feof(f))
		 {
              ch= fgetc(f);
              if(ch=='\n')
			  {
				  if(ch_num==2) 
					  nlCount++;
				      ch_num=0;
			  }
             else if(ch=='/') 
				 ch_num++;
             else if(ch_num==1)
			 {
				 if(ch=='/') 
					 ch_num++;
			 } 
		 } 
		 if(f!=NULL)
       fclose(f);
	   return nlCount;
	}
	
void CWcDlg::OnCheck() 
{
	// TODO: Add your control notification handler code here

	//文件字符数
	int cCount=0;
	if(((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck()) 
	{
		FILE *fp;
		fflush(stdin);
		fp=fopen(m_editFileName,"r");
		char a;
		
		if(NULL==fp)
		{
		  printf("文件为空\n");
		}else{
			while((a=fgetc(fp))!=EOF){
				  cCount++;
			}
		}
		UpdateData(FALSE);
		 m_charNum=cCount;
		if (fp!=NULL)  
	    fclose(fp);
	   
	}
	//文件单词数
	int wCount=0;
	if(((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck()){
		FILE *fp;
		
		int is_word=0;
		char a;
		fflush(stdin);
		fp=fopen(m_editFileName,"r");
		if(fp==NULL){
		  printf("文件打开失败\n");
		}else{
			while(!feof(fp)){
				a=fgetc(fp);
				if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||a=='_')
					is_word=1;
				else if(is_word){
				     wCount++;
					 is_word=0;
				}
				}
			}
		UpdateData(FALSE);
		m_wordNum=wCount;
		if (fp!=NULL) 
		fclose(fp);
	}
	//文件总行数
	int lCount=0;
    if(((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck()){
	  	FILE *fp;
		fflush(stdin);
		fp=fopen(m_editFileName,"r");
		
		char a;
		if(NULL==fp)
		{
		  printf("文件为空\n");
		}else{
			while((a=fgetc(fp))!=EOF){
			  if(a=='\n')
				  lCount++;
			}
		}
		UpdateData(FALSE);
		m_lineNum=lCount;
		if (fp!=NULL) 
		fclose(fp);
	}
	//文件空行、代码、注释
	int blCount=0,clCount=0,rlCount=0;
    if(((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck()){
	   blCount=count_blankLine(m_editFileName);
		   m_blankLineNum=blCount;
	   clCount=count_codeLine(m_editFileName);
	      m_codeLineNum=clCount;
	   rlCount=count_noteLine(m_editFileName);
          m_referLineNum=rlCount;
	}
	//保存
    if(((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck()){
	    FILE *wp;
		fflush(stdin);
		wp=fopen("outputFile.txt","a");
	  if(wp==NULL){
		   printf("文件不存在\n\n");
	  }else{
		  if(cCount!=0){
			      
			      fprintf(wp, "%s文件中字符数有%d\n", m_editFileName,cCount);
		  }
			       
		  if(wCount!=0){
			       fprintf(wp, "%s文件中单词数有%d\n",m_editFileName,wCount);
		  }
			     
		  if(lCount!=0){
			       fprintf(wp, "%s文件中总行数数有%d\n",m_editFileName, lCount);
		  }
			  
		  if(blCount!=0){
			       fprintf(wp, "%s文件中代码行数有%d\n",m_editFileName, blCount);
		  }
		  if(clCount!=0){
			      fprintf(wp, "%s文件中空行数有%d\n",m_editFileName, clCount);
		  }
		  if(rlCount!=0){
			       fprintf(wp, "%s文件中注释数有%d\n",m_editFileName, rlCount);
		  }
		   
	  }
	if(wp!=NULL)
     fclose(wp);
	}
	
	 UpdateData(FALSE);
	
}
    
	//递归找符合条件的文件
    void scanFile(char *file)
	{
	   struct _finddata_t filefind;
	   long handle;
	   int t=0;
	   if((handle=_findfirst(file,&filefind))==-1L)
	   {
	     printf("没找到此类型文件");
	   }
	   else
		   do{
		     t++;
			 printf("找到文件:%s\n",filefind.name);
		   }while(_findnext(handle,&filefind)==0);
		   _findclose(handle);
		   printf("文件数量：%d\n",t);
	 
	}

void CWcDlg::OnChangeEditFileName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
	UpdateData(FALSE);
}

void CWcDlg::OnChangeEdit7() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
}
