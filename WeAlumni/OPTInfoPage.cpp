#include "OPTInfoPage.h"

/*
 * OPTInfoPage.cpp
 *
 * This file will show all info of a certain ID, and contains functions of editing and deleting.
 *
 * @author: Xiangdong Che
 * Revised: 4/04/20  Fixed button's position. Added verification function
 *          3/31/20  Renamed class name from OPT to OPTInfoPage
 *          3/27/20
 *
 */

using namespace System;

/*
 * SetLableInvisible
 * This method will set All labels to invisible
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::SetLableInvisible() {
    lbl_Status->Visible = false;
    lbl_MemId->Visible = false;
    lbl_StfId->Visible = false;
    lbl_StartDate->Visible = false;
    lbl_EndDate->Visible = false;
    lbl_Title->Visible = false;
    lbl_Position->Visible = false;
    lbl_CardNumber->Visible = false;
    lbl_CardStartDate->Visible = false;
    lbl_CardEndDate->Visible = false;
}

/*
 * SetLableVisible
 * This method will set all labels to visible
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::SetLableVisible() {
    lbl_Status->Visible = true;
    lbl_MemId->Visible = true;
    lbl_StfId->Visible = true;
    lbl_StartDate->Visible = true;
    lbl_EndDate->Visible = true;
    lbl_Title->Visible = true;
    lbl_Position->Visible = true;
    lbl_CardNumber->Visible = true;
    lbl_CardStartDate->Visible = true;
    lbl_CardEndDate->Visible = true;
}

/*
 * SetBoxInvisible
 * This method will set all boxes to invisible
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::SetBoxInvisible() {
    cbm_Status->Visible = false;
    txt_MemId->Visible = false;
    txt_StfId->Visible = false;
    txt_StartDate->Visible = false;
    txt_EndDate->Visible = false;
    txt_Title->Visible = false;
    txt_Position->Visible = false;
    txt_CardNumber->Visible = false;
    txt_CardEndDate->Visible = false;
    txt_CardStartDate->Visible = false;
}

/*
 * SetBoxVisible
 * This method will set all Boxes to visible
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::SetBoxVisible() {
    cbm_Status->Visible = true;
    txt_MemId->Visible = true;
    txt_StfId->Visible = true;
    txt_StartDate->Visible = true;
    txt_EndDate->Visible = true;
    txt_Title->Visible = true;
    txt_Position->Visible = true;
    txt_CardNumber->Visible = true;
    txt_CardEndDate->Visible = true;
    txt_CardStartDate->Visible = true;
}

/*
 * Initialize
 * This method will initialize all data
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::Initialize() {
    try {
        database = gcnew Database(Database::DatabaseType::Data);
        UpdateInfo();
    }
    catch (Exception^ exception) {
        lbl_error->Text = exception->Message;
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }
    if (lbl_MemId->Text == "N/A") {
        btn_ChangeInfo->Enabled = false;
        btn_DeleteAll->Enabled = false;
        lbl_error->Text = "无效的成员编号";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }
}

/*
 * UpdateInfo
 * This method read from OPT table. Then update info to according labels.
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::UpdateInfo() {
    String^ command_OPT = "SELECT * FROM OPT WHERE Id = " + _OPTId + ";";
    String^ command_Member = "SELECT Name, " +
                                    "Gender, " +
                                    "Email, " +
                                    "Phone, " +
                                    "Wechat " +
                             "FROM Member INNER JOIN OPT " +
                             "WHERE Member.Id = OPT.MemId AND " + 
                                   "OPT.Id = " + _OPTId + ";";
    String^ command_Staff = "SELECT Name From Member INNER JOIN Staff " + 
                                                    "INNER JOIN OPT " + 
                            "WHERE Member.Id = Staff.MemId AND " + 
                                  "Staff.MemId = OPT.StfId AND " + 
                                  "OPT.Id = " + _OPTId + ";";
    int status = -1;
    //read data from OPT
    try
    {
        status = database->ReadData(command_OPT);
    }
    catch (Exception^ exception) {
        lbl_error->Text = exception->Message;
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
        return;
    }
    if (status == 1) {
        
        lbl_OPTID->Text = database->dataReader[0]->ToString();
        lbl_Status->Text = database->dataReader[1]->ToString();
        cbm_Status->Text = lbl_Status->Text;
        lbl_MemId->Text = database->dataReader[2]->ToString();
        txt_MemId->Text = lbl_MemId->Text;
        lbl_StfId->Text = database->dataReader[3]->ToString();
        txt_StfId->Text = lbl_StfId->Text;
        lbl_StartDate->Text = database->dataReader[4]->ToString();
        txt_StartDate->Text = lbl_StartDate->Text;
        lbl_EndDate->Text = database->dataReader[5]->ToString();
        txt_EndDate->Text = lbl_EndDate->Text;
        lbl_Title->Text = database->dataReader[6]->ToString();
        txt_Title->Text = lbl_Title->Text;
        lbl_Position->Text = database->dataReader[7]->ToString();
        txt_Position->Text = lbl_Position->Text;
        lbl_CardNumber->Text = database->dataReader[8]->ToString();
        txt_CardNumber->Text = lbl_CardNumber->Text;
        lbl_CardStartDate->Text = database->dataReader[9]->ToString();
        txt_CardStartDate->Text = lbl_CardStartDate->Text;
        lbl_CardEndDate->Text = database->dataReader[10]->ToString();
        txt_CardEndDate->Text = lbl_CardEndDate->Text;
        if (_auth == PublicUserInfo::Auth::Level_3) {
            lbl_CardNumber->Visible = false;
            lbl_CardStartDate->Visible = false;
            lbl_CardEndDate->Visible = false;
            lbl_Prompt_CardNumber->Visible = false;
            lbl_Prompt_CardStartDate->Visible = false;
            lbl_Prompt_CardEndDate->Visible = false;
        }
    }
    else {
        lbl_error->Text = "OPT信息读取失败";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
        return;
    }
    //read data from Member
    try 
    {
        status = database->ReadData(command_Member);
    }
    catch (Exception^ exception) {
        lbl_error->Text = exception->Message;
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
        return;
    }
    if (status == 1) {
        lbl_MemName->Text = database->dataReader[0]->ToString();
        lbl_Gender->Text = database->dataReader[1]->ToString();
        lbl_Email->Text = database->dataReader[2]->ToString();
        lbl_Phone->Text = database->dataReader[3]->ToString();
        lbl_WeChat->Text = database->dataReader[4]->ToString();
    }
    else {
        lbl_error->Text = "成员信息读取失败";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
        return;
    }
    //read data from Staff
    try 
    {
        status = database->ReadData(command_Staff);
    }
    catch (Exception^ exception) {
        lbl_error->Text = exception->Message;
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
        return;
    }
    if (status == 1) {
        lbl_StfName->Text = database->dataReader[0]->ToString();
    }
    else {
        lbl_error->Text = "员工信息读取失败";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
        return;
    }
}

/*
 * btn_ChangeInfo_Click
 * When click button "Change Info", multiple TextBoxes will be visible to collect changed info.
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    SetLableInvisible();
    SetBoxVisible();
    if (_auth == PublicUserInfo::Auth::Level_3) {
        lbl_CardNumber->Visible = false;
        lbl_CardStartDate->Visible = false;
        lbl_CardEndDate->Visible = false;
        txt_CardNumber->Visible = false;
        txt_CardStartDate->Visible = false;
        txt_CardEndDate->Visible = false;
        lbl_Prompt_CardNumber->Visible = false;
        lbl_Prompt_CardStartDate->Visible = false;
        lbl_Prompt_CardEndDate->Visible = false;
    }
    lbl_error->Visible = false;
    btn_ChangeInfo->Visible = false;
    btn_DeleteAll->Visible = false;
    btn_Exit->Visible = false;
    btn_Verify->Visible = true;
    btn_ChangeConfirm->Visible = true;
    btn_ChangeCancel->Visible = true;
    btn_Verify->Enabled = true;
}

/*
 * btn_ChangeConfirm_Click
 * When click button "Confirm", this method will trigger a Database update execution.
 * If exception occurs, an error message will be shown.
 * Then set all TextBoxes and two buttons to invisable.
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::btn_ChangeConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
    if (btn_Verify->Enabled == false) {
        String^ command = "UPDATE OPT " +
            "SET Status = '" + cbm_Status->Text + "', " +
            "MemId = '" + txt_MemId->Text + "', "
            "StfId = '" + txt_StfId->Text + "', "
            "StartDate = '" + txt_StartDate->Text + "', " +
            "EndDate = '" + txt_EndDate->Text + "', " +
            "Title = '" + txt_Title->Text + "', " +
            "Position = '" + txt_Position->Text + "', " +
            "CardNumber = '" + txt_CardNumber->Text + "', " +
            "CardStartDate = '" + txt_CardStartDate->Text + "', " +
            "CardEndDate = '" + txt_CardEndDate->Text + "' " +
            "WHERE Id = " + _OPTId + ";";
        int status = -1;
        try {
            status = database->UpdateData(command);
        }
        catch (Exception^ exception) {
            lbl_error->Text = exception->Message;
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
            return;
        }

        if (status == 1) {
            String^ action = "Changed OPT " + _OPTId;
            Database::Log(_pui->GetId(), action);
            lbl_error->Text = "更改成功";
            lbl_error->ForeColor = Color::Green;
            lbl_error->Visible = true;
            UpdateInfo();
            SetBoxInvisible();
            SetLableVisible();
            if (_auth == PublicUserInfo::Auth::Level_3) {
                lbl_CardNumber->Visible = false;
                lbl_CardStartDate->Visible = false;
                lbl_CardEndDate->Visible = false;
                txt_CardNumber->Visible = false;
                txt_CardStartDate->Visible = false;
                txt_CardEndDate->Visible = false;
                lbl_Prompt_CardNumber->Visible = false;
                lbl_Prompt_CardStartDate->Visible = false;
                lbl_Prompt_CardEndDate->Visible = false;
            }
            btn_DeleteAll->Visible = true;
            btn_ChangeInfo->Visible = true;
            btn_ChangeConfirm->Visible = false;
            btn_ChangeCancel->Visible = false;
            btn_Verify->Visible = false;
            lbl_Verify->Visible = false;
        }
        else {
            lbl_error->Text = "更改失败";
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
        }
    }
    else {
        lbl_error->Text = "需要验证";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }
}

/*
 * btn_ChangeCancel_Click
 * This method reset the value of TextBoxes, and set all TextBoxes and two buttons to invisible.
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::btn_ChangeCancel_Click(System::Object^ sender, System::EventArgs^ e) {
    UpdateInfo();
    btn_DeleteAll->Visible = true;
    btn_ChangeInfo->Visible = true;
    btn_Exit->Visible = true;
    btn_ChangeConfirm->Visible = false;
    btn_ChangeCancel->Visible = false;
    btn_Verify->Visible = false;
    lbl_Verify->Visible = false;
    lbl_error->Visible = false;
    SetBoxInvisible();
    SetLableVisible();
    if (_auth == PublicUserInfo::Auth::Level_3) {
        lbl_CardNumber->Visible = false;
        lbl_CardStartDate->Visible = false;
        lbl_CardEndDate->Visible = false;
        txt_CardNumber->Visible = false;
        txt_CardStartDate->Visible = false;
        txt_CardEndDate->Visible = false;
        lbl_Prompt_CardNumber->Visible = false;
        lbl_Prompt_CardStartDate->Visible = false;
        lbl_Prompt_CardEndDate->Visible = false;
    }
}

/*
 * btn_DeleteAllButton_Click
 * Set Two buttons to Visable
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::btn_DeleteAllButton_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_DeleteAll->Visible = false;
    btn_ChangeInfo->Visible = false;
    btn_Exit->Visible = false;
    btn_DeleteConfirm->Visible = true;
    btn_DeleteCancel->Visible = true;
    lbl_error->Visible = false;
    SetBoxInvisible();
    SetLableVisible();
    if (_auth == PublicUserInfo::Auth::Level_3) {
        lbl_CardNumber->Visible = false;
        lbl_CardStartDate->Visible = false;
        lbl_CardEndDate->Visible = false;
        txt_CardNumber->Visible = false;
        txt_CardStartDate->Visible = false;
        txt_CardEndDate->Visible = false;
        lbl_Prompt_CardNumber->Visible = false;
        lbl_Prompt_CardStartDate->Visible = false;
        lbl_Prompt_CardEndDate->Visible = false;
    }
}

/*
 * btn_DeleteConfirm_Click
 * Delete current Form from TABLE OPT and close the page
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::btn_DeleteConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ command = "DELETE FROM OPT WHERE Id = " + _OPTId + ";";
    int status = -1;
    try {
        status = database->DeleteData(command);
    }
    catch (Exception^ exception) {
        lbl_error->Text = exception->Message;
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
        return;
    }
    if (status == 1) {
        this->Close();
    }
    else {
        lbl_error->Text = "删除失败";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }
}

/*
 * btn_DeleteCancel_Click
 * Reset the buttons to ChangeInfo page
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::btn_DeleteCancel_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_DeleteAll->Visible = true;
    btn_ChangeInfo->Visible = true;
    btn_Exit->Visible = true;
    btn_DeleteConfirm->Visible = false;
    btn_DeleteCancel->Visible = false;
    SetBoxVisible();
    SetLableInvisible();
    if (_auth == PublicUserInfo::Auth::Level_3) {
        lbl_CardNumber->Visible = false;
        lbl_CardStartDate->Visible = false;
        lbl_CardEndDate->Visible = false;
        txt_CardNumber->Visible = false;
        txt_CardStartDate->Visible = false;
        txt_CardEndDate->Visible = false;
        lbl_Prompt_CardNumber->Visible = false;
        lbl_Prompt_CardStartDate->Visible = false;
        lbl_Prompt_CardEndDate->Visible = false;
    }
}

/*
 * VerifyUpdate
 * Update member name and staff name
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::VerifyUpdate(int^ MemId, int^ StfId) {
    String^ command = "SELECT Name FROM Member WHERE Id = " + MemId + ";";
    int status = -1;
    try {
        status = database->ReadData(command);
    }
    catch (Exception^) {
        lbl_error->Text = "无匹配姓名";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }

    if (status == 1) {
        lbl_MemId->Text = MemId->ToString();
        lbl_MemName->Text = database->dataReader[0]->ToString();
    }
    else {
        lbl_error->Text = "编号为空";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }

    command = "SELECT Name FROM Member WHERE Id = " + StfId + ";";
    try {
        status = database->ReadData(command);
    }
    catch (Exception^ ) {
        lbl_error->Text = "无法读取员工信息";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }

    if (status == 1) {
        lbl_StfId->Text = StfId->ToString();
        lbl_StfName->Text = database->dataReader[0]->ToString();
    }
    else {
        lbl_error->Text = "编号为空";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }
}

/*
 * btn_Verify_Click
 * Verify if Member name and staff name valid or not
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::btn_Verify_Click(System::Object^ sender, System::EventArgs^ e) {
    int nextId = database->GetNextId(Database::DatabaseTable::Member);
    lbl_MemName->Text = "N/A";
    lbl_StfId->Text = "N/A";
    if (txt_MemId->Text == "" || txt_StfId->Text == "") {
        lbl_Verify->Text = "成员编号和员工编号不能为空";
        lbl_Verify->ForeColor = Color::Red;
        lbl_Verify->Visible = true;
    }
    else if (Convert::ToInt32(txt_MemId->Text) >= nextId) {
        lbl_Verify->Text = "无效的成员编号";
        lbl_Verify->ForeColor = Color::Red;
        lbl_Verify->Visible = true;
    }
    else if(Convert::ToInt32(txt_StfId->Text) >= nextId){
        lbl_Verify->Text = "无效的员工编号";
        lbl_Verify->ForeColor = Color::Red;
        lbl_Verify->Visible = true;
    }
    else {
        lbl_Verify->Text = "验证成功";
        lbl_Verify->ForeColor = Color::Green;
        lbl_Verify->Visible = true;
        int^ MemId = Convert::ToInt32(txt_MemId->Text);
        int^ StfId = Convert::ToInt32(txt_StfId->Text);
        VerifyUpdate(MemId, StfId);
        btn_Verify->Enabled = false;
        txt_MemId->Visible = false;
        txt_StfId->Visible = false;
        lbl_MemId->Visible = true;
        lbl_StfId->Visible = true;
    }
}

/*
 * btn_Exit_Click
 * Close page
 * @param None
 * @return None
 */
Void WeAlumni::OPTInfoPage::btn_Exit_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
}

