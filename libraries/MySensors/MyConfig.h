/*
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */

/**
 * @file MyConfig.h
 *
 * MySensors specific configurations
 */
#ifndef MyConfig_h
#define MyConfig_h
#include <stdint.h>


/**********************************
*  Serial and debug options
***********************************/

// Enables this in sketch to show debug prints. This option will add a lot to the size of the
// final sketch but is helpful to see what is actually is happening during development
//#define MY_DEBUG

// Enable MY_DEBUG_VERBOSE flag for verbose debug prints. Requires DEBUG to be enabled.
// This will add even more to the size of the final sketch!
//#define MY_DEBUG_VERBOSE

// Enable this in sketch if you want to use TX(1), RX(0) as normal I/O pin
//#define MY_DISABLED_SERIAL

// Turn off debug if serial pins is used for other stuff
#ifdef MY_DISABLED_SERIAL
#undef MY_DEBUG
#endif

// Serial output baud rate (debug prints and serial gateway speed)
#ifndef MY_BAUD_RATE
#define MY_BAUD_RATE 115200
#endif

// Disables over-the-air reset of node
//#define MY_DISABLE_REMOTE_RESET

/**********************************
*  Radio selection and node config
***********************************/

// Selecting uplink transport layer is optional (for a gateway node).

//#define MY_RADIO_NRF24
//#define MY_RADIO_RFM69
//#define MY_RS485

// Node id defaults to AUTO (tries to fetch id from controller)
#ifndef MY_NODE_ID
#define MY_NODE_ID AUTO
#endif

// Node parent defaults to AUTO (tries to find a parent automatically)
#ifndef MY_PARENT_NODE_ID
#define MY_PARENT_NODE_ID AUTO
#endif

// Enables repeater functionality (relays messages from other nodes)
// #define MY_REPEATER_FEATURE

// The wait period before going to sleep when using smartSleep-functions
// This period has to be long enough for controller to be able to send out
// potential buffered messages.
#ifndef MY_SMART_SLEEP_WAIT_DURATION
#define MY_SMART_SLEEP_WAIT_DURATION 500
#endif

/**********************************
*  Over the air firmware updates
***********************************/

// Enable MY_OTA_FIRMWARE_FEATURE in sketch to allow safe over-the-air firmware updates.
// This feature requires external flash and the DualOptiBoot boot-loader.
// Note: You can still have OTA FW updates without external flash but it
// requires the MYSBootloader and disabled MY_OTA_FIRMWARE_FEATURE
//#define MY_OTA_FIRMWARE_FEATURE

// Slave select pin for external flash
#ifndef MY_OTA_FLASH_SS
#define MY_OTA_FLASH_SS 8
#endif

// Flash jdecid
#ifndef MY_OTA_FLASH_JDECID
#define MY_OTA_FLASH_JDECID 0x1F65
#endif


/**********************************
*  Gateway config
***********************************/

// Max buffersize needed for messages coming from controller
#ifndef MY_GATEWAY_MAX_RECEIVE_LENGTH
#define MY_GATEWAY_MAX_RECEIVE_LENGTH 100
#endif

// Max buffer size when sending messages
#ifndef MY_GATEWAY_MAX_SEND_LENGTH
#define MY_GATEWAY_MAX_SEND_LENGTH 120
#endif

// Max number of parallel clients (sever mode)
#ifndef MY_GATEWAY_MAX_CLIENTS
#define MY_GATEWAY_MAX_CLIENTS 1
#endif



/**********************************
*  Information LEDs blinking
***********************************/
// This feature enables LEDs blinking on message receive, transmit
// or if some error occurred. This was commonly used only in gateways,
// but now can be used in any sensor node. Also the LEDs can now be
// disabled in the gateway.

//#define MY_LEDS_BLINKING_FEATURE

// The following setting allows you to inverse the blinking feature MY_LEDS_BLINKING_FEATURE
// When MY_WITH_LEDS_BLINKING_INVERSE is enabled LEDSs are normally turned on and switches
// off when blinking

