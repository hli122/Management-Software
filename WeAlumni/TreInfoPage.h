#pragma once
#include "Database.h"

/*
 * StarterPage.h
 *
 * This file set up Treasury Info Page and support modifying treasury infomation, 
 * comfirm modify and delete record.
 *
 * @author: Yiyun Zheng
 * Revised: 3/28/20
 *          4/04/20 Change input to int, lock the size of window and lock the position of infos
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
	/// TreInfoPage 摘要
	/// </summary>
	public ref class TreInfoPage : public System::Windows::Forms::Form
	{
	public:
		TreInfoPage(Int32 OId)
		{
			InitializeComponent();
			OrderId = Convert::ToString(OId);
			UpdateInfo(OrderId);
		}
		
	protected:
		~TreInfoPage()
		{
			if (components)
			{
				delete components;
			}
			if (_DataDB) {
				_DataDB->~Database();
			}
			if (_TreDB) {
				_TreDB->~Database();
			}
		}
	private: System::Windows::Forms::Label^ lbl_Prompt_Title;
	private: System::Windows::Forms::Label^ lbl_Prompt_Id;
	private: System::Windows::Forms::Label^ lbl_Prompt_Time;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfId;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfName;
	private: System::Windows::Forms::Label^ lbl_Prompt_Dept;
	private: System::Windows::Forms::Label^ lbl_Prompt_Position;
	private: System::Windows::Forms::Label^ lbl_Prompt_Amount;
	private: System::Windows::Forms::Label^ lbl_Prompt_Comment;
	private: System::Windows::Forms::Label^ lbl_Prompt_Type;

	private: System::Windows::Forms::TextBox^ txt_Id;
	private: System::Windows::Forms::TextBox^ txt_StfId;
	private: System::Windows::Forms::TextBox^ txt_Time;
	private: System::Windows::Forms::TextBox^ txt_Amount;
	private: System::Windows::Forms::TextBox^ txt_Dept;
	private: System::Windows::Forms::TextBox^ txt_Position;
	private: System::Windows::Forms::TextBox^ txt_StfName;
	private: System::Windows::Forms::TextBox^ txt_Type;
	private: System::Windows::Forms::RichTextBox^ txt_Comment;

	private: System::Windows::Forms::Label^ lbl_Id;
	private: System::Windows::Forms::Label^ lbl_Time;
	private: System::Windows::Forms::Label^ lbl_StfId;
	private: System::Windows::Forms::Label^ lbl_Dept;
	private: System::Windows::Forms::Label^ lbl_StfName;
	private: System::Windows::Forms::Label^ lbl_Position;
	private: System::Windows::Forms::Label^ lbl_Amount;
	private: System::Windows::Forms::Label^ lbl_Comment;
	private: System::Windows::Forms::Label^ lbl_Type;
	private: System::Windows::Forms::Label^ lbl_Error;

	private: System::Windows::Forms::Button^ btn_Cancle;
	private: System::Windows::Forms::Button^ btn_ChangeInfo;
	private: System::Windows::Forms::Button^ btn_Delete;
	private: System::Windows::Forms::Button^ btn_Accpet;

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
			this->lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Time = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfName = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Dept = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Position = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Amount = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Comment = (gcnew System::Windows::Forms::Label());
			this->txt_Id = (gcnew System::Windows::Forms::TextBox());
			this->txt_StfId = (gcnew System::Windows::Forms::TextBox());
			this->txt_Time = (gcnew System::Windows::Forms::TextBox());
			this->txt_Amount = (gcnew System::Windows::Forms::TextBox());
			this->txt_Dept = (gcnew System::Windows::Forms::TextBox());
			this->txt_Position = (gcnew System::Windows::Forms::TextBox());
			this->txt_StfName = (gcnew System::Windows::Forms::TextBox());
			this->txt_Comment = (gcnew System::Windows::Forms::RichTextBox());
			this->btn_ChangeInfo = (gcnew System::Windows::Forms::Button());
			this->btn_Delete = (gcnew System::Windows::Forms::Button());
			this->lbl_Id = (gcnew System::Windows::Forms::Label());
			this->lbl_Time = (gcnew System::Windows::Forms::Label());
			this->lbl_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_Dept = (gcnew System::Windows::Forms::Label());
			this->lbl_StfName = (gcnew System::Windows::Forms::Label());
			this->lbl_Position = (gcnew System::Windows::Forms::Label());
			this->lbl_Amount = (gcnew System::Windows::Forms::Label());
			this->lbl_Comment = (gcnew System::Windows::Forms::Label());
			this->lbl_Type = (gcnew System::Windows::Forms::Label());
			this->txt_Type = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Type = (gcnew System::Windows::Forms::Label());
			this->btn_Cancle = (gcnew System::Windows::Forms::Button());
			this->btn_Accpet = (gcnew System::Windows::Forms::Button());
			this->lbl_Error = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbl_Prompt_Title
			// 
			this->lbl_Prompt_Title->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Title->AutoSize = true;
			this->lbl_Prompt_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Title->Location = System::Drawing::Point(364, 57);
			this->lbl_Prompt_Title->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_Title->Name = L"lbl_Prompt_Title";
			this->lbl_Prompt_Title->Size = System::Drawing::Size(254, 32);
			this->lbl_Prompt_Title->TabIndex = 0;
			this->lbl_Prompt_Title->Text = L"Treasury Info Page";
			this->lbl_Prompt_Title->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lbl_Prompt_Id
			// 
			this->lbl_Prompt_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Id->AutoSize = true;
			this->lbl_Prompt_Id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Id->Location = System::Drawing::Point(172, 139);
			this->lbl_Prompt_Id->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_Id->Name = L"lbl_Prompt_Id";
			this->lbl_Prompt_Id->Size = System::Drawing::Size(36, 29);
			this->lbl_Prompt_Id->TabIndex = 1;
			this->lbl_Prompt_Id->Text = L"ID";
			// 
			// lbl_Prompt_Time
			// 
			this->lbl_Prompt_Time->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Time->AutoSize = true;
			this->lbl_Prompt_Time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Time->Location = System::Drawing::Point(589, 139);
			this->lbl_Prompt_Time->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_Time->Name = L"lbl_Prompt_Time";
			this->lbl_Prompt_Time->Size = System::Drawing::Size(69, 29);
			this->lbl_Prompt_Time->TabIndex = 2;
			this->lbl_Prompt_Time->Text = L"Time";
			// 
			// lbl_Prompt_StfId
			// 
			this->lbl_Prompt_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_StfId->AutoSize = true;
			this->lbl_Prompt_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfId->Location = System::Drawing::Point(172, 207);
			this->lbl_Prompt_StfId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_StfId->Name = L"lbl_Prompt_StfId";
			this->lbl_Prompt_StfId->Size = System::Drawing::Size(89, 29);
			this->lbl_Prompt_StfId->TabIndex = 3;
			this->lbl_Prompt_StfId->Text = L"Staff ID";
			this->lbl_Prompt_StfId->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbl_Prompt_StfName
			// 
			this->lbl_Prompt_StfName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_StfName->AutoSize = true;
			this->lbl_Prompt_StfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfName->Location = System::Drawing::Point(589, 207);
			this->lbl_Prompt_StfName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_StfName->Name = L"lbl_Prompt_StfName";
			this->lbl_Prompt_StfName->Size = System::Drawing::Size(131, 29);
			this->lbl_Prompt_StfName->TabIndex = 4;
			this->lbl_Prompt_StfName->Text = L"Staff Name";
			// 
			// lbl_Prompt_Dept
			// 
			this->lbl_Prompt_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Dept->AutoSize = true;
			this->lbl_Prompt_Dept->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Dept->Location = System::Drawing::Point(172, 279);
			this->lbl_Prompt_Dept->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_Dept->Name = L"lbl_Prompt_Dept";
			this->lbl_Prompt_Dept->Size = System::Drawing::Size(138, 29);
			this->lbl_Prompt_Dept->TabIndex = 5;
			this->lbl_Prompt_Dept->Text = L"Department";
			// 
			// lbl_Prompt_Position
			// 
			this->lbl_Prompt_Position->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Position->AutoSize = true;
			this->lbl_Prompt_Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_Position->Location = System::Drawing::Point(589, 279);
			this->lbl_Prompt_Position->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_Position->Name = L"lbl_Prompt_Position";
			this->lbl_Prompt_Position->Size = System::Drawing::Size(100, 29);
			this->lbl_Prompt_Position->TabIndex = 6;
			this->lbl_Prompt_Position->Text = L"Position";
			// 
			// lbl_Prompt_Amount
			// 
			this->lbl_Prompt_Amount->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Amount->AutoSize = true;
			this->lbl_Prompt_Amount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Amount->Location = System::Drawing::Point(589, 352);
			this->lbl_Prompt_Amount->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_Amount->Name = L"lbl_Prompt_Amount";
			this->lbl_Prompt_Amount->Size = System::Drawing::Size(94, 29);
			this->lbl_Prompt_Amount->TabIndex = 7;
			this->lbl_Prompt_Amount->Text = L"Amount";
			// 
			// lbl_Prompt_Comment
			// 
			this->lbl_Prompt_Comment->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Comment->AutoSize = true;
			this->lbl_Prompt_Comment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Comment->Location = System::Drawing::Point(172, 420);
			this->lbl_Prompt_Comment->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_Comment->Name = L"lbl_Prompt_Comment";
			this->lbl_Prompt_Comment->Size = System::Drawing::Size(117, 29);
			this->lbl_Prompt_Comment->TabIndex = 8;
			this->lbl_Prompt_Comment->Text = L"Comment";
			// 
			// txt_Id
			// 
			this->txt_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Id->Location = System::Drawing::Point(341, 143);
			this->txt_Id->Margin = System::Windows::Forms::Padding(2);
			this->txt_Id->Name = L"txt_Id";
			this->txt_Id->Size = System::Drawing::Size(127, 30);
			this->txt_Id->TabIndex = 9;
			this->txt_Id->Visible = false;
			// 
			// txt_StfId
			// 
			this->txt_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_StfId->Location = System::Drawing::Point(341, 207);
			this->txt_StfId->Margin = System::Windows::Forms::Padding(2);
			this->txt_StfId->Name = L"txt_StfId";
			this->txt_StfId->Size = System::Drawing::Size(127, 30);
			this->txt_StfId->TabIndex = 10;
			this->txt_StfId->Visible = false;
			// 
			// txt_Time
			// 
			this->txt_Time->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Time->Location = System::Drawing::Point(736, 143);
			this->txt_Time->Margin = System::Windows::Forms::Padding(2);
			this->txt_Time->Name = L"txt_Time";
			this->txt_Time->Size = System::Drawing::Size(123, 30);
			this->txt_Time->TabIndex = 11;
			this->txt_Time->Visible = false;
			// 
			// txt_Amount
			// 
			this->txt_Amount->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Amount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Amount->Location = System::Drawing::Point(732, 352);
			this->txt_Amount->Margin = System::Windows::Forms::Padding(2);
			this->txt_Amount->Name = L"txt_Amount";
			this->txt_Amount->Size = System::Drawing::Size(127, 30);
			this->txt_Amount->TabIndex = 13;
			this->txt_Amount->Visible = false;
			// 
			// txt_Dept
			// 
			this->txt_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Dept->Location = System::Drawing::Point(341, 279);
			this->txt_Dept->Margin = System::Windows::Forms::Padding(2);
			this->txt_Dept->Name = L"txt_Dept";
			this->txt_Dept->Size = System::Drawing::Size(127, 26);
			this->txt_Dept->TabIndex = 14;
			this->txt_Dept->Visible = false;
			// 
			// txt_Position
			// 
			this->txt_Position->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Position->Location = System::Drawing::Point(736, 284);
			this->txt_Position->Margin = System::Windows::Forms::Padding(2);
			this->txt_Position->Name = L"txt_Position";
			this->txt_Position->Size = System::Drawing::Size(123, 30);
			this->txt_Position->TabIndex = 16;
			this->txt_Position->Visible = false;
			// 
			// txt_StfName
			// 
			this->txt_StfName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_StfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_StfName->Location = System::Drawing::Point(736, 212);
			this->txt_StfName->Margin = System::Windows::Forms::Padding(2);
			this->txt_StfName->Name = L"txt_StfName";
			this->txt_StfName->Size = System::Drawing::Size(123, 30);
			this->txt_StfName->TabIndex = 17;
			this->txt_StfName->Visible = false;
			// 
			// txt_Comment
			// 
			this->txt_Comment->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Comment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Comment->Location = System::Drawing::Point(177, 485);
			this->txt_Comment->Margin = System::Windows::Forms::Padding(2);
			this->txt_Comment->Name = L"txt_Comment";
			this->txt_Comment->Size = System::Drawing::Size(666, 201);
			this->txt_Comment->TabIndex = 18;
			this->txt_Comment->Text = L"";
			this->txt_Comment->Visible = false;
			// 
			// btn_ChangeInfo
			// 
			this->btn_ChangeInfo->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_ChangeInfo->Location = System::Drawing::Point(285, 770);
			this->btn_ChangeInfo->Margin = System::Windows::Forms::Padding(2);
			this->btn_ChangeInfo->Name = L"btn_ChangeInfo";
			this->btn_ChangeInfo->Size = System::Drawing::Size(137, 81);
			this->btn_ChangeInfo->TabIndex = 19;
			this->btn_ChangeInfo->Text = L"Modify Record";
			this->btn_ChangeInfo->UseVisualStyleBackColor = true;
			this->btn_ChangeInfo->Click += gcnew System::EventHandler(this, &TreInfoPage::btn_ChangeInfo_Click);
			// 
			// btn_Delete
			// 
			this->btn_Delete->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Delete->Location = System::Drawing::Point(579, 772);
			this->btn_Delete->Margin = System::Windows::Forms::Padding(2);
			this->btn_Delete->Name = L"btn_Delete";
			this->btn_Delete->Size = System::Drawing::Size(137, 78);
			this->btn_Delete->TabIndex = 20;
			this->btn_Delete->Text = L"Delete Record";
			this->btn_Delete->UseVisualStyleBackColor = true;
			this->btn_Delete->Click += gcnew System::EventHandler(this, &TreInfoPage::btn_Delete_Click);
			// 
			// lbl_Id
			// 
			this->lbl_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Id->AutoSize = true;
			this->lbl_Id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Id->Location = System::Drawing::Point(337, 146);
			this->lbl_Id->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Id->Name = L"lbl_Id";
			this->lbl_Id->Size = System::Drawing::Size(30, 25);
			this->lbl_Id->TabIndex = 21;
			this->lbl_Id->Text = L"-1";
			// 
			// lbl_Time
			// 
			this->lbl_Time->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Time->AutoSize = true;
			this->lbl_Time->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Time->Location = System::Drawing::Point(732, 146);
			this->lbl_Time->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Time->Name = L"lbl_Time";
			this->lbl_Time->Size = System::Drawing::Size(0, 25);
			this->lbl_Time->TabIndex = 22;
			// 
			// lbl_StfId
			// 
			this->lbl_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_StfId->AutoSize = true;
			this->lbl_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_StfId->Location = System::Drawing::Point(337, 209);
			this->lbl_StfId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_StfId->Name = L"lbl_StfId";
			this->lbl_StfId->Size = System::Drawing::Size(0, 25);
			this->lbl_StfId->TabIndex = 23;
			// 
			// lbl_Dept
			// 
			this->lbl_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Dept->AutoSize = true;
			this->lbl_Dept->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Dept->Location = System::Drawing::Point(337, 277);
			this->lbl_Dept->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Dept->Name = L"lbl_Dept";
			this->lbl_Dept->Size = System::Drawing::Size(0, 25);
			this->lbl_Dept->TabIndex = 24;
			// 
			// lbl_StfName
			// 
			this->lbl_StfName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_StfName->AutoSize = true;
			this->lbl_StfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_StfName->Location = System::Drawing::Point(738, 212);
			this->lbl_StfName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_StfName->Name = L"lbl_StfName";
			this->lbl_StfName->Size = System::Drawing::Size(0, 25);
			this->lbl_StfName->TabIndex = 25;
			// 
			// lbl_Position
			// 
			this->lbl_Position->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Position->AutoSize = true;
			this->lbl_Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Position->Location = System::Drawing::Point(732, 288);
			this->lbl_Position->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Position->Name = L"lbl_Position";
			this->lbl_Position->Size = System::Drawing::Size(0, 25);
			this->lbl_Position->TabIndex = 26;
			// 
			// lbl_Amount
			// 
			this->lbl_Amount->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Amount->AutoSize = true;
			this->lbl_Amount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Amount->Location = System::Drawing::Point(732, 350);
			this->lbl_Amount->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Amount->Name = L"lbl_Amount";
			this->lbl_Amount->Size = System::Drawing::Size(0, 25);
			this->lbl_Amount->TabIndex = 27;
			// 
			// lbl_Comment
			// 
			this->lbl_Comment->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Comment->AutoSize = true;
			this->lbl_Comment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Comment->Location = System::Drawing::Point(179, 487);
			this->lbl_Comment->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Comment->Name = L"lbl_Comment";
			this->lbl_Comment->Size = System::Drawing::Size(0, 25);
			this->lbl_Comment->TabIndex = 28;
			// 
			// lbl_Type
			// 
			this->lbl_Type->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Type->AutoSize = true;
			this->lbl_Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Type->Location = System::Drawing::Point(337, 352);
			this->lbl_Type->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Type->Name = L"lbl_Type";
			this->lbl_Type->Size = System::Drawing::Size(0, 25);
			this->lbl_Type->TabIndex = 31;
			// 
			// txt_Type
			// 
			this->txt_Type->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Type->Location = System::Drawing::Point(341, 350);
			this->txt_Type->Margin = System::Windows::Forms::Padding(2);
			this->txt_Type->Name = L"txt_Type";
			this->txt_Type->Size = System::Drawing::Size(127, 30);
			this->txt_Type->TabIndex = 30;
			this->txt_Type->Visible = false;
			// 
			// lbl_Prompt_Type
			// 
			this->lbl_Prompt_Type->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Type->AutoSize = true;
			this->lbl_Prompt_Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Type->Location = System::Drawing::Point(172, 352);
			this->lbl_Prompt_Type->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Prompt_Type->Name = L"lbl_Prompt_Type";
			this->lbl_Prompt_Type->Size = System::Drawing::Size(68, 29);
			this->lbl_Prompt_Type->TabIndex = 29;
			this->lbl_Prompt_Type->Text = L"Type";
			// 
			// btn_Cancle
			// 
			this->btn_Cancle->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Cancle->ForeColor = System::Drawing::Color::Red;
			this->btn_Cancle->Location = System::Drawing::Point(579, 770);
			this->btn_Cancle->Margin = System::Windows::Forms::Padding(2);
			this->btn_Cancle->Name = L"btn_Cancle";
			this->btn_Cancle->Size = System::Drawing::Size(137, 78);
			this->btn_Cancle->TabIndex = 33;
			this->btn_Cancle->Text = L"Cancel Modify";
			this->btn_Cancle->UseVisualStyleBackColor = true;
			this->btn_Cancle->Visible = false;
			this->btn_Cancle->Click += gcnew System::EventHandler(this, &TreInfoPage::btn_Cancle_Click);
			// 
			// btn_Accpet
			// 
			this->btn_Accpet->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Accpet->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_Accpet->Location = System::Drawing::Point(285, 772);
			this->btn_Accpet->Margin = System::Windows::Forms::Padding(2);
			this->btn_Accpet->Name = L"btn_Accpet";
			this->btn_Accpet->Size = System::Drawing::Size(137, 81);
			this->btn_Accpet->TabIndex = 32;
			this->btn_Accpet->Text = L"Confirm Modify";
			this->btn_Accpet->UseVisualStyleBackColor = true;
			this->btn_Accpet->Visible = false;
			this->btn_Accpet->Click += gcnew System::EventHandler(this, &TreInfoPage::btn_Accpet_Click);
			// 
			// lbl_Error
			// 
			this->lbl_Error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Error->AutoSize = true;
			this->lbl_Error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Error->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->lbl_Error->Location = System::Drawing::Point(391, 714);
			this->lbl_Error->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Error->Name = L"lbl_Error";
			this->lbl_Error->Size = System::Drawing::Size(0, 29);
			this->lbl_Error->TabIndex = 34;
			// 
			// TreInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1018, 967);
			this->Controls->Add(this->lbl_Error);
			this->Controls->Add(this->btn_Cancle);
			this->Controls->Add(this->btn_Accpet);
			this->Controls->Add(this->lbl_Type);
			this->Controls->Add(this->txt_Type);
			this->Controls->Add(this->lbl_Prompt_Type);
			this->Controls->Add(this->lbl_Comment);
			this->Controls->Add(this->lbl_Amount);
			this->Controls->Add(this->lbl_Position);
			this->Controls->Add(this->lbl_StfName);
			this->Controls->Add(this->lbl_Dept);
			this->Controls->Add(this->lbl_StfId);
			this->Controls->Add(this->lbl_Time);
			this->Controls->Add(this->lbl_Id);
			this->Controls->Add(this->btn_Delete);
			this->Controls->Add(this->btn_ChangeInfo);
			this->Controls->Add(this->txt_Comment);
			this->Controls->Add(this->txt_StfName);
			this->Controls->Add(this->txt_Position);
			this->Controls->Add(this->txt_Dept);
			this->Controls->Add(this->txt_Amount);
			this->Controls->Add(this->txt_Time);
			this->Controls->Add(this->txt_StfId);
			this->Controls->Add(this->txt_Id);
			this->Controls->Add(this->lbl_Prompt_Comment);
			this->Controls->Add(this->lbl_Prompt_Amount);
			this->Controls->Add(this->lbl_Prompt_Position);
			this->Controls->Add(this->lbl_Prompt_Dept);
			this->Controls->Add(this->lbl_Prompt_StfName);
			this->Controls->Add(this->lbl_Prompt_StfId);
			this->Controls->Add(this->lbl_Prompt_Time);
			this->Controls->Add(this->lbl_Prompt_Id);
			this->Controls->Add(this->lbl_Prompt_Title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"TreInfoPage";
			this->Text = L"TreInfoPage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Initialize Function
	private: 
		Void UpdateInfo(String^ OrderId);
		int UpdateOutsideInfo(String^);
	
	// Constant Data and DB
	private: 
		String^ OrderId;
		Database^ _TreDB = gcnew Database(Database::DatabaseType::Treasury);
		Database^ _DataDB = gcnew Database(Database::DatabaseType::Data);

	// Btn click function
	private:
		System::Void btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Accpet_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Delete_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_Cancle_Click(System::Object^ sender, System::EventArgs^ e);
	
	// Other help functions
	private: 
		System::Void WeAlumni::TreInfoPage::SetShowLabelStatus(bool);
		System::Void WeAlumni::TreInfoPage::SetTextStatus(bool);
		System::Void WeAlumni::TreInfoPage::SetShowToText(bool);
		System::Void WeAlumni::TreInfoPage::SetButtonStatus(bool);
		System::Void WeAlumni::TreInfoPage::UnableAllBtn();
	};
}
