#include "DBImportExport.h"
/*
 * DBImportExport.cpp
 *
 * Import and export database as .zip file
 *
 * @author: Yiyun Zheng
 * Revised: 4/12/20
 *
 */

 /*
  * UnzipDB
  * Copy zip file without unzip (since admin.db in used)
  * @param String^ Source path
  * @return None
  */
void WeAlumni::DBImportExport::UnZipDB(String^ Source) {
	try {
		System::IO::File::Copy(Source, "updatedDatabase.zip", true);
	}
	catch (Exception^ exception) {
		throw exception;
	}
}

/*
 * ZipDB
 * Zip all DB file into one zip file
 * @param String^ zip file path
 * @return None
 */
void WeAlumni::DBImportExport::ZipDB(String^ dst) {
	try {
		DatabasePrecheck^ file = gcnew DatabasePrecheck();
		ZipFile^ zip = ZipFile::Create(dst);
		zip->BeginUpdate();
		file->setDatabaseType(DatabasePrecheck::DatabaseType::admin);
		if (file->checkFile()) {
			zip->Add("admin.db");
		}
		file->setDatabaseType(DatabasePrecheck::DatabaseType::data);
		if (file->checkFile()) {
			zip->Add("data.db");
		}
		file->setDatabaseType(DatabasePrecheck::DatabaseType::admin);
		if (file->checkFile()) {
			zip->Add("treasury.db");
		}
		zip->CommitUpdate();
		zip->Close();
	}
	catch (Exception^ exception) {
		throw exception;
	}
}

/*
 * ImportDatabase
 * Import selected database zip file
 * @param PublicUserInfo^
 * @return None
 */
bool WeAlumni::DBImportExport::ImportDatabase(PublicUserInfo^) {
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "zip|*.zip";

	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

		try {
			UnZipDB(ofd->FileName);
		}
		catch (Exception^ exception) {
			throw exception;
		}
	}
	else {
		return false;
	}
}

/*
 * EXportDatabase
 * Export DB to selected folder
 * @param PublicUserInfo^
 * @return None
 */
bool WeAlumni::DBImportExport::ExportDatabase(PublicUserInfo^ pui) {
	
	FolderBrowserDialog^ fbd = gcnew FolderBrowserDialog();
	if (fbd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		try {
			String^ zipname = String::Format("{0}_Upload_{1}.zip", pui->GetId(), (gcnew DateTime)->Now.ToString("yyyy-MM-dd"));
			String^ dest = IO::Path::Combine(fbd->SelectedPath, zipname);
			ZipDB(dest);
			return true;

		}
		catch (Exception^ exception) {
			throw exception;
		}
	}
	else
	{
		return false;
	}
}