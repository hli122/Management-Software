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
#include "SysChangeUserInfoPage.h"
#include "SysInfoPage.h"
#define MEM_SELECT_ALL "SELECT Member.Id AS 'MemberId', Member.Status AS 'MemberStatus', Member.Type AS 'MemberType', Member.Name AS 'MemberName', Member.Gender AS 'MemberGender', Member.Email AS 'MemberEmail' FROM Member ORDER BY Id ASC"
#define STF_SELECT_ALL "SELECT Staff.MemId AS 'ID', Member.Name As '姓名', Member.Gender AS '性别', Member.Email AS 'Email', Staff.Dept As '所在部门', Staff.Position As '职位职务', Staff.Auth As '权限等级' FROM Member, Staff WHERE Staff.MemId = Member.Id ORDER BY Staff.MemId ASC"
#define ORD_SELECT_ALL "SELECT Orders.Id AS 'ID', Orders.Status As '订单状态', Orders.Time AS '提交时间', Member.Name AS '成员姓名', Member.Email As 'Email', Item.Name As '商品名称', Orders.Amount As '数量', Item.Price As '单价', Orders.Comment As '备注' FROM Orders, Member, Item WHERE Orders.MemId = Member.Id AND Orders.ItemId = Item.Id ORDER BY Orders.Id ASC"
#define REC_SELECT_ALL "SELECT Record.Id AS 'ID', Record.Time AS '登记时间', Record.StfId AS '员工编号', Record.Memname AS '员工姓名', Staff.Dept AS '所在部门', Staff.Position AS '职位职务', Record.Action AS '操作内容' FROM Record, Staff WHERE Staff.MemId = Record.StfId"
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
	private: System::Windows::Forms::Panel^ pan_order;
	private: System::Windows::Forms::Label^ ord_lbl_Prompt_ViewInfo;
	private: System::Windows::Forms::Label^ ord_lbl_Error;
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
	private: System::Windows::Forms::Button^ Rec_btn_RecSearch;
	private: System::Windows::Forms::Button^ Rec_btn_Clear;
	private: System::Windows::Forms::Label^ rec_lbl_Count;
	private: System::Windows::Forms::Label^ rec_lbl_prompt_total;
	private: System::Windows::Forms::Panel^ pan_member;
	private: System::Windows::Forms::Label^ mem_lbl_Count;
	private: System::Windows::Forms::Label^ mem_lbl_Prompt_总数;
	private: System::Windows::Forms::Label^ mem_Prompt_PgInfo;
	private: System::Windows::Forms::Label^ mem_Prompt_ViewInfo;
	private: System::Windows::Forms::Label^ mem_Prompt_查询结果;
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
	private: System::Windows::Forms::DataGridView^ OPT_dataGridView;
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
	private: System::Windows::Forms::Panel^ mem_panel4;
	private: System::Windows::Forms::Panel^ mem_panel3;
	private: System::Windows::Forms::Panel^ mem_panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::ToolStripMenuItem^ tmsi_ChangeUserInfo;
	private: System::Windows::Forms::ToolStripMenuItem^ tsmi_VersionInfo;
	private: System::Windows::Forms::Splitter^ splitter5;
	private: System::Windows::Forms::Splitter^ splitter4;
	private: System::Windows::Forms::Splitter^ splitter3;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Auth;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Dept;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Name;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Id;
	private: System::Windows::Forms::TextBox^ stf_txt_Name;
	private: System::Windows::Forms::TextBox^ stf_txt_Id;
	private: System::Windows::Forms::ComboBox^ stf_cmb_Auth;
	private: System::Windows::Forms::ComboBox^ stf_cmb_Dept;
	private: System::Windows::Forms::Button^ stf_btn_Add;
	private: System::Windows::Forms::Button^ stf_btn_Clear;
	private: System::Windows::Forms::Button^ stf_btn_Search;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_SearchResult;
	private: System::Windows::Forms::Label^ stf_lbl_Error;
	private: System::Windows::Forms::Label^ stf_lbl_Count;
	private: System::Windows::Forms::Label^ stf_lbl_Prompt_Count;
	private: System::Windows::Forms::DataGridView^ stf_dataGridView;
	private: System::Windows::Forms::Panel^ ord_panel1;
	private: System::Windows::Forms::Panel^ ord_panel2;
	private: System::Windows::Forms::Panel^ ord_panel3;
	private: System::Windows::Forms::Panel^ rec_panel1;
	private: System::Windows::Forms::Panel^ rec_panel3;
	private: System::Windows::Forms::Label^ Rec_lbl_Error;
	private: System::Windows::Forms::DataGridView^ Rec_dataGridView;
	private: System::Windows::Forms::Label^ rec_lbl_prompt_Result;
	private: System::Windows::Forms::Panel^ rec_panel2;
	private: System::Windows::Forms::TextBox^ Rec_txt_StfId;
	private: System::Windows::Forms::TextBox^ Rec_txt_RecId;
	private: System::Windows::Forms::TextBox^ Rec_txt_department;
	private: System::Windows::Forms::Label^ Rec_lbl_Prompt_MemName;
	private: System::Windows::Forms::Label^ Rec_lbl_Prompt_StfId;
	private: System::Windows::Forms::Label^ Rec_lbl_Prompt_RecId;
	private: System::Windows::Forms::TextBox^ Rec_txt_MemName;
	private: System::Windows::Forms::Label^ rec_lbl_prompt_department;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ OPT_panel1;
	private: System::Windows::Forms::Panel^ pan_myInfo;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			   this->pan_OPT = (gcnew System::Windows::Forms::Panel());
			   this->OPT_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->OPT_lbl_Prompt_result = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_default = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_count = (gcnew System::Windows::Forms::Label());
			   this->OPT_btn_New = (gcnew System::Windows::Forms::Button());
			   this->OPT_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->OPT_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->OPT_cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			   this->OPT_txt_MemId = (gcnew System::Windows::Forms::TextBox());
			   this->OPT_txt_CardNumber = (gcnew System::Windows::Forms::TextBox());
			   this->OPT_txt_MemName = (gcnew System::Windows::Forms::TextBox());
			   this->OPT_txt_OPTId = (gcnew System::Windows::Forms::TextBox());
			   this->OPT_lbl_error = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_Active = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_MemId = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_MemName = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_CardNumber = (gcnew System::Windows::Forms::Label());
			   this->OPT_lbl_Prompt_OPTId = (gcnew System::Windows::Forms::Label());
			   this->OPT_panel1 = (gcnew System::Windows::Forms::Panel());
			   this->pan_record = (gcnew System::Windows::Forms::Panel());
			   this->Rec_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->Rec_btn_RecSearch = (gcnew System::Windows::Forms::Button());
			   this->rec_panel3 = (gcnew System::Windows::Forms::Panel());
			   this->Rec_lbl_Error = (gcnew System::Windows::Forms::Label());
			   this->Rec_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->rec_panel1 = (gcnew System::Windows::Forms::Panel());
			   this->rec_lbl_prompt_Result = (gcnew System::Windows::Forms::Label());
			   this->rec_lbl_prompt_total = (gcnew System::Windows::Forms::Label());
			   this->rec_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->rec_panel2 = (gcnew System::Windows::Forms::Panel());
			   this->Rec_txt_StfId = (gcnew System::Windows::Forms::TextBox());
			   this->Rec_txt_RecId = (gcnew System::Windows::Forms::TextBox());
			   this->Rec_txt_department = (gcnew System::Windows::Forms::TextBox());
			   this->Rec_lbl_Prompt_MemName = (gcnew System::Windows::Forms::Label());
			   this->Rec_lbl_Prompt_StfId = (gcnew System::Windows::Forms::Label());
			   this->Rec_lbl_Prompt_RecId = (gcnew System::Windows::Forms::Label());
			   this->Rec_txt_MemName = (gcnew System::Windows::Forms::TextBox());
			   this->rec_lbl_prompt_department = (gcnew System::Windows::Forms::Label());
			   this->pan_order = (gcnew System::Windows::Forms::Panel());
			   this->ord_panel3 = (gcnew System::Windows::Forms::Panel());
			   this->ord_lbl_Error = (gcnew System::Windows::Forms::Label());
			   this->ord_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->ord_panel2 = (gcnew System::Windows::Forms::Panel());
			   this->ord_lbl_Prompt_Count = (gcnew System::Windows::Forms::Label());
			   this->ord_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->ord_lbl_Prompt_SearchResult = (gcnew System::Windows::Forms::Label());
			   this->ord_lbl_Prompt_ViewInfo = (gcnew System::Windows::Forms::Label());
			   this->ord_panel1 = (gcnew System::Windows::Forms::Panel());
			   this->ord_lbl_Prompt_ordId = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_ordId = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			   this->ord_cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			   this->ord_btn_Add = (gcnew System::Windows::Forms::Button());
			   this->ord_lbl_Prompt_memId = (gcnew System::Windows::Forms::Label());
			   this->ord_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->ord_txt_memId = (gcnew System::Windows::Forms::TextBox());
			   this->ord_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->ord_lbl_Prompt_memName = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_memName = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_itmId = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_itmId = (gcnew System::Windows::Forms::TextBox());
			   this->ord_lbl_Prompt_itmName = (gcnew System::Windows::Forms::Label());
			   this->ord_txt_itmName = (gcnew System::Windows::Forms::TextBox());
			   this->pan_member = (gcnew System::Windows::Forms::Panel());
			   this->mem_panel4 = (gcnew System::Windows::Forms::Panel());
			   this->mem_lbl_error = (gcnew System::Windows::Forms::Label());
			   this->mem_dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->mem_panel3 = (gcnew System::Windows::Forms::Panel());
			   this->mem_Prompt_ViewInfo = (gcnew System::Windows::Forms::Label());
			   this->mem_Prompt_查询结果 = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_总数 = (gcnew System::Windows::Forms::Label());
			   this->mem_panel1 = (gcnew System::Windows::Forms::Panel());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->mem_cmb_SearchAuth = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_cmb_Status = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_txt_Gender = (gcnew System::Windows::Forms::TextBox());
			   this->mem_Prompt_PgInfo = (gcnew System::Windows::Forms::Label());
			   this->mem_txt_Name = (gcnew System::Windows::Forms::TextBox());
			   this->mem_txt_Major = (gcnew System::Windows::Forms::TextBox());
			   this->mem_btn_Import = (gcnew System::Windows::Forms::Button());
			   this->mem_txt_Id = (gcnew System::Windows::Forms::TextBox());
			   this->mem_btn_Add = (gcnew System::Windows::Forms::Button());
			   this->mem_lbl_Prompt_SearchAuth = (gcnew System::Windows::Forms::Label());
			   this->mem_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->mem_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->mem_lbl_Prompt_Major = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Gender = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Type = (gcnew System::Windows::Forms::Label());
			   this->mem_cmb_Type = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_lbl_Prompt_Status = (gcnew System::Windows::Forms::Label());
			   this->mem_cmb_CareerStatus = (gcnew System::Windows::Forms::ComboBox());
			   this->mem_lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			   this->mem_lbl_Prompt_CareerStatus = (gcnew System::Windows::Forms::Label());
			   this->pan_staff = (gcnew System::Windows::Forms::Panel());
			   this->stf_dataGridView = (gcnew System::Windows::Forms::DataGridView());
			   this->stf_lbl_Prompt_SearchResult = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Error = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Count = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Count = (gcnew System::Windows::Forms::Label());
			   this->stf_btn_Add = (gcnew System::Windows::Forms::Button());
			   this->stf_btn_Clear = (gcnew System::Windows::Forms::Button());
			   this->stf_btn_Search = (gcnew System::Windows::Forms::Button());
			   this->stf_cmb_Auth = (gcnew System::Windows::Forms::ComboBox());
			   this->stf_cmb_Dept = (gcnew System::Windows::Forms::ComboBox());
			   this->stf_txt_Name = (gcnew System::Windows::Forms::TextBox());
			   this->stf_txt_Id = (gcnew System::Windows::Forms::TextBox());
			   this->stf_lbl_Prompt_Auth = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Dept = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Name = (gcnew System::Windows::Forms::Label());
			   this->stf_lbl_Prompt_Id = (gcnew System::Windows::Forms::Label());
			   this->splitter5 = (gcnew System::Windows::Forms::Splitter());
			   this->splitter4 = (gcnew System::Windows::Forms::Splitter());
			   this->splitter3 = (gcnew System::Windows::Forms::Splitter());
			   this->pan_treasury = (gcnew System::Windows::Forms::Panel());
			   this->pan_myInfo = (gcnew System::Windows::Forms::Panel());
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
			   this->tmsi_ChangeUserInfo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_database = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsm_help = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->tsmi_VersionInfo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripContainer1->ContentPanel->SuspendLayout();
			   this->toolStripContainer1->LeftToolStripPanel->SuspendLayout();
			   this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			   this->toolStripContainer1->SuspendLayout();
			   this->pan_OPT->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OPT_dataGridView))->BeginInit();
			   this->panel1->SuspendLayout();
			   this->pan_record->SuspendLayout();
			   this->rec_panel3->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Rec_dataGridView))->BeginInit();
			   this->rec_panel1->SuspendLayout();
			   this->rec_panel2->SuspendLayout();
			   this->pan_order->SuspendLayout();
			   this->ord_panel3->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ord_dataGridView))->BeginInit();
			   this->ord_panel2->SuspendLayout();
			   this->ord_panel1->SuspendLayout();
			   this->pan_member->SuspendLayout();
			   this->mem_panel4->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mem_dataGridView1))->BeginInit();
			   this->mem_panel3->SuspendLayout();
			   this->mem_panel1->SuspendLayout();
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
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_record);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_order);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_member);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_staff);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_treasury);
			   this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_myInfo);
			   this->toolStripContainer1->ContentPanel->Margin = System::Windows::Forms::Padding(2);
			   this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(982, 636);
			   this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			   // 
			   // toolStripContainer1.LeftToolStripPanel
			   // 
			   this->toolStripContainer1->LeftToolStripPanel->Controls->Add(this->ms_panelOptions);
			   this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
			   this->toolStripContainer1->Margin = System::Windows::Forms::Padding(2);
			   this->toolStripContainer1->Name = L"toolStripContainer1";
			   this->toolStripContainer1->Size = System::Drawing::Size(1132, 661);
			   this->toolStripContainer1->TabIndex = 0;
			   this->toolStripContainer1->Text = L"toolStripContainer1";
			   // 
			   // toolStripContainer1.TopToolStripPanel
			   // 
			   this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->ms_systemOptions);
			   // 
			   // pan_OPT
			   // 
			   this->pan_OPT->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->pan_OPT->Controls->Add(this->OPT_dataGridView);
			   this->pan_OPT->Controls->Add(this->panel1);
			   this->pan_OPT->Controls->Add(this->OPT_btn_New);
			   this->pan_OPT->Controls->Add(this->OPT_btn_Clear);
			   this->pan_OPT->Controls->Add(this->OPT_btn_Search);
			   this->pan_OPT->Controls->Add(this->OPT_cmb_Status);
			   this->pan_OPT->Controls->Add(this->OPT_txt_MemId);
			   this->pan_OPT->Controls->Add(this->OPT_txt_CardNumber);
			   this->pan_OPT->Controls->Add(this->OPT_txt_MemName);
			   this->pan_OPT->Controls->Add(this->OPT_txt_OPTId);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_error);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_Active);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_MemId);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_MemName);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_CardNumber);
			   this->pan_OPT->Controls->Add(this->OPT_lbl_Prompt_OPTId);
			   this->pan_OPT->Controls->Add(this->OPT_panel1);
			   this->pan_OPT->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_OPT->Location = System::Drawing::Point(0, 0);
			   this->pan_OPT->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_OPT->Name = L"pan_OPT";
			   this->pan_OPT->Size = System::Drawing::Size(982, 636);
			   this->pan_OPT->TabIndex = 3;
			   // 
			   // OPT_dataGridView
			   // 
			   this->OPT_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->OPT_dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->OPT_dataGridView->Location = System::Drawing::Point(0, 364);
			   this->OPT_dataGridView->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OPT_dataGridView->Name = L"OPT_dataGridView";
			   this->OPT_dataGridView->ReadOnly = true;
			   this->OPT_dataGridView->RowHeadersWidth = 51;
			   this->OPT_dataGridView->Size = System::Drawing::Size(982, 272);
			   this->OPT_dataGridView->TabIndex = 13;
			   this->OPT_dataGridView->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::OPT_dataGridView_CellDoubleClick);
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->panel1->Controls->Add(this->OPT_lbl_Prompt_result);
			   this->panel1->Controls->Add(this->OPT_lbl_Prompt_default);
			   this->panel1->Controls->Add(this->OPT_lbl_Count);
			   this->panel1->Controls->Add(this->OPT_lbl_Prompt_count);
			   this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->panel1->Location = System::Drawing::Point(0, 271);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(982, 93);
			   this->panel1->TabIndex = 30;
			   // 
			   // OPT_lbl_Prompt_result
			   // 
			   this->OPT_lbl_Prompt_result->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_result->AutoSize = true;
			   this->OPT_lbl_Prompt_result->BackColor = System::Drawing::Color::White;
			   this->OPT_lbl_Prompt_result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_result->Location = System::Drawing::Point(420, 26);
			   this->OPT_lbl_Prompt_result->Name = L"OPT_lbl_Prompt_result";
			   this->OPT_lbl_Prompt_result->Size = System::Drawing::Size(100, 25);
			   this->OPT_lbl_Prompt_result->TabIndex = 22;
			   this->OPT_lbl_Prompt_result->Text = L"搜索结果";
			   // 
			   // OPT_lbl_Prompt_default
			   // 
			   this->OPT_lbl_Prompt_default->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_default->AutoSize = true;
			   this->OPT_lbl_Prompt_default->BackColor = System::Drawing::Color::White;
			   this->OPT_lbl_Prompt_default->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_default->Location = System::Drawing::Point(743, 30);
			   this->OPT_lbl_Prompt_default->Name = L"OPT_lbl_Prompt_default";
			   this->OPT_lbl_Prompt_default->Size = System::Drawing::Size(136, 16);
			   this->OPT_lbl_Prompt_default->TabIndex = 25;
			   this->OPT_lbl_Prompt_default->Text = L"默认显示全部搜索";
			   // 
			   // OPT_lbl_Count
			   // 
			   this->OPT_lbl_Count->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Count->AutoSize = true;
			   this->OPT_lbl_Count->BackColor = System::Drawing::Color::White;
			   this->OPT_lbl_Count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OPT_lbl_Count->Location = System::Drawing::Point(160, 30);
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
			   this->OPT_lbl_Prompt_count->Location = System::Drawing::Point(61, 30);
			   this->OPT_lbl_Prompt_count->Name = L"OPT_lbl_Prompt_count";
			   this->OPT_lbl_Prompt_count->Size = System::Drawing::Size(40, 16);
			   this->OPT_lbl_Prompt_count->TabIndex = 23;
			   this->OPT_lbl_Prompt_count->Text = L"总计";
			   // 
			   // OPT_btn_New
			   // 
			   this->OPT_btn_New->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_btn_New->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OPT_btn_New->Location = System::Drawing::Point(857, 182);
			   this->OPT_btn_New->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OPT_btn_New->Name = L"OPT_btn_New";
			   this->OPT_btn_New->Size = System::Drawing::Size(94, 49);
			   this->OPT_btn_New->TabIndex = 28;
			   this->OPT_btn_New->Text = L"新建";
			   this->OPT_btn_New->UseVisualStyleBackColor = true;
			   this->OPT_btn_New->Click += gcnew System::EventHandler(this, &MainWindow::OPT_btn_New_Click);
			   // 
			   // OPT_btn_Clear
			   // 
			   this->OPT_btn_Clear->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_btn_Clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OPT_btn_Clear->Location = System::Drawing::Point(719, 182);
			   this->OPT_btn_Clear->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OPT_btn_Clear->Name = L"OPT_btn_Clear";
			   this->OPT_btn_Clear->Size = System::Drawing::Size(94, 49);
			   this->OPT_btn_Clear->TabIndex = 27;
			   this->OPT_btn_Clear->Text = L"清空";
			   this->OPT_btn_Clear->UseVisualStyleBackColor = true;
			   this->OPT_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::OPT_btn_Clear_Click);
			   // 
			   // OPT_btn_Search
			   // 
			   this->OPT_btn_Search->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_btn_Search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->OPT_btn_Search->Location = System::Drawing::Point(581, 182);
			   this->OPT_btn_Search->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OPT_btn_Search->Name = L"OPT_btn_Search";
			   this->OPT_btn_Search->Size = System::Drawing::Size(94, 49);
			   this->OPT_btn_Search->TabIndex = 26;
			   this->OPT_btn_Search->Text = L"搜索";
			   this->OPT_btn_Search->UseVisualStyleBackColor = true;
			   this->OPT_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::OPT_btn_Search_Click);
			   // 
			   // OPT_cmb_Status
			   // 
			   this->OPT_cmb_Status->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_cmb_Status->FormattingEnabled = true;
			   this->OPT_cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Active", L"Invalid" });
			   this->OPT_cmb_Status->Location = System::Drawing::Point(433, 69);
			   this->OPT_cmb_Status->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OPT_cmb_Status->Name = L"OPT_cmb_Status";
			   this->OPT_cmb_Status->Size = System::Drawing::Size(121, 21);
			   this->OPT_cmb_Status->TabIndex = 21;
			   // 
			   // OPT_txt_MemId
			   // 
			   this->OPT_txt_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_txt_MemId->Location = System::Drawing::Point(148, 127);
			   this->OPT_txt_MemId->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OPT_txt_MemId->Name = L"OPT_txt_MemId";
			   this->OPT_txt_MemId->Size = System::Drawing::Size(100, 20);
			   this->OPT_txt_MemId->TabIndex = 20;
			   // 
			   // OPT_txt_CardNumber
			   // 
			   this->OPT_txt_CardNumber->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_txt_CardNumber->Location = System::Drawing::Point(150, 188);
			   this->OPT_txt_CardNumber->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OPT_txt_CardNumber->Name = L"OPT_txt_CardNumber";
			   this->OPT_txt_CardNumber->Size = System::Drawing::Size(100, 20);
			   this->OPT_txt_CardNumber->TabIndex = 19;
			   // 
			   // OPT_txt_MemName
			   // 
			   this->OPT_txt_MemName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_txt_MemName->Location = System::Drawing::Point(434, 133);
			   this->OPT_txt_MemName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->OPT_txt_MemName->Name = L"OPT_txt_MemName";
			   this->OPT_txt_MemName->Size = System::Drawing::Size(120, 20);
			   this->OPT_txt_MemName->TabIndex = 18;
			   // 
			   // OPT_txt_OPTId
			   // 
			   this->OPT_txt_OPTId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_txt_OPTId->Location = System::Drawing::Point(148, 66);
			   this->OPT_txt_OPTId->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			   this->OPT_lbl_error->Location = System::Drawing::Point(410, 445);
			   this->OPT_lbl_error->Name = L"OPT_lbl_error";
			   this->OPT_lbl_error->Size = System::Drawing::Size(94, 20);
			   this->OPT_lbl_error->TabIndex = 16;
			   this->OPT_lbl_error->Text = L"无搜索结果";
			   // 
			   // OPT_lbl_Prompt_Active
			   // 
			   this->OPT_lbl_Prompt_Active->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_Active->AutoSize = true;
			   this->OPT_lbl_Prompt_Active->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_Active->Location = System::Drawing::Point(336, 72);
			   this->OPT_lbl_Prompt_Active->Name = L"OPT_lbl_Prompt_Active";
			   this->OPT_lbl_Prompt_Active->Size = System::Drawing::Size(40, 16);
			   this->OPT_lbl_Prompt_Active->TabIndex = 12;
			   this->OPT_lbl_Prompt_Active->Text = L"状态";
			   // 
			   // OPT_lbl_Prompt_MemId
			   // 
			   this->OPT_lbl_Prompt_MemId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_MemId->AutoSize = true;
			   this->OPT_lbl_Prompt_MemId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_MemId->Location = System::Drawing::Point(50, 129);
			   this->OPT_lbl_Prompt_MemId->Name = L"OPT_lbl_Prompt_MemId";
			   this->OPT_lbl_Prompt_MemId->Size = System::Drawing::Size(72, 16);
			   this->OPT_lbl_Prompt_MemId->TabIndex = 11;
			   this->OPT_lbl_Prompt_MemId->Text = L"成员编号";
			   // 
			   // OPT_lbl_Prompt_MemName
			   // 
			   this->OPT_lbl_Prompt_MemName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_MemName->AutoSize = true;
			   this->OPT_lbl_Prompt_MemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_MemName->Location = System::Drawing::Point(336, 135);
			   this->OPT_lbl_Prompt_MemName->Name = L"OPT_lbl_Prompt_MemName";
			   this->OPT_lbl_Prompt_MemName->Size = System::Drawing::Size(72, 16);
			   this->OPT_lbl_Prompt_MemName->TabIndex = 10;
			   this->OPT_lbl_Prompt_MemName->Text = L"成员姓名";
			   // 
			   // OPT_lbl_Prompt_CardNumber
			   // 
			   this->OPT_lbl_Prompt_CardNumber->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_CardNumber->AutoSize = true;
			   this->OPT_lbl_Prompt_CardNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_CardNumber->Location = System::Drawing::Point(50, 190);
			   this->OPT_lbl_Prompt_CardNumber->Name = L"OPT_lbl_Prompt_CardNumber";
			   this->OPT_lbl_Prompt_CardNumber->Size = System::Drawing::Size(71, 16);
			   this->OPT_lbl_Prompt_CardNumber->TabIndex = 9;
			   this->OPT_lbl_Prompt_CardNumber->Text = L"EAD编号";
			   // 
			   // OPT_lbl_Prompt_OPTId
			   // 
			   this->OPT_lbl_Prompt_OPTId->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->OPT_lbl_Prompt_OPTId->AutoSize = true;
			   this->OPT_lbl_Prompt_OPTId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->OPT_lbl_Prompt_OPTId->Location = System::Drawing::Point(50, 69);
			   this->OPT_lbl_Prompt_OPTId->Name = L"OPT_lbl_Prompt_OPTId";
			   this->OPT_lbl_Prompt_OPTId->Size = System::Drawing::Size(71, 16);
			   this->OPT_lbl_Prompt_OPTId->TabIndex = 8;
			   this->OPT_lbl_Prompt_OPTId->Text = L"OPT编号";
			   // 
			   // OPT_panel1
			   // 
			   this->OPT_panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->OPT_panel1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->OPT_panel1->Location = System::Drawing::Point(0, 0);
			   this->OPT_panel1->Name = L"OPT_panel1";
			   this->OPT_panel1->Size = System::Drawing::Size(982, 271);
			   this->OPT_panel1->TabIndex = 29;
			   // 
			   // pan_record
			   // 
			   this->pan_record->BackColor = System::Drawing::SystemColors::Control;
			   this->pan_record->Controls->Add(this->Rec_btn_Clear);
			   this->pan_record->Controls->Add(this->Rec_btn_RecSearch);
			   this->pan_record->Controls->Add(this->rec_panel3);
			   this->pan_record->Controls->Add(this->rec_panel1);
			   this->pan_record->Controls->Add(this->rec_panel2);
			   this->pan_record->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_record->Location = System::Drawing::Point(0, 0);
			   this->pan_record->Margin = System::Windows::Forms::Padding(2);
			   this->pan_record->Name = L"pan_record";
			   this->pan_record->Size = System::Drawing::Size(982, 636);
			   this->pan_record->TabIndex = 4;
			   // 
			   // Rec_btn_Clear
			   // 
			   this->Rec_btn_Clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_btn_Clear->Location = System::Drawing::Point(837, 115);
			   this->Rec_btn_Clear->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Rec_btn_Clear->Name = L"Rec_btn_Clear";
			   this->Rec_btn_Clear->Size = System::Drawing::Size(79, 37);
			   this->Rec_btn_Clear->TabIndex = 9;
			   this->Rec_btn_Clear->Text = L"清除";
			   this->Rec_btn_Clear->UseVisualStyleBackColor = true;
			   this->Rec_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::Rec_btn_Clear_Click);
			   // 
			   // Rec_btn_RecSearch
			   // 
			   this->Rec_btn_RecSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_btn_RecSearch->Location = System::Drawing::Point(837, 50);
			   this->Rec_btn_RecSearch->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Rec_btn_RecSearch->Name = L"Rec_btn_RecSearch";
			   this->Rec_btn_RecSearch->Size = System::Drawing::Size(79, 37);
			   this->Rec_btn_RecSearch->TabIndex = 8;
			   this->Rec_btn_RecSearch->Text = L"查询";
			   this->Rec_btn_RecSearch->UseVisualStyleBackColor = true;
			   this->Rec_btn_RecSearch->Click += gcnew System::EventHandler(this, &MainWindow::Rec_btn_Search_Click);
			   // 
			   // rec_panel3
			   // 
			   this->rec_panel3->Controls->Add(this->Rec_lbl_Error);
			   this->rec_panel3->Controls->Add(this->Rec_dataGridView);
			   this->rec_panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->rec_panel3->Location = System::Drawing::Point(0, 309);
			   this->rec_panel3->Margin = System::Windows::Forms::Padding(2);
			   this->rec_panel3->Name = L"rec_panel3";
			   this->rec_panel3->Size = System::Drawing::Size(982, 327);
			   this->rec_panel3->TabIndex = 16;
			   // 
			   // Rec_lbl_Error
			   // 
			   this->Rec_lbl_Error->AutoSize = true;
			   this->Rec_lbl_Error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_lbl_Error->ForeColor = System::Drawing::Color::Red;
			   this->Rec_lbl_Error->Location = System::Drawing::Point(452, 136);
			   this->Rec_lbl_Error->Name = L"Rec_lbl_Error";
			   this->Rec_lbl_Error->Size = System::Drawing::Size(77, 20);
			   this->Rec_lbl_Error->TabIndex = 11;
			   this->Rec_lbl_Error->Text = L"错误信息";
			   this->Rec_lbl_Error->Visible = false;
			   // 
			   // Rec_dataGridView
			   // 
			   this->Rec_dataGridView->ColumnHeadersHeight = 29;
			   this->Rec_dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->Rec_dataGridView->Location = System::Drawing::Point(0, 0);
			   this->Rec_dataGridView->Margin = System::Windows::Forms::Padding(2);
			   this->Rec_dataGridView->Name = L"Rec_dataGridView";
			   this->Rec_dataGridView->RowHeadersWidth = 51;
			   this->Rec_dataGridView->RowTemplate->Height = 24;
			   this->Rec_dataGridView->Size = System::Drawing::Size(982, 327);
			   this->Rec_dataGridView->TabIndex = 10;
			   this->Rec_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::Rec_dataGridView_CellContentClick);
			   // 
			   // rec_panel1
			   // 
			   this->rec_panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->rec_panel1->Controls->Add(this->rec_lbl_prompt_Result);
			   this->rec_panel1->Controls->Add(this->rec_lbl_prompt_total);
			   this->rec_panel1->Controls->Add(this->rec_lbl_Count);
			   this->rec_panel1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->rec_panel1->Location = System::Drawing::Point(0, 244);
			   this->rec_panel1->Margin = System::Windows::Forms::Padding(2);
			   this->rec_panel1->MinimumSize = System::Drawing::Size(0, 65);
			   this->rec_panel1->Name = L"rec_panel1";
			   this->rec_panel1->Size = System::Drawing::Size(982, 65);
			   this->rec_panel1->TabIndex = 14;
			   // 
			   // rec_lbl_prompt_Result
			   // 
			   this->rec_lbl_prompt_Result->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->rec_lbl_prompt_Result->AutoSize = true;
			   this->rec_lbl_prompt_Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->rec_lbl_prompt_Result->Location = System::Drawing::Point(434, 21);
			   this->rec_lbl_prompt_Result->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->rec_lbl_prompt_Result->Name = L"rec_lbl_prompt_Result";
			   this->rec_lbl_prompt_Result->Size = System::Drawing::Size(90, 24);
			   this->rec_lbl_prompt_Result->TabIndex = 14;
			   this->rec_lbl_prompt_Result->Text = L"查询结果";
			   // 
			   // rec_lbl_prompt_total
			   // 
			   this->rec_lbl_prompt_total->AutoSize = true;
			   this->rec_lbl_prompt_total->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->rec_lbl_prompt_total->Location = System::Drawing::Point(91, 30);
			   this->rec_lbl_prompt_total->Name = L"rec_lbl_prompt_total";
			   this->rec_lbl_prompt_total->Size = System::Drawing::Size(43, 20);
			   this->rec_lbl_prompt_total->TabIndex = 12;
			   this->rec_lbl_prompt_total->Text = L"总计";
			   // 
			   // rec_lbl_Count
			   // 
			   this->rec_lbl_Count->AutoSize = true;
			   this->rec_lbl_Count->Location = System::Drawing::Point(137, 33);
			   this->rec_lbl_Count->Name = L"rec_lbl_Count";
			   this->rec_lbl_Count->Size = System::Drawing::Size(13, 13);
			   this->rec_lbl_Count->TabIndex = 13;
			   this->rec_lbl_Count->Text = L"0";
			   // 
			   // rec_panel2
			   // 
			   this->rec_panel2->BackColor = System::Drawing::SystemColors::Control;
			   this->rec_panel2->Controls->Add(this->Rec_txt_StfId);
			   this->rec_panel2->Controls->Add(this->Rec_txt_RecId);
			   this->rec_panel2->Controls->Add(this->Rec_txt_department);
			   this->rec_panel2->Controls->Add(this->Rec_lbl_Prompt_MemName);
			   this->rec_panel2->Controls->Add(this->Rec_lbl_Prompt_StfId);
			   this->rec_panel2->Controls->Add(this->Rec_lbl_Prompt_RecId);
			   this->rec_panel2->Controls->Add(this->Rec_txt_MemName);
			   this->rec_panel2->Controls->Add(this->rec_lbl_prompt_department);
			   this->rec_panel2->Dock = System::Windows::Forms::DockStyle::Top;
			   this->rec_panel2->Location = System::Drawing::Point(0, 0);
			   this->rec_panel2->Margin = System::Windows::Forms::Padding(2);
			   this->rec_panel2->MinimumSize = System::Drawing::Size(0, 244);
			   this->rec_panel2->Name = L"rec_panel2";
			   this->rec_panel2->Size = System::Drawing::Size(982, 244);
			   this->rec_panel2->TabIndex = 15;
			   // 
			   // Rec_txt_StfId
			   // 
			   this->Rec_txt_StfId->Location = System::Drawing::Point(150, 102);
			   this->Rec_txt_StfId->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Rec_txt_StfId->Name = L"Rec_txt_StfId";
			   this->Rec_txt_StfId->Size = System::Drawing::Size(100, 20);
			   this->Rec_txt_StfId->TabIndex = 5;
			   // 
			   // Rec_txt_RecId
			   // 
			   this->Rec_txt_RecId->Location = System::Drawing::Point(150, 47);
			   this->Rec_txt_RecId->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Rec_txt_RecId->Name = L"Rec_txt_RecId";
			   this->Rec_txt_RecId->Size = System::Drawing::Size(100, 20);
			   this->Rec_txt_RecId->TabIndex = 4;
			   // 
			   // Rec_txt_department
			   // 
			   this->Rec_txt_department->Location = System::Drawing::Point(380, 102);
			   this->Rec_txt_department->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Rec_txt_department->Name = L"Rec_txt_department";
			   this->Rec_txt_department->Size = System::Drawing::Size(100, 20);
			   this->Rec_txt_department->TabIndex = 7;
			   // 
			   // Rec_lbl_Prompt_MemName
			   // 
			   this->Rec_lbl_Prompt_MemName->AutoSize = true;
			   this->Rec_lbl_Prompt_MemName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->Rec_lbl_Prompt_MemName->Location = System::Drawing::Point(302, 43);
			   this->Rec_lbl_Prompt_MemName->Name = L"Rec_lbl_Prompt_MemName";
			   this->Rec_lbl_Prompt_MemName->Size = System::Drawing::Size(77, 20);
			   this->Rec_lbl_Prompt_MemName->TabIndex = 2;
			   this->Rec_lbl_Prompt_MemName->Text = L"员工姓名";
			   this->Rec_lbl_Prompt_MemName->Click += gcnew System::EventHandler(this, &MainWindow::lbl_Prompt_MemName_Click);
			   // 
			   // Rec_lbl_Prompt_StfId
			   // 
			   this->Rec_lbl_Prompt_StfId->AutoSize = true;
			   this->Rec_lbl_Prompt_StfId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_lbl_Prompt_StfId->Location = System::Drawing::Point(72, 99);
			   this->Rec_lbl_Prompt_StfId->Name = L"Rec_lbl_Prompt_StfId";
			   this->Rec_lbl_Prompt_StfId->Size = System::Drawing::Size(77, 20);
			   this->Rec_lbl_Prompt_StfId->TabIndex = 1;
			   this->Rec_lbl_Prompt_StfId->Text = L"职位职务";
			   // 
			   // Rec_lbl_Prompt_RecId
			   // 
			   this->Rec_lbl_Prompt_RecId->AutoSize = true;
			   this->Rec_lbl_Prompt_RecId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->Rec_lbl_Prompt_RecId->Location = System::Drawing::Point(72, 44);
			   this->Rec_lbl_Prompt_RecId->Name = L"Rec_lbl_Prompt_RecId";
			   this->Rec_lbl_Prompt_RecId->Size = System::Drawing::Size(77, 20);
			   this->Rec_lbl_Prompt_RecId->TabIndex = 0;
			   this->Rec_lbl_Prompt_RecId->Text = L"记录编号";
			   // 
			   // Rec_txt_MemName
			   // 
			   this->Rec_txt_MemName->Location = System::Drawing::Point(380, 46);
			   this->Rec_txt_MemName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Rec_txt_MemName->Name = L"Rec_txt_MemName";
			   this->Rec_txt_MemName->Size = System::Drawing::Size(100, 20);
			   this->Rec_txt_MemName->TabIndex = 6;
			   // 
			   // rec_lbl_prompt_department
			   // 
			   this->rec_lbl_prompt_department->AutoSize = true;
			   this->rec_lbl_prompt_department->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->rec_lbl_prompt_department->Location = System::Drawing::Point(302, 98);
			   this->rec_lbl_prompt_department->Name = L"rec_lbl_prompt_department";
			   this->rec_lbl_prompt_department->Size = System::Drawing::Size(77, 20);
			   this->rec_lbl_prompt_department->TabIndex = 3;
			   this->rec_lbl_prompt_department->Text = L"所在部门";
			   // 
			   // pan_order
			   // 
			   this->pan_order->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->pan_order->Controls->Add(this->ord_panel3);
			   this->pan_order->Controls->Add(this->ord_panel2);
			   this->pan_order->Controls->Add(this->ord_panel1);
			   this->pan_order->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_order->Location = System::Drawing::Point(0, 0);
			   this->pan_order->Margin = System::Windows::Forms::Padding(2);
			   this->pan_order->Name = L"pan_order";
			   this->pan_order->Size = System::Drawing::Size(982, 636);
			   this->pan_order->TabIndex = 2;
			   // 
			   // ord_panel3
			   // 
			   this->ord_panel3->Controls->Add(this->ord_lbl_Error);
			   this->ord_panel3->Controls->Add(this->ord_dataGridView);
			   this->ord_panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->ord_panel3->Location = System::Drawing::Point(0, 353);
			   this->ord_panel3->Margin = System::Windows::Forms::Padding(2);
			   this->ord_panel3->Name = L"ord_panel3";
			   this->ord_panel3->Size = System::Drawing::Size(982, 283);
			   this->ord_panel3->TabIndex = 24;
			   // 
			   // ord_lbl_Error
			   // 
			   this->ord_lbl_Error->AutoSize = true;
			   this->ord_lbl_Error->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Error->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Error->ForeColor = System::Drawing::Color::Red;
			   this->ord_lbl_Error->Location = System::Drawing::Point(478, 128);
			   this->ord_lbl_Error->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Error->Name = L"ord_lbl_Error";
			   this->ord_lbl_Error->Size = System::Drawing::Size(43, 20);
			   this->ord_lbl_Error->TabIndex = 21;
			   this->ord_lbl_Error->Text = L"错误";
			   // 
			   // ord_dataGridView
			   // 
			   this->ord_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->ord_dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->ord_dataGridView->Location = System::Drawing::Point(0, 0);
			   this->ord_dataGridView->Margin = System::Windows::Forms::Padding(2);
			   this->ord_dataGridView->Name = L"ord_dataGridView";
			   this->ord_dataGridView->RowHeadersWidth = 51;
			   this->ord_dataGridView->RowTemplate->Height = 24;
			   this->ord_dataGridView->Size = System::Drawing::Size(982, 283);
			   this->ord_dataGridView->TabIndex = 12;
			   this->ord_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::ord_dataGridView_CellContentClick);
			   // 
			   // ord_panel2
			   // 
			   this->ord_panel2->Controls->Add(this->ord_lbl_Prompt_Count);
			   this->ord_panel2->Controls->Add(this->ord_lbl_Count);
			   this->ord_panel2->Controls->Add(this->ord_lbl_Prompt_SearchResult);
			   this->ord_panel2->Controls->Add(this->ord_lbl_Prompt_ViewInfo);
			   this->ord_panel2->Dock = System::Windows::Forms::DockStyle::Top;
			   this->ord_panel2->Location = System::Drawing::Point(0, 281);
			   this->ord_panel2->Margin = System::Windows::Forms::Padding(2);
			   this->ord_panel2->Name = L"ord_panel2";
			   this->ord_panel2->Size = System::Drawing::Size(982, 72);
			   this->ord_panel2->TabIndex = 20;
			   // 
			   // ord_lbl_Prompt_Count
			   // 
			   this->ord_lbl_Prompt_Count->AutoSize = true;
			   this->ord_lbl_Prompt_Count->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Prompt_Count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_Count->Location = System::Drawing::Point(72, 30);
			   this->ord_lbl_Prompt_Count->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_Count->Name = L"ord_lbl_Prompt_Count";
			   this->ord_lbl_Prompt_Count->Size = System::Drawing::Size(48, 20);
			   this->ord_lbl_Prompt_Count->TabIndex = 15;
			   this->ord_lbl_Prompt_Count->Text = L"总计:";
			   // 
			   // ord_lbl_Count
			   // 
			   this->ord_lbl_Count->AutoSize = true;
			   this->ord_lbl_Count->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Count->Location = System::Drawing::Point(184, 30);
			   this->ord_lbl_Count->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Count->Name = L"ord_lbl_Count";
			   this->ord_lbl_Count->Size = System::Drawing::Size(35, 20);
			   this->ord_lbl_Count->TabIndex = 16;
			   this->ord_lbl_Count->Text = L"N/A";
			   // 
			   // ord_lbl_Prompt_SearchResult
			   // 
			   this->ord_lbl_Prompt_SearchResult->AutoSize = true;
			   this->ord_lbl_Prompt_SearchResult->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Prompt_SearchResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_SearchResult->Location = System::Drawing::Point(452, 24);
			   this->ord_lbl_Prompt_SearchResult->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_SearchResult->Name = L"ord_lbl_Prompt_SearchResult";
			   this->ord_lbl_Prompt_SearchResult->Size = System::Drawing::Size(104, 26);
			   this->ord_lbl_Prompt_SearchResult->TabIndex = 14;
			   this->ord_lbl_Prompt_SearchResult->Text = L"查询结果";
			   // 
			   // ord_lbl_Prompt_ViewInfo
			   // 
			   this->ord_lbl_Prompt_ViewInfo->AutoSize = true;
			   this->ord_lbl_Prompt_ViewInfo->BackColor = System::Drawing::SystemColors::Control;
			   this->ord_lbl_Prompt_ViewInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_ViewInfo->Location = System::Drawing::Point(766, 26);
			   this->ord_lbl_Prompt_ViewInfo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_ViewInfo->Name = L"ord_lbl_Prompt_ViewInfo";
			   this->ord_lbl_Prompt_ViewInfo->Size = System::Drawing::Size(73, 20);
			   this->ord_lbl_Prompt_ViewInfo->TabIndex = 22;
			   this->ord_lbl_Prompt_ViewInfo->Text = L"订单信息";
			   // 
			   // ord_panel1
			   // 
			   this->ord_panel1->BackColor = System::Drawing::SystemColors::Menu;
			   this->ord_panel1->Controls->Add(this->ord_lbl_Prompt_ordId);
			   this->ord_panel1->Controls->Add(this->ord_txt_ordId);
			   this->ord_panel1->Controls->Add(this->ord_lbl_Prompt_Status);
			   this->ord_panel1->Controls->Add(this->ord_cmb_Status);
			   this->ord_panel1->Controls->Add(this->ord_btn_Add);
			   this->ord_panel1->Controls->Add(this->ord_lbl_Prompt_memId);
			   this->ord_panel1->Controls->Add(this->ord_btn_Clear);
			   this->ord_panel1->Controls->Add(this->ord_txt_memId);
			   this->ord_panel1->Controls->Add(this->ord_btn_Search);
			   this->ord_panel1->Controls->Add(this->ord_lbl_Prompt_memName);
			   this->ord_panel1->Controls->Add(this->ord_txt_memName);
			   this->ord_panel1->Controls->Add(this->ord_lbl_Prompt_itmId);
			   this->ord_panel1->Controls->Add(this->ord_txt_itmId);
			   this->ord_panel1->Controls->Add(this->ord_lbl_Prompt_itmName);
			   this->ord_panel1->Controls->Add(this->ord_txt_itmName);
			   this->ord_panel1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->ord_panel1->Location = System::Drawing::Point(0, 0);
			   this->ord_panel1->Margin = System::Windows::Forms::Padding(2);
			   this->ord_panel1->Name = L"ord_panel1";
			   this->ord_panel1->Size = System::Drawing::Size(982, 281);
			   this->ord_panel1->TabIndex = 23;
			   // 
			   // ord_lbl_Prompt_ordId
			   // 
			   this->ord_lbl_Prompt_ordId->AutoSize = true;
			   this->ord_lbl_Prompt_ordId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_ordId->Location = System::Drawing::Point(66, 54);
			   this->ord_lbl_Prompt_ordId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_ordId->Name = L"ord_lbl_Prompt_ordId";
			   this->ord_lbl_Prompt_ordId->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_ordId->TabIndex = 0;
			   this->ord_lbl_Prompt_ordId->Text = L"订单编号";
			   // 
			   // ord_txt_ordId
			   // 
			   this->ord_txt_ordId->Location = System::Drawing::Point(188, 54);
			   this->ord_txt_ordId->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_ordId->Name = L"ord_txt_ordId";
			   this->ord_txt_ordId->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_ordId->TabIndex = 1;
			   // 
			   // ord_lbl_Prompt_Status
			   // 
			   this->ord_lbl_Prompt_Status->AutoSize = true;
			   this->ord_lbl_Prompt_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_Status->Location = System::Drawing::Point(364, 50);
			   this->ord_lbl_Prompt_Status->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_Status->Name = L"ord_lbl_Prompt_Status";
			   this->ord_lbl_Prompt_Status->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_Status->TabIndex = 2;
			   this->ord_lbl_Prompt_Status->Text = L"订单状态";
			   // 
			   // ord_cmb_Status
			   // 
			   this->ord_cmb_Status->FormattingEnabled = true;
			   this->ord_cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"InvalidComplete", L"In process" });
			   this->ord_cmb_Status->Location = System::Drawing::Point(469, 50);
			   this->ord_cmb_Status->Margin = System::Windows::Forms::Padding(2);
			   this->ord_cmb_Status->Name = L"ord_cmb_Status";
			   this->ord_cmb_Status->Size = System::Drawing::Size(92, 21);
			   this->ord_cmb_Status->TabIndex = 3;
			   // 
			   // ord_btn_Add
			   // 
			   this->ord_btn_Add->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_btn_Add->Location = System::Drawing::Point(695, 157);
			   this->ord_btn_Add->Margin = System::Windows::Forms::Padding(2);
			   this->ord_btn_Add->Name = L"ord_btn_Add";
			   this->ord_btn_Add->Size = System::Drawing::Size(75, 37);
			   this->ord_btn_Add->TabIndex = 19;
			   this->ord_btn_Add->Text = L"新建";
			   this->ord_btn_Add->UseVisualStyleBackColor = true;
			   this->ord_btn_Add->Click += gcnew System::EventHandler(this, &MainWindow::ord_btn_Add_Click);
			   // 
			   // ord_lbl_Prompt_memId
			   // 
			   this->ord_lbl_Prompt_memId->AutoSize = true;
			   this->ord_lbl_Prompt_memId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_memId->Location = System::Drawing::Point(66, 114);
			   this->ord_lbl_Prompt_memId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_memId->Name = L"ord_lbl_Prompt_memId";
			   this->ord_lbl_Prompt_memId->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_memId->TabIndex = 4;
			   this->ord_lbl_Prompt_memId->Text = L"成员编号";
			   // 
			   // ord_btn_Clear
			   // 
			   this->ord_btn_Clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_btn_Clear->Location = System::Drawing::Point(695, 100);
			   this->ord_btn_Clear->Margin = System::Windows::Forms::Padding(2);
			   this->ord_btn_Clear->Name = L"ord_btn_Clear";
			   this->ord_btn_Clear->Size = System::Drawing::Size(75, 37);
			   this->ord_btn_Clear->TabIndex = 18;
			   this->ord_btn_Clear->Text = L"清除";
			   this->ord_btn_Clear->UseVisualStyleBackColor = true;
			   this->ord_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::ord_btn_Clear_Click);
			   // 
			   // ord_txt_memId
			   // 
			   this->ord_txt_memId->Location = System::Drawing::Point(188, 112);
			   this->ord_txt_memId->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_memId->Name = L"ord_txt_memId";
			   this->ord_txt_memId->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_memId->TabIndex = 5;
			   // 
			   // ord_btn_Search
			   // 
			   this->ord_btn_Search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_btn_Search->Location = System::Drawing::Point(695, 41);
			   this->ord_btn_Search->Margin = System::Windows::Forms::Padding(2);
			   this->ord_btn_Search->Name = L"ord_btn_Search";
			   this->ord_btn_Search->Size = System::Drawing::Size(75, 37);
			   this->ord_btn_Search->TabIndex = 17;
			   this->ord_btn_Search->Text = L"查询";
			   this->ord_btn_Search->UseVisualStyleBackColor = true;
			   this->ord_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::ord_btn_Search_Click);
			   // 
			   // ord_lbl_Prompt_memName
			   // 
			   this->ord_lbl_Prompt_memName->AutoSize = true;
			   this->ord_lbl_Prompt_memName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_memName->Location = System::Drawing::Point(364, 112);
			   this->ord_lbl_Prompt_memName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_memName->Name = L"ord_lbl_Prompt_memName";
			   this->ord_lbl_Prompt_memName->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_memName->TabIndex = 6;
			   this->ord_lbl_Prompt_memName->Text = L"成员姓名";
			   // 
			   // ord_txt_memName
			   // 
			   this->ord_txt_memName->Location = System::Drawing::Point(469, 110);
			   this->ord_txt_memName->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_memName->Name = L"ord_txt_memName";
			   this->ord_txt_memName->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_memName->TabIndex = 7;
			   // 
			   // ord_lbl_Prompt_itmId
			   // 
			   this->ord_lbl_Prompt_itmId->AutoSize = true;
			   this->ord_lbl_Prompt_itmId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_itmId->Location = System::Drawing::Point(66, 169);
			   this->ord_lbl_Prompt_itmId->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_itmId->Name = L"ord_lbl_Prompt_itmId";
			   this->ord_lbl_Prompt_itmId->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_itmId->TabIndex = 8;
			   this->ord_lbl_Prompt_itmId->Text = L"商品编号";
			   // 
			   // ord_txt_itmId
			   // 
			   this->ord_txt_itmId->Location = System::Drawing::Point(188, 169);
			   this->ord_txt_itmId->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_itmId->Name = L"ord_txt_itmId";
			   this->ord_txt_itmId->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_itmId->TabIndex = 9;
			   // 
			   // ord_lbl_Prompt_itmName
			   // 
			   this->ord_lbl_Prompt_itmName->AutoSize = true;
			   this->ord_lbl_Prompt_itmName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->ord_lbl_Prompt_itmName->Location = System::Drawing::Point(364, 169);
			   this->ord_lbl_Prompt_itmName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->ord_lbl_Prompt_itmName->Name = L"ord_lbl_Prompt_itmName";
			   this->ord_lbl_Prompt_itmName->Size = System::Drawing::Size(77, 20);
			   this->ord_lbl_Prompt_itmName->TabIndex = 10;
			   this->ord_lbl_Prompt_itmName->Text = L"商品名称";
			   // 
			   // ord_txt_itmName
			   // 
			   this->ord_txt_itmName->Location = System::Drawing::Point(469, 169);
			   this->ord_txt_itmName->Margin = System::Windows::Forms::Padding(2);
			   this->ord_txt_itmName->Name = L"ord_txt_itmName";
			   this->ord_txt_itmName->Size = System::Drawing::Size(92, 20);
			   this->ord_txt_itmName->TabIndex = 11;
			   // 
			   // pan_member
			   // 
			   this->pan_member->Controls->Add(this->mem_panel4);
			   this->pan_member->Controls->Add(this->mem_panel3);
			   this->pan_member->Controls->Add(this->mem_panel1);
			   this->pan_member->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_member->Location = System::Drawing::Point(0, 0);
			   this->pan_member->Margin = System::Windows::Forms::Padding(2);
			   this->pan_member->Name = L"pan_member";
			   this->pan_member->Size = System::Drawing::Size(982, 636);
			   this->pan_member->TabIndex = 6;
			   // 
			   // mem_panel4
			   // 
			   this->mem_panel4->Controls->Add(this->mem_lbl_error);
			   this->mem_panel4->Controls->Add(this->mem_dataGridView1);
			   this->mem_panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->mem_panel4->Location = System::Drawing::Point(0, 335);
			   this->mem_panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_panel4->Name = L"mem_panel4";
			   this->mem_panel4->Size = System::Drawing::Size(982, 301);
			   this->mem_panel4->TabIndex = 73;
			   // 
			   // mem_lbl_error
			   // 
			   this->mem_lbl_error->AutoSize = true;
			   this->mem_lbl_error->ForeColor = System::Drawing::Color::Red;
			   this->mem_lbl_error->Location = System::Drawing::Point(479, 167);
			   this->mem_lbl_error->Name = L"mem_lbl_error";
			   this->mem_lbl_error->Size = System::Drawing::Size(29, 13);
			   this->mem_lbl_error->TabIndex = 22;
			   this->mem_lbl_error->Text = L"Error";
			   this->mem_lbl_error->Visible = false;
			   // 
			   // mem_dataGridView1
			   // 
			   this->mem_dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->mem_dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->mem_dataGridView1->Location = System::Drawing::Point(0, 0);
			   this->mem_dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_dataGridView1->Name = L"mem_dataGridView1";
			   this->mem_dataGridView1->RowHeadersWidth = 51;
			   this->mem_dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->mem_dataGridView1->Size = System::Drawing::Size(982, 301);
			   this->mem_dataGridView1->TabIndex = 16;
			   this->mem_dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::mem_dataGridView1_CellContentClick);
			   // 
			   // mem_panel3
			   // 
			   this->mem_panel3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->mem_panel3->Controls->Add(this->mem_Prompt_ViewInfo);
			   this->mem_panel3->Controls->Add(this->mem_Prompt_查询结果);
			   this->mem_panel3->Controls->Add(this->mem_lbl_Count);
			   this->mem_panel3->Controls->Add(this->mem_lbl_Prompt_总数);
			   this->mem_panel3->Dock = System::Windows::Forms::DockStyle::Top;
			   this->mem_panel3->Location = System::Drawing::Point(0, 265);
			   this->mem_panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_panel3->MinimumSize = System::Drawing::Size(0, 70);
			   this->mem_panel3->Name = L"mem_panel3";
			   this->mem_panel3->Size = System::Drawing::Size(982, 70);
			   this->mem_panel3->TabIndex = 72;
			   // 
			   // mem_Prompt_ViewInfo
			   // 
			   this->mem_Prompt_ViewInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->mem_Prompt_ViewInfo->AutoSize = true;
			   this->mem_Prompt_ViewInfo->Location = System::Drawing::Point(783, 54);
			   this->mem_Prompt_ViewInfo->Name = L"mem_Prompt_ViewInfo";
			   this->mem_Prompt_ViewInfo->Size = System::Drawing::Size(187, 13);
			   this->mem_Prompt_ViewInfo->TabIndex = 24;
			   this->mem_Prompt_ViewInfo->Text = L"默认查找结果为显示全部成员信息";
			   // 
			   // mem_Prompt_查询结果
			   // 
			   this->mem_Prompt_查询结果->Anchor = System::Windows::Forms::AnchorStyles::Top;
			   this->mem_Prompt_查询结果->AutoSize = true;
			   this->mem_Prompt_查询结果->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->mem_Prompt_查询结果->Location = System::Drawing::Point(466, 24);
			   this->mem_Prompt_查询结果->Name = L"mem_Prompt_查询结果";
			   this->mem_Prompt_查询结果->Size = System::Drawing::Size(77, 20);
			   this->mem_Prompt_查询结果->TabIndex = 23;
			   this->mem_Prompt_查询结果->Text = L"查询结果";
			   // 
			   // mem_lbl_Count
			   // 
			   this->mem_lbl_Count->AccessibleDescription = L"";
			   this->mem_lbl_Count->AutoSize = true;
			   this->mem_lbl_Count->Location = System::Drawing::Point(52, 26);
			   this->mem_lbl_Count->Name = L"mem_lbl_Count";
			   this->mem_lbl_Count->Size = System::Drawing::Size(13, 13);
			   this->mem_lbl_Count->TabIndex = 70;
			   this->mem_lbl_Count->Text = L"0";
			   // 
			   // mem_lbl_Prompt_总数
			   // 
			   this->mem_lbl_Prompt_总数->AccessibleDescription = L"";
			   this->mem_lbl_Prompt_总数->AutoSize = true;
			   this->mem_lbl_Prompt_总数->Location = System::Drawing::Point(12, 26);
			   this->mem_lbl_Prompt_总数->Name = L"mem_lbl_Prompt_总数";
			   this->mem_lbl_Prompt_总数->Size = System::Drawing::Size(34, 13);
			   this->mem_lbl_Prompt_总数->TabIndex = 69;
			   this->mem_lbl_Prompt_总数->Text = L"总计:";
			   // 
			   // mem_panel1
			   // 
			   this->mem_panel1->Controls->Add(this->panel2);
			   this->mem_panel1->Controls->Add(this->mem_cmb_SearchAuth);
			   this->mem_panel1->Controls->Add(this->mem_cmb_Status);
			   this->mem_panel1->Controls->Add(this->mem_txt_Gender);
			   this->mem_panel1->Controls->Add(this->mem_Prompt_PgInfo);
			   this->mem_panel1->Controls->Add(this->mem_txt_Name);
			   this->mem_panel1->Controls->Add(this->mem_txt_Major);
			   this->mem_panel1->Controls->Add(this->mem_btn_Import);
			   this->mem_panel1->Controls->Add(this->mem_txt_Id);
			   this->mem_panel1->Controls->Add(this->mem_btn_Add);
			   this->mem_panel1->Controls->Add(this->mem_lbl_Prompt_SearchAuth);
			   this->mem_panel1->Controls->Add(this->mem_btn_Clear);
			   this->mem_panel1->Controls->Add(this->mem_btn_Search);
			   this->mem_panel1->Controls->Add(this->mem_lbl_Prompt_Major);
			   this->mem_panel1->Controls->Add(this->mem_lbl_Prompt_Gender);
			   this->mem_panel1->Controls->Add(this->mem_lbl_Prompt_Type);
			   this->mem_panel1->Controls->Add(this->mem_cmb_Type);
			   this->mem_panel1->Controls->Add(this->mem_lbl_Prompt_Status);
			   this->mem_panel1->Controls->Add(this->mem_cmb_CareerStatus);
			   this->mem_panel1->Controls->Add(this->mem_lbl_Prompt_Id);
			   this->mem_panel1->Controls->Add(this->mem_lbl_Prompt_Name);
			   this->mem_panel1->Controls->Add(this->mem_lbl_Prompt_CareerStatus);
			   this->mem_panel1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->mem_panel1->Location = System::Drawing::Point(0, 0);
			   this->mem_panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_panel1->MinimumSize = System::Drawing::Size(0, 265);
			   this->mem_panel1->Name = L"mem_panel1";
			   this->mem_panel1->Size = System::Drawing::Size(982, 265);
			   this->mem_panel1->TabIndex = 71;
			   // 
			   // panel2
			   // 
			   this->panel2->Location = System::Drawing::Point(323, 274);
			   this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(630, 45);
			   this->panel2->TabIndex = 68;
			   // 
			   // mem_cmb_SearchAuth
			   // 
			   this->mem_cmb_SearchAuth->FormattingEnabled = true;
			   this->mem_cmb_SearchAuth->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Yes", L"No" });
			   this->mem_cmb_SearchAuth->Location = System::Drawing::Point(559, 102);
			   this->mem_cmb_SearchAuth->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_cmb_SearchAuth->Name = L"mem_cmb_SearchAuth";
			   this->mem_cmb_SearchAuth->Size = System::Drawing::Size(132, 21);
			   this->mem_cmb_SearchAuth->TabIndex = 15;
			   // 
			   // mem_cmb_Status
			   // 
			   this->mem_cmb_Status->FormattingEnabled = true;
			   this->mem_cmb_Status->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Active", L"Review", L"Invalid" });
			   this->mem_cmb_Status->Location = System::Drawing::Point(321, 51);
			   this->mem_cmb_Status->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_cmb_Status->Name = L"mem_cmb_Status";
			   this->mem_cmb_Status->Size = System::Drawing::Size(132, 21);
			   this->mem_cmb_Status->TabIndex = 13;
			   // 
			   // mem_txt_Gender
			   // 
			   this->mem_txt_Gender->Location = System::Drawing::Point(321, 102);
			   this->mem_txt_Gender->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_txt_Gender->Name = L"mem_txt_Gender";
			   this->mem_txt_Gender->Size = System::Drawing::Size(132, 20);
			   this->mem_txt_Gender->TabIndex = 11;
			   // 
			   // mem_Prompt_PgInfo
			   // 
			   this->mem_Prompt_PgInfo->AccessibleDescription = L"";
			   this->mem_Prompt_PgInfo->AutoSize = true;
			   this->mem_Prompt_PgInfo->Location = System::Drawing::Point(39, 238);
			   this->mem_Prompt_PgInfo->Name = L"mem_Prompt_PgInfo";
			   this->mem_Prompt_PgInfo->Size = System::Drawing::Size(331, 13);
			   this->mem_Prompt_PgInfo->TabIndex = 67;
			   this->mem_Prompt_PgInfo->Text = L"数据使用精准查询，没有必填项目。请尽量提供详细信息即可";
			   // 
			   // mem_txt_Name
			   // 
			   this->mem_txt_Name->Location = System::Drawing::Point(106, 102);
			   this->mem_txt_Name->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_txt_Name->Name = L"mem_txt_Name";
			   this->mem_txt_Name->Size = System::Drawing::Size(132, 20);
			   this->mem_txt_Name->TabIndex = 10;
			   // 
			   // mem_txt_Major
			   // 
			   this->mem_txt_Major->Location = System::Drawing::Point(106, 147);
			   this->mem_txt_Major->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_txt_Major->Name = L"mem_txt_Major";
			   this->mem_txt_Major->Size = System::Drawing::Size(132, 20);
			   this->mem_txt_Major->TabIndex = 9;
			   // 
			   // mem_btn_Import
			   // 
			   this->mem_btn_Import->Location = System::Drawing::Point(792, 206);
			   this->mem_btn_Import->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_btn_Import->Name = L"mem_btn_Import";
			   this->mem_btn_Import->Size = System::Drawing::Size(70, 28);
			   this->mem_btn_Import->TabIndex = 21;
			   this->mem_btn_Import->Text = L"导入";
			   this->mem_btn_Import->UseVisualStyleBackColor = true;
			   this->mem_btn_Import->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Import_Click);
			   // 
			   // mem_txt_Id
			   // 
			   this->mem_txt_Id->Location = System::Drawing::Point(106, 52);
			   this->mem_txt_Id->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_txt_Id->Name = L"mem_txt_Id";
			   this->mem_txt_Id->Size = System::Drawing::Size(132, 20);
			   this->mem_txt_Id->TabIndex = 8;
			   // 
			   // mem_btn_Add
			   // 
			   this->mem_btn_Add->Location = System::Drawing::Point(792, 148);
			   this->mem_btn_Add->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_btn_Add->Name = L"mem_btn_Add";
			   this->mem_btn_Add->Size = System::Drawing::Size(70, 28);
			   this->mem_btn_Add->TabIndex = 20;
			   this->mem_btn_Add->Text = L"添加";
			   this->mem_btn_Add->UseVisualStyleBackColor = true;
			   this->mem_btn_Add->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Add_Click);
			   // 
			   // mem_lbl_Prompt_SearchAuth
			   // 
			   this->mem_lbl_Prompt_SearchAuth->AutoSize = true;
			   this->mem_lbl_Prompt_SearchAuth->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->mem_lbl_Prompt_SearchAuth->Location = System::Drawing::Point(495, 103);
			   this->mem_lbl_Prompt_SearchAuth->Name = L"mem_lbl_Prompt_SearchAuth";
			   this->mem_lbl_Prompt_SearchAuth->Size = System::Drawing::Size(68, 18);
			   this->mem_lbl_Prompt_SearchAuth->TabIndex = 7;
			   this->mem_lbl_Prompt_SearchAuth->Text = L"搜索授权";
			   // 
			   // mem_btn_Clear
			   // 
			   this->mem_btn_Clear->Location = System::Drawing::Point(792, 87);
			   this->mem_btn_Clear->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_btn_Clear->Name = L"mem_btn_Clear";
			   this->mem_btn_Clear->Size = System::Drawing::Size(70, 28);
			   this->mem_btn_Clear->TabIndex = 19;
			   this->mem_btn_Clear->Text = L"清空";
			   this->mem_btn_Clear->UseVisualStyleBackColor = true;
			   this->mem_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Clear_Click);
			   // 
			   // mem_btn_Search
			   // 
			   this->mem_btn_Search->Location = System::Drawing::Point(792, 28);
			   this->mem_btn_Search->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_btn_Search->Name = L"mem_btn_Search";
			   this->mem_btn_Search->Size = System::Drawing::Size(70, 28);
			   this->mem_btn_Search->TabIndex = 18;
			   this->mem_btn_Search->Text = L"查询";
			   this->mem_btn_Search->UseVisualStyleBackColor = true;
			   this->mem_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::mem_btn_Search_Click);
			   // 
			   // mem_lbl_Prompt_Major
			   // 
			   this->mem_lbl_Prompt_Major->AutoSize = true;
			   this->mem_lbl_Prompt_Major->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->mem_lbl_Prompt_Major->Location = System::Drawing::Point(62, 147);
			   this->mem_lbl_Prompt_Major->Name = L"mem_lbl_Prompt_Major";
			   this->mem_lbl_Prompt_Major->Size = System::Drawing::Size(38, 18);
			   this->mem_lbl_Prompt_Major->TabIndex = 6;
			   this->mem_lbl_Prompt_Major->Text = L"专业";
			   // 
			   // mem_lbl_Prompt_Gender
			   // 
			   this->mem_lbl_Prompt_Gender->AutoSize = true;
			   this->mem_lbl_Prompt_Gender->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->mem_lbl_Prompt_Gender->Location = System::Drawing::Point(281, 102);
			   this->mem_lbl_Prompt_Gender->Name = L"mem_lbl_Prompt_Gender";
			   this->mem_lbl_Prompt_Gender->Size = System::Drawing::Size(38, 18);
			   this->mem_lbl_Prompt_Gender->TabIndex = 4;
			   this->mem_lbl_Prompt_Gender->Text = L"性别";
			   // 
			   // mem_lbl_Prompt_Type
			   // 
			   this->mem_lbl_Prompt_Type->AutoSize = true;
			   this->mem_lbl_Prompt_Type->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->mem_lbl_Prompt_Type->Location = System::Drawing::Point(495, 54);
			   this->mem_lbl_Prompt_Type->Name = L"mem_lbl_Prompt_Type";
			   this->mem_lbl_Prompt_Type->Size = System::Drawing::Size(68, 18);
			   this->mem_lbl_Prompt_Type->TabIndex = 2;
			   this->mem_lbl_Prompt_Type->Text = L"成员类型";
			   // 
			   // mem_cmb_Type
			   // 
			   this->mem_cmb_Type->FormattingEnabled = true;
			   this->mem_cmb_Type->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Normal", L"DivHead", L"Staff", L"Head" });
			   this->mem_cmb_Type->Location = System::Drawing::Point(559, 50);
			   this->mem_cmb_Type->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_cmb_Type->Name = L"mem_cmb_Type";
			   this->mem_cmb_Type->Size = System::Drawing::Size(132, 21);
			   this->mem_cmb_Type->TabIndex = 14;
			   // 
			   // mem_lbl_Prompt_Status
			   // 
			   this->mem_lbl_Prompt_Status->AutoSize = true;
			   this->mem_lbl_Prompt_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->mem_lbl_Prompt_Status->Location = System::Drawing::Point(248, 51);
			   this->mem_lbl_Prompt_Status->Name = L"mem_lbl_Prompt_Status";
			   this->mem_lbl_Prompt_Status->Size = System::Drawing::Size(68, 18);
			   this->mem_lbl_Prompt_Status->TabIndex = 1;
			   this->mem_lbl_Prompt_Status->Text = L"成员状态";
			   // 
			   // mem_cmb_CareerStatus
			   // 
			   this->mem_cmb_CareerStatus->FormattingEnabled = true;
			   this->mem_cmb_CareerStatus->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				   L"GradProgram", L"Unemployed", L"Employed",
					   L"StartBusiness"
			   });
			   this->mem_cmb_CareerStatus->Location = System::Drawing::Point(321, 147);
			   this->mem_cmb_CareerStatus->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->mem_cmb_CareerStatus->Name = L"mem_cmb_CareerStatus";
			   this->mem_cmb_CareerStatus->Size = System::Drawing::Size(132, 21);
			   this->mem_cmb_CareerStatus->TabIndex = 17;
			   // 
			   // mem_lbl_Prompt_Id
			   // 
			   this->mem_lbl_Prompt_Id->AutoSize = true;
			   this->mem_lbl_Prompt_Id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->mem_lbl_Prompt_Id->Location = System::Drawing::Point(35, 51);
			   this->mem_lbl_Prompt_Id->Name = L"mem_lbl_Prompt_Id";
			   this->mem_lbl_Prompt_Id->Size = System::Drawing::Size(68, 18);
			   this->mem_lbl_Prompt_Id->TabIndex = 0;
			   this->mem_lbl_Prompt_Id->Text = L"成员编号";
			   // 
			   // mem_lbl_Prompt_Name
			   // 
			   this->mem_lbl_Prompt_Name->AutoSize = true;
			   this->mem_lbl_Prompt_Name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->mem_lbl_Prompt_Name->Location = System::Drawing::Point(62, 102);
			   this->mem_lbl_Prompt_Name->Name = L"mem_lbl_Prompt_Name";
			   this->mem_lbl_Prompt_Name->Size = System::Drawing::Size(38, 18);
			   this->mem_lbl_Prompt_Name->TabIndex = 3;
			   this->mem_lbl_Prompt_Name->Text = L"姓名";
			   // 
			   // mem_lbl_Prompt_CareerStatus
			   // 
			   this->mem_lbl_Prompt_CareerStatus->AutoSize = true;
			   this->mem_lbl_Prompt_CareerStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->mem_lbl_Prompt_CareerStatus->Location = System::Drawing::Point(248, 147);
			   this->mem_lbl_Prompt_CareerStatus->Name = L"mem_lbl_Prompt_CareerStatus";
			   this->mem_lbl_Prompt_CareerStatus->Size = System::Drawing::Size(68, 18);
			   this->mem_lbl_Prompt_CareerStatus->TabIndex = 5;
			   this->mem_lbl_Prompt_CareerStatus->Text = L"就业状态";
			   // 
			   // pan_staff
			   // 
			   this->pan_staff->Controls->Add(this->stf_dataGridView);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_SearchResult);
			   this->pan_staff->Controls->Add(this->stf_lbl_Error);
			   this->pan_staff->Controls->Add(this->stf_lbl_Count);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Count);
			   this->pan_staff->Controls->Add(this->stf_btn_Add);
			   this->pan_staff->Controls->Add(this->stf_btn_Clear);
			   this->pan_staff->Controls->Add(this->stf_btn_Search);
			   this->pan_staff->Controls->Add(this->stf_cmb_Auth);
			   this->pan_staff->Controls->Add(this->stf_cmb_Dept);
			   this->pan_staff->Controls->Add(this->stf_txt_Name);
			   this->pan_staff->Controls->Add(this->stf_txt_Id);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Auth);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Dept);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Name);
			   this->pan_staff->Controls->Add(this->stf_lbl_Prompt_Id);
			   this->pan_staff->Controls->Add(this->splitter5);
			   this->pan_staff->Controls->Add(this->splitter4);
			   this->pan_staff->Controls->Add(this->splitter3);
			   this->pan_staff->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_staff->Location = System::Drawing::Point(0, 0);
			   this->pan_staff->Margin = System::Windows::Forms::Padding(2);
			   this->pan_staff->Name = L"pan_staff";
			   this->pan_staff->Size = System::Drawing::Size(982, 636);
			   this->pan_staff->TabIndex = 5;
			   // 
			   // stf_dataGridView
			   // 
			   this->stf_dataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->stf_dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->stf_dataGridView->Location = System::Drawing::Point(0, 369);
			   this->stf_dataGridView->Margin = System::Windows::Forms::Padding(2);
			   this->stf_dataGridView->Name = L"stf_dataGridView";
			   this->stf_dataGridView->RowHeadersWidth = 51;
			   this->stf_dataGridView->RowTemplate->Height = 27;
			   this->stf_dataGridView->Size = System::Drawing::Size(982, 275);
			   this->stf_dataGridView->TabIndex = 19;
			   this->stf_dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::stf_dataGridView_CellContentClick);
			   // 
			   // stf_lbl_Prompt_SearchResult
			   // 
			   this->stf_lbl_Prompt_SearchResult->AutoSize = true;
			   this->stf_lbl_Prompt_SearchResult->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->stf_lbl_Prompt_SearchResult->Font = (gcnew System::Drawing::Font(L"SimSun", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->stf_lbl_Prompt_SearchResult->Location = System::Drawing::Point(490, 327);
			   this->stf_lbl_Prompt_SearchResult->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_SearchResult->Name = L"stf_lbl_Prompt_SearchResult";
			   this->stf_lbl_Prompt_SearchResult->Size = System::Drawing::Size(89, 19);
			   this->stf_lbl_Prompt_SearchResult->TabIndex = 17;
			   this->stf_lbl_Prompt_SearchResult->Text = L"查询结果";
			   // 
			   // stf_lbl_Error
			   // 
			   this->stf_lbl_Error->AutoSize = true;
			   this->stf_lbl_Error->BackColor = System::Drawing::SystemColors::Control;
			   this->stf_lbl_Error->ForeColor = System::Drawing::Color::Red;
			   this->stf_lbl_Error->Location = System::Drawing::Point(519, 236);
			   this->stf_lbl_Error->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Error->Name = L"stf_lbl_Error";
			   this->stf_lbl_Error->Size = System::Drawing::Size(31, 13);
			   this->stf_lbl_Error->TabIndex = 16;
			   this->stf_lbl_Error->Text = L"错误";
			   // 
			   // stf_lbl_Count
			   // 
			   this->stf_lbl_Count->AutoSize = true;
			   this->stf_lbl_Count->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->stf_lbl_Count->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->stf_lbl_Count->Location = System::Drawing::Point(92, 335);
			   this->stf_lbl_Count->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Count->Name = L"stf_lbl_Count";
			   this->stf_lbl_Count->Size = System::Drawing::Size(15, 15);
			   this->stf_lbl_Count->TabIndex = 15;
			   this->stf_lbl_Count->Text = L"0";
			   // 
			   // stf_lbl_Prompt_Count
			   // 
			   this->stf_lbl_Prompt_Count->AutoSize = true;
			   this->stf_lbl_Prompt_Count->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->stf_lbl_Prompt_Count->Font = (gcnew System::Drawing::Font(L"SimSun", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->stf_lbl_Prompt_Count->Location = System::Drawing::Point(42, 335);
			   this->stf_lbl_Prompt_Count->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Count->Name = L"stf_lbl_Prompt_Count";
			   this->stf_lbl_Prompt_Count->Size = System::Drawing::Size(55, 15);
			   this->stf_lbl_Prompt_Count->TabIndex = 14;
			   this->stf_lbl_Prompt_Count->Text = L"总计：";
			   // 
			   // stf_btn_Add
			   // 
			   this->stf_btn_Add->Location = System::Drawing::Point(806, 181);
			   this->stf_btn_Add->Margin = System::Windows::Forms::Padding(2);
			   this->stf_btn_Add->Name = L"stf_btn_Add";
			   this->stf_btn_Add->Size = System::Drawing::Size(69, 28);
			   this->stf_btn_Add->TabIndex = 13;
			   this->stf_btn_Add->Text = L"添加";
			   this->stf_btn_Add->UseVisualStyleBackColor = true;
			   this->stf_btn_Add->Click += gcnew System::EventHandler(this, &MainWindow::stf_btn_Add_Click);
			   // 
			   // stf_btn_Clear
			   // 
			   this->stf_btn_Clear->Location = System::Drawing::Point(806, 111);
			   this->stf_btn_Clear->Margin = System::Windows::Forms::Padding(2);
			   this->stf_btn_Clear->Name = L"stf_btn_Clear";
			   this->stf_btn_Clear->Size = System::Drawing::Size(70, 28);
			   this->stf_btn_Clear->TabIndex = 12;
			   this->stf_btn_Clear->Text = L"清空";
			   this->stf_btn_Clear->UseVisualStyleBackColor = true;
			   this->stf_btn_Clear->Click += gcnew System::EventHandler(this, &MainWindow::stf_btn_Clear_Click);
			   // 
			   // stf_btn_Search
			   // 
			   this->stf_btn_Search->Location = System::Drawing::Point(806, 43);
			   this->stf_btn_Search->Margin = System::Windows::Forms::Padding(2);
			   this->stf_btn_Search->Name = L"stf_btn_Search";
			   this->stf_btn_Search->Size = System::Drawing::Size(70, 28);
			   this->stf_btn_Search->TabIndex = 11;
			   this->stf_btn_Search->Text = L"查询";
			   this->stf_btn_Search->UseVisualStyleBackColor = true;
			   this->stf_btn_Search->Click += gcnew System::EventHandler(this, &MainWindow::stf_btn_Search_Click);
			   // 
			   // stf_cmb_Auth
			   // 
			   this->stf_cmb_Auth->FormattingEnabled = true;
			   this->stf_cmb_Auth->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				   L"Level-1", L"Level-2", L"Level-3", L"Level-4",
					   L"Level-5"
			   });
			   this->stf_cmb_Auth->Location = System::Drawing::Point(482, 117);
			   this->stf_cmb_Auth->Margin = System::Windows::Forms::Padding(2);
			   this->stf_cmb_Auth->Name = L"stf_cmb_Auth";
			   this->stf_cmb_Auth->Size = System::Drawing::Size(92, 21);
			   this->stf_cmb_Auth->TabIndex = 10;
			   // 
			   // stf_cmb_Dept
			   // 
			   this->stf_cmb_Dept->FormattingEnabled = true;
			   this->stf_cmb_Dept->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				   L"General Administration", L"Information Technology Support",
					   L"Career Development Support"
			   });
			   this->stf_cmb_Dept->Location = System::Drawing::Point(120, 117);
			   this->stf_cmb_Dept->Margin = System::Windows::Forms::Padding(2);
			   this->stf_cmb_Dept->Name = L"stf_cmb_Dept";
			   this->stf_cmb_Dept->Size = System::Drawing::Size(230, 21);
			   this->stf_cmb_Dept->TabIndex = 9;
			   // 
			   // stf_txt_Name
			   // 
			   this->stf_txt_Name->Location = System::Drawing::Point(482, 47);
			   this->stf_txt_Name->Margin = System::Windows::Forms::Padding(2);
			   this->stf_txt_Name->Name = L"stf_txt_Name";
			   this->stf_txt_Name->Size = System::Drawing::Size(92, 20);
			   this->stf_txt_Name->TabIndex = 8;
			   // 
			   // stf_txt_Id
			   // 
			   this->stf_txt_Id->Location = System::Drawing::Point(120, 46);
			   this->stf_txt_Id->Margin = System::Windows::Forms::Padding(2);
			   this->stf_txt_Id->Name = L"stf_txt_Id";
			   this->stf_txt_Id->Size = System::Drawing::Size(92, 20);
			   this->stf_txt_Id->TabIndex = 7;
			   // 
			   // stf_lbl_Prompt_Auth
			   // 
			   this->stf_lbl_Prompt_Auth->AutoSize = true;
			   this->stf_lbl_Prompt_Auth->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->stf_lbl_Prompt_Auth->Location = System::Drawing::Point(391, 119);
			   this->stf_lbl_Prompt_Auth->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Auth->Name = L"stf_lbl_Prompt_Auth";
			   this->stf_lbl_Prompt_Auth->Size = System::Drawing::Size(76, 16);
			   this->stf_lbl_Prompt_Auth->TabIndex = 6;
			   this->stf_lbl_Prompt_Auth->Text = L"权限等级";
			   // 
			   // stf_lbl_Prompt_Dept
			   // 
			   this->stf_lbl_Prompt_Dept->AutoSize = true;
			   this->stf_lbl_Prompt_Dept->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->stf_lbl_Prompt_Dept->Location = System::Drawing::Point(35, 116);
			   this->stf_lbl_Prompt_Dept->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Dept->Name = L"stf_lbl_Prompt_Dept";
			   this->stf_lbl_Prompt_Dept->Size = System::Drawing::Size(76, 16);
			   this->stf_lbl_Prompt_Dept->TabIndex = 5;
			   this->stf_lbl_Prompt_Dept->Text = L"所在部门";
			   // 
			   // stf_lbl_Prompt_Name
			   // 
			   this->stf_lbl_Prompt_Name->AutoSize = true;
			   this->stf_lbl_Prompt_Name->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->stf_lbl_Prompt_Name->Location = System::Drawing::Point(422, 50);
			   this->stf_lbl_Prompt_Name->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Name->Name = L"stf_lbl_Prompt_Name";
			   this->stf_lbl_Prompt_Name->Size = System::Drawing::Size(42, 16);
			   this->stf_lbl_Prompt_Name->TabIndex = 4;
			   this->stf_lbl_Prompt_Name->Text = L"姓名";
			   // 
			   // stf_lbl_Prompt_Id
			   // 
			   this->stf_lbl_Prompt_Id->AutoSize = true;
			   this->stf_lbl_Prompt_Id->Font = (gcnew System::Drawing::Font(L"SimSun", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(134)));
			   this->stf_lbl_Prompt_Id->Location = System::Drawing::Point(82, 50);
			   this->stf_lbl_Prompt_Id->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->stf_lbl_Prompt_Id->Name = L"stf_lbl_Prompt_Id";
			   this->stf_lbl_Prompt_Id->Size = System::Drawing::Size(26, 16);
			   this->stf_lbl_Prompt_Id->TabIndex = 3;
			   this->stf_lbl_Prompt_Id->Text = L"Id";
			   // 
			   // splitter5
			   // 
			   this->splitter5->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->splitter5->Dock = System::Windows::Forms::DockStyle::Top;
			   this->splitter5->Location = System::Drawing::Point(0, 310);
			   this->splitter5->Margin = System::Windows::Forms::Padding(2);
			   this->splitter5->Name = L"splitter5";
			   this->splitter5->Size = System::Drawing::Size(982, 518);
			   this->splitter5->TabIndex = 2;
			   this->splitter5->TabStop = false;
			   // 
			   // splitter4
			   // 
			   this->splitter4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->splitter4->Dock = System::Windows::Forms::DockStyle::Top;
			   this->splitter4->Location = System::Drawing::Point(0, 269);
			   this->splitter4->Margin = System::Windows::Forms::Padding(2);
			   this->splitter4->Name = L"splitter4";
			   this->splitter4->Size = System::Drawing::Size(982, 41);
			   this->splitter4->TabIndex = 1;
			   this->splitter4->TabStop = false;
			   // 
			   // splitter3
			   // 
			   this->splitter3->BackColor = System::Drawing::SystemColors::Control;
			   this->splitter3->Dock = System::Windows::Forms::DockStyle::Top;
			   this->splitter3->Location = System::Drawing::Point(0, 0);
			   this->splitter3->Margin = System::Windows::Forms::Padding(2);
			   this->splitter3->Name = L"splitter3";
			   this->splitter3->Size = System::Drawing::Size(982, 269);
			   this->splitter3->TabIndex = 0;
			   this->splitter3->TabStop = false;
			   // 
			   // pan_treasury
			   // 
			   this->pan_treasury->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_treasury->Location = System::Drawing::Point(0, 0);
			   this->pan_treasury->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_treasury->Name = L"pan_treasury";
			   this->pan_treasury->Size = System::Drawing::Size(982, 636);
			   this->pan_treasury->TabIndex = 1;
			   // 
			   // pan_myInfo
			   // 
			   this->pan_myInfo->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->pan_myInfo->Location = System::Drawing::Point(0, 0);
			   this->pan_myInfo->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			   this->pan_myInfo->Name = L"pan_myInfo";
			   this->pan_myInfo->Size = System::Drawing::Size(982, 636);
			   this->pan_myInfo->TabIndex = 0;
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
			   this->ms_panelOptions->Size = System::Drawing::Size(150, 636);
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
			   this->tsm_system->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tmsi_ChangeUserInfo });
			   this->tsm_system->Name = L"tsm_system";
			   this->tsm_system->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
			   this->tsm_system->Size = System::Drawing::Size(103, 21);
			   this->tsm_system->Text = L"System";
			   // 
			   // tmsi_ChangeUserInfo
			   // 
			   this->tmsi_ChangeUserInfo->Name = L"tmsi_ChangeUserInfo";
			   this->tmsi_ChangeUserInfo->Size = System::Drawing::Size(124, 22);
			   this->tmsi_ChangeUserInfo->Text = L"更改密码";
			   this->tmsi_ChangeUserInfo->Click += gcnew System::EventHandler(this, &MainWindow::tmsi_ChangeUserInfo_Click);
			   // 
			   // tsm_database
			   // 
			   this->tsm_database->Name = L"tsm_database";
			   this->tsm_database->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
			   this->tsm_database->Size = System::Drawing::Size(117, 21);
			   this->tsm_database->Text = L"Database";
			   // 
			   // tsm_help
			   // 
			   this->tsm_help->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->tsmi_VersionInfo });
			   this->tsm_help->Name = L"tsm_help";
			   this->tsm_help->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
			   this->tsm_help->Size = System::Drawing::Size(89, 21);
			   this->tsm_help->Text = L"Help";
			   // 
			   // tsmi_VersionInfo
			   // 
			   this->tsmi_VersionInfo->Name = L"tsmi_VersionInfo";
			   this->tsmi_VersionInfo->Size = System::Drawing::Size(124, 22);
			   this->tsmi_VersionInfo->Text = L"版本信息";
			   this->tsmi_VersionInfo->Click += gcnew System::EventHandler(this, &MainWindow::tsmi_VersionInfo_Click);
			   // 
			   // MainWindow
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1132, 661);
			   this->Controls->Add(this->toolStripContainer1);
			   this->MainMenuStrip = this->ms_systemOptions;
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->MinimumSize = System::Drawing::Size(1128, 694);
			   this->Name = L"MainWindow";
			   this->Text = L"MainWindow";
			   this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			   this->toolStripContainer1->LeftToolStripPanel->ResumeLayout(false);
			   this->toolStripContainer1->LeftToolStripPanel->PerformLayout();
			   this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			   this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			   this->toolStripContainer1->ResumeLayout(false);
			   this->toolStripContainer1->PerformLayout();
			   this->pan_OPT->ResumeLayout(false);
			   this->pan_OPT->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OPT_dataGridView))->EndInit();
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->pan_record->ResumeLayout(false);
			   this->rec_panel3->ResumeLayout(false);
			   this->rec_panel3->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Rec_dataGridView))->EndInit();
			   this->rec_panel1->ResumeLayout(false);
			   this->rec_panel1->PerformLayout();
			   this->rec_panel2->ResumeLayout(false);
			   this->rec_panel2->PerformLayout();
			   this->pan_order->ResumeLayout(false);
			   this->ord_panel3->ResumeLayout(false);
			   this->ord_panel3->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ord_dataGridView))->EndInit();
			   this->ord_panel2->ResumeLayout(false);
			   this->ord_panel2->PerformLayout();
			   this->ord_panel1->ResumeLayout(false);
			   this->ord_panel1->PerformLayout();
			   this->pan_member->ResumeLayout(false);
			   this->mem_panel4->ResumeLayout(false);
			   this->mem_panel4->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mem_dataGridView1))->EndInit();
			   this->mem_panel3->ResumeLayout(false);
			   this->mem_panel3->PerformLayout();
			   this->mem_panel1->ResumeLayout(false);
			   this->mem_panel1->PerformLayout();
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
		Void ord_CheckAuth();
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
		Void WeAlumni::MainWindow::Rec_CheckAuth();
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
		Void OPT_CheckAuth();
	private: System::Void lbl_Prompt_MemName_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   /*
			*  System
			*/
		   Void tmsi_ChangeUserInfo_Click(System::Object^ sender, System::EventArgs^ e);
		   Void tsmi_VersionInfo_Click(System::Object^ sender, System::EventArgs^ e);

};
}