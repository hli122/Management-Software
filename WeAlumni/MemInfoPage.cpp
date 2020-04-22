#include "MemInfoPage.h"

/*
 * MemInfoPage.cpp
 *
 * This file implements all MemInfoPage interfaces.
 *
 * @author: Jiaying Hou
 * Revised: 4/1/20
 *          4/4/20 UI and bug fixes
 *          4/12/20 auth control added
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
		if (_auth == PublicUserInfo::Auth::Level_2) {
			database = gcnew Database(Database::DatabaseType::Data, true);
		}
		else {
			database = gcnew Database(Database::DatabaseType::Data);
		}
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
		lbl_成员编号->Text = _id.ToString();
		lbl_成员状态->Text = database->dataReader[1]->ToString();
		lbl_成员类型->Text = database->dataReader[2]->ToString();
		lbl_姓名->Text = database->dataReader[3]->ToString();
		lbl_性别->Text = database->dataReader[4]->ToString();
		lbl_出生日期->Text = database->dataReader[5]->ToString();
		lbl_Email->Text = database->dataReader[6]->ToString();
		lbl_联系电话->Text = database->dataReader[7]->ToString();
		lbl_微信号->Text = database->dataReader[8]->ToString();
		lbl_所在国家->Text = database->dataReader[9]->ToString();
		lbl_地址第一行->Text = database->dataReader[10]->ToString();
		lbl_地址第二行->Text = database->dataReader[11]->ToString();
		lbl_城市->Text = database->dataReader[12]->ToString();
		lbl_邮编->Text = database->dataReader[13]->ToString();
		lbl_学生编号->Text = database->dataReader[14]->ToString();
		lbl_学术项目->Text = database->dataReader[15]->ToString();
		lbl_结束日期->Text = database->dataReader[16]->ToString();
		lbl_学位->Text = database->dataReader[17]->ToString();
		lbl_专业一->Text = database->dataReader[18]->ToString();
		lbl_专业二->Text = database->dataReader[19]->ToString();
		lbl_就业状态->Text = database->dataReader[20]->ToString();
		lbl_公司->Text = database->dataReader[21]->ToString();
		lbl_职位->Text = database->dataReader[22]->ToString();
		lbl_搜索授权->Text = database->dataReader[23]->ToString();

		cmb_成员状态->Text = database->dataReader[1]->ToString();
		cmb_成员类型->Text = database->dataReader[2]->ToString();
		txt_姓名->Text = database->dataReader[3]->ToString();
		txt_性别->Text = database->dataReader[4]->ToString();
		txt_出生日期->Text = database->dataReader[5]->ToString();
		txt_Email->Text = database->dataReader[6]->ToString();
		txt_联系电话->Text = database->dataReader[7]->ToString();
		txt_微信号->Text = database->dataReader[8]->ToString();
		txt_所在国家->Text = database->dataReader[9]->ToString();
		txt_地址第一行->Text = database->dataReader[10]->ToString();
		txt_地址第二行->Text = database->dataReader[11]->ToString();
		txt_城市->Text = database->dataReader[12]->ToString();
		txt_邮编->Text = database->dataReader[13]->ToString();
		txt_学生编号->Text = database->dataReader[14]->ToString();
		cmb_学术项目->Text = database->dataReader[15]->ToString();
		txt_结束日期->Text = database->dataReader[16]->ToString();
		cmb_学位->Text = database->dataReader[17]->ToString();
		txt_专业一->Text = database->dataReader[18]->ToString();
		txt_专业二->Text = database->dataReader[19]->ToString();
		cmb_就业状态->Text = database->dataReader[20]->ToString();
		txt_公司->Text = database->dataReader[21]->ToString();
		txt_职位->Text = database->dataReader[22]->ToString();
		cmb_搜索授权->Text = database->dataReader[23]->ToString();
		if (_auth == PublicUserInfo::Auth::Level_2) {
			Level2Display();
		}
		else if (_auth == PublicUserInfo::Auth::Level_3) {
			Level3Display();
		}
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
	if (_auth == PublicUserInfo::Auth::Level_3) {
		Level3Display();
		cmb_成员状态->Visible = true;
		cmb_成员类型->Visible = true;
		txt_姓名->Visible = true;
		txt_Email->Visible = true;
		txt_所在国家->Visible = true;
		txt_地址第一行->Visible = true;
		txt_地址第二行->Visible = true;
		txt_城市->Visible = true;
		txt_邮编->Visible = true;
		cmb_学术项目->Visible = true;
		txt_结束日期->Visible = true;
		cmb_学位->Visible = true;
		txt_专业一->Visible = true;
		txt_专业二->Visible = true;
		cmb_就业状态->Visible = true;
		txt_公司->Visible = true;
		txt_职位->Visible = true;
		cmb_搜索授权->Visible = true;
		btn_确认编辑->Visible = true;
		btn_取消编辑->Visible = true;
		lbl_error->Visible = false;
	}
	else {
		cmb_成员状态->Visible = true;
		cmb_成员类型->Visible = true;
		txt_姓名->Visible = true;
		txt_性别->Visible = true;
		txt_出生日期->Visible = true;
		txt_Email->Visible = true;
		txt_联系电话->Visible = true;
		txt_微信号->Visible = true;
		txt_所在国家->Visible = true;
		txt_地址第一行->Visible = true;
		txt_地址第二行->Visible = true;
		txt_城市->Visible = true;
		txt_邮编->Visible = true;
		txt_学生编号->Visible = true;
		cmb_学术项目->Visible = true;
		txt_结束日期->Visible = true;
		cmb_学位->Visible = true;
		txt_专业一->Visible = true;
		txt_专业二->Visible = true;
		cmb_就业状态->Visible = true;
		txt_公司->Visible = true;
		txt_职位->Visible = true;
		cmb_搜索授权->Visible = true;
		btn_确认编辑->Visible = true;
		btn_取消编辑->Visible = true;
		lbl_error->Visible = false;
	}
}

/*
* btn_Delete_Click
* When click button "删除信息", two buttons will show up
*/
Void WeAlumni::MemInfoPage::btn_Delete_Click(System::Object^ sender, System::EventArgs^ e) {
	lbl_error->Visible = false;
	btn_取消删除->Visible = true;
	btn_确认删除->Visible = true;
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
	String^ command = "SELECT Record.Id AS '记录编号', " +
		"Record.Time AS '登记时间', " +
		"Staff.Position AS '职位职务', " +
		"Record.StfId AS '员工编号', " +
		"Record.Action AS '操作内容', " +
		"Member.Name AS '员工姓名', " +
		"Staff.Dept AS '所在部门' " +
		"FROM Record, Member, Staff " +
		"WHERE Record.MemId = " + _id +
		" AND Record.StfId = Staff.MemId AND Member.Id = Staff.MemId;";

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
		      "SET Status = '" + cmb_成员状态->Text + "', " +
			  "Type = '" + cmb_成员类型->Text + "', " +
			  "Name = '" + txt_姓名->Text + "', " +
			  "Gender = '" + txt_性别->Text + "', " +
			  "Birth = '" + txt_出生日期->Text + "', " +
			  "Email = '" + txt_Email->Text + "', " +
			  "Phone = '" + txt_联系电话->Text + "', " +
			  "Wechat = '" + txt_微信号->Text + "', " +
			  "Country = '" + txt_所在国家->Text + "', " +
			  "Address1 = '" + txt_地址第一行->Text + "', " +
			  "Address2 = '" + txt_地址第二行->Text + "', " +
			  "City = '" + txt_城市->Text + "', " +
			  "Postal = '" + txt_邮编->Text + "', " +
		      "StdId = '" + txt_学生编号->Text + "', " +
			  "Program = '" + cmb_学术项目->Text + "', " +
		      "EndDate = '" + txt_结束日期->Text + "', " +
			  "Degree = '" + cmb_学位->Text + "', " +
			  "Major1 = '" + txt_专业一->Text + "', " +
			  "Major2 = '" + txt_专业二->Text + "', " +
			  "CareerStatus = '" + cmb_就业状态->Text + "', " +
			  "Company = '" + txt_公司->Text + "', " +
			  "Position = '" + txt_职位->Text + "', " +
			  "SearchAuth = '" + cmb_搜索授权->Text + "' " +
		      "WHERE Id = " + _id;
	
	int status = -1;
	String^ logParam = _stfId.ToString() + " 编辑成员 " + _id.ToString() + " 信息:";
	try {
		status = database->UpdateData(cmd);
	}
	catch (Exception^ exception) {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return;
	}
	int first = 1;
	if (status > 0) {
		if (lbl_成员状态->Text != cmb_成员状态->Text) {
			lbl_成员状态->Text = cmb_成员状态->Text;
			logParam = logParam + " 成员状态";
			first = 0;
		}
		if (lbl_成员类型->Text != cmb_成员类型->Text) {
			lbl_成员类型->Text = cmb_成员类型->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 成员类型";
		}
		if (lbl_姓名->Text != txt_姓名->Text) {
			lbl_姓名->Text = txt_姓名->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 姓名";
		}
		if (lbl_性别->Text != txt_性别->Text) {
			lbl_性别->Text = txt_性别->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 性别";
		}
		if (lbl_出生日期->Text != txt_出生日期->Text) {
			lbl_出生日期->Text = txt_出生日期->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 出生日期";
		}
		if (lbl_Email->Text != txt_Email->Text) {
			lbl_Email->Text = txt_Email->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " Email";
		}
		if (lbl_联系电话->Text != txt_联系电话->Text) {
			lbl_联系电话->Text = txt_联系电话->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 联系电话";
		}
		if (lbl_微信号->Text != txt_微信号->Text) {
			lbl_微信号->Text = txt_微信号->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 微信号";
		}
		if (lbl_所在国家->Text != txt_所在国家->Text) {
			lbl_所在国家->Text = txt_所在国家->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 所在国家";
		}
		if (lbl_地址第一行->Text != txt_地址第一行->Text) {
			lbl_地址第一行->Text = txt_地址第一行->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + "地址第一行";
		}
		if (lbl_地址第二行->Text != txt_地址第二行->Text) {
			lbl_地址第二行->Text = txt_地址第二行->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 地址第二行";
		}
		if (lbl_城市->Text != txt_城市->Text) {
			lbl_城市->Text = txt_城市->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 城市";
		}
		if (lbl_邮编->Text != txt_邮编->Text) {
			lbl_邮编->Text = txt_邮编->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 邮编";
		}
		if (lbl_学生编号->Text != txt_学生编号->Text) {
			lbl_学生编号->Text = txt_学生编号->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 学生编号";
		}
		if (lbl_学术项目->Text != cmb_学术项目->Text) {
			lbl_学术项目->Text = cmb_学术项目->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 学术项目";
		}
		if (lbl_结束日期->Text != txt_结束日期->Text) {
			lbl_结束日期->Text = txt_结束日期->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 结束日期";
		}
		if (lbl_学位->Text != cmb_学位->Text) {
			lbl_学位->Text = cmb_学位->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 学位";
		}
		if (lbl_专业一->Text != txt_专业一->Text) {
			lbl_专业一->Text = txt_专业一->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam +  " 专业一";
		}
		if (lbl_专业二->Text != txt_专业二->Text) {
			lbl_专业二->Text = txt_专业二->Text;
			if (first = 0)logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 专业二";
		}
		if (lbl_就业状态->Text != cmb_就业状态->Text) {
			lbl_就业状态->Text = cmb_就业状态->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 就业状态";
		}
		if (lbl_公司->Text != txt_公司->Text) {
			lbl_公司->Text = txt_公司->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 公司";
		}
		if (lbl_职位->Text != txt_职位->Text) {
			lbl_职位->Text = txt_职位->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 职位";
		}
		if (lbl_搜索授权->Text != cmb_搜索授权->Text) {
			lbl_搜索授权->Text = cmb_搜索授权->Text;
			if (first = 0) logParam = logParam + ",";
			first = 0;
			logParam = logParam + " 搜索授权";
		}

		cmb_成员状态->Visible = false;
		cmb_成员类型->Visible = false;
		txt_姓名->Visible = false;
		txt_性别->Visible = false;
		txt_出生日期->Visible = false;
		txt_Email->Visible = false;
		txt_联系电话->Visible = false;
		txt_微信号->Visible = false;
		txt_所在国家->Visible = false;
		txt_地址第一行->Visible = false;
		txt_地址第二行->Visible = false;
		txt_城市->Visible = false;
		txt_邮编->Visible = false;
		txt_学生编号->Visible = false;
		cmb_学术项目->Visible = false;
		txt_结束日期->Visible = false;
		cmb_学位->Visible = false;
		txt_专业一->Visible = false;
		txt_专业二->Visible = false;
		cmb_就业状态->Visible = false;
		txt_公司->Visible = false;
		txt_职位->Visible = false;
		cmb_搜索授权->Visible = false;
		btn_确认编辑->Visible = false;
		btn_取消编辑->Visible = false;
		lbl_error->Text = "Changes saved";
		lbl_error->ForeColor = System::Drawing::Color::Green;
		lbl_error->Visible = true;
		if (first == 0) {
			WeAlumni::Database::Log(_stfId, logParam);
			InsertRecord(logParam);
			UpdateRecord();
		}
	}
	else {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = "Error occured";
		lbl_error->Visible = true;
	}
}

