#include "MainWindow.h"
#include <vector>
/*
 * MainWindow.h
 *
 * This file implements all sub-functions required in the MainWindow.
 *
 * @author: Hang Yuan
 * Revised: 3/27/20
 *          4/8/20 add member MainWindow functions
 *          4/12/20 add staff MainWindow and auth control for staff and member
 *
 */

using namespace System;

/*
 * SetAllPanelInvisible
 * This method will change all property Visible of all panels into false
 * @param None
 * @return None
 */
void WeAlumni::MainWindow::SetAllPanelInvisible() {
    pan_member->Visible = false;
    pan_staff->Visible = false;
    pan_record->Visible = false;
    pan_OPT->Visible = false;
    pan_order->Visible = false;
    pan_treasury->Visible = false;
    pan_myInfo->Visible = false;
}

/*
* Initialize
* This method will try to initialize database.
* @param none
* @return none
*/
Void WeAlumni::MainWindow::Initialize() {
    try {
        database = gcnew Database(Database::DatabaseType::Data);
    }
    catch (System::Exception^ exception) {
        mem_lbl_error->Text = exception->Message;
        mem_lbl_error->ForeColor = System::Drawing::Color::Red;
    }
    stf_CheckAuth();
    mem_CheckAuth();
}
/*
 *  Member
 */
/*
* mem_btn_Search_Click
*
* This method will try to search from Record table for the record of this member.
* Then update record to DataGridView1
*/
Void WeAlumni::MainWindow::mem_btn_Search_Click(System::Object^ sender, System::EventArgs^ e) {
    BindingSource^ bSource = gcnew BindingSource();
    String^ id = mem_txt_Id->Text;
    String^ status = mem_cmb_Status->Text;
    String^ type = mem_cmb_Type->Text;
    String^ name = mem_txt_Name->Text;
    String^ gender = mem_txt_Gender->Text;
    String^ careerStatus = mem_cmb_CareerStatus->Text;
    String^ major = mem_txt_Major->Text;
    String^ searchAuth = mem_cmb_SearchAuth->Text;
    String^ cmd = "SELECT Member.Id AS 'MemberId', Member.Status AS 'MemberStatus'," +
        " Member.Type AS 'MemberType'," + " Member.Name AS 'MemberName'," +
        " Member.Gender AS 'MemberGender'," + "Member.Email AS 'MemberEmail'" +
        "FROM Member WHERE ";
    String^ cmd2 = "";

    std::vector<int> vec;
    if (id->Length)           vec.push_back(0);
    if (status->Length)       vec.push_back(1);
    if (type->Length)         vec.push_back(2);
    if (name->Length)         vec.push_back(3);
    if (gender->Length)       vec.push_back(4);
    if (careerStatus->Length) vec.push_back(5);
    if (major->Length)        vec.push_back(6);
    if (searchAuth->Length)   vec.push_back(7);
    if (vec.size() == 0) {
        mem_dataGridView1->DataSource = nullptr;
        mem_lbl_error->Visible = true;
        mem_lbl_error->Text = "CANNOT FIND MEMBER";
        return;
    }

    bool flag = false;
    for (auto i : vec) {
        if (vec.size() != 1 && flag) cmd2 += " AND ";
        switch (i) {
        case 0: cmd2 += "Member.Id = " + Convert::ToInt32(id); break;
        case 1: cmd2 += "Member.Status = '" + status + "' "; break;
        case 2: cmd2 += "Member.Type = '" + type + "' "; break;
        case 3: cmd2 += "Member.Name = '" + name + "' "; break;
        case 4: cmd2 += "Member.Gender = '" + gender + "' "; break;
        case 5: cmd2 += "Member.CareerStatus = '" + careerStatus + "' "; break;
        case 6: cmd2 += "Member.Major1 = '" + major + "' " +
            "OR Member.Major2 = '" + major + "' "; break;
        case 7: cmd2 += "Member.SearchAuth = '" + searchAuth + "' "; break;
        }
        flag = true;
    }
    cmd += cmd2 + " ORDER BY Member.Id ASC;";

    int status1 = -1;

    try {
        status1 = database->ReadDataAdapter(cmd);
    }
    catch (Exception^ exception) {
        mem_lbl_error->ForeColor = System::Drawing::Color::Red;
        mem_lbl_error->Text = exception->Message;
        mem_lbl_error->Visible = true;
        return;
    }

    if (status1 > 0) {
        mem_lbl_error->Visible = false;
        bSource->DataSource = database->dataTable;
        mem_dataGridView1->DataSource = bSource;
    }
    else {
        mem_lbl_error->Visible = true;
        mem_lbl_error->ForeColor = System::Drawing::Color::Red;
        mem_lbl_error->Text = "CANNOT FIND MEMBER";
    }
}

/*
* mem_btn_Clear_Click
*
* When click button "Clear", this method clear up every TextBox or ComboBox of the search engine and UpdateDataGridView.
*/
Void WeAlumni::MainWindow::mem_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    mem_dataGridView1->DataSource = nullptr;
    mem_txt_Id->Text = "";
    mem_txt_Gender->Text = "";
    mem_txt_Major->Text = "";
    mem_txt_Name->Text = "";
    mem_cmb_CareerStatus->Text = "";
    mem_cmb_SearchAuth->Text = "";
    mem_cmb_Status->Text = "";
    mem_cmb_Type->Text = "";
    mem_dataGridView1->DataSource = nullptr;
}

