#pragma once

#include "HDIFD20B.h"
#include "ExternAPI.h"
#include "HEDCsp.h"

#include "shlwapi.h"

#include "USBHidDll.h"
#include "cspdk.h"

namespace TestGUI {

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
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnCallHDIFD20B;
	private: System::Windows::Forms::Button^  btnCallExternAPI;
	private: System::Windows::Forms::Button^  btnCallHedCsp;
	private: System::Windows::Forms::Button^  btnCallCspToSign;
	private: System::Windows::Forms::Button^  btnCallHID;


	protected: 

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
			this->btnCallHDIFD20B = (gcnew System::Windows::Forms::Button());
			this->btnCallExternAPI = (gcnew System::Windows::Forms::Button());
			this->btnCallHedCsp = (gcnew System::Windows::Forms::Button());
			this->btnCallCspToSign = (gcnew System::Windows::Forms::Button());
			this->btnCallHID = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnCallHDIFD20B
			// 
			this->btnCallHDIFD20B->Location = System::Drawing::Point(13, 13);
			this->btnCallHDIFD20B->Name = L"btnCallHDIFD20B";
			this->btnCallHDIFD20B->Size = System::Drawing::Size(133, 23);
			this->btnCallHDIFD20B->TabIndex = 0;
			this->btnCallHDIFD20B->Text = L"����HDIFD20B.dll";
			this->btnCallHDIFD20B->UseVisualStyleBackColor = true;
			this->btnCallHDIFD20B->Click += gcnew System::EventHandler(this, &Form1::btnCallHDIFD20B_Click);
			// 
			// btnCallExternAPI
			// 
			this->btnCallExternAPI->Location = System::Drawing::Point(13, 43);
			this->btnCallExternAPI->Name = L"btnCallExternAPI";
			this->btnCallExternAPI->Size = System::Drawing::Size(133, 22);
			this->btnCallExternAPI->TabIndex = 1;
			this->btnCallExternAPI->Text = L"����ExternAPI.dll";
			this->btnCallExternAPI->UseVisualStyleBackColor = true;
//			this->btnCallExternAPI->Click += gcnew System::EventHandler(this, &Form1::btnCallExternAPI_Click);
			// 
			// btnCallHedCsp
			// 
			this->btnCallHedCsp->Location = System::Drawing::Point(13, 72);
			this->btnCallHedCsp->Name = L"btnCallHedCsp";
			this->btnCallHedCsp->Size = System::Drawing::Size(133, 24);
			this->btnCallHedCsp->TabIndex = 2;
			this->btnCallHedCsp->Text = L"����HedCPAPI.dll";
			this->btnCallHedCsp->UseVisualStyleBackColor = true;
//			this->btnCallHedCsp->Click += gcnew System::EventHandler(this, &Form1::btnCallHedCsp_Click);
			// 
			// btnCallCspToSign
			// 
			this->btnCallCspToSign->Location = System::Drawing::Point(13, 103);
			this->btnCallCspToSign->Name = L"btnCallCspToSign";
			this->btnCallCspToSign->Size = System::Drawing::Size(133, 23);
			this->btnCallCspToSign->TabIndex = 3;
			this->btnCallCspToSign->Text = L"����CspToSign.dll";
			this->btnCallCspToSign->UseVisualStyleBackColor = true;
//			this->btnCallCspToSign->Click += gcnew System::EventHandler(this, &Form1::btnCallCspToSign_Click);
			// 
			// btnCallHID
			// 
			this->btnCallHID->Location = System::Drawing::Point(13, 133);
			this->btnCallHID->Name = L"btnCallHID";
			this->btnCallHID->Size = System::Drawing::Size(133, 23);
			this->btnCallHID->TabIndex = 4;
			this->btnCallHID->Text = L"����HID";
			this->btnCallHID->UseVisualStyleBackColor = true;
//			this->btnCallHID->Click += gcnew System::EventHandler(this, &Form1::btnCallHID_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->Controls->Add(this->btnCallHID);
			this->Controls->Add(this->btnCallCspToSign);
			this->Controls->Add(this->btnCallHedCsp);
			this->Controls->Add(this->btnCallExternAPI);
			this->Controls->Add(this->btnCallHDIFD20B);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���Գ���";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCallHDIFD20B_Click(System::Object^  sender, System::EventArgs^  e) {
				 HANDLE hReader;
				 DWORD ret = 0;

