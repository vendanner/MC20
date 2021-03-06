#include "include.h"


//********************************宏定义************************************

#define EepromPramID_SIZE (sizeof(EepromPramAddress)/sizeof(EepromPramAddress[0]))


//********************************全局变量**********************************
/////////////////////
const unsigned long c_usEepromPramID[] = 
{
    E2_FIRMWARE_VERSION_ID,             //版本号,特殊处理,不用写,
    E2_TERMINAL_HEARTBEAT_ID,           //01参数ID0x0001，终端心跳发送间隔，单位秒，默认值60
    E2_MAIN_SERVER_APN_ID,              //02参数ID0x0010，主服务器APN
    E2_MAIN_SERVER_DIAL_NAME_ID,        //03参数ID0x0011，主服务器无线通信拨号用户名
    E2_MAIN_SERVER_DIAL_PASSWORD_ID,    //04参数ID0x0012，主服务器无线通信拨号密码
    E2_MAIN_SERVER_IP_ID,               //05参数ID0x0013，主服务器地址，IP或域名
    E2_BACKUP_SERVER_APN_ID,			//06参数ID0x0014,备份服务器APN//无线通信拨号访问点
    E2_BACKUP_SERVER_DIAL_NAME_ID, 		//07参数ID0x0015,备份服务器无线通信拨号用户名
 	E2_BACKUP_SERVER_DIAL_PASSWORD_ID, 	//08参数ID0x0016,备份服务器无线通信拨号密码
	E2_BACKUP_SERVER_IP_ID,				//09参数ID0x0017,备份服务器地址//IP或域名
    E2_MAIN_SERVER_TCP_PORT_ID,         //10参数ID0x0018，主服务器TCP端口
    E2_SLEEP_REPORT_TIME_ID,            //11参数ID0x0027，休眠时汇报时间间隔，单位为秒，默认值为60
    E2_EMERGENCY_REPORT_TIME_ID,		//12参数ID0x0028,紧急报警时汇报时间间隔//单位为秒//默认值为10
    E2_ACCON_REPORT_TIME_ID,            //13参数ID0x0029,缺省时间汇报间隔,单位为秒，默认值为10 
	E2_CORNER_REPORT_ID, 				//14参数ID0x0030,拐点补传角度,单位度/秒//默认值为30
	E2_MONITOR_SERVER_SMS_PHONE_ID,		//0x0043//监控平台SMS电话号码
	E2_SMS_TEXT_ALARM_PHONE_ID,			//	0x0044//SMS文本报警电话号码
	E2_ALARM_MASK_ID, 					//15参数ID0x0050,报警屏蔽字//bit9,11,12默认屏蔽,LCD屏故障,TTS故障,IC卡模块故障默认为屏蔽
	E2_MAX_SPEED_ID, 					//16参数ID0x0055,最高速度,单位km/h,DWORD,默认值130,九通需求为100
	E2_OVER_SPEED_KEEP_TIME_ID, 		//17参数ID0x0056,超速持续时间,单位为秒,DWORD,默认为10秒,九通需求为立马上报
	E2_SET_CRASH_ALARM_ID,				//18参数ID0x005D,碰撞报警参数设置,碰撞加速度默认设置为4g
	E2_SET_ROLLOVER_ALARM_ID,	        //19参数ID0x005E,侧翻报警参数设置：侧翻角度，单位1 度，默认为45 度
	E2_CAR_TOTAL_MILE_ID,				//20参数ID0x0080，车辆里程表读数，0.1km
	E2_CAR_PROVINCE_ID, 				//21参数ID0x0081,车辆所在的省域ID
	E2_CAR_CITY_ID, 					//22参数ID0x0082,车辆所在的市域ID
	E2_CAR_PLATE_NUM_ID, 				//23参数ID0x0083,公安交通管理部门颁发的机动车号牌
	E2_CAR_PLATE_COLOR_ID, 				//24参数ID0x0084,车牌颜色//按照JT/T415-2006的5.4.12,1:蓝色,2:黄色,3:黑色,4:白色,9:其它
    E2_GPS_SET_MODE_ID,                 //25参数ID0x0090 GNSS 定位模式，默认为北斗定位
	E2_LOGINGPRS_PASSWORD_ID,			//26参数ID0xF200+0x00，自定义，鉴权码
	E2_MANUFACTURE_ID,					//27参数ID0xF205，自定义，制造商ID，5字节	
    E2_DEVICE_ID,                       //28参数ID0xF200+0x06，自定义，厂商终端ID，7字节
    E2_DEVICE_PHONE_ID,                 //29参数ID0xF200+0x07，自定义，终端手机号，6字节
    E2_CAR_VIN_ID,						//30参数ID0xF208，自定义，车辆识别码(VIN)，17字节，ASCII码
    E2_DEFINE_ALARM_MASK_WORD_ID,		//31参数ID0xF243，自定义，自定义报警屏蔽字，DWORD
    E2_DEFINE_HARD_VER_ID,				//32参数ID0x0001F0004，自定义，自定义硬件版本号，DWORD
    E2_SMS_ALARM_PHONE_NUM_ID,			//参数ID 0x0001F005，自定义，自定义用户短信报警电话，DWORD
	E2_SMS_OPERATE_PWD_ID,				//参数ID 0x0001F006，自定义，自定义用户短信操作密码，DWORD
	E2_LOW_VOL_THRESHOLD_ID,			//参数ID 0x0001F00F，自定义，自定义低电压阈值，WORD
};
////////////////////////
const u8 EepromPramLength[] = 
{
    0,
    E2_TERMINAL_HEARTBEAT_LEN,          //01参数ID0x0001，终端心跳发送间隔，单位秒，默认值60
    E2_MAIN_SERVER_APN_LEN,             //02参数ID0x0010，主服务器APN
    E2_MAIN_SERVER_DIAL_NAME_LEN,       //03参数ID0x0011，主服务器无线通信拨号用户名
    E2_MAIN_SERVER_DIAL_PASSWORD_LEN,   //04参数ID0x0012，主服务器无线通信拨号密码
    E2_MAIN_SERVER_IP_LEN,              //05参数ID0x0013，主服务器地址，IP或域名
	E2_BACKUP_SERVER_APN_LEN,			//06参数ID0x0014,备份服务器APN//无线通信拨号访问点
	E2_BACKUP_SERVER_DIAL_NAME_LEN,		//07参数ID0x0015,备份服务器无线通信拨号用户名
	E2_BACKUP_SERVER_DIAL_PASSWORD_LEN,	//08参数ID0x0016,备份服务器无线通信拨号密码
	E2_BACKUP_SERVER_IP_LEN, 			//09参数ID0x0017,备份服务器地址//IP或域名
    E2_MAIN_SERVER_TCP_PORT_LEN,        //10参数ID0x0018，主服务器TCP端口
    E2_SLEEP_REPORT_TIME_LEN,           //11参数ID0x0027，休眠时汇报时间间隔，单位为秒，默认值为60
	E2_EMERGENCY_REPORT_TIME_LEN,		//12参数ID0x0028,紧急报警时汇报时间间隔//单位为秒//默认值为10
    E2_ACCON_REPORT_TIME_LEN,           //13参数ID0x0029缺省时间汇报间隔,单位为秒，默认值为10
	E2_CORNER_REPORT_LEN, 				//14参数ID0x0030,拐点补传角度,单位度/秒//默认值为30
	E2_MONITOR_SERVER_SMS_PHONE_LEN,    //参数ID0x0043，监控平台SMS电话号码
	E2_SMS_TEXT_ALARM_PHONE_LEN,		//0x0044//SMS文本报警电话号码
	E2_ALARM_MASK_LEN,					//15参数ID0x0050,报警屏蔽字//bit9,11,12默认屏蔽,LCD屏故障,TTS故障,IC卡模块故障默认为屏蔽
	E2_MAX_SPEED_LEN, 					//16参数ID0x0055,最高速度,单位km/h,DWORD,默认值130,九通需求为100
	E2_OVER_SPEED_KEEP_TIME_LEN,		//17参数ID0x0056,超速持续时间,单位为秒,DWORD,默认为10秒,九通需求为立马上报
	E2_SET_CRASH_ALARM_LEN,				//18参数ID0x005D,碰撞报警参数设置,碰撞加速度默认设置为4g
	E2_SET_ROLLOVER_ALARM_LEN,			//19参数ID0x005E,侧翻报警参数设置：侧翻角度，单位1 度，默认为45 度
	E2_CAR_TOTAL_MILE_LEN,				//20参数ID0x0080，车辆里程表读数，0.1km
	E2_CAR_PROVINCE_LEN,				//21参数ID0x0081,车辆所在的省域ID
	E2_CAR_CITY_LEN,					//22参数ID0x0082,车辆所在的市域ID
	E2_CAR_PLATE_NUM_LEN, 				//23参数ID0x0083,公安交通管理部门颁发的机动车号牌
	E2_CAR_PLATE_COLOR_LEN,				//24参数ID0x0084,车牌颜色//按照JT/T415-2006的5.4.12,1:蓝色,2:黄色,3:黑色,4:白色,9:其它
    E2_GPS_SET_MODE_LEN,                //25参数ID0x0090 GNSS 定位模式，默认为北斗定位   
	E2_LOGINGPRS_PASSWORD_ID_LEN,		//26参数ID0xF200+0x00，自定义，鉴权码
	E2_MANUFACTURE_ID_LEN,				//27参数ID0xF205，自定义，制造商ID，5字节	
    E2_DEVICE_ID_LEN,                   //28参数ID0xF200+0x06，自定义，厂商终端ID，7字节
    E2_DEVICE_PHONE_ID_LEN,             //29参数ID0xF200+0x07，自定义，终端手机号，6字节
    E2_CAR_VIN_ID_LEN,					//30参数ID0xF208，自定义，车辆识别码(VIN)，17字节，ASCII码
    E2_DEFINE_ALARM_MASK_WORD_ID_LEN,	//31参数ID0xF243，自定义，自定义报警屏蔽字，DWORD
    E2_DEFINE_HARD_VER_ID_LEN,			//32参数ID0x0001F0004，自定义，自定义硬件版本号，DWORD
	E2_SMS_ALARM_PHONE_NUM_ID_LEN,		//参数ID 0x0001F005，自定义，自定义用户短信报警电话�
	E2_SMS_OPERATE_PWD_ID_LEN,			//参数ID 0x0001F006，自定义，自定义用户短信操作密码
	E2_LOW_VOL_THRESHOLD_ID_LEN,		//参数ID 0x0001F00F，自定义，自定义低电压阈值，WORD
};
//////////只能为0或1////////////
const u8 EepromPramSwitch[] = 
{
    0,
    0,		//01参数ID0x0001，终端心跳发送间隔，单位秒，默认值60
    1,		//02参数ID0x0010，主服务器APN
    1,      //03参数ID0x0011，主服务器无线通信拨号用户名
    1,      //04参数ID0x0012，主服务器无线通信拨号密码
    1,		//05参数ID0x0013，主服务器地址，IP或域名
	1,		//06参数ID0x0014，备份服务器APN，无线通信拨号访问点
	1,		//07参数ID0x0015，备份服务器无线通信拨号用户名
	1,		//08参数ID0x0016，备份服务器无线通信拨号密码
	1,		//09参数ID0x0017，备份服务器地址，IP或域名
    0,		//10参数ID0x0018，主服务器TCP端口
    0,		//11参数ID0x0027，休眠时汇报时间间隔，单位为秒，默认值为60
    0,		//12参数ID0x0028,紧急报警时汇报时间间隔//单位为秒//默认值为10
    0,		//13参数ID0x0029，缺省时间汇报间隔,单位为秒，默认值为10  
	0,		//14参数ID0x0030，拐点补传角度,单位度/秒，默认值为15
	1,		//0x0043//监控平台SMS电话号码
	1,		//0x0044//SMS文本报警电话号码
	0,		//15参数ID0x0050，报警屏蔽字，默认为全开
	0,		//16参数ID0x0055，最高速度
	0,		//17参数ID0x0056，超速持续时间，单位为秒，默认为10秒
    0,		//18参数ID0x005D,碰撞报警参数设置 
    0,		//19参数ID0x005E,侧翻报警参数设置：侧翻角度，单位1 度，默认为30 度
	0,		//20参数ID0x0080，车辆里程表读数，0.1km
	0,		//21参数ID0x0081，车辆所在的省域ID
	0,		//22参数ID0x0082，车辆所在的市域ID
	1,		//23参数ID0x0083，公安交通管理部门颁发的机动车号牌
	0,		//24参数ID0x0084，车牌颜色，按照JT/T415-2006的5.4.12
    0,      //25参数ID0x0090 GNSS 定位模式，默认为北斗定位
	1,		//26参数ID0xF200+0x00，自定义，鉴权码
	1,		//27参数ID0xF200+0x05，自定义，制造商ID，5字节
	1,		//28参数ID0xF200+0x06，自定义，厂商终端ID，7字节
	1,		//29参数ID0xF200+0x07，自定义，终端手机号，6字节
	1,		//30参数ID0xF200+0x08，自定义，车辆识别码
	0,		//31参数ID0xF200+0x43，自定义，自定义报警屏蔽字，DWORD
	1,		//32参数ID0x0001F0004，自定义，自定义硬件版本号，DWORD
	1,		//参数ID 0x0001F005，自定义，自定义用户短信报警电话�
	1,		//参数ID 0x0001F006，自定义，自定义用户短信操作密码
	0,		//参数ID 0x0001F00F，自定义，自定义低电压阈值，WORD
};
const u16 EepromPramAddress[] = 
{
    0,
    E2_TERMINAL_HEARTBEAT_ADDR,             //01参数ID0x0001，终端心跳发送间隔，单位秒，默认值60
    E2_MAIN_SERVER_APN_ADDR,                //02参数ID0x0010，主服务器APN  
    E2_MAIN_SERVER_DIAL_NAME_ADDR,          //03参数ID0x0011，主服务器无线通信拨号用户名
    E2_MAIN_SERVER_DIAL_PASSWORD_ADDR,      //04参数ID0x0012，主服务器无线通信拨号密码
    E2_MAIN_SERVER_IP_ADDR,                 //05参数ID0x0013，主服务器地址，IP或域名  
	E2_BACKUP_SERVER_APN_ADDR,				//06参数ID0x0014，备份服务器APN，无线通信拨号访问点
	E2_BACKUP_SERVER_DIAL_NAME_ADDR,		//07参数ID0x0015，备份服务器无线通信拨号用户名
	E2_BACKUP_SERVER_DIAL_PASSWORD_ADDR,	//08参数ID0x0016，备份服务器无线通信拨号密码
	E2_BACKUP_SERVER_IP_ADDR,				//09参数ID0x0017，备份服务器地址，IP或域名
    E2_MAIN_SERVER_TCP_PORT_ADDR,           //10参数ID0x0018，主服务器TCP端口 
    E2_SLEEP_REPORT_TIME_ADDR,              //11参数ID0x0027，休眠时汇报时间间隔，单位为秒，默认值为60    
    E2_EMERGENCY_REPORT_TIME_ADR,			//12参数ID0x0028,紧急报警时汇报时间间隔//单位为秒//默认值为10
    E2_ACCON_REPORT_TIME_ADDR,              //13参数ID0x0029 缺省时间汇报间隔,单位为秒，默认值为10  
    E2_CORNER_REPORT_ADDR,					//14参数ID0x0030，拐点补传角度,单位度/秒，默认值为15
    E2_MONITOR_SERVER_SMS_PHONE_ADDR,       //参数ID0x0043，监控平台SMS电话号码
    E2_SMS_TEXT_ALARM_PHONE_ADDR,			//0x0044//SMS文本报警电话号码
	E2_ALARM_MASK_ADDR,						//15参数ID0x0050，报警屏蔽字，默认为全开
	E2_MAX_SPEED_ADDR,						//16参数ID0x0055，最高速度
	E2_OVER_SPEED_KEEP_TIME_ADDR,			//17参数ID0x0056，超速持续时间，单位为秒，默认为10秒
	E2_SET_CRASH_ALARM_ADDR,				//18参数ID0x005D//碰撞报警参数设置 
	E2_SET_ROLLOVER_ALARM_ADDR,				//19参数ID0x005E//侧翻报警参数设置：侧翻角度，单位1 度，默认为30 度
	E2_CAR_TOTAL_MILE_ADDR,					//20参数ID0x0080，车辆里程表读数，0.1km	
	E2_CAR_PROVINCE_ID_ADDR,				//21参数ID0x0081，车辆所在的省域ID
	E2_CAR_CITY_ID_ADDR,					//22参数ID0x0082，车辆所在的市域ID
	E2_CAR_PLATE_NUM_ADDR,					//23参数ID0x0083，公安交通管理部门颁发的机动车号牌
	E2_CAR_PLATE_COLOR_ADDR,				//24参数ID0x0084，车牌颜色，按照JT/T415-2006的5.4.12
    E2_GPS_SET_MODE_ADDR,                   //25参数ID0x0090,GNSS 定位模式，默认为北斗定位    
   	E2_LOGINGPRS_PASSWORD_ID_ADDR,			//26参数ID0xF200+0x00，自定义，鉴权码
	E2_MANUFACTURE_ID_ADDR,					//27参数ID0xF200+0x05，自定义，制造商ID，5字节
	E2_DEVICE_ID_ADDR,						//28参数ID0xF200+0x06，自定义，厂商终端ID，7字节
	E2_DEVICE_PHONE_ID_ADDR,				//29参数ID0xF200+0x07，自定义，终端手机号，6字节
	E2_CAR_VIN_ID_ADDR,						//30参数ID0xF200+0x08，自定义，车辆识别码
	E2_DEFINE_ALARM_MASK_WORD_ID_ADDR,		//31参数ID0xF200+0x43，自定义，自定义报警屏蔽字，DWORD
	E2_DEFINE_HARD_VER_ID_ADDR,				//32参数ID0x0001F0004，自定义，自定义硬件版本号，DWORD
	E2_SMS_ALARM_PHONE_NUM_ID_ADDR, 		//参数ID 0x0001F005，自定义，自定义用户短信报警电话
	E2_SMS_OPERATE_PWD_ID_ADDR,     		//参数ID 0x0001F006，自定义，自定义用户短信操作密码 
	E2_LOW_VOL_THRESHOLD_ID_ADDR,			//参数ID 0x0001F00F，自定义，自定义低电压阈值，WORD
};

