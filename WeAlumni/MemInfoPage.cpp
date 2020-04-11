#include "MemInfoPage.h"

/*
 * MemInfoPage.cpp
 *
 * This file implements all MemInfoPage interfaces.
 *
 * @author: Jiaying Hou
 * Revised: 4/4/20
 *
 */

using namespace System;

/*
* Initialize
* This method will try to initialize database. 
* If success, it will pre-initialize all member's info.
* @param none
* @return none
*/
Void WeAlumni::MemInfoPage::Initialize() {
	try {
		database = gcnew Database(Database::DatabaseType::Data);
		UpdateInfo();
		UpdateRecord();
	}
	catch (System::Exception^ exception) {
		lbl_error->Text = exception->Message;
		lbl_error->ForeColor = System::Drawing::Color::Red;
	}
}

/*
* UpdateInfo
*
* This method read from Member table for the info of this member.
* Then update info to according labels
* @param none
* @return none
*/
Void WeAlumni::MemInfoPage::UpdateInfo() {
	lbl_error->Visible = false;
	String^ cmd= "SELECT * FROM Member WHERE Id = " + _id;

	int status = -1;

	try {
		status = database->ReadData(cmd);
	}
	catch (Exception^ exception) {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return;
	}
	
	if (status > 0) {
		lbl_error->Visible = false;
		lbl_Id->Text = _id.ToString();
		lbl_Status->Text = database->dataReader[1]->ToString();
		lbl_Type->Text = database->dataReader[2]->ToString();
		lbl_Name->Text = database->dataReader[3]->ToString();
		lbl_Gender->Text = database->dataReader[4]->ToString();
		lbl_Birth->Text = database->dataReader[5]->ToString();
		lbl_Email->Text = database->dataReader[6]->ToString();
		lbl_Phone->Text = database->dataReader[7]->ToString();
		lbl_Wechat->Text = database->dataReader[8]->ToString();
		lbl_Country->Text = database->dataReader[9]->ToString();
		lbl_Address1->Text = database->dataReader[10]->ToString();
		lbl_Address2->Text = database->dataReader[11]->ToString();
		lbl_City->Text = database->dataReader[12]->ToString();
		lbl_Postal->Text = database->dataReader[13]->ToString();
		lbl_StdId->Text = database->dataReader[14]->ToString();
		lbl_Program->Text = database->dataReader[15]->ToString();
		lbl_EndDate->Text = database->dataReader[16]->ToString();
		lbl_Degree->Text = database->dataReader[17]->ToString();
		lbl_Major1->Text = database->dataReader[18]->ToString();
		lbl_Major2->Text = database->dataReader[19]->ToString();
		lbl_CareerStatus->Text = database->dataReader[20]->ToString();
		lbl_Company->Text = database->dataReader[21]->ToString();
		lbl_Position->Text = database->dataReader[22]->ToString();
		lbl_SearchAuth->Text = database->dataReader[23]->ToString();

		cmb_Status->Text = database->dataReader[1]->ToString();
		cmb_Type->Text = database->dataReader[2]->ToString();
		txt_Name->Text = database->dataReader[3]->ToString();
		txt_Gender->Text = database->dataReader[4]->ToString();
		txt_Birth->Text = database->dataReader[5]->ToString();
		txt_Email->Text = database->dataReader[6]->ToString();
		txt_Phone->Text = database->dataReader[7]->ToString();
		txt_Wechat->Text = database->dataReader[8]->ToString();
		txt_Country->Text = database->dataReader[9]->ToString();
		txt_Address1->Text = database->dataReader[10]->ToString();
		txt_Address2->Text = database->dataReader[11]->ToString();
		txt_City->Text = database->dataReader[12]->ToString();
		txt_Postal->Text = database->dataReader[13]->ToString();
		txt_StdId->Text = database->dataReader[14]->ToString();
		cmb_Program->Text = database->dataReader[15]->ToString();
		txt_EndDate->Text = database->dataReader[16]->ToString();
		cmb_Degree->Text = database->dataReader[17]->ToString();
		txt_Major1->Text = database->dataReader[18]->ToString();
		txt_Major2->Text = database->dataReader[19]->ToString();
		cmb_CareerStatus->Text = database->dataReader[20]->ToString();
		txt_Company->Text = database->dataReader[21]->ToString();
		txt_Position->Text = database->dataReader[22]->ToString();
		cmb_SearchAuth->Text = database->dataReader[23]->ToString();
	}
	else {
		lbl_error->Text = "Error occured";
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Visible = true;
	}
}

