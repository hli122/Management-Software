#include "LoginPage.h"

/*
 * LoginPage.cpp
 *
 * this file is for login page get username and password matching in database
 *
 * @author: Sen Ma
 * Revised: 04/11/2020 
 *
 */

using namespace System;

 /*
  * Initialize
  * Initialize all data
  * @param None
  * @return None
  */
Void WeAlumni::LoginPage::Initialize() {
    DatabasePrecheck::loginPrecheck();
    try {
        _database = gcnew Database(Database::DatabaseType::Admin);
        ShowDefault();
    }
    catch (System::Exception^ exception) {
        lbl_DBError->Text = exception->Message;
        lbl_DBError->Visible = true;
    }
}

/*
  * Login_Click
  * this method logs in an user when username and password matches
  */
Void WeAlumni::LoginPage::Login_Click(System::Object^ sender, System::EventArgs^ e) {

    String^ command = "Select * From Admin Where Username = '" + txt_Username->Text + "';";
    int status = -1;
    
    try {
        status = _database->ReadData(command);
    }
    catch (Exception^ exception) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = exception->Message;
        return;
    }

    if (status == -1) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "Error -1 ";
        return;
    }
    else if (status == 0) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "No such Username";
        txt_Password->Text = "";
    }

    if (txt_Password->Text == _database->dataReader[1]->ToString()) {
        JumpToMain();
    }
    else {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "Password not match, Please try again";
    }
}

/*
  * Check_Remember
  * this method remembers username and password
  */
Void WeAlumni::LoginPage::Check_Remember() {
    String^ command = "Update Admin SET IsDefault = 0 Where IsDefault = 1;";
    String^ command1 = "Update Admin SET IsDefault = 1 Where Username  = '" + txt_Username->Text + "';";
    int status1 = -1;

    try {
        _database->UpdateData(command);
        status1 = _database->UpdateData(command1);
    }
    catch (Exception^ exception) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = exception->Message;
        return;
    }

    if (status1 == -1) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "remember Error -1 ";
    }
}

/*
  * ShowDefault
  * this method show remembered username and password in database
  * @param None
  * @return None
  */
Void WeAlumni::LoginPage::ShowDefault() {
    String^ command = "Select Username , Password From Admin Where IsDefault = 1;";
    int status = -1;

    try {
        status = _database->ReadData(command);
    }
    catch (Exception^ exception) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = exception->Message;
        return;
    }
    
    if (status == -1) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "found no defaut";
        return;
    }
    else if (status == 0) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "No such Username";
        txt_Password->Text = "";
        return;
    }
    txt_Username->Text = _database->dataReader[0]->ToString();
    txt_Password->Text = _database->dataReader[1]->ToString();
}

/*
  * JumpToMain
  * this method jumps to mainwindow, called after username & password match
  * @param None
  * @return None
  */
Void WeAlumni::LoginPage::JumpToMain() {
    String^ command = "Select Name From Member Where Id = " +  _database->dataReader[2]->ToString() + ";";
    Database^ _databaseData;

    try {
        _databaseData = gcnew Database(Database::DatabaseType::Data,true);
        _databaseData->ReadData(command);
    }
    catch (System::Exception^ exception) {
        lbl_DBError->Text = exception->Message;
        lbl_DBError->Visible = true;
    }

    PublicUserInfo^ pui = gcnew PublicUserInfo(Convert::ToInt32(_database->dataReader[2]->ToString()), 
                                               _databaseData->dataReader[0]->ToString(),
                                               PublicUserInfo::Auth(Convert::ToInt32(_database->dataReader[3]->ToString())));
   if (cbox_Remember->Checked) {
        Check_Remember();
   }
    MainWindow^ mw = gcnew MainWindow(pui);
    mw->Show();
}

/*
  * Forgot_Click
  * this method jump to SysForgotPassword page
  */
Void WeAlumni::LoginPage::Forgot_Click(System::Object^ sender, System::EventArgs^ e) {
    SysForgotPassword^ fp = gcnew SysForgotPassword();
    fp->Show();
}
