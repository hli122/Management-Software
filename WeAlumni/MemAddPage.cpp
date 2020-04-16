#include "MemAddPage.h"

/*
 * MemAddPage.cpp
 *
 * This file implements all MemAddPage interfaces.
 *
 * @author: Jiaying Hou
 * Revised: 4/4/20
 *          4/15/20 added PublicUserInfo
 */

using namespace System;

/*
* Initialize
* This method will try to initialize database
* @param none
* @return none
*/
Void WeAlumni::MemAddPage::Initialize() {
	try {
		database = gcnew Database(Database::DatabaseType::Data);
		UpdateInfo();
	}
	catch (System::Exception^ exception) {
		lbl_error->Text = exception->Message;
		lbl_error->ForeColor = System::Drawing::Color::Red;
	}
}

/*
* UpdateInfo
* This method will pre-initialize member's id
* @param none
* @return none
*/
Void WeAlumni::MemAddPage::UpdateInfo() {
	_id = database->GetNextId(WeAlumni::Database::DatabaseTable::Member);
	lbl_Id->Text = _id.ToString();
}

/*
* btn_accept_Click
* When click button "accept", this method will triger a database insert execution.
* If exception occurs, an error message will be shown.
* Otherwise, the window will be closed.
*/
Void WeAlumni::MemAddPage::btn_accept_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ cmd = "INSERT INTO Member (Id, Status, Type, Name, Gender, Birth, " +
									  "Email, Phone, Wechat, Country, Address1, " +
									  "Address2, City, Postal, StdId, Program, " +
		                              "EndDate, Degree, Major1, Major2, CareerStatus, " +
		                              "Company, Position, SearchAuth) " + "VALUES (" +
		                               _id + ", '" + cmb_Status->Text + "', '" +
					
		cmb_Type->Text + "', '" + txt_Name->Text + "', '" +
		                               txt_Gender->Text + "', '" + txt_Birth->Text + "', '" +
		                               txt_Email->Text + "', '" + txt_Phone->Text + "', '" +
		                               txt_Wechat + "', '" + txt_Country->Text + "', '" +
	                    	           txt_Address1->Text + "', '" + txt_Address2->Text + "', '" +
		                               txt_City->Text + "', '" + txt_Postal->Text + "', '" +
		                               txt_StdId->Text + "', '" + cmb_Program->Text + "', '" +
		                               txt_EndDate->Text + "', '" + cmb_Degree->Text + "', '" +
		                               txt_Major1->Text + "', '" + txt_Major2->Text + "', '" +
		                               cmb_CareerStatus->Text + "', '" + txt_Company->Text + "', '" +
		                               txt_Position->Text + "', '" + cmb_SearchAuth->Text + "');";

	int status = -1;
	
	try {
		status = database->InsertData(cmd);
	}
	catch (Exception^ exception) {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return;
	}

	int status1 = -1;
	
	try {
		status1 = insertRecord();
	}
	catch (Exception^ exception) {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return;
	} 
	
	if (status > 0 && status1 > 0) {
		this->Close();
	}
}

/*
* btn_Cancel_Click
* When click button "Cancel", the current window will be closed.
*/
Void WeAlumni::MemAddPage::btn_Cancel_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

/*
* insertRecord
* This method will try to insert data into Record table.
* @param None
* @return int # of rows that are successfully inserted
*             -1 if exception occured.
*/
int  WeAlumni::MemAddPage::insertRecord() {
	int recId = database->GetNextId(WeAlumni::Database::DatabaseTable::Record);
	String^ currTime = database->GetSystemTime();
	String^ cmd = "INSERT INTO Record (Id, StfId, MemId, Time, Action) " +
		          "VALUES (" + recId + ", " + _stfId + ", " + _id + 
		                  ", '" + currTime + "', '" + "Add Member" + "');";
	int status = -1;

	try {
		status = database->InsertData(cmd);
	}
	catch (Exception^ exception) {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return -1;
	}

	if (status > 0) {
		return status;
	}
	return -1;
} 