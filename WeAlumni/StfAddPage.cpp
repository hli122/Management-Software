#include "StfAddPage.h"

/*
 * StfAddPage.cpp
 *
 * This file implements all StfAddPage interfaces.
 *
 * @author: Rui Jia
 * Revised: 4/4/20
 *          4/15/20 use PublicUserInfo
 */

using namespace System;

/*
 * Initialize()
 * Pre-initialize all staff Add Page
 * @param None
 * @return None
 */
Void WeAlumni::StfAddPage::Initialize() {
    try {
        _database = gcnew Database(Database::DatabaseType::Data);
    }
    catch (System::Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }
}

/*
 * Verify_Click(System::Object^ sender, System::EventArgs^ e)
 * Verify Member ID or Name or both
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfAddPage::Verify_Click(System::Object^ sender, System::EventArgs^ e) {
    int status = -1;
    int status2 = -1;
    String^ MemId = txt_MemId->Text;
    String^ Name = txt_Name->Text;
    String^ Name_test = "";

    if (MemId != "") {
        int MemId2 = Int32::Parse(MemId);
        String^ cmd = "SELECT * FROM Member WHERE Id = '" + MemId2 + "';";
        try {
            status = _database->ReadData(cmd);
        }
        catch (Exception^ exception) {
            lbl_Error->Text = exception->Message;
            lbl_Error->Visible = true;
            return;
        }
        if (status > 0) {
            Name_test = _database->dataReader->GetString(3);
        }
    }

    if (Name != "") {
        String^ cmd2 = "SELECT * FROM Member WHERE Name = '" + Name + "';";
        try {
            status2 = _database->ReadData(cmd2);
        }
        catch (Exception^ exception) {
            lbl_Error->Text = exception->Message;
            lbl_Error->Visible = true;
            return;
        }
    }

    if (status > 0 && Name == "") {
        lbl_Error->ForeColor = Color::Green;
        lbl_Error->Text = "Verified";
        lbl_Error->Visible = true;
        txt_Name->Text = _database->dataReader->GetString(3);
        InsertStaff();
    }
    else if (MemId == "" && status2 > 0) {
        lbl_Error->ForeColor = Color::Green;
        lbl_Error->Text = "Verified";
        lbl_Error->Visible = true;
        txt_MemId->Text = _database->dataReader->GetInt32(0).ToString();
        InsertStaff();
    }
    else if (status > 0 && status2 > 0) {
        if (txt_Name->Text == Name_test) {
            lbl_Error->ForeColor = Color::Green;
            lbl_Error->Text = "Verified";
            lbl_Error->Visible = true;
            InsertStaff();
        }
        else {
            lbl_Error->Text = "Member ID and Name are not match";
            lbl_Error->Visible = true;
        }
    }
    else {
        lbl_Error->Text = "Invalid Member ID / Name";
        lbl_Error->Visible = true;
    }
}

/*
 * InsertStaff()
 * Multiple comboboxes will be enabled to collect insert info.
 * @param None
 * @return None
 */
Void WeAlumni::StfAddPage::InsertStaff() {
    txt_MemId->Enabled = false;
    txt_Name->Enabled = false;
    cmb_Auth->Enabled = true;
    cmb_Dept->Enabled = true;
    cmb_Posi->Enabled = true;
    btn_Confirm->Visible = true;
    btn_Cancel->Visible = true;
    btn_Verify->Visible = false;
}

/*
 * Confirm_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Confirm", this method will access the Database to iinsert data.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfAddPage::Confirm_Click(System::Object^ sender, System::EventArgs^ e) {
    txt_MemId->Enabled = false;
    txt_Name->Enabled = false;
    int status = -1;
    int MemId2 = Int32::Parse(txt_MemId->Text);
    String^ Dept = cmb_Dept->Text;
    String^ Posi = cmb_Posi->Text;
    String^ Auth = cmb_Auth->Text;
    String^ command = "INSERT INTO Staff VALUES(" + MemId2 + ", '" +
        Dept + "', '" +
        Posi + "', '" +
        Auth + "');";
    try {
        status = _database->InsertData(command);
    }
    catch (Exception^ exception) {
        lbl_Error->ForeColor = Color::Red;
        lbl_Error->Text = exception->Message;
        return;
    }

    if (status > 0) {
        lbl_Error->Text = "Insert success";
        cmb_Auth->Enabled = false;
        cmb_Dept->Enabled = false;
        cmb_Posi->Enabled = false;
        btn_Confirm->Visible = false;
        AddNewRecord();
        btn_Cancel->Text = "Close";
    }
    else {
        lbl_Error->Text = "ERRPR";
        lbl_Error->ForeColor = Color::Red;
    }
}

/*
 * Cancel_Click(System::Object^ sender, System::EventArgs^ e)
 * When click button "Cancel", close this window.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfAddPage::Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
}

/*
 * AddNewRecord(System::Object^ sender, System::EventArgs^ e)
 * When click button "Add new record"£¬ add new recoding data to Record table.
 * @param System::Object^ sender, System::EventArgs^ e
 * @return None
 */
Void WeAlumni::StfAddPage::AddNewRecord() {
    int status = -1;
    int RecordId = _database->GetNextId(Database::DatabaseTable::Record);
    int MemId = Int32::Parse(txt_MemId->Text);
    String^ Name = txt_Name->Text;
    String^ time = _database->GetSystemTime();
    String^ action = "Add Staff, Auth " + cmb_Auth->Text;
    String^ command = "INSERT INTO Record VALUES(" + RecordId + "," +
        _StfId + "," +
        MemId + ", '" +
        Name + "', '" +
        time + "', '" +
        action + "');";
    try {
        status = _database->InsertData(command);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        return;
    }

    if (status > 0) {
        lbl_Error->Text = "Update success";
    }
    else {
        lbl_Error->Text = "ERRPR";
        lbl_Error->ForeColor = Color::Red;
    }
}