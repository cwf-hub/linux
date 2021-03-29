#ifndef _DATA_ASSIST_H_
#define _DATA_ASSIST_H_

typedef unsigned int	uint;			///< sizeof(uint) == sizeof(int) == 4
typedef unsigned char	uchar;	

//error code
enum XMSDK_RETURN_CODE	//
{
	XMSDK_SUCCESS	= 0,
	XMSDK_NOT_SUPPORT_STREAM = -1000,
	XMSDK_NOT_SUPPORT_CHANNEL = -1001,
	XMSDK_CAPTURE_FAIL = -1002,
	XMSDK_NO_INIT = -1003,
	XMSDK_ILLEGAL_PARAM = -1004,
	XMSDK_TIMEOUT = -1005,
	XMSDK_INVALID_HANDLE = -1006,
	XMSDK_IN_PLAYING = -1007,
	XMSDK_NOT_FOUND_FILE = -1008,
	XMSDK_GET_DATA_FAIL = -1009,
	XMSDK_NOT_IN_PLAYING = -1010,
	XMSDK_CREATE_FILE_FAIL = -1011,
	XMSDK_SET_DATA_FAIL = -1012,
	XMSDK_VERSION_DISMATCH = -1013,
	XMSDK_NOT_SUPPORT_FUNCTION = -1014,
	XMSDK_OVER_SIZE = -1015,
	XMSDK_NEED_REBOOT = -1016,
	XMSDK_INIT_FAIL = -1017,
	XMSDK_ALLOC_FAIL = -1018,
};

enum XMSDK_STREAM_TYPE {
	SDK_CAPTURE_CHN_MAIN = 0,
	SDK_CAPTURE_CHN_2END = 1,
	SDK_CAPTURE_CHN_3IRD = 2,
	SDK_CAPTURE_CHN_4RTH = 3,
	SDK_CAPTURE_CHN_JPEG = 4,
	SDK_CAPTURE_CHN_NR
};

typedef struct {
	unsigned int	version;
	/*SDK������ڣ���ʽΪYYYYMMDD*/
	unsigned int date;            
	/*SDK���ʱ�䣬��ʽΪHHMMSS*/
	unsigned int time;
	/*�����־������ϣ�˵��SDK�ڵ�ǰ�汾���������޸�,��û�м�¼����ʱ�汾*/
	unsigned char plus;
	unsigned char	reserved[11];
} XMSDK_VERSION_S;

/// FrameType
enum FRAME_TYPE {
	FRAME_VIDEO = 1,
	FRAME_AUDIO = 2,
	FRAME_DATA = 3
};

/// FrameSubType
enum FRAME_SUB_TYPE {
	I_FRAME = 0,
	P_FRAME = 1,
	B_FRAME = 2,
	S_FRAME = 3,
	DATA_TEXT = 5,
	DATA_TNTL = 6
};


/// ��������
enum ENCODE_TYPE {
	StreamTypeEmpty = 0,
	StreamTypeH264 = 2,
	StreamTypeJpeg = 3,
	StreamTypeGeneral = 4,
	StreamTypePCM8 = 7,
	StreamTypeStd = 8,
	StreamTypeH265 = 9
};

typedef struct {

	unsigned char *pHeader;				///< buffer header address
	unsigned char *pContent;            ///< frame data address
	unsigned long nLength;              ///< packet len
	unsigned long nFrameLength;         ///< frame len

	unsigned int FrameType;            ///< refer to FRAME_TYPE
	unsigned int nSubType;             ///< refer to FRAME_SUB_TYPE

	unsigned int nEncodeType;		///ENCODE_TYPE

	unsigned long nYear;				///< timestamp
	unsigned long nMonth;
	unsigned long nDay;
	unsigned long nHour;
	unsigned long nMinute;
	unsigned long nSecond;
	unsigned long nMsecond;	
	unsigned long nTimeStamp;	

	unsigned int  nFrameRate;			///< frame rate
	int nWidth;							///< video resolution��width and height
	int nHeight;
	unsigned long nRequence;

	unsigned int nChannels;
	unsigned int nBitsPerSample;		///< audio sample bit depth
	unsigned int nSamplesPerSecond;		///< audio sample rate

	unsigned long nParam1;		// 
	unsigned long nParam2;		// 
	unsigned long version;		// �汾��
	unsigned long reserved[10];	// ��չ��
} XMSDK_VIDEO_FRAME_INFO_S;

