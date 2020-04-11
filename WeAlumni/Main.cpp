#include "StartPage.h"
#include "StartPage2.h"

/*
 * Main.cpp
 *
 * This file includes Main function as the entry point.
 *
 * @author: Hang Yuan
 * Revised: 3/21/20
 *
 */

/*
* Application-Entry Page, including a Main method to raise the StarterPage.
*/
System::Void Main(array<System::String^>^ args)
{
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

    WeAlumni::StartPage2 start_page;
    System::Windows::Forms::Application::Run(% start_page);
}