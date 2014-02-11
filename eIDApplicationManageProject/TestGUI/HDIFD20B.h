
// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� HDIFD20B_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// HDIFD20B_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef HDIFD20B_EXPORTS
#define HDIFD20B_API __declspec(dllexport)
#else
#define HDIFD20B_API __declspec(dllimport)
#endif


#define CCONV _stdcall//WINAPI

//��������
/**********************************************************************************************
1.HD_ContextInitialize
�����豸���������ͨ/USB KEY ͨѶǰ�����ȴ��豸��
unsigned short HD_ContextInitialize(
	HANDLE *ContextNo			//���ص�������

)

����˵��
ContextNo	���ص�������

����ֵ
��������0x9000��ʾ��ȷ����ʱdevNo��Ч������ֵ��ʾ������������Ϣ������ġ�������Ϣ������
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_ContextInitialize(HANDLE *ContextNo);

/**********************************************************************************************
2.HD_ContextRelease
�����豸���������ͨ/USB KEY ͨѶǰ�����ȴ��豸��
unsigned short HD_ContextRelease(
	HANDLE ContextNo				//������
)

����˵��
ContextNo			������

����ֵ
��������0x9000��ʾ��ȷ����ʱdevNo��Ч������ֵ��ʾ������������Ϣ������ġ�������Ϣ������
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_ContextRelease(HANDLE ContextNo);

/**********************************************************************************************
3.HD_GetReaderList
�����豸���������ͨ/USB KEY ͨѶǰ�����ȴ��豸��
unsigned short HD_GetReaderList(
	HANDLE ContextNo,				//������
	unsigned long * ReaderNo,		//����ֵ���豸��ʶ�б�
	unsigned long * ReaderCount		//����ֵ���豸����
)

����˵��
ContextNo		������
ReaderNo 		����ֵ���豸��ʶ�б���	
ReaderCount		����ֵ���豸������

����ֵ
��������0x9000��ʾ��ȷ����ʱdevNo��Ч������ֵ��ʾ������������Ϣ������ġ�������Ϣ������
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_GetReaderList(HANDLE ContextNo, int *ResponseBuffer , int *ResponseLength);

/**********************************************************************************************
4.HD_OpenPort
�����豸���������ͨ/USB KEY ͨѶǰ�����ȴ��豸��
unsigned short HD_OpenPort(
	HANDLE			ContextNo,		//������
	short  			ivPortNo,		// ����/USB �˿ڱ��/PCSC�豸���
	unsigned long 	ivBaud,			// ͨѶ������	//USB�ӿڲ�ʹ��
	short  			ivParity,		// У�鷽ʽ		//USB�ӿڲ�ʹ��
	HANDLE 			*devNo				
)

����˵��
ContextNo		������
ivPortNo 		���ڱ��: Windows�п�����1��2��3��4��	
                USB �˿ڱ��: 21, 22, 23, 24
				PCSC�豸���: ����ReaderName��Ӧѡ��
ivBaud			ͨѶ������, ����״̬����Ч;����9600, 19200 , 38400, 115200 ������ͨѶ��
ivParity	    У�鷽ʽ, ����״̬����Ч;0��У��λ(ȱʡ);1��У��;2żУ��;
devNo			���ص��豸��

����ֵ
��������0x9000��ʾ��ȷ����ʱdevNo��Ч������ֵ��ʾ������������Ϣ������ġ�������Ϣ������
***********************************************************************************************/
//HDIFD20B_API unsigned short CCONV HD_OpenPort(HANDLE ContextNo,short ivPortNo,unsigned long ivBaud, short ivParity, HANDLE *devNo);
HDIFD20B_API unsigned short CCONV HD_OpenPort(short ivPortNo,unsigned long ivBaud, short ivParity, HANDLE *devNo);
HDIFD20B_API unsigned short CCONV HD_OpenPath(unsigned char* DPath,HANDLE *devNo);