/*
* ChangeInfo_Click
* When click button "Change Info", multiple TextBoxes will be visible to collect changed information.
*/
Void WeAlumni::MemInfoPage::btn_ChangeInfo_Click(System::Object^ sender, System::EventArgs^ e) {
	cmb_Status->Visible = true;
	cmb_Type->Visible = true;
	txt_Name->Visible = true;
	txt_Gender->Visible = true;
	txt_Birth->Visible = true;
	txt_Email->Visible = true;
	txt_Phone->Visible = true;
	txt_Wechat->Visible = true;
	txt_Country->Visible = true;
	txt_Address1->Visible = true;
	txt_Address2->Visible = true;
	txt_City->Visible = true;
	txt_Postal->Visible = true;
	txt_StdId->Visible = true;
	cmb_Program->Visible = true;
	txt_EndDate->Visible = true;
	cmb_Degree->Visible = true;
	txt_Major1->Visible = true;
	txt_Major2->Visible = true;
	cmb_CareerStatus->Visible = true;
	txt_Company->Visible = true;
	txt_Position->Visible = true;
	cmb_SearchAuth->Visible = true;
	btn_ChangeInfoAccept->Visible = true;
	btn_ChangeInfoCancel->Visible = true;
	lbl_error->Visible = false;
}

/*
* btn_Delete_Click
* When click button "Delete Member", two buttons will show up
*/
Void WeAlumni::MemInfoPage::btn_Delete_Click(System::Object^ sender, System::EventArgs^ e) {
	lbl_error->Visible = false;
	btn_DeleteAccept->Visible = true;
	btn_DeleteCancel->Visible = true;
}

/*
* UpdateRecord
*
* This method read from Record table for the record of this member.
* Then update record to DataGridView1
* @param none
* @return none
*/
Void WeAlumni::MemInfoPage::UpdateRecord() {
	BindingSource^ bSource = gcnew BindingSource();
	String^ command = "SELECT Record.Id AS 'Record Id', " + 
				 "Record.Time AS 'Action Time', " + 
				 "Record.StfId AS 'Staff Id', " + 
				 "Member.Name AS 'Staff Name', " + 
				 "Staff.Dept AS 'Staff Department', " +
				 "Staff.Position AS 'Staff Position', " +
				 "Record.Action AS 'Action' " +
			  "FROM Record, Member, Staff " +
			  "WHERE Record.StfId = Staff.MemId AND " + 
				"Member.Id = Staff.MemId AND " + 
				"Record.MemId = " + _id + " ORDER BY Record.Id ASC;";

	int status = -1;

	try {
		status = database->ReadDataAdapter(command);
	}
	catch (Exception^ exception) {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return;
	}
	
	if (status >= 0) {
		lbl_error->Visible = false;
		bSource->DataSource = database->dataTable;
		dataGridView1->DataSource = bSource;
	}
	else {
		lbl_error->Visible = true;
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = "Error occured";
	}
}

