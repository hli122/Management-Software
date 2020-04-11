#include "DatabasePrecheckPrompt.h"

/*
 * DatabasePrecheckPage.cpp
 *
 * This file provide two button for DB Precheck
 *
 * @author: Xiangdong Che
 * Revised: 04/09/20
 *
 */

using namespace System;

/*
 * Initialize
 * This method initialize the prompt with correct text
 * @param None
 * @return None
 */
Void WeAlumni::DatabasePrecheckPrompt::Initialize() {
	exitStatus == false;
	if (_databaseType == DatabaseType::admin) {
		lbl_Prompt->Text = "Import Or Create An admin.db";
	}
	else {
		lbl_Prompt->Text = "Import Or Create An data.db";
	}
}

/*
 * btn_Import_Click
 * This method provide dialog for import
 * @param None
 * @return None
 */
Void WeAlumni::DatabasePrecheckPrompt::btn_Import_Click(System::Object^ sender, System::EventArgs^ e) {
	if (_databaseType == DatabaseType::admin) {
		FileDialog->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);
		FileDialog->Filter = "admin.db|admin.db";
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
Void WeAlumni::DatabasePrecheckPrompt::btn_New_Click(System::Object^ sender, System::EventArgs^ e) {
	Database^ _database = gcnew Database();
	if (_databaseType == DatabaseType::admin) {
		_database->SetDatabaseType(Database::DatabaseType::Admin);
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
Void WeAlumni::DatabasePrecheckPrompt::btn_Exit_Click(System::Object^ sender, System::EventArgs^ e) {
	exitStatus = true;
	this->Close();
}