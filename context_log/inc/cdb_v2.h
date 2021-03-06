// Copyright (c) 2007-2009 Google Inc.
// Copyright (c) 2006-2007 Jaiku Ltd.
// Copyright (c) 2002-2006 Mika Raento and Renaud Petit
//
// This software is licensed at your choice under either 1 or 2 below.
//
// 1. MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// 2. Gnu General Public license 2.0
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//
//
// This file is part of the JaikuEngine mobile client.

const CCommDbDump::TDbItem CCommDbDump::DEFAULT_FIELDS[] = {
	//{ BOOL,		COMMDB_HIDDEN },
	{ UINT,		COMMDB_ID },
	{ DES,		COMMDB_NAME },
	//{ BOOL,		COMMDB_READ_ONLY },
	{ END,		0 },
};

const CCommDbDump::TDbItem CCommDbDump::IAP_DB[] = {
	{ TABLE,	AGENT_LOOKUP },
	{ DES,		AGENT_FRIENDLY_NAME },
	{ DES,		AGENT_FILENAME },
	
	{ TABLE,	BT_DEFAULT_TABLE },
	{ DES,		BT_DFLT_SER_NAME },
	//{ UINT,		BT_DFLT_SER_UUID },
	{ DES8,		BT_DFLT_DEV_ADD },
	{ UINT,		BT_DFLT_VIRTUAL_PORT },
	{ UINT,		BT_DFLT_SECURITY_LEVEL },

	{ TABLE,	BT_PERSIST_TABLE },
	{ UINT,		BT_PERSIST_COD },
	{ UINT,		BT_PERSIST_PAGE_TIMEOUT },

	{ TABLE,	BT_SECURITY_TABLE },
	{ DES8,		BT_DEV_ADD },
	{ UINT,		BT_SEC_UID },
	{ UINT,		BT_SEC_DEVICE_SECURITY },

	{ TABLE,	NETWORK },

	{ TABLE,	CDMA2000_PACKET_SERVICE_TABLE },
	{ DES,		CDMA_IWF_NAME },
	{ UINT,		CDMA_SERVICE_OPTION },
	{ UINT,		CDMA_PDP_TYPE },
	{ DES,		CDMA_PDP_ADDRESS },
	{ UINT,		CDMA_REQ_FWD_PRIORITY },
	{ UINT,		CDMA_REQ_REV_PRIORITY },
	{ UINT,		CDMA_REQ_FWD_BITRATE },
	{ UINT,		CDMA_REQ_REV_BITRATE },
	{ UINT,		CDMA_REQ_FWD_LOSS },
	{ UINT,		CDMA_REQ_REV_LOSS },
	{ UINT,		CDMA_REQ_FWD_MAXDELAY },
	{ UINT,		CDMA_REQ_REV_MAXDELAY },
	{ UINT,		CDMA_MIN_FWD_BITRATE },
	{ UINT,		CDMA_MIN_REV_BITRATE },
	{ UINT,		CDMA_ACCPT_FWD_LOSS },
	{ UINT,		CDMA_ACCPT_REV_LOSS },
	{ UINT,		CDMA_ACCPT_FWD_MAXDELAY },
	{ UINT,		CDMA_ACCPT_REV_MAXDELAY },
	{ BOOL,		CDMA_DATA_COMPRESSION },
#ifndef __S60V2FP3__
	{ BOOL,		CDMA_HEADER_COMPRESSION },
#endif
	{ BOOL,		CDMA_ANONYMOUS_ACCESS },
	//{ DES,		CDMA_IF_NAME },
	{ DES,		CDMA_IF_PARAMS },
	{ DES,		CDMA_IF_NETWORKS },
	{ DES,		CDMA_IF_PROMPT_FOR_AUTH },
	{ DES,		CDMA_IF_AUTH_NAME },
	{ DES,		CDMA_IF_AUTH_PASS },
	{ UINT,		CDMA_IF_AUTH_RETRIES },
	{ DES,		CDMA_IP_NETMASK },
	{ DES,		CDMA_IP_GATEWAY },
	{ BOOL,		CDMA_IP_ADDR_FROM_SERVER },
	{ DES,		CDMA_IP_ADDR },
	{ BOOL,		CDMA_IP_DNS_ADDR_FROM_SERVER },
	{ DES,		CDMA_IP_NAME_SERVER2 },
	{ DES,		CDMA_IP_NAME_SERVER1 },
	{ BOOL,		CDMA_ENABLE_LCP_EXTENSIONS },
	{ BOOL,		CDMA_DISABLE_PLAIN_TEXT_AUTH },
	{ UINT,		CDMA_AP_TYPE },
	{ UINT,		CDMA_QOS_WARNING_TIMEOUT },
	{ UINT,		CDMA_RLP_MODE },
	{ BOOL,		CDMA_MIP },
	{ DES,		CDMA_MIP_HA_ADDRESS },
	{ UINT,		CDMA_MIP_TIMEOUT },

	{ TABLE_SAME_AS_PREV, DEFAULT_CDMA2000_SETTINGS_TABLE },

	{ TABLE,	CHARGECARD },
	{ DES,		CHARGECARD_ACCOUNT_NUMBER },
	{ DES,		CHARGECARD_PIN },
	{ DES,		CHARGECARD_LOCAL_RULE },
	{ DES,		CHARGECARD_NAT_RULE },
	{ DES,		CHARGECARD_INTL_RULE },

	{ TABLE,	DEFAULT_GPRS },
	{ UINT,		DEFAULT_GPRS_USAGE },
	{ DES,		DEFAULT_GPRS_APN },
	{ UINT,		DEFAULT_GPRS_PDP_TYPE },
	{ DES,		DEFAULT_GPRS_PDP_ADDRESS },
	{ UINT,		DEFAULT_GPRS_PRECEDENCE },
	{ UINT,		DEFAULT_GPRS_DELAY },
	{ UINT,		DEFAULT_GPRS_RELIABILITY },
	{ UINT,		DEFAULT_GPRS_PEAK_THROUGHPUT },
	{ UINT,		DEFAULT_GPRS_MEAN_THROUGHPUT },
	{ UINT,		DEFAULT_GPRS_MIN_PRECEDENCE },
	{ UINT,		DEFAULT_GPRS_MIN_DELAY },
	{ UINT,		DEFAULT_GPRS_MIN_RELIABILITY },
	{ UINT,		DEFAULT_GPRS_MIN_PEAK_THROUGHPUT },
	{ UINT,		DEFAULT_GPRS_MIN_MEAN_THROUGHPUT },
	{ BOOL,		DEFAULT_GPRS_DATA_COMPRESSION },
	{ BOOL,		DEFAULT_GPRS_HEADER_COMPRESSION },
	{ BOOL,		DEFAULT_GPRS_ANONYMOUS_ACCESS },
	{ BOOL,		DEFAULT_GPRS_USE_EDGE },

	{ TABLE,	DIAL_OUT_ISP },
	{ DES,		ISP_DESCRIPTION },
	{ UINT,		ISP_TYPE },
	{ DES,		ISP_DEFAULT_TEL_NUM },
	{ BOOL,		ISP_DIAL_RESOLUTION },
	{ BOOL,		ISP_USE_LOGIN_SCRIPT },
	{ LONGDES,	ISP_LOGIN_SCRIPT },
	{ BOOL,		ISP_PROMPT_FOR_LOGIN },
	{ DES,		ISP_LOGIN_NAME },
	{ DES,		ISP_LOGIN_PASS },
	{ BOOL,		ISP_DISPLAY_PCT },
	//{ DES,		ISP_IF_NAME },
	{ DES,		ISP_IF_PARAMS },
	{ DES,		ISP_IF_NETWORKS },
	{ BOOL,		ISP_IF_PROMPT_FOR_AUTH },
	{ DES,		ISP_IF_AUTH_NAME },
	{ DES,		ISP_IF_AUTH_PASS },
	{ UINT,		ISP_IF_AUTH_RETRIES },
	{ BOOL,		ISP_IF_CALLBACK_ENABLED },
	{ DES8,		ISP_IF_CALLBACK_INFO },
	{ UINT,		ISP_IF_CALLBACK_TYPE },
	{ UINT,		ISP_CALLBACK_TIMEOUT },
	{ BOOL,		ISP_IP_ADDR_FROM_SERVER },
	{ DES,		ISP_IP_ADDR },
	{ DES,		ISP_IP_NETMASK },
	{ DES,		ISP_IP_GATEWAY },
	{ BOOL,		ISP_IP_DNS_ADDR_FROM_SERVER },
	{ DES,		ISP_IP_NAME_SERVER1 },
	{ DES,		ISP_IP_NAME_SERVER2 },
	{ BOOL,		ISP_ENABLE_IP_HEADER_COMP },
	{ BOOL,		ISP_ENABLE_LCP_EXTENSIONS },
	{ BOOL,		ISP_DISABLE_PLAIN_TEXT_AUTH },
	{ BOOL,		ISP_ENABLE_SW_COMP },
	{ UINT,		ISP_BEARER_CE },
	{ UINT,		ISP_BEARER_NAME },
	{ UINT,		ISP_BEARER_SPEED },
	{ DES,		ISP_INIT_STRING },
	{ UINT,		ISP_BEARER_TYPE },
	{ UINT,		ISP_CHANNEL_CODING },
	{ UINT,		ISP_AIUR },
	{ UINT,		ISP_REQUESTED_TIME_SLOTS },
	{ UINT,		ISP_MAXIMUM_TIME_SLOTS },
	//{ UINT,		ISP_CDMA_SERVICE_OPTIONS },
	{ UINT,		ISP_BEARER_SERVICE },
	{ UINT,		ISP_BEARER_PROTOCOL },
	{ UINT,		ISP_RLP_VERSION },
	{ UINT,		ISP_IWF_TO_MS },
	{ UINT,		ISP_MS_TO_IWF },
	{ UINT,		ISP_ACK_TIMER },
	{ UINT,		ISP_RETRANSMISSION_ATTEMPTS },
	{ UINT,		ISP_RESEQUENCE_PERIOD },
	{ UINT,		ISP_V42_COMPRESSION },
	{ UINT,		ISP_V42_CODEWORDS },
	{ UINT,		ISP_V42_MAX_LENGTH },
	{ UINT,		ISP_ASYMMETRY },
	{ BOOL,		ISP_USER_INIT_UPGRADE },

	{ TABLE,	IAP },
	{ UINT,		IAP_SERVICE },
	{ DES,		IAP_SERVICE_TYPE },
	//{ UINT,		IAP_CHARGECARD },
	{ UINT,		IAP_DIALOG_PREF },
	{ UINT,		IAP_BEARER },
	{ DES,		IAP_BEARER_TYPE },
	{ UINT,		IAP_NETWORK },
	{ UINT,		IAP_NETWORK_WEIGHTING },
	{ UINT,		IAP_LOCATION },

	{ TABLE,	INCOMING_GPRS },
	{ DES,		GPRS_APN },
	{ UINT,		GPRS_PDP_TYPE },
	{ DES,		GPRS_PDP_ADDRESS },
	{ UINT,		GPRS_REQ_PRECEDENCE },
	{ UINT,		GPRS_REQ_DELAY },
	{ UINT,		GPRS_REQ_RELIABILITY },
	{ UINT,		GPRS_REQ_PEAK_THROUGHPUT },
	{ UINT,		GPRS_REQ_MEAN_THROUGHPUT },
	{ UINT,		GPRS_MIN_PRECEDENCE },
	{ UINT,		GPRS_MIN_DELAY },
	{ UINT,		GPRS_MIN_RELIABILITY },
	{ UINT,		GPRS_MIN_PEAK_THROUGHPUT },
	{ UINT,		GPRS_MIN_MEAN_THROUGHPUT },
	{ BOOL,		GPRS_DATA_COMPRESSION },
	{ BOOL,		GPRS_HEADER_COMPRESSION },
	{ BOOL,		GPRS_ANONYMOUS_ACCESS },
	//{ DES,		GPRS_IF_NAME },
	{ DES,		GPRS_IF_PARAMS },
	{ DES,		GPRS_IF_NETWORKS },
	{ BOOL,		GPRS_IF_PROMPT_FOR_AUTH },
	{ DES,		GPRS_IF_AUTH_NAME },
	{ DES,		GPRS_IF_AUTH_PASS },
	{ UINT,		GPRS_IF_AUTH_RETRIES },
	{ DES,		GPRS_IP_NETMASK },
	{ DES,		GPRS_IP_GATEWAY },
	{ BOOL,		GPRS_IP_ADDR_FROM_SERVER },
	{ DES,		GPRS_IP_ADDR },
	{ BOOL,		GPRS_IP_DNS_ADDR_FROM_SERVER },
	{ DES,		GPRS_IP_NAME_SERVER1 },
	{ DES,		GPRS_IP_NAME_SERVER2 },
	{ BOOL,		GPRS_ENABLE_LCP_EXTENSIONS },
	{ BOOL,		GPRS_DISABLE_PLAIN_TEXT_AUTH },

	{ TABLE_SAME_AS_PREV, OUTGOING_GPRS },

	{ TABLE,	LOCATION },
	{ DES,		LOCATION_INTL_PREFIX_CODE },
	{ DES,		LOCATION_NAT_PREFIX_CODE },
	{ DES,		LOCATION_NAT_CODE },
	{ DES,		LOCATION_AREA_CODE },
	{ DES,		LOCATION_DIAL_OUT_CODE },
	{ DES,		LOCATION_DISABLE_CALL_WAITING_CODE },
	{ BOOL,		LOCATION_MOBILE },
	{ BOOL,		LOCATION_USE_PULSE_DIAL },
	{ BOOL,		LOCATION_WAIT_FOR_DIAL_TONE },
	{ UINT,		LOCATION_PAUSE_AFTER_DIAL_OUT },

	{ TABLE,	MODEM_BEARER },
	{ DES,		MODEM_AGENT },
	{ DES,		MODEM_PORT_NAME },
	{ DES,		MODEM_TSY_NAME },
	{ DES,		MODEM_NIF_NAME },
	{ DES,		MODEM_CSY_NAME },
	{ UINT,		MODEM_DATA_BITS },
	{ UINT,		MODEM_STOP_BITS },
	{ UINT,		MODEM_PARITY },
	{ UINT,		MODEM_RATE },
	{ UINT,		MODEM_HANDSHAKING },
	{ UINT,		MODEM_SPECIAL_RATE },
	{ UINT,		MODEM_XOFF_CHAR },
	{ UINT,		MODEM_XON_CHAR },
	{ UINT,		MODEM_FAX_CLASS_PREF },
	{ UINT,		MODEM_SPEAKER_PREF },
	{ UINT,		MODEM_SPEAKER_VOL_PREF },
	{ DES8,		MODEM_MODEM_INIT_STRING },
	{ DES8,		MODEM_DATA_INIT_STRING },
	{ DES8,		MODEM_FAX_INIT_STRING },
	{ DES8,		MODEM_ISP_INIT_STRING },
	{ DES8,		MODEM_DIAL_PAUSE_LENGTH },
	{ DES8,		MODEM_CARRIER_TIMEOUT },
	{ DES8,		MODEM_AUTO_ANSWER_RING_COUNT },
	{ DES8,		MODEM_SPEAKER_ALWAYS_OFF },
	{ DES8,		MODEM_SPEAKER_ALWAYS_ON },
	{ DES8,		MODEM_SPEAKER_ON_AFTER_DIAL_UNTIL_CARRIER },
	{ DES8,		MODEM_SPEAKER_ON_UNTIL_CARRIER },
	{ DES8,		MODEM_SPEAKER_VOL_CONTROL_HIGH },
	{ DES8,		MODEM_SPEAKER_VOL_CONTROL_LOW },
	{ DES8,		MODEM_SPEAKER_VOL_CONTROL_MEDIUM },
	{ DES8,		MODEM_DIAL_TONE_WAIT_MODIFIER },
	{ DES8,		MODEM_CALL_PROGRESS_1 },
	{ DES8,		MODEM_CALL_PROGRESS_2 },
	{ DES8,		MODEM_CALL_PROGRESS_3 },
	{ DES8,		MODEM_CALL_PROGRESS_4 },
	{ DES8,		MODEM_ECHO_OFF },
	{ DES8,		MODEM_VERBOSE_TEXT },
	{ DES8,		MODEM_QUIET_OFF },
	{ DES8,		MODEM_QUIET_ON },
	{ DES8,		MODEM_DIAL_COMMAND_STATE_MODIFIER },
	{ DES8,		MODEM_ON_LINE },
	{ DES8,		MODEM_RESET_CONFIGURATION }, 
	{ DES8,		MODEM_RETURN_TO_FACTORY_DEFS },
	{ DES8,		MODEM_DCD_ON_DURING_LINK },
	{ DES8,		MODEM_DTR_HANG_UP },
	{ DES8,		MODEM_DSR_ALWAYS_ON },
	{ DES8,		MODEM_RTS_CTS_HANDSHAKE },
	{ DES8,		MODEM_XON_XOFF_HANDSHAKE },
	{ DES8,		MODEM_ESCAPE_CHARACTER },
	{ DES8,		MODEM_ESCAPE_GUARD_PERIOD },
	{ DES8,		MODEM_FAX_CLASS_INTERROGATE },
	{ DES8,		MODEM_FAX_CLASS },
	{ DES8,		MODEM_NO_ANSWER },
	{ DES8,		MODEM_NO_DIAL_TONE },
	{ DES8,		MODEM_BUSY },
	{ DES8,		MODEM_CARRIER },
	{ DES8,		MODEM_CONNECT },
	{ DES8,		MODEM_COMPRESSION_CLASS_5 },
	{ DES8,		MODEM_COMPRESSION_NONE },
	{ DES8,		MODEM_COMPRESSION_V42BIS },
	{ DES8,		MODEM_PROTOCOL_ALT },
	{ DES8,		MODEM_PROTOCOL_ALTCELLULAR },
	{ DES8,		MODEM_PROTOCOL_LAPD },
	{ DES8,		MODEM_PROTOCOL_NONE },
	{ DES8,		MODEM_MESSAGE_CENTRE_NUMBER },
	{ BOOL,		MODEM_MESSAGE_DELIVERY_REPORT },
	{ UINT,		MODEM_MESSAGE_VALIDITY_PERIOD },
	{ DES,		MODEM_CONTROL_CHANNEL_PORT_NAME },
	{ UINT,		MODEM_MIN_SIGNAL_LEVEL },

	//{ TABLE_SAME_AS_PREV, _S("ConnectedModem") },
	
	{ TABLE,	PROXIES },
	{ UINT,		PROXY_ISP },
	{ DES,		PROXY_SERVICE_TYPE },
	{ BOOL,		PROXY_USE_PROXY_SERVER },
	{ LONGDES,	PROXY_SERVER_NAME },
	{ DES,		PROXY_PROTOCOL_NAME },
	{ UINT,		PROXY_PORT_NUMBER },
	{ LONGDES,	PROXY_EXCEPTIONS },

	{ TABLE,	SS_PROTO_TABLE },
	{ DES,		SS_PROTO_NAME },
	{ DES,		SS_PROTO_LIBRARY },

	{ TABLE,	WAP_ACCESS_POINT },
	{ DES,		WAP_CURRENT_BEARER },
	{ DES,		WAP_START_PAGE },

	{ TABLE,	WAP_IP_BEARER },
	{ UINT,		WAP_ACCESS_POINT_ID },
	//{ UINT,		WAP_CHARGECARD },
	{ DES,		WAP_GATEWAY_ADDRESS },
	{ UINT,		WAP_IAP },
	//{ UINT,		WAP_ISP },
	//{ UINT,		WAP_ISP_TYPE },
	//{ UINT,		WAP_LOCATION },
	{ BOOL,		WAP_SECURITY },
	{ UINT,		WAP_WSP_OPTION },
	{ UINT,		WAP_PROXY_PORT },
	{ DES,		WAP_PROXY_LOGIN_NAME },
	{ DES,		WAP_PROXY_LOGIN_PASS },

	{ TABLE,	WAP_SMS_BEARER },
	{ UINT,		WAP_ACCESS_POINT_ID },
	{ DES,		WAP_GATEWAY_ADDRESS },
	{ DES,		WAP_SERVICE_CENTRE_ADDRESS },
	{ BOOL,		WAP_SECURITY },
	{ UINT,		WAP_WSP_OPTION },

	{ END,		0 },
};