//#define MY_WITH_LEDS_BLINKING_INVERSE


// default LEDs blinking period in milliseconds
#ifndef MY_DEFAULT_LED_BLINK_PERIOD
#define MY_DEFAULT_LED_BLINK_PERIOD 300
#endif
// The RX LED default pin
#ifndef MY_DEFAULT_RX_LED_PIN
	#if defined(ARDUINO_ARCH_ESP8266)
		#define MY_DEFAULT_RX_LED_PIN 8
	#else
		#define MY_DEFAULT_RX_LED_PIN 6
	#endif
#endif
// The TX LED default pin
#ifndef MY_DEFAULT_TX_LED_PIN
	#if defined(ARDUINO_ARCH_ESP8266)
		#define MY_DEFAULT_TX_LED_PIN 9
	#else
		#define MY_DEFAULT_TX_LED_PIN 5
	#endif
#endif
// The Error LED default pin
#ifndef MY_DEFAULT_ERR_LED_PIN
	#if defined(ARDUINO_ARCH_ESP8266)
		#define MY_DEFAULT_ERR_LED_PIN 7
	#else
		#define MY_DEFAULT_ERR_LED_PIN 4
	#endif
#endif

/**********************************************
*  Gateway inclusion button/mode configuration
**********************************************/
// Enabled inclusion mode feature
//#define MY_INCLUSION_MODE_FEATURE

// Enables inclusion-mode button feature on the gateway device
//#define MY_INCLUSION_BUTTON_FEATURE

// Disable inclusion mode button if inclusion mode feature is not enabled
#ifndef MY_INCLUSION_MODE_FEATURE
#undef MY_INCLUSION_BUTTON_FEATURE
#endif

// The default input pin used for the inclusion mode button
#ifndef MY_INCLUSION_MODE_BUTTON_PIN
	#if defined(ARDUINO_ARCH_ESP8266)
		#define MY_INCLUSION_MODE_BUTTON_PIN 5
	#else
		#define MY_INCLUSION_MODE_BUTTON_PIN 3
	#endif
#endif
// Number of seconds (default one minute) inclusion mode should be enabled
#ifndef MY_INCLUSION_MODE_DURATION
#define MY_INCLUSION_MODE_DURATION 60
#endif

#if defined(MY_INCLUSION_BUTTON_EXTERNAL_PULLUP)
#define MY_INCLUSION_BUTTON_PRESSED HIGH
#else
#define MY_INCLUSION_BUTTON_PRESSED LOW
#endif

/**********************************
*  Message Signing Settings
***********************************/
/**
 * @def MY_SIGNING_ATSHA204
 * @brief Enables HW backed signing functionality in library.
 *
 * For any signing related functionality to be included, this define or @ref MY_SIGNING_SOFT has to be enabled.
 */
//#define MY_SIGNING_ATSHA204

/**
 * @def MY_SIGNING_SOFT
 * @brief Enables SW backed signing functionality in library.
 *
 * For any signing related functionality to be included, this define or @ref MY_SIGNING_ATSHA204 has to be enabled.
 */
//#define MY_SIGNING_SOFT

/**
 * @def MY_SIGNING_REQUEST_SIGNATURES
 * @brief Enable this to inform gateway to sign all messages sent to this node.
 *
 * If used for a gateway, gateway will only request signatures from nodes that in turn
 * request signatures from gateway.
 */
//#define MY_SIGNING_REQUEST_SIGNATURES

/**
 * @def MY_VERIFICATION_TIMEOUT_MS
 * @brief Define a suitable timeout for a signature verification session
 *
 * Consider the turnaround from a nonce being generated to a signed message being received
 * which might vary, especially in networks with many hops. 5s ought to be enough for anyone.
 */
#ifndef MY_VERIFICATION_TIMEOUT_MS
#define MY_VERIFICATION_TIMEOUT_MS 5000
#endif