/*
* insertRecord
* This method will try to insert data into Record table.
* @param String^ action
* @return None
*/
Void WeAlumni::MemInfoPage::InsertRecord(String^ action) {
	int recId = database->GetNextId(WeAlumni::Database::DatabaseTable::Record);
	String^ currTime = database->GetSystemTime();
	String^ cmd = "INSERT INTO Record (Id, StfId, MemId, Time, Action) " +
		"VALUES (" + recId + ", " + _stfId + ", " + _id +
		", '" + currTime + "', '" + action + "');";

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
}

/*
* btn_ChangeInfoCancelButton_Click
* When click button "Cancel", go back to previous MemInfoPage, nothing changes
*/
Void WeAlumni::MemInfoPage::btn_ChangeInfoCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	lbl_error->Visible = false;
	cmb_成员状态->Visible = false;
	cmb_成员类型->Visible = false;
	txt_姓名->Visible = false;
	txt_性别->Visible = false;
	txt_出生日期->Visible = false;
	txt_Email->Visible = false;
	txt_联系电话->Visible = false;
	txt_微信号->Visible = false;
	txt_所在国家->Visible = false;
	txt_地址第一行->Visible = false;
	txt_地址第二行->Visible = false;
	txt_城市->Visible = false;
	txt_邮编->Visible = false;
	txt_学生编号->Visible = false;
	cmb_学术项目->Visible = false;
	txt_结束日期->Visible = false;
	cmb_学位->Visible = false;
	txt_专业一->Visible = false;
	txt_专业二->Visible = false;
	cmb_就业状态->Visible = false;
	txt_公司->Visible = false;
	txt_职位->Visible = false;
	cmb_搜索授权->Visible = false;
	btn_确认编辑->Visible = false;
	btn_取消编辑->Visible = false;

	cmb_成员状态->Text = lbl_成员状态->Text;
	cmb_成员类型->Text = lbl_成员类型->Text;
	txt_姓名->Text = lbl_姓名->Text;
	txt_性别->Text = lbl_性别->Text;
	txt_出生日期->Text = lbl_出生日期->Text;
	txt_Email->Text = lbl_Email->Text;
	txt_联系电话->Text = lbl_联系电话->Text;
	txt_微信号->Text = lbl_微信号->Text;
	txt_所在国家->Text = lbl_所在国家->Text;
	txt_地址第一行->Text = lbl_地址第一行->Text;
	txt_地址第二行->Text = lbl_地址第二行->Text;
	txt_城市->Text = lbl_城市->Text;
	txt_邮编->Text = lbl_邮编->Text;
	txt_学生编号->Text = lbl_学生编号->Text;
	cmb_学术项目->Text = lbl_学术项目->Text;
	txt_结束日期->Text = lbl_结束日期->Text;
	cmb_学位->Text = lbl_学位->Text;
	txt_专业一->Text = lbl_专业一->Text;
	txt_专业二->Text = lbl_专业二->Text;
	cmb_就业状态->Text = lbl_就业状态->Text;
	txt_公司->Text = lbl_公司->Text;
	txt_职位->Text = lbl_职位->Text;
	cmb_搜索授权->Text = lbl_搜索授权->Text;
}

