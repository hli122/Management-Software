#include "TreInfoPage.h"
/*
 * TreInfoPage.cpp
 *
 * This file includes suppot update info page and button click to changing info
 * accept changing, cancel changing and delete record.
 *
 * @author: Yiyun Zheng
 * Revised: 3/28/20
 *          4/4/20 Lock btn when record not found. No message if show data successfully
 *
 */

 /*
  * UpdateInfo
  * This method will read data from Treasury data base and Data data base and show infomation on page
  * @param String^ Record Id tell method which record should be shown.
  * @return None
  */
System::Void WeAlumni::TreInfoPage::UpdateInfo(String^ Record_Id) {
    lbl_Id->Text = Record_Id;
    String^ StaffId;
    int Status = -1;
    String^ cmd = "SELECT StfId, Time, Type, Amount, Comment "
                  "FROM Treasury "
                  "WHERE Id = " + Record_Id + "; ";

    try {
        Status = _TreDB->ReadData(cmd);
    }
    catch (Exception^ exception){
        lbl_Error->Text = exception->Message;
        lbl_Error->ForeColor = System::Drawing::Color::Red;
        UnableAllBtn();
        return;
    }
    if (Status == 1) {
        StaffId = _TreDB->dataReader[0]->ToString();
        lbl_StfId->Text = StaffId;
        lbl_Time->Text = _TreDB->dataReader[1]->ToString();
        lbl_Type->Text = _TreDB->dataReader[2]->ToString();
        lbl_Amount->Text = _TreDB->dataReader[3]->ToString();
        lbl_Comment->Text = _TreDB->dataReader[4]->ToString();
        UpdateOutsideInfo(StaffId);
    }
    else {
        lbl_Error->Text = "Error: Unable to find Treasury Info Page.";
        lbl_Error->ForeColor = System::Drawing::Color::Red;
        UnableAllBtn();
    }
}

/*
 * UpdateOutsideInfo
 * This method will read data from Data data base and show infomation on page
 * @param String^ Staff Id tell method which staff's infomation should be shown.
 * @return None
 */
int WeAlumni::TreInfoPage::UpdateOutsideInfo(String^ SId) {
    int Status = -1;
    String^ cmd = "SELECT S.Dept, S.Position, M.Name "
                  "FROM Staff S, Member M "
                  "WHERE S.MemId = " + SId + " And M.Id = " + SId + ";";
    try {
        Status = _DataDB->ReadData(cmd);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->ForeColor = System::Drawing::Color::Red;
        return -1;
    }
    if (Status == 1) {
        lbl_StfId->Text = SId;
        lbl_Dept->Text = _DataDB->dataReader[0]->ToString();
        lbl_Position->Text = _DataDB->dataReader[1]->ToString();
        lbl_StfName->Text = _DataDB->dataReader[2]->ToString();
        lbl_Error->Text = "";
        lbl_Error->ForeColor = System::Drawing::Color::Green;
    }
    else {
        lbl_Error->Text = "Error: Staff or Member Not Found, Error Status = " + Status;
        lbl_Error->ForeColor = System::Drawing::Color::Red;
    }

    return Status;
}

/*
 * btn_ChangeInfo_Click
 * This method will hide infomation label, show text box for modifying, 
 * and show other two button for accepting modify or not.
 * @param None
 * @return None
 */
System::Void WeAlumni::TreInfoPage::btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e) {
    SetShowLabelStatus(false);
    SetTextStatus(true);
    SetShowToText(true);
    SetButtonStatus(true);
}

/*
 * SetShowLabelStatus
 * This method will show infomation label on infopage depend on input bool
 * @param bool
 * @return None
 */
System::Void WeAlumni::TreInfoPage::SetShowLabelStatus(bool NewStatus) {
    lbl_StfId->Visible = NewStatus;
    lbl_Time->Visible = NewStatus;
    lbl_Type->Visible = NewStatus;
    lbl_Amount->Visible = NewStatus;
    lbl_Comment->Visible = NewStatus;
}

/*
 * SetTextStatus
 * This method will show text box on infopage depend on input bool.
 * @param bool
 * @return None
 */
System::Void WeAlumni::TreInfoPage::SetTextStatus(bool NewStatus) {
    txt_StfId->Visible = NewStatus;
    txt_Time->Visible = NewStatus;
    txt_Type->Visible = NewStatus;
    txt_Amount->Visible = NewStatus;
    txt_Comment->Visible = NewStatus;
}

/*
 * SetShowToText
 * If input ture, this method will set text of info label to text of text box.
 * Otherwise, set text of text box to text of info label
 * @param bool
 * @return None
 */