/**
 * @def MY_SIGNING_NODE_WHITELISTING
 * @brief Enable to turn on whitelisting
 *
 * When enabled, a signing node will salt the signature with it's unique signature and nodeId.<br>
 * The verifying node will look up the sender in a local table of trusted nodes and
 * do the corresponding salting in order to verify the signature.<br>
 * For this reason, if whitelisting is enabled on one of the nodes in a sign-verify pair, both
 * nodes have to implement whitelisting for this to work.<br>
 * Note that a node can still transmit a non-salted message (i.e. have whitelisting disabled)
 * to a node that has whitelisting enabled (assuming the receiver does not have a matching entry
 * for the sender in it's whitelist). The whitelist to use is defined as the value of the flag.
 */
//#define MY_SIGNING_NODE_WHITELISTING {{.nodeId = GATEWAY_ADDRESS,.serial = {0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01}}}

/**
 * @def MY_SIGNING_ATSHA204_PIN
 * @brief Atsha204 default pin setting
 *
 * Pin where ATSHA204 is attached
 */
#ifndef MY_SIGNING_ATSHA204_PIN
#define MY_SIGNING_ATSHA204_PIN 17
#endif

/**
 * @def MY_SIGNING_SOFT_RANDOMSEED_PIN
 * @brief Pin used for random generation in soft signing
 *
 * Do not connect anything to this when soft signing is enabled
 */
#ifndef MY_SIGNING_SOFT_RANDOMSEED_PIN
#define MY_SIGNING_SOFT_RANDOMSEED_PIN 7
#endif

/**
 * @def MY_SIGNING_SOFT_SERIAL
 * @brief Serial number for SW signing enabled node
 *
 * Set the soft_serial value to an arbitrary value for proper security.
 * It should be random and unique for each node.
 */
#ifndef MY_SIGNING_SOFT_SERIAL
#define MY_SIGNING_SOFT_SERIAL 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09
#endif

/**
 * @def MY_SIGNING_SOFT_HMAC_KEY
 * @brief Key to use for HMAC calculation in MySigningAtsha204Soft (32 bytes)
 */
#ifndef MY_SIGNING_SOFT_HMAC_KEY
#define MY_SIGNING_SOFT_HMAC_KEY 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
#endif

/**********************************
*  RS485 Driver Defaults
***********************************/

#ifndef MY_RS485_BAUD_RATE
#define MY_RS485_BAUD_RATE 9600
#endif

#ifndef MY_RS485_MAX_MESSAGE_LENGTH
#define MY_RS485_MAX_MESSAGE_LENGTH 40
#endif

/**********************************
*  NRF24L01 Driver Defaults
***********************************/

// Enables RF24 encryption (all nodes and gateway must have this enabled)
//#define MY_RF24_ENABLE_ENCRYPTION

// Default encryption key. Override in sketch if needed.
#ifndef MY_RF24_ENCRYPTKEY
#define MY_RF24_ENCRYPTKEY 0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x10,0x11,0x12,0x13,0x14,0x15,0x16
#endif

// Default pin settings. Override in sketch if needed.
#ifndef MY_RF24_CE_PIN
	#if defined(ARDUINO_ARCH_ESP8266)
		#define MY_RF24_CE_PIN 4
	#else
		#define MY_RF24_CE_PIN 9
	#endif
#endif

#ifndef MY_RF24_CS_PIN
	#if defined(ARDUINO_ARCH_ESP8266)
		#define MY_RF24_CS_PIN 15
	#else
		#define MY_RF24_CS_PIN 10
	#endif
#endif

