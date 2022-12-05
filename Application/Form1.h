#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include "cppAlg.h"
#include "Utility.h"
#include "startAsm.h"
#pragma warning(disable : 4996)








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

      //max number of threads
      this->maxNumbOfThreads = 64;
      this->label9->Text = this->maxNumbOfThreads.ToString();
      this->isLoaded = false;
      this->numberOfThreads = 1;
      this->contrastRatio = 0;
      this->libraryFlag = false;

      
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
  private: System::Windows::Forms::PictureBox^ picture2;
  private: System::Windows::Forms::Button^ startButton;

  private: System::Windows::Forms::TrackBar^ trackBar1;

  private: bool libraryFlag; // flaga kontrolujaca wybor bilbioteki (true = C++, fakse = ASM)
  private: int contrastRatio;// wspolczynnik kontrastu
  private: int maxNumbOfThreads;// maksymalna ilosc watkow komputera
  private: int numberOfThreads; // ilosc watkow wybierana w programie
  private: bool isLoaded; // flaga sterujaca czy plik zostal wczytany poprawnie
  private: double time; // czas wykonania funkcji 
  private: System::String^ path;// sciezka do pliku 
  private: System::Windows::Forms::Label^ label2;
  private: System::Windows::Forms::Label^ label3;
  private: System::Windows::Forms::Label^ label4;
  private: System::Windows::Forms::Label^ label5;
  private: System::Windows::Forms::Label^ label6;
  private: System::Windows::Forms::TrackBar^ trackBar2;
  private: System::Windows::Forms::Label^ label7;
  private: System::Windows::Forms::Label^ label8;
  private: System::Windows::Forms::Label^ label9;
  private: System::Windows::Forms::Label^ label10;
  private: System::Windows::Forms::Label^ label11;







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
        this->picture2 = (gcnew System::Windows::Forms::PictureBox());
        this->startButton = (gcnew System::Windows::Forms::Button());
        this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
        this->label2 = (gcnew System::Windows::Forms::Label());
        this->label3 = (gcnew System::Windows::Forms::Label());
        this->label4 = (gcnew System::Windows::Forms::Label());
        this->label5 = (gcnew System::Windows::Forms::Label());
        this->label6 = (gcnew System::Windows::Forms::Label());
        this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
        this->label7 = (gcnew System::Windows::Forms::Label());
        this->label8 = (gcnew System::Windows::Forms::Label());
        this->label9 = (gcnew System::Windows::Forms::Label());
        this->label10 = (gcnew System::Windows::Forms::Label());
        this->label11 = (gcnew System::Windows::Forms::Label());
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture1))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture2))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
        this->SuspendLayout();
        // 
        // radioButton1
        // 
        this->radioButton1->BackColor = System::Drawing::SystemColors::ControlLight;
        this->radioButton1->Location = System::Drawing::Point(85, 60);
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
        this->radioButton2->Location = System::Drawing::Point(287, 60);
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
        this->label1->Location = System::Drawing::Point(140, 23);
        this->label1->Name = L"label1";
        this->label1->Size = System::Drawing::Size(229, 34);
        this->label1->TabIndex = 2;
        this->label1->Text = L"Wybierz biblioteke";
        this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // button1
        // 
        this->button1->Location = System::Drawing::Point(563, 60);
        this->button1->Name = L"button1";
        this->button1->Size = System::Drawing::Size(269, 46);
        this->button1->TabIndex = 3;
        this->button1->Text = L"Wybierz plik";
        this->button1->UseVisualStyleBackColor = true;
        this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
        // 
        // picture1
        // 
        this->picture1->Location = System::Drawing::Point(44, 143);
        this->picture1->Name = L"picture1";
        this->picture1->Size = System::Drawing::Size(394, 306);
        this->picture1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        this->picture1->TabIndex = 4;
        this->picture1->TabStop = false;
        // 
        // picture2
        // 
        this->picture2->Location = System::Drawing::Point(494, 143);
        this->picture2->Name = L"picture2";
        this->picture2->Size = System::Drawing::Size(394, 306);
        this->picture2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
        this->picture2->TabIndex = 5;
        this->picture2->TabStop = false;
        // 
        // startButton
        // 
        this->startButton->Location = System::Drawing::Point(345, 613);
        this->startButton->Name = L"startButton";
        this->startButton->Size = System::Drawing::Size(195, 58);
        this->startButton->TabIndex = 6;
        this->startButton->Text = L"Start";
        this->startButton->UseVisualStyleBackColor = true;
        this->startButton->Click += gcnew System::EventHandler(this, &Form1::startButton_Click);
        // 
        // trackBar1
        // 
        this->trackBar1->AutoSize = false;
        this->trackBar1->BackColor = System::Drawing::SystemColors::Control;
        this->trackBar1->Location = System::Drawing::Point(481, 511);
        this->trackBar1->Maximum = 255;
        this->trackBar1->Minimum = -255;
        this->trackBar1->Name = L"trackBar1";
        this->trackBar1->Size = System::Drawing::Size(407, 65);
        this->trackBar1->TabIndex = 7;
        this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
        // 
        // label2
        // 
        this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label2->Location = System::Drawing::Point(657, 563);
        this->label2->Name = L"label2";
        this->label2->Size = System::Drawing::Size(58, 30);
        this->label2->TabIndex = 8;
        this->label2->Text = L"0";
        this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // label3
        // 
        this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label3->Location = System::Drawing::Point(477, 550);
        this->label3->Name = L"label3";
        this->label3->Size = System::Drawing::Size(55, 26);
        this->label3->TabIndex = 9;
        this->label3->Text = L"-255";
        // 
        // label4
        // 
        this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label4->Location = System::Drawing::Point(844, 550);
        this->label4->Name = L"label4";
        this->label4->Size = System::Drawing::Size(44, 26);
        this->label4->TabIndex = 10;
        this->label4->Text = L"255";
        // 
        // label5
        // 
        this->label5->BackColor = System::Drawing::SystemColors::ControlLight;
        this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label5->Location = System::Drawing::Point(494, 472);
        this->label5->Name = L"label5";
        this->label5->Size = System::Drawing::Size(394, 24);
        this->label5->TabIndex = 11;
        this->label5->Text = L"Wspó³czynnik kontrastu";
        this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // label6
        // 
        this->label6->BackColor = System::Drawing::SystemColors::ControlLight;
        this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label6->Location = System::Drawing::Point(44, 472);
        this->label6->Name = L"label6";
        this->label6->Size = System::Drawing::Size(394, 24);
        this->label6->TabIndex = 12;
        this->label6->Text = L"Iloœæ w¹tków";
        this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // trackBar2
        // 
        this->trackBar2->Location = System::Drawing::Point(102, 520);
        this->trackBar2->Maximum = 6;
        this->trackBar2->Minimum = 1;
        this->trackBar2->Name = L"trackBar2";
        this->trackBar2->Size = System::Drawing::Size(298, 56);
        this->trackBar2->TabIndex = 13;
        this->trackBar2->Value = 1;
        this->trackBar2->Scroll += gcnew System::EventHandler(this, &Form1::trackBar2_Scroll);
        // 
        // label7
        // 
        this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label7->Location = System::Drawing::Point(99, 555);
        this->label7->Name = L"label7";
        this->label7->Size = System::Drawing::Size(55, 26);
        this->label7->TabIndex = 14;
        this->label7->Text = L"1";
        // 
        // label8
        // 
        this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label8->Location = System::Drawing::Point(223, 565);
        this->label8->Name = L"label8";
        this->label8->Size = System::Drawing::Size(55, 26);
        this->label8->TabIndex = 15;
        this->label8->Text = L"1";
        this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // label9
        // 
        this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label9->Location = System::Drawing::Point(356, 555);
        this->label9->Name = L"label9";
        this->label9->Size = System::Drawing::Size(55, 26);
        this->label9->TabIndex = 16;
        this->label9->Text = L"label9";
        // 
        // label10
        // 
        this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label10->Location = System::Drawing::Point(658, 634);
        this->label10->Name = L"label10";
        this->label10->Size = System::Drawing::Size(156, 37);
        this->label10->TabIndex = 17;
        this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // label11
        // 
        this->label11->BackColor = System::Drawing::SystemColors::ControlLight;
        this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
            static_cast<System::Byte>(238)));
        this->label11->Location = System::Drawing::Point(608, 605);
        this->label11->Name = L"label11";
        this->label11->Size = System::Drawing::Size(266, 29);
        this->label11->TabIndex = 18;
        this->label11->Text = L"Czas wykonania programu";
        this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        // 
        // Form1
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(911, 703);
        this->Controls->Add(this->label11);
        this->Controls->Add(this->label10);
        this->Controls->Add(this->label9);
        this->Controls->Add(this->label8);
        this->Controls->Add(this->label7);
        this->Controls->Add(this->trackBar2);
        this->Controls->Add(this->label6);
        this->Controls->Add(this->label5);
        this->Controls->Add(this->label4);
        this->Controls->Add(this->label3);
        this->Controls->Add(this->label2);
        this->Controls->Add(this->trackBar1);
        this->Controls->Add(this->startButton);
        this->Controls->Add(this->picture2);
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
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture2))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
        (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
        this->ResumeLayout(false);
        this->PerformLayout();

    }