enum SDK_CaptureBitrateControlType 
{
	SDK_CAPTURE_BITRATE_CBR,			///< fixed bitrate
	SDK_CAPTURE_BITRATE_VBR,			///< Variable bitrate
	SDK_CAPTURE_BITRATE_NR				///< 
};

enum SDK_CaptureCompressType 
{
	SDK_CAPTURE_COMPRESS_MJPG,			
	SDK_CAPTURE_COMPRESS_H264,			
	SDK_CAPTURE_COMPRESS_H265,			
	SDK_CAPTURE_COMPRESS_NR				
};

typedef struct {
	int		iCompression;			/*refer to SDK_CaptureCompressType*/
	int     iWidth;                 /*����ͼ��Ŀ�*/
	int     iHeight;                /*����ͼ��ĸ�*/
	int		iBitRateControl;		/*refer to SDK_CaptureBitrateControlType*/
	int		iQuality;				/*refer to SDK_CaptureImageQuality*/
	int		nFPS;					/*֡��*/
	int		nBitRate;				
	int		iGOP;					/*I֡���*/
	int		iQpMax;
	int		iQpMin;
} XMSDK_VIDEO_FORMAT_S;

typedef struct {
	int bEnable[SDK_CAPTURE_CHN_NR];
	XMSDK_VIDEO_FORMAT_S stFormat[SDK_CAPTURE_CHN_NR];
} XMSDK_VIDEOENCODE_S;

/*
 * �����Ҫʹ���������룬�붼��ֵSDK_AUDIO_ENCODE_PCM
 * ���������Ľӿ�ʵ�ֱ����
 */
enum SDK_AudioEncodeTypes
{
	SDK_AUDIO_ENCODE_NONE = 0,
	SDK_AUDIO_ENCODE_PCM,
	SDK_AUDIO_ENCODE_G711_ALAW,
	SDK_AUDIO_ENCODE_G711_ULAW,
	SDK_AUDIO_ENCODE_TYPES_NR
};

enum SDK_AudioSoundModes
{
    SDK_AUDIO_SOUND_MODE_MONO   =0,/*mono*/
    SDK_AUDIO_SOUND_MODE_STEREO =1,/*stereo*/
};

typedef struct {
	/*�����ʣ�HzΪ��λ������8000Hz,44100Hz*/
	int iSampleRate;   
	/*������λ�� һ�����16*/
	int iSampleBit;    
	/*���뷽ʽ������SDK_AudioEncodeTypes����*/
	int iEncodeType;
	/*��˫ͨ��*/
	int iSoundmode;
	/*ÿ֡����*/
	int iPtNumPerFrm;
} XMSDK_AUDIO_FORMAT_S;

typedef struct {
	int bAecOpen;/*�Ƿ�����������*/	
	int bAnrOpen;/*�Ƿ�����������*/
	int bAgcOpen;/*�Ƿ����Զ�����*/
	int reserved[5];
} XMSDK_AUDIO_VQE_S;

typedef struct {
	unsigned char gain;/*����*/
} XMSDK_VOLUMN_S;

typedef struct {
	unsigned long nYear;				///< timestamp
	unsigned long nMonth;
	unsigned long nDay;
	unsigned long nHour;
	unsigned long nMinute;
	unsigned long nSecond;
	unsigned long nMsecond;
} XMSDK_TIMESTAMP_S;


