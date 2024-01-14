// loginDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "login.h"
#include "loginDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CloginDlg 对话框 构造函数 初始化对话框数据
/*
 CloginDlg的对话框类的构造函数.它继承自CDialogEx类，并且接受一个指向CWnd对象的指针作为参数.
*/
CloginDlg::CloginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN_DIALOG, pParent)
	//
	, m_csPwd(_T(""))  //
	, m_csUser(_T("")) //
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

/*
DoDataExchange函数用于将对话框中的控件数据与成员变量进行交换。
在这个函数中，我们使用了DDX_Text宏来实现文本框控件和成员变量之间的数据交换。
*/
void CloginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Password, m_csPwd);
	DDX_Text(pDX, IDC_Username, m_csUser);
}
/*
宏定义的消息映射表，用于将消息与对话框类的成员函数关联起来
用于将用户界面事件（例如点击按钮、绘制窗口等）与对应的处理函数关联起来
*/
BEGIN_MESSAGE_MAP(CloginDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/*
	将 BN_CLICKED 消息与 CloginDlg 类的 OnBnClickedOk 成员函数关联起来。
	BN_CLICKED 消息是在按钮被点击时发送给窗口的消息。IDOK 是一个预定义的标识符，表示对话框的“确定”按钮。
	*/
	ON_BN_CLICKED(IDOK, &CloginDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_Password, &CloginDlg::OnEnChangePassword)
END_MESSAGE_MAP()


// CloginDlg 消息处理程序

BOOL CloginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码  initialize code

	//m_csUser = _T("admin");
	m_csUser = _T("admin");
	m_csPwd = _T("");//密码为空 >> 此时可以密码为空
	UpdateData(FALSE);//更新数据到控件
	GetDlgItem(IDC_Password)->SetFocus();//设置焦点到用户名输入框 >> 指针 ->
	GetDlgItem(IDOK)->EnableWindow(FALSE);//禁用密码输入框



	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CloginDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CloginDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CloginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// https://learn.microsoft.com/en-us/cpp/mfc/reference/cwnd-class?view=msvc-170
void CloginDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);//更新数据到变量 >> 变量中的值 >> 把值更新过来
    MessageBox(m_csUser + "\n" + m_csPwd); 
	//弹出对话框 >> 用户名 + 密码 >> 在这里不使用宏而是使用换行（转义）实现同样意思

    /*
	在C++中，_T是一个宏，用于在字符串前面添加一个前缀，
	以指示该字符串应该以宽字符（Unicode）还是窄字符（ANSI）的形式进行编译。
	*/
	if (m_csUser == "admin" && m_csPwd == "123456") {
					MessageBox(_T("successful"));
    }
    else {
					MessageBox(_T("failure"));
    }
    CDialogEx::OnOK();
}


void CloginDlg::OnEnChangePassword()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDOK)->EnableWindow(TRUE);//启用密码输入框
}

