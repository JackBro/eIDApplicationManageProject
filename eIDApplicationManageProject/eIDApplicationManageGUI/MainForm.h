#pragma once

#include <windows.h>
#include <iostream>
#include <string>
#include <tchar.h>
//#include <atlstr.h>

#include "shlwapi.h"

//#include "define.h"
#include "USBHidDll.h"
#include "cspdk.h"

#define PCSC_REGISTER_NAME "SOFTWARE\\Microsoft\\Cryptography\\Defaults\\Provider\\HED_PCSC_Cryptographic_Service_Provider_V1.0"
#define HID_REGISTER_NAME "SOFTWARE\\Microsoft\\Cryptography\\Defaults\\Provider\\HED_HID_Cryptographic_Service_Provider_V1.0"
#define PCSC_DEVICE_ID  0x01
#define HID_DEVICE_ID   0x02

typedef BOOL(WINAPI *pCPAcquireContext)(
	OUT HCRYPTPROV *phProv,
    IN  LPCSTR szContainer,
    IN  DWORD dwFlags,
    IN  PVTableProvStruc pVTable);


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

		bool g_bPcscDeviceConnected;
		bool g_bHidDeviceConnected;
		HKEY g_hRegProviders;
		String^ lpstrRegImagePath;
		String^ lpsImagePath;
		HINSTANCE hDLL;
		DWORD dwDeviceType;

		MainForm(void)
		{
			g_bPcscDeviceConnected = false;
			g_bHidDeviceConnected = false;
			g_hRegProviders = NULL;
			lpstrRegImagePath = "";
			lpsImagePath = "";

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
					dwDeviceType = HID_DEVICE_ID;
					 if((detailData = bOpenHidDevice(0x1677, 0x0340)) != NULL){
						 
						 pWriteHandle = (PHANDLE)malloc(sizeof(HANDLE));
						 pReadHandle = (PHANDLE)malloc(sizeof(HANDLE));
						 if(bInitWriteHandle(detailData, pWriteHandle) && bInitReadHandle(detailData, pReadHandle)){	 
							 MessageBox::Show("����USB�豸�ɹ�!\r\n");
							 g_bHidDeviceConnected = true;
							 //��ʼ��Write����ɹ�!\r\n��ʼ��Read����ɹ�!\r\n
//							 this->Hide();
//							this->Owner->Show();
//							this->Owner->Activate();
						 }


					 }else{
						 MessageBox::Show("�Ҳ���ָ��USB�豸!\r\n�����Ƿ����USB�豸��\r\n");
					 }
				 }else if(comboBox1 -> SelectedItem == "eID Smart Card Reader PCSC"){
					 dwDeviceType = PCSC_DEVICE_ID;
					 hDLL = bGetCspRegisterInfo(dwDeviceType);
					 
					 if(hDLL != NULL){	
						g_bPcscDeviceConnected = true;
					 }else{
						g_bPcscDeviceConnected = false;
					 }
				 }
				 if(g_bPcscDeviceConnected){
					this->button1->Enabled = true;
					this->button2->Enabled = true;
				 }
			 }

	HINSTANCE  bGetCspRegisterInfo(DWORD type){
				
				DWORD dwStatus;
				
				HKEY hRegHandle;

				DWORD dwType = REG_SZ;

				CHAR buf[256] = {'\0'};
				DWORD bufSize = sizeof(buf);
				LPCSTR lpsRegName;
				
				switch (type){
					case PCSC_DEVICE_ID:
						lpsRegName = PCSC_REGISTER_NAME;
						break;
					case HID_DEVICE_ID:
						lpsRegName = HID_REGISTER_NAME;
						break;
					default:
						lpsRegName = "";
						break;
				};

				dwStatus = RegOpenKeyEx(
					HKEY_LOCAL_MACHINE,
//					TEXT(PCSC_REGISTER_NAME),
					TEXT(lpsRegName),
					0,
					KEY_READ,
					&hRegHandle);
				if (ERROR_SUCCESS == dwStatus)
				{

					dwStatus = RegQueryValueEx(
						hRegHandle,
						TEXT("Image Path"),
						NULL,
						&dwType,
						(LPBYTE)buf,
						&bufSize);

					if (ERROR_SUCCESS == dwStatus){
						hDLL = LoadLibrary(buf);
						

//						if(NULL != hDLL){
//							bRet = true;
/*
							pCPAcquireContext cPAcquireContext;
							cPAcquireContext = (pCPAcquireContext)GetProcAddress(hDLL, "CPAcquireContext");
							if(NULL == cPAcquireContext){
								bRet = false;
								MessageBox::Show("Find function \"CPAcquireContext\" failed!");
							}else{
								cPAcquireContext(NULL, NULL, NULL, NULL);
								bRet = true;
							}
*/
//						}else{
//							bRet = false;
//						}
						
					}else{
						hDLL = NULL;
					}	
				}
				else{
					hDLL = NULL;
					MessageBox::Show("Plesae Install HED CSP!");
					
				}
				RegCloseKey(hRegHandle);
				return hDLL;;
			 }

			 
	};

	
}