typedef struct {
	//0��Ӧʱ����⣬1��Ӧͨ�����⣬2��3����������
	int		index;

	/// �Ƿ���ʾ��0-����ʾ�������������ԣ�1-��ʾ��
	int		enable;

	/// �������Ͻ�x���꣬ȡ8�����������������������ϵ(CIF)��
	unsigned short	x;		

	/// �������Ͻ�y���꣬�������������ϵ(CIF)��
	unsigned short	y;

	/// �����ȣ������ص�ĸ�����ȡ8����������
	unsigned short	width;		

	/// ����߶ȣ������ص�ĸ�����ȡ8����������
	unsigned short	height;	

	/// ǰ����ɫ��16���Ʊ�ʾΪ0xAABBGGRR��A(Alpha)��ʾ͸���ȡ�
	/// text color, rgba 8:8:8:8	
	unsigned int	fg_color;

	/// ������ɫ��16���Ʊ�ʾΪ0xAABBGGRR��A(Alpha)��ʾ͸���ȡ�
	/// background color, rgba 8:8:8:8	
	unsigned int	bg_color;

	//��ɫ��ʽ����ö��ֵGraphicsColorFormat������
	unsigned int    color_format;

	/// ����������ɫֵ�����color_format��ֵΪgraphicsColorRGB555��
	/// ����Ҫ�����ֽ�����ʾһ�����ص���ɫ������pixel�������������
	/// Ӧ���� (width * height * 2)�ֽڡ�
	/// ���pixel��NULL������indexΪ0�����ʾ�ɵײ���Լ�����������ʱ����⡣
	unsigned char	*pixel;
} XMSDK_OSD_TITLE_PARAM_S;


//��������ͷ����
//�ع�����
typedef struct {
	int  level;    //�ع�ȼ�
	uint leastTime;//�Զ��ع�ʱ�����޻��ֶ��ع�ʱ�䣬��λ΢��
	uint mostTime; //�Զ��ع�ʱ�����ޣ���λ΢��
} XMSDK_EXPOSURE_PARAM_S;

//��������
typedef struct{
	int gain;    //�Զ���������(�Զ���������)��̶�����ֵ
	int autoGain;//�Զ������Ƿ����ã�0:������  1:����
} XMSDK_GAIN_PARAM_S;


typedef enum REJECT_FLICKER_FREQ
{
	REJECT_FLICKER_50HZ,    //��ǰ�����޷���ʱ,������Ч
	REJECT_FLICKER_60HZ,    //��ǰ�����޷���ʱ,������Ч
	REJECT_FLICKER_DISABLE,
	REJECT_FLICKER_FORCE_50HZ,  //ǿ�Ʒ���,��ǰ�����޷���ʱ����
	REJECT_FLICKER_FORCE_60HZ   //ǿ�Ʒ���,��ǰ�����޷���ʱ����
} XMSDK_REJECT_FLICKER_FREQ_E;

typedef enum {
	XMSDK_IRCUT_SYN_INFRARED,
	XMSDK_IRCUT_SWITCH_AUTO,
	XMSDK_INFRARED_ON,
	XMSDK_INFRARED_OFF
} XMSDK_IRCUT_MODE_E;

//��������ͷ����
typedef struct {
	uint whiteBalance;          //��ƽ��
	uint dayNightColor;         //��ҹģʽ��ȡֵ�в�ɫ���Զ��л��ͺڰ�(0�Զ� 1�� 2��)
	int  elecLevel;             //�ο���ƽֵ
	uint apertureMode;          //�Զ���Ȧģʽ
	uint BLCMode;               //���ⲹ��ģʽ
	uint BLCLevel;               //���ⲹ��ǿ��
    XMSDK_EXPOSURE_PARAM_S exposureParam;//�ع�����
	XMSDK_GAIN_PARAM_S     gainParam;    //��������
	uint PictureFlip;		//ͼƬ���·�ת
	uint PictureMirror;	//ͼƬ���ҷ�ת
	XMSDK_REJECT_FLICKER_FREQ_E RejectFlicker;	//�չ�Ʒ�������
	uint EsShutter;		//���������Ź���
	int ircut_mode;		// XMSDK_IRCUT_MODE_E
	int dnc_thr;			//��ҹת����ֵ
	int ae_sensitivity;	//ae����������
	int Day_nfLevel;		//noise filter �ȼ���0-5,0���˲���1-5 ֵԽ���˲�Ч��Խ����
	int Night_nfLevel;
	int Ircut_swap;		//ircut ������= 0        ����= 1
} XMSDK_CAMERA_PARAM_S;