/*************************************************************
** 函数名称: Eepromflash_ReadBytes
** 功能描述: 读字节操作
** 入口参数: Address读的起始地址,*data 读出数据存放地址指针,len 读的字节数
** 出口参数: 
** 返回参数: 
** 全局变量: 
** 调用模块: 
*************************************************************/	
u8 E2prom_ReadBytes(char* lpFileName,unsigned long Address, unsigned char *data, unsigned short len)
{
	s32 ret=0;
	s32 handle=-1;
	u32 hasreadenLen = 0;//已经写入文件的字节数，初始值为零

	handle = Ql_FS_Open(lpFileName,QL_FS_READ_ONLY);
	 if(handle<0)
	 {
		 APP_DEBUG("\r\n<--The %s file does not exist,handle:%d-->\r\n",lpFileName,handle);
		 handle = Ql_FS_Open(lpFileName,QL_FS_READ_ONLY);
		 if(handle<0)
		  {
			  APP_DEBUG("\r\n<--The %s file does not exist,handle:%d-->\r\n",lpFileName,handle);
			  return 0;
		  }
	 }
	 ret = Ql_FS_Seek(handle,Address,QL_FS_FILE_BEGIN); 
	 ret = Ql_FS_Read(handle, data, len, &hasreadenLen);
	 /*
	 APP_DEBUG("\r\n<--Eepromflash_ReadBytes  ret =%d  hasreadenLen =%d-->\r\n",ret,hasreadenLen);
	 if(len>5)
	 {
		APP_DEBUG("\r\n<--E2prom_ReadBytes len=%d Address=%d	Data=%s-->\r\n",len,Address,data);
 	}
 	else
 	{
 		APP_DEBUG("\r\n<--E2prom_ReadBytes len=%d Address=%d Data=%d",len,Address,data[0]);
 		u8 i;
 		for(i=1;i<len;i++)
 			{
 			APP_DEBUG("%d",data[i]);
 			}
 		APP_DEBUG("-->\r\n");
 	 }
 	 */
 	 Ql_FS_Close(handle);//close the file
	if(ret==QL_RET_OK)
	{
		return len;
	}
	else
	{
		return 0;
	}
}
/*************************************************************
** 函数名称: Eepromflash_WriteBytes
** 功能描述: 写字节操作
** 入口参数: Address写的起始地址,*data 写入数据存放地址指针,len 写的字节数
** 出口参数: 
** 返回参数: 1:成功，0:失败
** 全局变量: 
** 调用模块: 
*************************************************************/
unsigned char E2prom_WriteBytes(char* lpFileName,unsigned long Address, unsigned char *data,unsigned short len)
{
s32 ret=0;
s32 handle=-1;
u32 haswritenLen = 0;//已经写入文件的字节数，初始值为零

handle = Ql_FS_Open(lpFileName,QL_FS_READ_WRITE);
if(handle<0)
{
   APP_DEBUG("\r\n<--The %s file does not exist,handle:%d-->\r\n",lpFileName,handle);
   handle = Ql_FS_Open(lpFileName,QL_FS_READ_WRITE);
	if(handle<0)
	{
	   APP_DEBUG("\r\n<--The %s file does not exist,handle:%d-->\r\n",lpFileName,handle);
	   return 0;
	}
}
ret = Ql_FS_Seek(handle,Address,QL_FS_FILE_BEGIN);	//seek end 
ret = Ql_FS_Write(handle, data, len, &haswritenLen);
//APP_DEBUG("\r\n<--!! Function (E2prom_WriteBytes)  ret =%d  haswritenLen =%d-->\r\n",ret,haswritenLen);
//APP_DEBUG("%s",data);
/*
if(len>5)
{
APP_DEBUG("\r\n<--E2prom_WriteBytes len=%d Address=%d	Data=%s-->\r\n",len,Address,data);
}
else
{
	APP_DEBUG("\r\n<--E2prom_WriteBytes len=%d Address=%d Data=%d",len,Address,data[0]);
	u8 i;
	for(i=1;i<len;i++)
		{
		APP_DEBUG("-%d",data[i]);
		}
	APP_DEBUG("-->\r\n");
}
*/
Ql_FS_Flush(handle); //fflush强制缓存写入文件
Ql_FS_Close(handle);//close the file
return haswritenLen;
}

