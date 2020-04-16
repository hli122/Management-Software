#include "TreAddPage.h"

/*
 * TreAddPage.cpp
 *
 * This file includes suppot insert new record to treasury database.
 *
 * @author: Yiyun Zheng
 * Revised: 4/1/20
 *          4/4/20 Time textbox show current date and time.Provide exit btn after add new info
 *          4/12/20 Add public user info as input
 *
 */

 /*
  * UpdateInfo
  * This method will print next available ID from treasury data bsae and staff Id we input.
  * @param String^ Staff Id
  * @return None
  */
System::Void WeAlumni::TreAddPage::UpdateInfo(String^ SId) {
    lbl_Id->Text = Convert::ToString(_TreDB->GetNextId(Database::DatabaseTable::Treasury));
    lbl_StfId->Text = SId;
    txt_Time->Text = _TreDB->GetSystemTime();
}

/*
 * btn_Cancel_Click
 * Store all data into treasury database
 * @param None
 * @return None
 */
System::Void WeAlumni::TreAddPage::btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ cmd = "INSERT INTO Treasury (ID, StfId, Time, Type, Amount, Comment) " +
                  "VALUES ('" + lbl_Id->Text + "', " +
                                Convert::ToInt32(lbl_StfId->Text) + "," +
                          "'" + txt_Time->Text + "'," +
                          "'" + cmb_Type->Text + "'," +
                          "'" + txt_Amount->Text + "'," +
                          "'" + txt_Comment->Text + "');";
    int status = -1;
    try {
        status = _TreDB->InsertData(cmd);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->ForeColor = Color::Red;
        lbl_Error->Visible = true;
        return;
    }

    if (status == -1) {
        lbl_Error->Text = "Fail: Unable to Add record";
        lbl_Error->ForeColor = Color::Red;
        lbl_Error->Visible = true;
    }
    else {
        lbl_Error->Text = "Succuss: Add treasury record success";
        lbl_Error->ForeColor = Color::Green;
        lbl_Error->Visible = true;

        btn_Confirm->Enabled = false;
        btn_Cancel->Text = "Exit";
        SetBoxReadOnly();
    }
}

/*
 * btn_Cancel_Click
 * Cancel adding and close the window.
 * @param None
 * @return None
 */
System::Void WeAlumni::TreAddPage::btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
}

/*
 * btn_Cancel_Click
 * Set all box and button read only.
 * @param None
 * @return None
 */
System::Void WeAlumni::TreAddPage::SetBoxReadOnly() {
    cmb_Type->Enabled = false;
    txt_Time->Enabled = false;
    txt_Amount->Enabled = false;
    txt_Comment->Enabled = false;
}