typedef struct {
    int mode;
    int enable;
    int holdTimeSec;
} XMSDK_CAMERA_LED_PARAM_S;

typedef struct {
	unsigned short left; 
	unsigned short top;
	unsigned short right;
	unsigned short bottom;
} XMSDK_RECT_S;

typedef struct {
	XMSDK_RECT_S rect;
	unsigned int color;
	unsigned int enable;
} XMSDK_VIDEO_COVER_PARAM_S;

typedef struct {
	int  year;		///< �ꡣ   
	int  month;		///< �£�January = 1, February = 2, and so on.   
	int  day;			///< �ա�   
	int  wday;		///< ���ڣ�Sunday = 0, Monday = 1, and so on   
	int  hour;		///< ʱ��   
	int  minute;		///< �֡�   
	int  second;		///< �롣   
	int  isdst;		///< ����ʱ��ʶ��   
} XMSDK_SYSTEM_TIME_S;

typedef struct {
	int left; 
	int top; 
	int fontSize; //0:16  1:24  2:32  3:48  pixel
    int magn;   //0-16 �Ŵ���,0Ĭ��
	int fgTrans; //0 - 100   (0��ʾ��ȫ͸��)
	int bgTrans;//0 - 100   (0��ʾ��ȫ͸��)
	int fgColor; //0xAABBGGRR   AA=00
	int bgColor; //0xAABBGGRR  AA=00
	char index;		//���ڱ��Ҫ�޸��ĸ�OSD��ʱ����ⲻ���������ֵ����������ȡֵ��Χ1~5
	char res[3];	//
} XMSDK_OSD_PARAM_S; 

enum ALARM_MSG_TYPE {
	ALARM_IO,              /*IO����, ״̬��Ӧλ�ø�,��ʾ��ӦIO�ڱ���*/
	ALARM_MOTION,          /*���챨��, ״̬1����*/
	ALARM_LOSS,            /*��Ƶ��ʧ, ״̬1����*/
	ALARM_BLIND,           /*�ڵ�, ״̬1����*/
	ALARM_IRCUT,           /*IR-CUT�л�, ״̬1��ʾ�˺��⣬0��ʾ���˺���*/
	ALARM_UPDATE,          /*�������������˶�������*/
	ALARM_NUM
};

typedef struct {
	int nChannel;           /*ͨ����,Ŀǰ��Ϊ0*/
	int nType;              /*��Ϣ����,��ALARM_MSG_TYPE*/
	unsigned long uStatus;            /*״̬*/
} XMSDK_ALARM_MSG_S;

/*Ŀǰ֧�ֵķ�Χ7*7����*/
#define XMSDK_MD_LINE_MAX 7
#define XMSDK_MD_ROWS_MAX 18 

typedef struct {
	/*
	 * ÿһ�������Ա��ʾˮƽһ���е�����,��Ա��ǰ�ģ������������
	 * ÿһ�����Ա��һ������λ��ʾһ���������
	 * ����λ�ɵ�λ����λ����ʾ��������������,�ȴ�λ�ø߱�ʾѡ�ϣ��õͱ�ʾδѡ
	 */
	unsigned int win[XMSDK_MD_ROWS_MAX];

	int level; /*�����ȵȼ�1~6*/

	int enable;

} XMSDK_MD_PARAM_S;

typedef struct {
    unsigned int enable;
    unsigned int rows;
	unsigned int columns;
} XMSDK_MD_CAPS_S;

typedef struct {
    int level;  /*�����ȵȼ�,0-3��*/
    int enable;
} XMSDK_BD_PARAM_S;

typedef struct {
    int enable;
} XMSDK_BD_CAPS_S;