u8 FRAM_BufferWrite(unsigned short WriteAddr,unsigned char *pBuffer,unsigned short  NumBytesToWrite) 
{
	E2prom_WriteBytes(PRAM_FILE_NAME,WriteAddr, pBuffer, NumBytesToWrite);
}

u8 FRAM_BufferRead(unsigned char *pBuffer,unsigned short NumBytesToRead,unsigned long ReadAddr) 
{
	return	E2prom_ReadBytes(PRAM_FILE_NAME,ReadAddr,pBuffer,NumBytesToRead);
}

//********************************本地变量**********************************
/*************************************************************OK
** 函数名称: EepromPram_ConvertParamIDToIndex
** 功能描述: 二分法检索，返回要查找的记录
** 入口参数: 
** 出口参数: 返回要查找的Index
** 返回参数: 
** 全局变量: 无
** 调用模块:
*************************************************************/
unsigned char EepromPram_ConvertParamIDToIndex(unsigned int ParamID)//
{
    unsigned char index=0;
    ///////////////
    for(index = 1; index<EepromPramID_SIZE;index++)
    {
        if(ParamID==c_usEepromPramID[index])return index;;//找到ID跳出
    }
	return 0;
}

/*********************************************************************
//函数名称	:EepromPram_WritePram
//功能		:写eeprom参数
//输入		:PramID:参数ID;pBuffer:指向数据（待写入的字节流,写入的是数值的话则高字节应在前）的指针;
//		    :BufferLen:数据的长度
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:写入正确时，返回的长度等于BufferLen;写入错误时，返回0,此时可尝试再调用该函数写一次
*********************************************************************/
u16 EepromPram_WritePramEx(unsigned short index, u8 *pBuffer, u8 BufferLen)
{
    u8	VerifyByte;
    u8	sum;
    u8	len;
    u8	Buffer[52];
    u8	tmp[52];
    u8	PramType;//0为值,1为字符串
    u16	Address;
    //////////////////
    if(0==index)//不认识的ID
    {
        return 0;//先暂时不做
    }
    //判断长度是否正确
    if((BufferLen > EepromPramLength[index])||(0 == BufferLen))
    {
        return 0;//长度或参数ID出错
    }
    //////////////////////////////    
    //求校验和//为实际内容的累加和
    VerifyByte = Public_GetSumVerify(pBuffer,BufferLen);
    //获取参数类型
    PramType = EepromPramSwitch[index];
    //**************写参数****************
    //获取地址
    Address = EepromPramAddress[index];
	//APP_DEBUG("\r\n<--WritePramID Address=%d  PramType =%d-->\r\n",Address,PramType);
    //////////////////////
    len = 0;
    ////////////////
    if(PramType)//写的是字符串,//第一个字节写入字符串的长度
    {
        PramType = 1;
        Buffer[len++] = BufferLen;
    }
    ////////内容写入到eeprom/////////////
    memcpy(&Buffer[len],pBuffer,BufferLen);
    len +=BufferLen;
    //写入校验字节
    Buffer[len++] = VerifyByte;
    //结果写入到eeprom
    //APP_DEBUG("长度...%d..%d....%04x",index,BufferLen,Address);
	//if(index==36)
	//{
	//	Address = E2_TERMINAL_HEARTBEAT_ADDR;
	//}
    E2prom_WriteBytes(PRAM_FILE_NAME,Address,Buffer,len);
    //**************读参数****************
    if(BufferLen > 49)return BufferLen;//字节数大于等于30字节的直接返回,不校验
    ///////////////
    //读出写入的内容，长度和校验字节除外
    E2prom_ReadBytes(PRAM_FILE_NAME,Address+PramType, tmp, BufferLen+1);
	/*
		if(PramType==1)
			{
	 		APP_DEBUG("\r\n<--E2prom_ReadBytes len=%d Address=%d Data=%c",BufferLen+1,Address+PramType,tmp[0]);
 		u8 i;
 		for(i=1;i<BufferLen+1;i++)
 			{
 			APP_DEBUG("%c",tmp[i]);
 			}
 		APP_DEBUG("-->\r\n");
			}
		else
			{
	 		APP_DEBUG("\r\n<--E2prom_ReadBytes len=%d Address=%d Data=%d",BufferLen+1,Address+PramType,tmp[0]);
 		u8 i;
 		for(i=1;i<BufferLen+1;i++)
 			{
 			APP_DEBUG("-%d",tmp[i]);
 			}
 		APP_DEBUG("-->\r\n");
			}
			*/
    //计算读出数据的校验和
    sum  = Public_GetSumVerify(tmp,BufferLen);
    //比较校验和
    if((sum == VerifyByte)&&(tmp[BufferLen]==VerifyByte))
    {
        return BufferLen;
    }
    ///////校验出错,再写多一遍/////////
    E2prom_WriteBytes(PRAM_FILE_NAME,Address,Buffer,len);
    ////////////
    return 0; 
}
/*********************************************************************
//函数名称	:EepromPram_WritePram(u32 PramID, u8 *pBuffer, BufferLen)
//功能		:写eeprom参数
//输入		:PramID:参数ID;pBuffer:指向数据（待写入的字节流,写入的是数值的话则高字节应在前）的指针;
//		:BufferLen:数据的长度
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:写入正确时，返回的长度等于BufferLen;写入错误时，返回0,此时可尝试再调用该函数写一次
*********************************************************************/
u16 EepromPram_WritePram(u32 PramID, u8 *pBuffer, u8 BufferLen)
{
    unsigned char index;
//APP_DEBUG("\r\n<--WritePramID:=%d-->\r\n",PramID);
    index = EepromPram_ConvertParamIDToIndex(PramID); 
//APP_DEBUG("\r\n<--WritePramID_INDEX:=%d-->\r\n",index);
    return EepromPram_WritePramEx(index,pBuffer,BufferLen);
}
/*********************************************************************
//函数名称	:EepromPram_ReadPram(u32 PramID, u8 *pBuffer)
//功能		:读eeprom参数
//输入		:PramID:参数ID;pBuffer:指向数据（读出的字节流，读出的是数值则高字节在前）的指针;
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:返回值>0表示正确读出，返回值==0表示读错误;
*********************************************************************/
u16 EepromPram_ReadPramEx(unsigned long pramID,unsigned short index, u8 *pBuffer)
{
    u16	Address;
    u8 PramType;
    u8 length;    
    u8 sum;
    u8 Buffer[52];
    /////////////////////////
    if(0==index)return 0;//先暂时不做//不认识的ID
    ///////////////
    if(0 == EepromPramLength[index])//参数ID号为保留的
    {
        return 0;
    }
    ///////////////
    Address = EepromPramAddress[index];
    ///////////////////
    PramType = EepromPramSwitch[index];
	
    if(PramType)
    {
    	//if(index == 36)
		//	Address = E2_TERMINAL_HEARTBEAT_ADDR;
        E2prom_ReadBytes(PRAM_FILE_NAME,Address, Buffer, 1);
        length = Buffer[0];//长度
        //APP_DEBUG("长度...%d..%d...%04x",index,length,Address);
        Address++;		
    }
    else
    {
        length = EepromPramLength[index];
    }
	
    ///////////////
    if(length > 49) return 0;   
    //按长度再读取数据和校验字节
    E2prom_ReadBytes(PRAM_FILE_NAME,Address, Buffer, length+1);
    //计算校验和
    sum = Public_GetSumVerify(Buffer,length);
    if(sum == Buffer[length])//校验正确
    {//APP_DEBUG("\r\n校验正确.....%d\r\n",length)
    		//if(pramID == E2_DEVICE_PHONE_ID)Buffer[0] &= 0x0f;
        memcpy(pBuffer,Buffer,length);
        return length;
    }
    ////////////
    pBuffer[0]=0;
    return 0;
}
/*********************************************************************
//函数名称	:EepromPram_ReadPram(u32 PramID, u8 *pBuffer)
//功能		:读eeprom参数
//输入		:PramID:参数ID;pBuffer:指向数据（读出的字节流，读出的是数值则高字节在前）的指针;
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:返回值>0表示正确读出，返回值==0表示读错误;
*********************************************************************/
u16 EepromPram_ReadPram(u32 PramID, u8 *pBuffer)
{
    unsigned char index;    
    index = EepromPram_ConvertParamIDToIndex(PramID);
    return EepromPram_ReadPramEx(PramID,index,pBuffer);
}
/*********************************************************************
//函数名称	:EepromPram_UpdateVariable(u16 PramID)
//功能		:更新PramID变量
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:千万注意:EepromPram_UpdateVariable(E2_CAR_TOTAL_MILE_ID)不可随便调用，只能在设置完E2_CAR_TOTAL_MILE_ID后调用              
*********************************************************************/
void EepromPram_UpdateVariable(u32 PramID)
{
	u8	Buffer[30];
	u8	BufferLen;
	u32	temp;
       
	switch(PramID)
	{
	case E2_TERMINAL_HEARTBEAT_ID:		
		{
			HeartBeat_UpdatePram();
			break;
		}//参数ID0x0001，终端心跳发送间隔，单位秒，默认值60
	case E2_MAIN_SERVER_APN_ID:	
                {
                        break;
                }//参数ID0x0010，主服务器APN
	//E2_MAIN_SERVER_DIAL_NAME_ID:			//参数ID0x0011，主服务器无线通信拨号用户名
	//E2_MAIN_SERVER_DIAL_PASSWORD_ID:		//参数ID0x0012，主服务器无线通信拨号密码
	//E2_MAIN_SERVER_IP_ID:				//参数ID0x0013，主服务器地址，IP或域名
	//E2_BACKUP_SERVER_APN_ID:			//参数ID0x0014，备份服务器APN，无线通信拨号访问点
	//E2_BACKUP_SERVER_DIAL_NAME_ID:		//参数ID0x0015，备份服务器无线通信拨号用户名
	//E2_BACKUP_SERVER_DIAL_PASSWORD_ID:		//参数ID0x0016，备份服务器无线通信拨号密码
	//E2_BACKUP_SERVER_IP_ID:			//参数ID0x0017，备份服务器地址，IP或域名
	//E2_MAIN_SERVER_TCP_PORT_ID:			//参数ID0x0018，主服务器TCP端口
	//E2_MAIN_SERVER_UDP_PORT_ID:			//参数ID0x0019，主服务器UDP端口
	//E2_BACKUP_SERVER_TCP_PORT_ID:		//参数ID0x001a，备份服务器TCP端口
	//E2_BACKUP_SERVER_UDP_PORT_ID:		//参数ID0x001b，备份服务器UDP端口
	//E2_REGISTER_SMS_CENTER_NUM_ID:		//参数ID0x001C，注册短信中心号码
	//E2_PRIVILEGE_SMS_CENTER_NUM_ID:		//参数ID0x001D，控制短信号码（特权）
	//0,0,						//参数ID0x001E~0x001f，保留
	case E2_SLEEP_REPORT_TIME_ID://0X0027 更新ACC OFF汇报时间间隔
		{
			Report_UpdatePram();
			break;
		}
	case E2_EMERGENCY_REPORT_TIME_ID://0X0028 更新紧急报警时汇报时间间隔
		{
			//Report_UpdateOnePram(PRAM_EMERGENCY_REPORT_TIME);
			//Report_UpdatePram();
			break;
		}
	case E2_ACCON_REPORT_TIME_ID://0X0029 更新ACC ON汇报时间间隔
		{
			Report_UpdatePram();
			//Report_UpdateOnePram(PRAM_ACC_ON_REPORT_TIME);
			break;
		}
	case E2_CORNER_REPORT_ID://参数ID0x0030，拐点补传角度,单位度/秒，默认值为15
		{
			//Corner_UpdataPram();
			break;
		}
	case E2_ALARM_MASK_ID://参数ID0x0050，报警屏蔽字，默认为全开
	case E2_DEFINE_ALARM_MASK_WORD_ID://参数ID，自定义，自定义报警屏蔽字，DWORD
		{
			Io_UpdataPram();
            //Photo_UpdatePram();
			break;
		}
	case E2_MAX_SPEED_ID://参数ID0x0055，最高速度
		{
             //Overspeed_UpdateParameter(); //正常使用
			break;
		}
	case E2_OVER_SPEED_KEEP_TIME_ID://参数ID0x0056，超速持续时间，单位为秒，默认为10秒
		{
              //Overspeed_UpdateParameter();//正常使用

			break;
		}
        case E2_SET_CRASH_ALARM_ID:	//参数ID0x005D,碰撞报警参数设置
		{
			//UpdataBmaAppPra();
			break;
		}
        case E2_SET_ROLLOVER_ALARM_ID:	//参数ID0x005E,侧翻报警参数设置：侧翻角度，单位1 度，默认为30 度 
		{
			//BMA250_UpdataRollOverAlarmParam();
			//UpdataBmaAppPra();
			break;
		}            
	case E2_CAR_TOTAL_MILE_ID:	//参数ID0x0080，车辆里程表读数，0.1km,千万注意:EepromPram_UpdateVariable(E2_CAR_TOTAL_MILE_ID)不可随便调用，只能在设置完E2_CAR_TOTAL_MILE_ID后调用                                  			
		{
			//读取刚刚设置的里程
			EepromPram_ReadPram(E2_CAR_TOTAL_MILE_ID,Buffer);//0.1公里为单位
			temp = 0;
			temp |= Buffer[0] << 24;
			temp |= Buffer[1] << 16;
			temp |= Buffer[2] << 8;
			temp |= Buffer[3];
			//设置初始里程
			GpsMile_SetPram(temp);
			
			break;
		}           
        case E2_GPS_SET_MODE_ID://参数ID0x0090,GNSS 定位模式，默认为0x02 北斗定位	
		{
              //GnssCheckChangePar();
			
			break;
		}
	case E2_MANUFACTURE_ID://参数IDE2_PRAM_BASE_CUSTOM_ID+0x05，自定义，制造商ID，5字节				
		{
			BufferLen = EepromPram_ReadPram(E2_MANUFACTURE_ID, Buffer);
			if(0 == BufferLen)
			{
			
			}
			break;
		}
	case E2_DEVICE_ID://参数IDE2_PRAM_BASE_CUSTOM_ID+0x06，自定义，终端ID，7字节
		{
			BufferLen = EepromPram_ReadPram(E2_DEVICE_ID, Buffer);
			if(0 == BufferLen)
			{
			
			}
			break;
		}
	case E2_DEVICE_PHONE_ID://参数IDE2_PRAM_BASE_CUSTOM_ID+0x07，自定义，终端手机号，6字节
		{
			//RadioProtocol_UpdateTerminalPhoneNum();
			break;
		}
	case E2_MONITOR_SERVER_SMS_PHONE_ID:
			{
				UpSmsMonitorPhoNum();
				break;
			}
	case E2_SMS_ALARM_PHONE_NUM_ID:
			{
				UpSmsAlarmPhoNum();
				break;
			}
		default:	
          break;
	}

}

