
// kalculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "kalculator.h"
#include "kalculatorDlg.h"
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


// CkalculatorDlg 对话框



CkalculatorDlg::CkalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KALCULATOR_DIALOG, pParent)
	, m_csRes(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CkalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RES, m_csRes);
}

BEGIN_MESSAGE_MAP(CkalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDABORT, &CkalculatorDlg::OnBnClickedAbort)
ON_BN_CLICKED(IDC_BUTTON0, &CkalculatorDlg::OnBnClickedButton0)
//ON_BN_CLICKED(IDABORT, &CkalculatorDlg::OnBnClickedAbort)
ON_BN_CLICKED(IDABORT, &CkalculatorDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CkalculatorDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CkalculatorDlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CkalculatorDlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &CkalculatorDlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON6, &CkalculatorDlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON7, &CkalculatorDlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CkalculatorDlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON9, &CkalculatorDlg::OnBnClickedButton9)
ON_BN_CLICKED(IDC_Sum, &CkalculatorDlg::OnBnClickedSum)
ON_BN_CLICKED(IDC_Sub, &CkalculatorDlg::OnBnClickedSub)
ON_BN_CLICKED(IDC_Mult, &CkalculatorDlg::OnBnClickedMult)
ON_BN_CLICKED(IDC_Divi, &CkalculatorDlg::OnBnClickedDivi)
ON_BN_CLICKED(IDC_Equ, &CkalculatorDlg::OnBnClickedEqu)
ON_BN_CLICKED(IDC_Dot, &CkalculatorDlg::OnBnClickedDot)
ON_BN_CLICKED(IDC_EquTwo, &CkalculatorDlg::OnBnClickedEqutwo)
END_MESSAGE_MAP()


// CkalculatorDlg 消息处理程序

/*
该函数是对话框初始化时自动调用的一个函数。在这个函数中，你可以进行一些初始化设置，比如设置图标、菜单项等。
*/
BOOL CkalculatorDlg::OnInitDialog()
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

	// TODO: 在此添加额外的初始化代码

	// custome codes

//void CkalculatorDlg::ResetInput(bool bResetOpType)
//{
//	
//	if (bResetOpType) // 如果需要重置运算符类型
//	{	bResetOpType = false; // 重置运算符类型
//		m_csRes = _T("0"); // 清空显示型
//	}
//		else UpdateData(TRUE); // 从控件更新到变量
//}

	m_iOpType = -1; //未输入运算符
	m_csRes = _T("0");
	bResetOpType = true; // 重置输入变量
	/*void ResetInput(ResetOption option);*/

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CkalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CkalculatorDlg::OnPaint()
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
HCURSOR CkalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




// Customized functions

void CkalculatorDlg::OnBnClickedButton0()
{
	NumInput(0);
	// TODO: 在此添加控件通知处理程序代码
}