				 BYTE res[1024] = {0};
				 short retlen = 0;
				 ret = HD_OpenPort(21, 9600, 8, &hReader);
				 if(ret == 0x9000){
					 BYTE cmd[11] = {0x80, 0xD1, 0x00, 0x00, 0x06, 0x0C, 0x60, 0x00, 0x01, 0x00, 0x01};
					 ret = HD_ApduT0(hReader, cmd, 11, (BYTE *)res, &retlen, 0);
//					 ret = HD_ProbeCard(hReader, 0);
//					 HD_ResetCard(hReader, NULL, NULL, 0);
					 MessageBox::Show("OpenPort done!");
				 }else{
					 MessageBox::Show("OpenPort failed!");
				 }
			 }
			 /*
	private: System::Void btnCallExternAPI_Click(System::Object^  sender, System::EventArgs^  e) {
				 BYTE data[255] = {0};
				 int len;
				 if(UKeyGetContainerName(NULL, data, &len)){
					MessageBox::Show("GetContainerName done!");
				 }else{
					MessageBox::Show("GetContainerName failed!");
				 }


			}
//			 private: System::Void btnCallHedCsp_Click(System::Object^  sender, System::EventArgs^  e) {}
			 
	private: System::Void btnCallHedCsp_Click(System::Object^  sender, System::EventArgs^  e) {
				 HANDLE uKey;
				 int num = 0x37;

				 HCRYPTPROV hProv;
    HCRYPTKEY hKey;
    DWORD dwParam;
    DWORD dwFlags;

	PVTableProvStruc pVTable;

		LPDWORD dwret = (DWORD*)malloc(sizeof(DWORD));
		LPBYTE pbDate;
		
		pbDate = (BYTE*)malloc(sizeof(BYTE) * 255);
	hProv = (HCRYPTPROV)malloc(sizeof(HCRYPTPROV));
	hKey = (HCRYPTKEY)malloc(sizeof(HCRYPTKEY));
	dwParam = KP_KEYLEN;
	dwFlags = 0x31;
	pVTable = (PVTableProvStruc)malloc(sizeof(PVTableProvStruc));

	if(!CPAcquireContext1(
		&hProv, 
		NULL, 
		0,
		NULL
		))
	{
		CPAcquireContext1(
		&hProv, 
		NULL, 
		CRYPT_NEWKEYSET,
		NULL
		);

	}

				 CPTestDisplayNum1(uKey, num);
	}
			 
private: System::Void btnCallCspToSign_Click(System::Object^  sender, System::EventArgs^  e) {

			 HCRYPTPROV hProv;

			 CPAcquireContext(
				&hProv, 
				NULL, 
				0,
				NULL);
			 MessageBox::Show("done!");

		 }
private: System::Void btnCallHID_Click(System::Object^  sender, System::EventArgs^  e) {
			 PHANDLE pWriteHandle;
			 PHANDLE pReadHandle;
			 PSP_DEVICE_INTERFACE_DETAIL_DATA detailData = NULL;

			 if((detailData = bOpenHidDevice(0x0400, 0x345a)) != NULL){	 
				 pWriteHandle = (PHANDLE)malloc(sizeof(HANDLE));
				 pReadHandle = (PHANDLE)malloc(sizeof(HANDLE));
				 if(bInitWriteHandle(detailData, pWriteHandle) && bInitReadHandle(detailData, pReadHandle)){	 
					 MessageBox::Show("����USB�豸�ɹ�!\r\n");
					}
				}
		 }
		 */
};
}

