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
}
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
    MemInfoPage^ mip = gcnew MemInfoPage(Convert::ToInt32(mem_dataGridView1->CurrentRow->Cells[0]->Value));
    mip->ShowDialog();
}

Void WeAlumni::MainWindow::mem_btn_Import_Click(System::Object^ sender, System::EventArgs^ e) {

}