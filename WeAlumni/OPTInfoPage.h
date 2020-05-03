#pragma once
#include "Database.h"
#include "PublicUserInfo.h"

/*
 * OPTInfoPage.h
 *
 * This file includes functions of editing and deleting on OPT data.
 *
 * @author: Xiangdong Che
 * Revised: 4/04/20  Fixed button's position. Added verification function
 *          3/31/20  Renamed class name from OPT to OPTInfoPage
 *          3/27/20
 *          5/02/20 Changed layout of OPT part(Xiangdong Che)
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
	/// Summary for OPTInfoPage
	/// </summary>
	public ref class OPTInfoPage : public System::Windows::Forms::Form
	{
	public:
		OPTInfoPage(int^ InputId)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_OPTId = InputId;
			try {
				database = gcnew Database(Database::DatabaseType::Data);
				Initialize();
			}
			catch(Exception^ exception){
				lbl_error->Text = exception->Message;
				lbl_error->ForeColor = Color::Red;
				lbl_error->Visible = true;
			}
		}

		OPTInfoPage(int^ InputId, PublicUserInfo^ pui)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			_OPTId = InputId;
			_pui = pui;
			_auth = pui->GetAuth();
			Initialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~OPTInfoPage()
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
	private: System::Windows::Forms::Label^ lbl_Prompt_OPTID;
	private: System::Windows::Forms::Label^ lbl_Prompt_Status;
	private: System::Windows::Forms::Label^ lbl_Prompt_MemId;
	private: System::Windows::Forms::TextBox^ txt_MemId;
	private: System::Windows::Forms::Label^ lbl_Prompt_Title;
	private: System::Windows::Forms::Label^ lbl_Prompt_EndDate;
	private: System::Windows::Forms::Label^ lbl_Prompt_StartDate;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfId;
	private: System::Windows::Forms::TextBox^ txt_StfId;
	private: System::Windows::Forms::TextBox^ txt_StartDate;
	private: System::Windows::Forms::TextBox^ txt_CardNumber;
	private: System::Windows::Forms::TextBox^ txt_Position;
	private: System::Windows::Forms::TextBox^ txt_Title;
	private: System::Windows::Forms::TextBox^ txt_EndDate;
	private: System::Windows::Forms::Label^ lbl_Prompt_CardNumber;
	private: System::Windows::Forms::Label^ lbl_Prompt_Position;
	private: System::Windows::Forms::Label^ lbl_Prompt_CardEndDate;
	private: System::Windows::Forms::Label^ lbl_Prompt_CardStartDate;
	private: System::Windows::Forms::TextBox^ txt_CardEndDate;
	private: System::Windows::Forms::TextBox^ txt_CardStartDate;
	private: System::Windows::Forms::Button^ btn_ChangeInfo;
	private: System::Windows::Forms::Button^ btn_ChangeConfirm;
	private: System::Windows::Forms::Button^ btn_ChangeCancel;
	private: System::Windows::Forms::Label^ lbl_PageName;
	private: System::Windows::Forms::Label^ lbl_Prompt_MemName;
	private: System::Windows::Forms::Label^ lbl_Prompt_Gender;
	private: System::Windows::Forms::Label^ lbl_Prompt_Email;
	private: System::Windows::Forms::Label^ lbl_Prompt_Phone;
	private: System::Windows::Forms::Label^ lbl_Prompt_WeChat;
	private: System::Windows::Forms::Label^ lbl_Prompt_StfName;
	private: System::Windows::Forms::Label^ lbl_error;
	private: System::Windows::Forms::Button^ btn_DeleteAll;
	private: System::Windows::Forms::Button^ btn_DeleteConfirm;
	private: System::Windows::Forms::Button^ btn_DeleteCancel;
	private: System::Windows::Forms::Label^ lbl_Email;
	private: System::Windows::Forms::Label^ lbl_StfName;
	private: System::Windows::Forms::Label^ lbl_Phone;
	private: System::Windows::Forms::Label^ lbl_MemName;
	private: System::Windows::Forms::Label^ lbl_WeChat;
	private: System::Windows::Forms::Label^ lbl_Gender;
	private: System::Windows::Forms::Label^ lbl_OPTID;
	private: System::Windows::Forms::Label^ lbl_MemId;
	private: System::Windows::Forms::Label^ lbl_StfId;
	private: System::Windows::Forms::Label^ lbl_StartDate;
	private: System::Windows::Forms::Label^ lbl_Title;
	private: System::Windows::Forms::Label^ lbl_CardNumber;
	private: System::Windows::Forms::Label^ lbl_Status;
	private: System::Windows::Forms::Label^ lbl_EndDate;
	private: System::Windows::Forms::Label^ lbl_Position;
	private: System::Windows::Forms::Label^ lbl_CardStartDate;
	private: System::Windows::Forms::Label^ lbl_CardEndDate;
	private: System::Windows::Forms::Button^ btn_Verify;
	private: System::Windows::Forms::Label^ lbl_Verify;
	private: System::Windows::Forms::Button^ btn_Exit;
	private: System::Windows::Forms::ComboBox^ cbm_Status;

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
			this->lbl_Prompt_OPTID = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_MemId = (gcnew System::Windows::Forms::Label());
			this->txt_MemId = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_Title = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_EndDate = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StartDate = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfId = (gcnew System::Windows::Forms::Label());
			this->txt_StfId = (gcnew System::Windows::Forms::TextBox());
			this->txt_StartDate = (gcnew System::Windows::Forms::TextBox());
			this->txt_CardNumber = (gcnew System::Windows::Forms::TextBox());
			this->txt_Position = (gcnew System::Windows::Forms::TextBox());
			this->txt_Title = (gcnew System::Windows::Forms::TextBox());
			this->txt_EndDate = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Prompt_CardNumber = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Position = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_CardEndDate = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_CardStartDate = (gcnew System::Windows::Forms::Label());
			this->txt_CardEndDate = (gcnew System::Windows::Forms::TextBox());
			this->txt_CardStartDate = (gcnew System::Windows::Forms::TextBox());
			this->btn_ChangeInfo = (gcnew System::Windows::Forms::Button());
			this->btn_ChangeConfirm = (gcnew System::Windows::Forms::Button());
			this->btn_ChangeCancel = (gcnew System::Windows::Forms::Button());
			this->lbl_PageName = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_MemName = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Gender = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_Phone = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_WeChat = (gcnew System::Windows::Forms::Label());
			this->lbl_Prompt_StfName = (gcnew System::Windows::Forms::Label());
			this->lbl_error = (gcnew System::Windows::Forms::Label());
			this->btn_DeleteAll = (gcnew System::Windows::Forms::Button());
			this->btn_DeleteConfirm = (gcnew System::Windows::Forms::Button());
			this->btn_DeleteCancel = (gcnew System::Windows::Forms::Button());
			this->lbl_Email = (gcnew System::Windows::Forms::Label());
			this->lbl_StfName = (gcnew System::Windows::Forms::Label());
			this->lbl_Phone = (gcnew System::Windows::Forms::Label());
			this->lbl_MemName = (gcnew System::Windows::Forms::Label());
			this->lbl_WeChat = (gcnew System::Windows::Forms::Label());
			this->lbl_Gender = (gcnew System::Windows::Forms::Label());
			this->lbl_OPTID = (gcnew System::Windows::Forms::Label());
			this->lbl_MemId = (gcnew System::Windows::Forms::Label());
			this->lbl_StfId = (gcnew System::Windows::Forms::Label());
			this->lbl_StartDate = (gcnew System::Windows::Forms::Label());
			this->lbl_Title = (gcnew System::Windows::Forms::Label());
			this->lbl_CardNumber = (gcnew System::Windows::Forms::Label());
			this->lbl_Status = (gcnew System::Windows::Forms::Label());
			this->lbl_EndDate = (gcnew System::Windows::Forms::Label());
			this->lbl_Position = (gcnew System::Windows::Forms::Label());
			this->lbl_CardStartDate = (gcnew System::Windows::Forms::Label());
			this->lbl_CardEndDate = (gcnew System::Windows::Forms::Label());
			this->btn_Verify = (gcnew System::Windows::Forms::Button());
			this->lbl_Verify = (gcnew System::Windows::Forms::Label());
			this->btn_Exit = (gcnew System::Windows::Forms::Button());
			this->cbm_Status = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// lbl_Prompt_OPTID
			// 
			this->lbl_Prompt_OPTID->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_OPTID->AutoSize = true;
			this->lbl_Prompt_OPTID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_OPTID->Location = System::Drawing::Point(343, 64);
			this->lbl_Prompt_OPTID->Name = L"lbl_Prompt_OPTID";
			this->lbl_Prompt_OPTID->Size = System::Drawing::Size(74, 18);
			this->lbl_Prompt_OPTID->TabIndex = 0;
			this->lbl_Prompt_OPTID->Text = L"OPT编号";
			// 
			// lbl_Prompt_Status
			// 
			this->lbl_Prompt_Status->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Status->AutoSize = true;
			this->lbl_Prompt_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Status->Location = System::Drawing::Point(537, 66);
			this->lbl_Prompt_Status->Name = L"lbl_Prompt_Status";
			this->lbl_Prompt_Status->Size = System::Drawing::Size(40, 18);
			this->lbl_Prompt_Status->TabIndex = 2;
			this->lbl_Prompt_Status->Text = L"状态";
			// 
			// lbl_Prompt_MemId
			// 
			this->lbl_Prompt_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_MemId->AutoSize = true;
			this->lbl_Prompt_MemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_MemId->Location = System::Drawing::Point(79, 64);
			this->lbl_Prompt_MemId->Name = L"lbl_Prompt_MemId";
			this->lbl_Prompt_MemId->Size = System::Drawing::Size(72, 18);
			this->lbl_Prompt_MemId->TabIndex = 4;
			this->lbl_Prompt_MemId->Text = L"成员编号";
			// 
			// txt_MemId
			// 
			this->txt_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_MemId->BackColor = System::Drawing::Color::White;
			this->txt_MemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_MemId->Location = System::Drawing::Point(180, 63);
			this->txt_MemId->Name = L"txt_MemId";
			this->txt_MemId->Size = System::Drawing::Size(120, 22);
			this->txt_MemId->TabIndex = 5;
			this->txt_MemId->Visible = false;
			// 
			// lbl_Prompt_Title
			// 
			this->lbl_Prompt_Title->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Title->AutoSize = true;
			this->lbl_Prompt_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Title->Location = System::Drawing::Point(111, 336);
			this->lbl_Prompt_Title->Name = L"lbl_Prompt_Title";
			this->lbl_Prompt_Title->Size = System::Drawing::Size(40, 18);
			this->lbl_Prompt_Title->TabIndex = 6;
			this->lbl_Prompt_Title->Text = L"头衔";
			// 
			// lbl_Prompt_EndDate
			// 
			this->lbl_Prompt_EndDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_EndDate->AutoSize = true;
			this->lbl_Prompt_EndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_EndDate->Location = System::Drawing::Point(345, 284);
			this->lbl_Prompt_EndDate->Name = L"lbl_Prompt_EndDate";
			this->lbl_Prompt_EndDate->Size = System::Drawing::Size(72, 18);
			this->lbl_Prompt_EndDate->TabIndex = 7;
			this->lbl_Prompt_EndDate->Text = L"结束日期";
			// 
			// lbl_Prompt_StartDate
			// 
			this->lbl_Prompt_StartDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_StartDate->AutoSize = true;
			this->lbl_Prompt_StartDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_StartDate->Location = System::Drawing::Point(79, 284);
			this->lbl_Prompt_StartDate->Name = L"lbl_Prompt_StartDate";
			this->lbl_Prompt_StartDate->Size = System::Drawing::Size(72, 18);
			this->lbl_Prompt_StartDate->TabIndex = 8;
			this->lbl_Prompt_StartDate->Text = L"开始日期";
			// 
			// lbl_Prompt_StfId
			// 
			this->lbl_Prompt_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_StfId->AutoSize = true;
			this->lbl_Prompt_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfId->Location = System::Drawing::Point(79, 235);
			this->lbl_Prompt_StfId->Name = L"lbl_Prompt_StfId";
			this->lbl_Prompt_StfId->Size = System::Drawing::Size(72, 18);
			this->lbl_Prompt_StfId->TabIndex = 9;
			this->lbl_Prompt_StfId->Text = L"员工编号";
			// 
			// txt_StfId
			// 
			this->txt_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_StfId->BackColor = System::Drawing::Color::White;
			this->txt_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_StfId->Location = System::Drawing::Point(180, 234);
			this->txt_StfId->Name = L"txt_StfId";
			this->txt_StfId->Size = System::Drawing::Size(120, 22);
			this->txt_StfId->TabIndex = 10;
			this->txt_StfId->Visible = false;
			// 
			// txt_StartDate
			// 
			this->txt_StartDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_StartDate->BackColor = System::Drawing::Color::White;
			this->txt_StartDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_StartDate->Location = System::Drawing::Point(180, 283);
			this->txt_StartDate->Name = L"txt_StartDate";
			this->txt_StartDate->Size = System::Drawing::Size(120, 22);
			this->txt_StartDate->TabIndex = 11;
			this->txt_StartDate->Visible = false;
			// 
			// txt_CardNumber
			// 
			this->txt_CardNumber->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_CardNumber->BackColor = System::Drawing::Color::White;
			this->txt_CardNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_CardNumber->Location = System::Drawing::Point(180, 405);
			this->txt_CardNumber->Name = L"txt_CardNumber";
			this->txt_CardNumber->Size = System::Drawing::Size(120, 22);
			this->txt_CardNumber->TabIndex = 12;
			this->txt_CardNumber->Visible = false;
			// 
			// txt_Position
			// 
			this->txt_Position->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Position->BackColor = System::Drawing::Color::White;
			this->txt_Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Position->Location = System::Drawing::Point(444, 335);
			this->txt_Position->Name = L"txt_Position";
			this->txt_Position->Size = System::Drawing::Size(120, 22);
			this->txt_Position->TabIndex = 13;
			this->txt_Position->Visible = false;
			// 
			// txt_Title
			// 
			this->txt_Title->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_Title->BackColor = System::Drawing::Color::White;
			this->txt_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_Title->Location = System::Drawing::Point(180, 335);
			this->txt_Title->Name = L"txt_Title";
			this->txt_Title->Size = System::Drawing::Size(120, 22);
			this->txt_Title->TabIndex = 14;
			this->txt_Title->Visible = false;
			// 
			// txt_EndDate
			// 
			this->txt_EndDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_EndDate->BackColor = System::Drawing::Color::White;
			this->txt_EndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_EndDate->Location = System::Drawing::Point(444, 283);
			this->txt_EndDate->Name = L"txt_EndDate";
			this->txt_EndDate->Size = System::Drawing::Size(120, 22);
			this->txt_EndDate->TabIndex = 15;
			this->txt_EndDate->Visible = false;
			// 
			// lbl_Prompt_CardNumber
			// 
			this->lbl_Prompt_CardNumber->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_CardNumber->AutoSize = true;
			this->lbl_Prompt_CardNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_CardNumber->Location = System::Drawing::Point(77, 406);
			this->lbl_Prompt_CardNumber->Name = L"lbl_Prompt_CardNumber";
			this->lbl_Prompt_CardNumber->Size = System::Drawing::Size(74, 18);
			this->lbl_Prompt_CardNumber->TabIndex = 16;
			this->lbl_Prompt_CardNumber->Text = L"CAD编号";
			// 
			// lbl_Prompt_Position
			// 
			this->lbl_Prompt_Position->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Position->AutoSize = true;
			this->lbl_Prompt_Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_Position->Location = System::Drawing::Point(377, 336);
			this->lbl_Prompt_Position->Name = L"lbl_Prompt_Position";
			this->lbl_Prompt_Position->Size = System::Drawing::Size(40, 18);
			this->lbl_Prompt_Position->TabIndex = 17;
			this->lbl_Prompt_Position->Text = L"职位";
			// 
			// lbl_Prompt_CardEndDate
			// 
			this->lbl_Prompt_CardEndDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_CardEndDate->AutoSize = true;
			this->lbl_Prompt_CardEndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_CardEndDate->Location = System::Drawing::Point(570, 407);
			this->lbl_Prompt_CardEndDate->Name = L"lbl_Prompt_CardEndDate";
			this->lbl_Prompt_CardEndDate->Size = System::Drawing::Size(106, 18);
			this->lbl_Prompt_CardEndDate->TabIndex = 18;
			this->lbl_Prompt_CardEndDate->Text = L"CAD失效日期";
			// 
			// lbl_Prompt_CardStartDate
			// 
			this->lbl_Prompt_CardStartDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_CardStartDate->AutoSize = true;
			this->lbl_Prompt_CardStartDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_CardStartDate->Location = System::Drawing::Point(311, 406);
			this->lbl_Prompt_CardStartDate->Name = L"lbl_Prompt_CardStartDate";
			this->lbl_Prompt_CardStartDate->Size = System::Drawing::Size(106, 18);
			this->lbl_Prompt_CardStartDate->TabIndex = 19;
			this->lbl_Prompt_CardStartDate->Text = L"CAD生效日期";
			// 
			// txt_CardEndDate
			// 
			this->txt_CardEndDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_CardEndDate->BackColor = System::Drawing::Color::White;
			this->txt_CardEndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_CardEndDate->Location = System::Drawing::Point(692, 406);
			this->txt_CardEndDate->Name = L"txt_CardEndDate";
			this->txt_CardEndDate->Size = System::Drawing::Size(116, 22);
			this->txt_CardEndDate->TabIndex = 20;
			this->txt_CardEndDate->Visible = false;
			// 
			// txt_CardStartDate
			// 
			this->txt_CardStartDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->txt_CardStartDate->BackColor = System::Drawing::Color::White;
			this->txt_CardStartDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txt_CardStartDate->Location = System::Drawing::Point(444, 405);
			this->txt_CardStartDate->Name = L"txt_CardStartDate";
			this->txt_CardStartDate->Size = System::Drawing::Size(120, 22);
			this->txt_CardStartDate->TabIndex = 21;
			this->txt_CardStartDate->Visible = false;
			// 
			// btn_ChangeInfo
			// 
			this->btn_ChangeInfo->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_ChangeInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ChangeInfo->Location = System::Drawing::Point(131, 469);
			this->btn_ChangeInfo->Name = L"btn_ChangeInfo";
			this->btn_ChangeInfo->Size = System::Drawing::Size(118, 48);
			this->btn_ChangeInfo->TabIndex = 22;
			this->btn_ChangeInfo->Text = L"改变信息";
			this->btn_ChangeInfo->UseVisualStyleBackColor = true;
			this->btn_ChangeInfo->Click += gcnew System::EventHandler(this, &OPTInfoPage::btn_ChangeInfo_Click);
			// 
			// btn_ChangeConfirm
			// 
			this->btn_ChangeConfirm->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_ChangeConfirm->Location = System::Drawing::Point(434, 469);
			this->btn_ChangeConfirm->Name = L"btn_ChangeConfirm";
			this->btn_ChangeConfirm->Size = System::Drawing::Size(118, 48);
			this->btn_ChangeConfirm->TabIndex = 23;
			this->btn_ChangeConfirm->Text = L"确认";
			this->btn_ChangeConfirm->UseVisualStyleBackColor = true;
			this->btn_ChangeConfirm->Visible = false;
			this->btn_ChangeConfirm->Click += gcnew System::EventHandler(this, &OPTInfoPage::btn_ChangeConfirm_Click);
			// 
			// btn_ChangeCancel
			// 
			this->btn_ChangeCancel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_ChangeCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_ChangeCancel->Location = System::Drawing::Point(584, 469);
			this->btn_ChangeCancel->Name = L"btn_ChangeCancel";
			this->btn_ChangeCancel->Size = System::Drawing::Size(118, 48);
			this->btn_ChangeCancel->TabIndex = 24;
			this->btn_ChangeCancel->Text = L"取消";
			this->btn_ChangeCancel->UseVisualStyleBackColor = true;
			this->btn_ChangeCancel->Visible = false;
			this->btn_ChangeCancel->Click += gcnew System::EventHandler(this, &OPTInfoPage::btn_ChangeCancel_Click);
			// 
			// lbl_PageName
			// 
			this->lbl_PageName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_PageName->AutoSize = true;
			this->lbl_PageName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_PageName->Location = System::Drawing::Point(356, 9);
			this->lbl_PageName->Name = L"lbl_PageName";
			this->lbl_PageName->Size = System::Drawing::Size(133, 33);
			this->lbl_PageName->TabIndex = 25;
			this->lbl_PageName->Text = L"OPT信息";
			// 
			// lbl_Prompt_MemName
			// 
			this->lbl_Prompt_MemName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_MemName->AutoSize = true;
			this->lbl_Prompt_MemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_MemName->Location = System::Drawing::Point(79, 129);
			this->lbl_Prompt_MemName->Name = L"lbl_Prompt_MemName";
			this->lbl_Prompt_MemName->Size = System::Drawing::Size(72, 18);
			this->lbl_Prompt_MemName->TabIndex = 26;
			this->lbl_Prompt_MemName->Text = L"成员姓名";
			// 
			// lbl_Prompt_Gender
			// 
			this->lbl_Prompt_Gender->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Gender->AutoSize = true;
			this->lbl_Prompt_Gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Gender->Location = System::Drawing::Point(377, 129);
			this->lbl_Prompt_Gender->Name = L"lbl_Prompt_Gender";
			this->lbl_Prompt_Gender->Size = System::Drawing::Size(40, 18);
			this->lbl_Prompt_Gender->TabIndex = 28;
			this->lbl_Prompt_Gender->Text = L"性别";
			// 
			// lbl_Prompt_Email
			// 
			this->lbl_Prompt_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Email->AutoSize = true;
			this->lbl_Prompt_Email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Email->Location = System::Drawing::Point(111, 172);
			this->lbl_Prompt_Email->Name = L"lbl_Prompt_Email";
			this->lbl_Prompt_Email->Size = System::Drawing::Size(40, 18);
			this->lbl_Prompt_Email->TabIndex = 30;
			this->lbl_Prompt_Email->Text = L"邮箱";
			// 
			// lbl_Prompt_Phone
			// 
			this->lbl_Prompt_Phone->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_Phone->AutoSize = true;
			this->lbl_Prompt_Phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_Phone->Location = System::Drawing::Point(537, 178);
			this->lbl_Prompt_Phone->Name = L"lbl_Prompt_Phone";
			this->lbl_Prompt_Phone->Size = System::Drawing::Size(40, 18);
			this->lbl_Prompt_Phone->TabIndex = 32;
			this->lbl_Prompt_Phone->Text = L"电话";
			// 
			// lbl_Prompt_WeChat
			// 
			this->lbl_Prompt_WeChat->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_WeChat->AutoSize = true;
			this->lbl_Prompt_WeChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Prompt_WeChat->Location = System::Drawing::Point(377, 172);
			this->lbl_Prompt_WeChat->Name = L"lbl_Prompt_WeChat";
			this->lbl_Prompt_WeChat->Size = System::Drawing::Size(40, 18);
			this->lbl_Prompt_WeChat->TabIndex = 34;
			this->lbl_Prompt_WeChat->Text = L"微信";
			// 
			// lbl_Prompt_StfName
			// 
			this->lbl_Prompt_StfName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Prompt_StfName->AutoSize = true;
			this->lbl_Prompt_StfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_Prompt_StfName->Location = System::Drawing::Point(345, 235);
			this->lbl_Prompt_StfName->Name = L"lbl_Prompt_StfName";
			this->lbl_Prompt_StfName->Size = System::Drawing::Size(72, 18);
			this->lbl_Prompt_StfName->TabIndex = 36;
			this->lbl_Prompt_StfName->Text = L"员工姓名";
			// 
			// lbl_error
			// 
			this->lbl_error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_error->AutoSize = true;
			this->lbl_error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_error->ForeColor = System::Drawing::Color::Red;
			this->lbl_error->Location = System::Drawing::Point(336, 540);
			this->lbl_error->Name = L"lbl_error";
			this->lbl_error->Size = System::Drawing::Size(169, 31);
			this->lbl_error->TabIndex = 38;
			this->lbl_error->Text = L"System error";
			this->lbl_error->Visible = false;
			// 
			// btn_DeleteAll
			// 
			this->btn_DeleteAll->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_DeleteAll->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_DeleteAll->ForeColor = System::Drawing::Color::Red;
			this->btn_DeleteAll->Location = System::Drawing::Point(285, 469);
			this->btn_DeleteAll->Name = L"btn_DeleteAll";
			this->btn_DeleteAll->Size = System::Drawing::Size(118, 48);
			this->btn_DeleteAll->TabIndex = 39;
			this->btn_DeleteAll->Text = L"删除记录";
			this->btn_DeleteAll->UseVisualStyleBackColor = true;
			this->btn_DeleteAll->Click += gcnew System::EventHandler(this, &OPTInfoPage::btn_DeleteAllButton_Click);
			// 
			// btn_DeleteConfirm
			// 
			this->btn_DeleteConfirm->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_DeleteConfirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_DeleteConfirm->ForeColor = System::Drawing::Color::Red;
			this->btn_DeleteConfirm->Location = System::Drawing::Point(434, 469);
			this->btn_DeleteConfirm->Name = L"btn_DeleteConfirm";
			this->btn_DeleteConfirm->Size = System::Drawing::Size(118, 48);
			this->btn_DeleteConfirm->TabIndex = 40;
			this->btn_DeleteConfirm->Text = L"确认";
			this->btn_DeleteConfirm->UseVisualStyleBackColor = true;
			this->btn_DeleteConfirm->Visible = false;
			this->btn_DeleteConfirm->Click += gcnew System::EventHandler(this, &OPTInfoPage::btn_DeleteConfirm_Click);
			// 
			// btn_DeleteCancel
			// 
			this->btn_DeleteCancel->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_DeleteCancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_DeleteCancel->ForeColor = System::Drawing::Color::Red;
			this->btn_DeleteCancel->Location = System::Drawing::Point(584, 469);
			this->btn_DeleteCancel->Name = L"btn_DeleteCancel";
			this->btn_DeleteCancel->Size = System::Drawing::Size(118, 48);
			this->btn_DeleteCancel->TabIndex = 41;
			this->btn_DeleteCancel->Text = L"取消";
			this->btn_DeleteCancel->UseVisualStyleBackColor = true;
			this->btn_DeleteCancel->Visible = false;
			this->btn_DeleteCancel->Click += gcnew System::EventHandler(this, &OPTInfoPage::btn_DeleteCancel_Click);
			// 
			// lbl_Email
			// 
			this->lbl_Email->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Email->AutoSize = true;
			this->lbl_Email->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Email->Location = System::Drawing::Point(180, 175);
			this->lbl_Email->Name = L"lbl_Email";
			this->lbl_Email->Size = System::Drawing::Size(31, 16);
			this->lbl_Email->TabIndex = 42;
			this->lbl_Email->Text = L"N/A";
			// 
			// lbl_StfName
			// 
			this->lbl_StfName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_StfName->AutoSize = true;
			this->lbl_StfName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_StfName->Location = System::Drawing::Point(444, 238);
			this->lbl_StfName->Name = L"lbl_StfName";
			this->lbl_StfName->Size = System::Drawing::Size(31, 16);
			this->lbl_StfName->TabIndex = 43;
			this->lbl_StfName->Text = L"N/A";
			// 
			// lbl_Phone
			// 
			this->lbl_Phone->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Phone->AutoSize = true;
			this->lbl_Phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Phone->Location = System::Drawing::Point(621, 181);
			this->lbl_Phone->Name = L"lbl_Phone";
			this->lbl_Phone->Size = System::Drawing::Size(31, 16);
			this->lbl_Phone->TabIndex = 44;
			this->lbl_Phone->Text = L"N/A";
			// 
			// lbl_MemName
			// 
			this->lbl_MemName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_MemName->AutoSize = true;
			this->lbl_MemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_MemName->Location = System::Drawing::Point(180, 132);
			this->lbl_MemName->Name = L"lbl_MemName";
			this->lbl_MemName->Size = System::Drawing::Size(31, 16);
			this->lbl_MemName->TabIndex = 45;
			this->lbl_MemName->Text = L"N/A";
			// 
			// lbl_WeChat
			// 
			this->lbl_WeChat->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_WeChat->AutoSize = true;
			this->lbl_WeChat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_WeChat->Location = System::Drawing::Point(444, 175);
			this->lbl_WeChat->Name = L"lbl_WeChat";
			this->lbl_WeChat->Size = System::Drawing::Size(31, 16);
			this->lbl_WeChat->TabIndex = 46;
			this->lbl_WeChat->Text = L"N/A";
			// 
			// lbl_Gender
			// 
			this->lbl_Gender->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Gender->AutoSize = true;
			this->lbl_Gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Gender->Location = System::Drawing::Point(444, 132);
			this->lbl_Gender->Name = L"lbl_Gender";
			this->lbl_Gender->Size = System::Drawing::Size(31, 16);
			this->lbl_Gender->TabIndex = 47;
			this->lbl_Gender->Text = L"N/A";
			// 
			// lbl_OPTID
			// 
			this->lbl_OPTID->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_OPTID->AutoSize = true;
			this->lbl_OPTID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_OPTID->Location = System::Drawing::Point(444, 67);
			this->lbl_OPTID->Name = L"lbl_OPTID";
			this->lbl_OPTID->Size = System::Drawing::Size(31, 16);
			this->lbl_OPTID->TabIndex = 48;
			this->lbl_OPTID->Text = L"N/A";
			// 
			// lbl_MemId
			// 
			this->lbl_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_MemId->AutoSize = true;
			this->lbl_MemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_MemId->Location = System::Drawing::Point(180, 67);
			this->lbl_MemId->Name = L"lbl_MemId";
			this->lbl_MemId->Size = System::Drawing::Size(31, 16);
			this->lbl_MemId->TabIndex = 49;
			this->lbl_MemId->Text = L"N/A";
			// 
			// lbl_StfId
			// 
			this->lbl_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_StfId->AutoSize = true;
			this->lbl_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_StfId->Location = System::Drawing::Point(180, 238);
			this->lbl_StfId->Name = L"lbl_StfId";
			this->lbl_StfId->Size = System::Drawing::Size(31, 16);
			this->lbl_StfId->TabIndex = 50;
			this->lbl_StfId->Text = L"N/A";
			// 
			// lbl_StartDate
			// 
			this->lbl_StartDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_StartDate->AutoSize = true;
			this->lbl_StartDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_StartDate->Location = System::Drawing::Point(180, 287);
			this->lbl_StartDate->Name = L"lbl_StartDate";
			this->lbl_StartDate->Size = System::Drawing::Size(31, 16);
			this->lbl_StartDate->TabIndex = 51;
			this->lbl_StartDate->Text = L"N/A";
			// 
			// lbl_Title
			// 
			this->lbl_Title->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Title->AutoSize = true;
			this->lbl_Title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Title->Location = System::Drawing::Point(180, 339);
			this->lbl_Title->Name = L"lbl_Title";
			this->lbl_Title->Size = System::Drawing::Size(31, 16);
			this->lbl_Title->TabIndex = 52;
			this->lbl_Title->Text = L"N/A";
			// 
			// lbl_CardNumber
			// 
			this->lbl_CardNumber->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_CardNumber->AutoSize = true;
			this->lbl_CardNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_CardNumber->Location = System::Drawing::Point(180, 409);
			this->lbl_CardNumber->Name = L"lbl_CardNumber";
			this->lbl_CardNumber->Size = System::Drawing::Size(31, 16);
			this->lbl_CardNumber->TabIndex = 53;
			this->lbl_CardNumber->Text = L"N/A";
			// 
			// lbl_Status
			// 
			this->lbl_Status->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Status->AutoSize = true;
			this->lbl_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Status->Location = System::Drawing::Point(621, 69);
			this->lbl_Status->Name = L"lbl_Status";
			this->lbl_Status->Size = System::Drawing::Size(31, 16);
			this->lbl_Status->TabIndex = 54;
			this->lbl_Status->Text = L"N/A";
			// 
			// lbl_EndDate
			// 
			this->lbl_EndDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_EndDate->AutoSize = true;
			this->lbl_EndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_EndDate->Location = System::Drawing::Point(444, 287);
			this->lbl_EndDate->Name = L"lbl_EndDate";
			this->lbl_EndDate->Size = System::Drawing::Size(31, 16);
			this->lbl_EndDate->TabIndex = 55;
			this->lbl_EndDate->Text = L"N/A";
			// 
			// lbl_Position
			// 
			this->lbl_Position->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_Position->AutoSize = true;
			this->lbl_Position->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Position->Location = System::Drawing::Point(444, 339);
			this->lbl_Position->Name = L"lbl_Position";
			this->lbl_Position->Size = System::Drawing::Size(31, 16);
			this->lbl_Position->TabIndex = 56;
			this->lbl_Position->Text = L"N/A";
			// 
			// lbl_CardStartDate
			// 
			this->lbl_CardStartDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_CardStartDate->AutoSize = true;
			this->lbl_CardStartDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->lbl_CardStartDate->Location = System::Drawing::Point(444, 409);
			this->lbl_CardStartDate->Name = L"lbl_CardStartDate";
			this->lbl_CardStartDate->Size = System::Drawing::Size(31, 16);
			this->lbl_CardStartDate->TabIndex = 57;
			this->lbl_CardStartDate->Text = L"N/A";
			// 
			// lbl_CardEndDate
			// 
			this->lbl_CardEndDate->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->lbl_CardEndDate->AutoSize = true;
			this->lbl_CardEndDate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_CardEndDate->Location = System::Drawing::Point(692, 410);
			this->lbl_CardEndDate->Name = L"lbl_CardEndDate";
			this->lbl_CardEndDate->Size = System::Drawing::Size(31, 16);
			this->lbl_CardEndDate->TabIndex = 58;
			this->lbl_CardEndDate->Text = L"N/A";
			// 
			// btn_Verify
			// 
			this->btn_Verify->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Verify->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Verify->Location = System::Drawing::Point(638, 258);
			this->btn_Verify->Name = L"btn_Verify";
			this->btn_Verify->Size = System::Drawing::Size(116, 45);
			this->btn_Verify->TabIndex = 59;
			this->btn_Verify->Text = L"验证";
			this->btn_Verify->UseVisualStyleBackColor = true;
			this->btn_Verify->Visible = false;
			this->btn_Verify->Click += gcnew System::EventHandler(this, &OPTInfoPage::btn_Verify_Click);
			// 
			// lbl_Verify
			// 
			this->lbl_Verify->AutoSize = true;
			this->lbl_Verify->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Verify->ForeColor = System::Drawing::Color::Red;
			this->lbl_Verify->Location = System::Drawing::Point(645, 329);
			this->lbl_Verify->Name = L"lbl_Verify";
			this->lbl_Verify->Size = System::Drawing::Size(43, 20);
			this->lbl_Verify->TabIndex = 60;
			this->lbl_Verify->Text = L"无效";
			this->lbl_Verify->Visible = false;
			// 
			// btn_Exit
			// 
			this->btn_Exit->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_Exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Exit->Location = System::Drawing::Point(434, 469);
			this->btn_Exit->Name = L"btn_Exit";
			this->btn_Exit->Size = System::Drawing::Size(118, 48);
			this->btn_Exit->TabIndex = 61;
			this->btn_Exit->Text = L"退出";
			this->btn_Exit->UseVisualStyleBackColor = true;
			this->btn_Exit->Click += gcnew System::EventHandler(this, &OPTInfoPage::btn_Exit_Click);
			// 
			// cbm_Status
			// 
			this->cbm_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbm_Status->FormattingEnabled = true;
			this->cbm_Status->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Active", L"Invalid" });
			this->cbm_Status->Location = System::Drawing::Point(621, 63);
			this->cbm_Status->Name = L"cbm_Status";
			this->cbm_Status->Size = System::Drawing::Size(121, 24);
			this->cbm_Status->TabIndex = 62;
			this->cbm_Status->Visible = false;
			// 
			// OPTInfoPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(847, 594);
			this->Controls->Add(this->lbl_Status);
			this->Controls->Add(this->cbm_Status);
			this->Controls->Add(this->btn_Exit);
			this->Controls->Add(this->lbl_Verify);
			this->Controls->Add(this->btn_Verify);
			this->Controls->Add(this->lbl_error);
			this->Controls->Add(this->btn_DeleteCancel);
			this->Controls->Add(this->btn_DeleteConfirm);
			this->Controls->Add(this->btn_DeleteAll);
			this->Controls->Add(this->btn_ChangeCancel);
			this->Controls->Add(this->btn_ChangeConfirm);
			this->Controls->Add(this->btn_ChangeInfo);
			this->Controls->Add(this->lbl_Prompt_StfName);
			this->Controls->Add(this->lbl_Prompt_WeChat);
			this->Controls->Add(this->lbl_Prompt_Phone);
			this->Controls->Add(this->lbl_Prompt_Email);
			this->Controls->Add(this->lbl_Prompt_Gender);
			this->Controls->Add(this->lbl_Prompt_MemName);
			this->Controls->Add(this->lbl_Prompt_CardStartDate);
			this->Controls->Add(this->lbl_Prompt_CardEndDate);
			this->Controls->Add(this->lbl_Prompt_Position);
			this->Controls->Add(this->lbl_Prompt_CardNumber);
			this->Controls->Add(this->lbl_Prompt_StfId);
			this->Controls->Add(this->lbl_Prompt_StartDate);
			this->Controls->Add(this->lbl_Prompt_EndDate);
			this->Controls->Add(this->lbl_Prompt_Title);
			this->Controls->Add(this->lbl_Prompt_MemId);
			this->Controls->Add(this->lbl_Prompt_Status);
			this->Controls->Add(this->lbl_Prompt_OPTID);
			this->Controls->Add(this->lbl_CardEndDate);
			this->Controls->Add(this->lbl_CardStartDate);
			this->Controls->Add(this->lbl_Position);
			this->Controls->Add(this->lbl_EndDate);
			this->Controls->Add(this->lbl_CardNumber);
			this->Controls->Add(this->lbl_Title);
			this->Controls->Add(this->lbl_StartDate);
			this->Controls->Add(this->lbl_StfId);
			this->Controls->Add(this->lbl_MemId);
			this->Controls->Add(this->lbl_OPTID);
			this->Controls->Add(this->lbl_Gender);
			this->Controls->Add(this->lbl_WeChat);
			this->Controls->Add(this->lbl_MemName);
			this->Controls->Add(this->lbl_Phone);
			this->Controls->Add(this->lbl_StfName);
			this->Controls->Add(this->lbl_Email);
			this->Controls->Add(this->lbl_PageName);
			this->Controls->Add(this->txt_CardStartDate);
			this->Controls->Add(this->txt_CardEndDate);
			this->Controls->Add(this->txt_EndDate);
			this->Controls->Add(this->txt_Title);
			this->Controls->Add(this->txt_Position);
			this->Controls->Add(this->txt_CardNumber);
			this->Controls->Add(this->txt_StartDate);
			this->Controls->Add(this->txt_StfId);
			this->Controls->Add(this->txt_MemId);
			this->Name = L"OPTInfoPage";
			this->Text = L"OPT信息";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Database^ database;
		int^ _OPTId;
		PublicUserInfo^ _pui;
		PublicUserInfo::Auth _auth;
		
	private:
		Void Initialize();
		Void UpdateInfo();
		Void SetLableVisible();
		Void SetLableInvisible();
		Void SetBoxInvisible();
		Void SetBoxVisible();
		Void VerifyUpdate(int^ MemId, int^ StfId);
		Void btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_ChangeConfirm_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_ChangeCancel_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_DeleteConfirm_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_DeleteCancel_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_DeleteAllButton_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Verify_Click(System::Object^ sender, System::EventArgs^ e);
		Void btn_Exit_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
