#pragma once

process_list *newList1[5];						// Global pointer to Process List
int io_counter = 0;

namespace myScheduler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
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
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->chart1, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 24.05063F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 75.94937F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(714, 395);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->button1, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 67.53247F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 32.46753F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(708, 88);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->groupBox1, 1, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 53)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(702, 53);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->textBox1, 1, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 47)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(345, 47);
			this->tableLayoutPanel4->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(61, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 47);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Number of Processes";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(175, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(167, 20);
			this->textBox1->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(354, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(345, 47);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Algorithms";
			// 
			// radioButton4
			// 
			this->radioButton4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(257, 17);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(62, 17);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"STCF-P";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(183, 17);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(52, 17);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"STCF";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(116, 17);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(41, 17);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"RR";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(41, 17);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(51, 17);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"FCFS";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->button1->Location = System::Drawing::Point(293, 62);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Generate and Run";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(3, 97);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			series1->Legend = L"Legend1";
			series1->Name = L"0%";
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::Gray;
			series2->Legend = L"Legend1";
			series2->Name = L"25%";
			series3->ChartArea = L"ChartArea1";
			series3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			series3->Legend = L"Legend1";
			series3->Name = L"50%";
			series4->ChartArea = L"ChartArea1";
			series4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series4->Legend = L"Legend1";
			series4->Name = L"75%";
			series5->ChartArea = L"ChartArea1";
			series5->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			series5->Legend = L"Legend1";
			series5->Name = L"100%";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Series->Add(series5);
			this->chart1->Size = System::Drawing::Size(708, 295);
			this->chart1->TabIndex = 1;
			this->chart1->Text = L"chart1";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 395);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"I/O Impact Analysis";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			double  process_count;
			int ratio = -25;
			int choice, rvalue;

			ProcessGenerator P[5];
			double normUtil_io[5];
			double normThru_io[5];
			double normReady_io[5];
			double normIO_io[5];
			double normTurn_io[5];

			Double::TryParse(textBox1->Text, process_count);
		
			if (radioButton1->Checked == true)
				choice = 1;
			else if (radioButton2->Checked == true)
				choice = 2;
			else if (radioButton3->Checked == true)
				choice = 3;
			else if (radioButton4->Checked == true)
				choice = 4;
			else
				choice = 1;

			if (process_count > 0 && process_count <= 20)
			{
				for (int i = 0; i < 5; i++)
				{ 
					ratio += 25;
					newList1[i] = P[i].generate_pool(process_count, ratio);
					rvalue = run_algorithms(choice, newList1[i]);
				
					normUtil_io[i] = m2.cpuUtil[0];
					normThru_io[i] = m2.throughput[0];
					normThru_io[i] *= 300;
					normReady_io[i] = m2.avgReadyWaitTime[0];
					normReady_io[i] *= 3;
					normIO_io[i] = m2.avgIOWaitTime[0];
					normIO_io[i] *= 3;
					normTurn_io[i] = m2.avgTurnAroundTime[0];
					normTurn_io[i] *= 2;
					io_counter++;
				}
				MessageBox::Show("Processes Generated and Run Successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
					MessageBox::Show("Not more than 20, please!", "Oops!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}

			/*------------------------------------------------------------*/
			/*------------------------------------------------------------*/
			/*------------------------------------------------------------*/
			/*------------------------------------------------------------*/
			
			this->chart1->Series["0%"]->Points->Clear();
			this->chart1->Series["25%"]->Points->Clear();
			this->chart1->Series["50%"]->Points->Clear();
			this->chart1->Series["75%"]->Points->Clear();
			this->chart1->Series["100%"]->Points->Clear();

			this->chart1->Series["0%"]->Points->AddXY("CPU Utilization", normUtil_io[0]);
			this->chart1->Series["25%"]->Points->AddXY("CPU Utilization", normUtil_io[1]);
			this->chart1->Series["50%"]->Points->AddXY("CPU Utilization", normUtil_io[2]);
			this->chart1->Series["75%"]->Points->AddXY("CPU Utilization", normUtil_io[3]);
			this->chart1->Series["100%"]->Points->AddXY("CPU Utilization", normUtil_io[4]);

			this->chart1->Series["0%"]->Points->AddXY("Throughput", normThru_io[0]);
			this->chart1->Series["25%"]->Points->AddXY("Throughput", normThru_io[1]);
			this->chart1->Series["50%"]->Points->AddXY("Throughput", normThru_io[2]);
			this->chart1->Series["75%"]->Points->AddXY("Throughput", normThru_io[3]);
			this->chart1->Series["100%"]->Points->AddXY("Throughput", normThru_io[4]);

			this->chart1->Series["0%"]->Points->AddXY("AvgReadyWaitTime", normReady_io[0]);
			this->chart1->Series["25%"]->Points->AddXY("AvgReadyWaitTime", normReady_io[1]);
			this->chart1->Series["50%"]->Points->AddXY("AvgReadyWaitTime", normReady_io[2]);
			this->chart1->Series["75%"]->Points->AddXY("AvgReadyWaitTime", normReady_io[3]);
			this->chart1->Series["100%"]->Points->AddXY("AvgReadyWaitTime", normReady_io[4]);

			this->chart1->Series["0%"]->Points->AddXY("AvgTurnAroundTime", normTurn_io[0]);
			this->chart1->Series["25%"]->Points->AddXY("AvgTurnAroundTime", normTurn_io[1]);
			this->chart1->Series["50%"]->Points->AddXY("AvgTurnAroundTime", normTurn_io[2]);
			this->chart1->Series["75%"]->Points->AddXY("AvgTurnAroundTime", normTurn_io[3]);
			this->chart1->Series["100%"]->Points->AddXY("AvgTurnAroundTime", normTurn_io[4]);
		}
};
}
