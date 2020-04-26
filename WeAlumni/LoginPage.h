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



	private: System::Windows::Forms::Button^ btn_forgotpswd;

	private: System::Windows::Forms::Label^ lbl_DBError;
	private: System::Windows::Forms::CheckBox^ cbox_Remember;


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
			this->btn_forgotpswd = (gcnew System::Windows::Forms::Button());
			this->lbl_DBError = (gcnew System::Windows::Forms::Label());
			this->cbox_Remember = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// lbl_Prompt_Title
			// 
			this->lbl_Prompt_Title->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Title->AutoSize = true;
			this->lbl_Prompt_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Title->Location = System::Drawing::Point(272, 37);
			this->lbl_Prompt_Title->Name = L"lbl_Prompt_Title";
			this->lbl_Prompt_Title->Size = System::Drawing::Size(113, 29);
			this->lbl_Prompt_Title->TabIndex = 0;
			this->lbl_Prompt_Title->Text = L"用户登录";
			// 
			// lbl_Prompt_Username
			// 
			this->lbl_Prompt_Username->AutoSize = true;
			this->lbl_Prompt_Username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Username->Location = System::Drawing::Point(135, 123);
			this->lbl_Prompt_Username->Name = L"lbl_Prompt_Username";
			this->lbl_Prompt_Username->Size = System::Drawing::Size(82, 25);
			this->lbl_Prompt_Username->TabIndex = 1;
			this->lbl_Prompt_Username->Text = L"用户名:";
			// 
			// lbl_Prompt_Password
			// 
			this->lbl_Prompt_Password->AutoSize = true;
			this->lbl_Prompt_Password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Password->Location = System::Drawing::Point(144, 189);
			this->lbl_Prompt_Password->Name = L"lbl_Prompt_Password";
			this->lbl_Prompt_Password->Size = System::Drawing::Size(61, 25);
			this->lbl_Prompt_Password->TabIndex = 2;
			this->lbl_Prompt_Password->Text = L"密码:";
			// 
			// txt_Username
			// 
			this->txt_Username->Location = System::Drawing::Point(238, 126);
			this->txt_Username->Name = L"txt_Username";
			this->txt_Username->Size = System::Drawing::Size(181, 22);
			this->txt_Username->TabIndex = 3;
			// 
			// txt_Password
			// 
			this->txt_Password->Location = System::Drawing::Point(238, 191);
			this->txt_Password->Name = L"txt_Password";
			this->txt_Password->Size = System::Drawing::Size(181, 22);
			this->txt_Password->TabIndex = 4;
			// 
			// btn_Login
			// 
			this->btn_Login->Location = System::Drawing::Point(238, 281);
			this->btn_Login->Name = L"btn_Login";
			this->btn_Login->Size = System::Drawing::Size(78, 45);
			this->btn_Login->TabIndex = 6;
			this->btn_Login->Text = L"登录";
			this->btn_Login->UseVisualStyleBackColor = true;
			this->btn_Login->Click += gcnew System::EventHandler(this, &LoginPage::Login_Click);
			// 
			// btn_forgotpswd
			// 
			this->btn_forgotpswd->Location = System::Drawing::Point(341, 281);
			this->btn_forgotpswd->Name = L"btn_forgotpswd";
			this->btn_forgotpswd->Size = System::Drawing::Size(78, 45);
			this->btn_forgotpswd->TabIndex = 9;
			this->btn_forgotpswd->Text = L"忘记密码";
			this->btn_forgotpswd->UseVisualStyleBackColor = true;
			this->btn_forgotpswd->Click += gcnew System::EventHandler(this, &LoginPage::Forgot_Click);
			// 
			// lbl_DBError
			// 
			this->lbl_DBError->AutoSize = true;
			this->lbl_DBError->Location = System::Drawing::Point(308, 242);
			this->lbl_DBError->Name = L"lbl_DBError";
			this->lbl_DBError->Size = System::Drawing::Size(40, 17);
			this->lbl_DBError->TabIndex = 10;
			this->lbl_DBError->Text = L"Error";
			this->lbl_DBError->Visible = false;
			// 
			// cbox_Remember
			// 
			this->cbox_Remember->AutoSize = true;
			this->cbox_Remember->Location = System::Drawing::Point(452, 189);
			this->cbox_Remember->Name = L"cbox_Remember";
			this->cbox_Remember->Size = System::Drawing::Size(86, 21);
			this->cbox_Remember->TabIndex = 11;
			this->cbox_Remember->Text = L"记住密码";
			this->cbox_Remember->UseVisualStyleBackColor = true;
			// 
			// LoginPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(676, 447);
			this->Controls->Add(this->cbox_Remember);
			this->Controls->Add(this->lbl_DBError);
			this->Controls->Add(this->btn_forgotpswd);
			this->Controls->Add(this->btn_Login);
			this->Controls->Add(this->txt_Password);
			this->Controls->Add(this->txt_Username);
			this->Controls->Add(this->lbl_Prompt_Password);
			this->Controls->Add(this->lbl_Prompt_Username);
			this->Controls->Add(this->lbl_Prompt_Title);
			this->Name = L"LoginPage";
			this->Text = L"登录界面";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		Database^ _database;
		int^ _stfId;
	private:  
		System::Void Initialize();
		Void WeAlumni::LoginPage::ShowDefault();
		Void WeAlumni::LoginPage::JumpToMain();
		Void WeAlumni::LoginPage::Check_Remember();
		Void WeAlumni::LoginPage::Clear_User();
		Void WeAlumni::LoginPage::Login_Click(System::Object^ sender, System::EventArgs^ e);
		Void WeAlumni::LoginPage::Forgot_Click(System::Object^ sender, System::EventArgs^ e);
};
}

