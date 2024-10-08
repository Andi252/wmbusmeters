// Copyright (C) 2024 Fredrik Öhrström (gpl-3.0-or-later)

// Service access endpoints inside the iu891a dongle that can receive send messages.
#define SAP_DEVMGMT_ID 0x01
#define SAP_WMBUSGW_ID 0x09

#define LINK_MODE_OFF 0
#define LINK_MODE_S 1
#define LINK_MODE_T 2
#define LINK_MODE_CT 3
#define LINK_MODE_C 5
#define LINK_MODE_ENHANCED_T 6

#define DEVMGMT_MSG_PING_REQ 0x01
#define DEVMGMT_MSG_PING_RSP 0x02
#define DEVMGMT_MSG_GET_DEVICE_INFO_REQ 0x03
#define DEVMGMT_MSG_GET_DEVICE_INFO_RSP 0x04
#define DEVMGMT_MSG_GET_FW_INFO_REQ 0x05
#define DEVMGMT_MSG_GET_FW_INFO_RSP 0x06
#define DEVMGMT_MSG_RESTART_REQ 0x07
#define DEVMGMT_MSG_RESTART_RSP 0x08
#define DEVMGMT_MSG_SET_SYS_OP_MODE_REQ 0x09
#define DEVMGMT_MSG_SET_SYS_OP_MODE_RSP 0x0a
#define DEVMGMT_MSG_GET_SYS_OP_MODE_REQ 0x0b
#define DEVMGMT_MSG_GET_SYS_OP_MODE_RSP 0x0c
#define DEVMGMT_MSG_SET_SYS_DATE_TIME_REQ 0x0d
#define DEVMGMT_MSG_SET_SYS_DATE_TIME_RSP 0x0e
#define DEVMGMT_MSG_GET_SYS_DATE_TIME_REQ 0x0f
#define DEVMGMT_MSG_GET_SYS_DATE_TIME_RSP 0x10
#define DEVMGMT_MSG_SET_SYS_OPTIONS_REQ 0xf7
#define DEVMGMT_MSG_SET_SYS_OPTIONS_RSP 0xf8
#define DEVMGMT_MSG_GET_SYS_OPTIONS_REQ 0xf9
#define DEVMGMT_MSG_GET_SYS_OPTIONS_RSP 0xfa

#define LIST_OF_IU891A_DEVMGMT_ERROR_CODES \
    X(0, OK, "ok") \
    X(1, ERROR, "error") \
    X(2, COMMAND_NOT_SUPPORTED, "command not supported") \
    X(3, WRONG_PARAMETER, "wrong parameter") \
    X(4, WRONG_APPLICATION, "wrong application / device mode") \
    X(5, RESERVED, "reserved") \
    X(6, BUSY, "application / device busy, try later") \
    X(7, WRONG_MSG_LENGTH, "wrong message length") \
    X(8, NVM_WRITE_ERROR, "NVM write error") \
    X(9, NVM_READ_ERROR, "NVM read error ( NVM content is invalid )") \
    X(10, COMMAND_REJECTED, "command rejected") \
    X(11, RESERVED2, "reserved2") \
    X(12, UNEXPECTED_MSG_FORMAT, "unexpected message format")

enum class ErrorCodeIU891ADevMgmt {
#define X(num,text,info) text,
LIST_OF_IU891A_DEVMGMT_ERROR_CODES
#undef X
    UNKNOWN
};

const char *toString(ErrorCodeIU891ADevMgmt ec);
ErrorCodeIU891ADevMgmt toErrorCodeIU891ADevMgmt(uchar c);

#define WMBUSGW_GET_ACTIVE_CONFIGURATION_REQ 0x01
#define WMBUSGW_GET_ACTIVE_CONFIGURATION_RSP 0x02
#define WMBUSGW_SET_ACTIVE_CONFIGURATION_REQ 0x03
#define WMBUSGW_SET_ACTIVE_CONFIGURATION_RSP 0x04
#define WMBUSGW_GET_DEFAULT_CONFIGURATION_REQ 0x05
#define WMBUSGW_GET_DEFAULT_CONFIGURATION_RSP 0x06
#define WMBUSGW_SET_DEFAULT_CONFIGURATION_REQ 0x07
#define WMBUSGW_SET_DEFAULT_CONFIGURATION_RSP 0x08
#define WMBUSGW_RESET_DEFAULT_CONFIGURATION_REQ 0x09
#define WMBUSGW_RESET_DEFAULT_CONFIGURATION_RSP 0x0a

