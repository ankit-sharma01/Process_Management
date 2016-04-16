#pragma once

#include <iostream>
#include "mydriver.h"
#include "MyForm1.h"

extern int total_count;
extern int cpubound_count;
extern int iobound_count;
extern double iotime_ratio;
process_list *newList=NULL;						// Global pointer to Process List

//using MessageBox = System::Windows::Forms::MessageBox;

namespace myScheduler {

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
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	protected:


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton8;


	private: System::Windows::Forms::Button^  button2;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::RadioButton^  radioButton1;

	private: System::Windows::Forms::Button^  button6;

	private: System::Windows::Forms::Label^  label2;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button5;



	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 8;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10.53923F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.55098F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.61669F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				3.670408F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				21.23593F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				16.29656F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.55098F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				10.53922F)));
			this->tableLayoutPanel1->Controls->Add(this->label1, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->label3, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label4, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox1, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox2, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->label6, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->label8, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->label9, 5, 2);
			this->tableLayoutPanel1->Controls->Add(this->label10, 5, 3);
			this->tableLayoutPanel1->Controls->Add(this->textBox4, 6, 1);
			this->tableLayoutPanel1->Controls->Add(this->textBox5, 6, 2);
			this->tableLayoutPanel1->Controls->Add(this->textBox6, 6, 3);
			this->tableLayoutPanel1->Controls->Add(this->button6, 4, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(764, 121);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(336, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 30);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Process Creation";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Location = System::Drawing::Point(83, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 30);
			this->label3->TabIndex = 8;
			this->label3->Text = L"I/O Bound Ratio";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label4->Location = System::Drawing::Point(83, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 30);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Process Count";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Location = System::Drawing::Point(178, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(90, 20);
			this->textBox1->TabIndex = 11;
			// 
			// textBox2
			// 
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox2->Location = System::Drawing::Point(178, 63);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(90, 20);
			this->textBox2->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label6->Location = System::Drawing::Point(274, 60);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(22, 30);
			this->label6->TabIndex = 14;
			this->label6->Text = L"%";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label8->Location = System::Drawing::Point(464, 30);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(118, 30);
			this->label8->TabIndex = 16;
			this->label8->Text = L"CPU Bound Processes";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label9->Location = System::Drawing::Point(464, 60);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(118, 30);
			this->label9->TabIndex = 17;
			this->label9->Text = L"I/O Bound Processes";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label10->Location = System::Drawing::Point(464, 90);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(118, 31);
			this->label10->TabIndex = 18;
			this->label10->Text = L"I/O Time Ratio";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox4
			// 
			this->textBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(588, 33);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(89, 20);
			this->textBox4->TabIndex = 19;
			// 
			// textBox5
			// 
			this->textBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(588, 63);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(89, 20);
			this->textBox5->TabIndex = 20;
			// 
			// textBox6
			// 
			this->textBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(588, 93);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(89, 20);
			this->textBox6->TabIndex = 21;
			// 
			// button6
			// 
			this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->button6->Location = System::Drawing::Point(322, 63);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(115, 24);
			this->button6->TabIndex = 22;
			this->button6->Text = L"Generate";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel3->ColumnCount = 5;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				20)));
			this->tableLayoutPanel3->Controls->Add(this->radioButton5, 1, 2);
			this->tableLayoutPanel3->Controls->Add(this->radioButton4, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->radioButton1, 2, 1);
			this->tableLayoutPanel3->Controls->Add(this->radioButton6, 2, 2);
			this->tableLayoutPanel3->Controls->Add(this->radioButton7, 3, 2);
			this->tableLayoutPanel3->Controls->Add(this->radioButton8, 4, 2);
			this->tableLayoutPanel3->Controls->Add(this->label2, 2, 0);
			this->tableLayoutPanel3->Controls->Add(this->button1, 2, 3);
			this->tableLayoutPanel3->Location = System::Drawing::Point(0, 121);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 4;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(764, 114);
			this->tableLayoutPanel3->TabIndex = 2;
			// 
			// radioButton5
			// 
			this->radioButton5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(176, 59);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(103, 22);
			this->radioButton5->TabIndex = 2;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Round Robin - 3";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(50, 59);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(51, 22);
			this->radioButton4->TabIndex = 1;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"FCFS";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(350, 31);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(59, 22);
			this->radioButton1->TabIndex = 8;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Run All";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(328, 59);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(103, 22);
			this->radioButton6->TabIndex = 3;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Round Robin - 6";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton7
			// 
			this->radioButton7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(506, 59);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(52, 22);
			this->radioButton7->TabIndex = 4;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"STCF";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton8
			// 
			this->radioButton8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(652, 59);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(68, 22);
			this->radioButton8->TabIndex = 5;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"STCF - P";
			this->radioButton8->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->Location = System::Drawing::Point(307, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 28);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Process Scheduling";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(307, 87);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(146, 24);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Run";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(385, 3);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			series1->Legend = L"Legend1";
			series1->Name = L"FCFS";
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::Gray;
			series2->Legend = L"Legend1";
			series2->Name = L"RR3";
			series3->ChartArea = L"ChartArea1";
			series3->Color = System::Drawing::Color::LightSalmon;
			series3->Legend = L"Legend1";
			series3->Name = L"RR6";
			series4->ChartArea = L"ChartArea1";
			series4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series4->Legend = L"Legend1";
			series4->Name = L"STCF";
			series5->ChartArea = L"ChartArea1";
			series5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			series5->Legend = L"Legend1";
			series5->Name = L"STCF-P";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Series->Add(series5);
			this->chart1->Size = System::Drawing::Size(376, 157);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->button4, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->chart1, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->richTextBox1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 1, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 238);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 78.36539F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 17.30769F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 3.846154F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(764, 208);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button4->Location = System::Drawing::Point(141, 166);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(99, 30);
			this->button4->TabIndex = 2;
			this->button4->Text = L"View Results";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Location = System::Drawing::Point(3, 3);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(376, 157);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->button5, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->button3, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(385, 166);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(376, 30);
			this->tableLayoutPanel4->TabIndex = 6;
			// 
			// button5
			// 
			this->button5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button5->Location = System::Drawing::Point(230, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(103, 24);
			this->button5->TabIndex = 1;
			this->button5->Text = L"IO Impact Analysis";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->Location = System::Drawing::Point(44, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 24);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Compare";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(764, 446);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel3);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Process Management";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
		private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e)
		{
			double  process_count, ratio;
			//		double % aout = total_count;
			Double::TryParse(textBox1->Text, process_count);
			Double::TryParse(textBox2->Text, ratio);

			if ((process_count > 0 && process_count <= 200) && (ratio >= 0 && ratio <= 100))
			{
				ProcessGenerator P;
				newList = P.generate_pool(process_count, ratio);
				char str1[50];
				strcpy(str1, " Processes Generated Successfully!");
				MessageBox::Show(String::Format("{0} Processes Generated Successfully!", total_count), "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				if (process_count>200)
					MessageBox::Show("Not more than 200, please!", "Oops!", MessageBoxButtons::OK, MessageBoxIcon::Information);
				else if ((ratio < 0 || ratio > 100))
					MessageBox::Show("Ratio is improper, Jim!", "Oops!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			/*  textBox2->Text=strTextBoxContent;; */

			textBox4->Text = Convert::ToString(cpubound_count);
			textBox5->Text = Convert::ToString(iobound_count);
			textBox6->Text = Convert::ToString(iotime_ratio);
		}

		private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->richTextBox1->LoadFile("results.txt", RichTextBoxStreamType::PlainText);
		}
		private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e)
		{
			int choice, rvalue;
			if (radioButton1->Checked == true)
				choice = 6;
			else if (radioButton4->Checked == true)
				choice = 1;
			else if (radioButton5->Checked == true)
				choice = 2;
			else if (radioButton6->Checked == true)
				choice = 3;
			else if (radioButton7->Checked == true)
				choice = 4;
			else if (radioButton8->Checked == true)
				choice = 5;
			else
				choice = 6;
			rvalue = run_algorithms(choice, newList);
			if (choice == 6)
				MessageBox::Show("Done Running All Algorithms!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			else
				MessageBox::Show("Done Running Algorithm!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
		{
			this->chart1->Series["FCFS"]->Points->Clear();
			this->chart1->Series["RR3"]->Points->Clear();
			this->chart1->Series["RR6"]->Points->Clear();
			this->chart1->Series["STCF"]->Points->Clear();
			this->chart1->Series["STCF-P"]->Points->Clear();
			// Normalize the values to fit in single graph
			double normUtil[MAXALGORITHMS];
			double normThru[MAXALGORITHMS];
			double normReady[MAXALGORITHMS];
			double normIO[MAXALGORITHMS];
			double normTurn[MAXALGORITHMS];

			for (int i = 0; i < MAXALGORITHMS; i++)
			{
			normUtil[i] = m1->cpuUtil[i];
			normThru[i] = m1->throughput[i];
			normThru[i] *= 300;
			normReady[i] = m1->avgReadyWaitTime[i];
			normReady[i] *= 3;
			normIO[i] = m1->avgIOWaitTime[i];
			normIO[i] *= 3;
			normTurn[i] = m1->avgTurnAroundTime[i];
			normTurn[i] *= 2;

			}
			this->chart1->Series["FCFS"]->Points->AddXY("CPU Utilization", normUtil[0]);
			this->chart1->Series["RR3"]->Points->AddXY("CPU Utilization", normUtil[1]);
			this->chart1->Series["RR6"]->Points->AddXY("CPU Utilization", normUtil[2]);
			this->chart1->Series["STCF"]->Points->AddXY("CPU Utilization", normUtil[3]);
			this->chart1->Series["STCF-P"]->Points->AddXY("CPU Utilization", normUtil[4]);

			this->chart1->Series["FCFS"]->Points->AddXY("Throughput", normThru[0]);
			this->chart1->Series["RR3"]->Points->AddXY("Throughput", normThru[1]);
			this->chart1->Series["RR6"]->Points->AddXY("Throughput", normThru[2]);
			this->chart1->Series["STCF"]->Points->AddXY("Throughput", normThru[3]);
			this->chart1->Series["STCF-P"]->Points->AddXY("Throughput", normThru[4]);

			this->chart1->Series["FCFS"]->Points->AddXY("AvgReadyWaitTime", normReady[0]);
			this->chart1->Series["RR3"]->Points->AddXY("AvgReadyWaitTime", normReady[1]);
			this->chart1->Series["RR6"]->Points->AddXY("AvgReadyWaitTime", normReady[2]);
			this->chart1->Series["STCF"]->Points->AddXY("AvgReadyWaitTime", normReady[3]);
			this->chart1->Series["STCF-P"]->Points->AddXY("AvgReadyWaitTime", normReady[4]);
			/*
			this->chart1->Series["FCFS"]->Points->AddXY("AvgIOWaitTime", 20);
			this->chart1->Series["RR3"]->Points->AddXY("AvgIOWaitTime", 15);
			this->chart1->Series["RR6"]->Points->AddXY("AvgIOWaitTime", 10);
			this->chart1->Series["STCF"]->Points->AddXY("AvgIOWaitTime", 4);
			this->chart1->Series["STCF-P"]->Points->AddXY("AvgIOWaitTime", 8);
			*/
			this->chart1->Series["FCFS"]->Points->AddXY("AvgTurnAroundTime", normTurn[0]);
			this->chart1->Series["RR3"]->Points->AddXY("AvgTurnAroundTime", normTurn[1]);
			this->chart1->Series["RR6"]->Points->AddXY("AvgTurnAroundTime", normTurn[2]);
			this->chart1->Series["STCF"]->Points->AddXY("AvgTurnAroundTime", normTurn[3]);
			this->chart1->Series["STCF-P"]->Points->AddXY("AvgTurnAroundTime", normTurn[4]);
		}
		private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			MyForm1^ form1 = gcnew MyForm1();
			form1->Show();
		}
};
}
