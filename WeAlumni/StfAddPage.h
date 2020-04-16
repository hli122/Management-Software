#pragma once
#include "Database.h"
#include "PublicUserInfo.h"

/*
 * StfAddPage.h
 *
 * This file includes functions of inserting new data into Staff table
 *
 * @author: Rui Jia
 * Revised: 4/4/20
 *          4/15/20 use PublicUserInfo
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
	/// Summary for StfAddPage
	/// </summary>
	public ref class StfAddPage : public System::Windows::Forms::Form
	{
	public:
		StfAddPage(void)
		{
			InitializeComponent();
			Initialize();
		}

		StfAddPage(PublicUserInfo^ pui) {
			InitializeComponent();
			Initialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StfAddPage()
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
	private: System::Windows::Forms::Label^ lbl_Prompt_StfAddPage;
	private: System::Windows::Forms::TextBox^ txt_MemId;
	private: System::Windows::Forms::Label^ lbl_Prompt_MemId;
	private: System::Windows::Forms::Label^ lbl_Prompt_Name;
	private: System::Windows::Forms::TextBox^ txt_Name;
	private: System::Windows::Forms::Label^ lbl_Prompt_Dept;
	private: System::Windows::Forms::Label^ lbl_Prompt_Posi;
	private: System::Windows::Forms::Label^ lbl_Prompt_Auth;
	private: System::Windows::Forms::ComboBox^ cmb_Dept;
	private: System::Windows::Forms::ComboBox^ cmb_Posi;
	private: System::Windows::Forms::ComboBox^ cmb_Auth;
	private: System::Windows::Forms::Button^ btn_Confirm;
	private: System::Windows::Forms::Button^ btn_Cancel;
	private: System::Windows::Forms::Button^ btn_Verify;
	private: System::Windows::Forms::Label^ lbl_Error;
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
			this->lbl_Prompt_StfAddPage = (gcnew System::Windows::Forms::Label());
			this->txt_MemId = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_MemId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			this->txt_Name = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Dept = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Posi = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Auth = (gcnew System::Windows::Forms::Label());
			this->cmb_Dept = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_Posi = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_Auth = (gcnew System::Windows::Forms::ComboBox());
			this->btn_Confirm = (gcnew System::Windows::Forms::Button());
			this->btn_Cancel = (gcnew System::Windows::Forms::Button());
			this->btn_Verify = (gcnew System::Windows::Forms::Button());
			this->lbl_Error = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_Prompt_StfAddPage
			// 
			this->lbl_Prompt_StfAddPage->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_StfAddPage->AutoSize = true;
			this->lbl_Prompt_StfAddPage->Font = (gcnew System::Drawing::Font(L"SimSun", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_StfAddPage->Location = System::Drawing::Point(377, 54);
			this->lbl_Prompt_StfAddPage->Name = L"lbl_Prompt_StfAddPage";
			this->lbl_Prompt_StfAddPage->Size = System::Drawing::Size(208, 25);
			this->lbl_Prompt_StfAddPage->TabIndex = 0;
			this->lbl_Prompt_StfAddPage->Text = L"Staff Add Page";
			// 
			// txt_MemId
			// 
			this->txt_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_MemId->Location = System::Drawing::Point(249, 120);
			this->txt_MemId->Name = L"txt_MemId";
			this->txt_MemId->Size = System::Drawing::Size(95, 25);
			this->txt_MemId->TabIndex = 2;
			// 
			// lbl_Prompt_MemId
			// 
			this->lbl_Prompt_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_MemId->AutoSize = true;
			this->lbl_Prompt_MemId->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_MemId->Location = System::Drawing::Point(120, 121);
			this->lbl_Prompt_MemId->Name = L"lbl_Prompt_MemId";
			this->lbl_Prompt_MemId->Size = System::Drawing::Size(108, 19);
			this->lbl_Prompt_MemId->TabIndex = 3;
			this->lbl_Prompt_MemId->Text = L"Member ID";
			// 
			// lbl_Prompt_Name
			// 
			this->lbl_Prompt_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Name->AutoSize = true;
			this->lbl_Prompt_Name->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Name->Location = System::Drawing::Point(394, 121);
			this->lbl_Prompt_Name->Name = L"lbl_Prompt_Name";
			this->lbl_Prompt_Name->Size = System::Drawing::Size(130, 19);
			this->lbl_Prompt_Name->TabIndex = 4;
			this->lbl_Prompt_Name->Text = L"Member Name";
			// 
			// txt_Name
			// 
			this->txt_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Name->Location = System::Drawing::Point(557, 120);
			this->txt_Name->Name = L"txt_Name";
			this->txt_Name->Size = System::Drawing::Size(100, 25);
			this->txt_Name->TabIndex = 5;
			// 
			// lbl_Prompt_Dept
			// 
			this->lbl_Prompt_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Dept->AutoSize = true;
			this->lbl_Prompt_Dept->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Dept->Location = System::Drawing::Point(109, 174);
			this->lbl_Prompt_Dept->Name = L"lbl_Prompt_Dept";
			this->lbl_Prompt_Dept->Size = System::Drawing::Size(119, 19);
			this->lbl_Prompt_Dept->TabIndex = 6;
			this->lbl_Prompt_Dept->Text = L"Department";
			// 
			// lbl_Prompt_Posi
			// 
			this->lbl_Prompt_Posi->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Posi->AutoSize = true;
			this->lbl_Prompt_Posi->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Posi->Location = System::Drawing::Point(131, 228);
			this->lbl_Prompt_Posi->Name = L"lbl_Prompt_Posi";
			this->lbl_Prompt_Posi->Size = System::Drawing::Size(97, 19);
			this->lbl_Prompt_Posi->TabIndex = 7;
			this->lbl_Prompt_Posi->Text = L"Position";
			// 
			// lbl_Prompt_Auth
			// 
			this->lbl_Prompt_Auth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Auth->AutoSize = true;
			this->lbl_Prompt_Auth->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Auth->Location = System::Drawing::Point(109, 279);
			this->lbl_Prompt_Auth->Name = L"lbl_Prompt_Auth";
			this->lbl_Prompt_Auth->Size = System::Drawing::Size(119, 19);
			this->lbl_Prompt_Auth->TabIndex = 8;
			this->lbl_Prompt_Auth->Text = L"Auth Level";
			// 
			// cmb_Dept
			// 
			this->cmb_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Dept->Enabled = false;
			this->cmb_Dept->FormattingEnabled = true;
			this->cmb_Dept->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"General Administration", L"Information Technology Support",
					L"Career Development Support"
			});
			this->cmb_Dept->Location = System::Drawing::Point(249, 173);
			this->cmb_Dept->Name = L"cmb_Dept";
			this->cmb_Dept->Size = System::Drawing::Size(275, 23);
			this->cmb_Dept->TabIndex = 9;
			// 
			// cmb_Posi
			// 
			this->cmb_Posi->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Posi->Enabled = false;
			this->cmb_Posi->FormattingEnabled = true;
			this->cmb_Posi->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Director", L"Manager", L"Staff" });
			this->cmb_Posi->Location = System::Drawing::Point(249, 227);
			this->cmb_Posi->Name = L"cmb_Posi";
			this->cmb_Posi->Size = System::Drawing::Size(275, 23);
			this->cmb_Posi->TabIndex = 10;
			// 
			// cmb_Auth
			// 
			this->cmb_Auth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Auth->Enabled = false;
			this->cmb_Auth->FormattingEnabled = true;
			this->cmb_Auth->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Level 1", L"Level 2", L"Level 3", L"Level 4",
					L"Level 5"
			});
			this->cmb_Auth->Location = System::Drawing::Point(249, 278);
			this->cmb_Auth->Name = L"cmb_Auth";
			this->cmb_Auth->Size = System::Drawing::Size(275, 23);
			this->cmb_Auth->TabIndex = 11;
			// 
			// btn_Confirm
			// 
			this->btn_Confirm->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Confirm->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_Confirm->Location = System::Drawing::Point(90, 427);
			this->btn_Confirm->Name = L"btn_Confirm";
			this->btn_Confirm->Size = System::Drawing::Size(223, 64);
			this->btn_Confirm->TabIndex = 12;
			this->btn_Confirm->Text = L"Confirm";
			this->btn_Confirm->UseVisualStyleBackColor = true;
			this->btn_Confirm->Visible = false;
			this->btn_Confirm->Click += gcnew System::EventHandler(this, &StfAddPage::Confirm_Click);
			// 
			// btn_Cancel
			// 
			this->btn_Cancel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Cancel->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_Cancel->Location = System::Drawing::Point(343, 427);
			this->btn_Cancel->Name = L"btn_Cancel";
			this->btn_Cancel->Size = System::Drawing::Size(223, 64);
			this->btn_Cancel->TabIndex = 13;
			this->btn_Cancel->Text = L"Cancel";
			this->btn_Cancel->UseVisualStyleBackColor = true;
			this->btn_Cancel->Visible = false;
			this->btn_Cancel->Click += gcnew System::EventHandler(this, &StfAddPage::Cancel_Click);
			// 
			// btn_Verify
			// 
			this->btn_Verify->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Verify->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_Verify->Location = System::Drawing::Point(591, 427);
			this->btn_Verify->Name = L"btn_Verify";
			this->btn_Verify->Size = System::Drawing::Size(223, 64);
			this->btn_Verify->TabIndex = 14;
			this->btn_Verify->Text = L"Verify Information";
			this->btn_Verify->UseVisualStyleBackColor = true;
			this->btn_Verify->Click += gcnew System::EventHandler(this, &StfAddPage::Verify_Click);
			// 
			// lbl_Error
			// 
			this->lbl_Error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Error->AutoSize = true;
			this->lbl_Error->Font = (gcnew System::Drawing::Font(L"SimSun", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Error->ForeColor = System::Drawing::Color::Red;
			this->lbl_Error->Location = System::Drawing::Point(422, 352);
			this->lbl_Error->Name = L"lbl_Error";
			this->lbl_Error->Size = System::Drawing::Size(75, 24);
			this->lbl_Error->TabIndex = 15;
			this->lbl_Error->Text = L"ERROR";
			this->lbl_Error->Visible = false;
			// 
			// StfAddPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(931, 599);
			this->Controls->Add(this->lbl_Error);
			this->Controls->Add(this->btn_Verify);
			this->Controls->Add(this->btn_Cancel);
			this->Controls->Add(this->btn_Confirm);
			this->Controls->Add(this->cmb_Auth);
			this->Controls->Add(this->cmb_Posi);
			this->Controls->Add(this->cmb_Dept);
			this->Controls->Add(this->lbl_Prompt_Auth);
			this->Controls->Add(this->lbl_Prompt_Posi);
			this->Controls->Add(this->lbl_Prompt_Dept);
			this->Controls->Add(this->txt_Name);
			this->Controls->Add(this->lbl_Prompt_Name);
			this->Controls->Add(this->lbl_Prompt_MemId);
			this->Controls->Add(this->txt_MemId);
			this->Controls->Add(this->lbl_Prompt_StfAddPage);
			this->Name = L"StfAddPage";
			this->Text = L"StfAddPage";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private:
		int _StfId;
		Database^ _database;

	private:
		Void Initialize();
		Void Verify_Click(System::Object^ sender, System::EventArgs^ e);
		Void InsertStaff();
		Void Confirm_Click(System::Object^ sender, System::EventArgs^ e);
		Void Cancel_Click(System::Object^ sender, System::EventArgs^ e);
		Void AddNewRecord();
	};
}