typedef enum {
    WIFI_UNKONW,
    WIFI_XM711,
    WIFI_XM712,
    WIFI_RTL8188EU,
    WIFI_SS6051,
    WIFI_XM713G,
    NR_WIFI_TYPE
} XMSDK_WIFI_TYPE_E;

typedef enum {
    WIFI_MODE_MANAG,
    WIFI_MODE_MONIT,
} XMSDK_WIFI_MODE_E;

typedef struct {
    char mac[18];
    char hostIP[16];
    char mask[16];
    char gatewayIP[16];
} XMSDK_NET_ATTR_S;

typedef struct {
    char    bssid[18];     // BSSID xx:xx:xx:xx:xx:xx
    char    ssid[128];      // SSID 
    char    passwd[128];    // ����
    int     channel;        //
    int     signal;         // 0-100
    int     connected;      //��ʶ�豸�Ƿ����� (sdk������)
    int     hidden;         //��ʶ�豸�Ƿ����� (�ݲ�֧��)
    int     signal_level;   //�źż��� (�ݲ�֧��)
    int     noise_level;    //��������dBm (�ݲ�֧��)
    int     open;           //0: ������ 1������ 
} XMSDK_WIFI_S;

typedef struct {
    int count;
    XMSDK_WIFI_S *stWifiBuf;
} XMSDK_WIFI_LIST_S;

typedef struct {
    char ssid[128];
    char passwd[128];
    int channel;
    char hostIP[256];
} XMSDK_AP_S;

typedef enum {
    SD_INEXST = 1,  //SD��������
    SD_ABNORMAL,    //SD��������
    SD_NORMAL       //SD������
} XMSD_SD_STATUS_E;

typedef struct {
    char MountPath[128];	/*SD��Ҫ���ص�·��*/
    char DevName[32];		/*��ʽ����SD��������,��ֻ֧��fat��8�ַ�����*/
} XMSDK_SD_INIT_PARAM_S;

typedef struct {
    char DevName[128];          //dev����
    unsigned long capacity;     //������ ��λ: K bytes
    unsigned long remain;       //ʣ������ 
} XMSDK_SD_STORAGE_S;

typedef enum {
    XMSDK_LED_RL,
    XMSDK_LED_RLAUTO,
    XMSDK_LED_WL,
    XMSDK_LED_WLAUTO,
    XMSDK_LED_SMART,
} XMSDK_CAMERA_LED_MODE_E;

typedef struct {
     unsigned int ResultType;  /*�������*/
     unsigned int AlarmFlag; /*������־*/
     unsigned int TargetNum; /*Ŀ����(����/����) */
} XMSDK_AI_RESULT_S;
   
typedef struct {
    unsigned int id;
    unsigned int width;
    unsigned int height;
    unsigned int PhyAddr;
    char *pVirAddr;
    unsigned int length;
    unsigned long long pts;
} XMSDK_YUV_FRAME_S;

typedef enum {
    _4G_STATE_CONNECTED,		/*4Gģ�������ɹ�*/
    _4G_STATE_CONNECT_FAILED, 	/*4Gģ������ʧ��*/
    _4G_STATE_ABNORMAL,			/*4Gģ���쳣*/
    _4G_STATE_UNEXIST,			/*4Gģ��δʶ��*/
    _4G_STATE_NO_SIMCARD,		/*4Gģ��ûSIM��*/
} XMSDK_4G_STATE_TYPE_E;

typedef enum {
    CMD_4G_GET_CARD_ID,			/*��ȡ����*/
    CMD_4G_GET_HOST_IP,			/*��ȡIP��ַ*/
    CMD_4G_GET_SIGNAL_STRENGTH,	/*��ȡ�ź�ǿ��, level 0-3*/
    CMD_4G_GET_REGISTER_STATUS,	/*��ȡע��״̬,ע��1��ûע��0*/
    CMD_4G_GET_NETWORK_TYPE,	/*��ȡ��Ӫ�����ͣ� 2/3/4G*/
    MAX_4G_PARAM_TYPE_NR
} XMSDK_4G_CMD_TYPE_E;

