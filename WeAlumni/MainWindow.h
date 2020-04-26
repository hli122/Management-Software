#pragma once
#include "Database.h"
#include "MemInfoPage.h"
#include "MemAddPage.h"
#include "StfInfoPage.h"
#include "StfAddPage.h"
#include "OrdInfoPage.h"
#include "OrdAddPage.h"
#include "RecInfoPage.h"
#include "OPTAddPage.h"
#include "OPTInfoPage.h"
#define MEM_SELECT_ALL "SELECT Member.Id AS 'MemberId', Member.Status AS 'MemberStatus', Member.Type AS 'MemberType', Member.Name AS 'MemberName', Member.Gender AS 'MemberGender', Member.Email AS 'MemberEmail' FROM Member ORDER BY Id ASC"
#define STF_SELECT_ALL "SELECT Staff.MemId AS 'ID', Member.Name As 'Name', Member.Gender AS 'Gender', Member.Email AS 'Email', Staff.Dept As 'Department', Staff.Position As 'Position', Staff.Auth As 'Auth' FROM Member, Staff WHERE Staff.MemId = Member.Id ORDER BY Staff.MemId ASC"
#define ORD_SELECT_ALL "SELECT Orders.Id AS 'OrderId', Orders.Status As 'Status', Orders.Time AS 'Time', Member.Name AS 'MemName', Member.Email As 'Email', Item.Name As 'ItmName', Orders.Amount As 'Amount', Item.Price As 'ItmPrice', Orders.Comment As 'Comment' FROM Orders, Member, Item WHERE Orders.MemId = Member.Id AND Orders.ItemId = Item.Id ORDER BY Member.Id ASC"
#define REC_SELECT_ALL "SELECT Record.Id AS 'RecordId', Record.Time AS 'Time', Record.StfId AS 'StfId', Record.Memname AS 'MemName', Staff.Dept AS 'Department', Staff.Position AS 'Position', Record.Action AS 'Action' FROM Record, Staff WHERE Staff.MemId = Record.StfId"
#define OPT_SELECT_ALL "SELECT OPT.Id AS 'OPT编号', OPT.Status AS '状态', (SELECT Member.Name FROM Member WHERE Member.Id = OPT.MemId)  AS '成员姓名' , (SELECT Member.Name FROM Member INNER JOIN Staff INNER JOIN OPT WHERE Member.Id = Staff.MemId AND Staff.MemId = OPT.StfId)  AS '员工姓名', OPT.StartDate AS '开始日期', OPT.EndDate AS '结束日期', OPT.Title AS '头衔', OPT.Position AS '职位' FROM OPT"

