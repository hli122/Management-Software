#pragma once
#include "Database.h"

/*
 * DatabasePrecheck.h
 *
 * This file provide two button for DB Precheck
 *
 * @author: Xiangdong Che, Yiyun Zheng
 * Revised: 04/09/20
 *          04/11/20 Add check treasury database
 *	    04/12/20 Combine Prompt file and Precheck file together
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
	/// Summary for DatabasePrecheckPage
	/// </summary>
	public ref class DatabasePrecheck : public System::Windows::Forms::Form
	{
	public:
		enum class DatabaseType
		{
			admin,
			data,
			treasury,
		};

		DatabasePrecheck()
		{
			InitializeComponent();
		}

		DatabasePrecheck(DatabaseType type)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_databaseType = type;
			Initialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DatabasePrecheck()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_Import;
	private: System::Windows::Forms::Button^ btn_New;
	private: System::Windows::Forms::OpenFileDialog^ FileDialog;
	private: System::Windows::Forms::Label^ lbl_Prompt;
	private: System::Windows::Forms::Button^ btn_Exit;


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
			this->btn_Import = (gcnew System::Windows::Forms::Button());
			this->btn_New = (gcnew System::Windows::Forms::Button());
			this->FileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->lbl_Prompt = (gcnew System::Windows::Forms::Label());
			this->btn_Exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_Import
			// 
			this->btn_Import->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Import->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Import->Location = System::Drawing::Point(98, 107);
			this->btn_Import->Name = L"btn_Import";
			this->btn_Import->Size = System::Drawing::Size(114, 90);
			this->btn_Import->TabIndex = 0;
			this->btn_Import->Text = L"Import ";
			this->btn_Import->UseVisualStyleBackColor = true;
			this->btn_Import->Click += gcnew System::EventHandler(this, &DatabasePrecheck::btn_Import_Click);
			// 
			// btn_New
			// 
			this->btn_New->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_New->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_New->Location = System::Drawing::Point(266, 107);
			this->btn_New->Name = L"btn_New";
			this->btn_New->Size = System::Drawing::Size(114, 90);
			this->btn_New->TabIndex = 1;
			this->btn_New->Text = L"New";
			this->btn_New->UseVisualStyleBackColor = true;
			this->btn_New->Click += gcnew System::EventHandler(this, &DatabasePrecheck::btn_New_Click);
			// 
			// lbl_Prompt
			// 
			this->lbl_Prompt->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt->AutoSize = true;
			this->lbl_Prompt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt->Location = System::Drawing::Point(127, 53);
			this->lbl_Prompt->Name = L"lbl_Prompt";
			this->lbl_Prompt->Size = System::Drawing::Size(34, 16);
			this->lbl_Prompt->TabIndex = 3;
			this->lbl_Prompt->Text = L"N/A";
			this->lbl_Prompt->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_Exit
			// 
			this->btn_Exit->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Exit->Location = System::Drawing::Point(184, 227);
			this->btn_Exit->Name = L"btn_Exit";
			this->btn_Exit->Size = System::Drawing::Size(111, 57);
			this->btn_Exit->TabIndex = 4;
			this->btn_Exit->Text = L"Exit";
			this->btn_Exit->UseVisualStyleBackColor = true;
			this->btn_Exit->Click += gcnew System::EventHandler(this, &DatabasePrecheck::btn_Exit_Click);
			// 
			// DatabasePrecheckPrompt
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(462, 311);
			this->Controls->Add(this->btn_Exit);
			this->Controls->Add(this->lbl_Prompt);
			this->Controls->Add(this->btn_New);
			this->Controls->Add(this->btn_Import);
			this->MinimumSize = System::Drawing::Size(0, 350);
			this->Name = L"DatabasePrecheck";
			this->Text = L"DatabasePrecheck";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		DatabaseType _databaseType;

	public:
		bool exitStatus;
		bool checkFile();
	private:
		Void Initialize();
		Void btn_Import_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_New_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Exit_Click(System::Object^ sender, System::EventArgs^ e);

	public:
		void setDatabaseType(DatabaseType);
		static void loginPrecheck();
		static bool TrePrecheck();
	};
}
