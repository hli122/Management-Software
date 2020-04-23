#pragma once
#include "Database.h"
#include "PublicUserInfo.h"

/*
 * OrdInfoPage.h
 *
 * This file shows a Order Information page for on Order data.
 *
 * @author: Haoran Li
 * Revised: 4/12/20
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
	/// OrdInfoPage 摘要
	/// </summary>
	public ref class OrdInfoPage : public System::Windows::Forms::Form
	{
	public:
		OrdInfoPage(PublicUserInfo^ pui, int^ inputId)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
			_publicUserInfo = pui;
			_ordId = inputId;

			try {
				database = gcnew Database(Database::DatabaseType::Data);
				UpdateInfo();
			}
			catch (Exception^ exception) {
				lbl_DBError->Text = exception->Message;
				btn_ChangeInfo->Enabled = false;
				btn_Delete->Enabled = false;
			}
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~OrdInfoPage()
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
	private: System::Windows::Forms::Label^ lbl_Prompt_OdrId;
	private: System::Windows::Forms::Label^ lbl_OdrId;
	private: System::Windows::Forms::Label^ lbl_Prompt_OdrStat;
	private: System::Windows::Forms::Label^ lbl_OdrStat;
	private: System::Windows::Forms::TextBox^ txt_OdrStat;
	private: System::Windows::Forms::Label^ lbl_Prompt_SbmTime;
	private: System::Windows::Forms::Label^ lbl_Sbmtime;
	private: System::Windows::Forms::Label^ lbl_Prompt_MemID;
	private: System::Windows::Forms::Label^ lbl_MemID;
	private: System::Windows::Forms::Label^ lbl_Prompt_MemName;
	private: System::Windows::Forms::Label^ lbl_MemName;
	private: System::Windows::Forms::Label^ lbl_Prompt_Email;
	private: System::Windows::Forms::Label^ lbl_Email;
	private: System::Windows::Forms::Label^ lbl_Prompt_Country;
	private: System::Windows::Forms::Label^ lbl_Country;
	private: System::Windows::Forms::Label^ lbl_Prompt_City;
	private: System::Windows::Forms::Label^ lbl_City;
	private: System::Windows::Forms::Label^ lbl_Prompt_Postal;
	private: System::Windows::Forms::Label^ lbl_Postal;
	private: System::Windows::Forms::Label^ lbl_Prompt_Address1;
	private: System::Windows::Forms::Label^ lbl_Address1;
	private: System::Windows::Forms::Label^ lbl_Prompt_Address2;
	private: System::Windows::Forms::Label^ lbl_Address2;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfID;
	private: System::Windows::Forms::Label^ lbl_StfID;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfName;
	private: System::Windows::Forms::Label^ lbl_StfName;
	private: System::Windows::Forms::Label^ lbl_Prompt_ItemId;
	private: System::Windows::Forms::Label^ lbl_ItemId;
	private: System::Windows::Forms::Label^ lbl_Prompt_ItemName;
	private: System::Windows::Forms::Label^ lbl_ItemName;
	private: System::Windows::Forms::TextBox^ txt_ItemId;
	private: System::Windows::Forms::TextBox^ txt_ItemName;
	private: System::Windows::Forms::Label^ lbl_Prompt_ItemAmt;
	private: System::Windows::Forms::Label^ lbl_OdrAmt;
	private: System::Windows::Forms::TextBox^ txt_OdrAmt;
	private: System::Windows::Forms::Label^ lbl_Prompt_OrdPrice;
	private: System::Windows::Forms::Label^ lbl_OrdPrice;
	private: System::Windows::Forms::Label^ lbl_Prompt_Content;
	private: System::Windows::Forms::RichTextBox^ rtxt_Content;
	private: System::Windows::Forms::Button^ btn_ChangeInfo;
	private: System::Windows::Forms::Button^ btn_Delete;
	private: System::Windows::Forms::Button^ btn_Confirm;
	private: System::Windows::Forms::Button^ btn_Cancel;
	private: System::Windows::Forms::Label^ lbl_DBError;
	private: System::Windows::Forms::Button^ btn_DelConfirm;
	private: System::Windows::Forms::Label^ lbl_Content;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Label^ lbl_Prompt_Page;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::Label^ lbl_Prompt_ErrMsg;

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
			this->lbl_Prompt_OdrId = (gcnew System::Windows::Forms::Label());
			this->lbl_OdrId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_OdrStat = (gcnew System::Windows::Forms::Label());
			this->lbl_OdrStat = (gcnew System::Windows::Forms::Label());
			this->txt_OdrStat = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_SbmTime = (gcnew System::Windows::Forms::Label());
			this->lbl_Sbmtime = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_MemID = (gcnew System::Windows::Forms::Label());
			this->lbl_MemID = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_MemName = (gcnew System::Windows::Forms::Label());
			this->lbl_MemName = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Country = (gcnew System::Windows::Forms::Label());
			this->lbl_Country = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_City = (gcnew System::Windows::Forms::Label());
			this->lbl_City = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Postal = (gcnew System::Windows::Forms::Label());
			this->lbl_Postal = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Address1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Address1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Address2 = (gcnew System::Windows::Forms::Label());
			this->lbl_Address2 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfID = (gcnew System::Windows::Forms::Label());
			this->lbl_StfID = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfName = (gcnew System::Windows::Forms::Label());
			this->lbl_StfName = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_ItemId = (gcnew System::Windows::Forms::Label());
			this->lbl_ItemId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_ItemName = (gcnew System::Windows::Forms::Label());
			this->lbl_ItemName = (gcnew System::Windows::Forms::Label());
			this->txt_ItemId = (gcnew System::Windows::Forms::TextBox());
			this->txt_ItemName = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_ItemAmt = (gcnew System::Windows::Forms::Label());
			this->lbl_OdrAmt = (gcnew System::Windows::Forms::Label());
			this->txt_OdrAmt = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_OrdPrice = (gcnew System::Windows::Forms::Label());
			this->lbl_OrdPrice = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Content = (gcnew System::Windows::Forms::Label());
			this->rtxt_Content = (gcnew System::Windows::Forms::RichTextBox());
			this->btn_ChangeInfo = (gcnew System::Windows::Forms::Button());
			this->btn_Delete = (gcnew System::Windows::Forms::Button());
			this->btn_Confirm = (gcnew System::Windows::Forms::Button());
			this->btn_Cancel = (gcnew System::Windows::Forms::Button());
			this->lbl_DBError = (gcnew System::Windows::Forms::Label());
			this->btn_DelConfirm = (gcnew System::Windows::Forms::Button());
			this->lbl_Content = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->lbl_Prompt_Page = (gcnew System::Windows::Forms::Label());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->lbl_Prompt_ErrMsg = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// lbl_Prompt_OdrId
			// 
			this->lbl_Prompt_OdrId->AutoSize = true;
			this->lbl_Prompt_OdrId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_OdrId->Location = System::Drawing::Point(22, 42);
			this->lbl_Prompt_OdrId->Name = L"lbl_Prompt_OdrId";
			this->lbl_Prompt_OdrId->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_OdrId->TabIndex = 0;
			this->lbl_Prompt_OdrId->Text = L"订单编号";
			// 
			// lbl_OdrId
			// 
			this->lbl_OdrId->AutoSize = true;
			this->lbl_OdrId->Location = System::Drawing::Point(112, 42);
			this->lbl_OdrId->Name = L"lbl_OdrId";
			this->lbl_OdrId->Size = System::Drawing::Size(31, 17);
			this->lbl_OdrId->TabIndex = 1;
			this->lbl_OdrId->Text = L"N/A";
			// 
			// lbl_Prompt_OdrStat
			// 
			this->lbl_Prompt_OdrStat->AutoSize = true;
			this->lbl_Prompt_OdrStat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_OdrStat->Location = System::Drawing::Point(147, 42);
			this->lbl_Prompt_OdrStat->Name = L"lbl_Prompt_OdrStat";
			this->lbl_Prompt_OdrStat->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_OdrStat->TabIndex = 2;
			this->lbl_Prompt_OdrStat->Text = L"订单状态";
			// 
			// lbl_OdrStat
			// 
			this->lbl_OdrStat->AutoSize = true;
			this->lbl_OdrStat->Location = System::Drawing::Point(243, 42);
			this->lbl_OdrStat->Name = L"lbl_OdrStat";
			this->lbl_OdrStat->Size = System::Drawing::Size(31, 17);
			this->lbl_OdrStat->TabIndex = 3;
			this->lbl_OdrStat->Text = L"N/A";
			// 
			// txt_OdrStat
			// 
			this->txt_OdrStat->Location = System::Drawing::Point(246, 39);
			this->txt_OdrStat->Name = L"txt_OdrStat";
			this->txt_OdrStat->Size = System::Drawing::Size(100, 22);
			this->txt_OdrStat->TabIndex = 4;
			// 
			// lbl_Prompt_SbmTime
			// 
			this->lbl_Prompt_SbmTime->AutoSize = true;
			this->lbl_Prompt_SbmTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_SbmTime->Location = System::Drawing::Point(362, 42);
			this->lbl_Prompt_SbmTime->Name = L"lbl_Prompt_SbmTime";
			this->lbl_Prompt_SbmTime->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_SbmTime->TabIndex = 5;
			this->lbl_Prompt_SbmTime->Text = L"提交时间";
			// 
			// lbl_Sbmtime
			// 
			this->lbl_Sbmtime->AutoSize = true;
			this->lbl_Sbmtime->Location = System::Drawing::Point(465, 42);
			this->lbl_Sbmtime->Name = L"lbl_Sbmtime";
			this->lbl_Sbmtime->Size = System::Drawing::Size(31, 17);
			this->lbl_Sbmtime->TabIndex = 6;
			this->lbl_Sbmtime->Text = L"N/A";
			// 
			// lbl_Prompt_MemID
			// 
			this->lbl_Prompt_MemID->AutoSize = true;
			this->lbl_Prompt_MemID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_MemID->Location = System::Drawing::Point(21, 77);
			this->lbl_Prompt_MemID->Name = L"lbl_Prompt_MemID";
			this->lbl_Prompt_MemID->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_MemID->TabIndex = 7;
			this->lbl_Prompt_MemID->Text = L"成员编号";
			// 
			// lbl_MemID
			// 
			this->lbl_MemID->AutoSize = true;
			this->lbl_MemID->Location = System::Drawing::Point(112, 77);
			this->lbl_MemID->Name = L"lbl_MemID";
			this->lbl_MemID->Size = System::Drawing::Size(31, 17);
			this->lbl_MemID->TabIndex = 8;
			this->lbl_MemID->Text = L"N/A";
			// 
			// lbl_Prompt_MemName
			// 
			this->lbl_Prompt_MemName->AutoSize = true;
			this->lbl_Prompt_MemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_MemName->Location = System::Drawing::Point(147, 77);
			this->lbl_Prompt_MemName->Name = L"lbl_Prompt_MemName";
			this->lbl_Prompt_MemName->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_MemName->TabIndex = 9;
			this->lbl_Prompt_MemName->Text = L"成员姓名";
			// 
			// lbl_MemName
			// 
			this->lbl_MemName->AutoSize = true;
			this->lbl_MemName->Location = System::Drawing::Point(246, 77);
			this->lbl_MemName->Name = L"lbl_MemName";
			this->lbl_MemName->Size = System::Drawing::Size(31, 17);
			this->lbl_MemName->TabIndex = 10;
			this->lbl_MemName->Text = L"N/A";
			// 
			// lbl_Prompt_Email
			// 
			this->lbl_Prompt_Email->AutoSize = true;
			this->lbl_Prompt_Email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Email->Location = System::Drawing::Point(362, 77);
			this->lbl_Prompt_Email->Name = L"lbl_Prompt_Email";
			this->lbl_Prompt_Email->Size = System::Drawing::Size(38, 17);
			this->lbl_Prompt_Email->TabIndex = 11;
			this->lbl_Prompt_Email->Text = L"邮箱";
			// 
			// lbl_Email
			// 
			this->lbl_Email->AutoSize = true;
			this->lbl_Email->Location = System::Drawing::Point(465, 77);
			this->lbl_Email->Name = L"lbl_Email";
			this->lbl_Email->Size = System::Drawing::Size(31, 17);
			this->lbl_Email->TabIndex = 12;
			this->lbl_Email->Text = L"N/A";
			// 
			// lbl_Prompt_Country
			// 
			this->lbl_Prompt_Country->AutoSize = true;
			this->lbl_Prompt_Country->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Country->Location = System::Drawing::Point(561, 77);
			this->lbl_Prompt_Country->Name = L"lbl_Prompt_Country";
			this->lbl_Prompt_Country->Size = System::Drawing::Size(38, 17);
			this->lbl_Prompt_Country->TabIndex = 13;
			this->lbl_Prompt_Country->Text = L"国家";
			// 
			// lbl_Country
			// 
			this->lbl_Country->AutoSize = true;
			this->lbl_Country->Location = System::Drawing::Point(631, 77);
			this->lbl_Country->Name = L"lbl_Country";
			this->lbl_Country->Size = System::Drawing::Size(31, 17);
			this->lbl_Country->TabIndex = 14;
			this->lbl_Country->Text = L"N/A";
			// 
			// lbl_Prompt_City
			// 
			this->lbl_Prompt_City->AutoSize = true;
			this->lbl_Prompt_City->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_City->Location = System::Drawing::Point(674, 77);
			this->lbl_Prompt_City->Name = L"lbl_Prompt_City";
			this->lbl_Prompt_City->Size = System::Drawing::Size(38, 17);
			this->lbl_Prompt_City->TabIndex = 15;
			this->lbl_Prompt_City->Text = L"城市";
			// 
			// lbl_City
			// 
			this->lbl_City->AutoSize = true;
			this->lbl_City->Location = System::Drawing::Point(715, 77);
			this->lbl_City->Name = L"lbl_City";
			this->lbl_City->Size = System::Drawing::Size(31, 17);
			this->lbl_City->TabIndex = 16;
			this->lbl_City->Text = L"N/A";
			// 
			// lbl_Prompt_Postal
			// 
			this->lbl_Prompt_Postal->AutoSize = true;
			this->lbl_Prompt_Postal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Postal->Location = System::Drawing::Point(792, 77);
			this->lbl_Prompt_Postal->Name = L"lbl_Prompt_Postal";
			this->lbl_Prompt_Postal->Size = System::Drawing::Size(38, 17);
			this->lbl_Prompt_Postal->TabIndex = 17;
			this->lbl_Prompt_Postal->Text = L"邮编";
			// 
			// lbl_Postal
			// 
			this->lbl_Postal->AutoSize = true;
			this->lbl_Postal->Location = System::Drawing::Point(851, 77);
			this->lbl_Postal->Name = L"lbl_Postal";
			this->lbl_Postal->Size = System::Drawing::Size(31, 17);
			this->lbl_Postal->TabIndex = 18;
			this->lbl_Postal->Text = L"N/A";
			// 
			// lbl_Prompt_Address1
			// 
			this->lbl_Prompt_Address1->AutoSize = true;
			this->lbl_Prompt_Address1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Address1->Location = System::Drawing::Point(21, 113);
			this->lbl_Prompt_Address1->Name = L"lbl_Prompt_Address1";
			this->lbl_Prompt_Address1->Size = System::Drawing::Size(47, 17);
			this->lbl_Prompt_Address1->TabIndex = 19;
			this->lbl_Prompt_Address1->Text = L"地址1";
			// 
			// lbl_Address1
			// 
			this->lbl_Address1->AutoSize = true;
			this->lbl_Address1->Location = System::Drawing::Point(112, 113);
			this->lbl_Address1->Name = L"lbl_Address1";
			this->lbl_Address1->Size = System::Drawing::Size(31, 17);
			this->lbl_Address1->TabIndex = 20;
			this->lbl_Address1->Text = L"N/A";
			// 
			// lbl_Prompt_Address2
			// 
			this->lbl_Prompt_Address2->AutoSize = true;
			this->lbl_Prompt_Address2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Address2->Location = System::Drawing::Point(362, 113);
			this->lbl_Prompt_Address2->Name = L"lbl_Prompt_Address2";
			this->lbl_Prompt_Address2->Size = System::Drawing::Size(47, 17);
			this->lbl_Prompt_Address2->TabIndex = 21;
			this->lbl_Prompt_Address2->Text = L"地址2";
			// 
			// lbl_Address2
			// 
			this->lbl_Address2->AutoSize = true;
			this->lbl_Address2->Location = System::Drawing::Point(465, 113);
			this->lbl_Address2->Name = L"lbl_Address2";
			this->lbl_Address2->Size = System::Drawing::Size(31, 17);
			this->lbl_Address2->TabIndex = 22;
			this->lbl_Address2->Text = L"N/A";
			// 
			// lbl_Prompt_StfID
			// 
			this->lbl_Prompt_StfID->AutoSize = true;
			this->lbl_Prompt_StfID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfID->Location = System::Drawing::Point(22, 146);
			this->lbl_Prompt_StfID->Name = L"lbl_Prompt_StfID";
			this->lbl_Prompt_StfID->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_StfID->TabIndex = 23;
			this->lbl_Prompt_StfID->Text = L"员工编号";
			// 
			// lbl_StfID
			// 
			this->lbl_StfID->AutoSize = true;
			this->lbl_StfID->Location = System::Drawing::Point(112, 146);
			this->lbl_StfID->Name = L"lbl_StfID";
			this->lbl_StfID->Size = System::Drawing::Size(31, 17);
			this->lbl_StfID->TabIndex = 24;
			this->lbl_StfID->Text = L"N/A";
			// 
			// lbl_Prompt_StfName
			// 
			this->lbl_Prompt_StfName->AutoSize = true;
			this->lbl_Prompt_StfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfName->Location = System::Drawing::Point(362, 146);
			this->lbl_Prompt_StfName->Name = L"lbl_Prompt_StfName";
			this->lbl_Prompt_StfName->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_StfName->TabIndex = 25;
			this->lbl_Prompt_StfName->Text = L"员工姓名";
			// 
			// lbl_StfName
			// 
			this->lbl_StfName->AutoSize = true;
			this->lbl_StfName->Location = System::Drawing::Point(465, 146);
			this->lbl_StfName->Name = L"lbl_StfName";
			this->lbl_StfName->Size = System::Drawing::Size(31, 17);
			this->lbl_StfName->TabIndex = 26;
			this->lbl_StfName->Text = L"N/A";
			// 
			// lbl_Prompt_ItemId
			// 
			this->lbl_Prompt_ItemId->AutoSize = true;
			this->lbl_Prompt_ItemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_ItemId->Location = System::Drawing::Point(22, 180);
			this->lbl_Prompt_ItemId->Name = L"lbl_Prompt_ItemId";
			this->lbl_Prompt_ItemId->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_ItemId->TabIndex = 27;
			this->lbl_Prompt_ItemId->Text = L"商品编号";
			// 
			// lbl_ItemId
			// 
			this->lbl_ItemId->AutoSize = true;
			this->lbl_ItemId->Location = System::Drawing::Point(112, 181);
			this->lbl_ItemId->Name = L"lbl_ItemId";
			this->lbl_ItemId->Size = System::Drawing::Size(31, 17);
			this->lbl_ItemId->TabIndex = 28;
			this->lbl_ItemId->Text = L"N/A";
			// 
			// lbl_Prompt_ItemName
			// 
			this->lbl_Prompt_ItemName->AutoSize = true;
			this->lbl_Prompt_ItemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_ItemName->Location = System::Drawing::Point(362, 181);
			this->lbl_Prompt_ItemName->Name = L"lbl_Prompt_ItemName";
			this->lbl_Prompt_ItemName->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_ItemName->TabIndex = 29;
			this->lbl_Prompt_ItemName->Text = L"商品名称";
			// 
			// lbl_ItemName
			// 
			this->lbl_ItemName->AutoSize = true;
			this->lbl_ItemName->Location = System::Drawing::Point(465, 180);
			this->lbl_ItemName->Name = L"lbl_ItemName";
			this->lbl_ItemName->Size = System::Drawing::Size(31, 17);
			this->lbl_ItemName->TabIndex = 30;
			this->lbl_ItemName->Text = L"N/A";
			// 
			// txt_ItemId
			// 
			this->txt_ItemId->Location = System::Drawing::Point(115, 181);
			this->txt_ItemId->Name = L"txt_ItemId";
			this->txt_ItemId->Size = System::Drawing::Size(100, 22);
			this->txt_ItemId->TabIndex = 31;
			// 
			// txt_ItemName
			// 
			this->txt_ItemName->Location = System::Drawing::Point(468, 178);
			this->txt_ItemName->Name = L"txt_ItemName";
			this->txt_ItemName->Size = System::Drawing::Size(100, 22);
			this->txt_ItemName->TabIndex = 32;
			// 
			// lbl_Prompt_ItemAmt
			// 
			this->lbl_Prompt_ItemAmt->AutoSize = true;
			this->lbl_Prompt_ItemAmt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_ItemAmt->Location = System::Drawing::Point(21, 221);
			this->lbl_Prompt_ItemAmt->Name = L"lbl_Prompt_ItemAmt";
			this->lbl_Prompt_ItemAmt->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_ItemAmt->TabIndex = 33;
			this->lbl_Prompt_ItemAmt->Text = L"商品数量";
			// 
			// lbl_OdrAmt
			// 
			this->lbl_OdrAmt->AutoSize = true;
			this->lbl_OdrAmt->Location = System::Drawing::Point(115, 221);
			this->lbl_OdrAmt->Name = L"lbl_OdrAmt";
			this->lbl_OdrAmt->Size = System::Drawing::Size(31, 17);
			this->lbl_OdrAmt->TabIndex = 34;
			this->lbl_OdrAmt->Text = L"N/A";
			// 
			// txt_OdrAmt
			// 
			this->txt_OdrAmt->Location = System::Drawing::Point(115, 221);
			this->txt_OdrAmt->Name = L"txt_OdrAmt";
			this->txt_OdrAmt->Size = System::Drawing::Size(100, 22);
			this->txt_OdrAmt->TabIndex = 35;
			// 
			// lbl_Prompt_OrdPrice
			// 
			this->lbl_Prompt_OrdPrice->AutoSize = true;
			this->lbl_Prompt_OrdPrice->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_OrdPrice->Location = System::Drawing::Point(362, 221);
			this->lbl_Prompt_OrdPrice->Name = L"lbl_Prompt_OrdPrice";
			this->lbl_Prompt_OrdPrice->Size = System::Drawing::Size(68, 17);
			this->lbl_Prompt_OrdPrice->TabIndex = 36;
			this->lbl_Prompt_OrdPrice->Text = L"商品总价";
			// 
			// lbl_OrdPrice
			// 
			this->lbl_OrdPrice->AutoSize = true;
			this->lbl_OrdPrice->Location = System::Drawing::Point(465, 221);
			this->lbl_OrdPrice->Name = L"lbl_OrdPrice";
			this->lbl_OrdPrice->Size = System::Drawing::Size(31, 17);
			this->lbl_OrdPrice->TabIndex = 37;
			this->lbl_OrdPrice->Text = L"N/A";
			// 
			// lbl_Prompt_Content
			// 
			this->lbl_Prompt_Content->AutoSize = true;
			this->lbl_Prompt_Content->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Content->Location = System::Drawing::Point(22, 257);
			this->lbl_Prompt_Content->Name = L"lbl_Prompt_Content";
			this->lbl_Prompt_Content->Size = System::Drawing::Size(38, 17);
			this->lbl_Prompt_Content->TabIndex = 38;
			this->lbl_Prompt_Content->Text = L"备注";
			// 
			// rtxt_Content
			// 
			this->rtxt_Content->Location = System::Drawing::Point(33, 288);
			this->rtxt_Content->Name = L"rtxt_Content";
			this->rtxt_Content->Size = System::Drawing::Size(244, 96);
			this->rtxt_Content->TabIndex = 39;
			this->rtxt_Content->Text = L"";
			// 
			// btn_ChangeInfo
			// 
			this->btn_ChangeInfo->Location = System::Drawing::Point(365, 291);
			this->btn_ChangeInfo->Name = L"btn_ChangeInfo";
			this->btn_ChangeInfo->Size = System::Drawing::Size(75, 41);
			this->btn_ChangeInfo->TabIndex = 40;
			this->btn_ChangeInfo->Text = L"修改";
			this->btn_ChangeInfo->UseVisualStyleBackColor = true;
			this->btn_ChangeInfo->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_Change_Click);
			// 
			// btn_Delete
			// 
			this->btn_Delete->Location = System::Drawing::Point(512, 291);
			this->btn_Delete->Name = L"btn_Delete";
			this->btn_Delete->Size = System::Drawing::Size(75, 41);
			this->btn_Delete->TabIndex = 41;
			this->btn_Delete->Text = L"删除";
			this->btn_Delete->UseVisualStyleBackColor = true;
			this->btn_Delete->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_Delete_Click);
			// 
			// btn_Confirm
			// 
			this->btn_Confirm->Location = System::Drawing::Point(365, 357);
			this->btn_Confirm->Name = L"btn_Confirm";
			this->btn_Confirm->Size = System::Drawing::Size(75, 41);
			this->btn_Confirm->TabIndex = 43;
			this->btn_Confirm->Text = L"确认";
			this->btn_Confirm->UseVisualStyleBackColor = true;
			this->btn_Confirm->Visible = false;
			this->btn_Confirm->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_Confirm_Click);
			// 
			// btn_Cancel
			// 
			this->btn_Cancel->Location = System::Drawing::Point(634, 357);
			this->btn_Cancel->Name = L"btn_Cancel";
			this->btn_Cancel->Size = System::Drawing::Size(75, 41);
			this->btn_Cancel->TabIndex = 44;
			this->btn_Cancel->Text = L"取消";
			this->btn_Cancel->UseVisualStyleBackColor = true;
			this->btn_Cancel->Visible = false;
			this->btn_Cancel->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_Cancel_Click);
			// 
			// lbl_DBError
			// 
			this->lbl_DBError->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_DBError->AutoSize = true;
			this->lbl_DBError->Location = System::Drawing::Point(420, 521);
			this->lbl_DBError->Name = L"lbl_DBError";
			this->lbl_DBError->Size = System::Drawing::Size(61, 17);
			this->lbl_DBError->TabIndex = 45;
			this->lbl_DBError->Text = L"No error";
			this->lbl_DBError->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->lbl_DBError->Visible = false;
			// 
			// btn_DelConfirm
			// 
			this->btn_DelConfirm->Location = System::Drawing::Point(512, 357);
			this->btn_DelConfirm->Name = L"btn_DelConfirm";
			this->btn_DelConfirm->Size = System::Drawing::Size(75, 41);
			this->btn_DelConfirm->TabIndex = 46;
			this->btn_DelConfirm->Text = L"确认";
			this->btn_DelConfirm->UseVisualStyleBackColor = true;
			this->btn_DelConfirm->Visible = false;
			this->btn_DelConfirm->Click += gcnew System::EventHandler(this, &OrdInfoPage::btn_DelConfirm_Click);
			// 
			// lbl_Content
			// 
			this->lbl_Content->AutoSize = true;
			this->lbl_Content->Location = System::Drawing::Point(33, 291);
			this->lbl_Content->Name = L"lbl_Content";
			this->lbl_Content->Size = System::Drawing::Size(31, 17);
			this->lbl_Content->TabIndex = 47;
			this->lbl_Content->Text = L"N/A";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Info;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->dataGridView1->Location = System::Drawing::Point(0, 435);
			this->dataGridView1->MinimumSize = System::Drawing::Size(840, 40);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(919, 40);
			this->dataGridView1->TabIndex = 48;
			// 
			// dataGridView2
			// 
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::Info;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Top;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(919, 40);
			this->dataGridView2->TabIndex = 49;
			// 
			// lbl_Prompt_Page
			// 
			this->lbl_Prompt_Page->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Page->AutoSize = true;
			this->lbl_Prompt_Page->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Page->Location = System::Drawing::Point(370, 9);
			this->lbl_Prompt_Page->Name = L"lbl_Prompt_Page";
			this->lbl_Prompt_Page->Size = System::Drawing::Size(96, 25);
			this->lbl_Prompt_Page->TabIndex = 50;
			this->lbl_Prompt_Page->Text = L"订单信息";
			this->lbl_Prompt_Page->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// dataGridView3
			// 
			this->dataGridView3->BackgroundColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView3->Location = System::Drawing::Point(0, 0);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(919, 475);
			this->dataGridView3->TabIndex = 51;
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->dataGridView4->Location = System::Drawing::Point(0, 475);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowHeadersWidth = 51;
			this->dataGridView4->RowTemplate->Height = 24;
			this->dataGridView4->Size = System::Drawing::Size(919, 116);
			this->dataGridView4->TabIndex = 52;
			// 
			// lbl_Prompt_ErrMsg
			// 
			this->lbl_Prompt_ErrMsg->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_ErrMsg->AutoSize = true;
			this->lbl_Prompt_ErrMsg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_ErrMsg->ForeColor = System::Drawing::Color::Red;
			this->lbl_Prompt_ErrMsg->Location = System::Drawing::Point(382, 447);
			this->lbl_Prompt_ErrMsg->Name = L"lbl_Prompt_ErrMsg";
			this->lbl_Prompt_ErrMsg->Size = System::Drawing::Size(96, 25);
			this->lbl_Prompt_ErrMsg->TabIndex = 53;
			this->lbl_Prompt_ErrMsg->Text = L"错误信息";
			this->lbl_Prompt_ErrMsg->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// OrdInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(919, 591);
			this->Controls->Add(this->lbl_Prompt_ErrMsg);
			this->Controls->Add(this->lbl_Prompt_Page);
			this->Controls->Add(this->rtxt_Content);
			this->Controls->Add(this->lbl_Content);
			this->Controls->Add(this->btn_DelConfirm);
			this->Controls->Add(this->lbl_DBError);
			this->Controls->Add(this->btn_Cancel);
			this->Controls->Add(this->btn_Confirm);
			this->Controls->Add(this->btn_Delete);
			this->Controls->Add(this->btn_ChangeInfo);
			this->Controls->Add(this->lbl_Prompt_Content);
			this->Controls->Add(this->lbl_OrdPrice);
			this->Controls->Add(this->lbl_Prompt_OrdPrice);
			this->Controls->Add(this->txt_OdrAmt);
			this->Controls->Add(this->lbl_OdrAmt);
			this->Controls->Add(this->lbl_Prompt_ItemAmt);
			this->Controls->Add(this->txt_ItemName);
			this->Controls->Add(this->txt_ItemId);
			this->Controls->Add(this->lbl_ItemName);
			this->Controls->Add(this->lbl_Prompt_ItemName);
			this->Controls->Add(this->lbl_ItemId);
			this->Controls->Add(this->lbl_Prompt_ItemId);
			this->Controls->Add(this->lbl_StfName);
			this->Controls->Add(this->lbl_Prompt_StfName);
			this->Controls->Add(this->lbl_StfID);
			this->Controls->Add(this->lbl_Prompt_StfID);
			this->Controls->Add(this->lbl_Address2);
			this->Controls->Add(this->lbl_Prompt_Address2);
			this->Controls->Add(this->lbl_Address1);
			this->Controls->Add(this->lbl_Prompt_Address1);
			this->Controls->Add(this->lbl_Postal);
			this->Controls->Add(this->lbl_Prompt_Postal);
			this->Controls->Add(this->lbl_City);
			this->Controls->Add(this->lbl_Prompt_City);
			this->Controls->Add(this->lbl_Country);
			this->Controls->Add(this->lbl_Prompt_Country);
			this->Controls->Add(this->lbl_Email);
			this->Controls->Add(this->lbl_Prompt_Email);
			this->Controls->Add(this->lbl_MemName);
			this->Controls->Add(this->lbl_Prompt_MemName);
			this->Controls->Add(this->lbl_MemID);
			this->Controls->Add(this->lbl_Prompt_MemID);
			this->Controls->Add(this->lbl_Sbmtime);
			this->Controls->Add(this->lbl_Prompt_SbmTime);
			this->Controls->Add(this->txt_OdrStat);
			this->Controls->Add(this->lbl_OdrStat);
			this->Controls->Add(this->lbl_Prompt_OdrStat);
			this->Controls->Add(this->lbl_OdrId);
			this->Controls->Add(this->lbl_Prompt_OdrId);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView3);
			this->Controls->Add(this->dataGridView4);
			this->Name = L"OrdInfoPage";
			this->Text = L"OrdInfoPage";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Database^ database;
		PublicUserInfo^ _publicUserInfo;
		int^ _ordId;
		double^ item_price;
	private:
		Void UpdateInfo();
		Void btn_Change_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Delete_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_DelConfirm_Click(System::Object^ sender, System::EventArgs^ e);
};
}