#pragma once
#include "MemInfoPage.h"
#include "MemAddPage.h"
#include "StfInfoPage.h"
#include "StfAddPage.h"
#include "OPTInfoPage.h"
#include "OPTAddPage.h"
#include "RecInfoPage.h"
#include "TreInfoPage.h"
#include "TreAddPage.h"
#include "OrdInfoPage.h"

namespace WeAlumni {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartPage
	/// </summary>
	public ref class StartPage : public System::Windows::Forms::Form
	{
	public:
		StartPage(void)
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
		~StartPage()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button8;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(189, 104);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 37);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Member";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StartPage::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(189, 173);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(194, 37);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Staff";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &StartPage::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(189, 241);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(194, 37);
			this->button3->TabIndex = 6;
			this->button3->Text = L"OPT";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &StartPage::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(189, 310);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(194, 37);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Order";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &StartPage::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(189, 375);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(194, 37);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Record";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &StartPage::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(189, 443);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(194, 37);
			this->button6->TabIndex = 12;
			this->button6->Text = L"Treasury";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &StartPage::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(425, 443);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(194, 37);
			this->button7->TabIndex = 19;
			this->button7->Text = L"Treasury_Add";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &StartPage::button7_Click);
			// 
			// button9
			// 
			this->button9->Enabled = false;
			this->button9->Location = System::Drawing::Point(425, 310);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(194, 37);
			this->button9->TabIndex = 17;
			this->button9->Text = L"Order_Add";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &StartPage::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(425, 241);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(194, 37);
			this->button10->TabIndex = 16;
			this->button10->Text = L"OPT_Add";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &StartPage::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(425, 173);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(194, 37);
			this->button11->TabIndex = 15;
			this->button11->Text = L"Staff_Add";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &StartPage::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(425, 104);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(194, 37);
			this->button12->TabIndex = 14;
			this->button12->Text = L"Member_Add";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &StartPage::button12_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(177, 35);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(206, 25);
			this->textBox7->TabIndex = 20;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"SimSun", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(54, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 15);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Any Id ->";
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"SimSun", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button8->ForeColor = System::Drawing::Color::Red;
			this->button8->Location = System::Drawing::Point(425, 23);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(192, 43);
			this->button8->TabIndex = 22;
			this->button8->Text = L"Set Id";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &StartPage::button8_Click);
			// 
			// StartPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(742, 538);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"StartPage";
			this->Text = L"StartPage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		int _id;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MemInfoPage^ p = gcnew MemInfoPage(_id);
		p->ShowDialog();
		p->~MemInfoPage();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	StfInfoPage^ p = gcnew StfInfoPage(_id);
	p->ShowDialog();
	p->~StfInfoPage();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	OPTInfoPage^ p = gcnew OPTInfoPage(_id);
	p->ShowDialog();
	p->~OPTInfoPage();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	OrdInfoPage^ p = gcnew OrdInfoPage(_id);
	p->ShowDialog();
	p->~OrdInfoPage();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	RecInfoPage^ p = gcnew RecInfoPage(_id);
	p->ShowDialog();
	p->~RecInfoPage();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	TreInfoPage^ p = gcnew TreInfoPage(_id);
	p->ShowDialog();
	p->~TreInfoPage();
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	MemAddPage^ p = gcnew MemAddPage();
	p->ShowDialog();
	p->~MemAddPage();
}
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	StfAddPage^ p = gcnew StfAddPage();
	p->ShowDialog();
	p->~StfAddPage();
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	OPTAddPage^ p = gcnew OPTAddPage(_id);
	p->ShowDialog();
	p->~OPTAddPage();
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	//Leave empty
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	TreAddPage^ p = gcnew TreAddPage(_id);
	p->ShowDialog();
	p->~TreAddPage();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	_id = Convert::ToInt32(textBox7->Text);
}
};
}