#define WMBUSGW_CLEAR_WMBUS_DEVICE_LIST_REQ 0x11
#define WMBUSGW_CLEAR_WMBUS_DEVICE_LIST_RSP 0x12
#define WMBUSGW_APPEND_WMBUS_DEVICE_LIST_REQ 0x13
#define WMBUSGW_APPEND_WMBUS_DEVICE_LIST_RSP 0x14
#define WMBUSGW_READ_WMBUS_DEVICE_LIST_REQ 0x15
#define WMBUSGW_READ_WMBUS_DEVICE_LIST_RSP 0x16
#define WMBUSGW_SAVE_WMBUS_DEVICE_LIST_REQ 0x17
#define WMBUSGW_SAVE_WMBUS_DEVICE_LIST_RSP 0x18
#define WMBUSGW_LOAD_WMBUS_DEVICE_LIST_REQ 0x19
#define WMBUSGW_LOAD_WMBUS_DEVICE_LIST_RSP 0x1a

#define WMBUSGW_RX_MESSAGE_IND 0x20

#define WMBUSGW_ENABLE_DISABLE_SCAN_MODE_REQ 0x21
#define WMBUSGW_ENABLE_DISABLE_SCAN_MODE_RSP 0x22

#define WMBUSGW_SCAN_MODE_PACKET_IND 0x24

// Only iM881-XL and iM891A-XL
#define WMBUSGW_SEND_MESSAGE_REQ 0x31
#define WMBUSGW_SEND_MESSAGE_RSP 0x32

#define WMBUSGW_MESSAGE_PACKET_TRANSMITTED_IND 0x34

// Only iM881-XL and iM891A-XL
#define WMBUSGW_ENCRYPT_SEND_MESSAGE_REQ 0x35
#define WMBUSGW_ENCRYPT_SEND_MESSAGE_RSP 0x36

#define WMBUSGW_ENCRYPTED_MESSAGE_PACKET_TRANSMITTED_IND 0x38

// OnlyiU891A-XL
#define WMBUSGW_SEND_PACKET_REQ 0x39
#define WMBUSGW_SEND_PACKET_RSP 0x3A

// Only iU891A-XL
#define WMBUSGW_ENCRYPT_SEND_PACKET_REQ 0x3b
#define WMBUSGW_ENCRYPT_SEND_PACKET_RSP 0x3c

#define WMBUSGW_GET_APPLICATION_STATUS_REQ 0x41
#define WMBUSGW_GET_APPLICATION_STATUS_RSP 0x42

#define WMBUSGW_RESET_APPLICATION_STATUS_REQ 0x43
#define WMBUSGW_RESET_APPLICATION_STATUS_RSP 0x44

// Only iM881A-XL, iM891A-XL
#define WMBUSGW_GET_RADIO_CONTROL_CONFIG_REQ 0x51
#define WMBUSGW_GET_RADIO_CONTROL_CONFIG_RSP 0x52
#define WMBUSGW_SET_RADIO_CONTROL_CONFIG_REQ 0x53
#define WMBUSGW_SET_RADIO_CONTROL_CONFIG_RSP 0x54

// Only iU891A-XL
#define WMBUSGW_GET_WMBUS_ADDRESS_REQ 0x81
#define WMBUSGW_GET_WMBUS_ADDRESS_RSP 0x82

#define LIST_OF_IU891A_WMBUSGW_ERROR_CODES \
    X(0, OK, "ok") \
    X(1, ERROR, "error") \
    X(2, COMMAND_NOT_SUPPORTED, "command not supported") \
    X(3, WRONG_PARAMETER, "wrong parameter") \
    X(4, WRONG_APPLICATION_MODE, "wrong application mode") \
    X(5, NO_MORE_DATA, "no more data") \
    X(6, APPLICATION_BUSY, "application busy, try later") \
    X(7, WRONG_MSG_LENGTH, "wrong message length") \
    X(8, NVM_WRITE_ERROR, "NVM write error") \
    X(9, NVM_READ_ERROR, "NVM read error ( NVM content is invalid )") \
    X(10, COMMAND_REJECTED, "command rejected, execution not possible in current application state") \
    X(11, ACCESS_DENIED, "access denied, operation may need another system operation mode") \
    X(12, DATA_TRUNCATED, "data truncated") \
    X(13, UNSUPPORTED_ENCRYPTION_MODE, "unsupported encryption mode") \
    X(14, NO_ENCRYPTION_KEY_FOUND, "no encryption key found for given meter address") \
    X(15, ENCRYPTION_PARAMETER_MISSING, "encryption info / parameter missing") \
    X(16, ENCRYPTION_ERROR, "encryption error")

enum class ErrorCodeIU891AWMBUSGW {
#define X(num,text,info) text,
LIST_OF_IU891A_WMBUSGW_ERROR_CODES
#undef X
    UNKNOWN
};

const char *toString(ErrorCodeIU891AWMBUSGW ec);
ErrorCodeIU891AWMBUSGW toErrorCodeIU891AWMBUSGW(uchar c);
