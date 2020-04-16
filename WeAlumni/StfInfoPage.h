#pragma once
#include "Database.h"
#include "RecInfoPage.h"
#include "PublicUserInfo.h"

/*
 * StfInfoPage.h
 *
 * This file have basic Staff Information interaction actions.
 *
 * @author: Rui Jia
 * Revised: 4/12/20
 *          4/15/20 add AddNewRecord();
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
	/// Summary for StfInfoPage
	/// </summary>
	public ref class StfInfoPage : public System::Windows::Forms::Form
	{
	public:
		StfInfoPage(int^ InputStfId)
		{
			InitializeComponent();
			_MemId = InputStfId;
			_Auth = PublicUserInfo::Auth::Level_1;
			Initialize();
		}

		StfInfoPage(int^ InputStfId, PublicUserInfo^ pui) {
			InitializeComponent();
			_pui = pui;
			_StfId = pui->GetId();
			_MemId = InputStfId;
			_Auth = pui->GetAuth();
			Initialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StfInfoPage()
		{
			if (components)
			{
				delete components;
			}

			if (_database)
			{
				delete _database;
			}
		}

	private: System::Windows::Forms::DataGridView^ dgv_Staff;
	private: System::Windows::Forms::Splitter^ splitter1;
	private: System::Windows::Forms::Label^ lbl_StfId;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfId;
	private: System::Windows::Forms::ComboBox^ cmb_Auth;
	private: System::Windows::Forms::ComboBox^ cmb_Posi;
	private: System::Windows::Forms::ComboBox^ cmb_Dept;
	private: System::Windows::Forms::Label^ lbl_Error;
	private: System::Windows::Forms::Button^ btn_Close;
	private: System::Windows::Forms::Button^ btn_Delete;
	private: System::Windows::Forms::Label^ lbl_Auth;
	private: System::Windows::Forms::Label^ lbl_Posi;
	private: System::Windows::Forms::Label^ lbl_Dept;
	private: System::Windows::Forms::Label^ lbl_Wechat;
	private: System::Windows::Forms::Label^ lbl_Phone;
	private: System::Windows::Forms::Label^ lbl_Email;
	private: System::Windows::Forms::Label^ lbl_Birth;
	private: System::Windows::Forms::Label^ lbl_Gender;
	private: System::Windows::Forms::Label^ lbl_Name;
	private: System::Windows::Forms::Label^ lbl_MemId;
	private: System::Windows::Forms::Button^ btn_Cancle;
	private: System::Windows::Forms::Label^ lbl_Prompt_Auth;
	private: System::Windows::Forms::Label^ lbl_Prompt_Posi;
	private: System::Windows::Forms::Label^ lbl_Prompt_Dept;
	private: System::Windows::Forms::Label^ lbl_Prompt_Wechat;
	private: System::Windows::Forms::Label^ lbl_Prompt_Phone;
	private: System::Windows::Forms::Label^ lbl_Prompt_Gender;
	private: System::Windows::Forms::Button^ btn_Accpet;
	private: System::Windows::Forms::Button^ btn_DeleteInfo;
	private: System::Windows::Forms::Button^ btn_ChangeInfo;
	private: System::Windows::Forms::Label^ lbl_Prompt_Email;
	private: System::Windows::Forms::Label^ lbl_Prompt_Birth;
	private: System::Windows::Forms::Label^ lbl_Prompt_Name;
	private: System::Windows::Forms::Label^ lbl_Prompt_MemId;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfInfoPage;
	private: System::Windows::Forms::Splitter^ splitter2;
	private: System::Windows::Forms::Label^ lbl_Prompt_DataArea;
	private: System::Windows::Forms::Label^ lbl_Error_Data;
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
			this->dgv_Staff = (gcnew System::Windows::Forms::DataGridView());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->lbl_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfId = (gcnew System::Windows::Forms::Label());
			this->cmb_Auth = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_Posi = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_Dept = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_Error = (gcnew System::Windows::Forms::Label());
			this->btn_Close = (gcnew System::Windows::Forms::Button());
			this->btn_Delete = (gcnew System::Windows::Forms::Button());
			this->lbl_Auth = (gcnew System::Windows::Forms::Label());
			this->lbl_Posi = (gcnew System::Windows::Forms::Label());
			this->lbl_Dept = (gcnew System::Windows::Forms::Label());
			this->lbl_Wechat = (gcnew System::Windows::Forms::Label());
			this->lbl_Phone = (gcnew System::Windows::Forms::Label());
			this->lbl_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Birth = (gcnew System::Windows::Forms::Label());
			this->lbl_Gender = (gcnew System::Windows::Forms::Label());
			this->lbl_Name = (gcnew System::Windows::Forms::Label());
			this->lbl_MemId = (gcnew System::Windows::Forms::Label());
			this->btn_Cancle = (gcnew System::Windows::Forms::Button());
			this->lbl_Prompt_Auth = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Posi = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Dept = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Wechat = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Phone = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Gender = (gcnew System::Windows::Forms::Label());
			this->btn_Accpet = (gcnew System::Windows::Forms::Button());
			this->btn_DeleteInfo = (gcnew System::Windows::Forms::Button());
			this->btn_ChangeInfo = (gcnew System::Windows::Forms::Button());
			this->lbl_Prompt_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Birth = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_MemId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfInfoPage = (gcnew System::Windows::Forms::Label());
			this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			this->lbl_Prompt_DataArea = (gcnew System::Windows::Forms::Label());
			this->lbl_Error_Data = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Staff))->BeginInit();
			this->SuspendLayout();
			// 
			// dgv_Staff
			// 
			this->dgv_Staff->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->dgv_Staff->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_Staff->Location = System::Drawing::Point(0, 573);
			this->dgv_Staff->Name = L"dgv_Staff";
			this->dgv_Staff->RowHeadersWidth = 51;
			this->dgv_Staff->RowTemplate->Height = 27;
			this->dgv_Staff->Size = System::Drawing::Size(1373, 253);
			this->dgv_Staff->TabIndex = 71;
			this->dgv_Staff->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &StfInfoPage::dgv_Staff_CellContentClick);
			// 
			// splitter1
			// 
			this->splitter1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->splitter1->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter1->Enabled = false;
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(1374, 501);
			this->splitter1->TabIndex = 79;
			this->splitter1->TabStop = false;
			// 
			// lbl_StfId
			// 
			this->lbl_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_StfId->AutoSize = true;
			this->lbl_StfId->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_StfId->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_StfId->Location = System::Drawing::Point(687, 78);
			this->lbl_StfId->Name = L"lbl_StfId";
			this->lbl_StfId->Size = System::Drawing::Size(23, 15);
			this->lbl_StfId->TabIndex = 112;
			this->lbl_StfId->Text = L"no";
			// 
			// lbl_Prompt_StfId
			// 
			this->lbl_Prompt_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_StfId->AutoSize = true;
			this->lbl_Prompt_StfId->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_StfId->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_StfId->Location = System::Drawing::Point(570, 76);
			this->lbl_Prompt_StfId->Name = L"lbl_Prompt_StfId";
			this->lbl_Prompt_StfId->Size = System::Drawing::Size(97, 19);
			this->lbl_Prompt_StfId->TabIndex = 111;
			this->lbl_Prompt_StfId->Text = L"Staff ID";
			// 
			// cmb_Auth
			// 
			this->cmb_Auth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Auth->FormattingEnabled = true;
			this->cmb_Auth->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Level 1", L"Level 2", L"Level 3", L"Level 4",
					L"Level 5"
			});
			this->cmb_Auth->Location = System::Drawing::Point(1043, 234);
			this->cmb_Auth->Name = L"cmb_Auth";
			this->cmb_Auth->Size = System::Drawing::Size(243, 23);
			this->cmb_Auth->TabIndex = 110;
			this->cmb_Auth->Visible = false;
			// 
			// cmb_Posi
			// 
			this->cmb_Posi->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Posi->FormattingEnabled = true;
			this->cmb_Posi->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Director", L"Manager", L"Staff" });
			this->cmb_Posi->Location = System::Drawing::Point(690, 234);
			this->cmb_Posi->Name = L"cmb_Posi";
			this->cmb_Posi->Size = System::Drawing::Size(243, 23);
			this->cmb_Posi->TabIndex = 109;
			this->cmb_Posi->Visible = false;
			// 
			// cmb_Dept
			// 
			this->cmb_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Dept->FormattingEnabled = true;
			this->cmb_Dept->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"General Administration", L"Information Technology Support",
					L"Career Development Support"
			});
			this->cmb_Dept->Location = System::Drawing::Point(296, 234);
			this->cmb_Dept->Name = L"cmb_Dept";
			this->cmb_Dept->Size = System::Drawing::Size(243, 23);
			this->cmb_Dept->TabIndex = 108;
			this->cmb_Dept->Visible = false;
			// 
			// lbl_Error
			// 
			this->lbl_Error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Error->AutoSize = true;
			this->lbl_Error->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Error->Font = (gcnew System::Drawing::Font(L"SimSun", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Error->ForeColor = System::Drawing::Color::Red;
			this->lbl_Error->Location = System::Drawing::Point(674, 424);
			this->lbl_Error->Name = L"lbl_Error";
			this->lbl_Error->Size = System::Drawing::Size(75, 24);
			this->lbl_Error->TabIndex = 107;
			this->lbl_Error->Text = L"Error";
			this->lbl_Error->Visible = false;
			// 
			// btn_Close
			// 
			this->btn_Close->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Close->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_Close->Location = System::Drawing::Point(849, 415);
			this->btn_Close->Name = L"btn_Close";
			this->btn_Close->Size = System::Drawing::Size(103, 46);
			this->btn_Close->TabIndex = 106;
			this->btn_Close->Text = L"Close";
			this->btn_Close->UseVisualStyleBackColor = true;
			this->btn_Close->Visible = false;
			this->btn_Close->Click += gcnew System::EventHandler(this, &StfInfoPage::btn_Close_Click);
			// 
			// btn_Delete
			// 
			this->btn_Delete->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Delete->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_Delete->Location = System::Drawing::Point(457, 415);
			this->btn_Delete->Name = L"btn_Delete";
			this->btn_Delete->Size = System::Drawing::Size(103, 46);
			this->btn_Delete->TabIndex = 105;
			this->btn_Delete->Text = L"Delete";
			this->btn_Delete->UseVisualStyleBackColor = true;
			this->btn_Delete->Visible = false;
			this->btn_Delete->Click += gcnew System::EventHandler(this, &StfInfoPage::btn_Delete_Click);
			// 
			// lbl_Auth
			// 
			this->lbl_Auth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Auth->AutoSize = true;
			this->lbl_Auth->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Auth->Location = System::Drawing::Point(1040, 237);
			this->lbl_Auth->Name = L"lbl_Auth";
			this->lbl_Auth->Size = System::Drawing::Size(23, 15);
			this->lbl_Auth->TabIndex = 104;
			this->lbl_Auth->Text = L"no";
			// 
			// lbl_Posi
			// 
			this->lbl_Posi->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Posi->AutoSize = true;
			this->lbl_Posi->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Posi->Location = System::Drawing::Point(687, 237);
			this->lbl_Posi->Name = L"lbl_Posi";
			this->lbl_Posi->Size = System::Drawing::Size(23, 15);
			this->lbl_Posi->TabIndex = 103;
			this->lbl_Posi->Text = L"no";
			// 
			// lbl_Dept
			// 
			this->lbl_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Dept->AutoSize = true;
			this->lbl_Dept->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Dept->Location = System::Drawing::Point(293, 237);
			this->lbl_Dept->Name = L"lbl_Dept";
			this->lbl_Dept->Size = System::Drawing::Size(23, 15);
			this->lbl_Dept->TabIndex = 102;
			this->lbl_Dept->Text = L"no";
			// 
			// lbl_Wechat
			// 
			this->lbl_Wechat->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Wechat->AutoSize = true;
			this->lbl_Wechat->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Wechat->Location = System::Drawing::Point(1040, 189);
			this->lbl_Wechat->Name = L"lbl_Wechat";
			this->lbl_Wechat->Size = System::Drawing::Size(23, 15);
			this->lbl_Wechat->TabIndex = 101;
			this->lbl_Wechat->Text = L"no";
			// 
			// lbl_Phone
			// 
			this->lbl_Phone->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Phone->AutoSize = true;
			this->lbl_Phone->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Phone->Location = System::Drawing::Point(687, 189);
			this->lbl_Phone->Name = L"lbl_Phone";
			this->lbl_Phone->Size = System::Drawing::Size(23, 15);
			this->lbl_Phone->TabIndex = 100;
			this->lbl_Phone->Text = L"no";
			// 
			// lbl_Email
			// 
			this->lbl_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Email->AutoSize = true;
			this->lbl_Email->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Email->Location = System::Drawing::Point(293, 189);
			this->lbl_Email->Name = L"lbl_Email";
			this->lbl_Email->Size = System::Drawing::Size(23, 15);
			this->lbl_Email->TabIndex = 99;
			this->lbl_Email->Text = L"no";
			// 
			// lbl_Birth
			// 
			this->lbl_Birth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Birth->AutoSize = true;
			this->lbl_Birth->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Birth->Location = System::Drawing::Point(1040, 135);
			this->lbl_Birth->Name = L"lbl_Birth";
			this->lbl_Birth->Size = System::Drawing::Size(23, 15);
			this->lbl_Birth->TabIndex = 98;
			this->lbl_Birth->Text = L"no";
			// 
			// lbl_Gender
			// 
			this->lbl_Gender->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Gender->AutoSize = true;
			this->lbl_Gender->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Gender->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Gender->Location = System::Drawing::Point(687, 135);
			this->lbl_Gender->Name = L"lbl_Gender";
			this->lbl_Gender->Size = System::Drawing::Size(23, 15);
			this->lbl_Gender->TabIndex = 97;
			this->lbl_Gender->Text = L"no";
			// 
			// lbl_Name
			// 
			this->lbl_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Name->AutoSize = true;
			this->lbl_Name->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Name->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Name->Location = System::Drawing::Point(293, 135);
			this->lbl_Name->Name = L"lbl_Name";
			this->lbl_Name->Size = System::Drawing::Size(23, 15);
			this->lbl_Name->TabIndex = 96;
			this->lbl_Name->Text = L"no";
			// 
			// lbl_MemId
			// 
			this->lbl_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_MemId->AutoSize = true;
			this->lbl_MemId->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_MemId->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_MemId->Location = System::Drawing::Point(293, 78);
			this->lbl_MemId->Name = L"lbl_MemId";
			this->lbl_MemId->Size = System::Drawing::Size(23, 15);
			this->lbl_MemId->TabIndex = 95;
			this->lbl_MemId->Text = L"no";
			// 
			// btn_Cancle
			// 
			this->btn_Cancle->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Cancle->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_Cancle->Location = System::Drawing::Point(1013, 415);
			this->btn_Cancle->Name = L"btn_Cancle";
			this->btn_Cancle->Size = System::Drawing::Size(103, 46);
			this->btn_Cancle->TabIndex = 94;
			this->btn_Cancle->Text = L"Cancle";
			this->btn_Cancle->UseVisualStyleBackColor = true;
			this->btn_Cancle->Visible = false;
			this->btn_Cancle->Click += gcnew System::EventHandler(this, &StfInfoPage::btn_Cancle_Click);
			// 
			// lbl_Prompt_Auth
			// 
			this->lbl_Prompt_Auth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Auth->AutoSize = true;
			this->lbl_Prompt_Auth->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Auth->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Auth->Location = System::Drawing::Point(960, 235);
			this->lbl_Prompt_Auth->Name = L"lbl_Prompt_Auth";
			this->lbl_Prompt_Auth->Size = System::Drawing::Size(53, 19);
			this->lbl_Prompt_Auth->TabIndex = 93;
			this->lbl_Prompt_Auth->Text = L"Auth";
			// 
			// lbl_Prompt_Posi
			// 
			this->lbl_Prompt_Posi->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Posi->AutoSize = true;
			this->lbl_Prompt_Posi->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Posi->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Posi->Location = System::Drawing::Point(570, 235);
			this->lbl_Prompt_Posi->Name = L"lbl_Prompt_Posi";
			this->lbl_Prompt_Posi->Size = System::Drawing::Size(97, 19);
			this->lbl_Prompt_Posi->TabIndex = 92;
			this->lbl_Prompt_Posi->Text = L"Position";
			// 
			// lbl_Prompt_Dept
			// 
			this->lbl_Prompt_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Dept->AutoSize = true;
			this->lbl_Prompt_Dept->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Dept->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Dept->Location = System::Drawing::Point(151, 235);
			this->lbl_Prompt_Dept->Name = L"lbl_Prompt_Dept";
			this->lbl_Prompt_Dept->Size = System::Drawing::Size(119, 19);
			this->lbl_Prompt_Dept->TabIndex = 91;
			this->lbl_Prompt_Dept->Text = L"Department";
			// 
			// lbl_Prompt_Wechat
			// 
			this->lbl_Prompt_Wechat->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Wechat->AutoSize = true;
			this->lbl_Prompt_Wechat->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Wechat->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Wechat->Location = System::Drawing::Point(938, 187);
			this->lbl_Prompt_Wechat->Name = L"lbl_Prompt_Wechat";
			this->lbl_Prompt_Wechat->Size = System::Drawing::Size(75, 19);
			this->lbl_Prompt_Wechat->TabIndex = 90;
			this->lbl_Prompt_Wechat->Text = L"Wechat";
			// 
			// lbl_Prompt_Phone
			// 
			this->lbl_Prompt_Phone->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Phone->AutoSize = true;
			this->lbl_Prompt_Phone->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Phone->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Phone->Location = System::Drawing::Point(603, 187);
			this->lbl_Prompt_Phone->Name = L"lbl_Prompt_Phone";
			this->lbl_Prompt_Phone->Size = System::Drawing::Size(64, 19);
			this->lbl_Prompt_Phone->TabIndex = 89;
			this->lbl_Prompt_Phone->Text = L"Phone";
			// 
			// lbl_Prompt_Gender
			// 
			this->lbl_Prompt_Gender->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Gender->AutoSize = true;
			this->lbl_Prompt_Gender->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Gender->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Gender->Location = System::Drawing::Point(592, 133);
			this->lbl_Prompt_Gender->Name = L"lbl_Prompt_Gender";
			this->lbl_Prompt_Gender->Size = System::Drawing::Size(75, 19);
			this->lbl_Prompt_Gender->TabIndex = 88;
			this->lbl_Prompt_Gender->Text = L"Gender";
			// 
			// btn_Accpet
			// 
			this->btn_Accpet->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Accpet->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_Accpet->Location = System::Drawing::Point(282, 415);
			this->btn_Accpet->Name = L"btn_Accpet";
			this->btn_Accpet->Size = System::Drawing::Size(103, 46);
			this->btn_Accpet->TabIndex = 87;
			this->btn_Accpet->Text = L"Accept";
			this->btn_Accpet->UseVisualStyleBackColor = true;
			this->btn_Accpet->Visible = false;
			this->btn_Accpet->Click += gcnew System::EventHandler(this, &StfInfoPage::btn_Accpet_Click);
			// 
			// btn_DeleteInfo
			// 
			this->btn_DeleteInfo->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_DeleteInfo->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_DeleteInfo->Location = System::Drawing::Point(790, 306);
			this->btn_DeleteInfo->Name = L"btn_DeleteInfo";
			this->btn_DeleteInfo->Size = System::Drawing::Size(223, 64);
			this->btn_DeleteInfo->TabIndex = 86;
			this->btn_DeleteInfo->Text = L"Delete Information";
			this->btn_DeleteInfo->UseVisualStyleBackColor = true;
			this->btn_DeleteInfo->Click += gcnew System::EventHandler(this, &StfInfoPage::btn_DeleteInfo_Click);
			// 
			// btn_ChangeInfo
			// 
			this->btn_ChangeInfo->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_ChangeInfo->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_ChangeInfo->Location = System::Drawing::Point(444, 306);
			this->btn_ChangeInfo->Name = L"btn_ChangeInfo";
			this->btn_ChangeInfo->Size = System::Drawing::Size(223, 64);
			this->btn_ChangeInfo->TabIndex = 85;
			this->btn_ChangeInfo->Text = L"Edit Information";
			this->btn_ChangeInfo->UseVisualStyleBackColor = true;
			this->btn_ChangeInfo->Click += gcnew System::EventHandler(this, &StfInfoPage::btn_ChangeInfo_Click);
			// 
			// lbl_Prompt_Email
			// 
			this->lbl_Prompt_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Email->AutoSize = true;
			this->lbl_Prompt_Email->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Email->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Email->Location = System::Drawing::Point(206, 187);
			this->lbl_Prompt_Email->Name = L"lbl_Prompt_Email";
			this->lbl_Prompt_Email->Size = System::Drawing::Size(64, 19);
			this->lbl_Prompt_Email->TabIndex = 84;
			this->lbl_Prompt_Email->Text = L"Email";
			// 
			// lbl_Prompt_Birth
			// 
			this->lbl_Prompt_Birth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Birth->AutoSize = true;
			this->lbl_Prompt_Birth->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Birth->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Birth->Location = System::Drawing::Point(916, 133);
			this->lbl_Prompt_Birth->Name = L"lbl_Prompt_Birth";
			this->lbl_Prompt_Birth->Size = System::Drawing::Size(97, 19);
			this->lbl_Prompt_Birth->TabIndex = 83;
			this->lbl_Prompt_Birth->Text = L"Birthday";
			// 
			// lbl_Prompt_Name
			// 
			this->lbl_Prompt_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Name->AutoSize = true;
			this->lbl_Prompt_Name->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_Name->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Name->Location = System::Drawing::Point(217, 133);
			this->lbl_Prompt_Name->Name = L"lbl_Prompt_Name";
			this->lbl_Prompt_Name->Size = System::Drawing::Size(53, 19);
			this->lbl_Prompt_Name->TabIndex = 82;
			this->lbl_Prompt_Name->Text = L"Name";
			// 
			// lbl_Prompt_MemId
			// 
			this->lbl_Prompt_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_MemId->AutoSize = true;
			this->lbl_Prompt_MemId->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_MemId->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_MemId->Location = System::Drawing::Point(162, 76);
			this->lbl_Prompt_MemId->Name = L"lbl_Prompt_MemId";
			this->lbl_Prompt_MemId->Size = System::Drawing::Size(108, 19);
			this->lbl_Prompt_MemId->TabIndex = 81;
			this->lbl_Prompt_MemId->Text = L"Member ID";
			// 
			// lbl_Prompt_StfInfoPage
			// 
			this->lbl_Prompt_StfInfoPage->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_StfInfoPage->AutoSize = true;
			this->lbl_Prompt_StfInfoPage->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->lbl_Prompt_StfInfoPage->Font = (gcnew System::Drawing::Font(L"SimSun", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_StfInfoPage->Location = System::Drawing::Point(536, 9);
			this->lbl_Prompt_StfInfoPage->Name = L"lbl_Prompt_StfInfoPage";
			this->lbl_Prompt_StfInfoPage->Size = System::Drawing::Size(320, 25);
			this->lbl_Prompt_StfInfoPage->TabIndex = 80;
			this->lbl_Prompt_StfInfoPage->Text = L"Staff Information Page";
			// 
			// splitter2
			// 
			this->splitter2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->splitter2->Dock = System::Windows::Forms::DockStyle::Top;
			this->splitter2->Location = System::Drawing::Point(0, 501);
			this->splitter2->Name = L"splitter2";
			this->splitter2->Size = System::Drawing::Size(1374, 71);
			this->splitter2->TabIndex = 114;
			this->splitter2->TabStop = false;
			// 
			// lbl_Prompt_DataArea
			// 
			this->lbl_Prompt_DataArea->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_DataArea->AutoSize = true;
			this->lbl_Prompt_DataArea->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->lbl_Prompt_DataArea->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_DataArea->Location = System::Drawing::Point(650, 529);
			this->lbl_Prompt_DataArea->Name = L"lbl_Prompt_DataArea";
			this->lbl_Prompt_DataArea->Size = System::Drawing::Size(108, 19);
			this->lbl_Prompt_DataArea->TabIndex = 115;
			this->lbl_Prompt_DataArea->Text = L"Data Area";
			// 
			// lbl_Error_Data
			// 
			this->lbl_Error_Data->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Error_Data->AutoSize = true;
			this->lbl_Error_Data->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->lbl_Error_Data->Font = (gcnew System::Drawing::Font(L"SimSun", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Error_Data->ForeColor = System::Drawing::Color::Red;
			this->lbl_Error_Data->Location = System::Drawing::Point(650, 606);
			this->lbl_Error_Data->Name = L"lbl_Error_Data";
			this->lbl_Error_Data->Size = System::Drawing::Size(101, 24);
			this->lbl_Error_Data->TabIndex = 116;
			this->lbl_Error_Data->Text = L"No Data";
			this->lbl_Error_Data->Visible = false;
			// 
			// StfInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1374, 824);
			this->Controls->Add(this->lbl_Error_Data);
			this->Controls->Add(this->lbl_Prompt_DataArea);
			this->Controls->Add(this->splitter2);
			this->Controls->Add(this->lbl_StfId);
			this->Controls->Add(this->lbl_Prompt_StfId);
			this->Controls->Add(this->cmb_Auth);
			this->Controls->Add(this->cmb_Posi);
			this->Controls->Add(this->cmb_Dept);
			this->Controls->Add(this->lbl_Error);
			this->Controls->Add(this->btn_Close);
			this->Controls->Add(this->btn_Delete);
			this->Controls->Add(this->lbl_Auth);
			this->Controls->Add(this->lbl_Posi);
			this->Controls->Add(this->lbl_Dept);
			this->Controls->Add(this->lbl_Wechat);
			this->Controls->Add(this->lbl_Phone);
			this->Controls->Add(this->lbl_Email);
			this->Controls->Add(this->lbl_Birth);
			this->Controls->Add(this->lbl_Gender);
			this->Controls->Add(this->lbl_Name);
			this->Controls->Add(this->lbl_MemId);
			this->Controls->Add(this->btn_Cancle);
			this->Controls->Add(this->lbl_Prompt_Auth);
			this->Controls->Add(this->lbl_Prompt_Posi);
			this->Controls->Add(this->lbl_Prompt_Dept);
			this->Controls->Add(this->lbl_Prompt_Wechat);
			this->Controls->Add(this->lbl_Prompt_Phone);
			this->Controls->Add(this->lbl_Prompt_Gender);
			this->Controls->Add(this->btn_Accpet);
			this->Controls->Add(this->btn_DeleteInfo);
			this->Controls->Add(this->btn_ChangeInfo);
			this->Controls->Add(this->lbl_Prompt_Email);
			this->Controls->Add(this->lbl_Prompt_Birth);
			this->Controls->Add(this->lbl_Prompt_Name);
			this->Controls->Add(this->lbl_Prompt_MemId);
			this->Controls->Add(this->lbl_Prompt_StfInfoPage);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->dgv_Staff);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"StfInfoPage";
			this->Text = L"Staff Information Page";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_Staff))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:
		int^ _MemId;
		int _StfId;
		PublicUserInfo::Auth _Auth;
		PublicUserInfo^ _pui;
		Database^ _database;

	private:
		Void CheckAuth();
		Void UpdateInfo();
		Void Initialize();
		Void UpdateDataGridView();
		Void ChangeTxtVisible();
		Void ChangeTxtInvisible();
		Void ChangeLabelVisible();
		Void ChangeLabelInvisible();
		Void AuthInvisible();
		Void DeleteRecord();
		Void dgv_Staff_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		Void btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Accpet_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Cancle_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_DeleteInfo_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Delete_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Close_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