/*
* mem_btn_Add_Click
*
* When click button "Add", a new window MemAddPage will be called up.
*/
Void WeAlumni::MainWindow::mem_btn_Add_Click(System::Object^ sender, System::EventArgs^ e) {
    MemAddPage^ map = gcnew MemAddPage();
    map->ShowDialog();
    mem_dataGridView1->DataSource = nullptr;
}

/*
 * mem_dataGridView1_CellDoubleClick
 * by double clicking specific row of mem_dataGridView1, a corresponding Record Info page will show up.
 */
Void WeAlumni::MainWindow::mem_dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    MemInfoPage^ mip = gcnew MemInfoPage(Convert::ToInt32(mem_dataGridView1->CurrentRow->Cells[0]->Value), _pui);
    mip->ShowDialog();
}

Void WeAlumni::MainWindow::mem_CheckAuth() {
    if (_Auth == PublicUserInfo::Auth::Level_1) {
        tsm_member->Visible = false;
        pan_member->Visible = false;
    }
    else if (_Auth == PublicUserInfo::Auth::Level_2) {
        mem_btn_Add->Visible = false;
        mem_btn_Import->Visible = false;
    }
}

Void WeAlumni::MainWindow::mem_btn_Import_Click(System::Object^ sender, System::EventArgs^ e) {

}

/*
 *  Staff
 */

 /*
  * stf_CheckAuth()
  * Check staff Auth. If Level < 3, user can't add/import information.
  * @param None
  * @return None
  */
Void WeAlumni::MainWindow::stf_CheckAuth() {
    if (_Auth == PublicUserInfo::Auth::Level_1 || _Auth == PublicUserInfo::Auth::Level_2) {
        stf_btn_Add->Enabled = false;
        stf_btn_Import->Enabled = false;
    }
}

/*
 * stf_btn_Search_Click()
 * This method will try to search from Member table and Staff table of this member.
 * Then update record to stf_dataGridView
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::stf_btn_Search_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ Id = stf_txt_Id->Text;
    String^ Name = stf_txt_Name->Text;
    String^ Dept = stf_cmb_Dept->Text;
    String^ Auth = stf_cmb_Auth->Text;
    String^ command = "SELECT Staff.MemId    AS 'ID', " +
        "Member.Name    As 'Name', " +
        "Member.Gender  AS 'Gender', " +
        "Member.Email   AS 'Email', " +
        "Staff.Dept     As 'Department', " +
        "Staff.Position As 'Position', " +
        "Staff.Auth     As 'Auth' " +
        "FROM   Member, Staff " +
        "WHERE Staff.MemId = Member.Id AND ";
    BindingSource^ bSource = gcnew BindingSource();
    String^ cmd2 = "";

    std::vector<int> vec;
    if (Id->Length)           vec.push_back(0);
    if (Name->Length)         vec.push_back(1);
    if (Dept->Length)         vec.push_back(2);
    if (Auth->Length)         vec.push_back(3);
    if (vec.size() == 0) {
        stf_dataGridView->DataSource = nullptr;
        stf_lbl_Error->Visible = true;
        stf_lbl_Error->Text = "CANNOT FIND MEMBER";
        return;
    }

    bool flag = false;
    for (auto i : vec) {
        if (vec.size() != 1 && flag) cmd2 += " AND ";
        switch (i) {
        case 0: cmd2 += "Staff.MemId = " + Convert::ToInt32(Id); break;
        case 1: cmd2 += "Member.Name = '" + Name + "' "; break;
        case 2: cmd2 += "Staff.Dept = '" + Dept + "' "; break;
        case 3: cmd2 += "Staff.Auth = '" + Auth + "' "; break;
        }
        flag = true;
    }
    command += cmd2 + " ORDER BY Staff.MemId ASC;";

    int status = -1;
    try {
        status = database->ReadDataAdapter(command);
    }
    catch (Exception^ exception) {
        stf_lbl_Error->Text = exception->Message;
        stf_lbl_Error->Visible = true;
        return;
    }

    if (status > 0) {
        stf_lbl_Error->Visible = false;
        bSource->DataSource = database->dataTable;
        stf_dataGridView->DataSource = bSource;
    }
    else {
        stf_lbl_Error->Visible = true;
        stf_lbl_Error->Text = "CANNOT FIND MEMBER";
    }
}

/*
 * stf_btn_Add_Click
 * When click button "Add", a new window StfAddPage will be called up.
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::stf_btn_Add_Click(System::Object^ sender, System::EventArgs^ e) {
    StfAddPage^ add = gcnew StfAddPage();
    add->ShowDialog();
    stf_dataGridView->DataSource = nullptr;
}

/*
 * stf_btn_Clear_Click
 * When click button "Clear", this method clear up every TextBox or ComboBox of the search engine and UpdateDataGridView.
 * @param None
 * @return None
 */
Void WeAlumni::MainWindow::stf_btn_Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    stf_dataGridView->DataSource = nullptr;
    stf_txt_Id->Text = "";
    stf_txt_Name->Text = "";
    stf_cmb_Dept->Text = "";
    stf_cmb_Auth->Text = "";
}

/*
 * stf_dataGridView_CellContentClick
 * by double clicking specific row of stf_dataGridView, a corresponding Record Info page will show up.
 */
Void WeAlumni::MainWindow::stf_dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    StfInfoPage^ mip = gcnew StfInfoPage(Convert::ToInt32(stf_dataGridView->CurrentRow->Cells[0]->Value), _pui);
    mip->ShowDialog();
}

Void WeAlumni::MainWindow::stf_btn_Import_Click(System::Object^ sender, System::EventArgs^ e) {

}