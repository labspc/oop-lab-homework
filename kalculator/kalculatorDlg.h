
 // kalculatorDlg.h: 头文件


#pragma once




// CkalculatorDlg 对话框
class CkalculatorDlg : public CDialogEx
{
// 构造
public:
	CkalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// custom data
public:
	CString m_csOpA;
	CString m_csOpB; 
	//CString m_csOpRes;// 存储结果
	CString m_dPreviousResult; // 存储上一次的结果

	int m_iOpType; // 0: +, 1: -, 2: *, 3: /
	//void ResetInput(bool); // 重置输入变量
	//void ResetInput(bool bResetOpType = true); // 重置输入变量
	//void ResetInput(bool bResetOpType); // 重置输入变量
	bool bResetOpType; // 使用布尔值来决定是否重置某些变量 >> 重置输入变量

	//enum ResetOption {
	//	RESET_ALL,
	//	RESET_OP_TYPE,
	//	// 可以添加更多选项
	//};
	//void ResetInput(ResetOption option) {
	//	switch (option) {
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

public:
	void NumInput(int iNum); // 输入数字
	void OpInput(int iOp); // 输入运算符
	//void ResetInput(bool bResetOpType = true); // 重置输入变量




// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// output Result
	CString m_csRes;
//	afx_msg void OnBnClickedAbort();
	afx_msg void OnBnClickedButton0();
//	afx_msg void OnBnClickedAbort();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedSum();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMult();
	afx_msg void OnBnClickedDivi();
	afx_msg void OnBnClickedEqu();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedEqutwo();
};

