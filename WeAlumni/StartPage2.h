#pragma once
#include "Database.h"
#include "PublicUserInfo.h"

namespace WeAlumni {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartPage2
	/// </summary>
	public ref class StartPage2 : public System::Windows::Forms::Form
	{
	public:
		StartPage2(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			try {
				_db = gcnew Database(Database::DatabaseType::Admin, true);
			}
			catch (Exception^ exception) {
				lbl_prompt->Text = exception->Message;
				lbl_prompt->ForeColor = Color::Red;
				btn_checkStf->Enabled = false;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartPage2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_jumpToYourPage;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btn_checkStf;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ lbl_stfName;
	private: System::Windows::Forms::Label^ lbl_auth;


	private: System::Windows::Forms::Label^ lbl_prompt;
	private: System::Windows::Forms::Label^ label5;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_jumpToYourPage = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btn_checkStf = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->lbl_stfName = (gcnew System::Windows::Forms::Label());
			this->lbl_auth = (gcnew System::Windows::Forms::Label());
			this->lbl_prompt = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_jumpToYourPage
			// 
			this->btn_jumpToYourPage->Enabled = false;
			this->btn_jumpToYourPage->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_jumpToYourPage->Location = System::Drawing::Point(563, 300);
			this->btn_jumpToYourPage->Name = L"btn_jumpToYourPage";
			this->btn_jumpToYourPage->Size = System::Drawing::Size(294, 65);
			this->btn_jumpToYourPage->TabIndex = 0;
			this->btn_jumpToYourPage->Text = L"Jump to your page";
			this->btn_jumpToYourPage->UseVisualStyleBackColor = true;
			this->btn_jumpToYourPage->Click += gcnew System::EventHandler(this, &StartPage2::btn_jumpToYourPage_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"SimSun", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(151, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"PublicUserInfo";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(58, 107);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"StfId";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(59, 271);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 15);
			this->label3->TabIndex = 3;
			this->label3->Text = L"StfName";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(59, 361);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 15);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Auth";
			// 
			// btn_checkStf
			// 
			this->btn_checkStf->Font = (gcnew System::Drawing::Font(L"SimSun", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->btn_checkStf->Location = System::Drawing::Point(339, 90);
			this->btn_checkStf->Name = L"btn_checkStf";
			this->btn_checkStf->Size = System::Drawing::Size(111, 48);
			this->btn_checkStf->TabIndex = 5;
			this->btn_checkStf->Text = L"Check";
			this->btn_checkStf->UseVisualStyleBackColor = true;
			this->btn_checkStf->Click += gcnew System::EventHandler(this, &StartPage2::btn_checkStf_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(138, 104);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(156, 25);
			this->textBox1->TabIndex = 6;
			// 
			// lbl_stfName
			// 
			this->lbl_stfName->AutoSize = true;
			this->lbl_stfName->Location = System::Drawing::Point(152, 300);
			this->lbl_stfName->Name = L"lbl_stfName";
			this->lbl_stfName->Size = System::Drawing::Size(95, 15);
			this->lbl_stfName->TabIndex = 7;
			this->lbl_stfName->Text = L"lbl_stfName";
			// 
			// lbl_auth
			// 
			this->lbl_auth->AutoSize = true;
			this->lbl_auth->Location = System::Drawing::Point(152, 392);
			this->lbl_auth->Name = L"lbl_auth";
			this->lbl_auth->Size = System::Drawing::Size(71, 15);
			this->lbl_auth->TabIndex = 8;
			this->lbl_auth->Text = L"lbl_auth";
			// 
			// lbl_prompt
			// 
			this->lbl_prompt->AutoSize = true;
			this->lbl_prompt->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_prompt->Location = System::Drawing::Point(58, 179);
			this->lbl_prompt->Name = L"lbl_prompt";
			this->lbl_prompt->Size = System::Drawing::Size(418, 17);
			this->lbl_prompt->TabIndex = 9;
			this->lbl_prompt->Text = L"Please enter StfId and click Check button";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(58, 218);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(415, 15);
			this->label5->TabIndex = 10;
			this->label5->Text = L"---------------------------------------------------";
			// 
			// StartPage2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(918, 479);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lbl_prompt);
			this->Controls->Add(this->lbl_auth);
			this->Controls->Add(this->lbl_stfName);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btn_checkStf);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_jumpToYourPage);
			this->Name = L"StartPage2";
			this->Text = L"StartPage2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		PublicUserInfo^ _pui = gcnew PublicUserInfo();
		Database^ _db;

	private:
		void FindName(String^ stfId) {
			Database^ db;
			int status = -1;
			try {
				db = gcnew Database(Database::DatabaseType::Data, true);
				String^ command = "SELECT Name FROM Member WHERE Id = " + stfId;
				status = db->ReadData(command);
			} catch (Exception^ exception) {
				lbl_prompt->Text = exception->Message;
				lbl_prompt->ForeColor = Color::Red;
				db->~Database();
				return;
			}
			
			if (status == 0) {
				lbl_prompt->Text = "Staff Name Not Found";
				lbl_prompt->ForeColor = Color::Red;
			}
			else if (status == 1) {
				lbl_stfName->Text = db->dataReader[0]->ToString();
				_pui->SetName(lbl_stfName->Text);
				btn_jumpToYourPage->Enabled = true;
			}
			else {
				lbl_prompt->Text = "FAILED to read staff name from data.db";
				lbl_prompt->ForeColor = Color::Red;
			}

			db->~Database();
		}

		void UpdateAuth(int Auth) {
			switch (Auth) {
			case 0: lbl_auth->Text = "Level-1"; _pui->SetAuth(PublicUserInfo::Auth::Level_1); break;
			case 1: lbl_auth->Text = "Level-2"; _pui->SetAuth(PublicUserInfo::Auth::Level_2); break;
			case 2: lbl_auth->Text = "Level-3"; _pui->SetAuth(PublicUserInfo::Auth::Level_3); break;
			case 3: lbl_auth->Text = "Level-4"; _pui->SetAuth(PublicUserInfo::Auth::Level_4); break;
			case 4: lbl_auth->Text = "Level-5"; _pui->SetAuth(PublicUserInfo::Auth::Level_5); break;
			default: lbl_auth->Text = "WRONG LEVEL: set default level-1"; _pui->SetAuth(PublicUserInfo::Auth::Level_1); break;
			}
		}

		Void btn_checkStf_Click(System::Object^ sender, System::EventArgs^ e) {
			btn_jumpToYourPage->Enabled = false;
			String^ stfId = textBox1->Text;
			if (stfId->Length == 0) {
				lbl_prompt->Text = "Please enter stfId";
				lbl_prompt->ForeColor = Color::Red;
				return;
			}

			String^ command = "SELECT Auth FROM Admin WHERE StfId = " + stfId;
			int status = -1;
			try {
				status = _db->ReadData(command);
			}
			catch (Exception^ exception) {
				lbl_prompt->Text = exception->Message;
				lbl_prompt->ForeColor = Color::Red;
				return;
			}
			
			if (status == 0) {
				lbl_prompt->Text = "User Not Found";
				lbl_prompt->ForeColor = Color::Red;
			}
			else if (status == 1) {
				lbl_prompt->Text = "User Found";
				lbl_prompt->ForeColor = Color::Green;
				UpdateAuth(Convert::ToInt32(_db->dataReader[0]->ToString()));
				_db->dataReader->Close();
				_pui->SetId(Convert::ToInt32(textBox1->Text));
				FindName(stfId);
			}
			else {
				lbl_prompt->Text = "FAILED to read user info from Admin.db";
				lbl_prompt->ForeColor = Color::Red;
			}
		}

	private:
		// Write your code in .cpp file
		Void btn_jumpToYourPage_Click(System::Object^ sender, System::EventArgs^ e);
};
}
