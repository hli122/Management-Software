#pragma once
#include "Database.h"
#include "PublicUserInfo.h"

/*
 * MemAddPage.h
 *
 * This file have basic Member Add page interaction actions.
 *
 * @author: Jiaying Hou
 * Revised: 4/4/20
 *          4/15/20 added PublicUserInfo
 *
 */

namespace WeAlumni {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MemAddPage
	/// </summary>
	public ref class MemAddPage : public System::Windows::Forms::Form
	{
	public:
		MemAddPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Initialize();
		}
		MemAddPage(PublicUserInfo^ pui) {
			InitializeComponent();
			_stfId = pui->GetId();
			Initialize();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MemAddPage()
		{
			if (components)
			{
				delete components;
			}
			if (database)
			{
				delete database;
			}
		}
	private: System::Windows::Forms::Label^ lbl_Prompt_添加成员;
	private: System::Windows::Forms::Label^ lbl_Prompt_成员编号;
	private: System::Windows::Forms::Label^ lbl_Prompt_成员状态;
	private: System::Windows::Forms::Label^ lbl_Prompt_成员类型;
	private: System::Windows::Forms::Label^ lbl_Prompt_出生日期;
	protected:





	private: System::Windows::Forms::Label^ lbl_Prompt_性别;

	private: System::Windows::Forms::Label^ lbl_Prompt_姓名;
	private: System::Windows::Forms::Label^ lbl_Prompt_地址第二行;


	private: System::Windows::Forms::Label^ lbl_Prompt_地址第一行;


	private: System::Windows::Forms::Label^ lbl_Prompt_所在国家;

	private: System::Windows::Forms::Label^ lbl_Prompt_微信号;

	private: System::Windows::Forms::Label^ lbl_Prompt_联系电话;

	private: System::Windows::Forms::Label^ lbl_Prompt_Email;
	private: System::Windows::Forms::Label^ lbl_Prompt_搜索授权;

	private: System::Windows::Forms::Label^ lbl_Prompt_就业状态;

	private: System::Windows::Forms::Label^ lbl_Prompt_学术项目;

	private: System::Windows::Forms::Label^ lbl_Prompt_学生编号;

	private: System::Windows::Forms::Label^ lbl_Prompt_邮编;

	private: System::Windows::Forms::Label^ lbl_Prompt_城市;

	private: System::Windows::Forms::Label^ lbl_成员编号;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ txt_姓名;

	private: System::Windows::Forms::TextBox^ txt_出生日期;

	private: System::Windows::Forms::TextBox^ txt_Email;
	private: System::Windows::Forms::TextBox^ txt_联系电话;
	private: System::Windows::Forms::TextBox^ txt_微信号;
	private: System::Windows::Forms::TextBox^ txt_所在国家;
	private: System::Windows::Forms::TextBox^ txt_地址第一行;
	private: System::Windows::Forms::TextBox^ txt_地址第二行;
	private: System::Windows::Forms::TextBox^ txt_城市;
	private: System::Windows::Forms::TextBox^ txt_邮编;
	private: System::Windows::Forms::TextBox^ txt_学生编号;
	private: System::Windows::Forms::Button^ btn_确认;
	private: System::Windows::Forms::Button^ btn_取消;










	private: System::Windows::Forms::Label^ lbl_error;
	private: System::Windows::Forms::Label^ lbl_Prompt_结束日期;

	private: System::Windows::Forms::Label^ lbl_Prompt_学位;
	private: System::Windows::Forms::Label^ lbl_Prompt_专业一;
	private: System::Windows::Forms::Label^ lbl_Prompt_专业二;
	private: System::Windows::Forms::Label^ lbl_Prompt_公司;
private: System::Windows::Forms::TextBox^ txt_结束日期;






private: System::Windows::Forms::TextBox^ txt_专业一;
private: System::Windows::Forms::TextBox^ txt_专业二;
private: System::Windows::Forms::TextBox^ txt_公司;
private: System::Windows::Forms::Label^ lbl_Prompt_职位;
private: System::Windows::Forms::TextBox^ txt_职位;






	private: System::Windows::Forms::ComboBox^ cmb_成员状态;
	private: System::Windows::Forms::ComboBox^ cmb_成员类型;
private: System::Windows::Forms::ComboBox^ cmb_学术项目;



	private: System::Windows::Forms::TextBox^ txt_性别;
private: System::Windows::Forms::ComboBox^ cmb_学位;
private: System::Windows::Forms::ComboBox^ cmb_就业状态;
private: System::Windows::Forms::ComboBox^ cmb_搜索授权;





	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lbl_Prompt_添加成员 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_成员编号 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_成员状态 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_成员类型 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_出生日期 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_性别 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_姓名 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_地址第二行 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_地址第一行 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_所在国家 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_微信号 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_联系电话 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_搜索授权 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_就业状态 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_学术项目 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_学生编号 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_邮编 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_城市 = (gcnew System::Windows::Forms::Label());
			this->lbl_成员编号 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->txt_姓名 = (gcnew System::Windows::Forms::TextBox());
			this->txt_出生日期 = (gcnew System::Windows::Forms::TextBox());
			this->txt_Email = (gcnew System::Windows::Forms::TextBox());
			this->txt_联系电话 = (gcnew System::Windows::Forms::TextBox());
			this->txt_微信号 = (gcnew System::Windows::Forms::TextBox());
			this->txt_所在国家 = (gcnew System::Windows::Forms::TextBox());
			this->txt_地址第一行 = (gcnew System::Windows::Forms::TextBox());
			this->txt_地址第二行 = (gcnew System::Windows::Forms::TextBox());
			this->txt_城市 = (gcnew System::Windows::Forms::TextBox());
			this->txt_邮编 = (gcnew System::Windows::Forms::TextBox());
			this->txt_学生编号 = (gcnew System::Windows::Forms::TextBox());
			this->btn_确认 = (gcnew System::Windows::Forms::Button());
			this->btn_取消 = (gcnew System::Windows::Forms::Button());
			this->lbl_error = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_结束日期 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_学位 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_专业一 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_专业二 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_公司 = (gcnew System::Windows::Forms::Label());
			this->txt_结束日期 = (gcnew System::Windows::Forms::TextBox());
			this->txt_专业一 = (gcnew System::Windows::Forms::TextBox());
			this->txt_专业二 = (gcnew System::Windows::Forms::TextBox());
			this->txt_公司 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_职位 = (gcnew System::Windows::Forms::Label());
			this->txt_职位 = (gcnew System::Windows::Forms::TextBox());
			this->cmb_成员状态 = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_成员类型 = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_学术项目 = (gcnew System::Windows::Forms::ComboBox());
			this->txt_性别 = (gcnew System::Windows::Forms::TextBox());
			this->cmb_学位 = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_就业状态 = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_搜索授权 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// lbl_Prompt_添加成员
			// 
			this->lbl_Prompt_添加成员->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_添加成员->AutoSize = true;
			this->lbl_Prompt_添加成员->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_添加成员->Location = System::Drawing::Point(290, 9);
			this->lbl_Prompt_添加成员->Name = L"lbl_Prompt_添加成员";
			this->lbl_Prompt_添加成员->Size = System::Drawing::Size(72, 18);
			this->lbl_Prompt_添加成员->TabIndex = 0;
			this->lbl_Prompt_添加成员->Text = L"添加成员";
			// 
			// lbl_Prompt_成员编号
			// 
			this->lbl_Prompt_成员编号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_成员编号->AutoSize = true;
			this->lbl_Prompt_成员编号->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_成员编号->Location = System::Drawing::Point(46, 62);
			this->lbl_Prompt_成员编号->Name = L"lbl_Prompt_成员编号";
			this->lbl_Prompt_成员编号->Size = System::Drawing::Size(66, 13);
			this->lbl_Prompt_成员编号->TabIndex = 1;
			this->lbl_Prompt_成员编号->Text = L"成员编号：";
			// 
			// lbl_Prompt_成员状态
			// 
			this->lbl_Prompt_成员状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_成员状态->AutoSize = true;
			this->lbl_Prompt_成员状态->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_成员状态->Location = System::Drawing::Point(286, 62);
			this->lbl_Prompt_成员状态->Name = L"lbl_Prompt_成员状态";
			this->lbl_Prompt_成员状态->Size = System::Drawing::Size(66, 13);
			this->lbl_Prompt_成员状态->TabIndex = 2;
			this->lbl_Prompt_成员状态->Text = L"成员状态：";
			// 
			// lbl_Prompt_成员类型
			// 
			this->lbl_Prompt_成员类型->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_成员类型->AutoSize = true;
			this->lbl_Prompt_成员类型->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_成员类型->Location = System::Drawing::Point(484, 62);
			this->lbl_Prompt_成员类型->Name = L"lbl_Prompt_成员类型";
			this->lbl_Prompt_成员类型->Size = System::Drawing::Size(63, 13);
			this->lbl_Prompt_成员类型->TabIndex = 3;
			this->lbl_Prompt_成员类型->Text = L"成员类型：";
			// 
			// lbl_Prompt_出生日期
			// 
			this->lbl_Prompt_出生日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_出生日期->AutoSize = true;
			this->lbl_Prompt_出生日期->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_出生日期->Location = System::Drawing::Point(46, 124);
			this->lbl_Prompt_出生日期->Name = L"lbl_Prompt_出生日期";
			this->lbl_Prompt_出生日期->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_出生日期->TabIndex = 6;
			this->lbl_Prompt_出生日期->Text = L"出生日期";
			// 
			// lbl_Prompt_性别
			// 
			this->lbl_Prompt_性别->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_性别->AutoSize = true;
			this->lbl_Prompt_性别->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_性别->Location = System::Drawing::Point(436, 98);
			this->lbl_Prompt_性别->Name = L"lbl_Prompt_性别";
			this->lbl_Prompt_性别->Size = System::Drawing::Size(30, 13);
			this->lbl_Prompt_性别->TabIndex = 5;
			this->lbl_Prompt_性别->Text = L"性别";
			// 
			// lbl_Prompt_姓名
			// 
			this->lbl_Prompt_姓名->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_姓名->AutoSize = true;
			this->lbl_Prompt_姓名->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_姓名->Location = System::Drawing::Point(70, 99);
			this->lbl_Prompt_姓名->Name = L"lbl_Prompt_姓名";
			this->lbl_Prompt_姓名->Size = System::Drawing::Size(33, 13);
			this->lbl_Prompt_姓名->TabIndex = 4;
			this->lbl_Prompt_姓名->Text = L"姓名";
			// 
			// lbl_Prompt_地址第二行
			// 
			this->lbl_Prompt_地址第二行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_地址第二行->AutoSize = true;
			this->lbl_Prompt_地址第二行->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_地址第二行->Location = System::Drawing::Point(30, 378);
			this->lbl_Prompt_地址第二行->Name = L"lbl_Prompt_地址第二行";
			this->lbl_Prompt_地址第二行->Size = System::Drawing::Size(72, 13);
			this->lbl_Prompt_地址第二行->TabIndex = 12;
			this->lbl_Prompt_地址第二行->Text = L"地址第二行";
			// 
			// lbl_Prompt_地址第一行
			// 
			this->lbl_Prompt_地址第一行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_地址第一行->AutoSize = true;
			this->lbl_Prompt_地址第一行->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_地址第一行->Location = System::Drawing::Point(30, 351);
			this->lbl_Prompt_地址第一行->Name = L"lbl_Prompt_地址第一行";
			this->lbl_Prompt_地址第一行->Size = System::Drawing::Size(72, 13);
			this->lbl_Prompt_地址第一行->TabIndex = 11;
			this->lbl_Prompt_地址第一行->Text = L"地址第一行";
			// 
			// lbl_Prompt_所在国家
			// 
			this->lbl_Prompt_所在国家->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_所在国家->AutoSize = true;
			this->lbl_Prompt_所在国家->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_所在国家->Location = System::Drawing::Point(43, 325);
			this->lbl_Prompt_所在国家->Name = L"lbl_Prompt_所在国家";
			this->lbl_Prompt_所在国家->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_所在国家->TabIndex = 10;
			this->lbl_Prompt_所在国家->Text = L"所在国家";
			// 
			// lbl_Prompt_微信号
			// 
			this->lbl_Prompt_微信号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_微信号->AutoSize = true;
			this->lbl_Prompt_微信号->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_微信号->Location = System::Drawing::Point(420, 150);
			this->lbl_Prompt_微信号->Name = L"lbl_Prompt_微信号";
			this->lbl_Prompt_微信号->Size = System::Drawing::Size(46, 13);
			this->lbl_Prompt_微信号->TabIndex = 9;
			this->lbl_Prompt_微信号->Text = L"微信号";
			// 
			// lbl_Prompt_联系电话
			// 
			this->lbl_Prompt_联系电话->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_联系电话->AutoSize = true;
			this->lbl_Prompt_联系电话->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_联系电话->Location = System::Drawing::Point(46, 150);
			this->lbl_Prompt_联系电话->Name = L"lbl_Prompt_联系电话";
			this->lbl_Prompt_联系电话->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_联系电话->TabIndex = 8;
			this->lbl_Prompt_联系电话->Text = L"联系电话";
			// 
			// lbl_Prompt_Email
			// 
			this->lbl_Prompt_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Email->AutoSize = true;
			this->lbl_Prompt_Email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Email->Location = System::Drawing::Point(427, 124);
			this->lbl_Prompt_Email->Name = L"lbl_Prompt_Email";
			this->lbl_Prompt_Email->Size = System::Drawing::Size(37, 13);
			this->lbl_Prompt_Email->TabIndex = 7;
			this->lbl_Prompt_Email->Text = L"Email";
			// 
			// lbl_Prompt_搜索授权
			// 
			this->lbl_Prompt_搜索授权->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_搜索授权->AutoSize = true;
			this->lbl_Prompt_搜索授权->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_搜索授权->Location = System::Drawing::Point(49, 12);
			this->lbl_Prompt_搜索授权->Name = L"lbl_Prompt_搜索授权";
			this->lbl_Prompt_搜索授权->Size = System::Drawing::Size(56, 13);
			this->lbl_Prompt_搜索授权->TabIndex = 18;
			this->lbl_Prompt_搜索授权->Text = L"搜索授权";
			// 
			// lbl_Prompt_就业状态
			// 
			this->lbl_Prompt_就业状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_就业状态->AutoSize = true;
			this->lbl_Prompt_就业状态->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_就业状态->Location = System::Drawing::Point(43, 433);
			this->lbl_Prompt_就业状态->Name = L"lbl_Prompt_就业状态";
			this->lbl_Prompt_就业状态->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_就业状态->TabIndex = 17;
			this->lbl_Prompt_就业状态->Text = L"就业状态";
			// 
			// lbl_Prompt_学术项目
			// 
			this->lbl_Prompt_学术项目->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_学术项目->AutoSize = true;
			this->lbl_Prompt_学术项目->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_学术项目->Location = System::Drawing::Point(46, 224);
			this->lbl_Prompt_学术项目->Name = L"lbl_Prompt_学术项目";
			this->lbl_Prompt_学术项目->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_学术项目->TabIndex = 16;
			this->lbl_Prompt_学术项目->Text = L"学术项目";
			// 
			// lbl_Prompt_学生编号
			// 
			this->lbl_Prompt_学生编号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_学生编号->AutoSize = true;
			this->lbl_Prompt_学生编号->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_学生编号->Location = System::Drawing::Point(46, 204);
			this->lbl_Prompt_学生编号->Name = L"lbl_Prompt_学生编号";
			this->lbl_Prompt_学生编号->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_学生编号->TabIndex = 15;
			this->lbl_Prompt_学生编号->Text = L"学生编号";
			// 
			// lbl_Prompt_邮编
			// 
			this->lbl_Prompt_邮编->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_邮编->AutoSize = true;
			this->lbl_Prompt_邮编->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_邮编->Location = System::Drawing::Point(507, 325);
			this->lbl_Prompt_邮编->Name = L"lbl_Prompt_邮编";
			this->lbl_Prompt_邮编->Size = System::Drawing::Size(33, 13);
			this->lbl_Prompt_邮编->TabIndex = 14;
			this->lbl_Prompt_邮编->Text = L"邮编";
			// 
			// lbl_Prompt_城市
			// 
			this->lbl_Prompt_城市->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_城市->AutoSize = true;
			this->lbl_Prompt_城市->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_城市->Location = System::Drawing::Point(308, 325);
			this->lbl_Prompt_城市->Name = L"lbl_Prompt_城市";
			this->lbl_Prompt_城市->Size = System::Drawing::Size(33, 13);
			this->lbl_Prompt_城市->TabIndex = 13;
			this->lbl_Prompt_城市->Text = L"城市";
			// 
			// lbl_成员编号
			// 
			this->lbl_成员编号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_成员编号->AutoSize = true;
			this->lbl_成员编号->Location = System::Drawing::Point(115, 59);
			this->lbl_成员编号->Name = L"lbl_成员编号";
			this->lbl_成员编号->Size = System::Drawing::Size(10, 13);
			this->lbl_成员编号->TabIndex = 19;
			this->lbl_成员编号->Text = L"-";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// txt_姓名
			// 
			this->txt_姓名->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_姓名->Location = System::Drawing::Point(108, 95);
			this->txt_姓名->Name = L"txt_姓名";
			this->txt_姓名->Size = System::Drawing::Size(148, 20);
			this->txt_姓名->TabIndex = 23;
			// 
			// txt_出生日期
			// 
			this->txt_出生日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_出生日期->Location = System::Drawing::Point(108, 121);
			this->txt_出生日期->Name = L"txt_出生日期";
			this->txt_出生日期->Size = System::Drawing::Size(148, 20);
			this->txt_出生日期->TabIndex = 27;
			// 
			// txt_Email
			// 
			this->txt_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Email->Location = System::Drawing::Point(472, 121);
			this->txt_Email->Name = L"txt_Email";
			this->txt_Email->Size = System::Drawing::Size(144, 20);
			this->txt_Email->TabIndex = 26;
			// 
			// txt_联系电话
			// 
			this->txt_联系电话->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_联系电话->Location = System::Drawing::Point(108, 147);
			this->txt_联系电话->Name = L"txt_联系电话";
			this->txt_联系电话->Size = System::Drawing::Size(148, 20);
			this->txt_联系电话->TabIndex = 25;
			// 
			// txt_微信号
			// 
			this->txt_微信号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_微信号->Location = System::Drawing::Point(472, 147);
			this->txt_微信号->Name = L"txt_微信号";
			this->txt_微信号->Size = System::Drawing::Size(144, 20);
			this->txt_微信号->TabIndex = 30;
			// 
			// txt_所在国家
			// 
			this->txt_所在国家->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_所在国家->Location = System::Drawing::Point(108, 322);
			this->txt_所在国家->Name = L"txt_所在国家";
			this->txt_所在国家->Size = System::Drawing::Size(148, 20);
			this->txt_所在国家->TabIndex = 29;
			// 
			// txt_地址第一行
			// 
			this->txt_地址第一行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_地址第一行->Location = System::Drawing::Point(108, 348);
			this->txt_地址第一行->Name = L"txt_地址第一行";
			this->txt_地址第一行->Size = System::Drawing::Size(508, 20);
			this->txt_地址第一行->TabIndex = 28;
			// 
			// txt_地址第二行
			// 
			this->txt_地址第二行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_地址第二行->Location = System::Drawing::Point(108, 375);
			this->txt_地址第二行->Name = L"txt_地址第二行";
			this->txt_地址第二行->Size = System::Drawing::Size(508, 20);
			this->txt_地址第二行->TabIndex = 33;
			// 
			// txt_城市
			// 
			this->txt_城市->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_城市->Location = System::Drawing::Point(347, 322);
			this->txt_城市->Name = L"txt_城市";
			this->txt_城市->Size = System::Drawing::Size(119, 20);
			this->txt_城市->TabIndex = 32;
			// 
			// txt_邮编
			// 
			this->txt_邮编->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_邮编->Location = System::Drawing::Point(546, 322);
			this->txt_邮编->Name = L"txt_邮编";
			this->txt_邮编->Size = System::Drawing::Size(70, 20);
			this->txt_邮编->TabIndex = 31;
			// 
			// txt_学生编号
			// 
			this->txt_学生编号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_学生编号->Location = System::Drawing::Point(108, 197);
			this->txt_学生编号->Name = L"txt_学生编号";
			this->txt_学生编号->Size = System::Drawing::Size(148, 20);
			this->txt_学生编号->TabIndex = 36;
			// 
			// btn_确认
			// 
			this->btn_确认->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_确认->Location = System::Drawing::Point(510, 504);
			this->btn_确认->Name = L"btn_确认";
			this->btn_确认->Size = System::Drawing::Size(61, 20);
			this->btn_确认->TabIndex = 40;
			this->btn_确认->Text = L"确认";
			this->btn_确认->UseVisualStyleBackColor = true;
			this->btn_确认->Click += gcnew System::EventHandler(this, &MemAddPage::btn_accept_Click);
			// 
			// btn_取消
			// 
			this->btn_取消->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_取消->Location = System::Drawing::Point(587, 504);
			this->btn_取消->Name = L"btn_取消";
			this->btn_取消->Size = System::Drawing::Size(61, 20);
			this->btn_取消->TabIndex = 41;
			this->btn_取消->Text = L"取消";
			this->btn_取消->UseVisualStyleBackColor = true;
			this->btn_取消->Click += gcnew System::EventHandler(this, &MemAddPage::btn_Cancel_Click);
			// 
			// lbl_error
			// 
			this->lbl_error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_error->AutoSize = true;
			this->lbl_error->ForeColor = System::Drawing::Color::Red;
			this->lbl_error->Location = System::Drawing::Point(21, 513);
			this->lbl_error->Name = L"lbl_error";
			this->lbl_error->Size = System::Drawing::Size(44, 13);
			this->lbl_error->TabIndex = 44;
			this->lbl_error->Text = L"warning";
			this->lbl_error->Visible = false;
			// 
			// lbl_Prompt_结束日期
			// 
			this->lbl_Prompt_结束日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_结束日期->AutoSize = true;
			this->lbl_Prompt_结束日期->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_结束日期->Location = System::Drawing::Point(407, 224);
			this->lbl_Prompt_结束日期->Name = L"lbl_Prompt_结束日期";
			this->lbl_Prompt_结束日期->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_结束日期->TabIndex = 45;
			this->lbl_Prompt_结束日期->Text = L"结束日期";
			// 
			// lbl_Prompt_学位
			// 
			this->lbl_Prompt_学位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_学位->AutoSize = true;
			this->lbl_Prompt_学位->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_学位->Location = System::Drawing::Point(433, 197);
			this->lbl_Prompt_学位->Name = L"lbl_Prompt_学位";
			this->lbl_Prompt_学位->Size = System::Drawing::Size(33, 13);
			this->lbl_Prompt_学位->TabIndex = 46;
			this->lbl_Prompt_学位->Text = L"学位";
			// 
			// lbl_Prompt_专业一
			// 
			this->lbl_Prompt_专业一->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_专业一->AutoSize = true;
			this->lbl_Prompt_专业一->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_专业一->Location = System::Drawing::Point(56, 251);
			this->lbl_Prompt_专业一->Name = L"lbl_Prompt_专业一";
			this->lbl_Prompt_专业一->Size = System::Drawing::Size(46, 13);
			this->lbl_Prompt_专业一->TabIndex = 47;
			this->lbl_Prompt_专业一->Text = L"专业一";
			// 
			// lbl_Prompt_专业二
			// 
			this->lbl_Prompt_专业二->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_专业二->AutoSize = true;
			this->lbl_Prompt_专业二->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_专业二->Location = System::Drawing::Point(56, 277);
			this->lbl_Prompt_专业二->Name = L"lbl_Prompt_专业二";
			this->lbl_Prompt_专业二->Size = System::Drawing::Size(46, 13);
			this->lbl_Prompt_专业二->TabIndex = 48;
			this->lbl_Prompt_专业二->Text = L"专业二";
			// 
			// lbl_Prompt_公司
			// 
			this->lbl_Prompt_公司->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_公司->AutoSize = true;
			this->lbl_Prompt_公司->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_公司->Location = System::Drawing::Point(433, 433);
			this->lbl_Prompt_公司->Name = L"lbl_Prompt_公司";
			this->lbl_Prompt_公司->Size = System::Drawing::Size(33, 13);
			this->lbl_Prompt_公司->TabIndex = 49;
			this->lbl_Prompt_公司->Text = L"公司";
			// 
			// txt_结束日期
			// 
			this->txt_结束日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_结束日期->Location = System::Drawing::Point(472, 221);
			this->txt_结束日期->Name = L"txt_结束日期";
			this->txt_结束日期->Size = System::Drawing::Size(144, 20);
			this->txt_结束日期->TabIndex = 50;
			// 
			// txt_专业一
			// 
			this->txt_专业一->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_专业一->Location = System::Drawing::Point(108, 248);
			this->txt_专业一->Name = L"txt_专业一";
			this->txt_专业一->Size = System::Drawing::Size(508, 20);
			this->txt_专业一->TabIndex = 52;
			// 
			// txt_专业二
			// 
			this->txt_专业二->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_专业二->Location = System::Drawing::Point(108, 274);
			this->txt_专业二->Name = L"txt_专业二";
			this->txt_专业二->Size = System::Drawing::Size(508, 20);
			this->txt_专业二->TabIndex = 53;
			// 
			// txt_公司
			// 
			this->txt_公司->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_公司->Location = System::Drawing::Point(472, 430);
			this->txt_公司->Name = L"txt_公司";
			this->txt_公司->Size = System::Drawing::Size(144, 20);
			this->txt_公司->TabIndex = 54;
			// 
			// lbl_Prompt_职位
			// 
			this->lbl_Prompt_职位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_职位->AutoSize = true;
			this->lbl_Prompt_职位->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_职位->Location = System::Drawing::Point(69, 459);
			this->lbl_Prompt_职位->Name = L"lbl_Prompt_职位";
			this->lbl_Prompt_职位->Size = System::Drawing::Size(33, 13);
			this->lbl_Prompt_职位->TabIndex = 55;
			this->lbl_Prompt_职位->Text = L"职位";
			// 
			// txt_职位
			// 
			this->txt_职位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_职位->Location = System::Drawing::Point(108, 456);
			this->txt_职位->Name = L"txt_职位";
			this->txt_职位->Size = System::Drawing::Size(148, 20);
			this->txt_职位->TabIndex = 56;
			// 
			// cmb_成员状态
			// 
			this->cmb_成员状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_成员状态->FormattingEnabled = true;
			this->cmb_成员状态->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"Review", L"Invalid" });
			this->cmb_成员状态->Location = System::Drawing::Point(347, 59);
			this->cmb_成员状态->Name = L"cmb_成员状态";
			this->cmb_成员状态->Size = System::Drawing::Size(119, 21);
			this->cmb_成员状态->TabIndex = 57;
			// 
			// cmb_成员类型
			// 
			this->cmb_成员类型->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_成员类型->FormattingEnabled = true;
			this->cmb_成员类型->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Normal", L"DivHead", L"Staff", L"Head" });
			this->cmb_成员类型->Location = System::Drawing::Point(546, 59);
			this->cmb_成员类型->Name = L"cmb_成员类型";
			this->cmb_成员类型->Size = System::Drawing::Size(70, 21);
			this->cmb_成员类型->TabIndex = 58;
			// 
			// cmb_学术项目
			// 
			this->cmb_学术项目->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_学术项目->FormattingEnabled = true;
			this->cmb_学术项目->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"UnderGrad", L"Grad", L"TransOus", L"Exchange",
					L"VisitingScholar"
			});
			this->cmb_学术项目->Location = System::Drawing::Point(108, 221);
			this->cmb_学术项目->Name = L"cmb_学术项目";
			this->cmb_学术项目->Size = System::Drawing::Size(148, 21);
			this->cmb_学术项目->TabIndex = 59;
			// 
			// txt_性别
			// 
			this->txt_性别->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_性别->Location = System::Drawing::Point(472, 95);
			this->txt_性别->Name = L"txt_性别";
			this->txt_性别->Size = System::Drawing::Size(144, 20);
			this->txt_性别->TabIndex = 22;
			// 
			// cmb_学位
			// 
			this->cmb_学位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_学位->FormattingEnabled = true;
			this->cmb_学位->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Bachelor", L"Master", L"PhD", L"Post-PhD" });
			this->cmb_学位->Location = System::Drawing::Point(472, 194);
			this->cmb_学位->Name = L"cmb_学位";
			this->cmb_学位->Size = System::Drawing::Size(144, 21);
			this->cmb_学位->TabIndex = 60;
			// 
			// cmb_就业状态
			// 
			this->cmb_就业状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_就业状态->FormattingEnabled = true;
			this->cmb_就业状态->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"GradProgram", L"Unemployed", L"Employed", L"StartBusiness" });
			this->cmb_就业状态->Location = System::Drawing::Point(108, 430);
			this->cmb_就业状态->Name = L"cmb_就业状态";
			this->cmb_就业状态->Size = System::Drawing::Size(148, 21);
			this->cmb_就业状态->TabIndex = 61;
			// 
			// cmb_搜索授权
			// 
			this->cmb_搜索授权->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_搜索授权->FormattingEnabled = true;
			this->cmb_搜索授权->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Yes", L"No" });
			this->cmb_搜索授权->Location = System::Drawing::Point(108, 6);
			this->cmb_搜索授权->Name = L"cmb_搜索授权";
			this->cmb_搜索授权->Size = System::Drawing::Size(148, 21);
			this->cmb_搜索授权->TabIndex = 62;
			// 
			// MemAddPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 536);
			this->Controls->Add(this->cmb_搜索授权);
			this->Controls->Add(this->cmb_就业状态);
			this->Controls->Add(this->cmb_学位);
			this->Controls->Add(this->cmb_学术项目);
			this->Controls->Add(this->cmb_成员类型);
			this->Controls->Add(this->cmb_成员状态);
			this->Controls->Add(this->txt_职位);
			this->Controls->Add(this->lbl_Prompt_职位);
			this->Controls->Add(this->txt_公司);
			this->Controls->Add(this->txt_专业二);
			this->Controls->Add(this->txt_专业一);
			this->Controls->Add(this->txt_结束日期);
			this->Controls->Add(this->lbl_Prompt_公司);
			this->Controls->Add(this->lbl_Prompt_专业二);
			this->Controls->Add(this->lbl_Prompt_专业一);
			this->Controls->Add(this->lbl_Prompt_学位);
			this->Controls->Add(this->lbl_Prompt_结束日期);
			this->Controls->Add(this->lbl_error);
			this->Controls->Add(this->btn_取消);
			this->Controls->Add(this->btn_确认);
			this->Controls->Add(this->txt_学生编号);
			this->Controls->Add(this->txt_地址第二行);
			this->Controls->Add(this->txt_城市);
			this->Controls->Add(this->txt_邮编);
			this->Controls->Add(this->txt_微信号);
			this->Controls->Add(this->txt_所在国家);
			this->Controls->Add(this->txt_地址第一行);
			this->Controls->Add(this->txt_出生日期);
			this->Controls->Add(this->txt_Email);
			this->Controls->Add(this->txt_联系电话);
			this->Controls->Add(this->txt_姓名);
			this->Controls->Add(this->txt_性别);
			this->Controls->Add(this->lbl_成员编号);
			this->Controls->Add(this->lbl_Prompt_搜索授权);
			this->Controls->Add(this->lbl_Prompt_就业状态);
			this->Controls->Add(this->lbl_Prompt_学术项目);
			this->Controls->Add(this->lbl_Prompt_学生编号);
			this->Controls->Add(this->lbl_Prompt_邮编);
			this->Controls->Add(this->lbl_Prompt_城市);
			this->Controls->Add(this->lbl_Prompt_地址第二行);
			this->Controls->Add(this->lbl_Prompt_地址第一行);
			this->Controls->Add(this->lbl_Prompt_所在国家);
			this->Controls->Add(this->lbl_Prompt_微信号);
			this->Controls->Add(this->lbl_Prompt_联系电话);
			this->Controls->Add(this->lbl_Prompt_Email);
			this->Controls->Add(this->lbl_Prompt_出生日期);
			this->Controls->Add(this->lbl_Prompt_性别);
			this->Controls->Add(this->lbl_Prompt_姓名);
			this->Controls->Add(this->lbl_Prompt_成员类型);
			this->Controls->Add(this->lbl_Prompt_成员状态);
			this->Controls->Add(this->lbl_Prompt_成员编号);
			this->Controls->Add(this->lbl_Prompt_添加成员);
			this->Name = L"MemAddPage";
			this->Text = L"添加成员";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		int _id;
		int _stfId;
		Database^ database;
	
	private: 
		Void Initialize();
		Void UpdateInfo();
		int insertRecord();
		Void btn_accept_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
