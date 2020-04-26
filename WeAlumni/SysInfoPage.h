#pragma once

/*
 * SysInfoPage.h
 *
 * This file have basic information of system.
 *
 * @author: Rui Jia
 * Revised: 4/7/20
 *          4/25/20
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
	/// Summary for SysInfoPage
	/// </summary>
	public ref class SysInfoPage : public System::Windows::Forms::Form
	{
	public:
		SysInfoPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SysInfoPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_Prompt_Version;
	private: System::Windows::Forms::Label^ lbl_Version;
	private: System::Windows::Forms::Label^ lbl_Prompt_Intro;
	private: System::Windows::Forms::Label^ lbl_Prompt_Feed;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ lbl_Prompt_Con;
	private: System::Windows::Forms::Label^ lbl_Con;
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
			this->lbl_Prompt_Version = (gcnew System::Windows::Forms::Label());
			this->lbl_Version = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Intro = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Feed = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Con = (gcnew System::Windows::Forms::Label());
			this->lbl_Con = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_Prompt_Version
			// 
			this->lbl_Prompt_Version->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Version->AutoSize = true;
			this->lbl_Prompt_Version->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Version->Location = System::Drawing::Point(45, 81);
			this->lbl_Prompt_Version->Name = L"lbl_Prompt_Version";
			this->lbl_Prompt_Version->Size = System::Drawing::Size(89, 19);
			this->lbl_Prompt_Version->TabIndex = 0;
			this->lbl_Prompt_Version->Text = L"版本信息";
			// 
			// lbl_Version
			// 
			this->lbl_Version->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Version->AutoSize = true;
			this->lbl_Version->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Version->Location = System::Drawing::Point(198, 81);
			this->lbl_Version->Name = L"lbl_Version";
			this->lbl_Version->Size = System::Drawing::Size(119, 19);
			this->lbl_Version->TabIndex = 1;
			this->lbl_Version->Text = L"Version 1.0";
			// 
			// lbl_Prompt_Intro
			// 
			this->lbl_Prompt_Intro->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Intro->AutoSize = true;
			this->lbl_Prompt_Intro->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Intro->Location = System::Drawing::Point(45, 143);
			this->lbl_Prompt_Intro->Name = L"lbl_Prompt_Intro";
			this->lbl_Prompt_Intro->Size = System::Drawing::Size(89, 19);
			this->lbl_Prompt_Intro->TabIndex = 2;
			this->lbl_Prompt_Intro->Text = L"软件介绍";
			// 
			// lbl_Prompt_Feed
			// 
			this->lbl_Prompt_Feed->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Feed->AutoSize = true;
			this->lbl_Prompt_Feed->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Feed->Location = System::Drawing::Point(52, 209);
			this->lbl_Prompt_Feed->Name = L"lbl_Prompt_Feed";
			this->lbl_Prompt_Feed->Size = System::Drawing::Size(82, 19);
			this->lbl_Prompt_Feed->TabIndex = 4;
			this->lbl_Prompt_Feed->Text = L"反馈bug";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(198, 143);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(225, 19);
			this->label6->TabIndex = 5;
			this->label6->Text = L"联系方式: caa@ucsc.edu";
			// 
			// lbl_Prompt_Con
			// 
			this->lbl_Prompt_Con->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Con->AutoSize = true;
			this->lbl_Prompt_Con->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Prompt_Con->Location = System::Drawing::Point(45, 273);
			this->lbl_Prompt_Con->Name = L"lbl_Prompt_Con";
			this->lbl_Prompt_Con->Size = System::Drawing::Size(89, 19);
			this->lbl_Prompt_Con->TabIndex = 6;
			this->lbl_Prompt_Con->Text = L"软件配置";
			// 
			// lbl_Con
			// 
			this->lbl_Con->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Con->AutoSize = true;
			this->lbl_Con->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->lbl_Con->Location = System::Drawing::Point(198, 273);
			this->lbl_Con->Name = L"lbl_Con";
			this->lbl_Con->Size = System::Drawing::Size(189, 19);
			this->lbl_Con->TabIndex = 7;
			this->lbl_Con->Text = L".NET Framework 4.0";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"SimSun", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(183, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(116, 25);
			this->label1->TabIndex = 8;
			this->label1->Text = L"系统信息";
			// 
			// SysInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(494, 359);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbl_Con);
			this->Controls->Add(this->lbl_Prompt_Con);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->lbl_Prompt_Feed);
			this->Controls->Add(this->lbl_Prompt_Intro);
			this->Controls->Add(this->lbl_Version);
			this->Controls->Add(this->lbl_Prompt_Version);
			this->Name = L"SysInfoPage";
			this->Text = L"SysInfoPage";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	};
}
