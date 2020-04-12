#include "OrdAddPage.h"

/*
 * OrdAddPage.cpp
 *
 * This file will provide an empty page with textbox for new file
 *
 * @author: Haoran Li
 * Revised: 4/07/20
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
Void WeAlumni::OrdAddPage::Initialize() {
    lbl_OrdId->Text = Convert::ToString(database->GetNextId(Database::DatabaseTable::Orders));
    txt_SubmitTime->Text = database->GetSystemTime(); 
    lbl_StfId->Text = Convert::ToString(_PublicUserInfo->GetId());
    lbl_StfName->Text = _PublicUserInfo->GetName(); 
}

/*
 * btn_VerifyMem_Click
 * Verify if Member ID and Member Name valid
 * @param None
 * @return None
 */
Void WeAlumni::OrdAddPage::btn_VerifyMem_Click(System::Object^ sender, System::EventArgs^ e) {
    bool success = false;
    String^ command;
    int status = -1;
    if (txt_MemId->Text == "" && txt_MemName->Text == "") {
        lbl_error->Text = "Empty ID and Name";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
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
            lbl_error->Text = "Mem ID not exist";
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
        }
        else {
            lbl_error->Text = "MemInfo Verified";
            lbl_error->ForeColor = Color::Green;
            lbl_error->Visible = true;
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
            lbl_error->Text = "Mem Name not exist";
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
        }
        else {
            lbl_error->Text = "MemInfo Verified";
            lbl_error->ForeColor = Color::Green;
            lbl_error->Visible = true;
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

        if (database->dataReader[0]->ToString() == txt_MemName->Text) {
            lbl_error->Text = "MemInfo Verified";
            lbl_error->ForeColor = Color::Green;
            lbl_error->Visible = true;
            success = true;
        }
        else {
            lbl_error->Text = "MemInfo not match";
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
        }
    }

    if (success == true) {
        btn_VerifyMem->Enabled = false;
    }
}

/*
 * btn_VerifyItm_Click
 * Verify if Item ID and Item Name valid
 * @param None
 * @return None
 */
Void WeAlumni::OrdAddPage::btn_VerifyItm_Click(System::Object^ sender, System::EventArgs^ e) {
    bool success = false;
    String^ command;
    int status = -1;
    if (txt_ItemId->Text == "" && txt_ItemName->Text == "") {
        lbl_error->Text = "Empty ID and Name";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }
    else if (txt_ItemId->Text != "" && txt_ItemName->Text == "") {
        command = "SELECT Name, Price " +
            "FROM Item " +
            "WHERE Id = " + Convert::ToInt32(txt_ItemId->Text) + ";";
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
            lbl_error->Text = "Item ID not exist";
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
        }
        else {
            lbl_error->Text = "Item Verified";
            lbl_error->ForeColor = Color::Green;
            lbl_error->Visible = true;
            txt_ItemName->Text = database->dataReader[0]->ToString();
            lbl_ItemPrice->Text = database->dataReader[1]->ToString();
            success = true;
        }
    }
    else if (txt_ItemId->Text == "" && txt_ItemName->Text != "") {
        command = "SELECT Id, Price " +
            "FROM Item " +
            "WHERE Name = '" + txt_ItemName->Text + "';";
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
            lbl_error->Text = "Item Name not exist";
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
        }
        else {
            lbl_error->Text = "ItmInfo Verified";
            lbl_error->ForeColor = Color::Green;
            lbl_error->Visible = true;
            txt_ItemId->Text = database->dataReader[0]->ToString();
            lbl_ItemPrice->Text = database->dataReader[1]->ToString();
            success = true;
        }
    }
    else {
        command = "SELECT Name, Price " +
            "FROM Item " +
            "WHERE Id = " + Convert::ToInt32(txt_ItemId->Text) + ";";
        try {
            status = database->ReadData(command);
        }
        catch (Exception^ exception) {
            lbl_error->Text = exception->Message;
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
            return;
        }

        if (database->dataReader[0]->ToString() == txt_ItemName->Text) {
            lbl_error->Text = "ItmInfo Verified";
            lbl_error->ForeColor = Color::Green;
            lbl_error->Visible = true;
            lbl_ItemPrice->Text = database->dataReader[1]->ToString();
            success = true;
        }
        else {
            lbl_error->Text = "ItmInfo not match";
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
        }
    }

    if (success == true) {
        btn_VerifyItm->Enabled = false;
    }
}

/*
 * btn_Confirm_Click
 * Insert all text into Orders table
 * @param None
 * @return None
 */
Void WeAlumni::OrdAddPage::btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e) {
    bool finish = false;
    double order_price;
    if (btn_VerifyMem->Enabled == true || btn_VerifyItm->Enabled == true || txt_OrdAmt->Text == "") {
        lbl_error->Text = "Wrong or Lack Info";
        lbl_error->ForeColor = Color::Red;
        lbl_error->Visible = true;
    }
    else {
        order_price = Convert::ToDouble(txt_OrdAmt->Text) * Convert::ToDouble(lbl_ItemPrice->Text);
        lbl_SubmitTime->Text = txt_SubmitTime->Text;
        txt_SubmitTime->Visible = false;
        int o_id = Convert::ToInt32(lbl_OrdId->Text);
        int m_id = Convert::ToInt32(txt_MemId->Text);
        int s_id = Convert::ToInt32(lbl_StfId->Text);
        int i_id = Convert::ToInt32(txt_ItemId->Text);
        String^ sts = cmb_OrdStat->Text;
        String^ stm = lbl_SubmitTime->Text;
        String^ o_amt = txt_OrdAmt->Text;
        String^ op = Convert::ToString(order_price);
        String^ command = "INSERT INTO Orders (Id, " +
                                            "MemId, " +
                                            "StfId, " +
                                            "ItemId, " +
                                            "Status, " +
                                            "Time, " +
                                            "Amount, " +
                                            "Price) " +
                                            "VALUES(" + o_id + "," +
                                                        m_id + "," +
                                                        s_id + "," +
                                                        i_id + ", '" +
                                                        sts + "', '" +
                                                        stm + "', '" +
                                                        o_amt + "', '" +
                                                        op + "');";
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
            lbl_error->Text = "Fail to Add Page";
            lbl_error->ForeColor = Color::Red;
            lbl_error->Visible = true;
        }
        else {
            lbl_error->Text = "Succuss: Add Page";
            lbl_error->ForeColor = Color::Green;
            lbl_error->Visible = true;
            finish = true;
        }
    }

    if (finish == true) {
        lbl_OrdAmt->Text = txt_OrdAmt->Text;
        lbl_OrdPrice->Text = Convert::ToString(order_price);
        btn_Confirm->Enabled = false;
        cmb_OrdStat->Enabled = false;
        txt_SubmitTime->Enabled = false;
        txt_MemId->Enabled = false;
        txt_MemName->Enabled = false;
        txt_ItemId->Enabled = false;
        txt_ItemName->Enabled = false;
        txt_OrdAmt->Enabled = false;
    }
}

/*
 * btn_Cancel_Click
 * Cancel add process and close current page
 * @param None
 * @return None
 */
Void WeAlumni::OrdAddPage::btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
}