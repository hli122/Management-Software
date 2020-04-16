#include "StartPage2.h"
#include "MemInfoPage.h"

// Define your own test code
System::Void WeAlumni::StartPage2::btn_jumpToYourPage_Click(System::Object^ sender, System::EventArgs^ e) {
	_pui;// PublicUserInfo should be ready for you

	// WRITE YOUR CODE HERE

	MemInfoPage^ mip = gcnew MemInfoPage(0, _pui);
	mip->Show();
}