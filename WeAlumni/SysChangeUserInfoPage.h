#pragma once
#include "Database.h"
#include "PublicUserInfo.h"

/*
 * SysChangeUserInfoPage.h
 *
 * This file have basic username/password interaction actions.
 *
 * @author: Rui Jia
 * Revised: 4/12/20
			4/25/20 changed English to Chinese
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
	/// Summary for SysChangeUserInfoPage
	/// </summary>
	public ref class SysChangeUserInfoPage : public System::Windows::Forms::Form
	{
	public:
		SysChangeUserInfoPage(int stfId)
		{
			InitializeComponent();
			_stfId = stfId;
			Initialize();
			//
			//TODO: Add the constructor code here
			//
		}
		SysChangeUserInfoPage(PublicUserInfo^ pui) {
			InitializeComponent();
			_stfId = pui->GetId();
			Initialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SysChangeUserInfoPage()
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
	private: System::Windows::Forms::Label^ lbl_prompt_changeUser;
	private: System::Windows::Forms::Label^ lbl_prompt_changePass;
	private: System::Windows::Forms::TextBox^ txt_changeUser;
	private: System::Windows::Forms::TextBox^ txt_changePass;
	private: System::Windows::Forms::Button^ btn_Confirm;
	private: System::Windows::Forms::Button^ btn_Cancle;
	private: System::Windows::Forms::Label^ lbl_Error;
	private: System::Windows::Forms::Label^ label1;
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
			this->lbl_prompt_changeUser = (gcnew System::Windows::Forms::Label());
			this->lbl_prompt_changePass = (gcnew System::Windows::Forms::Label());
			this->txt_changeUser = (gcnew System::Windows::Forms::TextBox());
			this->txt_changePass = (gcnew System::Windows::Forms::TextBox());
			this->btn_Confirm = (gcnew System::Windows::Forms::Button());
			this->btn_Cancle = (gcnew System::Windows::Forms::Button());
			this->lbl_Error = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_prompt_changeUser
			// 
			this->lbl_prompt_changeUser->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_prompt_changeUser->AutoSize = true;
			this->lbl_prompt_changeUser->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_prompt_changeUser->Location = System::Drawing::Point(29, 94);
			this->lbl_prompt_changeUser->Name = L"lbl_prompt_changeUser";
			this->lbl_prompt_changeUser->Size = System::Drawing::Size(149, 19);
			this->lbl_prompt_changeUser->TabIndex = 0;
			this->lbl_prompt_changeUser->Text = L"（更改）用户名";
			// 
			// lbl_prompt_changePass
			// 
			this->lbl_prompt_changePass->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_prompt_changePass->AutoSize = true;
			this->lbl_prompt_changePass->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_prompt_changePass->Location = System::Drawing::Point(29, 163);
			this->lbl_prompt_changePass->Name = L"lbl_prompt_changePass";
			this->lbl_prompt_changePass->Size = System::Drawing::Size(129, 19);
			this->lbl_prompt_changePass->TabIndex = 1;
			this->lbl_prompt_changePass->Text = L"（更改）密码";
			// 
			// txt_changeUser
			// 
			this->txt_changeUser->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_changeUser->Location = System::Drawing::Point(242, 93);
			this->txt_changeUser->Name = L"txt_changeUser";
			this->txt_changeUser->Size = System::Drawing::Size(100, 25);
			this->txt_changeUser->TabIndex = 2;
			// 
			// txt_changePass
			// 
			this->txt_changePass->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_changePass->Location = System::Drawing::Point(242, 162);
			this->txt_changePass->Name = L"txt_changePass";
			this->txt_changePass->Size = System::Drawing::Size(100, 25);
			this->txt_changePass->TabIndex = 3;
			// 
			// btn_Confirm
			// 
			this->btn_Confirm->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Confirm->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_Confirm->Location = System::Drawing::Point(33, 267);
			this->btn_Confirm->Name = L"btn_Confirm";
			this->btn_Confirm->Size = System::Drawing::Size(223, 64);
			this->btn_Confirm->TabIndex = 4;
			this->btn_Confirm->Text = L"确认更改";
			this->btn_Confirm->UseVisualStyleBackColor = true;
			this->btn_Confirm->Click += gcnew System::EventHandler(this, &SysChangeUserInfoPage::btn_Confirm_Click);
			// 
			// btn_Cancle
			// 
			this->btn_Cancle->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Cancle->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_Cancle->Location = System::Drawing::Point(274, 267);
			this->btn_Cancle->Name = L"btn_Cancle";
			this->btn_Cancle->Size = System::Drawing::Size(223, 64);
			this->btn_Cancle->TabIndex = 5;
			this->btn_Cancle->Text = L"取消更改";
			this->btn_Cancle->UseVisualStyleBackColor = true;
			this->btn_Cancle->Click += gcnew System::EventHandler(this, &SysChangeUserInfoPage::btn_Cancle_Click);
			// 
			// lbl_Error
			// 
			this->lbl_Error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Error->AutoSize = true;
			this->lbl_Error->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Error->ForeColor = System::Drawing::Color::Red;
			this->lbl_Error->Location = System::Drawing::Point(238, 227);
			this->lbl_Error->Name = L"lbl_Error";
			this->lbl_Error->Size = System::Drawing::Size(49, 19);
			this->lbl_Error->TabIndex = 6;
			this->lbl_Error->Text = L"错误";
			this->lbl_Error->Visible = false;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"SimSun", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(205, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 25);
			this->label1->TabIndex = 7;
			this->label1->Text = L"修改信息";
			// 
			// SysChangeUserInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(568, 417);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbl_Error);
			this->Controls->Add(this->btn_Cancle);
			this->Controls->Add(this->btn_Confirm);
			this->Controls->Add(this->txt_changePass);
			this->Controls->Add(this->txt_changeUser);
			this->Controls->Add(this->lbl_prompt_changePass);
			this->Controls->Add(this->lbl_prompt_changeUser);
			this->Name = L"SysChangeUserInfoPage";
			this->Text = L"修改用户信息页面";
			this->ResumeLayout(false);
			this->PerformLayout();
		}

	private:
		int _stfId;
		Database^ _database;

	private:
		Void Initialize();
		Void UpdateInfo();
		Void btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Cancle_Click(System::Object^ sender, System::EventArgs^ e);
#pragma endregion
	};
}