/*
* btn_ChangeInfoAccept_Click
*
* When click button "Affirm", this method will trigger a database update execution.
* If exception occurs, an error message will be shown.
* Then set all TextBoxes and two buttons(affirmButton, cancelButton) to invisible
*/
Void WeAlumni::MemInfoPage::btn_ChangeInfoAccept_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ cmd = "UPDATE Member " +
		      "SET Status = '" + cmb_Status->Text + "', " +
			  "Type = '" + cmb_Type->Text + "', " +
			  "Name = '" + txt_Name->Text + "', " +
			  "Gender = '" + txt_Gender->Text + "', " +
			  "Birth = '" + txt_Birth->Text + "', " +
			  "Email = '" + txt_Email->Text + "', " +
			  "Phone = '" + txt_Phone->Text + "', " +
			  "Wechat = '" + txt_Wechat->Text + "', " +
			  "Country = '" + txt_Country->Text + "', " +
			  "Address1 = '" + txt_Address1->Text + "', " +
			  "Address2 = '" + txt_Address2->Text + "', " +
			  "City = '" + txt_City->Text + "', " +
			  "Postal = '" + txt_Postal->Text + "', " +
		      	  "StdId = '" + txt_StdId->Text + "', " +
			  "Program = '" + cmb_Program->Text + "', " +
		      	  "EndDate = '" + txt_EndDate->Text + "', " +
			  "Degree = '" + cmb_Degree->Text + "', " +
			  "Major1 = '" + txt_Major1->Text + "', " +
			  "Major2 = '" + txt_Major2->Text + "', " +
			  "CareerStatus = '" + cmb_CareerStatus->Text + "', " +
			  "Company = '" + txt_Company->Text + "', " +
			  "Position = '" + txt_Position->Text + "', " +
			  "SearchAuth = '" + cmb_SearchAuth->Text + "' " +
		      "WHERE Id = " + _id;
	
	int status = -1;

	try {
		status = database->UpdateData(cmd);
	}
	catch (Exception^ exception) {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return;
	}
	
	if (status > 0) {
		lbl_Status->Text = cmb_Status->Text;
		lbl_Type->Text = cmb_Type->Text;
		lbl_Name->Text = txt_Name->Text;
		lbl_Gender->Text = txt_Gender->Text;
		lbl_Birth->Text = txt_Birth->Text;
		lbl_Email->Text = txt_Email->Text;
		lbl_Phone->Text = txt_Phone->Text;
		lbl_Wechat->Text = txt_Wechat->Text;
		lbl_Country->Text = txt_Country->Text;
		lbl_Address1->Text = txt_Address1->Text;
		lbl_Address2->Text = txt_Address2->Text;
		lbl_City->Text = txt_City->Text;
		lbl_Postal->Text = txt_Postal->Text;
		lbl_StdId->Text = txt_StdId->Text;
		lbl_Program->Text = cmb_Program->Text;
		lbl_EndDate->Text = txt_EndDate->Text;
		lbl_Degree->Text = cmb_Degree->Text;
		lbl_Major1->Text = txt_Major1->Text;
		lbl_Major2->Text = txt_Major2->Text;
		lbl_CareerStatus->Text = cmb_CareerStatus->Text;
		lbl_Company->Text = txt_Company->Text;
		lbl_Position->Text = txt_Position->Text;
		lbl_SearchAuth->Text = cmb_SearchAuth->Text;

		cmb_Status->Visible = false;
		cmb_Type->Visible = false;
		txt_Name->Visible = false;
		txt_Gender->Visible = false;
		txt_Birth->Visible = false;
		txt_Email->Visible = false;
		txt_Phone->Visible = false;
		txt_Wechat->Visible = false;
		txt_Country->Visible = false;
		txt_Address1->Visible = false;
		txt_Address2->Visible = false;
		txt_City->Visible = false;
		txt_Postal->Visible = false;
		txt_StdId->Visible = false;
		cmb_Program->Visible = false;
		txt_EndDate->Visible = false;
		cmb_Degree->Visible = false;
		txt_Major1->Visible = false;
		txt_Major2->Visible = false;
		cmb_CareerStatus->Visible = false;
		txt_Company->Visible = false;
		txt_Position->Visible = false;
		cmb_SearchAuth->Visible = false;
		btn_ChangeInfoAccept->Visible = false;
		btn_ChangeInfoCancel->Visible = false;
		lbl_error->Text = "Changes saved";
		lbl_error->ForeColor = System::Drawing::Color::Green;
		lbl_error->Visible = true;
	}
	else {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = "Error occured";
		lbl_error->Visible = true;
	}
}

