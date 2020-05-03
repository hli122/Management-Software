#include "RecInfoPage.h"

/*
 * RecInfoPage.cpp
 *
 * This file shows a RecordInfo page for a unique Record Id.
 *
 * @author: Sen Ma
 * Revised: 3/28/20
 * Revised: 4/25/20 chinese
 * Revised: 5/1/20 auth update
 */

using namespace System;

/*
* Initialize
* This method will try to initialize database.
* @param none
* @return none
*/
Void WeAlumni::RecInfoPage::Initialize() {
    try {
        if (auth == PublicUserInfo::Auth::Level_5) {
            btn_Update->Enabled = true;
            database = gcnew Database(Database::DatabaseType::Data, true);
        }
        else {
            btn_Update->Enabled = false;
            database = gcnew Database(Database::DatabaseType::Data);
        }
        UpdateInfo();
    }
    catch (System::Exception^ exception) {
        lbl_DBError->Text = exception->Message;
        lbl_DBError->ForeColor = System::Drawing::Color::Red;
    }
}

/*
 * UpdateInfo
 * This method will try to read record from the current database.
 * @param None 
 * @return None
 */
Void WeAlumni::RecInfoPage::UpdateInfo() {
    String^ command = "SELECT * FROM (Staff Join Record ON Staff.MemId = Record.MemId AND Record.Id = " + recId + ");";
    int status = -1;
    
    try {
        status = database->ReadData(command);
    }
    catch (Exception^ exception) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = exception->Message;
        return;
    }
    
    if (status == -1) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "Error -1";
    }
    else if (status == 0) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "找不到记录";
    }
    else {
        lbl_RcdId->Text = database->dataReader[4]->ToString();
        lbl_StfId->Text = database->dataReader[0]->ToString();
        lbl_StfName->Text = database->dataReader[7]->ToString();
        lbl_Time->Text = database->dataReader[8]->ToString();
        lbl_Content->Text = database->dataReader[9]->ToString();
        lbl_Dep->Text = database->dataReader[1]->ToString();
        lbl_Duty->Text = database->dataReader[2]->ToString();
        txt_Content->Visible = false;
    }
}

/*
 * btn_Confirm_Click
 * This method will try to update user input to Record.Action.
 */
Void WeAlumni::RecInfoPage::btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Confirm->Visible = false;
    btn_Cancel->Visible = false;
    btn_DeleteId->Visible = true;
    String^ command = "UPDATE Record SET Action = '" + txt_Content->Text + "' WHERE Id = " + recId + ";";
    int status = -1;
    
    try {
        status = database->UpdateData(command);

    }
    catch (Exception^ exception) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = exception->Message;
        return;
    }

    if (status == -1) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "Error -1 ";
    }
    else if (status == 0) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "无更改";
    }
    UpdateInfo();
}

/*
 * btn_DelConfirm_Click
 * This method will delete current Record from database.
 */
Void WeAlumni::RecInfoPage::btn_DelConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Confirm->Visible = false;
    btn_Cancel->Visible = false;
    lbl_DBError->Visible = true;
    String^ command = "DELETE FROM Record WHERE Id =" + recId + ";";
    int status = -1;
    
    try {
        status = database->UpdateData(command);

    }
    catch (Exception^ exception) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = exception->Message;
        return;
    }

    if (status == -1) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "无法删除不存在的记录";
    }
    else if (status == 0) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "无法删除不存在的记录";
    }
    else {
        this->Close();
    }
}

/*
 * btn_Update_Click
 * This method will show btn_confirm and btn_delete.
 */
Void WeAlumni::RecInfoPage::btn_Update_Click(System::Object^ sender, System::EventArgs^ e) {
    txt_Content->Text = lbl_Content->Text;
    txt_Content->Visible = true;
    btn_DeleteId->Visible = false;
    btn_Confirm->Visible = true;
    btn_Cancel->Visible = true;
}

/*
 * btn_Cancel_Click
 * This method will cancel last step and show previous record
 */
Void WeAlumni::RecInfoPage::btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
    UpdateInfo();
    btn_DeleteId->Visible = true;
    btn_Update->Visible = true;
    btn_Confirm->Visible = false;
    btn_DelConfirm->Visible = false;
    btn_Cancel->Visible = false;
}

/*
 * btn_DeleteId_Click
 * This method will show btn_DelConfirm and btn_Cancel
 */
Void WeAlumni::RecInfoPage::btn_DeleteId_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Update->Visible = false;
    btn_DelConfirm->Visible = true;
    btn_Cancel->Visible = true;
}