/*
* btn_DeleteAccept_Click
*
* When click button "确认:, the method will trigger a delete command.
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
		btn_确认删除->Visible = false;
		btn_取消删除->Visible = false;
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return;
	}
	
	if (status > 0) {
		DeleteRecord();
		WeAlumni::Database::Log(_stfId, "删除成员");
		this->Close();
	}	
	else {
		btn_确认删除->Visible = false;
		btn_取消删除->Visible = false;
		lbl_error->Visible = true;
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = "Error occured";
	}
}

/*
* DeleteRecord
*
* This method delete the corresponding record when a member is being deleted. 
* @param none
* @return none
*/
Void WeAlumni::MemInfoPage::DeleteRecord() {
	int status = -1;
	String^ cmd = "DELETE FROM RECORD WHERE MemId = " + _id;

	try {
		status = database->DeleteData(cmd);
	}
	catch (Exception^ exception) {
		lbl_error->ForeColor = System::Drawing::Color::Red;
		lbl_error->Text = exception->Message;
		lbl_error->Visible = true;
		return;
	}
}

/*
* btn_DeleteCancel_Click
* When click button "Cancel", two new buttons will be hiden.
*/
Void WeAlumni::MemInfoPage::btn_DeleteCancel_Click(System::Object^ sender, System::EventArgs^ e) {
	lbl_error->Visible = false;
	btn_确认删除->Visible = false;
	btn_取消删除->Visible = false;
}