/**********************************************************************************************
5  HD_ResetCard 
�����ܿ������ϵ縴λ��ȡ�ø�λӦ����Ϣ��

unsigned short HD_ResetCard(		
	HANDLE 			devNo,
	char			*srATR,			
    short			*srATRLen,
	short 			ivCardSeat	//USB�ӿڲ�ʹ��
)

����˵��
devNo			    ��HD_OpenPort���ص��豸��
srATR            	����յ�������
srATRLen			��Ž��յ������ݵĳ���
ivCardSeat			�����š�1����������2:������

����ֵ
��������0x9000��ʾ��ȷ����ʱsrATR������Ч������ֵ��ʾ������������Ϣ������ġ�������Ϣ��������ʱsrATR������Ч��

ע������
�ú��������󣬿���RST�ܽ�Ϊ�ߵ�ƽ�������빤��״̬�������صĸ�λӦ���ֽڴ���srATR�����С�
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_ResetCard( HANDLE devNo, unsigned char	*srATR, short	*srATRLen, short ivCardSeat);
HDIFD20B_API unsigned short CCONV HD_ResetCardVB( HANDLE devNo, char	*srATR, short ivCardSeat);

/**********************************************************************************************
6  HD_ClosePort
�ر��豸���ú����ر���HD_OpenPort�����򿪵��豸��
unsigned short HD_ClosePort(
	HANDLE devNo
)

����˵��
devNo				��HD_OpenPort���ص��豸��

����ֵ
��������0x9000��ʾ��ȷ�� ����ֵ��ʾ������������Ϣ������ġ�������Ϣ������
***********************************************************************************************/
//HDIFD20B_API unsigned short CCONV HD_ClosePort(short ivPort,HANDLE devNo);
HDIFD20B_API unsigned short CCONV HD_ClosePort(HANDLE devNo);

/**********************************************************************************************
7  HD_PowerOn
�����ϵ硣�ϵ�����󣬿���Vcc�ܽ�Ϊ5V,CLK�ܽ��ṩһ��3.684MHz���ȶ�ʱ�ӣ�RST�ܽ�Ϊ�͵�ƽ��I/O�ܽ�Ϊ�ߵ�ƽ��

unsigned short  HD_PowerOn(
HANDLE 		devNo,
short  		ivCardSeat	//USB�ӿڲ�ʹ��
)

����˵��
devNo			    ��HD_OpenPort���ص��豸��
ivCardSeat		    �����š�1����������2:������

����ֵ
��������0x9000��ʾ��ȷ�� ����ֵ��ʾ������������Ϣ������ġ�������Ϣ������

ע������
�ú��������󣬿����ڸ�λ״̬����RST�ܽ�Ϊ�͵�ƽ��
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_PowerOn(HANDLE devNo, short ivCardSeat);

/**********************************************************************************************
8  HD_PowerOff
�����ϵ硣�ú����ɹ���ɺ󣬿��ĸ��ܽ������������롣

unsigned short HD_PowerOff(
	HANDLE 		devNo,
	short 		ivCardSeat	//USB�ӿڲ�ʹ��
)

����˵��
devNo			��HD_OpenPort���ص��豸��
ivCardSeat		�����š�1����������2:������

����ֵ
��������0x9000��ʾ��ȷ�� ����ֵ��ʾ������������Ϣ������ġ�������Ϣ������
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_PowerOff(	HANDLE 	devNo,short	ivCardSeat);

/**********************************************************************************************
3  HD_SetTimeout
���ó�ʱʱ�䡣���ڷ�ʽ����Ч��

unsigned short HD_SetTimeout(
    HANDLE 		devNo, 
	int 		ivTimeOut,	 // ʱ�䣬��msΪ��λ
	short 		type  		 // TimeOut����
)

����˵��
devNo		 	��HD_OpenPort���ص��豸��
ivTimeOut       ʱ��, ��msΪ��λ
type			TimeOut����(���궨��)��
				type = 0 ����PC�˿ڳ�ʱʱ��(�ȴ������������ݣ�
				type = 1 ���ö��������ڳ�ʱʱ�䣨�ȴ�PC�����ݣ�
				type = 2 ���ÿ���λӦ��ʱʱ�� (�������ȴ�3B��ʱ�䣩
				type = 3 ���ÿ���Ӧ��ʱʱ�� ���ȴ�����һ��״̬�ֽڵ�ʱ�䣩
				type = 4 ���ÿ��ּ�೬ʱʱ�� ���ȴ������������ֽڵ�ʱ�䣩
				��ivTimeOut = 0, PC�˿ڵȴ�ʱ�����޳���ϵͳȱʡֵΪ1s��

����ֵ
��������0x9000��ʾ��ȷ�� ����ֵ��ʾ������������Ϣ������ġ�������Ϣ������
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_SetTimeout( HANDLE devNo,	int ivTimeOut, short type );

/**********************************************************************************************
9 HD_ProbeCard
̽�⿨�����Ƿ��п����ڡ�

unsigned short HD_ProbeCard(
HANDLE 		devNo,
short 		ivCardSeat	//USB�ӿڲ�ʹ��
)		

����˵��
devNo			 ��HD_OpenPort���ص��豸��
ivCardSeat	 	 �����š�1����������2:������

����ֵ
��������0x0000ֵ��ʾ�޿����룬0x9000��ʾ�п�������ֵ��ʾ������������Ϣ������ġ�������Ϣ������
***********************************************************************************************/
//HDIFD20B_API unsigned short CCONV HD_ProbeCard(HANDLE ContextNo, HANDLE devNo,short ivPortNo, short ivCardSeat);		
//HDIFD20B_API unsigned short CCONV HD_ProbeCard(HANDLE ContextNo, short ivPortNo, short ivCardSeat);		
HDIFD20B_API unsigned short CCONV HD_ProbeCard(HANDLE devNo,short	ivCardSeat);		