/*
 * MainWindow.h
 *
 * This file initializes the MainWindow's UI and declares the sub-functions required.
 *
 * @author: Hang Yuan
 * Revised: 3/27/20
 *          4/8/20 add member MainWindow
 *          4/12/20 add staff MainWindow and auth control for staff and member
 *          4/15/20 bug fix
 *			4/22/20 add record Mainwindow
 *          4/21/20 Added OPT MainWindow Part(Xiangdong Che)
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
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			Initialize();
		}
		MainWindow(PublicUserInfo^ pui) {
			InitializeComponent();
			_pui = pui;
			_Auth = pui->GetAuth();
			Initialize();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
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

	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
	private: System::Windows::Forms::MenuStrip^ ms_systemOptions;
	private: System::Windows::Forms::MenuStrip^ ms_panelOptions;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_system;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_database;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_help;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_member;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_staff;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_record;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_OPT;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_order;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_treasury;
	private: System::Windows::Forms::ToolStripMenuItem^ tsm_myInfo;
	private: System::Windows::Forms::Panel^ pan_staff;
	private: System::Windows::Forms::Panel^ pan_record;
	private: System::Windows::Forms::Panel^ pan_OPT;
	private: System::Windows::Forms::Panel^ pan_treasury;
	private: System::Windows::Forms::Button^ stf_btn_Add;
	private: System::Windows::Forms::Button^ stf_btn_Clear;
	private: System::Windows::Forms::Button^ stf_btn_Search;
	private: System::Windows::Forms::TextBox^ stf_txt_Name;
	private: System::Windows::Forms::TextBox^ stf_txt_Id;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Auth;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Dept;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Name;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Id;
	private: System::Windows::Forms::ComboBox^ stf_cmb_Auth;
	private: System::Windows::Forms::ComboBox^ stf_cmb_Dept;
	private: System::Windows::Forms::Label^ stf_lbl_Error;
	private: System::Windows::Forms::Label^ stf_lbl_Count;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Count;
	private: System::Windows::Forms::Splitter^ stf_splitter1;
	private: System::Windows::Forms::DataGridView^ stf_dataGridView;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_SearchResult;
	private: System::Windows::Forms::Splitter^ stf_splitter3;
	private: System::Windows::Forms::Splitter^ stf_splitter2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ pan_order;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_ViewInfo;
	private: System::Windows::Forms::Label^ ord_lbl_Error;
	private: System::Windows::Forms::Splitter^ ord_splitter_Error;
	private: System::Windows::Forms::Button^ ord_btn_Add;
	private: System::Windows::Forms::Button^ ord_btn_Clear;
	private: System::Windows::Forms::Button^ ord_btn_Search;
	private: System::Windows::Forms::Label^ ord_lbl_Count;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_Count;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_SearchResult;
	private: System::Windows::Forms::DataGridView^ ord_dataGridView;
	private: System::Windows::Forms::TextBox^ ord_txt_itmName;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_itmName;
	private: System::Windows::Forms::TextBox^ ord_txt_itmId;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_itmId;
	private: System::Windows::Forms::TextBox^ ord_txt_memName;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_memName;
	private: System::Windows::Forms::TextBox^ ord_txt_memId;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_memId;
	private: System::Windows::Forms::ComboBox^ ord_cmb_Status;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_Status;
	private: System::Windows::Forms::TextBox^ ord_txt_ordId;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_ordId;
	private: System::Windows::Forms::Splitter^ ord_splitter;
	private: System::Windows::Forms::Label^ Rec_lbl_Prompt_RecId;
	private: System::Windows::Forms::TextBox^ Rec_txt_RecId;
	private: System::Windows::Forms::Label^ rec_lbl_prompt_department;
	private: System::Windows::Forms::Label^ Rec_lbl_Prompt_MemName;
	private: System::Windows::Forms::Label^ Rec_lbl_Prompt_StfId;
	private: System::Windows::Forms::TextBox^ Rec_txt_MemName;
	private: System::Windows::Forms::TextBox^ Rec_txt_StfId;
	private: System::Windows::Forms::Button^ Rec_btn_RecSearch;
	private: System::Windows::Forms::TextBox^ Rec_txt_department;
	private: System::Windows::Forms::DataGridView^ Rec_dataGridView;
	private: System::Windows::Forms::Button^ Rec_btn_Clear;
	private: System::Windows::Forms::Label^ Rec_lbl_Error;
	private: System::Windows::Forms::Label^ rec_lbl_Count;
	private: System::Windows::Forms::Label^ rec_lbl_prompt_total;
	private: System::Windows::Forms::Panel^ pan_member;
	private: System::Windows::Forms::Label^ mem_lbl_Count;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Total;
	private: System::Windows::Forms::Label^ mem_Prompt_PgInfo;
	private: System::Windows::Forms::Label^ mem_Prompt_ViewInfo;
	private: System::Windows::Forms::Label^ mem_Prompt_Result;
	private: System::Windows::Forms::Label^ mem_lbl_error;
	private: System::Windows::Forms::Button^ mem_btn_Import;
	private: System::Windows::Forms::Button^ mem_btn_Add;
	private: System::Windows::Forms::Button^ mem_btn_Clear;
	private: System::Windows::Forms::Button^ mem_btn_Search;
	private: System::Windows::Forms::ComboBox^ mem_cmb_CareerStatus;
	private: System::Windows::Forms::DataGridView^ mem_dataGridView1;
	private: System::Windows::Forms::ComboBox^ mem_cmb_SearchAuth;
	private: System::Windows::Forms::ComboBox^ mem_cmb_Type;
	private: System::Windows::Forms::ComboBox^ mem_cmb_Status;
	private: System::Windows::Forms::TextBox^ mem_txt_Gender;
	private: System::Windows::Forms::TextBox^ mem_txt_Name;
	private: System::Windows::Forms::TextBox^ mem_txt_Major;
	private: System::Windows::Forms::TextBox^ mem_txt_Id;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_SearchAuth;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Major;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_CareerStatus;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Gender;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Name;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Type;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Status;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_Id;
	private: System::Windows::Forms::Splitter^ mem_splitter2;
	private: System::Windows::Forms::Splitter^ splitter2;
	private: System::Windows::Forms::DataGridView^ OPT_dataGridView;
	private: System::Windows::Forms::Splitter^ splitter1;
	private: System::Windows::Forms::Label^ OPT_lbl_Prompt_Active;
	private: System::Windows::Forms::Label^ OPT_lbl_Prompt_MemId;
	private: System::Windows::Forms::Label^ OPT_lbl_Prompt_MemName;
	private: System::Windows::Forms::Label^ OPT_lbl_Prompt_CardNumber;
	private: System::Windows::Forms::Label^ OPT_lbl_Prompt_OPTId;
	private: System::Windows::Forms::Label^ OPT_lbl_error;
	private: System::Windows::Forms::ComboBox^ OPT_cmb_Status;
	private: System::Windows::Forms::TextBox^ OPT_txt_MemId;
	private: System::Windows::Forms::TextBox^ OPT_txt_CardNumber;
	private: System::Windows::Forms::TextBox^ OPT_txt_MemName;
	private: System::Windows::Forms::TextBox^ OPT_txt_OPTId;
	private: System::Windows::Forms::Label^ OPT_lbl_Prompt_default;
	private: System::Windows::Forms::Label^ OPT_lbl_Count;
	private: System::Windows::Forms::Label^ OPT_lbl_Prompt_count;
	private: System::Windows::Forms::Label^ OPT_lbl_Prompt_result;
	private: System::Windows::Forms::Button^ OPT_btn_New;
	private: System::Windows::Forms::Button^ OPT_btn_Clear;
	private: System::Windows::Forms::Button^ OPT_btn_Search;
	private: System::Windows::Forms::Panel^ pan_myInfo;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			   this->pan_record = (gcnew System::Windows::Forms::Panel());
			   this->rec_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->rec_lbl_prompt_total = (gcnew System::Windows::Forms::Label());
			   this->Rec_lbl_Error = (gcnew System::Windows::Forms::Label());
			   this->Rec_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->Rec_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->Rec_btn_RecSearch = (gcnew System::Windows::Forms::Button());
			   this->Rec_txt_department = (gcnew System::Windows::Forms::TextBox());
			   this->Rec_txt_MemName = (gcnew System::Windows::Forms::TextBox());
			   this->Rec_txt_StfId = (gcnew System::Windows::Forms::TextBox());
			   this->Rec_txt_RecId = (gcnew System::Windows::Forms::TextBox());
			   this->rec_lbl_prompt_department = (gcnew System::Windows::Forms::Label());
			   this->Rec_lbl_Prompt_MemName = (gcnew System::Windows::Forms::Label());
			   this->Rec_lbl_Prompt_StfId = (gcnew System::Windows::Forms::Label());
			   this->Rec_lbl_Prompt_RecId = (gcnew System::Windows::Forms::Label());
			   this->pan_OPT = (gcnew System::Windows::Forms::Panel());
			   this->OPT_btn_New = (gcnew System::Windows::Forms::Button());
			   this->OPT_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->OPT_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->OPT_lbl_Prompt_default = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_count = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_result = (gcnew System::Windows::Forms::Label());
			   this->OPT_cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			   this->OPT_txt_MemId = (gcnew System::Windows::Forms::TextBox());
			   this->OPT_txt_CardNumber = (gcnew System::Windows::Forms::TextBox());
			   this->OPT_txt_MemName = (gcnew System::Windows::Forms::TextBox());
			   this->OPT_txt_OPTId = (gcnew System::Windows::Forms::TextBox());
			   this->OPT_lbl_error = (gcnew System::Windows::Forms::Label());
			   this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			   this->OPT_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			   this->OPT_lbl_Prompt_Active = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_MemId = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_MemName = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_CardNumber = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_OPTId = (gcnew System::Windows::Forms::Label());
			   this->pan_treasury = (gcnew System::Windows::Forms::Panel());
			   this->pan_myInfo = (gcnew System::Windows::Forms::Panel());
			   this->pan_order = (gcnew System::Windows::Forms::Panel());
			   this->ord_lbl_Prompt_ViewInfo = (gcnew System::Windows::Forms::Label());
			   this->ord_lbl_Error = (gcnew System::Windows::Forms::Label());
			   this->ord_splitter_Error = (gcnew System::Windows::Forms::Splitter());
			   this->ord_btn_Add = (gcnew System::Windows::Forms::Button());
			   this->ord_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->ord_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->ord_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->ord_lbl_Prompt_Count = (gcnew System::Windows::Forms::Label());
			   this->ord_lbl_Prompt_SearchResult = (gcnew System::Windows::Forms::Label());
			   this->ord_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->ord_txt_itmName = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_itmName = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_itmId = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_itmId = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_memName = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_memName = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_memId = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_memId = (gcnew System::Windows::Forms::Label());
			   this->ord_cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			   this->ord_lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_ordId = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_ordId = (gcnew System::Windows::Forms::Label());
			   this->ord_splitter = (gcnew System::Windows::Forms::Splitter());
			   this->pan_member = (gcnew System::Windows::Forms::Panel());
			   this->mem_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Total = (gcnew System::Windows::Forms::Label());
			   this->mem_Prompt_PgInfo = (gcnew System::Windows::Forms::Label());
			   this->mem_Prompt_ViewInfo = (gcnew System::Windows::Forms::Label());
			   this->mem_Prompt_Result = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_error = (gcnew System::Windows::Forms::Label());
			   this->mem_btn_Import = (gcnew System::Windows::Forms::Button());
			   this->mem_btn_Add = (gcnew System::Windows::Forms::Button());
			   this->mem_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->mem_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->mem_cmb_CareerStatus = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->mem_cmb_SearchAuth = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_cmb_Type = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_txt_Gender = (gcnew System::Windows::Forms::TextBox());
			   this->mem_txt_Name = (gcnew System::Windows::Forms::TextBox());
			   this->mem_txt_Major = (gcnew System::Windows::Forms::TextBox());
			   this->mem_txt_Id = (gcnew System::Windows::Forms::TextBox());
			   this->mem_lbl_Prompt_SearchAuth = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Major = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_CareerStatus = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Gender = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Type = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			   this->mem_splitter2 = (gcnew System::Windows::Forms::Splitter());
			   this->pan_staff = (gcnew System::Windows::Forms::Panel());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_SearchResult = (gcnew System::Windows::Forms::Label());
			   this->stf_splitter3 = (gcnew System::Windows::Forms::Splitter());
			   this->stf_splitter2 = (gcnew System::Windows::Forms::Splitter());
			   this->stf_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->stf_splitter1 = (gcnew System::Windows::Forms::Splitter());
			   this->stf_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Count = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Error = (gcnew System::Windows::Forms::Label());
			   this->stf_cmb_Auth = (gcnew System::Windows::Forms::ComboBox());
			   this->stf_cmb_Dept = (gcnew System::Windows::Forms::ComboBox());
			   this->stf_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->stf_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->stf_txt_Name = (gcnew System::Windows::Forms::TextBox());
			   this->stf_txt_Id = (gcnew System::Windows::Forms::TextBox());
			   this->stf_lbl_Prompt_Auth = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Dept = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			   this->stf_btn_Add = (gcnew System::Windows::Forms::Button());
			   this->pan_OPT = (gcnew System::Windows::Forms::Panel());
			   this->pan_treasury = (gcnew System::Windows::Forms::Panel());
			   this->pan_myInfo = (gcnew System::Windows::Forms::Panel());
			   this->pan_record = (gcnew System::Windows::Forms::Panel());
			   this->ms_panelOptions = (gcnew System::Windows::Forms::MenuStrip());
			   this->tsm_member = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_staff = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_record = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_OPT = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_order = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_treasury = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_myInfo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ms_systemOptions = (gcnew System::Windows::Forms::MenuStrip());
			   this->tsm_system = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_database = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripContainer1->ContentPanel->SuspendLayout();
			   this->toolStripContainer1->LeftToolStripPanel->SuspendLayout();
			   this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			   this->toolStripContainer1->SuspendLayout();
			   this->pan_record->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Rec_dataGridView))->BeginInit();
			   this->pan_OPT->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OPT_dataGridView))->BeginInit();
			   this->pan_order->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ord_dataGridView))->BeginInit();
			   this->pan_member->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mem_dataGridView1))->BeginInit();
			   this->pan_staff->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stf_dataGridView))->BeginInit();
			   this->ms_panelOptions->SuspendLayout();
			   this->ms_systemOptions->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // toolStripContainer1
			   // 
			   // 
			   // toolStripContainer1.ContentPanel
			   // 
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_OPT);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_treasury);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_myInfo);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_order);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_member);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_staff);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_record);
			   this->toolStripContainer1->ContentPanel->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(982, 635);
			   this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			   // 
			   // toolStripContainer1.LeftToolStripPanel
			   // 
			   this->toolStripContainer1->LeftToolStripPanel->Controls->Add(this->ms_panelOptions);
			   this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
			   this->toolStripContainer1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->toolStripContainer1->Name = L"toolStripContainer1";
			   this->toolStripContainer1->Size = System::Drawing::Size(1132, 660);
			   this->toolStripContainer1->TabIndex = 0;
			   this->toolStripContainer1->Text = L"toolStripContainer1";
			   // 
			   // toolStripContainer1.TopToolStripPanel
			   // 
			   this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->ms_systemOptions);
			   // 
			   // pan_record
			   // 
			   this->pan_record->Controls->Add(this->rec_lbl_Count);
			   this->pan_record->Controls->Add(this->rec_lbl_prompt_total);
			   this->pan_record->Controls->Add(this->Rec_lbl_Error);
			   this->pan_record->Controls->Add(this->Rec_dataGridView);
			   this->pan_record->Controls->Add(this->Rec_btn_Clear);
			   this->pan_record->Controls->Add(this->Rec_btn_RecSearch);
			   this->pan_record->Controls->Add(this->Rec_txt_department);
			   this->pan_record->Controls->Add(this->Rec_txt_MemName);
			   this->pan_record->Controls->Add(this->Rec_txt_StfId);
			   this->pan_record->Controls->Add(this->Rec_txt_RecId);
			   this->pan_record->Controls->Add(this->rec_lbl_prompt_department);
			   this->pan_record->Controls->Add(this->Rec_lbl_Prompt_MemName);
			   this->pan_record->Controls->Add(this->Rec_lbl_Prompt_StfId);
			   this->pan_record->Controls->Add(this->Rec_lbl_Prompt_RecId);
			   this->pan_record->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_record->Location = System::Drawing::Point(0, 0);
			   this->pan_record->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_record->Name = L"pan_record";
			   this->pan_record->Size = System::Drawing::Size(1359, 784);
			   this->pan_record->TabIndex = 4;
			   // 
			   // rec_lbl_Count
			   // 
			   this->rec_lbl_Count->AutoSize = true;
			   this->rec_lbl_Count->Location = System::Drawing::Point(138, 338);
			   this->rec_lbl_Count->Name = L"rec_lbl_Count";
			   this->rec_lbl_Count->Size = System::Drawing::Size(16, 17);
			   this->rec_lbl_Count->TabIndex = 13;
			   this->rec_lbl_Count->Text = L"0";
			   // 
			   // rec_lbl_prompt_total
			   // 
			   this->rec_lbl_prompt_total->AutoSize = true;
			   this->rec_lbl_prompt_total->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->rec_lbl_prompt_total->Location = System::Drawing::Point(61, 335);
			   this->rec_lbl_prompt_total->Name = L"rec_lbl_prompt_total";
			   this->rec_lbl_prompt_total->Size = System::Drawing::Size(62, 20);
			   this->rec_lbl_prompt_total->TabIndex = 12;
			   this->rec_lbl_prompt_total->Text = L"总计:";
			   // 
			   // Rec_lbl_Error
			   // 
			   this->Rec_lbl_Error->AutoSize = true;
			   this->Rec_lbl_Error->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_lbl_Error->ForeColor = System::Drawing::Color::Red;
			   this->Rec_lbl_Error->Location = System::Drawing::Point(555, 320);
			   this->Rec_lbl_Error->Name = L"Rec_lbl_Error";
			   this->Rec_lbl_Error->Size = System::Drawing::Size(93, 20);
			   this->Rec_lbl_Error->TabIndex = 11;
			   this->Rec_lbl_Error->Text = L"错误信息";
			   // 
			   // Rec_dataGridView
			   // 
			   this->Rec_dataGridView->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			   this->Rec_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->Rec_dataGridView->Location = System::Drawing::Point(53, 385);
			   this->Rec_dataGridView->Name = L"Rec_dataGridView";
			   this->Rec_dataGridView->RowHeadersWidth = 51;
			   this->Rec_dataGridView->RowTemplate->Height = 24;
			   this->Rec_dataGridView->Size = System::Drawing::Size(1121, 276);
			   this->Rec_dataGridView->TabIndex = 10;
			   // 
			   // Rec_btn_Clear
			   // 
			   this->Rec_btn_Clear->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_btn_Clear->Location = System::Drawing::Point(837, 115);
			   this->Rec_btn_Clear->Name = L"Rec_btn_Clear";
			   this->Rec_btn_Clear->Size = System::Drawing::Size(79, 37);
			   this->Rec_btn_Clear->TabIndex = 9;
			   this->Rec_btn_Clear->Text = L"清空";
			   this->Rec_btn_Clear->UseVisualStyleBackColor = true;
			   this->Rec_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::Rec_btn_Clear_Click);
			   // 
			   // Rec_btn_RecSearch
			   // 
			   this->Rec_btn_RecSearch->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_btn_RecSearch->Location = System::Drawing::Point(837, 50);
			   this->Rec_btn_RecSearch->Name = L"Rec_btn_RecSearch";
			   this->Rec_btn_RecSearch->Size = System::Drawing::Size(79, 37);
			   this->Rec_btn_RecSearch->TabIndex = 8;
			   this->Rec_btn_RecSearch->Text = L"查询";
			   this->Rec_btn_RecSearch->UseVisualStyleBackColor = true;
			   this->Rec_btn_RecSearch->Click += gcnew System::EventHandler(this, &MainWindow::Rec_btn_Search_Click);
			   // 
			   // Rec_txt_department
			   // 
			   this->Rec_txt_department->Location = System::Drawing::Point(587, 111);
			   this->Rec_txt_department->Name = L"Rec_txt_department";
			   this->Rec_txt_department->Size = System::Drawing::Size(100, 22);
			   this->Rec_txt_department->TabIndex = 7;
			   // 
			   // Rec_txt_MemName
			   // 
			   this->Rec_txt_MemName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->Rec_txt_MemName->Location = System::Drawing::Point(587, 56);
			   this->Rec_txt_MemName->Name = L"Rec_txt_MemName";
			   this->Rec_txt_MemName->Size = System::Drawing::Size(100, 22);
			   this->Rec_txt_MemName->TabIndex = 6;
			   // 
			   // Rec_txt_StfId
			   // 
			   this->Rec_txt_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->Rec_txt_StfId->Location = System::Drawing::Point(185, 112);
			   this->Rec_txt_StfId->Name = L"Rec_txt_StfId";
			   this->Rec_txt_StfId->Size = System::Drawing::Size(100, 22);
			   this->Rec_txt_StfId->TabIndex = 5;
			   // 
			   // Rec_txt_RecId
			   // 
			   this->Rec_txt_RecId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->Rec_txt_RecId->Location = System::Drawing::Point(185, 57);
			   this->Rec_txt_RecId->Name = L"Rec_txt_RecId";
			   this->Rec_txt_RecId->Size = System::Drawing::Size(100, 22);
			   this->Rec_txt_RecId->TabIndex = 4;
			   // 
			   // rec_lbl_prompt_department
			   // 
			   this->rec_lbl_prompt_department->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->rec_lbl_prompt_department->AutoSize = true;
			   this->rec_lbl_prompt_department->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->rec_lbl_prompt_department->Location = System::Drawing::Point(465, 115);
			   this->rec_lbl_prompt_department->Name = L"rec_lbl_prompt_department";
			   this->rec_lbl_prompt_department->Size = System::Drawing::Size(114, 20);
			   this->rec_lbl_prompt_department->TabIndex = 3;
			   this->rec_lbl_prompt_department->Text = L"所在部门：";
			   // 
			   // Rec_lbl_Prompt_MemName
			   // 
			   this->Rec_lbl_Prompt_MemName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->Rec_lbl_Prompt_MemName->AutoSize = true;
			   this->Rec_lbl_Prompt_MemName->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_lbl_Prompt_MemName->Location = System::Drawing::Point(465, 57);
			   this->Rec_lbl_Prompt_MemName->Name = L"Rec_lbl_Prompt_MemName";
			   this->Rec_lbl_Prompt_MemName->Size = System::Drawing::Size(114, 20);
			   this->Rec_lbl_Prompt_MemName->TabIndex = 2;
			   this->Rec_lbl_Prompt_MemName->Text = L"员工姓名：";
			   this->Rec_lbl_Prompt_MemName->Click += gcnew System::EventHandler(this, &MainWindow::lbl_Prompt_MemName_Click);
			   // 
			   // Rec_lbl_Prompt_StfId
			   // 
			   this->Rec_lbl_Prompt_StfId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->Rec_lbl_Prompt_StfId->AutoSize = true;
			   this->Rec_lbl_Prompt_StfId->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_lbl_Prompt_StfId->Location = System::Drawing::Point(72, 115);
			   this->Rec_lbl_Prompt_StfId->Name = L"Rec_lbl_Prompt_StfId";
			   this->Rec_lbl_Prompt_StfId->Size = System::Drawing::Size(114, 20);
			   this->Rec_lbl_Prompt_StfId->TabIndex = 1;
			   this->Rec_lbl_Prompt_StfId->Text = L"员工编号：";
			   // 
			   // Rec_lbl_Prompt_RecId
			   // 
			   this->Rec_lbl_Prompt_RecId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->Rec_lbl_Prompt_RecId->AutoSize = true;
			   this->Rec_lbl_Prompt_RecId->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_lbl_Prompt_RecId->Location = System::Drawing::Point(72, 57);
			   this->Rec_lbl_Prompt_RecId->Name = L"Rec_lbl_Prompt_RecId";
			   this->Rec_lbl_Prompt_RecId->Size = System::Drawing::Size(114, 20);
			   this->Rec_lbl_Prompt_RecId->TabIndex = 0;
			   this->Rec_lbl_Prompt_RecId->Text = L"记录编号：";
			   // pan_OPT
			   // 
			   this->pan_OPT->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->pan_OPT->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->pan_OPT->Controls->Add(this->OPT_btn_New);
			   this->pan_OPT->Controls->Add(this->OPT_btn_Clear);
			   this->pan_OPT->Controls->Add(this->OPT_btn_Search);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_default);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Count);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_count);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_result);
			   this->pan_OPT->Controls->Add(this->OPT_cmb_Status);
			   this->pan_OPT->Controls->Add(this->OPT_txt_MemId);
			   this->pan_OPT->Controls->Add(this->OPT_txt_CardNumber);
			   this->pan_OPT->Controls->Add(this->OPT_txt_MemName);
			   this->pan_OPT->Controls->Add(this->OPT_txt_OPTId);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_error);
			   this->pan_OPT->Controls->Add(this->splitter2);
			   this->pan_OPT->Controls->Add(this->OPT_dataGridView);
			   this->pan_OPT->Controls->Add(this->splitter1);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_Active);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_MemId);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_MemName);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_CardNumber);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_OPTId);
			   this->pan_OPT->Location = System::Drawing::Point(0, 0);
			   this->pan_OPT->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->pan_OPT->Name = L"pan_OPT";
			   this->pan_OPT->Size = System::Drawing::Size(982, 635);
			   this->pan_OPT->TabIndex = 3;
			   // 
			   // OPT_btn_New
			   // 
			   this->OPT_btn_New->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_btn_New->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OPT_btn_New->Location = System::Drawing::Point(869, 130);
			   this->OPT_btn_New->Name = L"OPT_btn_New";
			   this->OPT_btn_New->Size = System::Drawing::Size(84, 31);
			   this->OPT_btn_New->TabIndex = 28;
			   this->OPT_btn_New->Text = L"新增";
			   this->OPT_btn_New->UseVisualStyleBackColor = true;
			   this->OPT_btn_New->Click += gcnew System::EventHandler(this, &MainWindow::OPT_btn_New_Click);
			   // 
			   // OPT_btn_Clear
			   // 
			   this->OPT_btn_Clear->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_btn_Clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OPT_btn_Clear->Location = System::Drawing::Point(731, 130);
			   this->OPT_btn_Clear->Name = L"OPT_btn_Clear";
			   this->OPT_btn_Clear->Size = System::Drawing::Size(84, 31);
			   this->OPT_btn_Clear->TabIndex = 27;
			   this->OPT_btn_Clear->Text = L"清空";
			   this->OPT_btn_Clear->UseVisualStyleBackColor = true;
			   this->OPT_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::OPT_btn_Clear_Click);
			   // 
			   // OPT_btn_Search
			   // 
			   this->OPT_btn_Search->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_btn_Search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OPT_btn_Search->Location = System::Drawing::Point(593, 130);
			   this->OPT_btn_Search->Name = L"OPT_btn_Search";
			   this->OPT_btn_Search->Size = System::Drawing::Size(84, 31);
			   this->OPT_btn_Search->TabIndex = 26;
			   this->OPT_btn_Search->Text = L"查询";
			   this->OPT_btn_Search->UseVisualStyleBackColor = true;
			   this->OPT_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::OPT_btn_Search_Click);
			   // 
			   // OPT_lbl_Prompt_default
			   // 
			   this->OPT_lbl_Prompt_default->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_default->AutoSize = true;
			   this->OPT_lbl_Prompt_default->BackColor = System::Drawing::Color::White;
			   this->OPT_lbl_Prompt_default->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_default->Location = System::Drawing::Point(763, 233);
			   this->OPT_lbl_Prompt_default->Name = L"OPT_lbl_Prompt_default";
			   this->OPT_lbl_Prompt_default->Size = System::Drawing::Size(135, 16);
			   this->OPT_lbl_Prompt_default->TabIndex = 25;
			   this->OPT_lbl_Prompt_default->Text = L"显示默认OPT信息";
			   // 
			   // OPT_lbl_Count
			   // 
			   this->OPT_lbl_Count->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Count->AutoSize = true;
			   this->OPT_lbl_Count->BackColor = System::Drawing::Color::White;
			   this->OPT_lbl_Count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OPT_lbl_Count->Location = System::Drawing::Point(149, 233);
			   this->OPT_lbl_Count->Name = L"OPT_lbl_Count";
			   this->OPT_lbl_Count->Size = System::Drawing::Size(34, 16);
			   this->OPT_lbl_Count->TabIndex = 24;
			   this->OPT_lbl_Count->Text = L"N/A";
			   // 
			   // OPT_lbl_Prompt_count
			   // 
			   this->OPT_lbl_Prompt_count->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_count->AutoSize = true;
			   this->OPT_lbl_Prompt_count->BackColor = System::Drawing::Color::White;
			   this->OPT_lbl_Prompt_count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_count->Location = System::Drawing::Point(46, 233);
			   this->OPT_lbl_Prompt_count->Name = L"OPT_lbl_Prompt_count";
			   this->OPT_lbl_Prompt_count->Size = System::Drawing::Size(44, 16);
			   this->OPT_lbl_Prompt_count->TabIndex = 23;
			   this->OPT_lbl_Prompt_count->Text = L"总计:";
			   // 
			   // OPT_lbl_Prompt_result
			   // 
			   this->OPT_lbl_Prompt_result->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_result->AutoSize = true;
			   this->OPT_lbl_Prompt_result->BackColor = System::Drawing::Color::White;
			   this->OPT_lbl_Prompt_result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_result->Location = System::Drawing::Point(426, 233);
			   this->OPT_lbl_Prompt_result->Name = L"OPT_lbl_Prompt_result";
			   this->OPT_lbl_Prompt_result->Size = System::Drawing::Size(100, 25);
			   this->OPT_lbl_Prompt_result->TabIndex = 22;
			   this->OPT_lbl_Prompt_result->Text = L"搜索结果";
			   // 
			   // OPT_cmb_Status
			   // 
			   this->OPT_cmb_Status->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_cmb_Status->FormattingEnabled = true;
			   this->OPT_cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Active", L"Invalid" });
			   this->OPT_cmb_Status->Location = System::Drawing::Point(418, 34);
			   this->OPT_cmb_Status->Name = L"OPT_cmb_Status";
			   this->OPT_cmb_Status->Size = System::Drawing::Size(121, 21);
			   this->OPT_cmb_Status->TabIndex = 21;
			   // 
			   // OPT_txt_MemId
			   // 
			   this->OPT_txt_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_txt_MemId->Location = System::Drawing::Point(149, 95);
			   this->OPT_txt_MemId->Name = L"OPT_txt_MemId";
			   this->OPT_txt_MemId->Size = System::Drawing::Size(100, 20);
			   this->OPT_txt_MemId->TabIndex = 20;
			   // 
			   // OPT_txt_CardNumber
			   // 
			   this->OPT_txt_CardNumber->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_txt_CardNumber->Location = System::Drawing::Point(151, 156);
			   this->OPT_txt_CardNumber->Name = L"OPT_txt_CardNumber";
			   this->OPT_txt_CardNumber->Size = System::Drawing::Size(100, 20);
			   this->OPT_txt_CardNumber->TabIndex = 19;
			   // 
			   // OPT_txt_MemName
			   // 
			   this->OPT_txt_MemName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_txt_MemName->Location = System::Drawing::Point(419, 98);
			   this->OPT_txt_MemName->Name = L"OPT_txt_MemName";
			   this->OPT_txt_MemName->Size = System::Drawing::Size(100, 20);
			   this->OPT_txt_MemName->TabIndex = 18;
			   // 
			   // OPT_txt_OPTId
			   // 
			   this->OPT_txt_OPTId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_txt_OPTId->Location = System::Drawing::Point(149, 34);
			   this->OPT_txt_OPTId->Name = L"OPT_txt_OPTId";
			   this->OPT_txt_OPTId->Size = System::Drawing::Size(100, 20);
			   this->OPT_txt_OPTId->TabIndex = 17;
			   // 
			   // OPT_lbl_error
			   // 
			   this->OPT_lbl_error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_error->AutoSize = true;
			   this->OPT_lbl_error->BackColor = System::Drawing::Color::White;
			   this->OPT_lbl_error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OPT_lbl_error->ForeColor = System::Drawing::Color::Red;
			   this->OPT_lbl_error->Location = System::Drawing::Point(447, 445);
			   this->OPT_lbl_error->Name = L"OPT_lbl_error";
			   this->OPT_lbl_error->Size = System::Drawing::Size(94, 20);
			   this->OPT_lbl_error->TabIndex = 16;
			   this->OPT_lbl_error->Text = L"无搜索结果";
			   // 
			   // splitter2
			   // 
			   this->splitter2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->splitter2->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->splitter2->Location = System::Drawing::Point(0, 199);
			   this->splitter2->Name = L"splitter2";
			   this->splitter2->Size = System::Drawing::Size(982, 84);
			   this->splitter2->TabIndex = 15;
			   this->splitter2->TabStop = false;
			   // 
			   // OPT_dataGridView
			   // 
			   this->OPT_dataGridView->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->OPT_dataGridView->Location = System::Drawing::Point(0, 284);
			   this->OPT_dataGridView->Name = L"OPT_dataGridView";
			   this->OPT_dataGridView->ReadOnly = true;
			   this->OPT_dataGridView->Size = System::Drawing::Size(982, 352);
			   this->OPT_dataGridView->TabIndex = 13;
			   this->OPT_dataGridView->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::OPT_dataGridView_CellDoubleClick);
			   // 
			   // splitter1
			   // 
			   this->splitter1->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->splitter1->Location = System::Drawing::Point(0, 283);
			   this->splitter1->Name = L"splitter1";
			   this->splitter1->Size = System::Drawing::Size(982, 352);
			   this->splitter1->TabIndex = 14;
			   this->splitter1->TabStop = false;
			   // 
			   // OPT_lbl_Prompt_Active
			   // 
			   this->OPT_lbl_Prompt_Active->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_Active->AutoSize = true;
			   this->OPT_lbl_Prompt_Active->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_Active->Location = System::Drawing::Point(321, 36);
			   this->OPT_lbl_Prompt_Active->Name = L"OPT_lbl_Prompt_Active";
			   this->OPT_lbl_Prompt_Active->Size = System::Drawing::Size(38, 16);
			   this->OPT_lbl_Prompt_Active->TabIndex = 12;
			   this->OPT_lbl_Prompt_Active->Text = L"状态";
			   // 
			   // OPT_lbl_Prompt_MemId
			   // 
			   this->OPT_lbl_Prompt_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_MemId->AutoSize = true;
			   this->OPT_lbl_Prompt_MemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_MemId->Location = System::Drawing::Point(51, 97);
			   this->OPT_lbl_Prompt_MemId->Name = L"OPT_lbl_Prompt_MemId";
			   this->OPT_lbl_Prompt_MemId->Size = System::Drawing::Size(68, 16);
			   this->OPT_lbl_Prompt_MemId->TabIndex = 11;
			   this->OPT_lbl_Prompt_MemId->Text = L"成员编号";
			   // 
			   // OPT_lbl_Prompt_MemName
			   // 
			   this->OPT_lbl_Prompt_MemName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_MemName->AutoSize = true;
			   this->OPT_lbl_Prompt_MemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_MemName->Location = System::Drawing::Point(321, 100);
			   this->OPT_lbl_Prompt_MemName->Name = L"OPT_lbl_Prompt_MemName";
			   this->OPT_lbl_Prompt_MemName->Size = System::Drawing::Size(68, 16);
			   this->OPT_lbl_Prompt_MemName->TabIndex = 10;
			   this->OPT_lbl_Prompt_MemName->Text = L"成员姓名";
			   // 
			   // OPT_lbl_Prompt_CardNumber
			   // 
			   this->OPT_lbl_Prompt_CardNumber->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_CardNumber->AutoSize = true;
			   this->OPT_lbl_Prompt_CardNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_CardNumber->Location = System::Drawing::Point(51, 158);
			   this->OPT_lbl_Prompt_CardNumber->Name = L"OPT_lbl_Prompt_CardNumber";
			   this->OPT_lbl_Prompt_CardNumber->Size = System::Drawing::Size(66, 16);
			   this->OPT_lbl_Prompt_CardNumber->TabIndex = 9;
			   this->OPT_lbl_Prompt_CardNumber->Text = L"EAD编号";
			   // 
			   // OPT_lbl_Prompt_OPTId
			   // 
			   this->OPT_lbl_Prompt_OPTId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_OPTId->AutoSize = true;
			   this->OPT_lbl_Prompt_OPTId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_OPTId->Location = System::Drawing::Point(51, 36);
			   this->OPT_lbl_Prompt_OPTId->Name = L"OPT_lbl_Prompt_OPTId";
			   this->OPT_lbl_Prompt_OPTId->Size = System::Drawing::Size(66, 16);
			   this->OPT_lbl_Prompt_OPTId->TabIndex = 8;
			   this->OPT_lbl_Prompt_OPTId->Text = L"OPT编号";
			   // 
			   // pan_treasury
			   // 
			   this->pan_treasury->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_treasury->Location = System::Drawing::Point(0, 0);
			   this->pan_treasury->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->pan_treasury->Name = L"pan_treasury";
			   this->pan_treasury->Size = System::Drawing::Size(982, 635);
			   this->pan_treasury->TabIndex = 1;
			   // 
			   // pan_myInfo
			   // 
			   this->pan_myInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_myInfo->Location = System::Drawing::Point(0, 0);
			   this->pan_myInfo->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->pan_myInfo->Name = L"pan_myInfo";
			   this->pan_myInfo->Size = System::Drawing::Size(982, 635);
			   this->pan_myInfo->TabIndex = 0;
			   // 
			   // pan_order
			   // 
			   this->pan_order->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_ViewInfo);
			   this->pan_order->Controls->Add(this->ord_lbl_Error);
			   this->pan_order->Controls->Add(this->ord_splitter_Error);
			   this->pan_order->Controls->Add(this->ord_btn_Add);
			   this->pan_order->Controls->Add(this->ord_btn_Clear);
			   this->pan_order->Controls->Add(this->ord_btn_Search);
			   this->pan_order->Controls->Add(this->ord_lbl_Count);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_Count);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_SearchResult);
			   this->pan_order->Controls->Add(this->ord_dataGridView);
			   this->pan_order->Controls->Add(this->ord_txt_itmName);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_itmName);
			   this->pan_order->Controls->Add(this->ord_txt_itmId);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_itmId);
			   this->pan_order->Controls->Add(this->ord_txt_memName);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_memName);
			   this->pan_order->Controls->Add(this->ord_txt_memId);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_memId);
			   this->pan_order->Controls->Add(this->ord_cmb_Status);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_Status);
			   this->pan_order->Controls->Add(this->ord_txt_ordId);
			   this->pan_order->Controls->Add(this->ord_lbl_Prompt_ordId);
			   this->pan_order->Controls->Add(this->ord_splitter);
			   this->pan_order->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_order->Location = System::Drawing::Point(0, 0);
			   this->pan_order->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->pan_order->Name = L"pan_order";
			   this->pan_order->Size = System::Drawing::Size(982, 635);
			   this->pan_order->TabIndex = 2;
			   // 
			   // ord_lbl_Prompt_ViewInfo
			   // 
			   this->ord_lbl_Prompt_ViewInfo->AutoSize = true;
			   this->ord_lbl_Prompt_ViewInfo->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Prompt_ViewInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_ViewInfo->Location = System::Drawing::Point(752, 392);
			   this->ord_lbl_Prompt_ViewInfo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_ViewInfo->Name = L"ord_lbl_Prompt_ViewInfo";
			   this->ord_lbl_Prompt_ViewInfo->Size = System::Drawing::Size(137, 20);
			   this->ord_lbl_Prompt_ViewInfo->TabIndex = 22;
			   this->ord_lbl_Prompt_ViewInfo->Text = L"显示订单默认信息";
			   // 
			   // ord_lbl_Error
			   // 
			   this->ord_lbl_Error->AutoSize = true;
			   this->ord_lbl_Error->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Error->ForeColor = System::Drawing::Color::Red;
			   this->ord_lbl_Error->Location = System::Drawing::Point(478, 313);
			   this->ord_lbl_Error->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Error->Name = L"ord_lbl_Error";
			   this->ord_lbl_Error->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Error->TabIndex = 21;
			   this->ord_lbl_Error->Text = L"此处报错";
			   // 
			   // ord_splitter_Error
			   // 
			   this->ord_splitter_Error->BackColor = System::Drawing::Color::DarkOrange;
			   this->ord_splitter_Error->Cursor = System::Windows::Forms::Cursors::HSplit;
			   this->ord_splitter_Error->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->ord_splitter_Error->Enabled = false;
			   this->ord_splitter_Error->Location = System::Drawing::Point(0, 280);
			   this->ord_splitter_Error->Margin = System::Windows::Forms::Padding(2);
			   this->ord_splitter_Error->Name = L"ord_splitter_Error";
			   this->ord_splitter_Error->Size = System::Drawing::Size(982, 74);
			   this->ord_splitter_Error->TabIndex = 20;
			   this->ord_splitter_Error->TabStop = false;
			   // 
			   // ord_btn_Add
			   // 
			   this->ord_btn_Add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_btn_Add->Location = System::Drawing::Point(634, 171);
			   this->ord_btn_Add->Margin = System::Windows::Forms::Padding(2);
			   this->ord_btn_Add->Name = L"ord_btn_Add";
			   this->ord_btn_Add->Size = System::Drawing::Size(75, 37);
			   this->ord_btn_Add->TabIndex = 19;
			   this->ord_btn_Add->Text = L"添加";
			   this->ord_btn_Add->UseVisualStyleBackColor = true;
			   this->ord_btn_Add->Click += gcnew System::EventHandler(this, &MainWindow::ord_btn_Add_Click);
			   // 
			   // ord_btn_Clear
			   // 
			   this->ord_btn_Clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_btn_Clear->Location = System::Drawing::Point(634, 116);
			   this->ord_btn_Clear->Margin = System::Windows::Forms::Padding(2);
			   this->ord_btn_Clear->Name = L"ord_btn_Clear";
			   this->ord_btn_Clear->Size = System::Drawing::Size(75, 37);
			   this->ord_btn_Clear->TabIndex = 18;
			   this->ord_btn_Clear->Text = L"清空";
			   this->ord_btn_Clear->UseVisualStyleBackColor = true;
			   this->ord_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::ord_btn_Clear_Click);
			   // 
			   // ord_btn_Search
			   // 
			   this->ord_btn_Search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_btn_Search->Location = System::Drawing::Point(634, 63);
			   this->ord_btn_Search->Margin = System::Windows::Forms::Padding(2);
			   this->ord_btn_Search->Name = L"ord_btn_Search";
			   this->ord_btn_Search->Size = System::Drawing::Size(75, 37);
			   this->ord_btn_Search->TabIndex = 17;
			   this->ord_btn_Search->Text = L"查询";
			   this->ord_btn_Search->UseVisualStyleBackColor = true;
			   this->ord_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::ord_btn_Search_Click);
			   // 
			   // ord_lbl_Count
			   // 
			   this->ord_lbl_Count->AutoSize = true;
			   this->ord_lbl_Count->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Count->Location = System::Drawing::Point(135, 392);
			   this->ord_lbl_Count->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Count->Name = L"ord_lbl_Count";
			   this->ord_lbl_Count->Size = System::Drawing::Size(35, 20);
			   this->ord_lbl_Count->TabIndex = 16;
			   this->ord_lbl_Count->Text = L"N/A";
			   // 
			   // ord_lbl_Prompt_Count
			   // 
			   this->ord_lbl_Prompt_Count->AutoSize = true;
			   this->ord_lbl_Prompt_Count->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Prompt_Count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_Count->Location = System::Drawing::Point(61, 392);
			   this->ord_lbl_Prompt_Count->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_Count->Name = L"ord_lbl_Prompt_Count";
			   this->ord_lbl_Prompt_Count->Size = System::Drawing::Size(60, 20);
			   this->ord_lbl_Prompt_Count->TabIndex = 15;
			   this->ord_lbl_Prompt_Count->Text = L"总计：";
			   // 
			   // ord_lbl_Prompt_SearchResult
			   // 
			   this->ord_lbl_Prompt_SearchResult->AutoSize = true;
			   this->ord_lbl_Prompt_SearchResult->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Prompt_SearchResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_SearchResult->Location = System::Drawing::Point(445, 382);
			   this->ord_lbl_Prompt_SearchResult->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_SearchResult->Name = L"ord_lbl_Prompt_SearchResult";
			   this->ord_lbl_Prompt_SearchResult->Size = System::Drawing::Size(126, 31);
			   this->ord_lbl_Prompt_SearchResult->TabIndex = 14;
			   this->ord_lbl_Prompt_SearchResult->Text = L"搜索结果";
			   // 
			   // ord_dataGridView
			   // 
			   this->ord_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->ord_dataGridView->Location = System::Drawing::Point(64, 436);
			   this->ord_dataGridView->Margin = System::Windows::Forms::Padding(2);
			   this->ord_dataGridView->Name = L"ord_dataGridView";
			   this->ord_dataGridView->RowHeadersWidth = 51;
			   this->ord_dataGridView->RowTemplate->Height = 24;
			   this->ord_dataGridView->Size = System::Drawing::Size(890, 180);
			   this->ord_dataGridView->TabIndex = 12;
			   this->ord_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::ord_dataGridView_CellContentClick);
			   // 
			   // ord_txt_itmName
			   // 
			   this->ord_txt_itmName->Location = System::Drawing::Point(416, 175);
			   this->ord_txt_itmName->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_itmName->Name = L"ord_txt_itmName";
			   this->ord_txt_itmName->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_itmName->TabIndex = 11;
			   // 
			   // ord_lbl_Prompt_itmName
			   // 
			   this->ord_lbl_Prompt_itmName->AutoSize = true;
			   this->ord_lbl_Prompt_itmName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_itmName->Location = System::Drawing::Point(295, 171);
			   this->ord_lbl_Prompt_itmName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_itmName->Name = L"ord_lbl_Prompt_itmName";
			   this->ord_lbl_Prompt_itmName->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_itmName->TabIndex = 10;
			   this->ord_lbl_Prompt_itmName->Text = L"商品名称";
			   // 
			   // ord_txt_itmId
			   // 
			   this->ord_txt_itmId->Location = System::Drawing::Point(170, 173);
			   this->ord_txt_itmId->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_itmId->Name = L"ord_txt_itmId";
			   this->ord_txt_itmId->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_itmId->TabIndex = 9;
			   // 
			   // ord_lbl_Prompt_itmId
			   // 
			   this->ord_lbl_Prompt_itmId->AutoSize = true;
			   this->ord_lbl_Prompt_itmId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_itmId->Location = System::Drawing::Point(67, 171);
			   this->ord_lbl_Prompt_itmId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_itmId->Name = L"ord_lbl_Prompt_itmId";
			   this->ord_lbl_Prompt_itmId->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_itmId->TabIndex = 8;
			   this->ord_lbl_Prompt_itmId->Text = L"商品编号";
			   // 
			   // ord_txt_memName
			   // 
			   this->ord_txt_memName->Location = System::Drawing::Point(416, 120);
			   this->ord_txt_memName->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_memName->Name = L"ord_txt_memName";
			   this->ord_txt_memName->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_memName->TabIndex = 7;
			   // 
			   // ord_lbl_Prompt_memName
			   // 
			   this->ord_lbl_Prompt_memName->AutoSize = true;
			   this->ord_lbl_Prompt_memName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_memName->Location = System::Drawing::Point(295, 117);
			   this->ord_lbl_Prompt_memName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_memName->Name = L"ord_lbl_Prompt_memName";
			   this->ord_lbl_Prompt_memName->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_memName->TabIndex = 6;
			   this->ord_lbl_Prompt_memName->Text = L"成员姓名";
			   // 
			   // ord_txt_memId
			   // 
			   this->ord_txt_memId->Location = System::Drawing::Point(170, 117);
			   this->ord_txt_memId->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_memId->Name = L"ord_txt_memId";
			   this->ord_txt_memId->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_memId->TabIndex = 5;
			   // 
			   // ord_lbl_Prompt_memId
			   // 
			   this->ord_lbl_Prompt_memId->AutoSize = true;
			   this->ord_lbl_Prompt_memId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_memId->Location = System::Drawing::Point(67, 115);
			   this->ord_lbl_Prompt_memId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_memId->Name = L"ord_lbl_Prompt_memId";
			   this->ord_lbl_Prompt_memId->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_memId->TabIndex = 4;
			   this->ord_lbl_Prompt_memId->Text = L"成员编号";
			   // 
			   // ord_cmb_Status
			   // 
			   this->ord_cmb_Status->FormattingEnabled = true;
			   this->ord_cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"InvalidComplete", L"In process" });
			   this->ord_cmb_Status->Location = System::Drawing::Point(416, 63);
			   this->ord_cmb_Status->Margin = System::Windows::Forms::Padding(2);
			   this->ord_cmb_Status->Name = L"ord_cmb_Status";
			   this->ord_cmb_Status->Size = System::Drawing::Size(92, 21);
			   this->ord_cmb_Status->TabIndex = 3;
			   // 
			   // ord_lbl_Prompt_Status
			   // 
			   this->ord_lbl_Prompt_Status->AutoSize = true;
			   this->ord_lbl_Prompt_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_Status->Location = System::Drawing::Point(295, 63);
			   this->ord_lbl_Prompt_Status->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_Status->Name = L"ord_lbl_Prompt_Status";
			   this->ord_lbl_Prompt_Status->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_Status->TabIndex = 2;
			   this->ord_lbl_Prompt_Status->Text = L"订单状态";
			   // 
			   // ord_txt_ordId
			   // 
			   this->ord_txt_ordId->Location = System::Drawing::Point(170, 63);
			   this->ord_txt_ordId->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_ordId->Name = L"ord_txt_ordId";
			   this->ord_txt_ordId->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_ordId->TabIndex = 1;
			   // 
			   // ord_lbl_Prompt_ordId
			   // 
			   this->ord_lbl_Prompt_ordId->AutoSize = true;
			   this->ord_lbl_Prompt_ordId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_ordId->Location = System::Drawing::Point(68, 63);
			   this->ord_lbl_Prompt_ordId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_ordId->Name = L"ord_lbl_Prompt_ordId";
			   this->ord_lbl_Prompt_ordId->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_ordId->TabIndex = 0;
			   this->ord_lbl_Prompt_ordId->Text = L"订单编号";
			   // 
			   // ord_splitter
			   // 
			   this->ord_splitter->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->ord_splitter->Cursor = System::Windows::Forms::Cursors::HSplit;
			   this->ord_splitter->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->ord_splitter->Enabled = false;
			   this->ord_splitter->Location = System::Drawing::Point(0, 354);
			   this->ord_splitter->Margin = System::Windows::Forms::Padding(2);
			   this->ord_splitter->Name = L"ord_splitter";
			   this->ord_splitter->Size = System::Drawing::Size(982, 281);
			   this->ord_splitter->TabIndex = 13;
			   this->ord_splitter->TabStop = false;
			   // 
			   // pan_member
			   // 
			   this->pan_member->Controls->Add(this->mem_lbl_Count);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Total);
			   this->pan_member->Controls->Add(this->mem_Prompt_PgInfo);
			   this->pan_member->Controls->Add(this->mem_Prompt_ViewInfo);
			   this->pan_member->Controls->Add(this->mem_Prompt_Result);
			   this->pan_member->Controls->Add(this->mem_lbl_error);
			   this->pan_member->Controls->Add(this->mem_btn_Import);
			   this->pan_member->Controls->Add(this->mem_btn_Add);
			   this->pan_member->Controls->Add(this->mem_btn_Clear);
			   this->pan_member->Controls->Add(this->mem_btn_Search);
			   this->pan_member->Controls->Add(this->mem_cmb_CareerStatus);
			   this->pan_member->Controls->Add(this->mem_dataGridView1);
			   this->pan_member->Controls->Add(this->mem_cmb_SearchAuth);
			   this->pan_member->Controls->Add(this->mem_cmb_Type);
			   this->pan_member->Controls->Add(this->mem_cmb_Status);
			   this->pan_member->Controls->Add(this->mem_txt_Gender);
			   this->pan_member->Controls->Add(this->mem_txt_Name);
			   this->pan_member->Controls->Add(this->mem_txt_Major);
			   this->pan_member->Controls->Add(this->mem_txt_Id);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_SearchAuth);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Major);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_CareerStatus);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Gender);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Name);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Type);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Status);
			   this->pan_member->Controls->Add(this->mem_lbl_Prompt_Id);
			   this->pan_member->Controls->Add(this->mem_splitter2);
			   this->pan_member->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_member->Location = System::Drawing::Point(0, 0);
			   this->pan_member->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->pan_member->Name = L"pan_member";
			   this->pan_member->Size = System::Drawing::Size(982, 635);
			   this->pan_member->TabIndex = 6;
			   // 
			   // mem_lbl_Count
			   // 
			   this->mem_lbl_Count->AccessibleDescription = L"";
			   this->mem_lbl_Count->AutoSize = true;
			   this->mem_lbl_Count->Location = System::Drawing::Point(86, 282);
			   this->mem_lbl_Count->Name = L"mem_lbl_Count";
			   this->mem_lbl_Count->Size = System::Drawing::Size(13, 13);
			   this->mem_lbl_Count->TabIndex = 70;
			   this->mem_lbl_Count->Text = L"0";
			   // 
			   // mem_lbl_Prompt_Total
			   // 
			   this->mem_lbl_Prompt_Total->AccessibleDescription = L"";
			   this->mem_lbl_Prompt_Total->AutoSize = true;
			   this->mem_lbl_Prompt_Total->Location = System::Drawing::Point(46, 282);
			   this->mem_lbl_Prompt_Total->Name = L"mem_lbl_Prompt_Total";
			   this->mem_lbl_Prompt_Total->Size = System::Drawing::Size(34, 13);
			   this->mem_lbl_Prompt_Total->TabIndex = 69;
			   this->mem_lbl_Prompt_Total->Text = L"Total:";
			   // 
			   // mem_Prompt_PgInfo
			   // 
			   this->mem_Prompt_PgInfo->AccessibleDescription = L"";
			   this->mem_Prompt_PgInfo->AutoSize = true;
			   this->mem_Prompt_PgInfo->Location = System::Drawing::Point(30, 201);
			   this->mem_Prompt_PgInfo->Name = L"mem_Prompt_PgInfo";
			   this->mem_Prompt_PgInfo->Size = System::Drawing::Size(540, 13);
			   this->mem_Prompt_PgInfo->TabIndex = 67;
			   this->mem_Prompt_PgInfo->Text = L"The data is accurately queried and there are no necessary items. Please provide a"
				   L"s much information as possible.";
			   // 
			   // mem_Prompt_ViewInfo
			   // 
			   this->mem_Prompt_ViewInfo->AutoSize = true;
			   this->mem_Prompt_ViewInfo->Location = System::Drawing::Point(652, 289);
			   this->mem_Prompt_ViewInfo->Name = L"mem_Prompt_ViewInfo";
			   this->mem_Prompt_ViewInfo->Size = System::Drawing::Size(193, 13);
			   this->mem_Prompt_ViewInfo->TabIndex = 24;
			   this->mem_Prompt_ViewInfo->Text = L"All member info will be shown by default";
			   // 
			   // mem_Prompt_Result
			   // 
			   this->mem_Prompt_Result->AutoSize = true;
			   this->mem_Prompt_Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->mem_Prompt_Result->Location = System::Drawing::Point(445, 282);
			   this->mem_Prompt_Result->Name = L"mem_Prompt_Result";
			   this->mem_Prompt_Result->Size = System::Drawing::Size(123, 20);
			   this->mem_Prompt_Result->TabIndex = 23;
			   this->mem_Prompt_Result->Text = L"Search Result";
			   // 
			   // mem_lbl_error
			   // 
			   this->mem_lbl_error->AutoSize = true;
			   this->mem_lbl_error->ForeColor = System::Drawing::Color::Red;
			   this->mem_lbl_error->Location = System::Drawing::Point(480, 465);
			   this->mem_lbl_error->Name = L"mem_lbl_error";
			   this->mem_lbl_error->Size = System::Drawing::Size(29, 13);
			   this->mem_lbl_error->TabIndex = 22;
			   this->mem_lbl_error->Text = L"Error";
			   this->mem_lbl_error->Visible = false;
			   // 
			   // mem_btn_Import
			   // 
			   this->mem_btn_Import->Location = System::Drawing::Point(793, 220);
			   this->mem_btn_Import->Name = L"mem_btn_Import";
			   this->mem_btn_Import->Size = System::Drawing::Size(70, 28);
			   this->mem_btn_Import->TabIndex = 21;
			   this->mem_btn_Import->Text = L"Import";
			   this->mem_btn_Import->UseVisualStyleBackColor = true;
			   this->mem_btn_Import->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Import_Click);
			   // 
			   // mem_btn_Add
			   // 
			   this->mem_btn_Add->Location = System::Drawing::Point(793, 162);
			   this->mem_btn_Add->Name = L"mem_btn_Add";
			   this->mem_btn_Add->Size = System::Drawing::Size(70, 28);
			   this->mem_btn_Add->TabIndex = 20;
			   this->mem_btn_Add->Text = L"Add";
			   this->mem_btn_Add->UseVisualStyleBackColor = true;
			   this->mem_btn_Add->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Add_Click);
			   // 
			   // mem_btn_Clear
			   // 
			   this->mem_btn_Clear->Location = System::Drawing::Point(793, 101);
			   this->mem_btn_Clear->Name = L"mem_btn_Clear";
			   this->mem_btn_Clear->Size = System::Drawing::Size(70, 28);
			   this->mem_btn_Clear->TabIndex = 19;
			   this->mem_btn_Clear->Text = L"Clear";
			   this->mem_btn_Clear->UseVisualStyleBackColor = true;
			   this->mem_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Clear_Click);
			   // 
			   // mem_btn_Search
			   // 
			   this->mem_btn_Search->Location = System::Drawing::Point(793, 42);
			   this->mem_btn_Search->Name = L"mem_btn_Search";
			   this->mem_btn_Search->Size = System::Drawing::Size(70, 28);
			   this->mem_btn_Search->TabIndex = 18;
			   this->mem_btn_Search->Text = L"Search";
			   this->mem_btn_Search->UseVisualStyleBackColor = true;
			   this->mem_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Search_Click);
			   // 
			   // mem_cmb_CareerStatus
			   // 
			   this->mem_cmb_CareerStatus->FormattingEnabled = true;
			   this->mem_cmb_CareerStatus->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				   L"GradProgram", L"Unemployed", L"Employed",
					   L"StartBusiness"
			   });
			   this->mem_cmb_CareerStatus->Location = System::Drawing::Point(120, 113);
			   this->mem_cmb_CareerStatus->Name = L"mem_cmb_CareerStatus";
			   this->mem_cmb_CareerStatus->Size = System::Drawing::Size(104, 21);
			   this->mem_cmb_CareerStatus->TabIndex = 17;
			   // 
			   // mem_dataGridView1
			   // 
			   this->mem_dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->mem_dataGridView1->Location = System::Drawing::Point(0, 305);
			   this->mem_dataGridView1->Name = L"mem_dataGridView1";
			   this->mem_dataGridView1->RowHeadersWidth = 51;
			   this->mem_dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->mem_dataGridView1->Size = System::Drawing::Size(982, 331);
			   this->mem_dataGridView1->TabIndex = 16;
			   this->mem_dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::mem_dataGridView1_CellContentClick);
			   // 
			   // mem_cmb_SearchAuth
			   // 
			   this->mem_cmb_SearchAuth->FormattingEnabled = true;
			   this->mem_cmb_SearchAuth->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Yes", L"No" });
			   this->mem_cmb_SearchAuth->Location = System::Drawing::Point(532, 112);
			   this->mem_cmb_SearchAuth->Name = L"mem_cmb_SearchAuth";
			   this->mem_cmb_SearchAuth->Size = System::Drawing::Size(75, 21);
			   this->mem_cmb_SearchAuth->TabIndex = 15;
			   // 
			   // mem_cmb_Type
			   // 
			   this->mem_cmb_Type->FormattingEnabled = true;
			   this->mem_cmb_Type->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Normal", L"DivHead", L"Staff", L"Head" });
			   this->mem_cmb_Type->Location = System::Drawing::Point(188, 55);
			   this->mem_cmb_Type->Name = L"mem_cmb_Type";
			   this->mem_cmb_Type->Size = System::Drawing::Size(102, 21);
			   this->mem_cmb_Type->TabIndex = 14;
			   // 
			   // mem_cmb_Status
			   // 
			   this->mem_cmb_Status->FormattingEnabled = true;
			   this->mem_cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"Review", L"Invalid" });
			   this->mem_cmb_Status->Location = System::Drawing::Point(333, 54);
			   this->mem_cmb_Status->Name = L"mem_cmb_Status";
			   this->mem_cmb_Status->Size = System::Drawing::Size(102, 21);
			   this->mem_cmb_Status->TabIndex = 13;
			   // 
			   // mem_txt_Gender
			   // 
			   this->mem_txt_Gender->Location = System::Drawing::Point(628, 54);
			   this->mem_txt_Gender->Name = L"mem_txt_Gender";
			   this->mem_txt_Gender->Size = System::Drawing::Size(75, 20);
			   this->mem_txt_Gender->TabIndex = 11;
			   // 
			   // mem_txt_Name
			   // 
			   this->mem_txt_Name->Location = System::Drawing::Point(487, 54);
			   this->mem_txt_Name->Name = L"mem_txt_Name";
			   this->mem_txt_Name->Size = System::Drawing::Size(75, 20);
			   this->mem_txt_Name->TabIndex = 10;
			   // 
			   // mem_txt_Major
			   // 
			   this->mem_txt_Major->Location = System::Drawing::Point(308, 113);
			   this->mem_txt_Major->Name = L"mem_txt_Major";
			   this->mem_txt_Major->Size = System::Drawing::Size(115, 20);
			   this->mem_txt_Major->TabIndex = 9;
			   // 
			   // mem_txt_Id
			   // 
			   this->mem_txt_Id->Location = System::Drawing::Point(64, 57);
			   this->mem_txt_Id->Name = L"mem_txt_Id";
			   this->mem_txt_Id->Size = System::Drawing::Size(75, 20);
			   this->mem_txt_Id->TabIndex = 8;
			   // 
			   // mem_lbl_Prompt_SearchAuth
			   // 
			   this->mem_lbl_Prompt_SearchAuth->AutoSize = true;
			   this->mem_lbl_Prompt_SearchAuth->Location = System::Drawing::Point(463, 116);
			   this->mem_lbl_Prompt_SearchAuth->Name = L"mem_lbl_Prompt_SearchAuth";
			   this->mem_lbl_Prompt_SearchAuth->Size = System::Drawing::Size(63, 13);
			   this->mem_lbl_Prompt_SearchAuth->TabIndex = 7;
			   this->mem_lbl_Prompt_SearchAuth->Text = L"SearchAuth";
			   // 
			   // mem_lbl_Prompt_Major
			   // 
			   this->mem_lbl_Prompt_Major->AutoSize = true;
			   this->mem_lbl_Prompt_Major->Location = System::Drawing::Point(257, 116);
			   this->mem_lbl_Prompt_Major->Name = L"mem_lbl_Prompt_Major";
			   this->mem_lbl_Prompt_Major->Size = System::Drawing::Size(33, 13);
			   this->mem_lbl_Prompt_Major->TabIndex = 6;
			   this->mem_lbl_Prompt_Major->Text = L"Major";
			   // 
			   // mem_lbl_Prompt_CareerStatus
			   // 
			   this->mem_lbl_Prompt_CareerStatus->AutoSize = true;
			   this->mem_lbl_Prompt_CareerStatus->Location = System::Drawing::Point(46, 116);
			   this->mem_lbl_Prompt_CareerStatus->Name = L"mem_lbl_Prompt_CareerStatus";
			   this->mem_lbl_Prompt_CareerStatus->Size = System::Drawing::Size(68, 13);
			   this->mem_lbl_Prompt_CareerStatus->TabIndex = 5;
			   this->mem_lbl_Prompt_CareerStatus->Text = L"CareerStatus";
			   // 
			   // mem_lbl_Prompt_Gender
			   // 
			   this->mem_lbl_Prompt_Gender->AutoSize = true;
			   this->mem_lbl_Prompt_Gender->Location = System::Drawing::Point(580, 57);
			   this->mem_lbl_Prompt_Gender->Name = L"mem_lbl_Prompt_Gender";
			   this->mem_lbl_Prompt_Gender->Size = System::Drawing::Size(42, 13);
			   this->mem_lbl_Prompt_Gender->TabIndex = 4;
			   this->mem_lbl_Prompt_Gender->Text = L"Gender";
			   // 
			   // mem_lbl_Prompt_Name
			   // 
			   this->mem_lbl_Prompt_Name->AutoSize = true;
			   this->mem_lbl_Prompt_Name->Location = System::Drawing::Point(446, 58);
			   this->mem_lbl_Prompt_Name->Name = L"mem_lbl_Prompt_Name";
			   this->mem_lbl_Prompt_Name->Size = System::Drawing::Size(35, 13);
			   this->mem_lbl_Prompt_Name->TabIndex = 3;
			   this->mem_lbl_Prompt_Name->Text = L"Name";
			   // 
			   // mem_lbl_Prompt_Type
			   // 
			   this->mem_lbl_Prompt_Type->AutoSize = true;
			   this->mem_lbl_Prompt_Type->Location = System::Drawing::Point(296, 57);
			   this->mem_lbl_Prompt_Type->Name = L"mem_lbl_Prompt_Type";
			   this->mem_lbl_Prompt_Type->Size = System::Drawing::Size(31, 13);
			   this->mem_lbl_Prompt_Type->TabIndex = 2;
			   this->mem_lbl_Prompt_Type->Text = L"Type";
			   // 
			   // mem_lbl_Prompt_Status
			   // 
			   this->mem_lbl_Prompt_Status->AutoSize = true;
			   this->mem_lbl_Prompt_Status->Location = System::Drawing::Point(145, 57);
			   this->mem_lbl_Prompt_Status->Name = L"mem_lbl_Prompt_Status";
			   this->mem_lbl_Prompt_Status->Size = System::Drawing::Size(37, 13);
			   this->mem_lbl_Prompt_Status->TabIndex = 1;
			   this->mem_lbl_Prompt_Status->Text = L"Status";
			   // 
			   // mem_lbl_Prompt_Id
			   // 
			   this->mem_lbl_Prompt_Id->AutoSize = true;
			   this->mem_lbl_Prompt_Id->Location = System::Drawing::Point(46, 57);
			   this->mem_lbl_Prompt_Id->Name = L"mem_lbl_Prompt_Id";
			   this->mem_lbl_Prompt_Id->Size = System::Drawing::Size(16, 13);
			   this->mem_lbl_Prompt_Id->TabIndex = 0;
			   this->mem_lbl_Prompt_Id->Text = L"Id";
			   // 
			   // mem_splitter2
			   // 
			   this->mem_splitter2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			   this->mem_splitter2->Cursor = System::Windows::Forms::Cursors::HSplit;
			   this->mem_splitter2->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->mem_splitter2->Enabled = false;
			   this->mem_splitter2->Location = System::Drawing::Point(0, 253);
			   this->mem_splitter2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->mem_splitter2->MinimumSize = System::Drawing::Size(0, 43);
			   this->mem_splitter2->Name = L"mem_splitter2";
			   this->mem_splitter2->Size = System::Drawing::Size(982, 382);
			   this->mem_splitter2->TabIndex = 66;
			   this->mem_splitter2->TabStop = false;
			   // 
			   // pan_staff
			   // 
			   this->pan_staff->Controls->Add(this->label1);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_SearchResult);
			   this->pan_staff->Controls->Add(this->stf_splitter3);
			   this->pan_staff->Controls->Add(this->stf_splitter2);
			   this->pan_staff->Controls->Add(this->stf_dataGridView);
			   this->pan_staff->Controls->Add(this->stf_splitter1);
			   this->pan_staff->Controls->Add(this->stf_lbl_Count);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Count);
			   this->pan_staff->Controls->Add(this->stf_lbl_Error);
			   this->pan_staff->Controls->Add(this->stf_cmb_Auth);
			   this->pan_staff->Controls->Add(this->stf_cmb_Dept);
			   this->pan_staff->Controls->Add(this->stf_btn_Clear);
			   this->pan_staff->Controls->Add(this->stf_btn_Search);
			   this->pan_staff->Controls->Add(this->stf_txt_Name);
			   this->pan_staff->Controls->Add(this->stf_txt_Id);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Auth);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Dept);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Name);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Id);
			   this->pan_staff->Controls->Add(this->stf_btn_Add);
			   this->pan_staff->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_staff->Location = System::Drawing::Point(0, 0);
			   this->pan_staff->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->pan_staff->Name = L"pan_staff";
			   this->pan_staff->Size = System::Drawing::Size(982, 635);
			   this->pan_staff->TabIndex = 5;
			   // 
			   // label1
			   // 
			   this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::SystemColors::Control;
			   this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->label1->Location = System::Drawing::Point(691, 269);
			   this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(245, 12);
			   this->label1->TabIndex = 23;
			   this->label1->Text = L"All member info will be shown by default";
			   // 
			   // stf_lbl_Prompt_SearchResult
			   // 
			   this->stf_lbl_Prompt_SearchResult->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_SearchResult->AutoSize = true;
			   this->stf_lbl_Prompt_SearchResult->BackColor = System::Drawing::SystemColors::Control;
			   this->stf_lbl_Prompt_SearchResult->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->stf_lbl_Prompt_SearchResult->Location = System::Drawing::Point(436, 264);
			   this->stf_lbl_Prompt_SearchResult->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_SearchResult->Name = L"stf_lbl_Prompt_SearchResult";
			   this->stf_lbl_Prompt_SearchResult->Size = System::Drawing::Size(125, 16);
			   this->stf_lbl_Prompt_SearchResult->TabIndex = 22;
			   this->stf_lbl_Prompt_SearchResult->Text = L"Search Result";
			   // 
			   // stf_splitter3
			   // 
			   this->stf_splitter3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->stf_splitter3->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->stf_splitter3->Location = System::Drawing::Point(0, 221);
			   this->stf_splitter3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_splitter3->Name = L"stf_splitter3";
			   this->stf_splitter3->Size = System::Drawing::Size(982, 30);
			   this->stf_splitter3->TabIndex = 21;
			   this->stf_splitter3->TabStop = false;
			   // 
			   // stf_splitter2
			   // 
			   this->stf_splitter2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->stf_splitter2->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->stf_splitter2->Location = System::Drawing::Point(0, 251);
			   this->stf_splitter2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_splitter2->Name = L"stf_splitter2";
			   this->stf_splitter2->Size = System::Drawing::Size(982, 36);
			   this->stf_splitter2->TabIndex = 20;
			   this->stf_splitter2->TabStop = false;
			   // 
			   // stf_dataGridView
			   // 
			   this->stf_dataGridView->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->stf_dataGridView->Location = System::Drawing::Point(-24, 289);
			   this->stf_dataGridView->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_dataGridView->Name = L"stf_dataGridView";
			   this->stf_dataGridView->RowHeadersWidth = 51;
			   this->stf_dataGridView->RowTemplate->Height = 27;
			   this->stf_dataGridView->Size = System::Drawing::Size(960, 299);
			   this->stf_dataGridView->TabIndex = 19;
			   this->stf_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::stf_dataGridView_CellContentClick);
			   // 
			   // stf_splitter1
			   // 
			   this->stf_splitter1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->stf_splitter1->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->stf_splitter1->Location = System::Drawing::Point(0, 287);
			   this->stf_splitter1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_splitter1->Name = L"stf_splitter1";
			   this->stf_splitter1->Size = System::Drawing::Size(982, 348);
			   this->stf_splitter1->TabIndex = 18;
			   this->stf_splitter1->TabStop = false;
			   // 
			   // stf_lbl_Count
			   // 
			   this->stf_lbl_Count->AutoSize = true;
			   this->stf_lbl_Count->Location = System::Drawing::Point(94, 101);
			   this->stf_lbl_Count->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Count->Name = L"stf_lbl_Count";
			   this->stf_lbl_Count->Size = System::Drawing::Size(0, 13);
			   this->stf_lbl_Count->TabIndex = 17;
			   // 
			   // stf_lbl_Prompt_Count
			   // 
			   this->stf_lbl_Prompt_Count->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Count->AutoSize = true;
			   this->stf_lbl_Prompt_Count->Location = System::Drawing::Point(20, 103);
			   this->stf_lbl_Prompt_Count->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Count->Name = L"stf_lbl_Prompt_Count";
			   this->stf_lbl_Prompt_Count->Size = System::Drawing::Size(31, 13);
			   this->stf_lbl_Prompt_Count->TabIndex = 16;
			   this->stf_lbl_Prompt_Count->Text = L"Total";
			   // 
			   // stf_lbl_Error
			   // 
			   this->stf_lbl_Error->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Error->AutoSize = true;
			   this->stf_lbl_Error->ForeColor = System::Drawing::Color::Red;
			   this->stf_lbl_Error->Location = System::Drawing::Point(446, 177);
			   this->stf_lbl_Error->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Error->Name = L"stf_lbl_Error";
			   this->stf_lbl_Error->Size = System::Drawing::Size(46, 13);
			   this->stf_lbl_Error->TabIndex = 15;
			   this->stf_lbl_Error->Text = L"ERROR";
			   this->stf_lbl_Error->Visible = false;
			   // 
			   // stf_cmb_Auth
			   // 
			   this->stf_cmb_Auth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_cmb_Auth->FormattingEnabled = true;
			   this->stf_cmb_Auth->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				   L"Level-1", L"Level-2", L"Level-3", L"Level-4",
					   L"Level-5"
			   });
			   this->stf_cmb_Auth->Location = System::Drawing::Point(564, 55);
			   this->stf_cmb_Auth->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_cmb_Auth->Name = L"stf_cmb_Auth";
			   this->stf_cmb_Auth->Size = System::Drawing::Size(113, 21);
			   this->stf_cmb_Auth->TabIndex = 14;
			   // 
			   // stf_cmb_Dept
			   // 
			   this->stf_cmb_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_cmb_Dept->FormattingEnabled = true;
			   this->stf_cmb_Dept->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				   L"General Administration", L"Information Technology Support",
					   L"Career Development Support"
			   });
			   this->stf_cmb_Dept->Location = System::Drawing::Point(306, 55);
			   this->stf_cmb_Dept->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_cmb_Dept->Name = L"stf_cmb_Dept";
			   this->stf_cmb_Dept->Size = System::Drawing::Size(210, 21);
			   this->stf_cmb_Dept->TabIndex = 13;
			   // 
			   // stf_btn_Clear
			   // 
			   this->stf_btn_Clear->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_btn_Clear->Location = System::Drawing::Point(766, 101);
			   this->stf_btn_Clear->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_btn_Clear->Name = L"stf_btn_Clear";
			   this->stf_btn_Clear->Size = System::Drawing::Size(70, 28);
			   this->stf_btn_Clear->TabIndex = 10;
			   this->stf_btn_Clear->Text = L"Clear";
			   this->stf_btn_Clear->UseVisualStyleBackColor = true;
			   this->stf_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::stf_btn_Clear_Click);
			   // 
			   // stf_btn_Search
			   // 
			   this->stf_btn_Search->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_btn_Search->Location = System::Drawing::Point(766, 42);
			   this->stf_btn_Search->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_btn_Search->Name = L"stf_btn_Search";
			   this->stf_btn_Search->Size = System::Drawing::Size(70, 28);
			   this->stf_btn_Search->TabIndex = 9;
			   this->stf_btn_Search->Text = L"Search";
			   this->stf_btn_Search->UseVisualStyleBackColor = true;
			   this->stf_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::stf_btn_Search_Click);
			   // 
			   // stf_txt_Name
			   // 
			   this->stf_txt_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_txt_Name->Location = System::Drawing::Point(152, 55);
			   this->stf_txt_Name->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_txt_Name->Name = L"stf_txt_Name";
			   this->stf_txt_Name->Size = System::Drawing::Size(76, 20);
			   this->stf_txt_Name->TabIndex = 6;
			   // 
			   // stf_txt_Id
			   // 
			   this->stf_txt_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_txt_Id->Location = System::Drawing::Point(38, 55);
			   this->stf_txt_Id->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_txt_Id->Name = L"stf_txt_Id";
			   this->stf_txt_Id->Size = System::Drawing::Size(76, 20);
			   this->stf_txt_Id->TabIndex = 5;
			   // 
			   // stf_lbl_Prompt_Auth
			   // 
			   this->stf_lbl_Prompt_Auth->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Auth->AutoSize = true;
			   this->stf_lbl_Prompt_Auth->Location = System::Drawing::Point(519, 58);
			   this->stf_lbl_Prompt_Auth->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Auth->Name = L"stf_lbl_Prompt_Auth";
			   this->stf_lbl_Prompt_Auth->Size = System::Drawing::Size(29, 13);
			   this->stf_lbl_Prompt_Auth->TabIndex = 4;
			   this->stf_lbl_Prompt_Auth->Text = L"Auth";
			   // 
			   // stf_lbl_Prompt_Dept
			   // 
			   this->stf_lbl_Prompt_Dept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Dept->AutoSize = true;
			   this->stf_lbl_Prompt_Dept->Location = System::Drawing::Point(236, 58);
			   this->stf_lbl_Prompt_Dept->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Dept->Name = L"stf_lbl_Prompt_Dept";
			   this->stf_lbl_Prompt_Dept->Size = System::Drawing::Size(62, 13);
			   this->stf_lbl_Prompt_Dept->TabIndex = 3;
			   this->stf_lbl_Prompt_Dept->Text = L"Department";
			   // 
			   // stf_lbl_Prompt_Name
			   // 
			   this->stf_lbl_Prompt_Name->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Name->AutoSize = true;
			   this->stf_lbl_Prompt_Name->Location = System::Drawing::Point(118, 57);
			   this->stf_lbl_Prompt_Name->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Name->Name = L"stf_lbl_Prompt_Name";
			   this->stf_lbl_Prompt_Name->Size = System::Drawing::Size(35, 13);
			   this->stf_lbl_Prompt_Name->TabIndex = 2;
			   this->stf_lbl_Prompt_Name->Text = L"Name";
			   // 
			   // stf_lbl_Prompt_Id
			   // 
			   this->stf_lbl_Prompt_Id->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_lbl_Prompt_Id->AutoSize = true;
			   this->stf_lbl_Prompt_Id->Location = System::Drawing::Point(20, 57);
			   this->stf_lbl_Prompt_Id->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Id->Name = L"stf_lbl_Prompt_Id";
			   this->stf_lbl_Prompt_Id->Size = System::Drawing::Size(16, 13);
			   this->stf_lbl_Prompt_Id->TabIndex = 1;
			   this->stf_lbl_Prompt_Id->Text = L"Id";
			   // 
			   // stf_btn_Add
			   // 
			   this->stf_btn_Add->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->stf_btn_Add->Location = System::Drawing::Point(766, 162);
			   this->stf_btn_Add->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->stf_btn_Add->Name = L"stf_btn_Add";
			   this->stf_btn_Add->Size = System::Drawing::Size(70, 28);
			   this->stf_btn_Add->TabIndex = 0;
			   this->stf_btn_Add->Text = L"Add";
			   this->stf_btn_Add->UseVisualStyleBackColor = true;
			   this->stf_btn_Add->Click += gcnew System::EventHandler(this, &MainWindow::stf_btn_Add_Click);
			   // 
			   // pan_OPT
			   // 
			   this->pan_OPT->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_OPT->Location = System::Drawing::Point(0, 0);
			   this->pan_OPT->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_OPT->Name = L"pan_OPT";
			   this->pan_OPT->Size = System::Drawing::Size(1359, 784);
			   this->pan_OPT->TabIndex = 3;
			   // 
			   // pan_treasury
			   // 
			   this->pan_treasury->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_treasury->Location = System::Drawing::Point(0, 0);
			   this->pan_treasury->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_treasury->Name = L"pan_treasury";
			   this->pan_treasury->Size = System::Drawing::Size(1359, 784);
			   this->pan_treasury->TabIndex = 1;
			   // 
			   // pan_myInfo
			   // 
			   this->pan_myInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_myInfo->Location = System::Drawing::Point(0, 0);
			   this->pan_myInfo->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_myInfo->Name = L"pan_myInfo";
			   this->pan_myInfo->Size = System::Drawing::Size(1359, 784);
			   this->pan_myInfo->TabIndex = 0;
			   // pan_record
			   // 
			   this->pan_record->BackColor = System::Drawing::SystemColors::Control;
			   this->pan_record->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_record->Location = System::Drawing::Point(0, 0);
			   this->pan_record->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->pan_record->Name = L"pan_record";
			   this->pan_record->Size = System::Drawing::Size(982, 635);
			   this->pan_record->TabIndex = 4;
			   // 
			   // ms_panelOptions
			   // 
			   this->ms_panelOptions->Dock = System::Windows::Forms::DockStyle::None;
			   this->ms_panelOptions->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->ms_panelOptions->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				   this->tsm_member,
					   this->tsm_staff, this->tsm_record, this->tsm_OPT, this->tsm_order, this->tsm_treasury, this->tsm_myInfo
			   });
			   this->ms_panelOptions->Location = System::Drawing::Point(0, 0);
			   this->ms_panelOptions->Margin = System::Windows::Forms::Padding(50, 0, 50, 0);
			   this->ms_panelOptions->MinimumSize = System::Drawing::Size(150, 0);
			   this->ms_panelOptions->Name = L"ms_panelOptions";
			   this->ms_panelOptions->Size = System::Drawing::Size(150, 635);
			   this->ms_panelOptions->TabIndex = 0;
			   this->ms_panelOptions->Text = L"ms_leftBar";
			   // 
			   // tsm_member
			   // 
			   this->tsm_member->Name = L"tsm_member";
			   this->tsm_member->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_member->Size = System::Drawing::Size(143, 71);
			   this->tsm_member->Text = L"Member";
			   this->tsm_member->Click += gcnew System::EventHandler(this, &MainWindow::tsm_member_Click);
			   // 
			   // tsm_staff
			   // 
			   this->tsm_staff->Name = L"tsm_staff";
			   this->tsm_staff->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_staff->Size = System::Drawing::Size(143, 71);
			   this->tsm_staff->Text = L"Staff";
			   this->tsm_staff->Click += gcnew System::EventHandler(this, &MainWindow::tsm_staff_Click);
			   // 
			   // tsm_record
			   // 
			   this->tsm_record->Name = L"tsm_record";
			   this->tsm_record->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_record->Size = System::Drawing::Size(143, 71);
			   this->tsm_record->Text = L"Record";
			   this->tsm_record->Click += gcnew System::EventHandler(this, &MainWindow::tsm_record_Click);
			   // 
			   // tsm_OPT
			   // 
			   this->tsm_OPT->Name = L"tsm_OPT";
			   this->tsm_OPT->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_OPT->Size = System::Drawing::Size(143, 71);
			   this->tsm_OPT->Text = L"OPT";
			   this->tsm_OPT->Click += gcnew System::EventHandler(this, &MainWindow::tsm_OPT_Click);
			   // 
			   // tsm_order
			   // 
			   this->tsm_order->Name = L"tsm_order";
			   this->tsm_order->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_order->Size = System::Drawing::Size(143, 71);
			   this->tsm_order->Text = L"Order";
			   this->tsm_order->Click += gcnew System::EventHandler(this, &MainWindow::tsm_order_Click);
			   // 
			   // tsm_treasury
			   // 
			   this->tsm_treasury->Name = L"tsm_treasury";
			   this->tsm_treasury->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_treasury->Size = System::Drawing::Size(143, 71);
			   this->tsm_treasury->Text = L"Treasury";
			   // 
			   // tsm_myInfo
			   // 
			   this->tsm_myInfo->Name = L"tsm_myInfo";
			   this->tsm_myInfo->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
			   this->tsm_myInfo->Size = System::Drawing::Size(143, 71);
			   this->tsm_myInfo->Text = L"My Info";
			   // 
			   // ms_systemOptions
			   // 
			   this->ms_systemOptions->BackColor = System::Drawing::SystemColors::Control;
			   this->ms_systemOptions->Dock = System::Windows::Forms::DockStyle::None;
			   this->ms_systemOptions->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->ms_systemOptions->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->tsm_system,
					   this->tsm_database, this->tsm_help
			   });
			   this->ms_systemOptions->Location = System::Drawing::Point(0, 0);
			   this->ms_systemOptions->Name = L"ms_systemOptions";
			   this->ms_systemOptions->Size = System::Drawing::Size(1132, 25);
			   this->ms_systemOptions->TabIndex = 0;
			   this->ms_systemOptions->Text = L"menuStrip1";
			   // 
			   // tsm_system
			   // 
			   this->tsm_system->Name = L"tsm_system";
			   this->tsm_system->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
			   this->tsm_system->Size = System::Drawing::Size(116, 24);
			   this->tsm_system->Size = System::Drawing::Size(103, 21);
			   this->tsm_system->Text = L"System";
			   // 
			   // tsm_database
			   // 
			   this->tsm_database->Name = L"tsm_database";
			   this->tsm_database->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
			   this->tsm_database->Size = System::Drawing::Size(130, 24);
			   this->tsm_database->Size = System::Drawing::Size(117, 21);
			   this->tsm_database->Text = L"Database";
			   // 
			   // tsm_help
			   // 
			   this->tsm_help->Name = L"tsm_help";
			   this->tsm_help->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
			   this->tsm_help->Size = System::Drawing::Size(98, 24);
			   this->tsm_help->Size = System::Drawing::Size(89, 21);
			   this->tsm_help->Text = L"Help";
			   // 
			   // MainWindow
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1132, 660);
			   this->Controls->Add(this->toolStripContainer1);
			   this->MainMenuStrip = this->ms_systemOptions;
			   this->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			   this->MinimumSize = System::Drawing::Size(1128, 695);
			   this->Name = L"MainWindow";
			   this->Text = L"MainWindow";
			   this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			   this->toolStripContainer1->LeftToolStripPanel->ResumeLayout(false);
			   this->toolStripContainer1->LeftToolStripPanel->PerformLayout();
			   this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			   this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			   this->toolStripContainer1->ResumeLayout(false);
			   this->toolStripContainer1->PerformLayout();
			   this->pan_record->ResumeLayout(false);
			   this->pan_record->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Rec_dataGridView))->EndInit();
			   this->pan_OPT->ResumeLayout(false);
			   this->pan_OPT->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OPT_dataGridView))->EndInit();
			   this->pan_order->ResumeLayout(false);
			   this->pan_order->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ord_dataGridView))->EndInit();
			   this->pan_member->ResumeLayout(false);
			   this->pan_member->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mem_dataGridView1))->EndInit();
			   this->pan_staff->ResumeLayout(false);
			   this->pan_staff->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stf_dataGridView))->EndInit();
			   this->ms_panelOptions->ResumeLayout(false);
			   this->ms_panelOptions->PerformLayout();
			   this->ms_systemOptions->ResumeLayout(false);
			   this->ms_systemOptions->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private:
		Void tsm_member_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_member->Visible = true;
		}
		Void tsm_staff_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_staff->Visible = true;
		}
		Void tsm_record_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_record->Visible = true;
		}
		Void tsm_OPT_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_OPT->Visible = true;
		}
		Void tsm_order_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_order->Visible = true;
		}
		Void tsm_treasury_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_treasury->Visible = true;
		}
		Void tsm_myInfo_Click(System::Object^ sender, System::EventArgs^ e) {
			SetAllPanelInvisible();
			pan_myInfo->Visible = true;
		}
		void SetAllPanelInvisible();

	private:
		Database^ database;
		PublicUserInfo^ _pui;
		PublicUserInfo::Auth _Auth;

		/*
			MemberMainWindow
		*/
	private:
		Void Initialize();
		Void mem_CheckAuth();
		Void mem_UpdateDataGridView(String^ command);
		Void mem_GeneralInformation();
		Void mem_btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_btn_Add_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_btn_Import_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

		/*
			StaffMainWindow
		*/
	private:
		Void stf_CheckAuth();
		Void stf_UpdateDataGridView(String^ command);
		Void stf_GeneralInformation();
		Void stf_btn_Add_Click(System::Object^ sender, System::EventArgs^ e);
		Void stf_btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		Void stf_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void stf_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		/*
			OrderMainWindow
		*/
	private:
		Void ord_UpdateDataGridView(String^ command);
		Void ord_GeneralInformation();
		Void ord_btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		Void ord_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void ord_btn_Add_Click(System::Object^ sender, System::EventArgs^ e);
		Void ord_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

		/*
			RecordMainWindow
		*/
	private:
		Void Rec_UpdateDataGridView(String^ command);
		Void Rec_GeneralInformation();
		Void Rec_btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		Void Rec_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void Rec_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

		/*
		*	OPTMainWindow
		*/
	private:
		Void OPT_UpdateDataGridView(String^ command);
		Void OPT_btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		Void OPT_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void OPT_dataGridView_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		Void OPT_btn_New_Click(System::Object^ sender, System::EventArgs^ e);
		Void OPT_GeneralInformation();
	private: System::Void lbl_Prompt_MemName_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
