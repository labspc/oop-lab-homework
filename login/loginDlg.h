
// loginDlg.h: 头文件
//

#pragma once


// CloginDlg 对话框
class CloginDlg : public CDialogEx
{
// 构造
public:
	CloginDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


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
	// member val CString pwd
//	CString m_csUsername;
// member val CString pwd
	CString m_csPwd;
	// member CString User
	CString m_csUser;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangePassword();
};
