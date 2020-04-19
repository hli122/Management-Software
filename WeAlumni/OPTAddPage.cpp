#include "OPTAddPage.h"

/*
 * OPTAddPage.cpp
 *
 * This file will provide an empty page with textbox for new file
 *
 * @author: Xiangdong Che
 * Revised:  4/04/20  Fixed insert fail bug and added Exit button
 *           4/01/20  
 *           4/14/20  Added PublicUserInfo
 *          
 *
 */

using namespace System;

/*
 * Initialize
 * Initialize all data
 * @param None
 * @return None
 */
Void WeAlumni::OPTAddPage::Initialize() {
    try {
        database = gcnew Database(Database::DatabaseType::Data);
    }
    catch (Exception^ exception) {
        lbl_error->Text = exception->Message;
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }
    lbl_OPTID->Text = Convert::ToString(database->GetNextId(Database::DatabaseTable::OPT));
    lbl_StfId->Text = _StfId -> ToString();
}

/*
 * SetBoxReadOnly
 * Set all boxes Enabled to false
 * @param None
 * @return None
 */
Void WeAlumni::OPTAddPage::SetBoxReadOnly() {
    cmb_Status->Enabled = false;
    txt_MemId->Enabled = false;
    txt_MemName->Enabled = false;
    txt_StartDate->Enabled = false;
    txt_EndDate->Enabled = false;
    txt_Title->Enabled = false;
    txt_Position->Enabled = false;
    txt_CardNumber->Enabled = false;
    txt_CardStartDate->Enabled = false;
    txt_CardEndDate->Enabled = false;
}

/*
 * InsertRecord
 * Insert a new item in record after add new OPT
 * @param None
 * @return None
 */
Void WeAlumni::OPTAddPage::InsertRecord() {
    int recId = database->GetNextId(WeAlumni::Database::DatabaseTable::Record);
    String^ currTime = database->GetSystemTime();
    String^ cmd = "INSERT INTO Record (Id, StfId, MemId, Time, Action)" +
        "VALUES (" + recId + "," + 
                    _StfId + "," + 
                    Convert::ToInt32(txt_MemId->Text) + "," + 
                "'" + currTime + "'," + 
                "'Add OPT '" + 
                "'" + txt_MemId->Text + "'" +  
                "'Status '" + 
                "'" + cmb_Status->Text + "'" + ");";
    int status = -1;

    try {
        status = database->InsertData(cmd);
    }
    catch (Exception^ exception) {
        lbl_error->ForeColor = System::Drawing::Color::Red;
        lbl_error->Text = exception->Message;
        lbl_error->Visible = true;
    }
}

/*
 * btn_Verify_Click
 * Verify if Member ID and Member Name valid
 * @param None
 * @return None
 */
