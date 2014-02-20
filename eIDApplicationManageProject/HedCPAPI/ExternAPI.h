//#define EXTERNAPI_EXPORTS
// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� EXTERNAPI_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// EXTERNAPI_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef EXTERNAPI_EXPORTS
#define EXTERNAPI_API __declspec(dllexport)
#else
#define EXTERNAPI_API __declspec(dllimport)
#endif

#pragma once


void EXTERNAPI_API SetUkeyLastErr(DWORD dwErr);

DWORD EXTERNAPI_API GetUkeyLastErr(void);

//��UKey
BOOL EXTERNAPI_API UKeyOpen(HANDLE *hUKey);
	
//�ر�UKey
BOOL EXTERNAPI_API UKeyClose(HANDLE hUKey);

//��֤UKey ��pin �����������,
BOOL EXTERNAPI_API UKeyVerifyPIN(HANDLE hUKey, const char *Pin, const short PinLen);
BOOL EXTERNAPI_API UKeyCheckPIN(HANDLE hUKey, int nLanguage = 1);
BOOL EXTERNAPI_API UKeyChangePINToUkey(HANDLE hUKey, const char *Pin, const short PinLen);
BOOL EXTERNAPI_API UKeyChangePIN(HANDLE hUKey, int nLanguage = 1);
//ȥ�����
BOOL EXTERNAPI_API UKeyGetChallange(HANDLE hUKey, unsigned char *Challange, const short Len);

BOOL EXTERNAPI_API UKeyGetContainer(HANDLE hUKey,BYTE *pbContainer,BYTE *pstrCardCt);
BOOL EXTERNAPI_API UKeyGetCspContainerCount(HANDLE hUKey, WORD *wCount, BYTE *pContainers);
BOOL EXTERNAPI_API UKeyFindContainer(HANDLE hUKey,BYTE *pbContainer);
BOOL EXTERNAPI_API UKeyDelContainer(HANDLE hUKey,BYTE *pbContainer);
BOOL EXTERNAPI_API UKeyAddContainer(HANDLE hUKey,BYTE *strCardCt);
BOOL EXTERNAPI_API UKeyUpdateContainer(HANDLE hUKey, BYTE *ContainerName, BYTE *strCardCt);
BOOL EXTERNAPI_API UKeyGenKey(HANDLE hUKey, WORD wKeyPSfi, WORD wKeySSfi);
BOOL EXTERNAPI_API UKeyGetKey(HANDLE hUKey, DWORD sfi, unsigned char KeyFlag, unsigned char *Key);
BOOL EXTERNAPI_API UKeyRSAEncrypt(HANDLE hUKey, DWORD sfi, unsigned char *InData, int *InDataLen, 
					unsigned char *OutData, int *OutDataLen);
BOOL EXTERNAPI_API UKeyRSADecrypt(HANDLE hUKey, DWORD sfi, unsigned char *InData, int *InDataLen, 
					unsigned char *OutData, int *OutDataLen);
BOOL EXTERNAPI_API UKeyRSASignature(HANDLE hUKey, DWORD sfi, unsigned char *InData, int InDataLen, 
					unsigned char *OutData, int *OutDataLen);
BOOL EXTERNAPI_API UKeyRSASignatureVerify(HANDLE hUKey, DWORD sfi, const unsigned char *InData, int InDataLen, 
					unsigned char *OutData, int *OutDataLen);
//֤�����
BOOL EXTERNAPI_API UKeyGetNameFromCN(char *cn,char *name);
BOOL EXTERNAPI_API UKeyGetCertName(BYTE *pbData, DWORD dwLen, char *pcOutName);
BOOL EXTERNAPI_API UKeyAppendCert(HANDLE hUKey, BYTE *pstrCardCt, BYTE *pbData, DWORD dwLen);
BOOL EXTERNAPI_API UKeyGetCert(HANDLE hUKey, BYTE *pstrCardCt, BYTE *pbData, DWORD dwLen);
BOOL EXTERNAPI_API UKeyImportKey(HANDLE hUKey, DWORD sfi, unsigned char *Key);

BOOL EXTERNAPI_API UKeyUnLock(HANDLE hUKey, BYTE *NewPin, int NewPinLen);
BOOL EXTERNAPI_API UKeyGetInfo(HANDLE hUKey,BYTE *Info, int *InfoLen);
BOOL EXTERNAPI_API UKeyGetContainerName(HANDLE hUKey,BYTE *CName, int *CNameLen);
BOOL EXTERNAPI_API UKeySetContainerName(HANDLE hUKey,BYTE *CName, int CNameLen);
BOOL EXTERNAPI_API UKeyClearPin(HANDLE hUKey);

BOOL EXTERNAPI_API UKeyTestDisplayNum(HANDLE hUKey, int num);

