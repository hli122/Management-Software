#pragma once
#include "database.h"
#include "MainWindow.h"
#include "DatabasePrecheck.h"
#include "SysForgotPassword.h"
#include "PublicUserInfo.h"

namespace WeAlumni {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// LoginPage 摘要
	/// </summary>
	public ref class LoginPage : public System::Windows::Forms::Form
	{
	public:
		LoginPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Initialize();
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~LoginPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_Prompt_Title;
	protected:
	private: System::Windows::Forms::Label^ lbl_Prompt_Username;
	private: System::Windows::Forms::Label^ lbl_Prompt_Password;
	private: System::Windows::Forms::TextBox^ txt_Username;
	private: System::Windows::Forms::TextBox^ txt_Password;
	private: System::Windows::Forms::Button^ btn_Login;
	private: System::Windows::Forms::Button^ btn_Clear;

	private: System::Windows::Forms::Button^ btn_Remember;
	private: System::Windows::Forms::Button^ btn_forgotpswd;

	private: System::Windows::Forms::Label^ lbl_DBError;
	private: System::Windows::Forms::Label^ lbl_PasswordStars;

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
			this->lbl_Prompt_Title = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Username = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Password = (gcnew System::Windows::Forms::Label());
			this->txt_Username = (gcnew System::Windows::Forms::TextBox());
			this->txt_Password = (gcnew System::Windows::Forms::TextBox());
			this->btn_Login = (gcnew System::Windows::Forms::Button());
			this->btn_Clear = (gcnew System::Windows::Forms::Button());
			this->btn_Remember = (gcnew System::Windows::Forms::Button());
			this->btn_forgotpswd = (gcnew System::Windows::Forms::Button());
			this->lbl_DBError = (gcnew System::Windows::Forms::Label());
			this->lbl_PasswordStars = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_Prompt_Title
			// 
			this->lbl_Prompt_Title->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Title->AutoSize = true;
			this->lbl_Prompt_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Title->Location = System::Drawing::Point(301, 9);
			this->lbl_Prompt_Title->Name = L"lbl_Prompt_Title";
			this->lbl_Prompt_Title->Size = System::Drawing::Size(146, 29);
			this->lbl_Prompt_Title->TabIndex = 0;
			this->lbl_Prompt_Title->Text = L"Login Page";
			// 
			// lbl_Prompt_Username
			// 
			this->lbl_Prompt_Username->AutoSize = true;
			this->lbl_Prompt_Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Username->Location = System::Drawing::Point(113, 122);
			this->lbl_Prompt_Username->Name = L"lbl_Prompt_Username";
			this->lbl_Prompt_Username->Size = System::Drawing::Size(117, 25);
			this->lbl_Prompt_Username->TabIndex = 1;
			this->lbl_Prompt_Username->Text = L"Username:";
			// 
			// lbl_Prompt_Password
			// 
			this->lbl_Prompt_Password->AutoSize = true;
			this->lbl_Prompt_Password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Password->Location = System::Drawing::Point(113, 187);
			this->lbl_Prompt_Password->Name = L"lbl_Prompt_Password";
			this->lbl_Prompt_Password->Size = System::Drawing::Size(113, 25);
			this->lbl_Prompt_Password->TabIndex = 2;
			this->lbl_Prompt_Password->Text = L"Password:";
			// 
			// txt_Username
			// 
			this->txt_Username->Location = System::Drawing::Point(248, 126);
			this->txt_Username->Name = L"txt_Username";
			this->txt_Username->Size = System::Drawing::Size(181, 22);
			this->txt_Username->TabIndex = 3;
			// 
			// txt_Password
			// 
			this->txt_Password->Location = System::Drawing::Point(248, 189);
			this->txt_Password->Name = L"txt_Password";
			this->txt_Password->Size = System::Drawing::Size(181, 22);
			this->txt_Password->TabIndex = 4;
			// 
			// btn_Login
			// 
			this->btn_Login->Location = System::Drawing::Point(248, 281);
			this->btn_Login->Name = L"btn_Login";
			this->btn_Login->Size = System::Drawing::Size(89, 41);
			this->btn_Login->TabIndex = 6;
			this->btn_Login->Text = L"Login";
			this->btn_Login->UseVisualStyleBackColor = true;
			this->btn_Login->Click += gcnew System::EventHandler(this, &LoginPage::Login_Click);
			// 
			// btn_Clear
			// 
			this->btn_Clear->Location = System::Drawing::Point(431, 281);
			this->btn_Clear->Name = L"btn_Clear";
			this->btn_Clear->Size = System::Drawing::Size(89, 41);
			this->btn_Clear->TabIndex = 7;
			this->btn_Clear->Text = L"Clear";
			this->btn_Clear->UseVisualStyleBackColor = true;
			this->btn_Clear->Click += gcnew System::EventHandler(this, &LoginPage::Clear_Click);
			// 
			// btn_Remember
			// 
			this->btn_Remember->Location = System::Drawing::Point(248, 340);
			this->btn_Remember->Name = L"btn_Remember";
			this->btn_Remember->Size = System::Drawing::Size(89, 45);
			this->btn_Remember->TabIndex = 8;
			this->btn_Remember->Text = L"Remember Password";
			this->btn_Remember->UseVisualStyleBackColor = true;
			this->btn_Remember->Click += gcnew System::EventHandler(this, &LoginPage::Remember_Click);
			// 
			// btn_forgotpswd
			// 
			this->btn_forgotpswd->Location = System::Drawing::Point(431, 340);
			this->btn_forgotpswd->Name = L"btn_forgotpswd";
			this->btn_forgotpswd->Size = System::Drawing::Size(89, 45);
			this->btn_forgotpswd->TabIndex = 9;
			this->btn_forgotpswd->Text = L"Forgot Password";
			this->btn_forgotpswd->UseVisualStyleBackColor = true;
			this->btn_forgotpswd->Click += gcnew System::EventHandler(this, &LoginPage::Forgot_Click);
			// 
			// lbl_DBError
			// 
			this->lbl_DBError->AutoSize = true;
			this->lbl_DBError->Location = System::Drawing::Point(350, 238);
			this->lbl_DBError->Name = L"lbl_DBError";
			this->lbl_DBError->Size = System::Drawing::Size(40, 17);
			this->lbl_DBError->TabIndex = 10;
			this->lbl_DBError->Text = L"Error";
			this->lbl_DBError->Visible = false;
			// 
			// lbl_PasswordStars
			// 
			this->lbl_PasswordStars->AutoSize = true;
			this->lbl_PasswordStars->Location = System::Drawing::Point(248, 194);
			this->lbl_PasswordStars->Name = L"lbl_PasswordStars";
			this->lbl_PasswordStars->Size = System::Drawing::Size(38, 17);
			this->lbl_PasswordStars->TabIndex = 11;
			this->lbl_PasswordStars->Text = L"******";
			this->lbl_PasswordStars->Visible = false;
			// 
			// LoginPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(734, 427);
			this->Controls->Add(this->lbl_PasswordStars);
			this->Controls->Add(this->lbl_DBError);
			this->Controls->Add(this->btn_forgotpswd);
			this->Controls->Add(this->btn_Remember);
			this->Controls->Add(this->btn_Clear);
			this->Controls->Add(this->btn_Login);
			this->Controls->Add(this->txt_Password);
			this->Controls->Add(this->txt_Username);
			this->Controls->Add(this->lbl_Prompt_Password);
			this->Controls->Add(this->lbl_Prompt_Username);
			this->Controls->Add(this->lbl_Prompt_Title);
			this->Name = L"LoginPage";
			this->Text = L"LoginPage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		Database^ _database;
		PublicUserInfo^ _publicUserInfo;
		int^ _StfId;
	private:  
		System::Void Initialize();
		Void WeAlumni::LoginPage::ShowDefault();
		Void WeAlumni::LoginPage::JumpToMain();
		Void WeAlumni::LoginPage::Login_Click(System::Object^ sender, System::EventArgs^ e);
		Void WeAlumni::LoginPage::Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void WeAlumni::LoginPage::Forgot_Click(System::Object^ sender, System::EventArgs^ e);
		Void WeAlumni::LoginPage::Remember_Click(System::Object^ sender, System::EventArgs^ e);
	};
}

