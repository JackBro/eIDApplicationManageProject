#pragma once

#include "USBHidDll.h"

namespace eIDApplicationManageGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 ժҪ
	///
	/// ����: ������Ĵ�������ƣ�����Ҫ����
	///          ����������������� .resx �ļ��������й���Դ���������ߵ�
	///          ����Դ�ļ��������ԡ�����
	///          �������������˴���Ĺ���
	///          ���ػ���Դ��ȷ������
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:

		bool g_bDeviceConnected;

		MainForm(void)
		{
			g_bDeviceConnected = false;

			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ѡ���豸:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"eID Adaptor USB-HID", L"eID Smart Card Reader PCSC"});
			this->comboBox1->Location = System::Drawing::Point(78, 10);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(242, 20);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(70, 86);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(229, 52);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Ӧ�ó���һ";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(70, 203);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(229, 55);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Ӧ�ó�����";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(383, 329);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"eIDӦ�ù������";
			this->Load += gcnew System::EventHandler(this, &MainForm::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 PHANDLE pWriteHandle;
				 PHANDLE pReadHandle;
				 PSP_DEVICE_INTERFACE_DETAIL_DATA detailData = NULL;
				 
				 if(comboBox1 -> SelectedItem == "eID Adaptor USB-HID"){
					if((detailData = bOpenHidDevice(0x1677, 0x0340)) != NULL){
						 
						 pWriteHandle = (PHANDLE)malloc(sizeof(HANDLE));
						 pReadHandle = (PHANDLE)malloc(sizeof(HANDLE));
						 if(bInitWriteHandle(detailData, pWriteHandle) && bInitReadHandle(detailData, pReadHandle)){	 
							 MessageBox::Show("����USB�豸�ɹ�!\r\n");
							 g_bDeviceConnected = true;
							 //��ʼ��Write����ɹ�!\r\n��ʼ��Read����ɹ�!\r\n
//							 this->Hide();
//							this->Owner->Show();
//							this->Owner->Activate();
						 }


					 }else{
						 MessageBox::Show("�Ҳ���ָ��USB�豸!\r\n�����Ƿ����USB�豸��\r\n");
					 }
				 }else if(comboBox1 -> SelectedItem == "eID Smart Card Reader PCSC"){
					g_bDeviceConnected = true;
				 }
				 if(g_bDeviceConnected){
					button1->Enabled = true;
					this->button2->Enabled = true;
				 }
			 }
	};
}

