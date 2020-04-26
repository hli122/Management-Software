#include "SysChangeUserInfoPage.h"

/*
 * SysChangeUserInfoPage.cpp
 *
 * This file implements all SysChangeUserInfoPage interfaces.
 *
 * @author: Rui Jia
 * Revised: 4/12/20
 *
 */

using namespace System;

/*
 * Initialize()
 * Pre-initialize all staff Add Page
 * @param None
 * @return None
 */
Void WeAlumni::SysChangeUserInfoPage::Initialize() {
    try {
        _database = gcnew Database(Database::DatabaseType::Admin);
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
 * This method read from Admin table for the info of this User.
 * Then update info to according textbox.
 * @param None
 * @return None
 */
Void WeAlumni::SysChangeUserInfoPage::UpdateInfo() {
    lbl_Error->Visible = false;

    int status = -1;
    String^ cmd = "SELECT * FROM Admin WHERE StfId = '" + _stfId + "';";
    try {
        status = _database->ReadData(cmd);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->Visible = true;
        return;
    }

    if (status > 0) {
        txt_changeUser->Text = _database->dataReader->GetString(0);
        txt_changePass->Text = _database->dataReader->GetString(1);
    }
    else {
        lbl_Error->Text = "找不到用户";
        lbl_Error->Visible = true;
    }
}

/*
 * btn_Confirm_Click()
 * When click "Confirm", update user name and password information.
 * @param None
 * @return None
 */
Void WeAlumni::SysChangeUserInfoPage::btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e) {
    int status = -1;
    String^ command = "UPDATE Admin " +
        "SET    Username = '" + txt_changeUser->Text + "', " +
        "Password = '" + txt_changePass->Text + "' " +
        "WHERE  StfId = '" + _stfId + "';";
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
        lbl_Error->Text = "Successful!";
        lbl_Error->ForeColor = Color::Green;
        lbl_Error->Visible = true;
        txt_changeUser->Enabled = false;
        txt_changePass->Enabled = false;
        btn_Confirm->Enabled = false;
        btn_Cancle->Text = "Close";
    }
    else {
        lbl_Error->Text = "错误，无法更改用户名/密码";
        lbl_Error->Visible = true;
    }
}


/*
 * btn_Cancle_Click()
 * When click "Cancle", nothing change.
 * When click "Close", close this window.
 * @param None
 * @return None
 */
Void WeAlumni::SysChangeUserInfoPage::btn_Cancle_Click(System::Object^ sender, System::EventArgs^ e) {
    UpdateInfo();
    if (btn_Cancle->Text == "Close") {
        _database->dataReader->Close();
        this->Close();
    }
}

