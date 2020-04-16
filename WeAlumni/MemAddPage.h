#pragma once
#include "Database.h"
#include "PublicUserInfo.h"

/*
 * MemAddPage.h
 *
 * This file have basic Member Add page interaction actions.
 *
 * @author: Jiaying Hou
 * Revised: 4/4/20
 *          4/15/20 added PublicUserInfo
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
	/// Summary for MemAddPage
	/// </summary>
	public ref class MemAddPage : public System::Windows::Forms::Form
	{
	public:
		MemAddPage(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Initialize();
		}
		MemAddPage(PublicUserInfo^ pui) {
			InitializeComponent();
			_stfId = pui->GetId();
			Initialize();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MemAddPage()
		{
			if (components)
			{
				delete components;
			}
			if (database)
			{
				delete database;
			}
		}
	private: System::Windows::Forms::Label^ lbl_Prompt_AddMemberPage;
	private: System::Windows::Forms::Label^ lbl_Prompt_Id;
	private: System::Windows::Forms::Label^ lbl_Prompt_Status;
	private: System::Windows::Forms::Label^ lbl_Prompt_Type;
	private: System::Windows::Forms::Label^ lbl_Prompt_Birth;
	private: System::Windows::Forms::Label^ lbl_Prompt_Gender;
	private: System::Windows::Forms::Label^ lbl_Prompt_Name;
	private: System::Windows::Forms::Label^ lbl_Prompt_Address2;
	private: System::Windows::Forms::Label^ lbl_Prompt_Address1;
	private: System::Windows::Forms::Label^ lbl_Prompt_Country;
	private: System::Windows::Forms::Label^ lbl_Prompt_Wechat;
	private: System::Windows::Forms::Label^ lbl_Prompt_Phone;
	private: System::Windows::Forms::Label^ lbl_Prompt_Email;
	private: System::Windows::Forms::Label^ lbl_Prompt_SearchAuth;
	private: System::Windows::Forms::Label^ lbl_Prompt_CareerStatus;
	private: System::Windows::Forms::Label^ lbl_Prompt_Program;
	private: System::Windows::Forms::Label^ lbl_Prompt_StdIl;
	private: System::Windows::Forms::Label^ lbl_Prompt_Postal;
	private: System::Windows::Forms::Label^ lbl_Prompt_City;
	private: System::Windows::Forms::Label^ lbl_Id;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::TextBox^ txt_Name;
	private: System::Windows::Forms::TextBox^ txt_Birth;
	private: System::Windows::Forms::TextBox^ txt_Email;
	private: System::Windows::Forms::TextBox^ txt_Phone;
	private: System::Windows::Forms::TextBox^ txt_Wechat;
	private: System::Windows::Forms::TextBox^ txt_Country;
	private: System::Windows::Forms::TextBox^ txt_Address1;
	private: System::Windows::Forms::TextBox^ txt_Address2;
	private: System::Windows::Forms::TextBox^ txt_City;
	private: System::Windows::Forms::TextBox^ txt_Postal;
	private: System::Windows::Forms::TextBox^ txt_StdId;
	private: System::Windows::Forms::Button^ btn_accept;
	private: System::Windows::Forms::Button^ btn_Cancel;
	private: System::Windows::Forms::Label^ lbl_error;
	private: System::Windows::Forms::Label^ lbl_Prompt_EndDate;
	private: System::Windows::Forms::Label^ lbl_Prompt_Degree;
	private: System::Windows::Forms::Label^ lbl_Prompt_Major1;
	private: System::Windows::Forms::Label^ lbl_Prompt_Major2;
	private: System::Windows::Forms::Label^ lbl_Prompt_Company;
	private: System::Windows::Forms::TextBox^ txt_EndDate;
	private: System::Windows::Forms::TextBox^ txt_Major1;
	private: System::Windows::Forms::TextBox^ txt_Major2;
	private: System::Windows::Forms::TextBox^ txt_Company;
	private: System::Windows::Forms::Label^ lbl_Prompt_Position;
	private: System::Windows::Forms::TextBox^ txt_Position;
	private: System::Windows::Forms::ComboBox^ cmb_Status;
	private: System::Windows::Forms::ComboBox^ cmb_Type;
	private: System::Windows::Forms::ComboBox^ cmb_Program;
	private: System::Windows::Forms::TextBox^ txt_Gender;
	private: System::Windows::Forms::ComboBox^ cmb_Degree;
	private: System::Windows::Forms::ComboBox^ cmb_CareerStatus;
	private: System::Windows::Forms::ComboBox^ cmb_SearchAuth;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lbl_Prompt_AddMemberPage = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Type = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Birth = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Gender = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Address2 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Address1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Country = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Wechat = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Phone = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_SearchAuth = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_CareerStatus = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Program = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StdIl = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Postal = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_City = (gcnew System::Windows::Forms::Label());
			this->lbl_Id = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->txt_Name = (gcnew System::Windows::Forms::TextBox());
			this->txt_Birth = (gcnew System::Windows::Forms::TextBox());
			this->txt_Email = (gcnew System::Windows::Forms::TextBox());
			this->txt_Phone = (gcnew System::Windows::Forms::TextBox());
			this->txt_Wechat = (gcnew System::Windows::Forms::TextBox());
			this->txt_Country = (gcnew System::Windows::Forms::TextBox());
			this->txt_Address1 = (gcnew System::Windows::Forms::TextBox());
			this->txt_Address2 = (gcnew System::Windows::Forms::TextBox());
			this->txt_City = (gcnew System::Windows::Forms::TextBox());
			this->txt_Postal = (gcnew System::Windows::Forms::TextBox());
			this->txt_StdId = (gcnew System::Windows::Forms::TextBox());
			this->btn_accept = (gcnew System::Windows::Forms::Button());
			this->btn_Cancel = (gcnew System::Windows::Forms::Button());
			this->lbl_error = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_EndDate = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Degree = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Major1 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Major2 = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Company = (gcnew System::Windows::Forms::Label());
			this->txt_EndDate = (gcnew System::Windows::Forms::TextBox());
			this->txt_Major1 = (gcnew System::Windows::Forms::TextBox());
			this->txt_Major2 = (gcnew System::Windows::Forms::TextBox());
			this->txt_Company = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Position = (gcnew System::Windows::Forms::Label());
			this->txt_Position = (gcnew System::Windows::Forms::TextBox());
			this->cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_Type = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_Program = (gcnew System::Windows::Forms::ComboBox());
			this->txt_Gender = (gcnew System::Windows::Forms::TextBox());
			this->cmb_Degree = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_CareerStatus = (gcnew System::Windows::Forms::ComboBox());
			this->cmb_SearchAuth = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// lbl_Prompt_AddMemberPage
			// 
			this->lbl_Prompt_AddMemberPage->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_AddMemberPage->AutoSize = true;
			this->lbl_Prompt_AddMemberPage->Location = System::Drawing::Point(290, 9);
			this->lbl_Prompt_AddMemberPage->Name = L"lbl_Prompt_AddMemberPage";
			this->lbl_Prompt_AddMemberPage->Size = System::Drawing::Size(95, 13);
			this->lbl_Prompt_AddMemberPage->TabIndex = 0;
			this->lbl_Prompt_AddMemberPage->Text = L"Add Member Page";
			// 
			// lbl_Prompt_Id
			// 
			this->lbl_Prompt_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Id->AutoSize = true;
			this->lbl_Prompt_Id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Id->Location = System::Drawing::Point(31, 56);
			this->lbl_Prompt_Id->Name = L"lbl_Prompt_Id";
			this->lbl_Prompt_Id->Size = System::Drawing::Size(18, 13);
			this->lbl_Prompt_Id->TabIndex = 1;
			this->lbl_Prompt_Id->Text = L"Id";
			// 
			// lbl_Prompt_Status
			// 
			this->lbl_Prompt_Status->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Status->AutoSize = true;
			this->lbl_Prompt_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Status->Location = System::Drawing::Point(80, 55);
			this->lbl_Prompt_Status->Name = L"lbl_Prompt_Status";
			this->lbl_Prompt_Status->Size = System::Drawing::Size(43, 13);
			this->lbl_Prompt_Status->TabIndex = 2;
			this->lbl_Prompt_Status->Text = L"Status";
			// 
			// lbl_Prompt_Type
			// 
			this->lbl_Prompt_Type->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Type->AutoSize = true;
			this->lbl_Prompt_Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Type->Location = System::Drawing::Point(202, 55);
			this->lbl_Prompt_Type->Name = L"lbl_Prompt_Type";
			this->lbl_Prompt_Type->Size = System::Drawing::Size(35, 13);
			this->lbl_Prompt_Type->TabIndex = 3;
			this->lbl_Prompt_Type->Text = L"Type";
			// 
			// lbl_Prompt_Birth
			// 
			this->lbl_Prompt_Birth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Birth->AutoSize = true;
			this->lbl_Prompt_Birth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Birth->Location = System::Drawing::Point(562, 59);
			this->lbl_Prompt_Birth->Name = L"lbl_Prompt_Birth";
			this->lbl_Prompt_Birth->Size = System::Drawing::Size(33, 13);
			this->lbl_Prompt_Birth->TabIndex = 6;
			this->lbl_Prompt_Birth->Text = L"Birth";
			// 
			// lbl_Prompt_Gender
			// 
			this->lbl_Prompt_Gender->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Gender->AutoSize = true;
			this->lbl_Prompt_Gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Gender->Location = System::Drawing::Point(424, 59);
			this->lbl_Prompt_Gender->Name = L"lbl_Prompt_Gender";
			this->lbl_Prompt_Gender->Size = System::Drawing::Size(48, 13);
			this->lbl_Prompt_Gender->TabIndex = 5;
			this->lbl_Prompt_Gender->Text = L"Gender";
			// 
			// lbl_Prompt_Name
			// 
			this->lbl_Prompt_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Name->AutoSize = true;
			this->lbl_Prompt_Name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Name->Location = System::Drawing::Point(318, 56);
			this->lbl_Prompt_Name->Name = L"lbl_Prompt_Name";
			this->lbl_Prompt_Name->Size = System::Drawing::Size(39, 13);
			this->lbl_Prompt_Name->TabIndex = 4;
			this->lbl_Prompt_Name->Text = L"Name";
			// 
			// lbl_Prompt_Address2
			// 
			this->lbl_Prompt_Address2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Address2->AutoSize = true;
			this->lbl_Prompt_Address2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_Address2->Location = System::Drawing::Point(26, 139);
			this->lbl_Prompt_Address2->Name = L"lbl_Prompt_Address2";
			this->lbl_Prompt_Address2->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_Address2->TabIndex = 12;
			this->lbl_Prompt_Address2->Text = L"Address2";
			// 
			// lbl_Prompt_Address1
			// 
			this->lbl_Prompt_Address1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Address1->AutoSize = true;
			this->lbl_Prompt_Address1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_Address1->Location = System::Drawing::Point(492, 97);
			this->lbl_Prompt_Address1->Name = L"lbl_Prompt_Address1";
			this->lbl_Prompt_Address1->Size = System::Drawing::Size(59, 13);
			this->lbl_Prompt_Address1->TabIndex = 11;
			this->lbl_Prompt_Address1->Text = L"Address1";
			// 
			// lbl_Prompt_Country
			// 
			this->lbl_Prompt_Country->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Country->AutoSize = true;
			this->lbl_Prompt_Country->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Country->Location = System::Drawing::Point(368, 98);
			this->lbl_Prompt_Country->Name = L"lbl_Prompt_Country";
			this->lbl_Prompt_Country->Size = System::Drawing::Size(50, 13);
			this->lbl_Prompt_Country->TabIndex = 10;
			this->lbl_Prompt_Country->Text = L"Country";
			// 
			// lbl_Prompt_Wechat
			// 
			this->lbl_Prompt_Wechat->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Wechat->AutoSize = true;
			this->lbl_Prompt_Wechat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Wechat->Location = System::Drawing::Point(239, 98);
			this->lbl_Prompt_Wechat->Name = L"lbl_Prompt_Wechat";
			this->lbl_Prompt_Wechat->Size = System::Drawing::Size(51, 13);
			this->lbl_Prompt_Wechat->TabIndex = 9;
			this->lbl_Prompt_Wechat->Text = L"Wechat";
			// 
			// lbl_Prompt_Phone
			// 
			this->lbl_Prompt_Phone->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Phone->AutoSize = true;
			this->lbl_Prompt_Phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Phone->Location = System::Drawing::Point(130, 98);
			this->lbl_Prompt_Phone->Name = L"lbl_Prompt_Phone";
			this->lbl_Prompt_Phone->Size = System::Drawing::Size(43, 13);
			this->lbl_Prompt_Phone->TabIndex = 8;
			this->lbl_Prompt_Phone->Text = L"Phone";
			// 
			// lbl_Prompt_Email
			// 
			this->lbl_Prompt_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Email->AutoSize = true;
			this->lbl_Prompt_Email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Email->Location = System::Drawing::Point(12, 98);
			this->lbl_Prompt_Email->Name = L"lbl_Prompt_Email";
			this->lbl_Prompt_Email->Size = System::Drawing::Size(37, 13);
			this->lbl_Prompt_Email->TabIndex = 7;
			this->lbl_Prompt_Email->Text = L"Email";
			// 
			// lbl_Prompt_SearchAuth
			// 
			this->lbl_Prompt_SearchAuth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_SearchAuth->AutoSize = true;
			this->lbl_Prompt_SearchAuth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_SearchAuth->Location = System::Drawing::Point(290, 222);
			this->lbl_Prompt_SearchAuth->Name = L"lbl_Prompt_SearchAuth";
			this->lbl_Prompt_SearchAuth->Size = System::Drawing::Size(73, 13);
			this->lbl_Prompt_SearchAuth->TabIndex = 18;
			this->lbl_Prompt_SearchAuth->Text = L"SearchAuth";
			// 
			// lbl_Prompt_CareerStatus
			// 
			this->lbl_Prompt_CareerStatus->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_CareerStatus->AutoSize = true;
			this->lbl_Prompt_CareerStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_CareerStatus->Location = System::Drawing::Point(480, 187);
			this->lbl_Prompt_CareerStatus->Name = L"lbl_Prompt_CareerStatus";
			this->lbl_Prompt_CareerStatus->Size = System::Drawing::Size(84, 13);
			this->lbl_Prompt_CareerStatus->TabIndex = 17;
			this->lbl_Prompt_CareerStatus->Text = L"Career Status";
			// 
			// lbl_Prompt_Program
			// 
			this->lbl_Prompt_Program->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Program->AutoSize = true;
			this->lbl_Prompt_Program->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Program->Location = System::Drawing::Point(551, 139);
			this->lbl_Prompt_Program->Name = L"lbl_Prompt_Program";
			this->lbl_Prompt_Program->Size = System::Drawing::Size(53, 13);
			this->lbl_Prompt_Program->TabIndex = 16;
			this->lbl_Prompt_Program->Text = L"Program";
			// 
			// lbl_Prompt_StdIl
			// 
			this->lbl_Prompt_StdIl->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_StdIl->AutoSize = true;
			this->lbl_Prompt_StdIl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StdIl->Location = System::Drawing::Point(442, 139);
			this->lbl_Prompt_StdIl->Name = L"lbl_Prompt_StdIl";
			this->lbl_Prompt_StdIl->Size = System::Drawing::Size(37, 13);
			this->lbl_Prompt_StdIl->TabIndex = 15;
			this->lbl_Prompt_StdIl->Text = L"StdId";
			// 
			// lbl_Prompt_Postal
			// 
			this->lbl_Prompt_Postal->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Postal->AutoSize = true;
			this->lbl_Prompt_Postal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Postal->Location = System::Drawing::Point(333, 139);
			this->lbl_Prompt_Postal->Name = L"lbl_Prompt_Postal";
			this->lbl_Prompt_Postal->Size = System::Drawing::Size(42, 13);
			this->lbl_Prompt_Postal->TabIndex = 14;
			this->lbl_Prompt_Postal->Text = L"Postal";
			// 
			// lbl_Prompt_City
			// 
			this->lbl_Prompt_City->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_City->AutoSize = true;
			this->lbl_Prompt_City->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_City->Location = System::Drawing::Point(227, 139);
			this->lbl_Prompt_City->Name = L"lbl_Prompt_City";
			this->lbl_Prompt_City->Size = System::Drawing::Size(28, 13);
			this->lbl_Prompt_City->TabIndex = 13;
			this->lbl_Prompt_City->Text = L"City";
			// 
			// lbl_Id
			// 
			this->lbl_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Id->AutoSize = true;
			this->lbl_Id->Location = System::Drawing::Point(46, 55);
			this->lbl_Id->Name = L"lbl_Id";
			this->lbl_Id->Size = System::Drawing::Size(10, 13);
			this->lbl_Id->TabIndex = 19;
			this->lbl_Id->Text = L"-";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// txt_Name
			// 
			this->txt_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Name->Location = System::Drawing::Point(356, 52);
			this->txt_Name->Name = L"txt_Name";
			this->txt_Name->Size = System::Drawing::Size(62, 20);
			this->txt_Name->TabIndex = 23;
			// 
			// txt_Birth
			// 
			this->txt_Birth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Birth->Location = System::Drawing::Point(596, 53);
			this->txt_Birth->Name = L"txt_Birth";
			this->txt_Birth->Size = System::Drawing::Size(62, 20);
			this->txt_Birth->TabIndex = 27;
			// 
			// txt_Email
			// 
			this->txt_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Email->Location = System::Drawing::Point(57, 95);
			this->txt_Email->Name = L"txt_Email";
			this->txt_Email->Size = System::Drawing::Size(62, 20);
			this->txt_Email->TabIndex = 26;
			// 
			// txt_Phone
			// 
			this->txt_Phone->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Phone->Location = System::Drawing::Point(171, 95);
			this->txt_Phone->Name = L"txt_Phone";
			this->txt_Phone->Size = System::Drawing::Size(62, 20);
			this->txt_Phone->TabIndex = 25;
			// 
			// txt_Wechat
			// 
			this->txt_Wechat->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Wechat->Location = System::Drawing::Point(291, 94);
			this->txt_Wechat->Name = L"txt_Wechat";
			this->txt_Wechat->Size = System::Drawing::Size(62, 20);
			this->txt_Wechat->TabIndex = 30;
			// 
			// txt_Country
			// 
			this->txt_Country->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Country->Location = System::Drawing::Point(412, 95);
			this->txt_Country->Name = L"txt_Country";
			this->txt_Country->Size = System::Drawing::Size(62, 20);
			this->txt_Country->TabIndex = 29;
			// 
			// txt_Address1
			// 
			this->txt_Address1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Address1->Location = System::Drawing::Point(549, 94);
			this->txt_Address1->Name = L"txt_Address1";
			this->txt_Address1->Size = System::Drawing::Size(127, 20);
			this->txt_Address1->TabIndex = 28;
			// 
			// txt_Address2
			// 
			this->txt_Address2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Address2->Location = System::Drawing::Point(83, 136);
			this->txt_Address2->Name = L"txt_Address2";
			this->txt_Address2->Size = System::Drawing::Size(125, 20);
			this->txt_Address2->TabIndex = 33;
			// 
			// txt_City
			// 
			this->txt_City->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_City->Location = System::Drawing::Point(265, 136);
			this->txt_City->Name = L"txt_City";
			this->txt_City->Size = System::Drawing::Size(62, 20);
			this->txt_City->TabIndex = 32;
			// 
			// txt_Postal
			// 
			this->txt_Postal->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Postal->Location = System::Drawing::Point(375, 136);
			this->txt_Postal->Name = L"txt_Postal";
			this->txt_Postal->Size = System::Drawing::Size(62, 20);
			this->txt_Postal->TabIndex = 31;
			// 
			// txt_StdId
			// 
			this->txt_StdId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_StdId->Location = System::Drawing::Point(483, 136);
			this->txt_StdId->Name = L"txt_StdId";
			this->txt_StdId->Size = System::Drawing::Size(62, 20);
			this->txt_StdId->TabIndex = 36;
			// 
			// btn_accept
			// 
			this->btn_accept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_accept->Location = System::Drawing::Point(308, 255);
			this->btn_accept->Name = L"btn_accept";
			this->btn_accept->Size = System::Drawing::Size(61, 20);
			this->btn_accept->TabIndex = 40;
			this->btn_accept->Text = L"accept";
			this->btn_accept->UseVisualStyleBackColor = true;
			this->btn_accept->Click += gcnew System::EventHandler(this, &MemAddPage::btn_accept_Click);
			// 
			// btn_Cancel
			// 
			this->btn_Cancel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Cancel->Location = System::Drawing::Point(308, 281);
			this->btn_Cancel->Name = L"btn_Cancel";
			this->btn_Cancel->Size = System::Drawing::Size(61, 20);
			this->btn_Cancel->TabIndex = 41;
			this->btn_Cancel->Text = L"cancel";
			this->btn_Cancel->UseVisualStyleBackColor = true;
			this->btn_Cancel->Click += gcnew System::EventHandler(this, &MemAddPage::btn_Cancel_Click);
			// 
			// lbl_error
			// 
			this->lbl_error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_error->AutoSize = true;
			this->lbl_error->ForeColor = System::Drawing::Color::Red;
			this->lbl_error->Location = System::Drawing::Point(546, 242);
			this->lbl_error->Name = L"lbl_error";
			this->lbl_error->Size = System::Drawing::Size(44, 13);
			this->lbl_error->TabIndex = 44;
			this->lbl_error->Text = L"warning";
			this->lbl_error->Visible = false;
			// 
			// lbl_Prompt_EndDate
			// 
			this->lbl_Prompt_EndDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_EndDate->AutoSize = true;
			this->lbl_Prompt_EndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_EndDate->Location = System::Drawing::Point(14, 186);
			this->lbl_Prompt_EndDate->Name = L"lbl_Prompt_EndDate";
			this->lbl_Prompt_EndDate->Size = System::Drawing::Size(60, 13);
			this->lbl_Prompt_EndDate->TabIndex = 45;
			this->lbl_Prompt_EndDate->Text = L"End Date";
			// 
			// lbl_Prompt_Degree
			// 
			this->lbl_Prompt_Degree->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Degree->AutoSize = true;
			this->lbl_Prompt_Degree->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Degree->Location = System::Drawing::Point(140, 186);
			this->lbl_Prompt_Degree->Name = L"lbl_Prompt_Degree";
			this->lbl_Prompt_Degree->Size = System::Drawing::Size(48, 13);
			this->lbl_Prompt_Degree->TabIndex = 46;
			this->lbl_Prompt_Degree->Text = L"Degree";
			// 
			// lbl_Prompt_Major1
			// 
			this->lbl_Prompt_Major1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Major1->AutoSize = true;
			this->lbl_Prompt_Major1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Major1->Location = System::Drawing::Point(253, 186);
			this->lbl_Prompt_Major1->Name = L"lbl_Prompt_Major1";
			this->lbl_Prompt_Major1->Size = System::Drawing::Size(45, 13);
			this->lbl_Prompt_Major1->TabIndex = 47;
			this->lbl_Prompt_Major1->Text = L"Major1";
			// 
			// lbl_Prompt_Major2
			// 
			this->lbl_Prompt_Major2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Major2->AutoSize = true;
			this->lbl_Prompt_Major2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Major2->Location = System::Drawing::Point(372, 186);
			this->lbl_Prompt_Major2->Name = L"lbl_Prompt_Major2";
			this->lbl_Prompt_Major2->Size = System::Drawing::Size(45, 13);
			this->lbl_Prompt_Major2->TabIndex = 48;
			this->lbl_Prompt_Major2->Text = L"Major2";
			// 
			// lbl_Prompt_Company
			// 
			this->lbl_Prompt_Company->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Company->AutoSize = true;
			this->lbl_Prompt_Company->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Company->Location = System::Drawing::Point(15, 222);
			this->lbl_Prompt_Company->Name = L"lbl_Prompt_Company";
			this->lbl_Prompt_Company->Size = System::Drawing::Size(58, 13);
			this->lbl_Prompt_Company->TabIndex = 49;
			this->lbl_Prompt_Company->Text = L"Company";
			// 
			// txt_EndDate
			// 
			this->txt_EndDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_EndDate->Location = System::Drawing::Point(72, 183);
			this->txt_EndDate->Name = L"txt_EndDate";
			this->txt_EndDate->Size = System::Drawing::Size(62, 20);
			this->txt_EndDate->TabIndex = 50;
			// 
			// txt_Major1
			// 
			this->txt_Major1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Major1->Location = System::Drawing::Point(295, 183);
			this->txt_Major1->Name = L"txt_Major1";
			this->txt_Major1->Size = System::Drawing::Size(62, 20);
			this->txt_Major1->TabIndex = 52;
			// 
			// txt_Major2
			// 
			this->txt_Major2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Major2->Location = System::Drawing::Point(417, 180);
			this->txt_Major2->Name = L"txt_Major2";
			this->txt_Major2->Size = System::Drawing::Size(62, 20);
			this->txt_Major2->TabIndex = 53;
			// 
			// txt_Company
			// 
			this->txt_Company->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Company->Location = System::Drawing::Point(72, 219);
			this->txt_Company->Name = L"txt_Company";
			this->txt_Company->Size = System::Drawing::Size(62, 20);
			this->txt_Company->TabIndex = 54;
			// 
			// lbl_Prompt_Position
			// 
			this->lbl_Prompt_Position->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Position->AutoSize = true;
			this->lbl_Prompt_Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_Position->Location = System::Drawing::Point(151, 222);
			this->lbl_Prompt_Position->Name = L"lbl_Prompt_Position";
			this->lbl_Prompt_Position->Size = System::Drawing::Size(52, 13);
			this->lbl_Prompt_Position->TabIndex = 55;
			this->lbl_Prompt_Position->Text = L"Position";
			// 
			// txt_Position
			// 
			this->txt_Position->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Position->Location = System::Drawing::Point(205, 219);
			this->txt_Position->Name = L"txt_Position";
			this->txt_Position->Size = System::Drawing::Size(62, 20);
			this->txt_Position->TabIndex = 56;
			// 
			// cmb_Status
			// 
			this->cmb_Status->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Status->FormattingEnabled = true;
			this->cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"Review", L"Invalid" });
			this->cmb_Status->Location = System::Drawing::Point(126, 53);
			this->cmb_Status->Name = L"cmb_Status";
			this->cmb_Status->Size = System::Drawing::Size(70, 21);
			this->cmb_Status->TabIndex = 57;
			// 
			// cmb_Type
			// 
			this->cmb_Type->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Type->FormattingEnabled = true;
			this->cmb_Type->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Normal", L"DivHead", L"Staff", L"Head" });
			this->cmb_Type->Location = System::Drawing::Point(242, 53);
			this->cmb_Type->Name = L"cmb_Type";
			this->cmb_Type->Size = System::Drawing::Size(70, 21);
			this->cmb_Type->TabIndex = 58;
			// 
			// cmb_Program
			// 
			this->cmb_Program->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Program->FormattingEnabled = true;
			this->cmb_Program->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"UnderGrad", L"Grad", L"TransOus", L"Exchange",
					L"VisitingScholar"
			});
			this->cmb_Program->Location = System::Drawing::Point(606, 136);
			this->cmb_Program->Name = L"cmb_Program";
			this->cmb_Program->Size = System::Drawing::Size(70, 21);
			this->cmb_Program->TabIndex = 59;
			// 
			// txt_Gender
			// 
			this->txt_Gender->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Gender->Location = System::Drawing::Point(472, 52);
			this->txt_Gender->Name = L"txt_Gender";
			this->txt_Gender->Size = System::Drawing::Size(62, 20);
			this->txt_Gender->TabIndex = 22;
			// 
			// cmb_Degree
			// 
			this->cmb_Degree->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_Degree->FormattingEnabled = true;
			this->cmb_Degree->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Bachelor", L"Master", L"PhD", L"Post-PhD" });
			this->cmb_Degree->Location = System::Drawing::Point(185, 183);
			this->cmb_Degree->Name = L"cmb_Degree";
			this->cmb_Degree->Size = System::Drawing::Size(70, 21);
			this->cmb_Degree->TabIndex = 60;
			// 
			// cmb_CareerStatus
			// 
			this->cmb_CareerStatus->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_CareerStatus->FormattingEnabled = true;
			this->cmb_CareerStatus->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"GradProgram", L"Unemployed", L"Employed",
					L"StartBusiness"
			});
			this->cmb_CareerStatus->Location = System::Drawing::Point(565, 180);
			this->cmb_CareerStatus->Name = L"cmb_CareerStatus";
			this->cmb_CareerStatus->Size = System::Drawing::Size(70, 21);
			this->cmb_CareerStatus->TabIndex = 61;
			// 
			// cmb_SearchAuth
			// 
			this->cmb_SearchAuth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->cmb_SearchAuth->FormattingEnabled = true;
			this->cmb_SearchAuth->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Yes", L"No" });
			this->cmb_SearchAuth->Location = System::Drawing::Point(369, 219);
			this->cmb_SearchAuth->Name = L"cmb_SearchAuth";
			this->cmb_SearchAuth->Size = System::Drawing::Size(70, 21);
			this->cmb_SearchAuth->TabIndex = 62;
			// 
			// MemAddPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(686, 331);
			this->Controls->Add(this->cmb_SearchAuth);
			this->Controls->Add(this->cmb_CareerStatus);
			this->Controls->Add(this->cmb_Degree);
			this->Controls->Add(this->cmb_Program);
			this->Controls->Add(this->cmb_Type);
			this->Controls->Add(this->cmb_Status);
			this->Controls->Add(this->txt_Position);
			this->Controls->Add(this->lbl_Prompt_Position);
			this->Controls->Add(this->txt_Company);
			this->Controls->Add(this->txt_Major2);
			this->Controls->Add(this->txt_Major1);
			this->Controls->Add(this->txt_EndDate);
			this->Controls->Add(this->lbl_Prompt_Company);
			this->Controls->Add(this->lbl_Prompt_Major2);
			this->Controls->Add(this->lbl_Prompt_Major1);
			this->Controls->Add(this->lbl_Prompt_Degree);
			this->Controls->Add(this->lbl_Prompt_EndDate);
			this->Controls->Add(this->lbl_error);
			this->Controls->Add(this->btn_Cancel);
			this->Controls->Add(this->btn_accept);
			this->Controls->Add(this->txt_StdId);
			this->Controls->Add(this->txt_Address2);
			this->Controls->Add(this->txt_City);
			this->Controls->Add(this->txt_Postal);
			this->Controls->Add(this->txt_Wechat);
			this->Controls->Add(this->txt_Country);
			this->Controls->Add(this->txt_Address1);
			this->Controls->Add(this->txt_Birth);
			this->Controls->Add(this->txt_Email);
			this->Controls->Add(this->txt_Phone);
			this->Controls->Add(this->txt_Name);
			this->Controls->Add(this->txt_Gender);
			this->Controls->Add(this->lbl_Id);
			this->Controls->Add(this->lbl_Prompt_SearchAuth);
			this->Controls->Add(this->lbl_Prompt_CareerStatus);
			this->Controls->Add(this->lbl_Prompt_Program);
			this->Controls->Add(this->lbl_Prompt_StdIl);
			this->Controls->Add(this->lbl_Prompt_Postal);
			this->Controls->Add(this->lbl_Prompt_City);
			this->Controls->Add(this->lbl_Prompt_Address2);
			this->Controls->Add(this->lbl_Prompt_Address1);
			this->Controls->Add(this->lbl_Prompt_Country);
			this->Controls->Add(this->lbl_Prompt_Wechat);
			this->Controls->Add(this->lbl_Prompt_Phone);
			this->Controls->Add(this->lbl_Prompt_Email);
			this->Controls->Add(this->lbl_Prompt_Birth);
			this->Controls->Add(this->lbl_Prompt_Gender);
			this->Controls->Add(this->lbl_Prompt_Name);
			this->Controls->Add(this->lbl_Prompt_Type);
			this->Controls->Add(this->lbl_Prompt_Status);
			this->Controls->Add(this->lbl_Prompt_Id);
			this->Controls->Add(this->lbl_Prompt_AddMemberPage);
			this->Name = L"MemAddPage";
			this->Text = L"MemAddPage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		int _id;
		int _stfId;
		Database^ database;
	
	private: 
		Void Initialize();
		Void UpdateInfo();
		int insertRecord();
		Void btn_accept_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
