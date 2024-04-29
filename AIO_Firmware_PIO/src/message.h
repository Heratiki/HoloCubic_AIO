#ifndef FILE_MSG_H
#define FILE_MSG_H

#include "stdint.h"
#include <string.h>

// Enumeration for module types
enum MODULE_TYPE : unsigned char
{
    MODULE_TYPE_UNKNOW = 0,                 // Unknown module type
    MODULE_TYPE_CUBIC_FILE_MANAGER,         // Cubic file manager module
    MODULE_TYPE_C_FILE_MANAGER,             // C file manager module
    MODULE_TYPE_CUBIC_SETTINGS,             // Cubic settings module
    MODULE_TYPE_TOOL_SETTINGS               // Tool settings module
};

// Enumeration for action types
enum ACTION_TYPE : unsigned char
{
    AT_UNKNOWN = 0,                         // Unknown action type
    AT_FREE_STATUS,                         // Free status action type

    // Directory actions
    AT_DIR_CREATE,                          // Directory create action
    AT_DIR_REMOVE,                          // Directory remove action
    AT_DIR_RENAME,                          // Directory rename action
    AT_DIR_LIST,                            // Directory list action

    // File actions
    AT_FILE_CREATE,                         // File create action
    AT_FILE_WRITE,                          // File write action
    AT_FILE_READ,                           // File read action
    AT_FILE_REMOVE,                         // File remove action
    AT_FILE_RENAME,                         // File rename action
    AT_FILE_GET_INFO,                       // File get info action

    // Setting actions
    AT_SETTING_SET,                         // Setting set action
    AT_SETTING_GET                          // Setting get action
};

// Message header class
class MsgHead
{
public:
    uint16_t m_header_mark;                 // Header mark
    uint16_t m_msg_len;                     // Message length
    MODULE_TYPE m_from_who;                  // Sender module type
    MODULE_TYPE m_to_who;                    // Receiver module type
    ACTION_TYPE m_action_type;               // Action type

public:
    MsgHead(MODULE_TYPE from_who = MODULE_TYPE_UNKNOW,
            MODULE_TYPE to_who = MODULE_TYPE_UNKNOW);
    ~MsgHead(){};
    bool isLegal();
    uint32_t decode(const uint8_t *msg);
    uint32_t encode(uint8_t *msg);
};

// Enumeration for value types
enum VALUE_TYPE : unsigned char
{
    VALUE_TYPE_UNKNOWN = 0,                 // Unknown value type

    VALUE_TYPE_INT,                         // Integer value type
    VALUE_TYPE_UCHAR,                       // Unsigned char value type
    VALUE_TYPE_STRING                       // String value type
};

// Settings message class
class SettingsMsg
{
public:
    MsgHead m_msg_head;                     // Message header
    char m_prefs_name[15];                   // Preferences name
    char m_key[16];                          // Key
    VALUE_TYPE m_value_type;                 // Value type
    unsigned char m_value[15];               // Value

public:
    SettingsMsg(ACTION_TYPE action_type = AT_SETTING_SET);
    ~SettingsMsg(){};
    bool isLegal();
    uint32_t decode(const uint8_t *msg);
    uint32_t encode(uint8_t *msg);
};

// File system class
class FileSystem
{
public:
    MsgHead m_msg_head;                     // Message header

public:
    FileSystem(ACTION_TYPE action_type = AT_FREE_STATUS);
    ~FileSystem(){};
    uint32_t decode(const uint8_t *msg);
    uint32_t encode(uint8_t *msg);
};

// Directory create class
class DirCreate
{
public:
    FileSystem m_file_system;               // File system object
    char m_dir_path[99];                     // Directory path

public:
    DirCreate(const char *dir_name = NULL);
    ~DirCreate(){};
    uint32_t decode(const uint8_t *msg);
    uint32_t encode(uint8_t *msg);
};

// Directory list class
class DirList
{
public:
    FileSystem m_file_system;               // File system object
    char m_dir_path[99];                     // Directory path
    char m_dir_info[400];                    // Directory info (contains names of child files separated by tabs)

public:
    DirList(const char *dir_path = NULL, const char *dir_info = NULL);
    ~DirList(){};
    uint32_t decode(const uint8_t *msg);
    uint32_t encode(uint8_t *msg);
};

#endif