typedef struct {
	unsigned int level;         /*ռ�ձ� 0~100*/
	unsigned int freq;          /*Ƶ�� 12000000/65536 ~ 12000000/100*/
	unsigned int resv[2];
} XMSDK_PWM_PARAM_S;

typedef struct {
	unsigned char	brightness;		/*���ȣ�ȡֵ0-100*/
	unsigned char	contrast;		/*�Աȶȣ�ȡֵ0-100*/
	unsigned char 	saturation;		/*���Ͷȣ�ȡֵ0-100*/
	unsigned char 	hue;			/*ɫ����ȡֵ0-100*/
	unsigned char 	gain;			/*���棬ȡֵ0-100��bit7��λ��ʾ�Զ����棬����λ������*/
	unsigned char	WhiteBalance;	/*�Զ��׵�ƽ���ƣ�bit7��λ��ʾ�����Զ�����.0x0,0x1,0x2�ֱ�����,��,�ߵȼ�*/
	unsigned short	acutance;       /*��ȣ�ȡֵ0-15, ��8λ��ʾˮƽ��ȣ���8Ϊ��ʾ��ֱ���*/
} XMSDK_PICTURE_COLOR_S;

typedef struct {
    char FileName[128];
    unsigned int size;
} XMSDK_LOG_PARAM_S;


typedef enum {
    HOTPLUG_EVENT_NONE,
    HOTPLUG_EVENT_SDIO,         //SDIO�¼�
    HOTPLUG_EVENT_USB,          //USB�¼�
} XMSDK_HOTPLUG_EVENT_TYPE_E;

typedef enum {
    HOTPLUG_DEVICE_NONE,
    HOTPLUG_DEVICE_SDCARD,         //SD��,��ҪӲ��֧��
    HOTPLUG_DEVICE_NIC,            //����
} XMSDK_HOTPLUG_DEVICE_TYPE_E;

typedef struct {
    int EventType;           /*ʱ�����ͣ��ο�: XMSDK_HOTPLUG_EVENT_TYPE_E*/
    int DevType;            /*�豸���ͣ��ο�: XMSDK_HOTPLUG_DEVICE_TYPE_E*/
    int status;             /*���״̬, 0: �Ȱ�  1: add �Ȳ�*/
    char DevName[32];       /*�豸��, �磺mmcblock0/eth2��*/
} XMSDK_HOTPLUG_EVENT_PARAM_S;

typedef enum {
    FILESYSTEM_SD_INEXST,  //SD��������
    FILESYSTEM_UNKOWN,  //δ֪����
    FILESYSTEM_VFAT,    //fat/fat32
    FILESYSTEM_EXFAT, 
    FILESYSTEM_EXT4,  
    FILESYSTEM_NTFS,  
} XMSD_FILESYSTEM_TYPE_E;

typedef enum {
    SAFESYSTEM_RUN_FAILED = -1,
    SAFESYSTEM_CMD_SUCCESS = 0,
    SAFESYSTEM_CMD_FAILED
} XMSDK_SAFESYSTEM_STATUS_E;

typedef void *hMemory;

/*******************************************************************
 *  �ص��ӿ�
 *	����: �����ڴ�
 * 	����:[out]phandle �ڴ���
 * 	     [out]buffer [in]size
 * 	     [in]boundary ��0ʱ��memalign�ӿڵ�boundaryһ��
 * 	���أ�0 �ɹ�
 * 		  <0 ʧ��
 *******************************************************************/
typedef int (*fXMSDKMemoryAlloc) (hMemory *phandle, unsigned char **buffer, unsigned int size, unsigned int boundary);


/*******************************************************************
 *  �ص��ӿ�
 *	����: �ͷ��ڴ������ڴ����ü���
 * 	����:[in]handle �ڴ���
 * 	���أ�0 �ɹ�
 * 		  <0 ʧ��
 *******************************************************************/
typedef int (*fXMSDKMemoryRelease) (hMemory handle);


/*******************************************************************
 *  �ص��ӿ�
 *	����: �����ڴ����ü���
 * 	����:[in]handle �ڴ���
 * 	���أ�0 �ɹ�
 * 		  <0 ʧ��
 *******************************************************************/
