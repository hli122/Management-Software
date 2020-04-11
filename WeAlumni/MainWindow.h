#pragma once
#include "MemInfoPage.h"
#include "Database.h"
#include "MemAddPage.h"

/*
 * MainWindow.h
 *
 * This file initializes the MainWindow's UI and declares the sub-functions required.
 *
 * @author: Hang Yuan
 * Revised: 3/27/20
 *          4/8/20 add member MainWindow
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
	private: System::Windows::Forms::Panel^ pan_member;
	private: System::Windows::Forms::Panel^ pan_staff;
	private: System::Windows::Forms::Panel^ pan_record;
	private: System::Windows::Forms::Panel^ pan_OPT;
	private: System::Windows::Forms::Panel^ pan_order;
	private: System::Windows::Forms::Panel^ pan_treasury;
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
	private: System::Windows::Forms::ComboBox^ mem_cmb_SearchAuth;
	private: System::Windows::Forms::ComboBox^ mem_cmb_Type;
	private: System::Windows::Forms::ComboBox^ mem_cmb_Status;
	private: System::Windows::Forms::DataGridView^ mem_dataGridView1;
	private: System::Windows::Forms::Button^ mem_btn_Import;
	private: System::Windows::Forms::Button^ mem_btn_Add;
	private: System::Windows::Forms::Button^ mem_btn_Clear;
	private: System::Windows::Forms::Button^ mem_btn_Search;
	private: System::Windows::Forms::ComboBox^ mem_cmb_CareerStatus;
	private: System::Windows::Forms::Label^ mem_lbl_error;
	private: System::Windows::Forms::Panel^ pan_myInfo;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
		this->pan_member = (gcnew System::Windows::Forms::Panel());
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
		this->pan_staff = (gcnew System::Windows::Forms::Panel());
		this->pan_record = (gcnew System::Windows::Forms::Panel());
		this->pan_OPT = (gcnew System::Windows::Forms::Panel());
		this->pan_order = (gcnew System::Windows::Forms::Panel());
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
		this->tsm_database = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->tsm_help = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripContainer1->ContentPanel->SuspendLayout();
		this->toolStripContainer1->LeftToolStripPanel->SuspendLayout();
		this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
		this->toolStripContainer1->SuspendLayout();
		this->pan_member->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mem_dataGridView1))->BeginInit();
		this->ms_panelOptions->SuspendLayout();
		this->ms_systemOptions->SuspendLayout();
		this->SuspendLayout();
		// 
		// toolStripContainer1
		// 
		// 
		// toolStripContainer1.ContentPanel
		// 
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_member);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_staff);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_record);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_OPT);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_order);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_treasury);
		this->toolStripContainer1->ContentPanel->Controls->Add(this->pan_myInfo);
		this->toolStripContainer1->ContentPanel->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(982, 636);
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
		// pan_member
		// 
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
		this->pan_member->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_member->Location = System::Drawing::Point(0, 0);
		this->pan_member->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->pan_member->Name = L"pan_member";
		this->pan_member->Size = System::Drawing::Size(982, 636);
		this->pan_member->TabIndex = 6;
		// 
		// mem_lbl_error
		// 
		this->mem_lbl_error->AutoSize = true;
		this->mem_lbl_error->ForeColor = System::Drawing::Color::Red;
		this->mem_lbl_error->Location = System::Drawing::Point(46, 251);
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
		this->mem_dataGridView1->Location = System::Drawing::Point(0, 267);
		this->mem_dataGridView1->Name = L"mem_dataGridView1";
		this->mem_dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
		this->mem_dataGridView1->Size = System::Drawing::Size(979, 317);
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
		this->mem_txt_Id->Location = System::Drawing::Point(64, 55);
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
		// pan_staff
		// 
		this->pan_staff->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_staff->Location = System::Drawing::Point(0, 0);
		this->pan_staff->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->pan_staff->Name = L"pan_staff";
		this->pan_staff->Size = System::Drawing::Size(982, 636);
		this->pan_staff->TabIndex = 5;
		// 
		// pan_record
		// 
		this->pan_record->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_record->Location = System::Drawing::Point(0, 0);
		this->pan_record->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->pan_record->Name = L"pan_record";
		this->pan_record->Size = System::Drawing::Size(982, 636);
		this->pan_record->TabIndex = 4;
		// 
		// pan_OPT
		// 
		this->pan_OPT->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_OPT->Location = System::Drawing::Point(0, 0);
		this->pan_OPT->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->pan_OPT->Name = L"pan_OPT";
		this->pan_OPT->Size = System::Drawing::Size(982, 636);
		this->pan_OPT->TabIndex = 3;
		// 
		// pan_order
		// 
		this->pan_order->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_order->Location = System::Drawing::Point(0, 0);
		this->pan_order->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->pan_order->Name = L"pan_order";
		this->pan_order->Size = System::Drawing::Size(982, 636);
		this->pan_order->TabIndex = 2;
		// 
		// pan_treasury
		// 
		this->pan_treasury->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_treasury->Location = System::Drawing::Point(0, 0);
		this->pan_treasury->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
		this->pan_treasury->Name = L"pan_treasury";
		this->pan_treasury->Size = System::Drawing::Size(982, 636);
		this->pan_treasury->TabIndex = 1;
		// 
		// pan_myInfo
		// 
		this->pan_myInfo->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pan_myInfo->Location = System::Drawing::Point(0, 0);
		this->pan_myInfo->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
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
		this->tsm_member->Size = System::Drawing::Size(143, 69);
		this->tsm_member->Text = L"Member";
		this->tsm_member->Click += gcnew System::EventHandler(this, &MainWindow::tsm_member_Click);
		// 
		// tsm_staff
		// 
		this->tsm_staff->Name = L"tsm_staff";
		this->tsm_staff->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
		this->tsm_staff->Size = System::Drawing::Size(143, 69);
		this->tsm_staff->Text = L"Staff";
		this->tsm_staff->Click += gcnew System::EventHandler(this, &MainWindow::tsm_staff_Click);
		// 
		// tsm_record
		// 
		this->tsm_record->Name = L"tsm_record";
		this->tsm_record->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
		this->tsm_record->Size = System::Drawing::Size(143, 69);
		this->tsm_record->Text = L"Record";
		this->tsm_record->Click += gcnew System::EventHandler(this, &MainWindow::tsm_record_Click);
		// 
		// tsm_OPT
		// 
		this->tsm_OPT->Name = L"tsm_OPT";
		this->tsm_OPT->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
		this->tsm_OPT->Size = System::Drawing::Size(143, 69);
		this->tsm_OPT->Text = L"OPT";
		this->tsm_OPT->Click += gcnew System::EventHandler(this, &MainWindow::tsm_OPT_Click);
		// 
		// tsm_order
		// 
		this->tsm_order->Name = L"tsm_order";
		this->tsm_order->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
		this->tsm_order->Size = System::Drawing::Size(143, 69);
		this->tsm_order->Text = L"Order";
		this->tsm_order->Click += gcnew System::EventHandler(this, &MainWindow::tsm_myInfo_Click);
		// 
		// tsm_treasury
		// 
		this->tsm_treasury->Name = L"tsm_treasury";
		this->tsm_treasury->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
		this->tsm_treasury->Size = System::Drawing::Size(143, 69);
		this->tsm_treasury->Text = L"Treasury";
		// 
		// tsm_myInfo
		// 
		this->tsm_myInfo->Name = L"tsm_myInfo";
		this->tsm_myInfo->Padding = System::Windows::Forms::Padding(5, 25, 5, 25);
		this->tsm_myInfo->Size = System::Drawing::Size(143, 69);
		this->tsm_myInfo->Text = L"My Info";
		// 
		// ms_systemOptions
		// 
		this->ms_systemOptions->Dock = System::Windows::Forms::DockStyle::None;
		this->ms_systemOptions->ImageScalingSize = System::Drawing::Size(20, 20);
		this->ms_systemOptions->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
			this->tsm_system,
				this->tsm_database, this->tsm_help
		});
		this->ms_systemOptions->Location = System::Drawing::Point(0, 0);
		this->ms_systemOptions->Name = L"ms_systemOptions";
		this->ms_systemOptions->Size = System::Drawing::Size(1132, 24);
		this->ms_systemOptions->TabIndex = 0;
		this->ms_systemOptions->Text = L"menuStrip1";
		// 
		// tsm_system
		// 
		this->tsm_system->Name = L"tsm_system";
		this->tsm_system->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
		this->tsm_system->Size = System::Drawing::Size(99, 20);
		this->tsm_system->Text = L"System";
		// 
		// tsm_database
		// 
		this->tsm_database->Name = L"tsm_database";
		this->tsm_database->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
		this->tsm_database->Size = System::Drawing::Size(109, 20);
		this->tsm_database->Text = L"Database";
		// 
		// tsm_help
		// 
		this->tsm_help->Name = L"tsm_help";
		this->tsm_help->Padding = System::Windows::Forms::Padding(25, 0, 25, 0);
		this->tsm_help->Size = System::Drawing::Size(86, 20);
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
		this->MinimumSize = System::Drawing::Size(1129, 699);
		this->Name = L"MainWindow";
		this->Text = L"MainWindow";
		this->toolStripContainer1->ContentPanel->ResumeLayout(false);
		this->toolStripContainer1->LeftToolStripPanel->ResumeLayout(false);
		this->toolStripContainer1->LeftToolStripPanel->PerformLayout();
		this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
		this->toolStripContainer1->TopToolStripPanel->PerformLayout();
		this->toolStripContainer1->ResumeLayout(false);
		this->toolStripContainer1->PerformLayout();
		this->pan_member->ResumeLayout(false);
		this->pan_member->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mem_dataGridView1))->EndInit();
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
	
	/*
		MemberMainWindow
	*/
	private:
		Database^ database;
		Void Initialize();
		Void mem_btn_Search_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_btn_Add_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_btn_Import_Click(System::Object^ sender, System::EventArgs^ e);
		Void mem_dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
};
}
