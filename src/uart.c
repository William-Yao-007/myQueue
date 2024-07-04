#include "queue.h"
#include "uart.h"


//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
QUEUE_T uart0_queue;
UART_DATA_T uart0_data;

//=============================================================================
//=============================================================================
void init_uart0(void)
{
    //
    uart0_data.uart_queue = &uart0_queue;
    init_queue(uart0_data.uart_queue);
}

//=============================================================================
// push data into queue buffer
//=============================================================================
char uart_push_byte(UART_DATA_T *uart_data, char byte_value)
{
    return(enqueue(uart_data->uart_queue, byte_value));
}

//=============================================================================
// push data into queue buffer
//=============================================================================
short uart_push_data(UART_DATA_T *uart_data, char *byte_array, unsigned short byte_length)
{
    short i = 0;

    for(i = 0; i < byte_length; i++) {
        if(enqueue(uart_data->uart_queue, byte_array[i]) < 0) return -1;       // buffer is full
    }

    return i;
}

//=============================================================================
// pull data from queue buffer
//=============================================================================
char uart_pull_byte(UART_DATA_T *uart_data, char *byte_variable)
{
    return(dequeue(uart_data->uart_queue, byte_variable));
}

//=============================================================================
// pull data from queue buffer
//=============================================================================
short uart_pull_data(UART_DATA_T *uart_data, char *byte_array, unsigned short byte_length)
{
    short i = 0;

    for(i = 0; i < byte_length; i++) {
        if(dequeue(uart_data->uart_queue, &byte_array[i]) < 0) {
            if(0xFFFF != byte_length) {
                return -2;       // buffer is empty
            }
            else {
                break;
            }   
        }
    }

    return i;
}

//=============================================================================
//=============================================================================