void CkalculatorDlg::OnBnClickedButton1()
{
	NumInput(1);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedButton2()
{
	NumInput(2);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedButton3()
{
	NumInput(3);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedButton4()
{
	NumInput(4);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedButton5()
{
	NumInput(5);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedButton6()
{
	NumInput(6);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedButton7()
{
	NumInput(7);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedButton8()
{
	NumInput(8);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedButton9()
{
	NumInput(9);
	// TODO: 在此添加控件通知处理程序代码
}



void CkalculatorDlg::NumInput(int iNum)
{
	//void ResetInput(ResetOption option) {
	//	switch (RESET_OP_TYPE) {
	//	case RESET_ALL:
	//		// 重置所有变量
	//		m_csOpA.Empty();
	//		m_csOpB.Empty();
	//		m_iOpType = 0;
	//		break;
	//	case RESET_OP_TYPE:
	//		// 只重置操作类型
	//		//m_iOpType = 0;
	//		m_csRes = _T("0"); // 清空显示
	//		break;
	//		// 可以添加更多选项
	//	}
	//}
	if (bResetOpType)
	{
		bResetOpType = false;
		//m_iOpType = -1; // 在输入新的数字时重置运算符类型
		
		//m_csOpA.Empty(); // 在输入新的数字时重置第一个操作数
		//m_csOpRes = m_csOpA; 
		m_csRes = _T("0"); // 清空显示
	}
	else UpdateData(TRUE); // 从控件更新到变量
	
    
    CString str; // 临时变量
    str.Format(_T("%d"), iNum); // 格式化输入数字到字符串 iNum >> str
	
	if (m_csRes == _T("0"))
	{
		m_csRes = _T(""); // 如果当前显示为0，则清空
	}
    m_csRes = m_csRes + str; // 使用赋值运算符将两个字符串拼接在一起

	UpdateData(FALSE); // 从变量更新到控件
}

// 定义运算符类型
const int OpTypeSum = 0;
const int OpTypeSub = 1;
const int OpTypeMult = 2;
const int OpTypeDivi = 3;
//const int OpTypeEqu = 4;
//const int OpTypeNone = 5;


void CkalculatorDlg::OpInput(int iOp)
{
	//m_csOpA.Format(_T("%.2f"), m_dPreviousResult); // 使用上一次的结果作为第一个操作数
	m_iOpType = iOp; // 保存运算符类型
	m_csOpA = m_csRes; // 保存第一个操作数
	m_csRes = _T("0"); // 清空显示
	//m_csOpRes = m_csRes; // 将结果存储为第一个操作数，以便进行连续计算
	UpdateData(FALSE); // 从变量更新到控件
}


void CkalculatorDlg::OnBnClickedSum()
{
	 OpInput(OpTypeSum);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedSub()
{
	OpInput(OpTypeSub);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedMult()
{
	OpInput(OpTypeMult);
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedDivi()
{
	OpInput(OpTypeDivi);
	// TODO: 在此添加控件通知处理程序代码
}



void CkalculatorDlg::OnBnClickedEqu()
{
	//m_csRes = m_csOpRes;
	m_csOpB = m_csRes; // 保存第二个操作数 >> 拿到第二个操作数

	// 后续尝试使用 atoi 函数
	double numA = _tstof(m_csOpA);
	double numB = _tstof(m_csOpB);
	double result = 0;
	switch (m_iOpType) {
	case OpTypeSum:
		result = numA + numB;
		break;
	case OpTypeSub:
		result = numA - numB;
		break;
	case OpTypeMult:
		result = numA * numB;
		break;
	case OpTypeDivi:
		result = numA / numB;
		break;
	default:
		break;
	}
	//int iOpA = _ttoi(m_csOpA); // 字符串转换为整数 >> _ttoi函数被用于将字符串类型的操作数转换为整数类型
	//int iOpB = _ttoi(m_csOpB); // 字符串转换为整数 >> _ttoi函数被用于将字符串类型的操作数转换为整数类型
	//int iRes = 0; // 保存结果
	//switch (m_iOpType) // 根据运算符类型进行运算
	//{
	//	case OpTypeSum:
	//		iRes = iOpA + iOpB;
	//		break;
	//		case OpTypeSub:
	//			iRes = iOpA - iOpB;
	//			break;
	//			case OpTypeMult:
	//				iRes = iOpA * iOpB;
	//				break;
	//				case OpTypeDivi:
	//					iRes = iOpA / iOpB;
	//					break;
	//					default:
	//						break;
	//}
	//m_csRes.Format(_T("%d"), iRes); // 将结果转换为字符串
	m_csRes.Format(_T("%.2f"), result); // 将结果转换为字符串，保留两位小数
	//m_dPreviousResult.Format(_T("%.2f"), result); // 保存上一次的结果
	m_dPreviousResult = m_csRes; // 保存上一次的结果
	//m_csOpRes = m_csRes; // 将结果存储为第一个操作数，以便进行连续计算
	
	m_iOpType = -1; // 重置运算符类型
	UpdateData(FALSE); // 从变量更新到控件
	bResetOpType = true; // 重置运算符类型
	
	// TODO: 在此添加控件通知处理程序代码
}

void CkalculatorDlg::OnBnClickedEqutwo()
{
	m_csOpB = m_dPreviousResult;
	double iOpA = _ttoi(m_csOpA); // 字符串转换为整数 >> _ttoi函数被用于将字符串类型的操作数转换为整数类型
	double iOpB = _ttoi(m_csOpB); // 字符串转换为整数 >> _ttoi函数被用于将字符串类型的操作数转换为整数类型
	double iRes = 0; // 保存结果
	switch (m_iOpType) // 根据运算符类型进行运算
	{
		case OpTypeSum:
			iRes = iOpA + iOpB;
			break;
			case OpTypeSub:
				iRes = iOpA - iOpB;
				break;
				case OpTypeMult:
					iRes = iOpA * iOpB;
					break;
					case OpTypeDivi:
						iRes = iOpA / iOpB;
						break;
						default:
							break;
	}
	m_dPreviousResult.Format(_T("%.2f"), iRes); // 将结果转换为字符串
	//m_iOpType = -1; // 重置运算符类型
	UpdateData(FALSE); // 从变量更新到控件
	bResetOpType = true; // 重置运算符类型
	// TODO: 在此添加控件通知处理程序代码
}


void CkalculatorDlg::OnBnClickedDot()
{
	if (m_csRes.Find('.') == -1) { // 如果当前数字还没有小数点
		m_csRes += '.'; // 添加小数点
	}
	UpdateData(FALSE); // 从变量更新到控件

	// TODO: 在此添加控件通知处理程序代码
}