#ifndef MY_RF24_PA_LEVEL
#define MY_RF24_PA_LEVEL RF24_PA_MAX
#endif
// RF channel for the sensor net, 0-127
#ifndef MY_RF24_CHANNEL
#define MY_RF24_CHANNEL	76
#endif
//RF24_250KBPS for 250kbs, RF24_1MBPS for 1Mbps, or RF24_2MBPS for 2Mbps
#ifndef MY_RF24_DATARATE
#define MY_RF24_DATARATE RF24_250KBPS
#endif
// This is also act as base value for sensor nodeId addresses. Change this (or channel) if you have more than one sensor network.
#ifndef MY_RF24_BASE_RADIO_ID
#define MY_RF24_BASE_RADIO_ID ((uint64_t)0xA8A8E1FC00LL)
#endif

// Enable SOFTSPI for NRF24L01, useful for the W5100 Ethernet module
//#define MY_SOFTSPI

#ifndef MY_SOFT_SPI_SCK_PIN
#define MY_SOFT_SPI_SCK_PIN 14
#endif
#ifndef MY_SOFT_SPI_MISO_PIN
#define MY_SOFT_SPI_MISO_PIN 16
#endif
#ifndef MY_SOFT_SPI_MOSI_PIN
#define MY_SOFT_SPI_MOSI_PIN 15
#endif

/**********************************
*  RFM69 Driver Defaults
***********************************/

// Default frequency to use. This must match the hardware version of the RFM69 radio (uncomment one):
#ifndef MY_RFM69_FREQUENCY
// #define MY_RFM69_FREQUENCY   RF69_433MHZ
#define MY_RFM69_FREQUENCY   RF69_868MHZ
//#define MY_RFM69_FREQUENCY     RF69_915MHZ
#endif

// Enable this if you're running the RFM69HW model
#ifdef MY_IS_RFM69HW
	#define MY_RFM69HW true
#else
	#define MY_RFM69HW false
#endif

// Default network id. Use the same for all nodes that will talk to each other
#ifndef MY_RFM69_NETWORKID
#define MY_RFM69_NETWORKID     100
#endif
#ifndef MY_RF69_IRQ_PIN
#define MY_RF69_IRQ_PIN RF69_IRQ_PIN
#endif
#ifndef MY_RF69_SPI_CS
#define MY_RF69_SPI_CS RF69_SPI_CS
#endif
#ifndef MY_RF69_IRQ_NUM
#define MY_RF69_IRQ_NUM RF69_IRQ_NUM
#endif

// Enable this for encryption of packets
//#define MY_RFM69_ENABLE_ENCRYPTION
#ifndef MY_RFM69_ENCRYPTKEY
#define MY_RFM69_ENCRYPTKEY    "sampleEncryptKey" //exactly the same 16 characters/bytes on all nodes!
#endif

/**************************************
* Ethernet Gateway Transport  Defaults
***************************************/

// The gateway options available
//#define MY_GATEWAY_W5100
//#define MY_GATEWAY_ENC28J60
//#define MY_GATEWAY_ESP8266

// The port to open on controller or gateway
#ifndef MY_PORT
#define MY_PORT 5003
#endif

// Static ip address of gateway (if this is disabled, DHCP will be used)
//#define MY_IP_ADDRESS 192,168,178,66

// Enables UDP mode for Ethernet gateway (W5100)
//#define MY_USE_UDP

// DHCP, default renewal setting
#ifndef MY_IP_RENEWAL_INTERVAL
#define MY_IP_RENEWAL_INTERVAL 60000
#endif

#ifndef MY_MAC_ADDRESS
#define MY_MAC_ADDRESS 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
#endif

// Controller ip-address, if this is defined, gateway will act as a client trying to contact controller on MY_PORT.
// If MY_CONTROLLER_IP_ADDRESS is left un-defined, gateway acts as server allowing incoming connections.
//#define MY_CONTROLLER_IP_ADDRESS 192, 168, 178, 254

#endif
// Doxygen specific constructs, not included when built normally
// This is used to enable disabled macros/definitions to be included in the documentation as well.
#if DOXYGEN
#define MY_SIGNING_ATSHA204
#define MY_SIGNING_SOFT
#define MY_SIGNING_NODE_WHITELISTING {{.nodeId = GATEWAY_ADDRESS,.serial = {0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01}}}
#endif