#pragma endregion

   // You can call the functions at a button click. If you prefer, 
    // you can call them by clicking a menu item.




  private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void C_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
  }
  private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
      
      this->libraryFlag = false;

  }
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    if (radioButton2->Checked) {
        
        this->libraryFlag = true;
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

            std::string path2;
            this->path = openFileDialog1->FileName;
            MarshalString(this->path, path2);
                 
              char header[54]; // 54 bitowy header
              FILE* input = fopen(path2.c_str(), "rb");
              
              fread(header, 1, 54, input); // wczytanie naglowka bitmapy
              int bitPerPix = *(int*)(header + 28); // pobranie formatu bitmapy
              int comp = *(int*)(header + 30); // pobranie metody kompresji

              if (bitPerPix == 24 || comp == 0 ) {

                 
                 
                  this->picture1->ImageLocation = openFileDialog1->FileName;// wyswietlanie oryginalnego obrazu
                  this->picture2->ImageLocation = openFileDialog1->FileName; // wyswietlanie przerabianego obrazu
                  this->isLoaded = true; // obraz prawidlowy i wczytany
               
              }

              else {
                
                  MessageBox::Show("Invalid format of bitmap. Try with different bmp file.", "Error",
                      System::Windows::Forms::MessageBoxButtons::OK,
                      System::Windows::Forms::MessageBoxIcon::Error);
                  this->isLoaded = false;
              }

             
            // FILE* input = fopen(, "rb");
           //  System::Drawing::Bitmap::FromFile(this->picture1->ImageLocation);
            myStream->Close();
            
           
            
        }
    }
}




