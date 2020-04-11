#include "StfInfoPage.h"

/*
 * StfInfoPage.cpp
 *
 * This file implements all StfInfoPage interfaces.
 *
 * @author: Rui Jia
 * Revised: 4/4/20
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
        btn_Record->Enabled = false;
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
 * ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Edit Information", multiple TextBoxes will be visible to collect changed info.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    lbl_Error->Visible = false;
    ChangeTxtVisible();
    ChangeLabelInvisible();
    btn_Accpet->Visible = true;
    btn_Cancle->Visible = true;
}

/*
 * AcceptButton_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Accept", this method will trigger a Database update execution.
 * If exception occurs, an error message will be shown.
 * Then set all TextBoxes and two buttons to invisible.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::AcceptButton_Click(System::Object^ sender, System::EventArgs^ e) {
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

    if (status > 0) {
        UpdateInfo();
        ChangeTxtInvisible();
        ChangeLabelVisible();
        lbl_Error->Text = "Updata Successful!";
        lbl_Error->ForeColor = Color::Green;
        lbl_Error->Visible = true;
        btn_Accpet->Visible = false;
        btn_Cancle->Visible = false;
    }
    else {
        lbl_Error->Text = "ERROR";
        lbl_Error->Visible = true;
    }
}

/*
 * CancelButton_Click(System::Object^ sender, System::EventArgs^ e)
 * Reset the value of TextBoxes. Set all TextBoxes and two buttons to invisible.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::CancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
    ChangeTxtInvisible();
    ChangeLabelVisible();
    btn_Accpet->Visible = false;
    btn_Cancle->Visible = false;
}

/*
 * DeleteInfo_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Delete Information", two buttons will show up
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::DeleteInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    lbl_Error->Visible = false;
    btn_Delete->Visible = true;
    btn_Close->Visible = true;
}

/*
 * DeleteAcceptButton_Click(System::Object^ sender, System::EventArgs^ e)
 * When clike "Delete", the method will trigger a delete command.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::DeleteAcceptButton_Click(System::Object^ sender, System::EventArgs^ e) {
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
        this->Close();
    }
    else {
        lbl_Error->Text = "ERROR";
        lbl_Error->Visible = true;
    }
}

/*
 * DeleteCancelButton_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Cancle", two new buttons will be hiden.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfInfoPage::DeleteCancelButton_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Delete->Visible = false;
    btn_Close->Visible = false;
}

/*
 * RecordButton_Click(System::Object^ sender, System::EventArgs^ e)
 * Click "Record", jump to RecInfoPage page.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::RecordButton_Click(System::Object^ sender, System::EventArgs^ e) {
    RecInfoPage^ page = gcnew RecInfoPage(_MemId);
    page->Show();
}

/*
 * UpdateDataGridView
 * This method will update the info for the dgv_ShowPassword.
 * @param None
 * @return None
 */
Void WeAlumni::StfInfoPage::UpdateDataGridView() {
    int status = -1;
    String^ command = "SELECT R.Id      AS 'Recording ID', " +
                             "R.Time    As 'Recording Time', " +
                             "R.MemId   AS 'Member ID', " +
                             "R.MemName AS 'Member Name', " +
                             "R.Action  AS 'Action' " +
                      "FROM   Record R";
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
        lbl_Error->Text = "NO DATA";
        lbl_Error->Visible = true;
    }
}


