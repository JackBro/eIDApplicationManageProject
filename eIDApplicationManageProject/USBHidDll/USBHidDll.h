//#define USBHIDDLL_EXPORTS
// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� USBHIDDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// USBHIDDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef USBHIDDLL_EXPORTS
#define USBHIDDLL_API __declspec(dllexport)
#else
#define USBHIDDLL_API __declspec(dllimport)
#endif

extern "C" {    // this MUST be included

	// These files are in the Windows DDK
	//#include <initguid.h>
#include "hidsdi.h"
#include <setupapi.h>

}


USBHIDDLL_API			bool bInitWriteHandle(PSP_DEVICE_INTERFACE_DETAIL_DATA detailData, PHANDLE pWriteHandle);
USBHIDDLL_API			 bool bInitReadHandle(PSP_DEVICE_INTERFACE_DETAIL_DATA detailData, PHANDLE pReadHandle);
USBHIDDLL_API			 bool bWrite_ToHIDDevice(PHANDLE pWriteHandle, LPBYTE lpWriteBuff);
USBHIDDLL_API			 DWORD dwRead_FromHIDDevice(PHANDLE pReadHandle, BYTE byReadBuff[], DWORD len);
USBHIDDLL_API			 PSP_DEVICE_INTERFACE_DETAIL_DATA bOpenHidDevice(USHORT VID, USHORT PID);