/*********************************************************************
//函数名称	:EepromPram_DefaultSet(void)
//功能		:系统第1次运行时的默认设置
//输入		:
//输出		:
//使用资源	:
//全局变量	:   
//调用函数	:
//中断资源	:  
//返回		:
//备注		:使用恢复默认出厂设置也会将参数设置为如下所示
*********************************************************************/
void EepromPram_DefaultSet(void)
{
    u32	temp=0;
	u8	Buffer[31]={0};
	u8	BufferLen=0;
    
    //0x0001	终端心跳发送间隔//单位秒//默认值50//60会主动断线
    temp = 50;//60会主动断线
    Public_ConvertLongToBuffer(temp, Buffer);
    EepromPram_WritePram(E2_TERMINAL_HEARTBEAT_ID, Buffer, E2_TERMINAL_HEARTBEAT_LEN); 

	//0x0010	   主服务器APN
	strcpy((char *)Buffer,"cmnet");
	BufferLen = strlen((char const *)Buffer);
	if(0 == EepromPram_WritePram(E2_MAIN_SERVER_APN_ID, Buffer, BufferLen))
	{
		EepromPram_WritePram(E2_MAIN_SERVER_APN_ID, Buffer, BufferLen);
	}
	//0x0011  主服务器无线通信拨号用户名
	strcpy((char *)Buffer,"card");
	BufferLen = strlen((char const *)Buffer);
	if(0 == EepromPram_WritePram(E2_MAIN_SERVER_DIAL_NAME_ID, Buffer, BufferLen))
	{
		EepromPram_WritePram(E2_MAIN_SERVER_DIAL_NAME_ID, Buffer, BufferLen);
	}
	//0x0012  主服务器无线通信拨号密码
	strcpy((char *)Buffer,"card");
	BufferLen = strlen((char const *)Buffer);
	if(0 == EepromPram_WritePram(E2_MAIN_SERVER_DIAL_PASSWORD_ID, Buffer, BufferLen))
	{
		EepromPram_WritePram(E2_MAIN_SERVER_DIAL_PASSWORD_ID, Buffer, BufferLen);
	}

	//0x0014 备份服务器APN
	strcpy((char *)Buffer,"cmnet");
	BufferLen = strlen((char const *)Buffer);
	if(0 == EepromPram_WritePram(E2_BACKUP_SERVER_APN_ID, Buffer, BufferLen))
	{
		EepromPram_WritePram(E2_BACKUP_SERVER_APN_ID, Buffer, BufferLen);
	}
	//0x0015 备份服务器无线通信拨号用户名
	strcpy((char *)Buffer,"card");
	BufferLen = strlen((char const *)Buffer);
	if(0 == EepromPram_WritePram(E2_BACKUP_SERVER_DIAL_NAME_ID, Buffer, BufferLen))
	{
		EepromPram_WritePram(E2_BACKUP_SERVER_DIAL_NAME_ID, Buffer, BufferLen);
	}
	//0x0016 备份服务器无线通信拨号密码
	strcpy((char *)Buffer,"card");
	BufferLen = strlen((char const *)Buffer);
	if(0 == EepromPram_WritePram(E2_BACKUP_SERVER_DIAL_PASSWORD_ID, Buffer, BufferLen))
	{
		EepromPram_WritePram(E2_BACKUP_SERVER_DIAL_PASSWORD_ID, Buffer, BufferLen);
	}	 
    //0x0027	休眠时汇报时间间隔//单位为秒//默认值为1200
    temp = 1200;
    Public_ConvertLongToBuffer(temp, Buffer);
    if(0 == EepromPram_WritePram(E2_SLEEP_REPORT_TIME_ID, Buffer, E2_SLEEP_REPORT_TIME_LEN))
    {
        EepromPram_WritePram(E2_SLEEP_REPORT_TIME_ID, Buffer, E2_SLEEP_REPORT_TIME_LEN);
    }

    //0x0028	紧急报警时汇报时间间隔//单位为秒//默认值为10
    temp = 10;
    Public_ConvertLongToBuffer(temp, Buffer);
    if(0 == EepromPram_WritePram(E2_EMERGENCY_REPORT_TIME_ID, Buffer, E2_EMERGENCY_REPORT_TIME_LEN))
    {
        EepromPram_WritePram(E2_EMERGENCY_REPORT_TIME_ID, Buffer, E2_EMERGENCY_REPORT_TIME_LEN);
    }

    //0x0029	缺省时间汇报间隔,单位为秒,默认为30
    temp = 30;
    Public_ConvertLongToBuffer(temp, Buffer);
    if(0 == EepromPram_WritePram(E2_ACCON_REPORT_TIME_ID, Buffer, E2_ACCON_REPORT_TIME_LEN))
    {
        EepromPram_WritePram(E2_ACCON_REPORT_TIME_ID, Buffer, E2_ACCON_REPORT_TIME_LEN);
    }
    //0x0030	拐点补传角度,单位度/秒//默认值为30
    temp = 30;
    Public_ConvertLongToBuffer(temp, Buffer);
    if(0 == EepromPram_WritePram(E2_CORNER_REPORT_ID, Buffer, E2_CORNER_REPORT_LEN))
    {
        EepromPram_WritePram(E2_CORNER_REPORT_ID, Buffer, E2_CORNER_REPORT_LEN);
    }
    //0x0050	报警屏蔽字//bit9,11,12默认屏蔽,LCD屏故障,摄像头故障,IC卡模块故障,VSS连接异常默认为屏蔽
    temp = 0x01001a00;
    Public_ConvertLongToBuffer(temp, Buffer);
    if(0 == EepromPram_WritePram(E2_ALARM_MASK_ID, Buffer, E2_ALARM_MASK_LEN))
    {
        EepromPram_WritePram(E2_ALARM_MASK_ID, Buffer, E2_ALARM_MASK_LEN);
    }
    //0x0055	最高速度,单位km/h,DWORD,默认值100km/h
    temp = 100;
    Public_ConvertLongToBuffer(temp, Buffer);
    if(0 == EepromPram_WritePram(E2_MAX_SPEED_ID, Buffer, E2_MAX_SPEED_LEN))
    {
        EepromPram_WritePram(E2_MAX_SPEED_ID, Buffer, E2_MAX_SPEED_LEN);
    }
    //0x0056	超速持续时间,单位为秒,DWORD,默认为10秒,九通要求立马上报
    temp = 10;
    Public_ConvertLongToBuffer(temp, Buffer);
    if(0 == EepromPram_WritePram(E2_OVER_SPEED_KEEP_TIME_ID, Buffer, E2_OVER_SPEED_KEEP_TIME_LEN))
    {
        EepromPram_WritePram(E2_OVER_SPEED_KEEP_TIME_ID, Buffer, E2_OVER_SPEED_KEEP_TIME_LEN);
    }
    //0x005D	碰撞报警参数设置,碰撞时间默认为4ms,碰撞加速度默认设置为4g
    temp = 0x2801;//4g,4ms
    Public_ConvertShortToBuffer(temp, Buffer);//modify by joneming
    if(0 == EepromPram_WritePram(E2_SET_CRASH_ALARM_ID, Buffer, E2_SET_CRASH_ALARM_LEN))
    {
        EepromPram_WritePram(E2_SET_CRASH_ALARM_ID, Buffer, E2_SET_CRASH_ALARM_LEN);
    }
    //0x005E	侧翻报警参数设置：侧翻角度，单位1 度，默认为45 度
    temp = 45;//45度
    Public_ConvertShortToBuffer(temp, Buffer);//modify by joneming
    if(0 == EepromPram_WritePram(E2_SET_ROLLOVER_ALARM_ID, Buffer, E2_SET_ROLLOVER_ALARM_LEN))
    {
        EepromPram_WritePram(E2_SET_ROLLOVER_ALARM_ID, Buffer, E2_SET_ROLLOVER_ALARM_LEN);
    }
    //0x0080,累计行驶里程清0,车辆里程表读数, 单位0.1km
    temp = 0;
    Public_ConvertLongToBuffer(temp, Buffer);
    if(0 == EepromPram_WritePram(E2_CAR_TOTAL_MILE_ID, Buffer, E2_CAR_TOTAL_MILE_LEN))
    {
        EepromPram_WritePram(E2_CAR_TOTAL_MILE_ID, Buffer, E2_CAR_TOTAL_MILE_LEN);
    }

    //0x0090  GNSS 定位模式，默认为0x03 北斗定位+GPS，全国货运平台联调设置
    temp = 3;
    Buffer[0] = temp;//modify by joneming
    if(0 == EepromPram_WritePram(E2_GPS_SET_MODE_ID, Buffer, E2_GPS_SET_MODE_LEN))
    {
        EepromPram_WritePram(E2_GPS_SET_MODE_ID, Buffer, E2_GPS_SET_MODE_LEN);
    }
    //参数ID 0xF205，自定义，制造商ID，5字节	制造商ID,默认为70108
    strcpy((char *)Buffer,"70108");
    if(0 == EepromPram_WritePram(E2_MANUFACTURE_ID, Buffer, E2_MANUFACTURE_ID_LEN))
    {
        EepromPram_WritePram(E2_MANUFACTURE_ID, Buffer, E2_MANUFACTURE_ID_LEN);
    }

	//0x0001f006 用户短信操作密码
	strcpy((char *)Buffer,"123456");
	BufferLen = strlen((char const *)Buffer);
	if(0 == EepromPram_WritePram(E2_SMS_OPERATE_PWD_ID, Buffer, BufferLen))
	{
		EepromPram_WritePram(E2_SMS_OPERATE_PWD_ID, Buffer, BufferLen);
	}

	//0x0001f00f 低电压关机电压
	temp = 3500;//3500mv
    Public_ConvertShortToBuffer(temp, Buffer);
	if(0 == EepromPram_WritePram(E2_LOW_VOL_THRESHOLD_ID, Buffer, E2_LOW_VOL_THRESHOLD_ID_LEN))
	{
		EepromPram_WritePram(E2_LOW_VOL_THRESHOLD_ID, Buffer, E2_LOW_VOL_THRESHOLD_ID_LEN);
	}
}
/*************************************************************OK
** 函数名称: EepromPram_GetLenEepromPramID
** 功能描述: 
** 入口参数: 
** 出口参数: 
** 返回参数: 
** 全局变量: 无
** 调用模块:
*************************************************************/
unsigned short EepromPram_GetLenEepromPramID(void)
{
    return EepromPramID_SIZE;
}


