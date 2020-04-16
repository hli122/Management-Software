#include "StfInfoPage.h"

/*
 * StfInfoPage.cpp
 *
 * This file implements all StfInfoPage interfaces.
 *
 * @author: Rui Jia
 * Revised: 4/12/20
 *          4/15/20 add DeleteRecord();
 *
 */

using namespace System;

/*
 * Initialize()
 * Pre-initialize all staff's info
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::Initialize() {
    try {
        _database = gcnew Database(Database::DatabaseType::Data);
    }
    catch (System::Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }
    UpdateInfo();
    CheckAuth();
}

/*
 * CheckAuth()
 * Check User Auth.
 * Level 1 & Level 2: PR
 * Level 3: PR/W
 * Level 4 & Level 5: F
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::CheckAuth() {
    if (_Auth == PublicUserInfo::Auth::Level_1 || _Auth == PublicUserInfo::Auth::Level_2 || _Auth == PublicUserInfo::Auth::Level_3) {
        AuthInvisible();
    }
    if (_Auth == PublicUserInfo::Auth::Level_3) {
        btn_ChangeInfo->Visible = true;
        btn_DeleteInfo->Visible = true;
    }
}

/*
 * AuthInvisible()
 * Set part of information invisible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::AuthInvisible() {
    lbl_Prompt_Gender->Visible = false;
    lbl_Gender->Visible = false;
    lbl_Prompt_Birth->Visible = false;
    lbl_Birth->Visible = false;
    lbl_Prompt_Phone->Visible = false;
    lbl_Phone->Visible = false;
    lbl_Prompt_Wechat->Visible = false;
    lbl_Wechat->Visible = false;
    lbl_Prompt_StfId->Visible = false;
    lbl_StfId->Visible = false;
    btn_ChangeInfo->Visible = false;
    btn_DeleteInfo->Visible = false;
}

/*
 * UpdateInfo()
 * This method read from Staff table for the info of this Staff.
 * Then update info to according labels.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::UpdateInfo() {
    lbl_Error->Visible = false;
    lbl_Error_Data->Visible = false;

    int status = -1;
    String^ cmd = "SELECT * FROM Staff WHERE MemId = '" + _MemId + "';";
    try {
        status = _database->ReadData(cmd);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }

    if (status > 0) {
        lbl_StfId->Text = _StfId.ToString();
        lbl_MemId->Text = _database->dataReader->GetInt32(0).ToString();
        lbl_Dept->Text = _database->dataReader->GetString(1);
        lbl_Posi->Text = _database->dataReader->GetString(2);
        lbl_Auth->Text = _database->dataReader->GetString(3);

        cmb_Dept->Text = lbl_Dept->Text;
        cmb_Posi->Text = lbl_Posi->Text;
        cmb_Auth->Text = lbl_Auth->Text;
    }
    else {
        lbl_Error->Text = "Can't find the data";
        lbl_Error->Visible = true;
        btn_ChangeInfo->Enabled = false;
        btn_DeleteInfo->Enabled = false;
    }

    int status2 = -1;
    String^ cmd2 = "SELECT * FROM Member WHERE Id = '" + _MemId + "';";
    try {
        status2 = _database->ReadData(cmd2);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }

    if (status > 0 && status2 > 0) {
        lbl_Name->Text = _database->dataReader->GetString(3);
        lbl_Gender->Text = _database->dataReader->GetString(4);
        lbl_Birth->Text = _database->dataReader->GetString(5);
        lbl_Email->Text = _database->dataReader->GetString(6);
        lbl_Phone->Text = _database->dataReader->GetString(7);
        lbl_Wechat->Text = _database->dataReader->GetString(8);
        UpdateDataGridView();
    }
    else {
        lbl_Error->Text = "Can't find the data";
        lbl_Error->Visible = true;
        btn_ChangeInfo->Enabled = false;
        btn_DeleteInfo->Enabled = false;
    }
}

/*
 * ChangeTxtVisible()
 * Set all comboboxs visible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::ChangeTxtVisible() {
    cmb_Dept->Visible = true;
    cmb_Posi->Visible = true;
    cmb_Auth->Visible = true;
}

/*
 * ChangeTxtInVisible()
 * Set all comboboxs invisible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::ChangeTxtInvisible() {
    cmb_Dept->Visible = false;
    cmb_Posi->Visible = false;
    cmb_Auth->Visible = false;
}

/*
 * ChangeLabelVisible()
 * Set all labels visible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::ChangeLabelVisible() {
    lbl_Dept->Visible = true;
    lbl_Posi->Visible = true;
    lbl_Auth->Visible = true;
}

/*
 * ChangeTxtVisible()
 * Set all labels invisible.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::ChangeLabelInvisible() {
    lbl_Dept->Visible = false;
    lbl_Posi->Visible = false;
    lbl_Auth->Visible = false;
}

/*
 * btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Edit Information", multiple TextBoxes will be visible to collect changed info.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    lbl_Error->Visible = false;
    ChangeTxtVisible();
    ChangeLabelInvisible();
    btn_Accpet->Visible = true;
    btn_Cancle->Visible = true;
    btn_DeleteInfo->Enabled = false;
}

/*
 * btn_Accpet_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Accept", this method will trigger a Database update execution.
 * If exception occurs, an error message will be shown.
 * Then set all TextBoxes and two buttons to invisible.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_Accpet_Click(System::Object^ sender, System::EventArgs^ e) {
    int status = -1;
    String^ command = "UPDATE Staff " +
        "SET    Dept = '" + cmb_Dept->Text + "', " +
        "Position = '" + cmb_Posi->Text + "', " +
        "Auth = '" + cmb_Auth->Text + "' " +
        "WHERE  MemId = '" + _MemId + "';";
    try {
        status = _database->UpdateData(command);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }

    int status2 = 0;
    int MemId = Int32::Parse(lbl_MemId->Text);
    String^ action = " changed Member " + MemId + " information: ";
    if (status > 0) {
        if (lbl_Dept->Text != cmb_Dept->Text) {
            status2++;
            action += "Department";
        }
        if (lbl_Posi->Text != cmb_Posi->Text) {
            if (status2 != 0) {
                action += ", ";
            }
            action += "Position";
            status2++;
        }
        if (lbl_Auth->Text != cmb_Auth->Text) {
            if (status2 != 0) {
                action += ", ";
            }
            action += "Auth";
            status2++;
        }

        UpdateInfo();
        ChangeTxtInvisible();
        ChangeLabelVisible();
        UpdateDataGridView();
        lbl_Error->Text = "Updata Successful!";
        lbl_Error->ForeColor = Color::Green;
        lbl_Error->Visible = true;
        btn_Accpet->Visible = false;
        btn_Cancle->Visible = false;
        btn_DeleteInfo->Enabled = true;
        if (status2 != 0) {
            WeAlumni::Database::Log(_StfId, action);
        }
    }
    else {
        lbl_Error->Text = "ERROR";
        lbl_Error->Visible = true;
    }
}

/*
 * btn_Cancle_Click(System::Object^ sender, System::EventArgs^ e)
 * Reset the value of TextBoxes. Set all TextBoxes and two buttons to invisible.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_Cancle_Click(System::Object^ sender, System::EventArgs^ e) {
    ChangeTxtInvisible();
    ChangeLabelVisible();
    btn_Accpet->Visible = false;
    btn_Cancle->Visible = false;
    btn_DeleteInfo->Enabled = true;
}

/*
 * btn_DeleteInfo_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Delete Information", two buttons will show up
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_DeleteInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    lbl_Error->Visible = false;
    btn_Delete->Visible = true;
    btn_Close->Visible = true;
    btn_ChangeInfo->Enabled = false;
}

/*
 * btn_Delete_Click(System::Object^ sender, System::EventArgs^ e)
 * When clike "Delete", the method will trigger a delete command.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_Delete_Click(System::Object^ sender, System::EventArgs^ e) {
    int status = -1;
    String^ command = "DELETE FROM Staff WHERE MemId = '" + _MemId + "';";
    try {
        status = _database->DeleteData(command);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        return;
    }

    if (status > 0) {
        DeleteRecord();
        WeAlumni::Database::Log(_StfId, "Deleted Member");
        this->Close();
    }
    else {
        lbl_Error->Text = "ERROR";
        lbl_Error->Visible = true;
    }
}

/*
 * btn_Close_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Cancle", two new buttons will be hiden.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::btn_Close_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Delete->Visible = false;
    btn_Close->Visible = false;
    btn_ChangeInfo->Enabled = true;
}

/*
 * UpdateDataGridView()
 * This method will update the info for the dgv_Staff.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::UpdateDataGridView() {
    int status = -1;
    String^ command = "SELECT Record.Id      AS 'Recording ID', " +
        "Record.Time    As 'Recording Time', " +
        "Record.MemId   AS 'Member ID', " +
        "Record.MemName AS 'Member Name', " +
        "Record.Action  AS 'Action' " +
        "FROM   Record WHERE Record.MemId = '" + _MemId + "' ORDER BY Record.Id ASC;";
    BindingSource^ bSource = gcnew BindingSource();
    try {
        status = _database->ReadDataAdapter(command);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }

    if (status > 0) {
        bSource->DataSource = _database->dataTable;
        dgv_Staff->DataSource = bSource;
    }
    else {
        lbl_Error_Data->Visible = true;
    }
}

/*
 * DeleteRecord()
 * This method will delete the info of record table.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::DeleteRecord() {
    int status = -1;
    String^ cmd = "DELETE FROM RECORD WHERE MemId = " + _MemId;

    try {
        status = _database->DeleteData(cmd);
    }
    catch (Exception^ exception) {
        lbl_Error->ForeColor = System::Drawing::Color::Red;
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }
}

/*
 * dgv_Staff_CellContentClick()
 * by double clicking specific row of dgv_Staff, a corresponding Record Info page will show up.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::dgv_Staff_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    RecInfoPage^ recInfoPage = gcnew RecInfoPage(Convert::ToInt32(dgv_Staff->CurrentRow->Cells[0]->Value));
    recInfoPage->ShowDialog();
}


