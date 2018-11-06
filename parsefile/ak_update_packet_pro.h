/*******************************************************************
 * @brief  a protocol to packet update bag
 
 * @Copyright (C), 2017-2018, Anyka Tech. Co., Ltd.
 * @author mic_chen
 * @date 2018-08-16
 * @version 1.0
*******************************************************************/
#ifndef __PCKET_PRO_H__
#define __PCKET_PRO_H__
    
#include <stdint.h>

struct ak_date {
	int year; 		//4 number
	int month;		//1-12
	int day; 		//1-31
	int hour; 		//0-23
	int minute; 	//0-59
	int second; 	//0-59
	int timezone; 	//local time zone 0-23
};


#define UPDATE_FILE_NUM_MAX         (20)
#define UPDATE_FILE_MAGIC_LEN       (32)
#define UPDATE_MD5_CHECK_LEN        (16)
#define UPDATE_VERSION_LEN          (16)



#define UPDATE_NAME_LEN             (6+1)           // burntool use 6,add '\0'
typedef struct update_sub_file_info{
    char            name[UPDATE_NAME_LEN];          // name
    char            version[UPDATE_VERSION_LEN];    // file version
    unsigned int    addr;                           // bin data offset addr
    unsigned int    len;                            // bin data len
}update_sub_file_info_t;

typedef struct update_file              
{
    // header
    char                magic[UPDATE_FILE_MAGIC_LEN];                   // fix to "anyka update"
    unsigned char       md5_check[UPDATE_MD5_CHECK_LEN];                // md5 check for all after this
    
    char                version[UPDATE_VERSION_LEN];
    struct ak_date      date;                                           // file time
    unsigned int        file_num;                                       //                 
    update_sub_file_info_t  psub_file_info[UPDATE_FILE_NUM_MAX];

    // body
    unsigned int                data_len;
    char                        data[];                                 // dynamic array                          
}update_file_t;


#endif