typedef int (*fXMSDKMemoryAddRef) (hMemory handle);


/*******************************************************************
 *  �ص��ӿ�
 *	����: �����ڴ�ʹ���˵ĳ���
 * 	����:[in]handle �ڴ���
 * 	     [in]len 
 * 	���أ�0 �ɹ�
 * 		  <0 ʧ��
 *******************************************************************/
typedef int (*fXMSDKMemorySetLength) (hMemory handle, unsigned int len);

typedef struct {
	fXMSDKMemoryAlloc  fMemoryAlloc;
	fXMSDKMemoryRelease fMemoryRelease;
	fXMSDKMemoryAddRef fMemoryAddRef;
	fXMSDKMemorySetLength fMemorySetLength;
} XMSDK_MEMORY_API_S;


/*******************************************************************
 *  �ص��ӿ�
 *	����: ע��󣬻�ȡ��H264/H265���ݾͻ�ص��ýӿ�
 * 	����: [in] nChannel
 *        [in] nStream �ο�XMSDK_STREAM_TYPE
 *        [in] mhandle
 * 	���أ�	0 �ɹ�
 * 			<0 ʧ��
 *******************************************************************/
typedef int(*fRealDataCallBack) (int nChannel, int nStream, XMSDK_VIDEO_FRAME_INFO_S *pFrameInfo, hMemory mhandle);


/*******************************************************************
 *  �ص��ӿ�
 *	����: ע�������Ӧ�ı����ͻ�ص��ýӿ�
 * 	����:[in] pMsg �ο�XMSDK_ALARM_MSG
 * 	     [in] dwUser �û��Զ�������
 * 	���أ�	0 �ɹ�
 * 			<0 ʧ��
 *******************************************************************/
typedef int(*fAbnormalCallBack) (XMSDK_ALARM_MSG_S *pMsg, unsigned long dwUser);


/*******************************************************************
 *  �ص��ӿ�
 *	����: ע�������Ƶ����ͻ�ص��ýӿ�
 * 	����:[in] mhandle 
 * 	     [in] pTime �ο�XMSDK_TIMESTAMP
 * 	���أ�	0 �ɹ�
 * 			<0 ʧ��
 *******************************************************************/
typedef int(*fAudioInCallBack) (hMemory mhandle, XMSDK_TIMESTAMP_S *pTime);


/*******************************************************************
 *  �ص��ӿ�
 *	����: ע��󣬻�ȡ��YUV���ݾͻ�ص��ýӿ�
 * 	����:[in] mhandle
 * 	     [in] dwUser �û��Զ�������
 * 	���أ�	0 �ɹ�
 * 			<0 ʧ��
 *******************************************************************/
typedef int(*fYUVCallBack) (hMemory mhandle, unsigned long dwUser);

/*******************************************************************
 *  �ص��ӿ�
 *	����: ע������ܾ���ģʽ����øýӿ�
 * 	����:[in] pstAIRsult ������� 
 * 	���أ�	0 �ɹ�
 * 			<0 ʧ��
 *******************************************************************/
typedef int(*fGetAIResultCallBack) (XMSDK_AI_RESULT_S *pstAIRsult);

/*******************************************************************
 *  �ص��ӿ�
 *	����: ע�������Ƶ��������ʱ��ص��ýӿ�
 * 	����:[in] buf ����
 * 	     [out] len ���ݳ���
 * 	���أ�	0 �ɹ�
 * 			<0 ʧ��
 *******************************************************************/
typedef void(*fGetAudioInDataCallBack) (unsigned char *buf, unsigned int len);

/*******************************************************************
 *  �ص��ӿ�
 *	����: ע��󣬴����Ȳ���¼�����øýӿ�
 * 	����:[int] pstHotplug �Ȳ������
 * 	���أ� ��
 *******************************************************************/
typedef void(*fHotplugEventCallBack) (XMSDK_HOTPLUG_EVENT_PARAM_S *pstHotplug);
#endif