Void WeAlumni::OPTAddPage::btn_Verify_Click(System::Object^ sender, System::EventArgs^ e) {
    bool success = false;
    String^ command;
    int status = -1;
    if (txt_MemId->Text == "" && txt_MemName->Text == "") {
        lbl_Verify->Text = "编号和姓名不能为空";
        lbl_Verify->ForeColor = Color::Red;
        lbl_Verify->Visible = true;
    }
    else if (txt_MemId->Text != "" && txt_MemName->Text == "") {
        command = "SELECT Name " +
                  "FROM Member " +
                  "WHERE Id = " + Convert::ToInt32(txt_MemId->Text) + ";";
        try {
            status = database->ReadData(command);
        }
        catch (Exception^ exception) {
            lbl_error->Text = exception->Message;
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
            return;
        }

        if (status == -1) {
            lbl_Verify->Text = "无效的编号";
            lbl_Verify->ForeColor = Color::Red;
            lbl_Verify->Visible = true;
        }
        else {
            lbl_Verify->Text = "验证成功";
            lbl_Verify->ForeColor = Color::Green;
            lbl_Verify->Visible = true;
            txt_MemName->Text = database->dataReader[0]->ToString();
            success = true;
        }
    }
    else if (txt_MemId->Text == "" && txt_MemName->Text != "") {
        command = "SELECT Id " +
                  "FROM Member " +
                  "WHERE Name = '" + txt_MemName->Text + "';";
        try {
            status = database->ReadData(command);
        }
        catch (Exception^ exception) {
            lbl_error->Text = exception->Message;
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
            return;
        }

        if (status == -1) {
            lbl_Verify->Text = "无效的姓名";
            lbl_Verify->ForeColor = Color::Red;
            lbl_Verify->Visible = true;
        }
        else {
            lbl_Verify->Text = "验证成功";
            lbl_Verify->ForeColor = Color::Green;
            lbl_Verify->Visible = true;
            txt_MemId->Text = database->dataReader[0]->ToString();
            success = true;
        }
    }
    else {
        command = "SELECT Name " +
                  "FROM Member " +
                  "WHERE Id = " + Convert::ToInt32(txt_MemId->Text) + ";";
        try {
            status = database->ReadData(command);
        }
        catch (Exception^ exception) {
            lbl_error->Text = exception->Message;
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
            return;
        }

        if (database->dataReader[0]->ToString() == lbl_MemName->Text) {
            lbl_Verify->Text = "验证成功";
            lbl_Verify->ForeColor = Color::Green;
            lbl_Verify->Visible = true;
            success = true;
        }
        else {
            lbl_Verify->Text = "编号和姓名不匹配";
            lbl_Verify->ForeColor = Color::Red;
            lbl_Verify->Visible = true;
        }
    }

    if (success == true) {
        btn_Verify->Enabled = false;
        txt_MemId->Enabled = false;
        txt_MemName->Enabled = false;
    }
}

/*
 * btn_Confirm_Click
 * Insert all text into OPT table 
 * @param None
 * @return None
 */
Void WeAlumni::OPTAddPage::btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e) {
    bool finish = false;
    if (btn_Verify->Enabled == true) {
        lbl_error->Text = "需要验证";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }
    else {
        String^ command = "INSERT INTO OPT (Id," +
                                           "Status, " +
                                           "MemId, " +
                                           "StfId, " +
                                           "StartDate, " +
                                           "EndDate, " +
                                           "Title, " +
                                           "Position, " +
                                           "CardNumber, " +
                                           "CardStartDate, " +
                                           "CardEndDate) " +
                          "VALUES ("  + Convert::ToInt32(lbl_OPTID->Text) + "," + 
                                  "'" + cmb_Status->Text + "', " +
                                        Convert::ToInt32(txt_MemId->Text) + "," +
                                        Convert::ToInt32(lbl_StfId->Text) + "," +
                                  "'" + txt_StartDate->Text + "'," +
                                  "'" + txt_EndDate->Text + "'," +
                                  "'" + txt_Title->Text + "'," +
                                  "'" + txt_Position->Text + "'," +
                                  "'" + txt_CardNumber->Text + "'," +
                                  "'" + txt_CardStartDate->Text + "'," +
                                  "'" + txt_CardEndDate->Text + "');";
        int status = -1;
        try {
            status = database->InsertData(command);
        }
        catch (Exception^ exception) {
            lbl_error->Text = exception->Message;
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
            return;
        }

        if (status == -1) {
            lbl_error->Text = "新建失败";
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
        }
        else {
            lbl_error->Text = "新建成功";
            lbl_error->ForeColor = Color::Green;
            lbl_error->Visible = true;
            finish = true;
        }
    }

    if (finish == true) {
        String^ action = "Added a new OPT record";
        InsertRecord();
        Database::Log(Convert::ToInt32(_StfId), action);
        btn_Confirm->Visible = false;
        btn_Cancel->Visible = false;
        btn_Exit->Visible = true;
        SetBoxReadOnly();
    }
}

/*
 * btn_Cancel_Click
 * Cancel add process and close current page
 * @param None
 * @return None
 */
Void WeAlumni::OPTAddPage::btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
}

/*
 * btn_Exit_Click
 * close current page after insert succussfully
 * @param None
 * @return None
 */
Void WeAlumni::OPTAddPage::btn_Exit_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
}

