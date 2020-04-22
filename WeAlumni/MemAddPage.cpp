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
	lbl_成员编号->Text = _id.ToString();
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
		                               _id + ", '" + cmb_成员状态->Text + "', '" +
		                               cmb_成员类型->Text + "', '" + txt_姓名->Text + "', '" +
		                               txt_性别->Text + "', '" + txt_出生日期->Text + "', '" +
		                               txt_Email->Text + "', '" + txt_联系电话->Text + "', '" +
		                               txt_微信号->Text + "', '" + txt_所在国家->Text + "', '" +
	                    	           txt_地址第一行->Text + "', '" + txt_地址第二行->Text + "', '" +
		                               txt_城市->Text + "', '" + txt_邮编->Text + "', '" +
		                               txt_学生编号->Text + "', '" + cmb_学术项目->Text + "', '" +
		                               txt_结束日期->Text + "', '" + cmb_学位->Text + "', '" +
		                               txt_专业一->Text + "', '" + txt_专业二->Text + "', '" +
		                               cmb_就业状态->Text + "', '" + txt_公司->Text + "', '" +
		                               txt_职位->Text + "', '" + cmb_搜索授权->Text + "');";

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
		WeAlumni::Database::Log(_stfId, "Added Member");
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