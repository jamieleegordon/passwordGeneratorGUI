#pragma once
#include <cstdlib>
#include <ctime>
#include <string>


namespace passwordGeneratorGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ numCharLabel;
	protected:

	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::Button^ generateButton;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ checkBox1;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numCharLabel = (gcnew System::Windows::Forms::TextBox());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"How many characters do you need\?";
			// 
			// numCharLabel
			// 
			this->numCharLabel->Location = System::Drawing::Point(206, 39);
			this->numCharLabel->Name = L"numCharLabel";
			this->numCharLabel->Size = System::Drawing::Size(100, 20);
			this->numCharLabel->TabIndex = 1;
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Cursor = System::Windows::Forms::Cursors::Default;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordLabel->Location = System::Drawing::Point(130, 156);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(0, 42);
			this->passwordLabel->TabIndex = 2;
			this->passwordLabel->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// generateButton
			// 
			this->generateButton->Location = System::Drawing::Point(338, 52);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(75, 23);
			this->generateButton->TabIndex = 3;
			this->generateButton->Text = L"Generate";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &MyForm::generateButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Include special characters\?";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(206, 77);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 5;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(471, 261);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->generateButton);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->numCharLabel);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Password generator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool isChecked = false;
	// function that converts system string to a standard string
	static std::string toStandardString(System::String^ string)
	{
		using System::Runtime::InteropServices::Marshal;
		System::IntPtr pointer = Marshal::StringToHGlobalAnsi(string);
		char* charPointer = reinterpret_cast<char*>(pointer.ToPointer());
		std::string returnString(charPointer, string->Length);
		Marshal::FreeHGlobal(pointer);
		return returnString;
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		isChecked = true;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void generateButton_Click(System::Object^ sender, System::EventArgs^ e) {

		std::string num = toStandardString(numCharLabel->Text);

		int numInt = stoi(num);

		srand(time(0)); // makes sure the numbers are always random and not the same every time

		String^ s = numCharLabel->Text;

		std::string password = ""; // final generated password

		std::string str;
		String^ str2;

		for (int i = 0; i < numInt; i++) {

			int asciiVal;
			int v = rand() % 3;

			int asciiValLower = (97 + (rand() % 26));
			int asciiValUpper = (65 + (rand() % 26));
			int asciiValNum = (48 + (rand() % 10));
			
			if (v == 0) {
				asciiVal = asciiValLower; // will asign random lowercase letter
			}
			else if (v == 1) {
				asciiVal = asciiValUpper; // will asign random uppercase letter
			}
			else if (v == 2) {
				asciiVal = asciiValNum; // will asign random number
			}
			
			char x = char(asciiVal); // get the character version of that ascii value

			str.push_back(x); // convert to a string
			
			password = password + str; // add to end of password string
		}

		if (isChecked) {
			for (int i = 0; i < numInt; i++) {

				int asciiVal;
				int v = rand() % 4;

				int asciiValLower = (97 + (rand() % 26));
				int asciiValUpper = (65 + (rand() % 26));
				int asciiValNum = (48 + (rand() % 10));
				int asciiValChar = (33 + (rand() % 15));

				if (v == 0) {
					asciiVal = asciiValLower; 
				}
				else if (v == 1) {
					asciiVal = asciiValUpper; 
				}
				else if (v == 2) {
					asciiVal = asciiValNum; 
				}
				else if (v == 3) {
					asciiVal = asciiValChar;
				}

				char x = char(asciiVal); 

				str.push_back(x); 

				password = password + str; 
			}
		}

		str2 = gcnew String(str.c_str()); // change the std::String into String^ (system string)
		passwordLabel->Text = str2; // display generated password
	}
};
}
