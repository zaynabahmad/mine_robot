/*
 * USART_Program.c
 *
 *  Created on: Dec 11, 2023
 *      Author: zaynab
 */

#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"
#include "../../Services/STD_LIB.h"
#include "../../Services/Bit_Math.h"


void USART_voidInit(void)
{

// baud rate
u16 baud_rate = 51;

UBRRH_REG = (u8) baud_rate>>8;
UBRRL_REG = (u8) baud_rate ;


// configration of parity bit
#if parity_mode==Disabled
	Clr_Bit(UCSRC_REG,UCSRC_UPM0);
	Clr_Bit(UCSRC_REG,UCSRC_UPM1);
#elif parity_mode==Reserved
	Set_Bit(UCSRC_REG,UCSRC_UPM0);
	Clr_Bit(UCSRC_REG,UCSRC_UPM1);
#elif parity_mode==Even_parity
	Clr_Bit(UCSRC_REG,UCSRC_UPM0);
	Set_Bit(UCSRC_REG,UCSRC_UPM1);
#elif parity_mode==Odd_parity
	Set_Bit(UCSRC_REG,UCSRC_UPM0);
	Set_Bit(UCSRC_REG,UCSRC_UPM1);
#endif

// configration of Data 5,6,7,8 and 9
#if char_size==_5bit
	Clr_Bit(UCSRC_REG,UCSRC_UCSZ0);
	Clr_Bit(UCSRC_REG,UCSRC_UCSZ1);
	Clr_Bit(UCSRB_REG,UCSRB_UCSZ2);
#elif char_size==_6bit
	Set_Bit(UCSRC_REG,UCSRC_UCSZ0);
	Clr_Bit(UCSRC_REG,UCSRC_UCSZ1);
	Clr_Bit(UCSRB_REG,UCSRB_UCSZ2);
#elif char_size==_7bit
	Clr_Bit(UCSRC_REG,UCSRC_UCSZ0);
	Set_Bit(UCSRC_REG,UCSRC_UCSZ1);
	Clr_Bit(UCSRB_REG,UCSRB_UCSZ2);
#elif char_size==_8bit
	Set_Bit(UCSRC_REG,UCSRC_UCSZ0);
	Set_Bit(UCSRC_REG,UCSRC_UCSZ1);
	Clr_Bit(UCSRB_REG,UCSRB_UCSZ2);
#elif char_size==_9bit
	Set_Bit(UCSRC_REG,UCSRC_UCSZ0);
	Set_Bit(UCSRC_REG,UCSRC_UCSZ1);
	Set_Bit(UCSRB_REG,UCSRB_UCSZ2);

#endif
//configration of synchrnazation
#if syncrnous_mode==asyncronous_mode
	Clr_Bit(UCSRC_REG,UCSRC_UMSEL);
#elif syncrnous_mode==syncrnous_mode
	Set_Bit(UCSRC_REG,UCSRC_UMSEL);
#endif
// configration transmitter enable or disable

    // Enable transmitter and receiver
	Set_Bit(UCSRB_REG, UCSRB_TXEN);
	Set_Bit(UCSRB_REG, UCSRB_RXEN);

// configraiton for stop bit
#if Stop_bit==_1bit
	Clr_Bit(UCSRC_REG,UCSRC_USBS);
#elif Stop_bit==_2bit
	Set_Bit(UCSRC_REG,UCSRC_USBS);
#endif
}
void USART_voidSendData(u8 Copy_Data)
{
// polling the bit 5
	while (Get_Bit(UCSRA_REG,UCSRA_UDRE)==0);
	UDR_REG=Copy_Data;

}

u8 USART_u8RreceiveData(void)
{
	while (Get_Bit(UCSRA_REG,UCSRA_RXC)==0);
	return UDR_REG;

}

// Function to disable the transmitter
void USART_voidDisableTransmitter(void)
{
    // Clear the transmitter enable bit (TXEN)
    Clr_Bit(UCSRB_REG, UCSRB_TXEN);
}

// Function to enable the transmitter
void USART_voidEnableTransmitter(void)
{
    // Set the transmitter enable bit (TXEN)
    Set_Bit(UCSRB_REG, UCSRB_TXEN);
}

