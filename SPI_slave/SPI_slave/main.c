/*
 * SPI_slave.c
 *
 * Created: 9/24/2021 3:34:16 AM
 * Author : Karim Essam
 */ 

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/USART/USART_interface.h"
#include "HAL/LCD/LCD_interface.h"

int main(void)
{
    /* Replace with your application code */
	USART_voidInit(TRANSMIT_RECIEVE , ASYNCRONOUS , EIGHT_BITS , DISAPLED , ONE_STOP_BIT , 2400);
	SPI_voidInit(SLAVE_MODE , MSB , LEADING_IS_RISING , LEADING_IS_SAMPLE , SPI_PRESCALAR_16);
	LCD_voidInit();
	
	u8 string[20];
	u8 index = 0;
    while (1) 
    {
		u8 data = SPI_u8SlaveRecieve();
		string[index++] = data;
		if (data == NULL)
		{
			USART_voidTransmitString(string);
			LCD_voidSendString(string);
			memset(string, NULL, sizeof(string));
			index = 0;
		}
    }
}

