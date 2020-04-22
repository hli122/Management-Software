#include "DatabasePrecheck.h"

/*
 * DatabasePrecheck.cpp
 *
 * This file provide two button for DB Precheck
 *
 * @author: Xiangdong Che, Yiyun Zheng
 * Revised: 04/09/20
 *          04/11/20 add check treasury database.
 *	    04/12/20 Combine this file with Prompt file 
 */

using namespace System;

/*
 * Initialize
 * This method initialize the prompt with correct text
 * @param None
 * @return None
 */
Void WeAlumni::DatabasePrecheck::Initialize() {
	exitStatus = false;
	if (_databaseType == DatabaseType::admin) {
		lbl_Prompt->Text = "Import Or Create An admin.db";
	}
	else if (_databaseType == DatabaseType::treasury) {
		lbl_Prompt->Text = "Import Or Create An treasury.db";
	}
	else {
		lbl_Prompt->Text = "Import Or Create An data.db";
	}
}

/*
 * setDatabaseType
 * This method initialize the prompt with correct text
 * @param DatabaseType
 * @return None
 */
Void WeAlumni::DatabasePrecheck::setDatabaseType(DatabaseType type) {
	_databaseType = type;
	Initialize();
}

/*
 * checkFile
 * This method check existence of corresponding file
 * @param None
 * @return None
 */
bool WeAlumni::DatabasePrecheck::checkFile() {
	String^ fileName;
	if (_databaseType == DatabaseType::admin) {
		fileName = "admin.db";
	}
	else if (_databaseType == DatabaseType::data) {
		fileName = "data.db";
	}
	else {
		fileName = "treasury.db";
	}

	return System::IO::File::Exists(fileName);
}



/*
 * loginPrecheck
 * This method start login precheck process
 * @param None
 * @return None
 *
 */
void WeAlumni::DatabasePrecheck::loginPrecheck() {
	DatabasePrecheck^ page = gcnew DatabasePrecheck();
	bool status = false;
	page->setDatabaseType(DatabaseType::admin);

	while (page->checkFile() == false) {
		if (page->exitStatus == false) {
			page->ShowDialog();
		}
		else {
			return;
		}
		status = page->exitStatus;
	}
	page->setDatabaseType(DatabaseType::data);
	while (page->checkFile() == false) {
		if (page->exitStatus == false) {
			page->ShowDialog();
		}
		else {
			return;
		}
		status = page->exitStatus;
	}
	page->~DatabasePrecheck();
}

/*
 * TrePrecheck
 * This method start TrePrecheck
 * @param None
 * @return None
 */
bool WeAlumni::DatabasePrecheck::TrePrecheck() {
	DatabasePrecheck^ page = gcnew DatabasePrecheck(DatabaseType::treasury);
	bool status = false;
	while (page->checkFile() == false) {
		if (page->exitStatus == false) {
			page->ShowDialog();
		}
		else {
			return false;
		}
		status = page->exitStatus;
	}
	return true;
	page->~DatabasePrecheck();
}

/*
 * btn_Import_Click
 * This method provide dialog for import
 * @param None
 * @return None
 */
Void WeAlumni::DatabasePrecheck::btn_Import_Click(System::Object^ sender, System::EventArgs^ e) {
	if (_databaseType == DatabaseType::admin) {
		FileDialog->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
		FileDialog->Filter = "admin.db|admin.db";
		if (FileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			String^ dest = IO::Path::Combine(Environment::CurrentDirectory, IO::Path::GetFileName(FileDialog->FileName));
			IO::File::Copy(FileDialog->FileName, dest);
		}
	}
	else if (_databaseType == DatabaseType::treasury) {
		FileDialog->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
		FileDialog->Filter = "treasury.db|*.DB";
		if (FileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			String^ dest = IO::Path::Combine(Environment::CurrentDirectory, IO::Path::GetFileName(FileDialog->FileName));
			IO::File::Copy(FileDialog->FileName, dest);
		}
	}

	else {
		FileDialog->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
		FileDialog->Filter = "data.db|data.db";
		if (FileDialog->ShowDialog() == Windows::Forms::DialogResult::OK) {
			String^ dest = IO::Path::Combine(Environment::CurrentDirectory, IO::Path::GetFileName(FileDialog->FileName));
			IO::File::Copy(FileDialog->FileName, dest);
		}
	}
	this->Close();
}

/*
 * btn_New_Click
 * This method provide dialog for creating new db file
 * @param None
 * @return None
 */
Void WeAlumni::DatabasePrecheck::btn_New_Click(System::Object^ sender, System::EventArgs^ e) {
	Database^ _database = gcnew Database();
	if (_databaseType == DatabaseType::admin) {
		_database->SetDatabaseType(Database::DatabaseType::Admin);
		_database->CreateDatabaseFile();
	}
	else if (_databaseType == DatabaseType::treasury) {
		_database->SetDatabaseType(Database::DatabaseType::Treasury);
		_database->CreateDatabaseFile();
	}
	else {
		_database->SetDatabaseType(Database::DatabaseType::Data);
		_database->CreateDatabaseFile();
	}
	this->Close();
}

/*
 * btn_Exit_Click
 * This method set exitStatus to true 
 * @param None
 * @return None
 */
Void WeAlumni::DatabasePrecheck::btn_Exit_Click(System::Object^ sender, System::EventArgs^ e) {
	exitStatus = true;
	this->Close();
}