System::Void WeAlumni::TreInfoPage::SetShowToText(bool Mode) {
    if (Mode) {
        txt_StfId->Text = lbl_StfId->Text;
        txt_Time->Text = lbl_Time->Text;;
        txt_Type->Text = lbl_Type->Text;
        txt_Amount->Text = lbl_Amount->Text;
        txt_Comment->Text = lbl_Comment->Text;
    }
    else {
        lbl_StfId->Text = txt_StfId->Text;
        lbl_Time->Text = txt_Time->Text;
        lbl_Type->Text = txt_Type->Text;
        lbl_Amount->Text = txt_Amount->Text;
        lbl_Comment->Text = txt_Comment->Text;
    }
}

/*
 * SetButtonStatus
 * Show different button depend on input
 * @param bool
 * @return None
 */
System::Void WeAlumni::TreInfoPage::SetButtonStatus(bool ModifyStatus) {
    if (ModifyStatus) {
        btn_ChangeInfo->Visible = false;
        btn_Delete->Visible = false;
        btn_Accpet->Visible = true;
        btn_Cancle->Visible = true;
    }
    else {
        btn_ChangeInfo->Visible = true;
        btn_Delete->Visible = true;
        btn_Accpet->Visible = false;
        btn_Cancle->Visible = false;
    }
}

/*
 * btn_Accpet_Click
 * This method will update changing to data base, if successed
 * show infomation label, hide text box
 * and show other two button for modify or delete.
 * @param None
 * @return None
 */
System::Void WeAlumni::TreInfoPage::btn_Accpet_Click(System::Object^ sender, System::EventArgs^ e) {
    int Status = -1;
    if (UpdateOutsideInfo(txt_StfId->Text) > 0) {
        try {
            String^ cmd = "UPDATE Treasury "
                          "SET StfId = " + txt_StfId->Text + ", "
                              "Time = '" + txt_Time->Text + "', "
                              "Type = '" + txt_Type->Text + "', "
                              "Amount = '" + txt_Amount->Text + "', "
                              "Comment = '" + txt_Comment->Text + "' "
                          "WHERE Id = " + OrderId + ";";
            Status = _TreDB->UpdateData(cmd);
        }
        catch (Exception^ exception) {
            lbl_Error->Text = exception->Message;
            lbl_Error->ForeColor = System::Drawing::Color::Red;
            return;
        }
        if (Status > 0) {
            UpdateInfo(OrderId);
            SetShowLabelStatus(true);
            SetTextStatus(false);
            SetButtonStatus(false);
            lbl_Error->Text = "Success: Modify Accepted";
            lbl_Error->ForeColor = System::Drawing::Color::Green;

        }
        else {
            lbl_Error->Text = "Error: Unable to Modify ";
            lbl_Error->ForeColor = System::Drawing::Color::Red;
        }
    }
}
/*
 * btn_Delete_Click
 * This method will delete current record from data base, if successed
 * close infopage
 * @param None
 * @return None
 */
System::Void WeAlumni::TreInfoPage::btn_Delete_Click(System::Object^ sender, System::EventArgs^ e) {
    int Status = -1;
    String^ cmd = "DELETE FROM Treasury WHERE Id = " + OrderId + ";";
    try {
        Status = _TreDB->DeleteData(cmd);
    }
    catch (Exception^ exception) {
        lbl_Error->Text = exception->Message;
        lbl_Error->ForeColor = System::Drawing::Color::Red;
        return;
    }
    if (Status == 1) {
        this->Close();
        lbl_Error->Text = "Success: Deleted";
        lbl_Error->ForeColor = System::Drawing::Color::Green;
    }
    else {
        lbl_Error->Text = "Error: Unable to Delete ";
        lbl_Error->ForeColor = System::Drawing::Color::Red;
    }
}

/*
 * btn_Cancle_Click
 * This method will show infomation label, hide text box,
 * and show other two button for modify or delete without change any infomation.
 * @param None
 * @return None
 */
System::Void WeAlumni::TreInfoPage::btn_Cancle_Click(System::Object^ sender, System::EventArgs^ e) {
    SetShowLabelStatus(true);
    SetTextStatus(false);
    SetButtonStatus(false);
}

/*
 * btn_Cancle_Click
 * This method will show infomation label, hide text box,
 * and show other two button for modify or delete without change any infomation.
 * @param None
 * @return None
 */
System::Void WeAlumni::TreInfoPage::UnableAllBtn() {
    btn_Accpet->Enabled = false;
    btn_Cancle->Enabled = false;
    btn_ChangeInfo->Enabled = false;
    btn_Delete->Enabled = false;
}