#pragma once

// uncomment to execute the rk1-utils:
//    #include "rk1_Utils_demo.h"  // shows how the rk1-utils can be used

#include "Header1.h"
#include "Header2.h"


namespace CppCLRWinFormsProject {

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  using namespace System::IO;

  /// <summary>
  /// Summary for Form1
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  public:
    Form1(void)
    {
      InitializeComponent();
      //
      //TODO: Add the constructor code here
      //

      // uncomment to execute the rk1-utils:
      //    N_rk1_Utils_demo::execute(); // shows how the rk1-utils can be used

    }

  protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~Form1()
    {
      if (components)
      {
        delete components;
      }
    }
  private: System::Windows::Forms::RadioButton^ radioButton1;
  protected:
  private: System::Windows::Forms::RadioButton^ radioButton2;
  private: System::Windows::Forms::Label^ label1;
  private: System::Windows::Forms::Button^ button1;
  private: System::Windows::Forms::PictureBox^ picture1;







  protected:





  protected:

  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
        this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
        this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
        this->label1 = (gcnew System::Windows::Forms::Label());
        this->button1 = (gcnew System::Windows::Forms::Button());
        this->picture1 = (gcnew System::Windows::Forms::PictureBox());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture1))->BeginInit();
        this->SuspendLayout();
        // 
        // radioButton1
        // 
        this->radioButton1->BackColor = System::Drawing::SystemColors::ControlLight;
        this->radioButton1->Location = System::Drawing::Point(12, 60);
        this->radioButton1->Name = L"radioButton1";
        this->radioButton1->Size = System::Drawing::Size(133, 46);
        this->radioButton1->TabIndex = 0;
        this->radioButton1->TabStop = true;
        this->radioButton1->Text = L"C++";
        this->radioButton1->UseVisualStyleBackColor = false;
        this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
        // 
        // radioButton2
        // 
        this->radioButton2->BackColor = System::Drawing::SystemColors::ControlLight;
        this->radioButton2->Location = System::Drawing::Point(174, 60);
        this->radioButton2->Name = L"radioButton2";
        this->radioButton2->Size = System::Drawing::Size(133, 46);
        this->radioButton2->TabIndex = 1;
        this->radioButton2->TabStop = true;
        this->radioButton2->Text = L"ASM";
        this->radioButton2->UseVisualStyleBackColor = false;
        this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
        // 
        // label1
        // 
        this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label1->Location = System::Drawing::Point(40, 23);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(229, 34);
        this->label1->TabIndex = 2;
        this->label1->Text = L"Wybierz biblioteke";
        this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // button1
        // 
        this->button1->Location = System::Drawing::Point(361, 60);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(138, 46);
        this->button1->TabIndex = 3;
        this->button1->Text = L"Open file";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
        // 
        // picture1
        // 
        this->picture1->Location = System::Drawing::Point(12, 223);
        this->picture1->Name = L"picture1";
        this->picture1->Size = System::Drawing::Size(295, 213);
        this->picture1->TabIndex = 4;
        this->picture1->TabStop = false;
        this->picture1->Click += gcnew System::EventHandler(this, &Form1::pictureBox1_Click);
        
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(793, 498);
        this->Controls->Add(this->picture1);
        this->Controls->Add(this->button1);
        this->Controls->Add(this->label1);
        this->Controls->Add(this->radioButton2);
        this->Controls->Add(this->radioButton1);
        this->Margin = System::Windows::Forms::Padding(4);
        this->Name = L"Form1";
        this->Text = L"Form1";
        this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture1))->EndInit();
        this->ResumeLayout(false);

    }
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.




  private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void C_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
      //DO ZROBIENIA
      int number = 15;

  }
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (radioButton2->Checked) {
        // DO ZROBIENIA
        int number = 10;
    }
}


      

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    Stream^ myStream;
    OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
    openFileDialog1->InitialDirectory = "c:\\";
    openFileDialog1->Filter = "bmp files (*.bmp)|*.bmp";
    openFileDialog1->FilterIndex = 2;
    openFileDialog1->RestoreDirectory = true;

    if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {
        if ((myStream = openFileDialog1->OpenFile()) != nullptr) {


             this->picture1->ImageLocation = openFileDialog1->FileName;
             System::Drawing::Bitmap::FromFile(this->picture1->ImageLocation);
            myStream->Close();
            
           
            
        }
    }
}

private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {

}


}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