/**********************************************************************************************
10  HD_ApduT0
�����������,���������APDU Case1 Case2 Case3 Case4��ʽ��ָ�

unsigned short HD_ApduT0(				
    HANDLE 				devNo,
	char 				*apduData,
	short				srAPDULen,
	char 				*respData,
	short				*respDataLen,
	short 				ivCardSeat	//USB�ӿڲ�ʹ��
)

����˵��
devNo				��HD_OpenPort���ص��豸��
apduData			APDU����(�ֽڴ�)��CLA��INS��P1��P2�Լ�һ���ɱ䳤�ȵ�����������ʾ��������Ķ���ΪLc��Data��Lc���ֽڣ���Le��
					����Lc��Leֵ�Ĳ�ͬ����������������������±���ʾ��
					���	�ṹ
					1	CLA INS P1 P2
					2	CLA INS P1 P2 Le
					3	CLA INS P1 P2 Lc Data
					4	CLA INS P1 P2 Lc Data Le
srAPDULen			��ŷ��͵�APDU���ݵĳ���
respData			����Ӧ����
respDataLen			����Ӧ���ݵĳ���
ivCardSeat	 		������

����ֵ
��������0xffXX��ʾ����δ�ɹ�ִ�У�������Ϣ������ġ�������Ϣ����������ֵΪ������Ӧ��
������Case1�� Case2ʱ��respData�����塣������Case3�� Case4ʱ����������0x9000��respData�����壻������Ӧ��respData�����塣
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_ApduT0( HANDLE devNo,  unsigned char *apduData, short srAPDULen, unsigned char *respData, short *respDataLen, short ivCardSeat );
HDIFD20B_API unsigned short CCONV HD_ApduVB( HANDLE devNo, char *apduData, char *respData, short ivCardSeat );

/**********************************************************************************************
11 HD_GetDescriptor
��ȡ�����豸����
   
unsigned short HD_GetDescriptor(		
	HANDLE 		devNo,		
	char 		*descriptor
)

����˵��
devNo			��HD_OpenPort���ص��豸��
descriptor		�����豸��Ϣ,����CI-4��˫����������������Ϣ����Ϊ��CIDC CI-4-1.0-009600��(ʮ�����ƴ�)
				����USBKey��Ӳ�����к��Ƕ�CPU IC����FORMATʱд�뿨�ڵ���ʷ�ֽ�

����ֵ
��������0x9000��ʾ��ȷ����ʱdescriptor��Ч������ֵ��ʾ������������Ϣ������ġ�������Ϣ��������ʱdescriptor������Ч��
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_GetDescriptor( HANDLE devNo, char *descriptor);

HDIFD20B_API unsigned short CCONV HD_GetProtocolType(short *ProtocolType);
/**********************************************************************************************
3.HD_GetReaderNames
�����豸���������ͨ/USB KEY ͨѶǰ�����ȴ��豸��
unsigned short HD_GetReaderNames(
	HANDLE ContextNo,				//������
	unsigned long * ReaderNo,		//����ֵ���豸��ʶ�б�
	ReaderList * readerinfo,		//����ֵ���豸����
	unsigned long * ReaderCount		//����ֵ���豸����
)
��������˵��
struct ReaderList
{
	char ReaderName[50];		//����������
	unsigned long ReaderID;		//��������ʶ
} readerinfo;��

����˵��
ContextNo		������
ReaderNo 		����ֵ���豸��ʶ�б���
readerinfo		����ֵ���豸��Ϣ��	
ReaderCount		����ֵ���豸������


����ֵ
��������0x9000��ʾ��ȷ����ʱdevNo��Ч������ֵ��ʾ������������Ϣ������ġ�������Ϣ������
***********************************************************************************************/
HDIFD20B_API unsigned short CCONV HD_GetReaderNames(char *ReaderNames, int *Count);

HDIFD20B_API unsigned short CCONV HD_OpenPort2(short ReaderID, unsigned long ivBaud, short ivParity, HANDLE *devNo);
void DebugMessage(const char * message);