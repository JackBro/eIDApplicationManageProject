// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CSPTOSIGN_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CSPTOSIGN_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CSPTOSIGN_EXPORTS
#define CSPTOSIGN_API __declspec(dllexport)
#else
#define CSPTOSIGN_API __declspec(dllimport)
#endif

// �����Ǵ� CspToSign.dll ������
class CSPTOSIGN_API CCspToSign {
public:
	CCspToSign(void);
	// TODO: �ڴ�������ķ�����
};

extern CSPTOSIGN_API int nCspToSign;

CSPTOSIGN_API int fnCspToSign(void);