/*
 * dataGridView1_CellContentClick
 * by double clicking specific row of DataGridView1, a corresponding Record Info page will show up.
 */
Void WeAlumni::MemInfoPage::dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e){
	RecInfoPage^ recInfoPage = gcnew RecInfoPage(Convert::ToInt32(dataGridView1->CurrentRow->Cells[0]->Value));
	recInfoPage->ShowDialog();
}

/*
* Level2Display
*
* This method set labels and buttons visibility to false for auth control
* @param none
* @return none
*/
Void WeAlumni::MemInfoPage::Level2Display() {
	lbl_性别->Visible = false;
	lbl_出生日期->Visible = false;
	lbl_联系电话->Visible = false;
	lbl_微信号->Visible = false;
	lbl_所在国家->Visible = false;
	lbl_地址第一行->Visible = false;
	lbl_地址第二行->Visible = false;
	lbl_城市->Visible = false;
	lbl_邮编->Visible = false;
	lbl_学生编号->Visible = false;
	
	lbl_Prompt_性别->Visible = false;
	lbl_Prompt_出生日期->Visible = false;
	lbl_Prompt_联系电话->Visible = false;
	lbl_Prompt_微信号->Visible = false;
	lbl_Prompt_所在国家->Visible = false;
	lbl_Prompt_地址第一行->Visible = false;
	lbl_Prompt_地址第二行->Visible = false;
	lbl_Prompt_城市->Visible = false;
	lbl_Prompt_邮编->Visible = false;
	lbl_Prompt_学生编号->Visible = false;
	btn_编辑信息->Visible = false;
	btn_删除信息->Visible = false;
}

/*
* Level3Display
*
* This method set labels, txt boxts visibility to false for auth control
* @param none
* @return none
*/
Void WeAlumni::MemInfoPage::Level3Display() {
	lbl_性别->Visible = false;
	lbl_出生日期->Visible = false;
	lbl_联系电话->Visible = false;
	lbl_微信号->Visible = false;
	lbl_学生编号->Visible = false;

	lbl_Prompt_性别->Visible = false;
	lbl_Prompt_出生日期->Visible = false;
	lbl_Prompt_联系电话->Visible = false;
	lbl_Prompt_微信号->Visible = false;
	lbl_Prompt_学生编号->Visible = false;

	txt_性别->Visible = false;
	txt_出生日期->Visible = false;
	txt_联系电话->Visible = false;
	txt_微信号->Visible = false;
	txt_学生编号->Visible = false;
}
