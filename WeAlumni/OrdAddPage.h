#pragma once
#include "Database.h"
#include "PublicUserInfo.h"

/*
 * OrdAddPage.h
 *
 * This file includes functions of inserting new data into Order table
 *
 * @author: Haoran Li
 * Revised: 4/07/20
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
	/// OrdAddPage 摘要
	/// </summary>
	public ref class OrdAddPage : public System::Windows::Forms::Form
	{
	public:
		OrdAddPage(PublicUserInfo^ input)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
			_PublicUserInfo = input;
			try {
				database = gcnew Database(Database::DatabaseType::Data);
				Initialize();
			}
			catch (Exception^ exception) {
				lbl_error->Text = exception->Message;
				lbl_error->ForeColor = Color::Red;
				lbl_error->Visible = true;
			}
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~OrdAddPage()
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
	private: System::Windows::Forms::Label^ lbl_OrdPageName;
	private: System::Windows::Forms::Label^ lbl_Promt_OrdId;
	private: System::Windows::Forms::Label^ lbl_OrdId;
	private: System::Windows::Forms::Label^ lbl_Prompt_OrdStat;
	private: System::Windows::Forms::ComboBox^ cmb_OrdStat;
	private: System::Windows::Forms::Label^ lbl_Prompt_SubmitTime;
	private: System::Windows::Forms::Label^ lbl_MemId;
	private: System::Windows::Forms::TextBox^ txt_MemId;
	private: System::Windows::Forms::Label^ lbl_MemName;
	private: System::Windows::Forms::TextBox^ txt_MemName;
	private: System::Windows::Forms::Button^ btn_VerifyMem;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfId;
	private: System::Windows::Forms::Label^ lbl_StfId;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfName;
	private: System::Windows::Forms::Label^ lbl_StfName;
	private: System::Windows::Forms::Label^ lbl_ItemId;
	private: System::Windows::Forms::TextBox^ txt_ItemId;
	private: System::Windows::Forms::Label^ lbl_ItemName;
	private: System::Windows::Forms::TextBox^ txt_ItemName;
	private: System::Windows::Forms::Label^ lbl_Prompt_ItemPrice;
	private: System::Windows::Forms::Label^ lbl_ItemPrice;
	private: System::Windows::Forms::Button^ btn_VerifyItm;
	private: System::Windows::Forms::Label^ lbl_Prompt_OrdAmt;
	private: System::Windows::Forms::Label^ lbl_Prompt_OrdPrice;
	private: System::Windows::Forms::Label^ lbl_OrdPrice;
	private: System::Windows::Forms::Button^ btn_Confirm;
	private: System::Windows::Forms::Button^ btn_Cancel;
	private: System::Windows::Forms::Label^ lbl_error;
	private: System::Windows::Forms::TextBox^ txt_OrdAmt;
	private: System::Windows::Forms::Label^ lbl_OrdAmt;
	private: System::Windows::Forms::TextBox^ txt_SubmitTime;
	private: System::Windows::Forms::Label^ lbl_SubmitTime;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbl_OrdPageName = (gcnew System::Windows::Forms::Label());
			this->lbl_Promt_OrdId = (gcnew System::Windows::Forms::Label());
			this->lbl_OrdId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_OrdStat = (gcnew System::Windows::Forms::Label());
			this->cmb_OrdStat = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_Prompt_SubmitTime = (gcnew System::Windows::Forms::Label());
			this->lbl_MemId = (gcnew System::Windows::Forms::Label());
			this->txt_MemId = (gcnew System::Windows::Forms::TextBox());
			this->lbl_MemName = (gcnew System::Windows::Forms::Label());
			this->txt_MemName = (gcnew System::Windows::Forms::TextBox());
			this->btn_VerifyMem = (gcnew System::Windows::Forms::Button());
			this->lbl_Prompt_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfName = (gcnew System::Windows::Forms::Label());
			this->lbl_StfName = (gcnew System::Windows::Forms::Label());
			this->lbl_ItemId = (gcnew System::Windows::Forms::Label());
			this->txt_ItemId = (gcnew System::Windows::Forms::TextBox());
			this->lbl_ItemName = (gcnew System::Windows::Forms::Label());
			this->txt_ItemName = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_ItemPrice = (gcnew System::Windows::Forms::Label());
			this->lbl_ItemPrice = (gcnew System::Windows::Forms::Label());
			this->btn_VerifyItm = (gcnew System::Windows::Forms::Button());
			this->lbl_Prompt_OrdAmt = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_OrdPrice = (gcnew System::Windows::Forms::Label());
			this->lbl_OrdPrice = (gcnew System::Windows::Forms::Label());
			this->btn_Confirm = (gcnew System::Windows::Forms::Button());
			this->btn_Cancel = (gcnew System::Windows::Forms::Button());
			this->lbl_error = (gcnew System::Windows::Forms::Label());
			this->txt_OrdAmt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_OrdAmt = (gcnew System::Windows::Forms::Label());
			this->txt_SubmitTime = (gcnew System::Windows::Forms::TextBox());
			this->lbl_SubmitTime = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_OrdPageName
			// 
			this->lbl_OrdPageName->AutoSize = true;
			this->lbl_OrdPageName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_OrdPageName->Location = System::Drawing::Point(320, 9);
			this->lbl_OrdPageName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_OrdPageName->Name = L"lbl_OrdPageName";
			this->lbl_OrdPageName->Size = System::Drawing::Size(113, 29);
			this->lbl_OrdPageName->TabIndex = 0;
			this->lbl_OrdPageName->Text = L"新建订单";
			this->lbl_OrdPageName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_Promt_OrdId
			// 
			this->lbl_Promt_OrdId->AutoSize = true;
			this->lbl_Promt_OrdId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Promt_OrdId->Location = System::Drawing::Point(39, 67);
			this->lbl_Promt_OrdId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Promt_OrdId->Name = L"lbl_Promt_OrdId";
			this->lbl_Promt_OrdId->Size = System::Drawing::Size(90, 24);
			this->lbl_Promt_OrdId->TabIndex = 1;
			this->lbl_Promt_OrdId->Text = L"订单编号";
			// 
			// lbl_OrdId
			// 
			this->lbl_OrdId->AutoSize = true;
			this->lbl_OrdId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_OrdId->Location = System::Drawing::Point(160, 65);
			this->lbl_OrdId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_OrdId->Name = L"lbl_OrdId";
			this->lbl_OrdId->Size = System::Drawing::Size(42, 24);
			this->lbl_OrdId->TabIndex = 2;
			this->lbl_OrdId->Text = L"N/A";
			// 
			// lbl_Prompt_OrdStat
			// 
			this->lbl_Prompt_OrdStat->AutoSize = true;
			this->lbl_Prompt_OrdStat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_OrdStat->Location = System::Drawing::Point(300, 67);
			this->lbl_Prompt_OrdStat->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_OrdStat->Name = L"lbl_Prompt_OrdStat";
			this->lbl_Prompt_OrdStat->Size = System::Drawing::Size(90, 24);
			this->lbl_Prompt_OrdStat->TabIndex = 3;
			this->lbl_Prompt_OrdStat->Text = L"订单状态";
			// 
			// cmb_OrdStat
			// 
			this->cmb_OrdStat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmb_OrdStat->FormattingEnabled = true;
			this->cmb_OrdStat->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Complete", L"In Process" });
			this->cmb_OrdStat->Location = System::Drawing::Point(456, 69);
			this->cmb_OrdStat->Margin = System::Windows::Forms::Padding(2);
			this->cmb_OrdStat->Name = L"cmb_OrdStat";
			this->cmb_OrdStat->Size = System::Drawing::Size(127, 24);
			this->cmb_OrdStat->TabIndex = 4;
			// 
			// lbl_Prompt_SubmitTime
			// 
			this->lbl_Prompt_SubmitTime->AutoSize = true;
			this->lbl_Prompt_SubmitTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_SubmitTime->Location = System::Drawing::Point(605, 67);
			this->lbl_Prompt_SubmitTime->Name = L"lbl_Prompt_SubmitTime";
			this->lbl_Prompt_SubmitTime->Size = System::Drawing::Size(90, 24);
			this->lbl_Prompt_SubmitTime->TabIndex = 5;
			this->lbl_Prompt_SubmitTime->Text = L"提交时间";
			// 
			// lbl_MemId
			// 
			this->lbl_MemId->AutoSize = true;
			this->lbl_MemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_MemId->Location = System::Drawing::Point(39, 130);
			this->lbl_MemId->Name = L"lbl_MemId";
			this->lbl_MemId->Size = System::Drawing::Size(90, 24);
			this->lbl_MemId->TabIndex = 7;
			this->lbl_MemId->Text = L"成员编号";
			// 
			// txt_MemId
			// 
			this->txt_MemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_MemId->Location = System::Drawing::Point(164, 130);
			this->txt_MemId->Name = L"txt_MemId";
			this->txt_MemId->Size = System::Drawing::Size(100, 24);
			this->txt_MemId->TabIndex = 8;
			// 
			// lbl_MemName
			// 
			this->lbl_MemName->AutoSize = true;
			this->lbl_MemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_MemName->Location = System::Drawing::Point(300, 129);
			this->lbl_MemName->Name = L"lbl_MemName";
			this->lbl_MemName->Size = System::Drawing::Size(90, 24);
			this->lbl_MemName->TabIndex = 9;
			this->lbl_MemName->Text = L"成员姓名";
			// 
			// txt_MemName
			// 
			this->txt_MemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_MemName->Location = System::Drawing::Point(456, 130);
			this->txt_MemName->Name = L"txt_MemName";
			this->txt_MemName->Size = System::Drawing::Size(100, 24);
			this->txt_MemName->TabIndex = 10;
			// 
			// btn_VerifyMem
			// 
			this->btn_VerifyMem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_VerifyMem->Location = System::Drawing::Point(795, 125);
			this->btn_VerifyMem->Name = L"btn_VerifyMem";
			this->btn_VerifyMem->Size = System::Drawing::Size(112, 37);
			this->btn_VerifyMem->TabIndex = 11;
			this->btn_VerifyMem->Text = L"成员验证";
			this->btn_VerifyMem->UseVisualStyleBackColor = true;
			this->btn_VerifyMem->Click += gcnew System::EventHandler(this, &OrdAddPage::btn_VerifyMem_Click);
			// 
			// lbl_Prompt_StfId
			// 
			this->lbl_Prompt_StfId->AutoSize = true;
			this->lbl_Prompt_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfId->Location = System::Drawing::Point(39, 193);
			this->lbl_Prompt_StfId->Name = L"lbl_Prompt_StfId";
			this->lbl_Prompt_StfId->Size = System::Drawing::Size(90, 24);
			this->lbl_Prompt_StfId->TabIndex = 12;
			this->lbl_Prompt_StfId->Text = L"员工编号";
			// 
			// lbl_StfId
			// 
			this->lbl_StfId->AutoSize = true;
			this->lbl_StfId->Location = System::Drawing::Point(160, 193);
			this->lbl_StfId->Name = L"lbl_StfId";
			this->lbl_StfId->Size = System::Drawing::Size(42, 24);
			this->lbl_StfId->TabIndex = 13;
			this->lbl_StfId->Text = L"N/A";
			// 
			// lbl_Prompt_StfName
			// 
			this->lbl_Prompt_StfName->AutoSize = true;
			this->lbl_Prompt_StfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfName->Location = System::Drawing::Point(300, 193);
			this->lbl_Prompt_StfName->Name = L"lbl_Prompt_StfName";
			this->lbl_Prompt_StfName->Size = System::Drawing::Size(90, 24);
			this->lbl_Prompt_StfName->TabIndex = 14;
			this->lbl_Prompt_StfName->Text = L"员工姓名";
			// 
			// lbl_StfName
			// 
			this->lbl_StfName->AutoSize = true;
			this->lbl_StfName->Location = System::Drawing::Point(452, 193);
			this->lbl_StfName->Name = L"lbl_StfName";
			this->lbl_StfName->Size = System::Drawing::Size(42, 24);
			this->lbl_StfName->TabIndex = 15;
			this->lbl_StfName->Text = L"N/A";
			// 
			// lbl_ItemId
			// 
			this->lbl_ItemId->AutoSize = true;
			this->lbl_ItemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_ItemId->Location = System::Drawing::Point(39, 256);
			this->lbl_ItemId->Name = L"lbl_ItemId";
			this->lbl_ItemId->Size = System::Drawing::Size(90, 24);
			this->lbl_ItemId->TabIndex = 16;
			this->lbl_ItemId->Text = L"商品编号";
			// 
			// txt_ItemId
			// 
			this->txt_ItemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_ItemId->Location = System::Drawing::Point(164, 256);
			this->txt_ItemId->Name = L"txt_ItemId";
			this->txt_ItemId->Size = System::Drawing::Size(100, 24);
			this->txt_ItemId->TabIndex = 17;
			// 
			// lbl_ItemName
			// 
			this->lbl_ItemName->AutoSize = true;
			this->lbl_ItemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_ItemName->Location = System::Drawing::Point(300, 256);
			this->lbl_ItemName->Name = L"lbl_ItemName";
			this->lbl_ItemName->Size = System::Drawing::Size(90, 24);
			this->lbl_ItemName->TabIndex = 18;
			this->lbl_ItemName->Text = L"商品名称";
			// 
			// txt_ItemName
			// 
			this->txt_ItemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_ItemName->Location = System::Drawing::Point(456, 256);
			this->txt_ItemName->Name = L"txt_ItemName";
			this->txt_ItemName->Size = System::Drawing::Size(100, 24);
			this->txt_ItemName->TabIndex = 19;
			// 
			// lbl_Prompt_ItemPrice
			// 
			this->lbl_Prompt_ItemPrice->AutoSize = true;
			this->lbl_Prompt_ItemPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_ItemPrice->Location = System::Drawing::Point(605, 256);
			this->lbl_Prompt_ItemPrice->Name = L"lbl_Prompt_ItemPrice";
			this->lbl_Prompt_ItemPrice->Size = System::Drawing::Size(90, 24);
			this->lbl_Prompt_ItemPrice->TabIndex = 20;
			this->lbl_Prompt_ItemPrice->Text = L"商品单价";
			// 
			// lbl_ItemPrice
			// 
			this->lbl_ItemPrice->AutoSize = true;
			this->lbl_ItemPrice->Location = System::Drawing::Point(728, 256);
			this->lbl_ItemPrice->Name = L"lbl_ItemPrice";
			this->lbl_ItemPrice->Size = System::Drawing::Size(42, 24);
			this->lbl_ItemPrice->TabIndex = 21;
			this->lbl_ItemPrice->Text = L"N/A";
			// 
			// btn_VerifyItm
			// 
			this->btn_VerifyItm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_VerifyItm->Location = System::Drawing::Point(795, 251);
			this->btn_VerifyItm->Name = L"btn_VerifyItm";
			this->btn_VerifyItm->Size = System::Drawing::Size(112, 37);
			this->btn_VerifyItm->TabIndex = 22;
			this->btn_VerifyItm->Text = L"商品验证";
			this->btn_VerifyItm->UseVisualStyleBackColor = true;
			this->btn_VerifyItm->Click += gcnew System::EventHandler(this, &OrdAddPage::btn_VerifyItm_Click);
			// 
			// lbl_Prompt_OrdAmt
			// 
			this->lbl_Prompt_OrdAmt->AutoSize = true;
			this->lbl_Prompt_OrdAmt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_OrdAmt->Location = System::Drawing::Point(38, 321);
			this->lbl_Prompt_OrdAmt->Name = L"lbl_Prompt_OrdAmt";
			this->lbl_Prompt_OrdAmt->Size = System::Drawing::Size(90, 24);
			this->lbl_Prompt_OrdAmt->TabIndex = 23;
			this->lbl_Prompt_OrdAmt->Text = L"商品数量";
			// 
			// lbl_Prompt_OrdPrice
			// 
			this->lbl_Prompt_OrdPrice->AutoSize = true;
			this->lbl_Prompt_OrdPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_OrdPrice->Location = System::Drawing::Point(300, 321);
			this->lbl_Prompt_OrdPrice->Name = L"lbl_Prompt_OrdPrice";
			this->lbl_Prompt_OrdPrice->Size = System::Drawing::Size(90, 24);
			this->lbl_Prompt_OrdPrice->TabIndex = 25;
			this->lbl_Prompt_OrdPrice->Text = L"商品总价";
			// 
			// lbl_OrdPrice
			// 
			this->lbl_OrdPrice->AutoSize = true;
			this->lbl_OrdPrice->Location = System::Drawing::Point(456, 321);
			this->lbl_OrdPrice->Name = L"lbl_OrdPrice";
			this->lbl_OrdPrice->Size = System::Drawing::Size(42, 24);
			this->lbl_OrdPrice->TabIndex = 26;
			this->lbl_OrdPrice->Text = L"N/A";
			// 
			// btn_Confirm
			// 
			this->btn_Confirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Confirm->Location = System::Drawing::Point(42, 431);
			this->btn_Confirm->Name = L"btn_Confirm";
			this->btn_Confirm->Size = System::Drawing::Size(112, 37);
			this->btn_Confirm->TabIndex = 27;
			this->btn_Confirm->Text = L"确认";
			this->btn_Confirm->UseVisualStyleBackColor = true;
			this->btn_Confirm->Click += gcnew System::EventHandler(this, &OrdAddPage::btn_Confirm_Click);
			// 
			// btn_Cancel
			// 
			this->btn_Cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Cancel->Location = System::Drawing::Point(304, 431);
			this->btn_Cancel->Name = L"btn_Cancel";
			this->btn_Cancel->Size = System::Drawing::Size(112, 37);
			this->btn_Cancel->TabIndex = 28;
			this->btn_Cancel->Text = L"取消";
			this->btn_Cancel->UseVisualStyleBackColor = true;
			this->btn_Cancel->Click += gcnew System::EventHandler(this, &OrdAddPage::btn_Cancel_Click);
			// 
			// lbl_error
			// 
			this->lbl_error->AutoSize = true;
			this->lbl_error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_error->ForeColor = System::Drawing::Color::Red;
			this->lbl_error->Location = System::Drawing::Point(609, 431);
			this->lbl_error->Name = L"lbl_error";
			this->lbl_error->Size = System::Drawing::Size(109, 29);
			this->lbl_error->TabIndex = 29;
			this->lbl_error->Text = L"系统错误";
			// 
			// txt_OrdAmt
			// 
			this->txt_OrdAmt->Location = System::Drawing::Point(164, 321);
			this->txt_OrdAmt->Name = L"txt_OrdAmt";
			this->txt_OrdAmt->Size = System::Drawing::Size(100, 28);
			this->txt_OrdAmt->TabIndex = 30;
			// 
			// lbl_OrdAmt
			// 
			this->lbl_OrdAmt->AutoSize = true;
			this->lbl_OrdAmt->Location = System::Drawing::Point(160, 321);
			this->lbl_OrdAmt->Name = L"lbl_OrdAmt";
			this->lbl_OrdAmt->Size = System::Drawing::Size(42, 24);
			this->lbl_OrdAmt->TabIndex = 24;
			this->lbl_OrdAmt->Text = L"N/A";
			// 
			// txt_SubmitTime
			// 
			this->txt_SubmitTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_SubmitTime->Location = System::Drawing::Point(795, 65);
			this->txt_SubmitTime->Name = L"txt_SubmitTime";
			this->txt_SubmitTime->Size = System::Drawing::Size(100, 24);
			this->txt_SubmitTime->TabIndex = 31;
			// 
			// lbl_SubmitTime
			// 
			this->lbl_SubmitTime->AutoSize = true;
			this->lbl_SubmitTime->Location = System::Drawing::Point(791, 65);
			this->lbl_SubmitTime->Name = L"lbl_SubmitTime";
			this->lbl_SubmitTime->Size = System::Drawing::Size(42, 24);
			this->lbl_SubmitTime->TabIndex = 6;
			this->lbl_SubmitTime->Text = L"N/A";
			// 
			// OrdAddPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(954, 749);
			this->Controls->Add(this->txt_SubmitTime);
			this->Controls->Add(this->txt_OrdAmt);
			this->Controls->Add(this->lbl_error);
			this->Controls->Add(this->btn_Cancel);
			this->Controls->Add(this->btn_Confirm);
			this->Controls->Add(this->lbl_OrdPrice);
			this->Controls->Add(this->lbl_Prompt_OrdPrice);
			this->Controls->Add(this->lbl_OrdAmt);
			this->Controls->Add(this->lbl_Prompt_OrdAmt);
			this->Controls->Add(this->btn_VerifyItm);
			this->Controls->Add(this->lbl_ItemPrice);
			this->Controls->Add(this->lbl_Prompt_ItemPrice);
			this->Controls->Add(this->txt_ItemName);
			this->Controls->Add(this->lbl_ItemName);
			this->Controls->Add(this->txt_ItemId);
			this->Controls->Add(this->lbl_ItemId);
			this->Controls->Add(this->lbl_StfName);
			this->Controls->Add(this->lbl_Prompt_StfName);
			this->Controls->Add(this->lbl_StfId);
			this->Controls->Add(this->lbl_Prompt_StfId);
			this->Controls->Add(this->btn_VerifyMem);
			this->Controls->Add(this->txt_MemName);
			this->Controls->Add(this->lbl_MemName);
			this->Controls->Add(this->txt_MemId);
			this->Controls->Add(this->lbl_MemId);
			this->Controls->Add(this->lbl_SubmitTime);
			this->Controls->Add(this->lbl_Prompt_SubmitTime);
			this->Controls->Add(this->cmb_OrdStat);
			this->Controls->Add(this->lbl_Prompt_OrdStat);
			this->Controls->Add(this->lbl_OrdId);
			this->Controls->Add(this->lbl_Promt_OrdId);
			this->Controls->Add(this->lbl_OrdPageName);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"OrdAddPage";
			this->Text = L"新建订单";
			this->Load += gcnew System::EventHandler(this, &OrdAddPage::OrdAddPage_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Database^ database;
		PublicUserInfo^ _PublicUserInfo;

	private:
		System::Void Initialize();
		System::Void InsertRecord();
		System::Void btn_VerifyMem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_VerifyItm_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void OrdAddPage_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