private: System::Void startButton_Click(System::Object^ sender, System::EventArgs^ e) {
    if (isLoaded) {

        std::string tempPath;
        char header[54]; // 54 bitowy header
        MarshalString(this->path, tempPath); 

        FILE* input = fopen(tempPath.c_str(), "rb");
        std::string outputPath = "C:/Users/zento/source/repos/rixis321/JA/Bitmap/output.bmp"; // sciezka zapisu wynikowej bitmapy

        FILE* output = fopen(outputPath.c_str(), "wb");

        fread(header, 1, 54, input); // wczytanie naglowka bitmapy
        fwrite(header, 1, 54, output); // zapis naglowka bitmapy do bitmapy wyjsciowej

        int bitPerPix = *(int*)(header + 28); // pobranie formatu bitmapy
        int comp = *(int*)(header + 30); // pobranie metody kompresji


        int width = *(int*)(header + 18); // pobranie dlugosci bitmapy
        int height = *(int*)(header + 22);// pobranie szerokosci bitmapy

        unsigned char* buf = new unsigned char[width * height * 3]; // bufor z RGB
        fread(buf, sizeof(unsigned char), width * height * 3, input); // wczytanie bitmapy do bufora
        fclose(input);

        /* Obliczanie wspolczynnika poprawy kontrastu */
        float factor = (259.0f * (this->contrastRatio + 255.0f)) / (255.0f * (259.0f - this->contrastRatio));

        int rowPerThread = height / this->numberOfThreads; // ilosc wierszy przypadajacych na jeden watek 
        std::vector<int> indexesPerThread; // wektor zawierajacy ilosc indeksow od do dla kazdego z watkow


        /* Przyporzadkowanie czesci bitmapy dla kazdego z watkow poprzez indeksy*/
        for (int i = 0; i < this->numberOfThreads; i++) {

            if (i == 0) {
                indexesPerThread.push_back(0);
                indexesPerThread.push_back(rowPerThread * width * 3);
            }
            else
            {
                indexesPerThread.push_back(i * rowPerThread * width * 3);
                if (i == this->numberOfThreads - 1) {
                    indexesPerThread.push_back(width * height * 3);
                    break;
                }
                indexesPerThread.push_back((i + 1) * rowPerThread * width * 3);
            }
        }

        /* Alokowanie pamieci na gotowa bitmape wyjsciowa*/
        std::vector<unsigned char*> parts;
        int x = 0;
        int y = 1;

        for (int i = 0; i < this->numberOfThreads; i++) {
            int size = indexesPerThread[y] - indexesPerThread[x];
            unsigned char* temp = new unsigned char[size];
            parts.push_back(temp);
            x += 2;
            y += 2;
        }


        x = 0;
        y = 1;

        std::vector<std::thread> thread;
        auto timerStart = std::chrono::steady_clock::now(); // czas startu

        /* Watki programu wykonujace algorytm */
        for (int i = 0; i < this->numberOfThreads; i++) {

            if (this->libraryFlag == false) {

                thread.push_back(std::thread(&cppAlg, buf, std::ref(parts[i]), indexesPerThread[x], indexesPerThread[y], factor));

            }
            else if (this->libraryFlag == true) {

                thread.push_back(std::thread(&startAsm, buf, std::ref(parts[i]), indexesPerThread[x], indexesPerThread[y], factor));
  
            }
            x += 2;
            y += 2;
        }
        for (int i = 0; i < this->numberOfThreads; i++) {
            if (thread[i].joinable()) {
                thread[i].join();

            }
        }
        auto timerEnd = std::chrono::steady_clock::now(); // czas konca
        auto finalTime = timerEnd - timerStart;
        this->time = std::chrono::duration<double, std::milli>(finalTime).count();
        
        x = 0;
        y = 1;
        /* Zapisanie gotowych czesci bitmapy do pliku wyjsciowego */
        for (int i = 0; i < parts.size(); i++) {
            int size = indexesPerThread[y] - indexesPerThread[x];
            fwrite((parts[i]), sizeof(unsigned char), size, output);

            x += 2;
            y += 2;
        }

        
        fclose(output);
        System::String^ out = gcnew System::String(outputPath.c_str());
        this->picture2->ImageLocation = out; // wyswietlanie wynikowej bitmapy


        /* Zwolnienie pamieci chroniace przed wyciekami pamieci */
        for (int i = 0; i < this->numberOfThreads; i++) {
            delete parts[i];
        }

        parts.clear();
        delete[] buf;

        this->label10->Text = this->time.ToString() + " ms";
        MessageBox::Show("Image has been saved in project directory", "Information",
            System::Windows::Forms::MessageBoxButtons::OK,
            System::Windows::Forms::MessageBoxIcon::Information);
    }
    else {
        MessageBox::Show("Bitmap is not loaded. Open a file first. ", "Information",
            System::Windows::Forms::MessageBoxButtons::OK,
            System::Windows::Forms::MessageBoxIcon::Information);
    }

}

private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {

    this->contrastRatio = this->trackBar1->Value;
    this->label2->Text = this->contrastRatio.ToString();
    
}



private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
    this->numberOfThreads = this->trackBar2->Value;
    this->label8->Text = this->numberOfThreads.ToString();
    this->trackBar2->Maximum = this->maxNumbOfThreads;
    
}

}; // end of class Form1
} // end of namespace CppCLRWinFormsProject

