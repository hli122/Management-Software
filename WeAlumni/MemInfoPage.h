#pragma once
#include "Database.h"
#include "RecInfoPage.h"
#include "PublicUserInfo.h"
#include "StartPage2.h"

/*
 * MemInfoPage.h
 *
 * This file have basic Member Information page interaction actions.
 *
 * @author: Jiaying Hou
 * Revised: 4/1/20
 *          4/4/20 UI and bug fixes
 *          4/12/20 auth control added
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
	/// Summary for MemInfoPage
	/// </summary>
	public ref class MemInfoPage : public System::Windows::Forms::Form
	{
	public:
		MemInfoPage(int inputMemId)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_id = inputMemId;
			_auth = PublicUserInfo::Auth::Level_1;
			Initialize();
		}

		MemInfoPage(int inputMemId, PublicUserInfo^ pui) {
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_id = inputMemId;
			_auth = pui->GetAuth();
			_stfId = pui->GetId();
			Initialize();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MemInfoPage()
		{
			if (components)
			{
				delete components;
			}
			if (database) {
				database->~Database();
			}
		}
	private: System::Windows::Forms::Label^ lbl_Prompt_成员信息;
	private: System::Windows::Forms::Label^ lbl_Prompt_成员编号;
	private: System::Windows::Forms::Label^ lbl_Prompt_成员状态;
	private: System::Windows::Forms::Label^ lbl_Prompt_成员类型;
	private: System::Windows::Forms::Label^ lbl_Prompt_姓名;
	private: System::Windows::Forms::TextBox^ txt_姓名;
	private: System::Windows::Forms::Label^ lbl_Prompt_性别;
	private: System::Windows::Forms::TextBox^ txt_性别;
	private: System::Windows::Forms::Label^ lbl_Prompt_出生日期;
	private: System::Windows::Forms::TextBox^ txt_出生日期;
	private: System::Windows::Forms::Label^ lbl_Prompt_Email;
	private: System::Windows::Forms::TextBox^ txt_Email;
	private: System::Windows::Forms::Label^ lbl_Prompt_联系电话;
	private: System::Windows::Forms::TextBox^ txt_联系电话;
	private: System::Windows::Forms::Label^ lbl_Prompt_微信号;
	private: System::Windows::Forms::TextBox^ txt_微信号;
	private: System::Windows::Forms::Label^ lbl_Prompt_所在国家;
	private: System::Windows::Forms::TextBox^ txt_所在国家;
	private: System::Windows::Forms::Label^ lbl_Prompt_城市;
	private: System::Windows::Forms::TextBox^ txt_城市;
	private: System::Windows::Forms::Label^ lbl_Prompt_邮编;
	private: System::Windows::Forms::TextBox^ txt_邮编;
	private: System::Windows::Forms::Label^ lbl_Prompt_地址第一行;
	private: System::Windows::Forms::TextBox^ txt_地址第一行;
	private: System::Windows::Forms::Label^ lbl_Prompt_地址第二行;
	private: System::Windows::Forms::TextBox^ txt_地址第二行;
	private: System::Windows::Forms::Label^ lbl_Prompt_学生编号;
	private: System::Windows::Forms::TextBox^ txt_学生编号;
	private: System::Windows::Forms::Label^ lbl_Prompt_学术项目;
	private: System::Windows::Forms::Label^ lbl_Prompt_结束日期;
	private: System::Windows::Forms::TextBox^ txt_结束日期;
	private: System::Windows::Forms::Label^ lbl_Prompt_学位;
	private: System::Windows::Forms::Label^ lbl_Prompt_专业一;
	private: System::Windows::Forms::TextBox^ txt_专业一;
	private: System::Windows::Forms::Label^ lbl_Prompt_专业二;
	private: System::Windows::Forms::TextBox^ txt_专业二;
	private: System::Windows::Forms::Label^ lbl_Prompt_就业状态;
	private: System::Windows::Forms::Label^ lbl_Prompt_公司;
	private: System::Windows::Forms::TextBox^ txt_公司;
private: System::Windows::Forms::Label^ lbl_Prompt_职位;
private: System::Windows::Forms::TextBox^ txt_职位;
private: System::Windows::Forms::Label^ lbl_Prompt_搜索授权;
private: System::Windows::Forms::Button^ btn_编辑信息;
	private: System::Windows::Forms::Label^ lbl_成员编号;
	private: System::Windows::Forms::Label^ lbl_成员状态;
	private: System::Windows::Forms::Label^ lbl_成员类型;
	private: System::Windows::Forms::Label^ lbl_姓名;
	private: System::Windows::Forms::Label^ lbl_性别;
	private: System::Windows::Forms::Label^ lbl_出生日期;






	private: System::Windows::Forms::Label^ lbl_Email;
private: System::Windows::Forms::Label^ lbl_联系电话;
private: System::Windows::Forms::Label^ lbl_微信号;
private: System::Windows::Forms::Label^ lbl_学生编号;
private: System::Windows::Forms::Label^ lbl_所在国家;
private: System::Windows::Forms::Label^ lbl_城市;
private: System::Windows::Forms::Label^ lbl_邮编;
private: System::Windows::Forms::Label^ lbl_地址第一行;
private: System::Windows::Forms::Label^ lbl_地址第二行;
private: System::Windows::Forms::Label^ lbl_学术项目;

private: System::Windows::Forms::Label^ lbl_结束日期;
private: System::Windows::Forms::Label^ lbl_学位;
private: System::Windows::Forms::Label^ lbl_专业一;
private: System::Windows::Forms::Label^ lbl_专业二;
private: System::Windows::Forms::Label^ lbl_就业状态;
private: System::Windows::Forms::Label^ lbl_公司;
private: System::Windows::Forms::Label^ lbl_职位;
private: System::Windows::Forms::Label^ lbl_搜索授权;
private: System::Windows::Forms::Button^ btn_删除信息;




















	private: System::Windows::Forms::Label^ lbl_error;
private: System::Windows::Forms::Button^ btn_确认删除;

private: System::Windows::Forms::Button^ btn_取消删除;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::Windows::Forms::Button^ btn_确认编辑;
private: System::Windows::Forms::Button^ btn_取消编辑;


	private: System::Windows::Forms::Splitter^ splitter1;

private: System::Windows::Forms::ComboBox^ cmb_成员类型;
private: System::Windows::Forms::ComboBox^ cmb_学位;
private: System::Windows::Forms::ComboBox^ cmb_学术项目;



private: System::Windows::Forms::ComboBox^ cmb_就业状态;
private: System::Windows::Forms::ComboBox^ cmb_搜索授权;



private: System::Windows::Forms::ComboBox^ cmb_成员状态;
private: System::Windows::Forms::Label^ lbl_Prompt_操作记录;
private: System::Windows::Forms::Splitter^ splitter3;
private: System::Windows::Forms::Splitter^ splitter2;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_Prompt_成员信息 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_成员编号 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_成员状态 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_成员类型 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_姓名 = (gcnew System::Windows::Forms::Label());
			this->txt_姓名 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_性别 = (gcnew System::Windows::Forms::Label());
			this->txt_性别 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_出生日期 = (gcnew System::Windows::Forms::Label());
			this->txt_出生日期 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Email = (gcnew System::Windows::Forms::Label());
			this->txt_Email = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_联系电话 = (gcnew System::Windows::Forms::Label());
			this->txt_联系电话 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_微信号 = (gcnew System::Windows::Forms::Label());
			this->txt_微信号 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_所在国家 = (gcnew System::Windows::Forms::Label());
			this->txt_所在国家 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_城市 = (gcnew System::Windows::Forms::Label());
			this->txt_城市 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_邮编 = (gcnew System::Windows::Forms::Label());
			this->txt_邮编 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_地址第一行 = (gcnew System::Windows::Forms::Label());
			this->txt_地址第一行 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_地址第二行 = (gcnew System::Windows::Forms::Label());
			this->txt_地址第二行 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_学生编号 = (gcnew System::Windows::Forms::Label());
			this->txt_学生编号 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_学术项目 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_结束日期 = (gcnew System::Windows::Forms::Label());
			this->txt_结束日期 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_学位 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_专业一 = (gcnew System::Windows::Forms::Label());
			this->txt_专业一 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_专业二 = (gcnew System::Windows::Forms::Label());
			this->txt_专业二 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_就业状态 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_公司 = (gcnew System::Windows::Forms::Label());
			this->txt_公司 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_职位 = (gcnew System::Windows::Forms::Label());
			this->txt_职位 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_搜索授权 = (gcnew System::Windows::Forms::Label());
			this->btn_编辑信息 = (gcnew System::Windows::Forms::Button());
			this->lbl_成员编号 = (gcnew System::Windows::Forms::Label());
			this->lbl_成员状态 = (gcnew System::Windows::Forms::Label());
			this->lbl_成员类型 = (gcnew System::Windows::Forms::Label());
			this->lbl_姓名 = (gcnew System::Windows::Forms::Label());
			this->lbl_性别 = (gcnew System::Windows::Forms::Label());
			this->lbl_出生日期 = (gcnew System::Windows::Forms::Label());
			this->lbl_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_联系电话 = (gcnew System::Windows::Forms::Label());
			this->lbl_微信号 = (gcnew System::Windows::Forms::Label());
			this->lbl_学生编号 = (gcnew System::Windows::Forms::Label());
			this->lbl_所在国家 = (gcnew System::Windows::Forms::Label());
			this->lbl_城市 = (gcnew System::Windows::Forms::Label());
			this->lbl_邮编 = (gcnew System::Windows::Forms::Label());
			this->lbl_地址第一行 = (gcnew System::Windows::Forms::Label());
			this->lbl_地址第二行 = (gcnew System::Windows::Forms::Label());
			this->lbl_学术项目 = (gcnew System::Windows::Forms::Label());
			this->lbl_结束日期 = (gcnew System::Windows::Forms::Label());
			this->lbl_学位 = (gcnew System::Windows::Forms::Label());
			this->lbl_专业一 = (gcnew System::Windows::Forms::Label());
			this->lbl_专业二 = (gcnew System::Windows::Forms::Label());
			this->lbl_就业状态 = (gcnew System::Windows::Forms::Label());
			this->lbl_公司 = (gcnew System::Windows::Forms::Label());
			this->lbl_职位 = (gcnew System::Windows::Forms::Label());
			this->lbl_搜索授权 = (gcnew System::Windows::Forms::Label());
			this->btn_删除信息 = (gcnew System::Windows::Forms::Button());
			this->lbl_error = (gcnew System::Windows::Forms::Label());
			this->btn_确认删除 = (gcnew System::Windows::Forms::Button());
			this->btn_取消删除 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->btn_确认编辑 = (gcnew System::Windows::Forms::Button());
			this->btn_取消编辑 = (gcnew System::Windows::Forms::Button());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->cmb_成员类型 = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_学位 = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_学术项目 = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_就业状态 = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_搜索授权 = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_成员状态 = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_Prompt_操作记录 = (gcnew System::Windows::Forms::Label());
			this->splitter3 = (gcnew System::Windows::Forms::Splitter());
			this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_Prompt_成员信息
			// 
			this->lbl_Prompt_成员信息->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_成员信息->AutoSize = true;
			this->lbl_Prompt_成员信息->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_成员信息->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_成员信息->Location = System::Drawing::Point(393, 13);
			this->lbl_Prompt_成员信息->Name = L"lbl_Prompt_成员信息";
			this->lbl_Prompt_成员信息->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_成员信息->TabIndex = 0;
			this->lbl_Prompt_成员信息->Text = L"成员信息";
			// 
			// lbl_Prompt_成员编号
			// 
			this->lbl_Prompt_成员编号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_成员编号->AutoSize = true;
			this->lbl_Prompt_成员编号->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_成员编号->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_成员编号->Location = System::Drawing::Point(48, 51);
			this->lbl_Prompt_成员编号->Name = L"lbl_Prompt_成员编号";
			this->lbl_Prompt_成员编号->Size = System::Drawing::Size(81, 18);
			this->lbl_Prompt_成员编号->TabIndex = 1;
			this->lbl_Prompt_成员编号->Text = L"成员编号：";
			// 
			// lbl_Prompt_成员状态
			// 
			this->lbl_Prompt_成员状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_成员状态->AutoSize = true;
			this->lbl_Prompt_成员状态->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_成员状态->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_成员状态->Location = System::Drawing::Point(318, 51);
			this->lbl_Prompt_成员状态->Name = L"lbl_Prompt_成员状态";
			this->lbl_Prompt_成员状态->Size = System::Drawing::Size(81, 18);
			this->lbl_Prompt_成员状态->TabIndex = 2;
			this->lbl_Prompt_成员状态->Text = L"成员状态：";
			// 
			// lbl_Prompt_成员类型
			// 
			this->lbl_Prompt_成员类型->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_成员类型->AutoSize = true;
			this->lbl_Prompt_成员类型->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_成员类型->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_成员类型->Location = System::Drawing::Point(581, 51);
			this->lbl_Prompt_成员类型->Name = L"lbl_Prompt_成员类型";
			this->lbl_Prompt_成员类型->Size = System::Drawing::Size(77, 18);
			this->lbl_Prompt_成员类型->TabIndex = 5;
			this->lbl_Prompt_成员类型->Text = L"成员类型：";
			// 
			// lbl_Prompt_姓名
			// 
			this->lbl_Prompt_姓名->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_姓名->AutoSize = true;
			this->lbl_Prompt_姓名->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_姓名->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_姓名->Location = System::Drawing::Point(75, 89);
			this->lbl_Prompt_姓名->Name = L"lbl_Prompt_姓名";
			this->lbl_Prompt_姓名->Size = System::Drawing::Size(40, 16);
			this->lbl_Prompt_姓名->TabIndex = 6;
			this->lbl_Prompt_姓名->Text = L"姓名";
			// 
			// txt_姓名
			// 
			this->txt_姓名->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_姓名->Location = System::Drawing::Point(121, 84);
			this->txt_姓名->Name = L"txt_姓名";
			this->txt_姓名->Size = System::Drawing::Size(200, 20);
			this->txt_姓名->TabIndex = 4;
			this->txt_姓名->Visible = false;
			// 
			// lbl_Prompt_性别
			// 
			this->lbl_Prompt_性别->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_性别->AutoSize = true;
			this->lbl_Prompt_性别->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_性别->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_性别->Location = System::Drawing::Point(511, 88);
			this->lbl_Prompt_性别->Name = L"lbl_Prompt_性别";
			this->lbl_Prompt_性别->Size = System::Drawing::Size(36, 16);
			this->lbl_Prompt_性别->TabIndex = 7;
			this->lbl_Prompt_性别->Text = L"性别";
			// 
			// txt_性别
			// 
			this->txt_性别->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_性别->Location = System::Drawing::Point(547, 85);
			this->txt_性别->Name = L"txt_性别";
			this->txt_性别->Size = System::Drawing::Size(209, 20);
			this->txt_性别->TabIndex = 4;
			this->txt_性别->Visible = false;
			// 
			// lbl_Prompt_出生日期
			// 
			this->lbl_Prompt_出生日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_出生日期->AutoSize = true;
			this->lbl_Prompt_出生日期->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_出生日期->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_出生日期->Location = System::Drawing::Point(56, 112);
			this->lbl_Prompt_出生日期->Name = L"lbl_Prompt_出生日期";
			this->lbl_Prompt_出生日期->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_出生日期->TabIndex = 8;
			this->lbl_Prompt_出生日期->Text = L"出生日期";
			// 
			// txt_出生日期
			// 
			this->txt_出生日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_出生日期->Location = System::Drawing::Point(121, 109);
			this->txt_出生日期->Name = L"txt_出生日期";
			this->txt_出生日期->Size = System::Drawing::Size(200, 20);
			this->txt_出生日期->TabIndex = 4;
			this->txt_出生日期->Visible = false;
			// 
			// lbl_Prompt_Email
			// 
			this->lbl_Prompt_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Email->AutoSize = true;
			this->lbl_Prompt_Email->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Email->Location = System::Drawing::Point(500, 112);
			this->lbl_Prompt_Email->Name = L"lbl_Prompt_Email";
			this->lbl_Prompt_Email->Size = System::Drawing::Size(47, 16);
			this->lbl_Prompt_Email->TabIndex = 9;
			this->lbl_Prompt_Email->Text = L"Email";
			// 
			// txt_Email
			// 
			this->txt_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Email->Location = System::Drawing::Point(547, 109);
			this->txt_Email->Name = L"txt_Email";
			this->txt_Email->Size = System::Drawing::Size(209, 20);
			this->txt_Email->TabIndex = 4;
			this->txt_Email->Visible = false;
			// 
			// lbl_Prompt_联系电话
			// 
			this->lbl_Prompt_联系电话->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_联系电话->AutoSize = true;
			this->lbl_Prompt_联系电话->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_联系电话->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_联系电话->Location = System::Drawing::Point(46, 138);
			this->lbl_Prompt_联系电话->Name = L"lbl_Prompt_联系电话";
			this->lbl_Prompt_联系电话->Size = System::Drawing::Size(72, 16);
			this->lbl_Prompt_联系电话->TabIndex = 10;
			this->lbl_Prompt_联系电话->Text = L"联系电话";
			// 
			// txt_联系电话
			// 
			this->txt_联系电话->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_联系电话->Location = System::Drawing::Point(121, 134);
			this->txt_联系电话->Name = L"txt_联系电话";
			this->txt_联系电话->Size = System::Drawing::Size(200, 20);
			this->txt_联系电话->TabIndex = 4;
			this->txt_联系电话->Visible = false;
			// 
			// lbl_Prompt_微信号
			// 
			this->lbl_Prompt_微信号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_微信号->AutoSize = true;
			this->lbl_Prompt_微信号->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_微信号->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_微信号->Location = System::Drawing::Point(495, 138);
			this->lbl_Prompt_微信号->Name = L"lbl_Prompt_微信号";
			this->lbl_Prompt_微信号->Size = System::Drawing::Size(56, 16);
			this->lbl_Prompt_微信号->TabIndex = 11;
			this->lbl_Prompt_微信号->Text = L"微信号";
			// 
			// txt_微信号
			// 
			this->txt_微信号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_微信号->Location = System::Drawing::Point(547, 135);
			this->txt_微信号->Name = L"txt_微信号";
			this->txt_微信号->Size = System::Drawing::Size(209, 20);
			this->txt_微信号->TabIndex = 4;
			this->txt_微信号->Visible = false;
			// 
			// lbl_Prompt_所在国家
			// 
			this->lbl_Prompt_所在国家->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_所在国家->AutoSize = true;
			this->lbl_Prompt_所在国家->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_所在国家->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_所在国家->Location = System::Drawing::Point(46, 300);
			this->lbl_Prompt_所在国家->Name = L"lbl_Prompt_所在国家";
			this->lbl_Prompt_所在国家->Size = System::Drawing::Size(72, 16);
			this->lbl_Prompt_所在国家->TabIndex = 12;
			this->lbl_Prompt_所在国家->Text = L"所在国家";
			// 
			// txt_所在国家
			// 
			this->txt_所在国家->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_所在国家->Location = System::Drawing::Point(121, 299);
			this->txt_所在国家->Name = L"txt_所在国家";
			this->txt_所在国家->Size = System::Drawing::Size(204, 20);
			this->txt_所在国家->TabIndex = 4;
			this->txt_所在国家->Visible = false;
			// 
			// lbl_Prompt_城市
			// 
			this->lbl_Prompt_城市->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_城市->AutoSize = true;
			this->lbl_Prompt_城市->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_城市->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_城市->Location = System::Drawing::Point(354, 302);
			this->lbl_Prompt_城市->Name = L"lbl_Prompt_城市";
			this->lbl_Prompt_城市->Size = System::Drawing::Size(40, 16);
			this->lbl_Prompt_城市->TabIndex = 17;
			this->lbl_Prompt_城市->Text = L"城市";
			// 
			// txt_城市
			// 
			this->txt_城市->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_城市->Location = System::Drawing::Point(390, 299);
			this->txt_城市->Name = L"txt_城市";
			this->txt_城市->Size = System::Drawing::Size(204, 20);
			this->txt_城市->TabIndex = 4;
			this->txt_城市->Visible = false;
			// 
			// lbl_Prompt_邮编
			// 
			this->lbl_Prompt_邮编->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_邮编->AutoSize = true;
			this->lbl_Prompt_邮编->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_邮编->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_邮编->Location = System::Drawing::Point(611, 302);
			this->lbl_Prompt_邮编->Name = L"lbl_Prompt_邮编";
			this->lbl_Prompt_邮编->Size = System::Drawing::Size(40, 16);
			this->lbl_Prompt_邮编->TabIndex = 16;
			this->lbl_Prompt_邮编->Text = L"邮编";
			// 
			// txt_邮编
			// 
			this->txt_邮编->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_邮编->Location = System::Drawing::Point(650, 299);
			this->txt_邮编->Name = L"txt_邮编";
			this->txt_邮编->Size = System::Drawing::Size(106, 20);
			this->txt_邮编->TabIndex = 4;
			this->txt_邮编->Visible = false;
			// 
			// lbl_Prompt_地址第一行
			// 
			this->lbl_Prompt_地址第一行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_地址第一行->AutoSize = true;
			this->lbl_Prompt_地址第一行->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_地址第一行->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_地址第一行->Location = System::Drawing::Point(30, 324);
			this->lbl_Prompt_地址第一行->Name = L"lbl_Prompt_地址第一行";
			this->lbl_Prompt_地址第一行->Size = System::Drawing::Size(88, 16);
			this->lbl_Prompt_地址第一行->TabIndex = 15;
			this->lbl_Prompt_地址第一行->Text = L"地址第一行";
			// 
			// txt_地址第一行
			// 
			this->txt_地址第一行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_地址第一行->Location = System::Drawing::Point(121, 324);
			this->txt_地址第一行->Name = L"txt_地址第一行";
			this->txt_地址第一行->Size = System::Drawing::Size(636, 20);
			this->txt_地址第一行->TabIndex = 4;
			this->txt_地址第一行->Visible = false;
			// 
			// lbl_Prompt_地址第二行
			// 
			this->lbl_Prompt_地址第二行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_地址第二行->AutoSize = true;
			this->lbl_Prompt_地址第二行->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_地址第二行->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_地址第二行->Location = System::Drawing::Point(30, 354);
			this->lbl_Prompt_地址第二行->Name = L"lbl_Prompt_地址第二行";
			this->lbl_Prompt_地址第二行->Size = System::Drawing::Size(88, 16);
			this->lbl_Prompt_地址第二行->TabIndex = 14;
			this->lbl_Prompt_地址第二行->Text = L"地址第二行";
			// 
			// txt_地址第二行
			// 
			this->txt_地址第二行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_地址第二行->Location = System::Drawing::Point(121, 351);
			this->txt_地址第二行->Name = L"txt_地址第二行";
			this->txt_地址第二行->Size = System::Drawing::Size(636, 20);
			this->txt_地址第二行->TabIndex = 4;
			this->txt_地址第二行->Visible = false;
			// 
			// lbl_Prompt_学生编号
			// 
			this->lbl_Prompt_学生编号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_学生编号->AutoSize = true;
			this->lbl_Prompt_学生编号->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_学生编号->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_学生编号->Location = System::Drawing::Point(46, 178);
			this->lbl_Prompt_学生编号->Name = L"lbl_Prompt_学生编号";
			this->lbl_Prompt_学生编号->Size = System::Drawing::Size(72, 16);
			this->lbl_Prompt_学生编号->TabIndex = 13;
			this->lbl_Prompt_学生编号->Text = L"学生编号";
			// 
			// txt_学生编号
			// 
			this->txt_学生编号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_学生编号->Location = System::Drawing::Point(121, 176);
			this->txt_学生编号->Name = L"txt_学生编号";
			this->txt_学生编号->Size = System::Drawing::Size(200, 20);
			this->txt_学生编号->TabIndex = 4;
			this->txt_学生编号->Visible = false;
			// 
			// lbl_Prompt_学术项目
			// 
			this->lbl_Prompt_学术项目->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_学术项目->AutoSize = true;
			this->lbl_Prompt_学术项目->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_学术项目->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_学术项目->Location = System::Drawing::Point(46, 204);
			this->lbl_Prompt_学术项目->Name = L"lbl_Prompt_学术项目";
			this->lbl_Prompt_学术项目->Size = System::Drawing::Size(72, 16);
			this->lbl_Prompt_学术项目->TabIndex = 22;
			this->lbl_Prompt_学术项目->Text = L"学术项目";
			// 
			// lbl_Prompt_结束日期
			// 
			this->lbl_Prompt_结束日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_结束日期->AutoSize = true;
			this->lbl_Prompt_结束日期->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_结束日期->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_结束日期->Location = System::Drawing::Point(476, 205);
			this->lbl_Prompt_结束日期->Name = L"lbl_Prompt_结束日期";
			this->lbl_Prompt_结束日期->Size = System::Drawing::Size(72, 16);
			this->lbl_Prompt_结束日期->TabIndex = 21;
			this->lbl_Prompt_结束日期->Text = L"结束日期";
			// 
			// txt_结束日期
			// 
			this->txt_结束日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_结束日期->Location = System::Drawing::Point(547, 203);
			this->txt_结束日期->Name = L"txt_结束日期";
			this->txt_结束日期->Size = System::Drawing::Size(209, 20);
			this->txt_结束日期->TabIndex = 4;
			this->txt_结束日期->Visible = false;
			// 
			// lbl_Prompt_学位
			// 
			this->lbl_Prompt_学位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_学位->AutoSize = true;
			this->lbl_Prompt_学位->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_学位->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_学位->Location = System::Drawing::Point(508, 177);
			this->lbl_Prompt_学位->Name = L"lbl_Prompt_学位";
			this->lbl_Prompt_学位->Size = System::Drawing::Size(40, 16);
			this->lbl_Prompt_学位->TabIndex = 20;
			this->lbl_Prompt_学位->Text = L"学位";
			// 
			// lbl_Prompt_专业一
			// 
			this->lbl_Prompt_专业一->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_专业一->AutoSize = true;
			this->lbl_Prompt_专业一->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_专业一->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_专业一->Location = System::Drawing::Point(59, 233);
			this->lbl_Prompt_专业一->Name = L"lbl_Prompt_专业一";
			this->lbl_Prompt_专业一->Size = System::Drawing::Size(56, 16);
			this->lbl_Prompt_专业一->TabIndex = 19;
			this->lbl_Prompt_专业一->Text = L"专业一";
			// 
			// txt_专业一
			// 
			this->txt_专业一->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_专业一->Location = System::Drawing::Point(121, 229);
			this->txt_专业一->Name = L"txt_专业一";
			this->txt_专业一->Size = System::Drawing::Size(636, 20);
			this->txt_专业一->TabIndex = 4;
			this->txt_专业一->Visible = false;
			// 
			// lbl_Prompt_专业二
			// 
			this->lbl_Prompt_专业二->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_专业二->AutoSize = true;
			this->lbl_Prompt_专业二->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_专业二->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_专业二->Location = System::Drawing::Point(59, 255);
			this->lbl_Prompt_专业二->Name = L"lbl_Prompt_专业二";
			this->lbl_Prompt_专业二->Size = System::Drawing::Size(56, 16);
			this->lbl_Prompt_专业二->TabIndex = 18;
			this->lbl_Prompt_专业二->Text = L"专业二";
			// 
			// txt_专业二
			// 
			this->txt_专业二->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_专业二->Location = System::Drawing::Point(121, 254);
			this->txt_专业二->Name = L"txt_专业二";
			this->txt_专业二->Size = System::Drawing::Size(636, 20);
			this->txt_专业二->TabIndex = 4;
			this->txt_专业二->Visible = false;
			// 
			// lbl_Prompt_就业状态
			// 
			this->lbl_Prompt_就业状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_就业状态->AutoSize = true;
			this->lbl_Prompt_就业状态->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_就业状态->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_就业状态->Location = System::Drawing::Point(46, 403);
			this->lbl_Prompt_就业状态->Name = L"lbl_Prompt_就业状态";
			this->lbl_Prompt_就业状态->Size = System::Drawing::Size(72, 16);
			this->lbl_Prompt_就业状态->TabIndex = 26;
			this->lbl_Prompt_就业状态->Text = L"就业状态";
			// 
			// lbl_Prompt_公司
			// 
			this->lbl_Prompt_公司->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_公司->AutoSize = true;
			this->lbl_Prompt_公司->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_公司->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_公司->Location = System::Drawing::Point(512, 400);
			this->lbl_Prompt_公司->Name = L"lbl_Prompt_公司";
			this->lbl_Prompt_公司->Size = System::Drawing::Size(40, 16);
			this->lbl_Prompt_公司->TabIndex = 25;
			this->lbl_Prompt_公司->Text = L"公司";
			// 
			// txt_公司
			// 
			this->txt_公司->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_公司->Location = System::Drawing::Point(556, 399);
			this->txt_公司->Name = L"txt_公司";
			this->txt_公司->Size = System::Drawing::Size(200, 20);
			this->txt_公司->TabIndex = 4;
			this->txt_公司->Visible = false;
			// 
			// lbl_Prompt_职位
			// 
			this->lbl_Prompt_职位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_职位->AutoSize = true;
			this->lbl_Prompt_职位->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_职位->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_职位->Location = System::Drawing::Point(75, 427);
			this->lbl_Prompt_职位->Name = L"lbl_Prompt_职位";
			this->lbl_Prompt_职位->Size = System::Drawing::Size(40, 16);
			this->lbl_Prompt_职位->TabIndex = 24;
			this->lbl_Prompt_职位->Text = L"职位";
			// 
			// txt_职位
			// 
			this->txt_职位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_职位->Location = System::Drawing::Point(121, 425);
			this->txt_职位->Name = L"txt_职位";
			this->txt_职位->Size = System::Drawing::Size(204, 20);
			this->txt_职位->TabIndex = 4;
			this->txt_职位->Visible = false;
			// 
			// lbl_Prompt_搜索授权
			// 
			this->lbl_Prompt_搜索授权->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_搜索授权->AutoSize = true;
			this->lbl_Prompt_搜索授权->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_搜索授权->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_搜索授权->Location = System::Drawing::Point(59, 15);
			this->lbl_Prompt_搜索授权->Name = L"lbl_Prompt_搜索授权";
			this->lbl_Prompt_搜索授权->Size = System::Drawing::Size(56, 13);
			this->lbl_Prompt_搜索授权->TabIndex = 23;
			this->lbl_Prompt_搜索授权->Text = L"搜索授权";
			// 
			// btn_编辑信息
			// 
			this->btn_编辑信息->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_编辑信息->Location = System::Drawing::Point(580, 459);
			this->btn_编辑信息->Name = L"btn_编辑信息";
			this->btn_编辑信息->Size = System::Drawing::Size(75, 22);
			this->btn_编辑信息->TabIndex = 27;
			this->btn_编辑信息->Text = L"编辑信息";
			this->btn_编辑信息->UseVisualStyleBackColor = true;
			this->btn_编辑信息->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_ChangeInfo_Click);
			// 
			// lbl_成员编号
			// 
			this->lbl_成员编号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_成员编号->AutoSize = true;
			this->lbl_成员编号->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_成员编号->Location = System::Drawing::Point(135, 51);
			this->lbl_成员编号->Name = L"lbl_成员编号";
			this->lbl_成员编号->Size = System::Drawing::Size(10, 13);
			this->lbl_成员编号->TabIndex = 29;
			this->lbl_成员编号->Text = L"-";
			// 
			// lbl_成员状态
			// 
			this->lbl_成员状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_成员状态->AutoSize = true;
			this->lbl_成员状态->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_成员状态->Location = System::Drawing::Point(393, 51);
			this->lbl_成员状态->Name = L"lbl_成员状态";
			this->lbl_成员状态->Size = System::Drawing::Size(10, 13);
			this->lbl_成员状态->TabIndex = 30;
			this->lbl_成员状态->Text = L"-";
			// 
			// lbl_成员类型
			// 
			this->lbl_成员类型->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_成员类型->AutoSize = true;
			this->lbl_成员类型->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_成员类型->Location = System::Drawing::Point(656, 51);
			this->lbl_成员类型->Name = L"lbl_成员类型";
			this->lbl_成员类型->Size = System::Drawing::Size(10, 13);
			this->lbl_成员类型->TabIndex = 32;
			this->lbl_成员类型->Text = L"-";
			// 
			// lbl_姓名
			// 
			this->lbl_姓名->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_姓名->AutoSize = true;
			this->lbl_姓名->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_姓名->Location = System::Drawing::Point(118, 86);
			this->lbl_姓名->Name = L"lbl_姓名";
			this->lbl_姓名->Size = System::Drawing::Size(10, 13);
			this->lbl_姓名->TabIndex = 31;
			this->lbl_姓名->Text = L"-";
			// 
			// lbl_性别
			// 
			this->lbl_性别->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_性别->AutoSize = true;
			this->lbl_性别->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_性别->Location = System::Drawing::Point(558, 86);
			this->lbl_性别->Name = L"lbl_性别";
			this->lbl_性别->Size = System::Drawing::Size(10, 13);
			this->lbl_性别->TabIndex = 34;
			this->lbl_性别->Text = L"-";
			// 
			// lbl_出生日期
			// 
			this->lbl_出生日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_出生日期->AutoSize = true;
			this->lbl_出生日期->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_出生日期->Location = System::Drawing::Point(118, 114);
			this->lbl_出生日期->Name = L"lbl_出生日期";
			this->lbl_出生日期->Size = System::Drawing::Size(10, 13);
			this->lbl_出生日期->TabIndex = 33;
			this->lbl_出生日期->Text = L"-";
			// 
			// lbl_Email
			// 
			this->lbl_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Email->AutoSize = true;
			this->lbl_Email->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Email->Location = System::Drawing::Point(558, 114);
			this->lbl_Email->Name = L"lbl_Email";
			this->lbl_Email->Size = System::Drawing::Size(10, 13);
			this->lbl_Email->TabIndex = 36;
			this->lbl_Email->Text = L"-";
			// 
			// lbl_联系电话
			// 
			this->lbl_联系电话->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_联系电话->AutoSize = true;
			this->lbl_联系电话->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_联系电话->Location = System::Drawing::Point(118, 138);
			this->lbl_联系电话->Name = L"lbl_联系电话";
			this->lbl_联系电话->Size = System::Drawing::Size(10, 13);
			this->lbl_联系电话->TabIndex = 35;
			this->lbl_联系电话->Text = L"-";
			// 
			// lbl_微信号
			// 
			this->lbl_微信号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_微信号->AutoSize = true;
			this->lbl_微信号->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_微信号->Location = System::Drawing::Point(558, 138);
			this->lbl_微信号->Name = L"lbl_微信号";
			this->lbl_微信号->Size = System::Drawing::Size(10, 13);
			this->lbl_微信号->TabIndex = 37;
			this->lbl_微信号->Text = L"-";
			// 
			// lbl_学生编号
			// 
			this->lbl_学生编号->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_学生编号->AutoSize = true;
			this->lbl_学生编号->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_学生编号->Location = System::Drawing::Point(118, 178);
			this->lbl_学生编号->Name = L"lbl_学生编号";
			this->lbl_学生编号->Size = System::Drawing::Size(10, 13);
			this->lbl_学生编号->TabIndex = 39;
			this->lbl_学生编号->Text = L"-";
			// 
			// lbl_所在国家
			// 
			this->lbl_所在国家->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_所在国家->AutoSize = true;
			this->lbl_所在国家->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_所在国家->Location = System::Drawing::Point(118, 302);
			this->lbl_所在国家->Name = L"lbl_所在国家";
			this->lbl_所在国家->Size = System::Drawing::Size(10, 13);
			this->lbl_所在国家->TabIndex = 38;
			this->lbl_所在国家->Text = L"-";
			// 
			// lbl_城市
			// 
			this->lbl_城市->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_城市->AutoSize = true;
			this->lbl_城市->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_城市->Location = System::Drawing::Point(393, 302);
			this->lbl_城市->Name = L"lbl_城市";
			this->lbl_城市->Size = System::Drawing::Size(10, 13);
			this->lbl_城市->TabIndex = 42;
			this->lbl_城市->Text = L"-";
			// 
			// lbl_邮编
			// 
			this->lbl_邮编->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_邮编->AutoSize = true;
			this->lbl_邮编->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_邮编->Location = System::Drawing::Point(656, 302);
			this->lbl_邮编->Name = L"lbl_邮编";
			this->lbl_邮编->Size = System::Drawing::Size(10, 13);
			this->lbl_邮编->TabIndex = 41;
			this->lbl_邮编->Text = L"-";
			// 
			// lbl_地址第一行
			// 
			this->lbl_地址第一行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_地址第一行->AutoSize = true;
			this->lbl_地址第一行->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_地址第一行->Location = System::Drawing::Point(118, 328);
			this->lbl_地址第一行->Name = L"lbl_地址第一行";
			this->lbl_地址第一行->Size = System::Drawing::Size(10, 13);
			this->lbl_地址第一行->TabIndex = 40;
			this->lbl_地址第一行->Text = L"-";
			// 
			// lbl_地址第二行
			// 
			this->lbl_地址第二行->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_地址第二行->AutoSize = true;
			this->lbl_地址第二行->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_地址第二行->Location = System::Drawing::Point(118, 354);
			this->lbl_地址第二行->Name = L"lbl_地址第二行";
			this->lbl_地址第二行->Size = System::Drawing::Size(10, 13);
			this->lbl_地址第二行->TabIndex = 43;
			this->lbl_地址第二行->Text = L"-";
			// 
			// lbl_学术项目
			// 
			this->lbl_学术项目->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_学术项目->AutoSize = true;
			this->lbl_学术项目->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_学术项目->Location = System::Drawing::Point(118, 204);
			this->lbl_学术项目->Name = L"lbl_学术项目";
			this->lbl_学术项目->Size = System::Drawing::Size(10, 13);
			this->lbl_学术项目->TabIndex = 44;
			this->lbl_学术项目->Text = L"-";
			// 
			// lbl_结束日期
			// 
			this->lbl_结束日期->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_结束日期->AutoSize = true;
			this->lbl_结束日期->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_结束日期->Location = System::Drawing::Point(558, 205);
			this->lbl_结束日期->Name = L"lbl_结束日期";
			this->lbl_结束日期->Size = System::Drawing::Size(10, 13);
			this->lbl_结束日期->TabIndex = 46;
			this->lbl_结束日期->Text = L"-";
			// 
			// lbl_学位
			// 
			this->lbl_学位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_学位->AutoSize = true;
			this->lbl_学位->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_学位->Location = System::Drawing::Point(558, 178);
			this->lbl_学位->Name = L"lbl_学位";
			this->lbl_学位->Size = System::Drawing::Size(10, 13);
			this->lbl_学位->TabIndex = 45;
			this->lbl_学位->Text = L"-";
			// 
			// lbl_专业一
			// 
			this->lbl_专业一->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_专业一->AutoSize = true;
			this->lbl_专业一->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_专业一->Location = System::Drawing::Point(118, 231);
			this->lbl_专业一->Name = L"lbl_专业一";
			this->lbl_专业一->Size = System::Drawing::Size(10, 13);
			this->lbl_专业一->TabIndex = 48;
			this->lbl_专业一->Text = L"-";
			// 
			// lbl_专业二
			// 
			this->lbl_专业二->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_专业二->AutoSize = true;
			this->lbl_专业二->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_专业二->Location = System::Drawing::Point(118, 257);
			this->lbl_专业二->Name = L"lbl_专业二";
			this->lbl_专业二->Size = System::Drawing::Size(10, 13);
			this->lbl_专业二->TabIndex = 47;
			this->lbl_专业二->Text = L"-";
			// 
			// lbl_就业状态
			// 
			this->lbl_就业状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_就业状态->AutoSize = true;
			this->lbl_就业状态->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_就业状态->Location = System::Drawing::Point(118, 400);
			this->lbl_就业状态->Name = L"lbl_就业状态";
			this->lbl_就业状态->Size = System::Drawing::Size(10, 13);
			this->lbl_就业状态->TabIndex = 49;
			this->lbl_就业状态->Text = L"-";
			// 
			// lbl_公司
			// 
			this->lbl_公司->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_公司->AutoSize = true;
			this->lbl_公司->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_公司->Location = System::Drawing::Point(558, 400);
			this->lbl_公司->Name = L"lbl_公司";
			this->lbl_公司->Size = System::Drawing::Size(10, 13);
			this->lbl_公司->TabIndex = 50;
			this->lbl_公司->Text = L"-";
			// 
			// lbl_职位
			// 
			this->lbl_职位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_职位->AutoSize = true;
			this->lbl_职位->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_职位->Location = System::Drawing::Point(118, 427);
			this->lbl_职位->Name = L"lbl_职位";
			this->lbl_职位->Size = System::Drawing::Size(10, 13);
			this->lbl_职位->TabIndex = 51;
			this->lbl_职位->Text = L"-";
			// 
			// lbl_搜索授权
			// 
			this->lbl_搜索授权->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_搜索授权->AutoSize = true;
			this->lbl_搜索授权->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_搜索授权->Location = System::Drawing::Point(119, 15);
			this->lbl_搜索授权->Name = L"lbl_搜索授权";
			this->lbl_搜索授权->Size = System::Drawing::Size(10, 13);
			this->lbl_搜索授权->TabIndex = 52;
			this->lbl_搜索授权->Text = L"-";
			// 
			// btn_删除信息
			// 
			this->btn_删除信息->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_删除信息->Location = System::Drawing::Point(682, 458);
			this->btn_删除信息->Name = L"btn_删除信息";
			this->btn_删除信息->Size = System::Drawing::Size(75, 22);
			this->btn_删除信息->TabIndex = 53;
			this->btn_删除信息->Text = L"删除信息";
			this->btn_删除信息->UseVisualStyleBackColor = true;
			this->btn_删除信息->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_Delete_Click);
			// 
			// lbl_error
			// 
			this->lbl_error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_error->AutoSize = true;
			this->lbl_error->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_error->ForeColor = System::Drawing::Color::Red;
			this->lbl_error->Location = System::Drawing::Point(52, 464);
			this->lbl_error->Name = L"lbl_error";
			this->lbl_error->Size = System::Drawing::Size(47, 13);
			this->lbl_error->TabIndex = 54;
			this->lbl_error->Text = L"Warning";
			this->lbl_error->Visible = false;
			// 
			// btn_确认删除
			// 
			this->btn_确认删除->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_确认删除->Location = System::Drawing::Point(580, 459);
			this->btn_确认删除->Name = L"btn_确认删除";
			this->btn_确认删除->Size = System::Drawing::Size(75, 23);
			this->btn_确认删除->TabIndex = 59;
			this->btn_确认删除->Text = L"确认";
			this->btn_确认删除->UseVisualStyleBackColor = true;
			this->btn_确认删除->Visible = false;
			this->btn_确认删除->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_DeleteAccept_Click);
			// 
			// btn_取消删除
			// 
			this->btn_取消删除->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_取消删除->Location = System::Drawing::Point(682, 457);
			this->btn_取消删除->Name = L"btn_取消删除";
			this->btn_取消删除->Size = System::Drawing::Size(75, 23);
			this->btn_取消删除->TabIndex = 60;
			this->btn_取消删除->Text = L"取消";
			this->btn_取消删除->UseVisualStyleBackColor = true;
			this->btn_取消删除->Visible = false;
			this->btn_取消删除->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_DeleteCancel_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->dataGridView1->Location = System::Drawing::Point(0, 534);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(839, 236);
			this->dataGridView1->TabIndex = 61;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MemInfoPage::dataGridView1_CellDoubleClick);
			// 
			// btn_确认编辑
			// 
			this->btn_确认编辑->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_确认编辑->Location = System::Drawing::Point(580, 459);
			this->btn_确认编辑->Name = L"btn_确认编辑";
			this->btn_确认编辑->Size = System::Drawing::Size(75, 23);
			this->btn_确认编辑->TabIndex = 62;
			this->btn_确认编辑->Text = L"确认";
			this->btn_确认编辑->UseVisualStyleBackColor = true;
			this->btn_确认编辑->Visible = false;
			this->btn_确认编辑->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_ChangeInfoAccept_Click);
			// 
			// btn_取消编辑
			// 
			this->btn_取消编辑->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_取消编辑->Location = System::Drawing::Point(682, 457);
			this->btn_取消编辑->Name = L"btn_取消编辑";
			this->btn_取消编辑->Size = System::Drawing::Size(75, 23);
			this->btn_取消编辑->TabIndex = 63;
			this->btn_取消编辑->Text = L"取消";
			this->btn_取消编辑->UseVisualStyleBackColor = true;
			this->btn_取消编辑->Visible = false;
			this->btn_取消编辑->Click += gcnew System::EventHandler(this, &MemInfoPage::btn_ChangeInfoCancel_Click);
			// 
			// splitter1
			// 
			this->splitter1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->splitter1->Cursor = System::Windows::Forms::Cursors::HSplit;
			this->splitter1->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter1->Enabled = false;
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(839, 488);
			this->splitter1->TabIndex = 64;
			this->splitter1->TabStop = false;
			// 
			// cmb_成员类型
			// 
			this->cmb_成员类型->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_成员类型->FormattingEnabled = true;
			this->cmb_成员类型->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Normal", L"DivHead", L"Staff", L"Head" });
			this->cmb_成员类型->Location = System::Drawing::Point(659, 48);
			this->cmb_成员类型->Name = L"cmb_成员类型";
			this->cmb_成员类型->Size = System::Drawing::Size(97, 21);
			this->cmb_成员类型->TabIndex = 67;
			this->cmb_成员类型->Visible = false;
			// 
			// cmb_学位
			// 
			this->cmb_学位->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_学位->FormattingEnabled = true;
			this->cmb_学位->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Bachelor", L"Master", L"PhD", L"Post-PhD" });
			this->cmb_学位->Location = System::Drawing::Point(547, 174);
			this->cmb_学位->Name = L"cmb_学位";
			this->cmb_学位->Size = System::Drawing::Size(210, 21);
			this->cmb_学位->TabIndex = 68;
			this->cmb_学位->Visible = false;
			// 
			// cmb_学术项目
			// 
			this->cmb_学术项目->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_学术项目->FormattingEnabled = true;
			this->cmb_学术项目->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"UnderGrad", L"Grad", L"TransOus", L"Exchange",
					L"VisitingScholar"
			});
			this->cmb_学术项目->Location = System::Drawing::Point(121, 203);
			this->cmb_学术项目->Name = L"cmb_学术项目";
			this->cmb_学术项目->Size = System::Drawing::Size(200, 21);
			this->cmb_学术项目->TabIndex = 69;
			this->cmb_学术项目->Visible = false;
			// 
			// cmb_就业状态
			// 
			this->cmb_就业状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_就业状态->FormattingEnabled = true;
			this->cmb_就业状态->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"GradProgram", L"Unemployed", L"Employed", L"StartBusiness" });
			this->cmb_就业状态->Location = System::Drawing::Point(121, 398);
			this->cmb_就业状态->Name = L"cmb_就业状态";
			this->cmb_就业状态->Size = System::Drawing::Size(204, 21);
			this->cmb_就业状态->TabIndex = 70;
			this->cmb_就业状态->Visible = false;
			// 
			// cmb_搜索授权
			// 
			this->cmb_搜索授权->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_搜索授权->FormattingEnabled = true;
			this->cmb_搜索授权->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Yes", L"No" });
			this->cmb_搜索授权->Location = System::Drawing::Point(121, 12);
			this->cmb_搜索授权->Name = L"cmb_搜索授权";
			this->cmb_搜索授权->Size = System::Drawing::Size(97, 21);
			this->cmb_搜索授权->TabIndex = 71;
			this->cmb_搜索授权->Visible = false;
			// 
			// cmb_成员状态
			// 
			this->cmb_成员状态->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_成员状态->FormattingEnabled = true;
			this->cmb_成员状态->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"Review", L"Invalid" });
			this->cmb_成员状态->Location = System::Drawing::Point(396, 48);
			this->cmb_成员状态->Name = L"cmb_成员状态";
			this->cmb_成员状态->Size = System::Drawing::Size(97, 21);
			this->cmb_成员状态->TabIndex = 72;
			this->cmb_成员状态->Visible = false;
			// 
			// lbl_Prompt_操作记录
			// 
			this->lbl_Prompt_操作记录->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_操作记录->AutoSize = true;
			this->lbl_Prompt_操作记录->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_操作记录->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_操作记录->Location = System::Drawing::Point(393, 506);
			this->lbl_Prompt_操作记录->Name = L"lbl_Prompt_操作记录";
			this->lbl_Prompt_操作记录->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_操作记录->TabIndex = 73;
			this->lbl_Prompt_操作记录->Text = L"操作记录";
			// 
			// splitter3
			// 
			this->splitter3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->splitter3->Cursor = System::Windows::Forms::Cursors::HSplit;
			this->splitter3->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter3->Enabled = false;
			this->splitter3->Location = System::Drawing::Point(3, 488);
			this->splitter3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->splitter3->Name = L"splitter3";
			this->splitter3->Size = System::Drawing::Size(836, 48);
			this->splitter3->TabIndex = 74;
			this->splitter3->TabStop = false;
			// 
			// splitter2
			// 
			this->splitter2->Location = System::Drawing::Point(0, 488);
			this->splitter2->Name = L"splitter2";
			this->splitter2->Size = System::Drawing::Size(3, 46);
			this->splitter2->TabIndex = 75;
			this->splitter2->TabStop = false;
			// 
			// MemInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(839, 770);
			this->Controls->Add(this->lbl_error);
			this->Controls->Add(this->lbl_Prompt_操作记录);
			this->Controls->Add(this->lbl_Prompt_成员信息);
			this->Controls->Add(this->splitter3);
			this->Controls->Add(this->splitter2);
			this->Controls->Add(this->txt_专业一);
			this->Controls->Add(this->cmb_成员状态);
			this->Controls->Add(this->cmb_搜索授权);
			this->Controls->Add(this->cmb_就业状态);
			this->Controls->Add(this->cmb_学术项目);
			this->Controls->Add(this->cmb_学位);
			this->Controls->Add(this->cmb_成员类型);
			this->Controls->Add(this->btn_取消编辑);
			this->Controls->Add(this->btn_确认编辑);
			this->Controls->Add(this->txt_专业二);
			this->Controls->Add(this->txt_地址第二行);
			this->Controls->Add(this->txt_学生编号);
			this->Controls->Add(this->txt_性别);
			this->Controls->Add(this->txt_地址第一行);
			this->Controls->Add(this->txt_微信号);
			this->Controls->Add(this->txt_姓名);
			this->Controls->Add(this->txt_邮编);
			this->Controls->Add(this->txt_联系电话);
			this->Controls->Add(this->txt_Email);
			this->Controls->Add(this->txt_城市);
			this->Controls->Add(this->txt_结束日期);
			this->Controls->Add(this->txt_职位);
			this->Controls->Add(this->txt_公司);
			this->Controls->Add(this->txt_所在国家);
			this->Controls->Add(this->txt_出生日期);
			this->Controls->Add(this->btn_取消删除);
			this->Controls->Add(this->btn_确认删除);
			this->Controls->Add(this->btn_删除信息);
			this->Controls->Add(this->lbl_搜索授权);
			this->Controls->Add(this->lbl_职位);
			this->Controls->Add(this->lbl_公司);
			this->Controls->Add(this->lbl_就业状态);
			this->Controls->Add(this->lbl_专业一);
			this->Controls->Add(this->lbl_专业二);
			this->Controls->Add(this->lbl_结束日期);
			this->Controls->Add(this->lbl_学位);
			this->Controls->Add(this->lbl_学术项目);
			this->Controls->Add(this->lbl_地址第二行);
			this->Controls->Add(this->lbl_城市);
			this->Controls->Add(this->lbl_邮编);
			this->Controls->Add(this->lbl_地址第一行);
			this->Controls->Add(this->lbl_学生编号);
			this->Controls->Add(this->lbl_所在国家);
			this->Controls->Add(this->lbl_微信号);
			this->Controls->Add(this->lbl_Email);
			this->Controls->Add(this->lbl_联系电话);
			this->Controls->Add(this->lbl_性别);
			this->Controls->Add(this->lbl_出生日期);
			this->Controls->Add(this->lbl_成员类型);
			this->Controls->Add(this->lbl_姓名);
			this->Controls->Add(this->lbl_成员状态);
			this->Controls->Add(this->lbl_成员编号);
			this->Controls->Add(this->btn_编辑信息);
			this->Controls->Add(this->lbl_Prompt_搜索授权);
			this->Controls->Add(this->lbl_Prompt_职位);
			this->Controls->Add(this->lbl_Prompt_公司);
			this->Controls->Add(this->lbl_Prompt_就业状态);
			this->Controls->Add(this->lbl_Prompt_专业二);
			this->Controls->Add(this->lbl_Prompt_专业一);
			this->Controls->Add(this->lbl_Prompt_学位);
			this->Controls->Add(this->lbl_Prompt_结束日期);
			this->Controls->Add(this->lbl_Prompt_学术项目);
			this->Controls->Add(this->lbl_Prompt_学生编号);
			this->Controls->Add(this->lbl_Prompt_地址第二行);
			this->Controls->Add(this->lbl_Prompt_地址第一行);
			this->Controls->Add(this->lbl_Prompt_邮编);
			this->Controls->Add(this->lbl_Prompt_城市);
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
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MemInfoPage";
			this->Text = L"成员信息";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		int _id;
		Database^ database;
		PublicUserInfo::Auth _auth;
		int _stfId;
		
	private:
		Void Initialize();
		Void UpdateInfo();
		Void UpdateRecord();
		Void InsertRecord(String^);
		Void Level2Display();
		Void Level3Display();
		Void DeleteRecord();
		Void btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Delete_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_ChangeInfoAccept_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_ChangeInfoCancel_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_DeleteAccept_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_DeleteCancel_Click(System::Object^ sender, System::EventArgs^ e);
		Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
