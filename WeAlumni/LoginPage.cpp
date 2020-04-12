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
    DatabasePrecheck::StartPrecheck();
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
    String^ command = "Select Username , Password From Admin Where Username = '" + txt_Username->Text + "';";
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
  * Remember_Click
  * this method remembers username and password
  */
Void WeAlumni::LoginPage::Remember_Click(System::Object^ sender, System::EventArgs^ e) {
    String^ command = "Update Admin SET Username  = '" + txt_Username->Text+ "' ,Password = '" + txt_Password->Text + "'Where IsDefault = 1" ";";
    int status = -1;

    try {
        status = _database->UpdateData(command);
        lbl_DBError->Visible = true;
        lbl_DBError->Text = "Ur username and Password is remembered";
    }
    catch (Exception^ exception) {
        lbl_DBError->Visible = true;
        lbl_DBError->Text = exception->Message;
        return;
    }

    if (status == -1) {
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
    String^ command = "Select Username , Password From Admin Where IsDefault == 1;";
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
        lbl_DBError->Text = "defaut fail Error -1 ";
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
    txt_Password->Visible = false;
    lbl_PasswordStars->Visible = true;
}

/*
  * JumpToMain
  * this method jumps to mainwindow, called after username & password match
  * @param None
  * @return None
  */
Void WeAlumni::LoginPage::JumpToMain() {
    MainWindow^ mw = gcnew MainWindow(_publicUserInfo);
    mw->Show();
}

/*
  * Clear_Click
  * this method clears all userinput
  */
Void WeAlumni::LoginPage::Clear_Click(System::Object^ sender, System::EventArgs^ e) {
    txt_Username->Text = "";
    txt_Password->Text = "";
    txt_Password->Visible = true;
    lbl_PasswordStars->Visible = false;
}

/*
  * Forgot_Click
  * this method jump to SysForgotPassword page
  */
Void WeAlumni::LoginPage::Forgot_Click(System::Object^ sender, System::EventArgs^ e) {
    SysForgotPassword^ fp = gcnew SysForgotPassword();
    fp->Show();
}