/*
* btn_ChangeInfoCancelButton_Click
* When click button "Cancel", go back to previous MemInfoPage, nothing changes
*/
Void WeAlumni::MemInfoPage::btn_ChangeInfoCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	lbl_error->Visible = false;
	cmb_Status->Visible = false;
	cmb_Type->Visible = false;
	txt_Name->Visible = false;
	txt_Gender->Visible = false;
	txt_Birth->Visible = false;
	txt_Email->Visible = false;
	txt_Phone->Visible = false;
	txt_Wechat->Visible = false;
	txt_Country->Visible = false;
	txt_Address1->Visible = false;
	txt_Address2->Visible = false;
	txt_City->Visible = false;
	txt_Postal->Visible = false;
	txt_StdId->Visible = false;
	cmb_Program->Visible = false;
	txt_EndDate->Visible = false;
	cmb_Degree->Visible = false;
	txt_Major1->Visible = false;
	txt_Major2->Visible = false;
	cmb_CareerStatus->Visible = false;
	txt_Company->Visible = false;
	txt_Position->Visible = false;
	cmb_SearchAuth->Visible = false;
	btn_ChangeInfoAccept->Visible = false;
	btn_ChangeInfoCancel->Visible = false;

	cmb_Status->Text = lbl_Status->Text;
	cmb_Type->Text = lbl_Type->Text;
	txt_Name->Text = lbl_Name->Text;
	txt_Gender->Text = lbl_Gender->Text;
	txt_Birth->Text = lbl_Birth->Text;
	txt_Email->Text = lbl_Email->Text;
	txt_Phone->Text = lbl_Phone->Text;
	txt_Wechat->Text = lbl_Wechat->Text;
	txt_Country->Text = lbl_Country->Text;
	txt_Address1->Text = lbl_Address1->Text;
	txt_Address2->Text = lbl_Address2->Text;
	txt_City->Text = lbl_City->Text;
	txt_Postal->Text = lbl_Postal->Text;
	txt_StdId->Text = lbl_StdId->Text;
	cmb_Program->Text = lbl_Program->Text;
	txt_EndDate->Text = lbl_EndDate->Text;
	cmb_Degree->Text = lbl_Degree->Text;
	txt_Major1->Text = lbl_Major1->Text;
	txt_Major2->Text = lbl_Major2->Text;
	cmb_CareerStatus->Text = lbl_CareerStatus->Text;
	txt_Company->Text = lbl_Company->Text;
	txt_Position->Text = lbl_Position->Text;
	cmb_SearchAuth->Text = lbl_SearchAuth->Text;
}

/*
* btn_DeleteAccept_Click
*
* When click button "Affirm:, the method will trigger a delete command.
* If an exception occurs, the error message will be shown
*/
Void WeAlumni::MemInfoPage::btn_DeleteAccept_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ cmd = "DELETE FROM Member " +
		      "WHERE Id = " + _id;

	int status = -1;

	try {
		status = database->DeleteData(cmd);
	}
	catch (Exception^ exception) {
		btn_DeleteAccept->Visible = false;
		btn_DeleteCancel->Visible = false;
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return;
	}
	
	if (status > 0) {
		this->Close();
	}	
	else {
		btn_DeleteAccept->Visible = false;
		btn_DeleteCancel->Visible = false;
		lbl_error->Visible = true;
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = "Error occured";
	}
}

/*
* btn_DeleteCancel_Click
* When click button "Cancel", two new buttons will be hiden.
*/
Void WeAlumni::MemInfoPage::btn_DeleteCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	lbl_error->Visible = false;
	btn_DeleteAccept->Visible = false;
	btn_DeleteCancel->Visible = false;
}

/*
 * dataGridView1_CellContentClick
 * by double clicking specific row of DataGridView1, a corresponding Record Info page will show up.
 */
Void WeAlumni::MemInfoPage::dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e){
	RecInfoPage^ recInfoPage = gcnew RecInfoPage(Convert::ToInt32(dataGridView1->CurrentRow->Cells[0]->Value));
	recInfoPage->ShowDialog();
}

