#include "OrdInfoPage.h"

/*
 * OrdInfoPage.cpp
 *
 * This file shows a Order Information page for a unique Order Id.
 *
 * @author: Haoran Li
 * Revised: 4/1/20
 *
 */

using namespace System;

/*
 * UpdateInfo
 * This method will try to read order's and item's information from the current database.
 * @param None
 * @return None
 */
Void WeAlumni::OrdInfoPage::UpdateInfo() {
    String^ command = "SELECT Orders.Id, Orders.Status, Orders.Time, Orders.MemId, Member.Name, Member.Email, Member.Country, Member.Address1, Member.Address2, Member.City, Member.Postal, Orders.StfId, Orders.ItemId, Item.Name, Orders.Amount, Orders.Price, Orders.Comment, Item.Price FROM (Item Join (Orders, Member) ON Item.Id = Orders.ItemId AND Orders.MemId = Member.Id AND Orders.Id = " + ordId + ");";
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
        lbl_DBError->Text = "Failed to read from Database! ";
    }
    else if (status == 0) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "Read nothing from Database. ";
    }
    else {
        lbl_OdrId->Text = database->dataReader[0]->ToString();
        lbl_OdrStat->Text = database->dataReader[1]->ToString();
        lbl_Sbmtime->Text = database->dataReader[2]->ToString();
        lbl_MemID->Text = database->dataReader[3]->ToString();
        lbl_MemName->Text = database->dataReader[4]->ToString();
        lbl_Email->Text = database->dataReader[5]->ToString();
        lbl_Country->Text = database->dataReader[6]->ToString();
        lbl_Address1->Text = database->dataReader[7]->ToString();
        lbl_Address2->Text = database->dataReader[8]->ToString();
        lbl_City->Text = database->dataReader[9]->ToString();
        lbl_Postal->Text = database->dataReader[10]->ToString();
        lbl_StfID->Text = database->dataReader[11]->ToString();
        lbl_StfName->Text = database->dataReader[4]->ToString();
        lbl_ItemId->Text = database->dataReader[12]->ToString();
        lbl_ItemName->Text = database->dataReader[13]->ToString();
        lbl_OdrAmt->Text = database->dataReader[14]->ToString();
        lbl_OrdPrice->Text = database->dataReader[15]->ToString();
        lbl_Content->Text = database->dataReader[16]->ToString();
        item_price = Convert::ToDouble(database->dataReader[17]);
        btn_Check->Visible = false;
        btn_Confirm->Visible = false;
        btn_Cancel->Visible = false;
        txt_OdrStat->Visible = false;
        txt_ItemId->Visible = false;
        txt_ItemName->Visible = false;
        txt_OdrAmt->Visible = false;
        rtxt_Content->Visible = false;
    }    
}

/*
 * btn_Change_Click
 * This method will show btn_ Check, btn_Confirm and btn_Cancel.
 */
Void WeAlumni::OrdInfoPage::btn_Change_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Delete->Visible = false;
    btn_Check->Visible = true;
    btn_Confirm->Visible = true;
    btn_DelConfirm->Visible = false;
    btn_Cancel->Visible = true;
    txt_OdrStat->Visible = true;
    txt_ItemId->Visible = true;
    txt_ItemName->Visible = true;
    txt_OdrAmt->Visible = true;
    rtxt_Content->Visible = true;
    txt_OdrStat->Text = lbl_OdrStat->Text;
    txt_ItemId->Text = lbl_ItemId->Text;
    txt_ItemName->Text = lbl_ItemName->Text;
    txt_OdrAmt->Text = lbl_OdrAmt->Text;
    rtxt_Content->Text = lbl_Content->Text;
}

/*
 * btn_Check_Click
 * This method will check if item id or name exist
 */
Void WeAlumni::OrdInfoPage::btn_Check_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ command = "SELECT Id, Name FROM Item WHERE Id = '" + txt_ItemId->Text + "';";
    String^ command1 = "SELECT Id, Name FROM Item WHERE Name = '" + txt_ItemName->Text + "';";
    txt_ItemId->Visible = false;
    txt_ItemName->Visible = false;
    int status = -1;
    if (txt_ItemId->Text) {
        try {
            status = database->ReadData(command);
            lbl_ItemId->Text = database->dataReader[0]->ToString();
            lbl_ItemName->Text = database->dataReader[1]->ToString();
        }
        catch (Exception^ exception) {
            lbl_DBError->Visible = true;
            lbl_DBError->Text = exception->Message;
            return;
        }
    }else if (txt_ItemName->Text) {
        try {
            status = database->ReadData(command1);
            lbl_ItemId->Text = database->dataReader[0]->ToString();
            lbl_ItemName->Text = database->dataReader[1]->ToString();
        }
        catch (Exception^ exception) {
            lbl_DBError->Visible = true;
            lbl_DBError->Text = exception->Message;
            return;
        }
    }
    lbl_DBError->Visible = true;
    lbl_DBError->Text = "Item Found";
    if (status == -1) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "Error -1 ";
    }
    else if (status == 0) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "nonexist Id or Name";
    }
}

/*
 * btn_Confirm_Click
 * This method will update user input to database 
 */
Void WeAlumni::OrdInfoPage::btn_Confirm_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Confirm->Visible = false;
    btn_Cancel->Visible = false;
    btn_Delete->Visible = true;
    double order_price = Convert::ToDouble(txt_OdrAmt->Text) * Convert::ToDouble(item_price);
    String^ command = "UPDATE Orders " +
                          "SET Status = '" + txt_OdrStat->Text + "', " +
                              "Amount = '" + txt_OdrAmt->Text + "', " +
                              "Comment = '" + rtxt_Content->Text + "', " +
                              "Price = '" + Convert::ToString(order_price) + "' " +
                          "WHERE Id = " + ordId + ";";
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
        lbl_DBError->Text = "Change to Orders failed ";
    }
    else if (status == 0) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "No Change to Orders ";
    }
    UpdateInfo();
}

/*
 * btn_Delete_Click
 * This method will show DelConfirm and cancel button
 */
Void WeAlumni::OrdInfoPage::btn_Delete_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Confirm->Visible = false;
    btn_Check->Visible = false;
    btn_DelConfirm->Visible = true;
    btn_Cancel->Visible = true;
}

/*
 * btn_Cancel_Click
 * This method will cancel user's previous action
 */
Void WeAlumni::OrdInfoPage::btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Confirm->Visible = false;
    btn_DelConfirm->Visible = false;
    btn_Cancel->Visible = false;
    btn_Check->Visible = false;
    btn_Delete->Visible = true;
    btn_ChangeInfo->Visible = true;
    UpdateInfo();
}

/*
 * btn_DelConfirm_Click
 * This method will delete current Order from database.
 */
Void WeAlumni::OrdInfoPage::btn_DelConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
    btn_Confirm->Visible = false;
    btn_Cancel->Visible = false;
    btn_ChangeInfo->Visible = true;
    String^ command = "DELETE FROM Orders WHERE Id =" + ordId + ";";
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
        lbl_DBError->Text = "No Such Id";
    }
    else {
        this->Close();
    }
}