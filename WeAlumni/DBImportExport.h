#pragma once
#include "Database.h"
#include "DatabasePrecheck.h"
#include "PublicUserInfo.h"
/*
 * DBImportExport.h
 *
 * Import and export database as .zip file
 *
 * @author: Yiyun Zheng
 * Revised: 4/12/20
 *
 */

namespace WeAlumni {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing; 
    using namespace ICSharpCode::SharpZipLib::Zip;

    public ref class DBImportExport {

    private:
        static void UnZipDB(String^);
        static void ZipDB(String^);

    public:
        static bool ImportDatabase(PublicUserInfo^);
        static bool ExportDatabase(PublicUserInfo^);
    };
}